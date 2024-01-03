#ifndef _STM32DUINO_H
#define _STM32DUINO_H

//STM32duino code
// - using STM32F030F4P6 chip
// - free running systick for ticks
// - 
// - version history
// - v2.0, 5/22/2021: simplified port
// - v2.1, 8/13/2022: modified uart functions
// - v2.2, 9/16/2022: added systickAttachISR()
// - v2.2a,10/29/2022:implemented clock switching
// - v2.2b,12/04/2022:implemented circular buffer + analog random number generator
// - v2.2c,01/28/2023:fixed an error in pll setup
// - v2.2d,02/19/2023:minor code fix for rtc - implemented unix epoch time
// - v2.2e,03/25/2023:added support for 32-bit chained timers
// - v2.2f,09/04/2023:added support for hardware 48-bit timers (tmr23 and tmr32/tmr142/tmr152 for now)
// - v2.2g,12/06/2023:added support for backup registers (a feature undocumented in the datasheet)
//
//
//               STM32F030F4P6
//      Vdd     |=====================|
//       |      |                     |
//       +------| Vdd            PA14 |<----- SWCLK (Pin20)
//              |                     |
//    NC +------| BOOT0          PA13 |<----> SWDIO (Pin19)
//              |                     |
//              |                     |
//   GND<-------| Vss             PA3 |--+--> LED1/VDD
//              |                     |  |
//              |                 PA4 |--+--> LED
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |                     |
//              |=====================|
//
//
//

#include <stm32f0xx.h>						//we use STM32F0
#include <string.h>							//we use strcpy()
#include <stdint.h>							//we use uint types
#include <time.h>							//we use time routines

//hardware configuration
//#define USE_CORETICK						//use coretick/DWT for tick generation - ignored for STM32F0
#define uRAM_SIZE			40				//uart buffer size

//oscillator configuration
#define F_XTAL				8000000ul		//crystal frequency, user-specified
#define F_LSE				32768			//watch crystal frequency, user-specified
//#define HSITRIM				16				//default trim, +/- 8, each = 40Khz step
//#define HSI14TRIM			16				//default trim, +/- 8, each = 50Khz step
//configuration for circular buffer
/*******NOTE********************************/
/******cBUFF_SIZE: must be power of 2*******/
/*******************************************/
#define cBUFF_SIZE 			32				//must be power of 2: 0..256 -> for buffers with more than 256 elements, change data type for writeIndex/readIndex
typedef char cbuffer_t;						//storage unit for the buffer
//end configuration for circular buffer
//end user specification

//pin config
#define U1TX2PIN()					U1TX2PA2()			//PB6, PA2, PA9, PA14
//#define U1RX2PIN()					U1RX2PB7()			//PB7, PA3, PA10,PA15
//#define U2TX2PIN()					U2TX2PA2()			//PA2, PA14	//uart2 doesn't exist on STM32F030
//#define U2RX2PIN()					U2RX2PA3()			//PA3, PA15

//pwm1 output pins / input capture pins
//#define TIM1CH1toPIN()				TIM1CH1toPA8()		//PA8
//#define TIM1CH2toPIN()				TIM1CH2toPA9()		//PA9
//#define TIM1CH3toPIN()				TIM1CH3toPA10()		//PA10
//#define TIM1CH4toPIN()				TIM1CH4toPA11()		//PA11
//#define TIM1CH1NtoPIN()				TIM1CH1NtoPA7()		//PA7, PB13
//#define TIM1CH2NtoPIN()				TIM1CH2NtoPB0()		//PB0, PB14
//#define TIM1CH3NtoPIN()				TIM1CH3NtoPB1()		//PB1, PB15

//pwm3 output pins
//#define TIM3CH1toPIN()				TIM3CH1toPA6()		//PA6, PB4
//#define TIM3CH2toPIN()				TIM3CH2toPA7()		//PA7, PB5
//#define TIM3CH3toPIN()				TIM3CH3toPB0()		//PB0
//#define TIM3CH4toPIN()				TIM3CH4toPB1()		//PB1

//pwm14 output pins
//#define TIM14CH1toPIN()				TIM14CH1toPA4()		//PA4, PA7, PB1

//pwm15 output pins
//#define TIM15CH1toPIN()				TIM15CH1toPA2()		//PA2, PB14 - only on STM32F030x8
//#define TIM15CH2toPIN()				TIM15CH2toPA3()		//PA3, PB15 - only on STM32F030x8
//#define TIM15CH1NtoPIN()			TIM15CH1NtoPB15()	//PB15 - only on STM32F030x8

//pwm16 output pins
//#define TIM16CH1toPIN()				TIM16CH1toPA6()		//PA6, PB8
//#define TIM16CH1NtoPIN()			TIM16CH1NtoPB6()	//PB6

//pwm17 output pins
//#define TIM17CH1toPIN()				TIM17CH1toPA7()		//PA7, PB9
//#define TIM17CH1NtoPIN()			TIM17CH1NtoPB7()	//PB7

//spi pins
//#define NSS1toPIN()					NSS1toPA4()			//PA4, PA15, PB12
//#define SCK1toPIN()					SCK1toPA5()			//PA5, PB3, PB13
//#define MISOtoPIN()					MISOtoPA6()			//PA6, PB4, PB14
//#define MOSI1toPIN()				MOSI1toPA7()		//PA7, PB5, PB15

//i2c pins
//#define SCL1toPIN()					SCL1toPA9()			//PA9, PB6, PB9
//#define SDA1toPIN()					SDA1toPA10()		//PA10,PB7, PB10

//others
#define SWDtoPA13()					pinAFIO(PA13,AFIO0)	//SWD pin to function as GPIO/PA13
#define SWCtoPA14()					pinAFIO(PA14,AFIO0)	//SWD pin to function as GPIO/PA14
#define MCOtoPA8()					pinAFIO(PA8, AFIO0)	//pa8 not available on tssop20
//end pin configuration

#define F_SYSCLK			(SystemCoreClock)
#define F_HCLK				(AHBClock())
#define F_PCLK				(APBClock())
#define F_CPU				(F_FCLK)					//peripheral block runs at F_PHB - default = F_CPU / 1
#define F_FCLK				F_HCLK
#define F_PHB				(F_APB)						//cpu runs at 8Mhz/2 by default -> Fxtal = 8Mhz. *4 for PLL. RCDIV set to 0 (1:1 postscaler)
#define F_AHB				(F_HCLK)
#define F_APB				(F_PCLK)
#define F_HSE				F_XTAL
#define F_LSI				38100ul						//LSI frequency, in hz - calibrated to HSI at ~38.088Khz. nominal 40K (from 30K - 50K, per datasheet)
#define F_HSI				8000000ul					//HSI frequency, in hz - uncalibrated, nominal 16Mhz
#define F_HCLK8				(F_HCLK/8)
#define F_TIMPCLK			(((RCC->CFGR & RCC_CFGR_PPRE) == RCC_CFGR_PPRE_DIV1)?F_APB:(F_APB*2))
#define F_UART1				(u1FreqGet())
#define F_I2C				((RCC->CFGR3 & RCC_CFGR3_I2C1SW)?F_SYSCLK:F_HSI)
#define PWM_PR				0xffff						//pwm period - don't change

//pin config
//uart1/2/3 pin config
#define U1TX2PB6()			pinAFIO(PB6, AFIO0)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 6))) | (/*0b10*/0x02<<(2* 6)); GPIOB->OTYPER &=~(1<< 6); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 6))) | (/*0b01*/0x01<<(2* 6)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 6%8)))) | (0<<(4*( 6%8)));} while (0)	//PB6, AF0
#define U1RX2PB7()			pinAFIO(PB7, AFIO0)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 7))) | (/*0b10*/0x02<<(2* 7)); GPIOB->OTYPER &=~(1<< 7); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 7))) | (/*0b01*/0x01<<(2* 7)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 7%8)))) | (0<<(4*( 7%8)));} while (0)	//PB7, AF0
#define U1TX2PA2()			pinAFIO(PA2, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 2))) | (/*0b10*/0x02<<(2* 2)); GPIOA->OTYPER &=~(1<< 2); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 2))) | (/*0b01*/0x01<<(2* 2)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 2%8)))) | (1<<(4*( 2%8)));} while (0)	//PA2, AF1
#define U1RX2PA3()			pinAFIO(PA3, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 3))) | (/*0b10*/0x02<<(2* 3)); GPIOA->OTYPER &=~(1<< 3); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 3))) | (/*0b01*/0x01<<(2* 3)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 3%8)))) | (1<<(4*( 3%8)));} while (0)	//PA3, AF1
#define U1TX2PA9()			pinAFIO(PA9, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 9))) | (/*0b10*/0x02<<(2* 9)); GPIOA->OTYPER &=~(1<< 9); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 9))) | (/*0b01*/0x01<<(2* 9)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*( 9%8)))) | (1<<(4*( 9%8)));} while (0)	//PA9, AF1
#define U1RX2PA10()			pinAFIO(PA10,AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2*10))) | (/*0b10*/0x02<<(2*10)); GPIOA->OTYPER &=~(1<<10); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2*10))) | (/*0b01*/0x01<<(2*10)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*(10%8)))) | (1<<(4*(10%8)));} while (0)	//PA10, AF1
#define U1TX2PA14()			pinAFIO(PA14,AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2*14))) | (/*0b10*/0x02<<(2*14)); GPIOA->OTYPER &=~(1<<14); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2*14))) | (/*0b01*/0x01<<(2*14)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*(14%8)))) | (1<<(4*(14%8)));} while (0)	//PA14, AF1
#define U1RX2PA15()			pinAFIO(PA15,AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2*15))) | (/*0b10*/0x02<<(2*15)); GPIOA->OTYPER &=~(1<<15); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2*15))) | (/*0b01*/0x01<<(2*15)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*(15%8)))) | (1<<(4*(15%8)));} while (0)	//PA15, AF1

//uart2 pins
#define U2TX2PA2()			pinAFIO(PA2, AFIO0)
#define U2RX2PA3()			pinAFIO(PA3, AFIO0)
#define U2TX2PA14()			pinAFIO(PA14,AFIO0)
#define U2RX2PA15()			pinAFIO(PA15,AFIO0)		//SWCLK pin

//pwm / oc
//global defines
#define TIM1CH1toPA8()				pinAFIO(PA8, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 8))) | (/*0b10*/0x02<<(2* 8)); GPIOA->OTYPER &=~(1<< 8); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 8))) | (/*0b01*/0x01<<(2* 8)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*( 8%8)))) | (2<<(4*( 8%8)));} while (0)
#define TIM1CH2toPA9()				pinAFIO(PA9, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 9))) | (/*0b10*/0x02<<(2* 9)); GPIOA->OTYPER &=~(1<< 9); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 9))) | (/*0b01*/0x01<<(2* 9)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*( 9%8)))) | (2<<(4*( 9%8)));} while (0)
#define TIM1CH3toPA10()				pinAFIO(PA10,AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2*10))) | (/*0b10*/0x02<<(2*10)); GPIOA->OTYPER &=~(1<<10); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2*10))) | (/*0b01*/0x01<<(2*10)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*(10%8)))) | (2<<(4*(10%8)));} while (0)
#define TIM1CH4toPA11()				pinAFIO(PA11,AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2*11))) | (/*0b10*/0x02<<(2*11)); GPIOA->OTYPER &=~(1<<11); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2*11))) | (/*0b01*/0x01<<(2*11)); GPIOA->AFR[1] = (GPIOA->AFR[1] &~(0x0f<<(4*(11%8)))) | (2<<(4*(11%8)));} while (0)
#define TIM1CH1NtoPA7()				pinAFIO(PA7, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 7))) | (/*0b10*/0x02<<(2* 7)); GPIOA->OTYPER &=~(1<< 7); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 7))) | (/*0b01*/0x01<<(2* 7)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 7%8)))) | (2<<(4*( 7%8)));} while (0)
#define TIM1CH1NtoPB13()			pinAFIO(PB13,AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2*13))) | (/*0b10*/0x02<<(2*13)); GPIOB->OTYPER &=~(1<<13); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2*13))) | (/*0b01*/0x01<<(2*13)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(13%8)))) | (2<<(4*(13%8)));} while (0)
#define TIM1CH2NtoPB0()				pinAFIO(PB0, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 0))) | (/*0b10*/0x02<<(2* 0)); GPIOB->OTYPER &=~(1<< 0); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 0))) | (/*0b01*/0x01<<(2* 0)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 0%8)))) | (2<<(4*( 0%8)));} while (0)
#define TIM1CH2NtoPB14()			pinAFIO(PB14,AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2*14))) | (/*0b10*/0x02<<(2*14)); GPIOB->OTYPER &=~(1<<14); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2*14))) | (/*0b01*/0x01<<(2*14)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(14%8)))) | (2<<(4*(14%8)));} while (0)
#define TIM1CH3NtoPB1()				pinAFIO(PB1, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 1))) | (/*0b10*/0x02<<(2* 1)); GPIOB->OTYPER &=~(1<< 1); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 1))) | (/*0b01*/0x01<<(2* 1)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 1%8)))) | (2<<(4*( 1%8)));} while (0)
#define TIM1CH3NtoPB15()			pinAFIO(PB15,AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2*15))) | (/*0b10*/0x02<<(2*15)); GPIOB->OTYPER &=~(1<<15); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2*15))) | (/*0b01*/0x01<<(2*15)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(15%8)))) | (2<<(4*(15%8)));} while (0)
//MODER=/*0b10*/0x02 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 1, AFR[0]/low byte
#define TIM3CH1toPA6()				pinAFIO(PA6, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 6))) | (/*0b10*/0x02<<(2* 6)); GPIOA->OTYPER &=~(1<< 6); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 6))) | (/*0b01*/0x01<<(2* 6)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 6%8)))) | (1<<(4*( 6%8)));} while (0)
#define TIM3CH1toPB4()				pinAFIO(PB4, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 4))) | (/*0b10*/0x02<<(2* 4)); GPIOB->OTYPER &=~(1<< 4); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 4))) | (/*0b01*/0x01<<(2* 4)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 4%8)))) | (1<<(4*( 4%8)));} while (0)
#define TIM3CH2toPA7()				pinAFIO(PA7, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 7))) | (/*0b10*/0x02<<(2* 7)); GPIOA->OTYPER &=~(1<< 7); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 7))) | (/*0b01*/0x01<<(2* 7)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 7%8)))) | (1<<(4*( 7%8)));} while (0)
#define TIM3CH2toPB5()				pinAFIO(PB5, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 5))) | (/*0b10*/0x02<<(2* 5)); GPIOB->OTYPER &=~(1<< 5); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 5))) | (/*0b01*/0x01<<(2* 5)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 5%8)))) | (1<<(1*( 5%8)));} while (0)
#define TIM3CH3toPB0()				pinAFIO(PB0, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 0))) | (/*0b10*/0x02<<(2* 0)); GPIOB->OTYPER &=~(1<< 0); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 0))) | (/*0b01*/0x01<<(2* 0)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 0%8)))) | (1<<(4*( 0%8)));} while (0)
#define TIM3CH4toPB1()				pinAFIO(PB1, AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 1))) | (/*0b10*/0x02<<(2* 1)); GPIOB->OTYPER &=~(1<< 1); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 1))) | (/*0b01*/0x01<<(2* 1)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 1%8)))) | (1<<(4*( 1%8)));} while (0)

#define TIM14CH1toPA4()				pinAFIO(PA4, AFIO4)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 4))) | (/*0b10*/0x02<<(2* 4)); GPIOA->OTYPER &=~(1<< 4); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 4))) | (/*0b01*/0x01<<(2* 4)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 4%8)))) | (4<<(4*( 4%8)));} while (0)
#define TIM14CH1toPA7()				pinAFIO(PA7, AFIO4)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 7))) | (/*0b10*/0x02<<(2* 7)); GPIOA->OTYPER &=~(1<< 7); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 7))) | (/*0b01*/0x01<<(2* 7)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 7%8)))) | (4<<(4*( 7%8)));} while (0)
#define TIM14CH1toPB1()				pinAFIO(PB1, AFIO0)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 1))) | (/*0b10*/0x02<<(2* 1)); GPIOB->OTYPER &=~(1<< 1); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 1))) | (/*0b01*/0x01<<(2* 1)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 1%8)))) | (0<<(4*( 1%8)));} while (0)

//MODER=/*0b10*/0x02 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 0, AFR[0]/low byte
#define TIM15CH1toPA2()				pinAFIO(PA2, AFIO0)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 2))) | (/*0b10*/0x02<<(2* 2)); GPIOA->OTYPER &=~(1<< 2); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 2))) | (/*0b01*/0x01<<(2* 2)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 2%8)))) | (0<<(4*( 2%8)));} while (0)
#define TIM15CH2toPA3()				pinAFIO(PA3, AFIO0)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 3))) | (/*0b10*/0x02<<(2* 3)); GPIOA->OTYPER &=~(1<< 3); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 3))) | (/*0b01*/0x01<<(2* 3)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 3%8)))) | (0<<(4*( 3%8)));} while (0)
//AF=1, AFR[1]/high byte
#define TIM15CH1toPB14()			pinAFIO(PB14,AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2*14))) | (/*0b10*/0x02<<(2*14)); GPIOB->OTYPER &=~(1<<14); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2*14))) | (/*0b01*/0x01<<(2*14)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(14%8)))) | (1<<(4*(14%8)));} while (0)
#define TIM15CH2toPB15()			pinAFIO(PB15,AFIO1)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2*15))) | (/*0b10*/0x02<<(2*15)); GPIOB->OTYPER &=~(1<<15); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2*15))) | (/*0b01*/0x01<<(2*15)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(15%8)))) | (1<<(4*(15%8)));} while (0)
#define TIM15CH1NtoPB15()			pinAFIO(PB15,AFIO3)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2*15))) | (/*0b10*/0x02<<(2*15)); GPIOB->OTYPER &=~(1<<15); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2*15))) | (/*0b01*/0x01<<(2*15)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*(15%8)))) | (3<<(4*(15%8)));} while (0)
//MODER=/*0b10*/0x02 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 5, AFR[0]/low byte
#define TIM16CH1toPA6()				pinAFIO(PA6, AFIO5)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 6))) | (/*0b10*/0x02<<(2* 6)); GPIOA->OTYPER &=~(1<< 6); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 6))) | (/*0b01*/0x01<<(2* 6)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 6%8)))) | (5<<(4*( 6%8)));} while (0)
//AF2, AFR[1]/high byte
#define TIM16CH1toPB8()				pinAFIO(PB8, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 8))) | (/*0b10*/0x02<<(2* 8)); GPIOB->OTYPER &=~(1<< 8); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 8))) | (/*0b01*/0x01<<(2* 8)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*( 8%8)))) | (2<<(4*( 8%8)));} while (0)
#define TIM16CH1NtoPB6()			pinAFIO(PB6, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 6))) | (/*0b10*/0x02<<(2* 6)); GPIOB->OTYPER &=~(1<< 6); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 6))) | (/*0b01*/0x01<<(2* 6)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 6%8)))) | (2<<(4*( 6%8)));} while (0)

//MODER=/*0b10*/0x02 (alternate function), OTYPER=(push-pull), OSPEEDR = medium speed
//Alternate function = 5, AFR[0]/low byte
#define TIM17CH1toPA7()				pinAFIO(PA7, AFIO5)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOAEN; GPIOA->MODER = (GPIOA->MODER &~(/*0b11*/0x03<<(2* 7))) | (/*0b10*/0x02<<(2* 7)); GPIOA->OTYPER &=~(1<< 7); GPIOA->OSPEEDR = (GPIOA->OSPEEDR &~(/*0b11*/0x03<<(2* 7))) | (/*0b01*/0x01<<(2* 7)); GPIOA->AFR[0] = (GPIOA->AFR[0] &~(0x0f<<(4*( 7%8)))) | (5<<(4*( 7%8)));} while (0)
//AF2, AFR[1]/high byte
#define TIM17CH1toPB9()				pinAFIO(PB9, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 9))) | (/*0b10*/0x02<<(2* 9)); GPIOB->OTYPER &=~(1<< 9); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 9))) | (/*0b01*/0x01<<(2* 9)); GPIOB->AFR[1] = (GPIOB->AFR[1] &~(0x0f<<(4*( 9%8)))) | (2<<(4*( 9%8)));} while (0)
#define TIM17CH1NtoPB7()			pinAFIO(PB7, AFIO2)	//do {RCC->AHBENR |= RCC_AHBENR_GPIOBEN; GPIOB->MODER = (GPIOB->MODER &~(/*0b11*/0x03<<(2* 7))) | (/*0b10*/0x02<<(2* 7)); GPIOB->OTYPER &=~(1<< 7); GPIOB->OSPEEDR = (GPIOB->OSPEEDR &~(/*0b11*/0x03<<(2* 7))) | (/*0b01*/0x01<<(2* 7)); GPIOB->AFR[0] = (GPIOB->AFR[0] &~(0x0f<<(4*( 7%8)))) | (2<<(4*( 7%8)));} while (0)

//spi pins
#define NSS1toPA4()					pinAFIO(PA4, AFIO0)
#define SCK1toPA5()					pinAFIO(PA5, AFIO0)
#define MISO1toPA6()				pinAFIO(PA6, AFIO0)
#define MOSI1toPA7()				pinAFIO(PA7, AFIO0)
#define SWDIOtoPA13()				pinAFIO(PA13,AFIO0)
#define SWCLKtoPA14()				pinAFIO(PA14,AFIO0)
#define NSS1toPA15()				pinAFIO(PA15,AFIO0)
#define SCK1toPB3()					pinAFIO(PB3, AFIO0)
#define MISO1toPB4()				pinAFIO(PB4, AFIO0)
#define MOSI1toPB5()				pinAFIO(PB5, AFIO0)
#define NSS1toPB12()				pinAFIO(PB12,AFIO0)
#define SCK1toPB13()				pinAFIO(PB13,AFIO0)
#define MISO1toPB14()				pinAFIO(PB14,AFIO0)
#define MOSI1toPB15()				pinAFIO(PB15,AFIO0)

//i2c pins
#define SCL1toPA9()					pinAFIO(PA9, AFIO4)
#define SDA1toPA10()				pinAFIO(PA10,AFIO4)
#define SCL1toPB6()					pinAFIO(PB6, AFIO1)
#define SDA1toPB7()					pinAFIO(PB7, AFIO1)
#define SCL1toPB9()					pinAFIO(PB9, AFIO1)
#define SDA1toPB10()				pinAFIO(PB10,AFIO1)

//end pin config

//for compatability with CoIDE
/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup 
   Timeout value 
   */
#if !defined  (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) Startup 
   Timeout value 
   */
#if !defined  (HSI_STARTUP_TIMEOUT)
#define HSI_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSI start up */
#endif /* HSI_STARTUP_TIMEOUT */


//end compatability with CoIDE
//port manipulation macros for PIC.
//MODE:
//Output modes: GPIOMODE_OUTPP, GPIOMODE_OUTOD
//Input mode: GPIOMODE_INPUT, GPIOMODE_INPUTPD, GPIOMODE_INPUTPU
//Alternate function: GPIOMODE_AFPP, GPIOMODE_AFOD
//for moder
#define GPIOMODE_INPUT		(0<<0)		//(0<<0)
#define GPIOMODE_OUTPUT		(1<<0)		//(1<<0)
#define GPIOMODE_AF			(2<<0)
#define GPIOMODE_AN			(3<<0)
//for otyper
#define GPIOMODE_PP			(1<<3)
#define GPIOMODE_OD			(0<<3)
//for pupdr
#define GPIOMODE_FL			(0<<4)
#define GPIOMODE_PU			(1<<4)
#define GPIOMODE_PD			(2<<4)

//AF defs
#define GPIOMODE_AF0		0
#define GPIOMODE_AF1		1
#define GPIOMODE_AF2		2
#define GPIOMODE_AF3		3
#define GPIOMODE_AF4		4
#define GPIOMODE_AF5		5
#define GPIOMODE_AF6		6
#define GPIOMODE_AF7		7

#define GPIOMODE_OUTPP		(GPIOMODE_OUTPUT | GPIOMODE_PP)		//gpio, output, push-pull
#define GPIOMODE_OUTOD		(GPIOMODE_OUTPUT | GPIOMODE_OD)		//gpio, output, od
#define GPIOMODE_INFL		(GPIOMODE_INPUT)
#define GPIOMODE_INPU		(GPIOMODE_INPUT | GPIOMODE_PU)
#define GPIOMODE_INPD		(GPIOMODE_INPUT | GPIOMODE_PD)
#define GPIOMODE_AFPP		(GPIOMODE_AF | GPIOMODE_PP)
#define GPIOMODE_AFOD		(GPIOMODE_AF | GPIOMODE_OD)
#define GPIOMODE_INAN		(GPIOMODE_AN)

//global variables

//tiny scheduler macro
#define TS_RUN_WHILE(cs)	if (cs)						//tiny scheduler macro
#define TSwhile(cs)			TS_RUN_WHILE(cs)			//shorter macro

//operate on a var
#define REG_EQU(var, bits)					var  = (bits)
#define REG_SET(var, bits)					var |= (bits)
#define REG_CLR(var, bits)					var &=~(bits)
#define REG_FLP(var, bits)					var ^= (bits)
#define REG_GET(var, bits)					((var) & (bits))
#define REG_MOD(var, bits, mask)			(var = ((var) &~(mask)) | ((bits) & (mask)))

//port/gpio oriented macros
#define IO_SET(port, pins)					GIO_SET(port, pins)				//port->BSRR = (pins)
#define IO_CLR(port, pins)					GIO_CLR(port, pins)				//port->BRR = (pins)
#define IO_FLP(port, pins)					GIO_FLP(port, pins)
#define IO_GET(port, pins)					GIO_GET(port, pins)
//set a pin to output/input
#define IO_OUTPP(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTPP)	//push-pull mode (CR1 set, CR2 cleared)	//IO_OUTPP(GPIOx, GPIO_Pins).
#define IO_OUTOD(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTOD)	//open drain mode (cr1 + cr2 cleared)	//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_OUT_OD_LOW_FAST)
#define IO_OUT(port, pins)					IO_OUTPP(port, pins)					//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_OUT_PP_LOW_FAST)
#define IO_INFL(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INFL)		//floating input, no interrupt			//IO_INFL(GPIOx, GPIO_Pins)
#define IO_INPU(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INPU)		//pull-up, no interrupt					//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_PU_NO_IT)
#define IO_INPD(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INPD)		//pull-up, no interrupt					//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_PU_NO_IT)
#define IO_IN(port, pins)					IO_INFL(port, pins)						//IO_IN(port, pins)				//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_FL_NO_IT)
#define IO_AFPP(port, pins)					GPIO_DDR(port, pins, GPIOMODE_AFPP)		//configure pin for alternative function output, push-pull, 10Mhz
#define IO_AFOD(port, pins)					GPIO_DDR(port, pins, GPIOMODE_AFOD)		//configure pin for alternative function output, open-drain, 10Mhz
#define IO_AN(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INAN)

//fast port/gpio oriented macros
#define FIO_SET(port, pins)					port->BSRR = (pins)				//set bits on port
#define FIO_CLR(port, pins)					port->BRR  = (pins)				//clear bits on port
#define FIO_FLP(port, pins)					GIO_FLP(port, pins)				//port->ODR ^= (pins)				//flip bits on port
#define FIO_GET(port, pins)					GIO_GET(port, pins)				//((port->IDR) & (pins))			//return bits on port

//fast routines through BRR/BSRR registers
#define GIO_SET(port, pins)					REG_SET(port->ODR, pins)				//set bits on port
#define GIO_CLR(port, pins)					REG_CLR(port->ODR, pins)				//clear bits on port
#define GIO_FLP(port, pins)					REG_FLP(port->ODR, pins)				//flip bits on port
#define GIO_GET(port, pins)					REG_GET(port->IDR, pins)				//return bits on port
#define GIO_IN(port, pins)					IO_IN(port, pins)
#define GIO_INFL(port, pins)				IO_INFL(port, pins)
#define GIO_INPU(port, pins)				IO_INPU(port, pins)
#define GIO_INPD(port, pins)				IO_INPD(port, pins)
#define GIO_OUT(port, pins)					IO_OUT(port, pins)
#define GIO_OUTOD(port, pins)				IO_OUTOD(port, pins)
#define GIO_OUTPP(port, pins)				IO_OUTPP(port, pins)
//configure gpio mode (cnf1..0 + mod1..0 bits)
void GPIO_DDR(GPIO_TypeDef * gpio, uint32_t mask, uint32_t mode);

#define NOP()				Nop()                           //asm("nop")					//nop()
#define NOP2()				{NOP(); NOP();}
#define NOP4()				{NOP2(); NOP2();}
#define NOP8()				{NOP4(); NOP4();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP24()				{NOP16(); NOP8();}
#define NOP32()				{NOP16(); NOP16();}
#define NOP40()				{NOP32(); NOP8();}
#define NOP64()				{NOP32(); NOP32();}

#define sleep()				asm("sleep")					//put the mcu into sleep

#ifndef ei
#define ei()				//asm volatile ("ei")				//__builtin_enable_interrupts()	//do {INTEnableInterrupts();	INTEnableSystemMultiVectoredInt();} while (0)	//__builtin_enable_interrupts()
#endif

#ifndef di
#define di()				//asm volatile ("di")				//__builtin_enable_interrupts()	//INTDisableInterrupts()			//__builtin_disable_interrupts()	//
#endif


//simple multiples
#define x1(val)				(val)								//multiply val by 1
#define x2(val)				(((val) << 1))						//multiply val by 2
#define x3(val)				(x2(val) + (val))					//multiply val by 3
#define x4(val)				(((val) << 2))						//multiply val by 4
#define x5(val)				(x4(val) + (val))					//multiply val by 5
#define x6(val)				(x4(val) + x2(val))					//multiply val by 6
#define x7(val)				(x6(val) + (val))					//multiply val by 7
#define x8(val)				((val) << 3)						//multiply val by 8
#define x9(val)				(x8(val) + (val))					//multiply val by 9

//multiples of 10s
#define x10(val)			(x8(val) + x2(val))					//multiply val by 10
#define x100(val)			(x10(x10(val)))						//multiply val by 100
#define x1000(val)			(x100(x10(val)))					//multiply val by 1000
#define x1k(val)			x1000(val)							//multiply val by 1000
#define x10k(val)			(x100(x100(val)))					//multiply val by 10000

#define x20(val)			(x2(x10(val)))
#define x30(val)			(x3(x10(val)))
#define x40(val)			(x4(x10(val)))
#define x50(val)			(x5(x10(val)))
#define x60(val)			(x6(x10(val)))
#define x70(val)			(x7(x10(val)))
#define x80(val)			(x8(x10(val)))
#define x90(val)			(x9(x10(val)))

//multiples of 100s
#define x200(val)			(x2(x100(val)))
#define x300(val)			(x3(x100(val)))
#define x400(val)			(x4(x100(val)))
#define x500(val)			(x5(x100(val)))
#define x600(val)			(x6(x100(val)))
#define x700(val)			(x7(x100(val)))
#define x800(val)			(x8(x100(val)))
#define x900(val)			(x9(x100(val)))

//custom definitions
#define x34(val)			(x30(val) + x4(val))				//multiply val by 34
#define x97(val)			(x90(val) + x7(val))				//multiply val by 97x

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
//typedef unsigned long uint32_t;
//typedef signed long int32_t;

//port structure

//global defines

//pin enum - matches GPIO_PinDef[]
typedef enum {
#if defined(GPIOA)
	PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
#endif		//GPIOA
#if defined(GPIOB)
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
#endif 		//GPIOB
#if defined(GPIOC)
	PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, PC8, PC9, PC10, PC11, PC12, PC13, PC14, PC15,
#endif		//GPIOC
#if defined(GPIOD)
	PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7, PD8, PD9, PD10, PD11, PD12, PD13, PD14, PD15,
#endif		//GPIOD
#if defined(GPIOE)
	PE0, PE1, PE2, PE3, PE4, PE5, PE6, PE7, PE8, PE9, PE10, PE11, PE12, PE13, PE14, PE15,
#endif		//GPIOE
#if defined(GPIOF)
	PF0, PF1, PF2, PF3, PF4, PF5, PF6, PF7, PF8, PF9, PF10, PF11, PF12, PF13, PF14, PF15,
#endif		//GPIOF
#if defined(GPIOG)
	PG0, PG1, PG2, PG3, PG4, PG5, PG6, PG7, PG8, PG9, PG10, PG11, PG12, PG13, PG14, PG15,
#endif		//GPIOG
	PMAX
} PIN_TypeDef;

//map pin number to GPIOx
typedef struct {
	GPIO_TypeDef *gpio;					//gpio for a pin
	uint16_t mask;						//pin mask - 16-bit port
} PIN2GPIO;
	
#define INPUT				0
#define OUTPUT				1			//(!INPUT)
#define INPUT_PULLUP		2
#define OUTPUT_OD			3			//(!INPUT)
#define INPUT_PULLDW		4
#define INPUT_PU			INPUT_PULLUP
#define INPUT_PD			INPUT_PULLDW

#define LOW					0
#define HIGH				(!LOW)

#define PI 					3.1415926535897932384626433832795
#define HALF_PI 			(PI / 2)							//1.5707963267948966192313216916398
#define TWO_PI 				(PI + PI)							//6.283185307179586476925286766559
#define DEG_TO_RAD 			(TWO_PI / 360)						//0.017453292519943295769236907684886
#define RAD_TO_DEG 			(360 / TWO_PI)						//57.295779513082320876798154814105
#define EULER 				2.718281828459045235360287471352	//Euler's number

#define SERIAL  			0x0
#define DISPLAY 			0x1

#define LSBFIRST 			0
#define MSBFIRST 			1									//(!LSBFIRST)							//1

#define CHANGE 				1
#define FALLING 			2
#define RISING 				3

#ifndef min
#define min(a,b) 			((a)<(b)?(a):(b))
#endif
#ifndef max
#define max(a,b) 			((a)>(b)?(a):(b))
#endif
#define abs(x) 				((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     		((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) 		((deg)*DEG_TO_RAD)
#define degrees(rad) 		((rad)*RAD_TO_DEG)
#define sq(x) 				((x)*(x))

#define interrupts() 		ei()
#define noInterrupts() 		di()

#define clockCyclesPerMillisecond() 	( F_CPU / 1000L )
#define clockCyclesPerMicrosecond() 	( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) 	( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) 	( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) 			((uint8_t) ((w) & 0xff))
#define highByte(w) 		((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) 	((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define bit(n)				(1ul<<(n))

#define false				0
#define true				(!false)

//characters
#define isAlphaNumeric(c)	isalnum(c)
#define isAlpha(c)			isalpha(c)
#define isAscii(c)			isascii(c)
#define isWhitespace(c)		isblank(c)
#define isControl(c)		iscntrl(c)
#define isDigit(c)			isdigit(c)
#define isGraph(c)			isgraph(c)
#define isLowerCase(c)		islower(c)
#define isPrintable(c)		isprint(c)
#define isPunct(c)			ispunct(c)
#define isSpace(c)			isspace(c)
#define isUpperCase(c)		isupper(c)
#define isHexadecimalDigit(c)	isxdigit(c)

//external setup/loop - defined by user
extern void setup(void);
extern void loop(void);

//random number
#define randomSeed(seed)	srand(seed)
#define random(max)			random2(0, max)
#define random2(min, max)	((min) + (int32_t) ((max) - (min)) * rand() / 32768)

//GPIO
//GPIO
typedef enum {
	//DEFAULT,					//default / reset state
	AFIO0 = 0,					//afio numbers
	AFIO1,
	AFIO2,
	AFIO3,
	AFIO4,
	AFIO5,
	AFIO6,
	AFIO7,
	AFIO8,
	AFIO9,
	AFIO10,
	AFIO11,
	AFIO12,
	AFIO13,
	AFIO14,
	AFIO15,
	AFIOMAX,
} AFIO_TypeDef;

void pinMode(PIN_TypeDef pin, uint8_t mode);
void digitalWrite(PIN_TypeDef pin, uint8_t mode);
int digitalRead(PIN_TypeDef pin);
#define pinFlip(pin)		digitalWrite(pin, !digitalRead(pin))
void pinAFIO(PIN_TypeDef pin, AFIO_TypeDef AFIOn);	//configure pin for AFIO

//do not put SWD pins (PA13/14) into GPIO - you will lose debug capability
//if you do, recover as follows:
// 1. pull down the nRST pin and hold it down.
// 2. flash the chip
// 3. release the nRST pin
//
// step 2 and 3 should be done reasonably quickly (within seconds of each other)
//

//time base
//uint32_t ticks(void);								//timer ticks from timer2
uint32_t systicks(void);
#define ticks()				systicks()				//map ticks to systicks()
#define millis()			(ticks() / cyclesPerMillisecond())
#define micros()			(ticks() / cyclesPerMicrosecond())
void delayTks(uint32_t tks);						//delay a given number of ticks
//void delayUs(uint32_t us);						//delay a given number of micro seconds
//void delayMs(uint32_t ms);						//delay a given number of millie seconds
#define delayUs(us)				delayTks((us) * cyclesPerMicrosecond())
#define delayMs(ms)				delayTks((ms) * cyclesPerMillisecond())
#define delay(ms)				delayMs(ms)
#define delayMilliseconds(ms)	delayMs(ms)
#define delayMicroseconds(us)	delayUs(us)
#define cyclesPerMicrosecond()			(F_CPU / 1000000ul)
#define cyclesPerMillisecond()			(F_CPU / 1000)

//advanced IO
//void tone(void);									//tone frequency specified by F_TONE in STM8Sduino.h
//void noTone(void);
//shiftin/out: bitOrder = MSBFIRST or LSBFIRST
uint8_t shiftIn(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder);
void shiftOut(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder, uint8_t val);
uint32_t pulseIn(PIN_TypeDef pin, uint8_t state);		//wait for a pulse and return timing

//pwm output
//dc = 0x00..0x0fff for pwm2/3/4/5, 0x00..0xffff for pwm1
//RP4=PWM1, RP12=PWM2, RP13=PWM3, RP14=PWM4, RP15=PWM5
void analogWrite(uint8_t pin, uint16_t dc);

//analog read on ADC1
//read DRL first for right aligned results
//uint16_t analogRead(uint8_t pin);

//analog reference - default to AVdd-AVss
//Vref sources: 0->Vref = AVdd-AVss, 1->Vref+-AVss, 2->AVdd-Vref-, 3->Vref+ - Vref-
//void analogReference(uint8_t Vref);

//interrupts
//install external interrupt handler
//mode 1: falling edge, 0: rising edge
//void attachInterrupt(uint8_t intx, void (*isrptr) (void), uint8_t mode);
//void detachInterrupt(uint8_t intx);

//change notification interrupts
//install user CN interrupt handler
//void attachCNInterrupt(void (*isrptr) (void));
//void detachCNInterrupt(void);
//void activateCNInterrupt(uint8_t cnx, uint8_t pue);
//void deactivateCNInterrupt(uint8_t cnx);

//global variables

//empty interrupt handler
void empty_handler(void);

//clock switching
//clock mgmt
//switch system clock
//clock choices: RCC_CFGR_SW_HSI, RCC_CFGR_SW_HSE, RCC_CFGR_SW_PLL (from HSI or HSE)
void SystemCoreClockConfig(uint32_t clk);
//set pll
//return Fvco: < 48Mhz (chip doesn't run at 52Mhz)
//Fvco=Fpllin * (N+2) / (M + 1)								//divider is fixed 2 for HSI
//N: 0..14, M = 1..15
void pllSet(uint32_t N, uint32_t M);
//clock switching
//Fvco<=48Mhz
#define pll0x125()	pllSet( 0, 15)
#define pll0x25()	pllSet( 0, 7)
#define pll0x5()	pllSet( 0, 3)
#define pll1x()		pllSet( 0, 1)
#define pll1x5()	pllSet( 1, 1)
#define pll2x()		pllSet( 2, 1)
#define pll2x5()	pllSet( 3, 1)
#define pll3x()		pllSet( 4, 1)
#define pll3x5()	pllSet( 5, 1)
#define pll4x()		pllSet( 6, 1)
#define pll4x5()	pllSet( 7, 1)
#define pll5x()		pllSet( 8, 1)
#define pll5x5()	pllSet( 9, 1)
#define pll6x()		pllSet(10, 1)			//datasheet frequency for hsi @ 48Mhz.
#define pll6x5()	pllSet(11, 1)
#define pll7x()		pllSet(12, 1)			//empirical max frequency for hsi @ 56Mhz
#define pll7x5()	pllSet(13, 1)
#define pll8x()		pllSet(14, 1)			//maximum multiplier

#define SystemCoreClockHSI()				SystemCoreClockConfig(RCC_CFGR_SW_HSI)
#define SystemCoreClockHSIPLL()				SystemCoreClockHSIPLL4x()			//default to pll4x
//HSIxPLL has a /2 fixed pre-divider hardwared.
#define SystemCoreClockHSIPLL0x25()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll0x25();SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x00);} while (0)
#define SystemCoreClockHSIPLL0x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll0x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x00);} while (0)
#define SystemCoreClockHSIPLL1x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll1x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x00);} while (0)
#define SystemCoreClockHSIPLL1x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll1x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x00);} while (0)
#define SystemCoreClockHSIPLL2x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll2x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x00);} while (0)
#define SystemCoreClockHSIPLL2x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll2x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x00);} while (0)
#define SystemCoreClockHSIPLL3x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll3x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x00);} while (0)
#define SystemCoreClockHSIPLL3x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll3x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL4x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll4x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL4x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll4x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL5x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll5x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL5x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll5x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL6x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll6x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL6x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll6x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL7x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll7x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL7x5()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll7x5(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSIPLL8x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSI); RCC->CFGR &=~RCC_CFGR_PLLSRC; pll8x();  SystemCoreClockConfig(RCC_CFGR_SW_PLL); FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
//#define SystemCoreClockHSI2Mhz()			SystemCoreClockHSIPLL0x25()			//doesn't work
//#define SystemCoreClockHSI4Mhz()			SystemCoreClockHSIPLL0x5()			//doesn't work
//#define SystemCoreClockHSI8Mhz()			SystemCoreClockHSI()				//doesn't work
#define SystemCoreClockHSI16Mhz()			SystemCoreClockHSIPLL2x()
#define SystemCoreClockHSI20Mhz()			SystemCoreClockHSIPLL2x5()
#define SystemCoreClockHSI24Mhz()			SystemCoreClockHSIPLL3x()
#define SystemCoreClockHSI28Mhz()			SystemCoreClockHSIPLL3x5()
#define SystemCoreClockHSI32Mhz()			SystemCoreClockHSIPLL4x()
#define SystemCoreClockHSI36Mhz()			SystemCoreClockHSIPLL4x5()
#define SystemCoreClockHSI40Mhz()			SystemCoreClockHSIPLL5x()
#define SystemCoreClockHSI44Mhz()			SystemCoreClockHSIPLL5x5()
#define SystemCoreClockHSI48Mhz()			SystemCoreClockHSIPLL6x()
#define SystemCoreClockHSI52Mhz()			SystemCoreClockHSIPLL6x5()			//max that works
//#define SystemCoreClockHSI56Mhz()			SystemCoreClockHSIPLL7x()			//doesn't work
//#define SystemCoreClockHSI60Mhz()			SystemCoreClockHSIPLL7x5()			//doesn't work
//#define SystemCoreClockHSI64Mhz()			SystemCoreClockHSIPLL8x()			//doesn't work

#define SystemCoreClockHSE()				SystemCoreClockConfig(RCC_CFGR_SW_HSE)
#define SystemCoreClockHSEPLL()				SystemCoreClockHSEPLL1x()
#define SystemCoreClockHSEPLL1x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll1x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSEPLL2x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll2x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSEPLL3x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll3x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSEPLL4x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll4x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSEPLL5x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll5x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSEPLL6x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll6x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSEPLL7x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll7x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)
#define SystemCoreClockHSEPLL8x()			do {SystemCoreClockConfig(RCC_CFGR_SW_HSE); RCC->CFGR |= RCC_CFGR_PLLSRC; pll8x(); SystemCoreClockConfig(RCC_CFGR_SW_PLL); if (AHBClock() > 24000000ul) FLASH->ACR = (FLASH->ACR &~FLASH_ACR_LATENCY) | (0x01);} while (0)

uint32_t AHBClock(void);				//get AHB speed
uint32_t APBClock(void);				//get APB speed

//hsi trimming - releative to their value (default value of 16)
#define HSITrimSet(trim)					RCC->CR = (RCC->CR &~RCC_CR_HSITRIM) | (((16+(trim)) << 3) & RCC_CR_HSITRIM)
#define HSITrimGet()						((RCC->CR & RCC_CR_HSITRIM) >> 3)
#define HSI14TrimSet(trim)					RCC->CR2 = (RCC->CR2 &~RCC_CR2_HSI14TRIM) | (((16+(trim) << 3) & RCC_CR2_HSI14TRIM)
#define HSI14TrimGet()						((RCC->CR2 & RCC_CR2_HSI14TRIM) >> 3)

//mco: div 0..7 -> 1..128:1
#define MCO2NoCLK(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_NOCLOCK;} while (0)
#define MCO2HSI14(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_HSI14;  } while (0)
#define MCO2LSI(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_LSI;    } while (0)
#define MCO2LSE(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_LSE;    } while (0)
#define MCO2SYSCLK(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_SYSCLK; } while (0)
#define MCO2HSI(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_HSI;    } while (0)
#define MCO2HSE(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_HSE;    } while (0)
#define MCO2PLL(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_PLL;    } while (0)
#define MCO2HSI48(div)						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO_PRE) | (((div) << 28) & RCC_CFGR_MCO_PRE); RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | RCC_CFGR_MCO_HSI48;  } while (0)

//global defines
#define IDCODE				(DBGMCU->IDCODE)
#define CPUID				(SCB->CPUID)
#define UID					((char *) 0x1ffff7ac)		//96bit/12byte unique id. UID[0]..UID[11]

//global variables

//reset the mcu
void mcuInit(void);

//activate the isr handler
void systickAttachISR(void (*isrptr)(void));

//#define Mhz					000000ul	//suffix for Mhz
#define F_UART				(F_PHB)	//8Mhz		//crystal frequency
#define UART_BR300			300ul		//buadrate=300
#define UART_BR600			600ul		//buadrate=600
#define UART_BR1200			1200ul		//buadrate=1200
#define UART_BR2400			2400ul		//buadrate=2400
#define UART_BR4800			4800ul		//buadrate=4800
#define UART_BR9600			9600ul		//buadrate=9600
#define UART_BR14400		14400ul		//buadrate=19200
#define UART_BR19200		19200ul		//buadrate=19200
#define UART_BR38400		38400ul		//buadrate=38400
#define UART_BR43000		43000ul		//buadrate=38400
#define UART_BR57600		57600ul		//buadrate=57600
#define UART_BR76800		76800ul		//buadrate=57600
#define UART_BR115200		115200ul	//buadrate=115200
#define UART_BR128000		128000ul	//buadrate=115200
#define UART_BR230400		230400ul	//buadrate=115200
#define UART_BR256000		256000ul	//buadrate=115200
#define UART_BR460800		460800ul	//buadrate=115200
#define UART_BR512000		512000ul	//buadrate=115200
#define UART_BR576000		576000ul	//buadrate=115200
#define UART_BR921600		921600ul	//buadrate=115200
#define UART_BR1000000		1000000ul	//buadrate=115200
#define UART_BR1250000		1250000ul	//buadrate=115200
#define UART_BR1500000		1500000ul	//buadrate=115200
#define UART_BR2000000		2000000ul	//buadrate=115200
//short notations
#define UART_BR0K3			UART_BR300
#define UART_BR0K6			UART_BR600
#define UART_BR1K2			UART_BR1200
#define UART_BR2K4			UART_BR2400
#define UART_BR4K8			UART_BR4800
#define UART_BR9K6			UART_BR9600
#define UART_BR14K4			UART_BR14400
#define UART_BR19K2			UART_BR19200
#define UART_BR38K4			UART_BR38400
#define UART_BR43K			UART_BR43000
#define UART_BR57K6			UART_BR57600
#define UART_BR76K8			UART_BR76800
#define UART_BR115K2		UART_BR115200
#define UART_BR128K			UART_BR128000
#define UART_BR256K			UART_BR256000
#define UART_BR460K8		UART_BR460800
#define UART_BR512K			UART_BR512000
#define UART_BR576K			UART_BR576000
#define UART_BR921K6		UART_BR921600
#define UART_BR1M			UART_BR1000000
#define UART_BR1M25			UART_BR1250000
#define UART_BR1M5			UART_BR1500000
#define UART_BR2M			UART_BR2000000

//for compatability
#define uart1Put(ch)		uart1Putch(ch)
#define uart1Get()			uart1Getch()

//initiate the hardware usart
void uart1Init(unsigned long baud_rate);
void uart1Putch(char ch);
void uart1Puts(char *str);
//uint16_t uart1Available(void);
#define uart1Available()	(USART1->ISR & USART_ISR_RXNE)
//uint16_t uart1Busy(void);
#define uart1Busy()			(!(USART1->ISR & USART_ISR_TXE))

void uart1Putline(char *ln);
//read a char from usart
//uint8_t uart1Getch(void);
#define uart1Getch()		(USART1->RDR)
void u1Print(char *str, int32_t dat);
#define u1Println()			uart1Puts("\r\n")
#define uart1bps()			(((USART1->CR1 & (1<<15))?2:1) * F_UART / USART1->BRR)
#define u1bps()				uart1bps()

//for compatability
#define uart2Put(ch)		uart2Putch(ch)
#define uart2Get()			uart2Getch()
//initiate the hardware usart
void uart2Init(unsigned long baud_rate);
void uart2Putch(char ch);
void uart2Puts(char *str);
//uint16_t uart2Available(void);
#define uart2Available()	(USART2->ISR & USART_ISR_RXNE)
//uint16_t uart2Busy(void);
#define uart2Busy()			(!(USART2->ISR & USART_ISR_TXE))
void uart2Putline(char *ln);

//read a char from usart
//uint8_t uart2Getch(void);
#define uart2Getch()		(USART2->RDR)
void u2Print(char *str, int32_t dat);
#define u2Println()			uart2Puts("\r\n")
#define uart2bps()			(((USART2->CR1 & (1<<15))?2:1) * F_UART / USART2->BRR)
#define u2bps()				uart2bps()
//end Serial

//ic1 bit position
#define TIM_CCMR1_IC1PSC_Pos	2
#define TIM_CCMR1_IC2PSC_Pos	10
#define TIM_CCMR2_IC3PSC_Pos	2
#define TIM_CCMR2_IC4PSC_Pos	10

#define tmrCC1Get(tmr)		(tmr->CCR1)				//get capture / compare value
#define tmrCC2Get(tmr)		(tmr->CCR2)				//get capture / compare value
#define tmrCC3Get(tmr)		(tmr->CCR3)				//get capture / compare value
#define tmrCC4Get(tmr)		(tmr->CCR4)				//get capture / compare value
//initialize the timer1 (16bit)
void tmr1Init(uint16_t ps);							//initialize timer with a prescaler
#define tmr1Get()			(TIM1->CNT)				//get counter value
#define tmr1SetPS(ps)		TIM1->PSC = (ps) - 1ul		//set prescaler
#define tmr1GetPS()			(TIM1->PSC + 1ul)		//get prescaler
#define tmr1SetPR(pr)		TIM1->ARR = (pr) - 1	//void tmr1SetPR(uint16_t pr);						//set period for ovf interupt
#define tmr1GetPR()			(TIM1->ARR + 1ul)		
void tmr1OVFAttachISR(void (*isrptr)(void));		//activate the ovf isr handler
//output compare
void tmr1OC1SetPR(uint16_t pr);						//set period
void tmr1OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr1OC2SetPR(uint16_t pr);						//set period
void tmr1OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr1OC3SetPR(uint16_t pr);						//set period
void tmr1OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr1OC4SetPR(uint16_t pr);						//set period
void tmr1OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr1IC1Init(uint8_t ps);								//activate input capture
#define tmr1CC1Get()		tmrCC1Get(TIM1)			//get compare / capture value
void tmr1IC2Init(uint8_t ps);								//activate input capture
#define tmr1CC2Get()		tmrCC2Get(TIM1)			//get compare / capture value
void tmr1IC3Init(uint8_t ps);								//activate input capture
#define tmr1CC3Get()		tmrCC3Get(TIM1)			//get compare / capture value
void tmr1IC4Init(uint8_t ps);								//activate input capture
#define tmr1CC4Get()		tmrCC4Get(TIM1)			//get compare / capture value

//initialize the timer2 (32bit)
void tmr2Init(uint16_t ps);							//initialize timer with a prescaler
#define tmr2Get()			(TIM2->CNT)				//get counter value
#define tmr2SetPS(ps)		TIM2->PSC = (ps) - 1ul		//set prescaler
#define tmr2GetPS()			(TIM2->PSC + 1ul)		//get prescaler
#define tmr2SetPR(pr)		TIM2->ARR = (pr) - 1	//void tmr2SetPR(uint16_t pr);						//set period for ovf interupt
#define tmr2GetPR()			((uint32_t) TIM2->ARR + 1ul)		
void tmr2OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr2OC1SetPR(uint32_t pr);						//set period
void tmr2OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr2OC2SetPR(uint32_t pr);						//set period
void tmr2OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr2OC3SetPR(uint32_t pr);						//set period
void tmr2OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr2OC4SetPR(uint32_t pr);						//set period
void tmr2OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr2IC1Init(uint8_t ps);								//activate input capture
#define tmr2CC1Get()		tmrCC1Get(TIM2)			//get compare / capture value
void tmr2IC2Init(uint8_t ps);								//activate input capture
#define tmr2CC2Get()		tmrCC2Get(TIM2)			//get compare / capture value
void tmr2IC3Init(uint8_t ps);								//activate input capture
#define tmr2CC3Get()		tmrCC3Get(TIM2)			//get compare / capture value
void tmr2IC4Init(uint8_t ps);								//activate input capture
#define tmr2CC4Get()		tmrCC4Get(TIM2)			//get compare / capture value


//initialize the timer3 (16bit)
void tmr3Init(uint16_t ps);							//initialize timer with a prescaler
#define tmr3Get()			(TIM3->CNT)				//get counter value
#define tmr3SetPS(ps)		TIM3->PSC = (ps) - 1ul		//set prescaler
#define tmr3GetPS()			(TIM3->PSC + 1ul)		//get prescaler
#define tmr3SetPR(pr)		TIM3->ARR = (pr) - 1	//void tmr3SetPR(uint16_t pr);						//set period for ovf interupt
#define tmr3GetPR()			(TIM3->ARR + 1ul)		
void tmr3OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr3OC1SetPR(uint16_t pr);						//set period
void tmr3OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr3OC2SetPR(uint16_t pr);						//set period
void tmr3OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr3OC3SetPR(uint16_t pr);						//set period
void tmr3OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr3OC4SetPR(uint16_t pr);						//set period
void tmr3OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr3IC1Init(uint8_t ps);								//activate input capture
#define tmr3CC1Get()		tmrCC1Get(TIM3)			//get compare / capture value
void tmr3IC2Init(uint8_t ps);								//activate input capture
#define tmr3CC2Get()		tmrCC2Get(TIM3)			//get compare / capture value
void tmr3IC3Init(uint8_t ps);								//activate input capture
#define tmr3CC3Get()		tmrCC3Get(TIM3)			//get compare / capture value
void tmr3IC4Init(uint8_t ps);								//activate input capture
#define tmr3CC4Get()		tmrCC4Get(TIM3)			//get compare / capture value

//initialize the timer6 (16bit)
void tmr6Init(uint16_t ps);							//initialize timer with a prescaler
#define tmr6Get()			(TIM6->CNT)				//get counter value
#define tmr6SetPS(ps)		TIM6->PSC = (ps) - 1ul		//set prescaler
#define tmr6GetPS()			(TIM6->PSC + 1ul)		//get prescaler
#define tmr6SetPR(pr)		TIM6->ARR = (pr) - 1	//void tmr6SetPR(uint16_t pr);						//set period for ovf interupt
#define tmr6GetPR()			(TIM6->ARR + 1ul)		
void tmr6OVFAttachISR(void (*isrptr)(void));		//activate the isr handler

//initialize the timer14 (16bit)
void tmr14Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr14Get()			(TIM14->CNT)				//get counter value
#define tmr14SetPS(ps)		TIM14->PSC = (ps) - 1ul		//set prescaler
#define tmr14GetPS()		(TIM14->PSC + 1ul)		//get prescaler
#define tmr14SetPR(pr)		TIM14->ARR = (pr) - 1	//void tmr14SetPR(uint16_t pr);						//set period
#define tmr14GetPR()		(TIM14->ARR + 1ul)		
void tmr14OVFAttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//output compare
void tmr14OC1SetPR(uint16_t pr);					//set period
void tmr14OC1AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
void tmr14OC2SetPR(uint16_t pr);					//set period
void tmr14OC2AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//input capture
void tmr14IC1Init(uint8_t ps);								//activate input capture
#define tmr14CC1Get()		tmrCC1Get(TIM14)			//get compare / capture value
void tmr14IC2Init(uint8_t ps);								//activate input capture
#define tmr14CC2Get()		tmrCC2Get(TIM14)			//get compare / capture value

//initialize the timer15 (16bit)
void tmr15Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr15Get()			(TIM15->CNT)				//get counter value
#define tmr15SetPS(ps)		TIM15->PSC = (ps) - 1ul		//set prescaler
#define tmr15GetPS()		(TIM15->PSC + 1ul)		//get prescaler
#define tmr15SetPR(pr)		TIM15->ARR = (pr) - 1	//void tmr15SetPR(uint16_t pr);						//set period
#define tmr15GetPR()		(TIM15->ARR + 1ul)		
void tmr15OVFAttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//output compare
void tmr15OC1SetPR(uint16_t pr);					//set period
void tmr15OC1AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
void tmr15OC2SetPR(uint16_t pr);					//set period
void tmr15OC2AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//input capture
void tmr15IC1Init(uint8_t ps);								//activate input capture
#define tmr15CC1Get()		tmrCC1Get(TIM15)			//get compare / capture value
void tmr15IC2Init(uint8_t ps);								//activate input capture
#define tmr15CC2Get()		tmrCC2Get(TIM15)			//get compare / capture value

//initialize the timer16 (16bit)
void tmr16Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr16Get()			(TIM16->CNT)				//get counter value
#define tmr16SetPS(ps)		TIM16->PSC = (ps) - 1ul		//set prescaler
#define tmr16GetPS()		(TIM16->PSC + 1ul)		//get prescaler
#define tmr16SetPR(pr)		TIM16->ARR = (pr) - 1	//void tmr16SetPR(uint16_t pr);						//set period
#define tmr16GetPR()		(TIM16->ARR + 1ul)		
void tmr16OVFAttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//output compare
void tmr16OC1SetPR(uint16_t pr);					//set period
void tmr16OC1AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
void tmr16OC2SetPR(uint16_t pr);					//set period
void tmr16OC2AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//input capture
void tmr16IC1Init(uint8_t ps);								//activate input capture
#define tmr16CC1Get()		tmrCC1Get(TIM16)			//get compare / capture value
void tmr16IC2Init(uint8_t ps);								//activate input capture
#define tmr16CC2Get()		tmrCC2Get(TIM16)			//get compare / capture value

//initialize the timer17 (16bit)
void tmr17Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr17Get()			(TIM17->CNT)				//get counter value
#define tmr17SetPS(ps)		TIM17->PSC = (ps) - 1ul		//set prescaler
#define tmr17GetPS()		(TIM17->PSC + 1ul)		//get prescaler
#define tmr17SetPR(pr)		TIM17->ARR = (pr) - 1	//void tmr17SetPR(uint16_t pr);						//set period
#define tmr17GetPR()		(TIM17->ARR + 1ul)		
void tmr17OVFAttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//output compare
void tmr17OC1SetPR(uint16_t pr);					//set period
void tmr17OC1AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
void tmr17OC2SetPR(uint16_t pr);					//set period
void tmr17OC2AttachISR(void (*isrptr)(void));		//activate the isr overflow handler
//input capture
void tmr17IC1Init(uint8_t ps);								//activate input capture
#define tmr17CC1Get()		tmrCC1Get(TIM17)			//get compare / capture value
void tmr17IC2Init(uint8_t ps);								//activate input capture
#define tmr17CC2Get()		tmrCC2Get(TIM17)			//get compare / capture value

//32-bit timers
//initialize tim31 as a synchronized 32-bit timer
//tim3 as master / lsw (including prescaler) to tim1 / msw of the 32-bit timer
//tim1 as slave / msw of the 32-bit timer
void tmr12Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr12Get(void);				//read 32-bit timer value
uint64_t tmr12SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr12GetPR(void);				//read 32-bit timer period
#define tmr12SetPS(ps)					tmr1SetPS(ps)
#define tmr12GetPS()					tmr1GetPS()
#define tmr12OVFAttachISR(isrptr)		tmr2OVFAttachISR(isrptr)		//activate the isr handler

void tmr13Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr13Get(void);				//read 32-bit timer value
uint32_t tmr13SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr13GetPR(void);				//read 32-bit timer period
#define tmr13SetPS(ps)					tmr1SetPS(ps)
#define tmr13GetPS()					tmr1GetPS()
#define tmr13OVFAttachISR(isrptr)		tmr3OVFAttachISR(isrptr)		//activate the isr handler

//name convention conflict
//void tmr14Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
//uint32_t tmr14Get(void);				//read 32-bit timer value
//uint32_t tmr14SetPR(uint32_t pr);		//set 32-bit timer period
//uint32_t tmr14GetPR(void);				//read 32-bit timer period
//#define tmr14SetPS(ps)					tmr1SetPS(ps)
//#define tmr14GetPS()					tmr1GetPS()
//#define tmr14OVFAttachISR(isrptr)		tmr3OVFAttachISR(isrptr)		//activate the isr handler

//initialize tim21 as a synchronized 48-bit timer
//tim2 as master / lsw (including prescaler) to tim1 / msw of the 48-bit timer
//tim1 as slave / msw of the 48-bit timer
void tmr21Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr21Get(void);				//read 32-bit timer value
uint64_t tmr21SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr21GetPR(void);				//read 32-bit timer period
#define tmr21SetPS(ps)					tmr2SetPS(ps)
#define tmr21GetPS()					tmr2GetPS()
#define tmr21OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr23Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr23Get(void);				//read 32-bit timer value
uint64_t tmr23SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr23GetPR(void);				//read 32-bit timer period
#define tmr23SetPS(ps)					tmr2SetPS(ps)
#define tmr23GetPS()					tmr2GetPS()
#define tmr23OVFAttachISR(isrptr)		tmr3OVFAttachISR(isrptr)		//activate the isr handler

void tmr24Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr24Get(void);				//read 32-bit timer value
uint64_t tmr24SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr24GetPR(void);				//read 32-bit timer period
#define tmr24SetPS(ps)					tmr2SetPS(ps)
#define tmr24GetPS()					tmr2GetPS()
#define tmr24OVFAttachISR(isrptr)		tmr4OVFAttachISR(isrptr)		//activate the isr handler

void tmr215Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr215Get(void);				//read 32-bit timer value
uint64_t tmr215SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr215GetPR(void);				//read 32-bit timer period
#define tmr215SetPS(ps)					tmr2SetPS(ps)
#define tmr215GetPS()					tmr2GetPS()
#define tmr215OVFAttachISR(isrptr)		tmr15OVFAttachISR(isrptr)		//activate the isr handler

void tmr31Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr31Get(void);				//read 32-bit timer value
uint32_t tmr31SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr31GetPR(void);				//read 32-bit timer period
#define tmr31SetPS(ps)					tmr3SetPS(ps)
#define tmr31GetPS()					tmr3GetPS()
#define tmr31OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr32Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr32Get(void);				//read 32-bit timer value
uint64_t tmr32SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr32GetPR(void);				//read 32-bit timer period
#define tmr32SetPS(ps)					tmr3SetPS(ps)
#define tmr32GetPS()					tmr3GetPS()
#define tmr32OVFAttachISR(isrptr)		tmr2OVFAttachISR(isrptr)		//activate the isr handler

void tmr315Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr315Get(void);				//read 32-bit timer value
uint32_t tmr315SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr315GetPR(void);			//read 32-bit timer period
#define tmr315SetPS(ps)					tmr3SetPS(ps)
#define tmr315GetPS()					tmr3GetPS()
#define tmr315OVFAttachISR(isrptr)		tmr15OVFAttachISR(isrptr)		//activate the isr handler

void tmr142Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr142Get(void);				//read 32-bit timer value
uint64_t tmr142SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr142GetPR(void);				//read 32-bit timer period
#define tmr142SetPS(ps)					tmr14SetPS(ps)
#define tmr142GetPS()					tmr14GetPS()
#define tmr142OVFAttachISR(isrptr)		tmr2OVFAttachISR(isrptr)		//activate the isr handler

void tmr143Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr143Get(void);				//read 32-bit timer value
uint32_t tmr143SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr143GetPR(void);				//read 32-bit timer period
#define tmr143SetPS(ps)					tmr14SetPS(ps)
#define tmr143GetPS()					tmr14GetPS()
#define tmr143OVFAttachISR(isrptr)		tmr3OVFAttachISR(isrptr)		//activate the isr handler

void tmr144Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr144Get(void);				//read 32-bit timer value
uint32_t tmr144SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr144GetPR(void);				//read 32-bit timer period
#define tmr144SetPS(ps)					tmr14SetPS(ps)
#define tmr144GetPS()					tmr14GetPS()
#define tmr144OVFAttachISR(isrptr)		tmr4OVFAttachISR(isrptr)		//activate the isr handler

void tmr151Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr151Get(void);				//read 32-bit timer value
uint32_t tmr151SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr151GetPR(void);			//read 32-bit timer period
#define tmr151SetPS(ps)					tmr15SetPS(ps)
#define tmr151GetPS()					tmr15GetPS()
#define tmr151OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr152Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint64_t tmr152Get(void);				//read 32-bit timer value
uint64_t tmr152SetPR(uint64_t pr);		//set 32-bit timer period
uint64_t tmr152GetPR(void);				//read 32-bit timer period
#define tmr152SetPS(ps)					tmr15SetPS(ps)
#define tmr152GetPS()					tmr15GetPS()
#define tmr152OVFAttachISR(isrptr)		tmr2OVFAttachISR(isrptr)		//activate the isr handler

void tmr153Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr153Get(void);				//read 32-bit timer value
uint32_t tmr153SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr153GetPR(void);				//read 32-bit timer period
#define tmr153SetPS(ps)					tmr15SetPS(ps)
#define tmr153GetPS()					tmr15GetPS()
#define tmr153OVFAttachISR(isrptr)		tmr3OVFAttachISR(isrptr)		//activate the isr handler

void tmr154Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr154Get(void);				//read 32-bit timer value
uint32_t tmr154SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr154GetPR(void);				//read 32-bit timer period
#define tmr154SetPS(ps)					tmr15SetPS(ps)
#define tmr154GetPS()					tmr15GetPS()
#define tmr154OVFAttachISR(isrptr)		tmr4OVFAttachISR(isrptr)		//activate the isr handler

void tmr1615Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr1615Get(void);				//read 32-bit timer value
uint32_t tmr1615SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr1615GetPR(void);				//read 32-bit timer period
#define tmr1615SetPS(ps)				tmr16SetPS(ps)
#define tmr1615GetPS()					tmr16GetPS()
#define tmr1615OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr171Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr171Get(void);				//read 32-bit timer value
uint32_t tmr171SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr171GetPR(void);			//read 32-bit timer period
#define tmr171SetPS(ps)					tmr17SetPS(ps)
#define tmr171GetPS()					tmr17GetPS()
#define tmr171OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr1715Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr1715Get(void);				//read 32-bit timer value
uint32_t tmr1715SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr1715GetPR(void);			//read 32-bit timer period
#define tmr1715SetPS(ps)				tmr17SetPS(ps)
#define tmr1715GetPS()					tmr17GetPS()
#define tmr1715OVFAttachISR(isrptr)		tmr15OVFAttachISR(isrptr)		//activate the isr handler


//global variables

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm1Init(uint16_t TxCCP_PS);
#define pwm1GetPS()			tmr1GetPS()
#define pwm1SetPS(ps)		tmr1SetPS(ps)
#define pwm1GetPR()			tmr1GetPR()
#define pwm1SetPR(pr)		tmr1SetPR(pr)
//set duty cycle
#define pwm1SetDC1(dc)		TIM1->CCR1 = (dc)
#define pwm1SetDC2(dc)		TIM1->CCR2 = (dc)
#define pwm1SetDC3(dc)		TIM1->CCR3 = (dc)
#define pwm1SetDC4(dc)		TIM1->CCR4 = (dc)
#define pwm1GetDC1()		(TIM1->CCR1)
#define pwm1GetDC2()		(TIM1->CCR2)
#define pwm1GetDC3()		(TIM1->CCR3)
#define pwm1GetDC4()		(TIM1->CCR4)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm3Init(uint16_t TxCCP_PS);
#define pwm3GetPS()			tmr3GetPS()
#define pwm3SetPS(ps)		tmr3SetPS(ps)
#define pwm3GetPR()			tmr3GetPR()
#define pwm3SetPR(pr)		tmr3SetPR(pr)
//set duty cycle
#define pwm3SetDC1(dc)		TIM3->CCR1 = (dc)
#define pwm3SetDC2(dc)		TIM3->CCR2 = (dc)
#define pwm3SetDC3(dc)		TIM3->CCR3 = (dc)
#define pwm3SetDC4(dc)		TIM3->CCR4 = (dc)
#define pwm3GetDC1()		(TIM3->CCR1)
#define pwm3GetDC2()		(TIM3->CCR2)
#define pwm3GetDC3()		(TIM3->CCR3)
#define pwm3GetDC4()		(TIM3->CCR4)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm14Init(uint16_t TxCCP_PS);
#define pwm14GetPS()		tmr14GetPS()
#define pwm14SetPS(ps)		tmr14SetPS(ps)
#define pwm14GetPR()		tmr14GetPR()
#define pwm14SetPR(pr)		tmr14SetPR(pr)
//set duty cycle
#define pwm14SetDC1(dc)		TIM14->CCR1 = (dc)
#define pwm14SetDC2(dc)		TIM14->CCR2 = (dc)
#define pwm14SetDC3(dc)		TIM14->CCR3 = (dc)
#define pwm14SetDC4(dc)		TIM14->CCR4 = (dc)
#define pwm14GetDC1()		(TIM14->CCR1)
#define pwm14GetDC2()		(TIM14->CCR2)
#define pwm14GetDC3()		(TIM14->CCR3)
#define pwm14GetDC4()		(TIM14->CCR4)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm15Init(uint16_t TxCCP_PS);
#define pwm15GetPS()		tmr15GetPS()
#define pwm15SetPS(ps)		tmr15SetPS(ps)
#define pwm15GetPR()		tmr15GetPR()
#define pwm15SetPR(pr)		tmr15SetPR(pr)
//set duty cycle
#define pwm15SetDC1(dc)		TIM15->CCR1 = (dc)
#define pwm15SetDC2(dc)		TIM15->CCR2 = (dc)
#define pwm15SetDC3(dc)		TIM15->CCR3 = (dc)
#define pwm15SetDC4(dc)		TIM15->CCR4 = (dc)
#define pwm15GetDC1()		(TIM15->CCR1)
#define pwm15GetDC2()		(TIM15->CCR2)
#define pwm15GetDC3()		(TIM15->CCR3)
#define pwm15GetDC4()		(TIM15->CCR4)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm16Init(uint16_t TxCCP_PS);
#define pwm16GetPS()		tmr16GetPS()
#define pwm16SetPS(ps)		tmr16SetPS(ps)
#define pwm16GetPR()		tmr16GetPR()
#define pwm16SetPR(pr)		tmr16SetPR(pr)
//set duty cycle
#define pwm16SetDC1(dc)		TIM16->CCR1 = (dc)
#define pwm16SetDC2(dc)		TIM16->CCR2 = (dc)
#define pwm16SetDC3(dc)		TIM16->CCR3 = (dc)
#define pwm16SetDC4(dc)		TIM16->CCR4 = (dc)
#define pwm16GetDC1()		(TIM16->CCR1)
#define pwm16GetDC2()		(TIM16->CCR2)
#define pwm16GetDC3()		(TIM16->CCR3)
#define pwm16GetDC4()		(TIM16->CCR4)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm17Init(uint16_t TxCCP_PS);
#define pwm17GetPS()		tmr17GetPS()
#define pwm17SetPS(ps)		tmr17SetPS(ps)
#define pwm17GetPR()		tmr17GetPR()
#define pwm17SetPR(pr)		tmr17SetPR(pr)
//set duty cycle
#define pwm17SetDC1(dc)		TIM17->CCR1 = (dc)
#define pwm17SetDC2(dc)		TIM17->CCR2 = (dc)
#define pwm17SetDC3(dc)		TIM17->CCR3 = (dc)
#define pwm17SetDC4(dc)		TIM17->CCR4 = (dc)
#define pwm17GetDC1()		(TIM17->CCR1)
#define pwm17GetDC2()		(TIM17->CCR2)
#define pwm17GetDC3()		(TIM17->CCR3)
#define pwm17GetDC4()		(TIM17->CCR4)

//adc
//adc channel definitions
#define ADC_CH0			(0)
#define ADC_CH1			(1)
#define ADC_CH2			(2)
#define ADC_CH3			(3)
#define ADC_CH4			(4)
#define ADC_CH5			(5)
#define ADC_CH6			(6)
#define ADC_CH7			(7)
#define ADC_CH8			(8)
#define ADC_CH9			(9)
#define ADC_CH10		(10)
#define ADC_CH11		(11)
#define ADC_CH12		(12)
#define ADC_CH13		(13)
#define ADC_CH14		(14)
#define ADC_CH15		(15)
#define ADC_CH16		(16)
#define ADC_CH17		(17)
#define ADC_CH18		(18)
#define ADC_TS			ADC_CH16				//tempeature sensor on CH16
#define ADC_VREFINT		ADC_CH17				//internal reference on CH17 @ 1.20v
#define ADC_TEMP		ADC_TS					//tempreature sensor
#define ADC_VREF		ADC_VREFINT				//internal reference
#define ADC_ARAND		ADC_VREFINT				//the channel for random number generators

//calibration for temperature sensors, 12 bits
#define TSCAL1			((*(int32_t *) 0x1ffff7b8) & 0x0fff)		//~1761 @ 30c
#define TSCAL2			((*(int32_t *) 0x1ffff7c2) & 0x0fff)		//~1320 @ 110c: this means that as temperature rises, adc readings decline -> contradicts the datasheet
#define VREFCAL			((*(int32_t *) 0x1ffff7ba) & 0x0fff)		//~1535

//helper macros
//two alternatives to calture temperature
//measurements in 0.01C or 0.01F
#define ADC2Cx100(adc)		((11000 - 3000) * ((adc) * VDDAmv / 3000 - TSCAL1) / (TSCAL2 - TSCAL1) + 3000)			//'-' added to reflect the fact that adc readings should decline as temperature rises
//#define ADC2Cx100(adc)		((1430 - ADC2mv(adc)) * 10 * 100 / (43) + 2500)					//per datasheet, using average slope. 
#define ADC2Fx100(adc)		(ADC2Cx100(adc) * 9 / 5 + 3200)
#define VREFadc			1489l					//VREF ADC reading on the target system
#define VREFmv			1200l					//Vref voltage in mv
#define VDDAmv			(VREFmv * 4096 / VREFadc)	//VADD=3.3v
#define ADC2mv(adc)		((adc) * VDDAmv / 4096)	//convert 12-bit adc to mv

//rest the adc
//automatic sampling (ASAM=1), manual conversion
void adc1Init(void);
int32_t adc1Read(uint32_t adc_ch);

//read the adc
#define analogRead(ch)	adc1Read(ch)
//end ADC

//input capture
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic1Init(void);
void ic1AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic1Get(void);							//read buffer value

void ic2Init(void);
void ic2AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic2Get(void);							//read buffer value

void ic3Init(void);
void ic3AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic3Get(void);							//read buffer value

void ic4Init(void);
void ic4AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic4Get(void);							//read buffer value

void ic5Init(void);
void ic5AttachISR(void (*isrptr)(void));		//activate user ptr
uint16_t ic5Get(void);							//read buffer value
//end input capture

//int
void int0Init(void);							//initialize the module
void int0AttachISR(void (*isrptr) (void));		//attach user isr

void int1Init(void);							//initialize the module
void int1AttachISR(void (*isrptr) (void));		//attach user isr

void int2Init(void);							//initialize the module
void int2AttachISR(void (*isrptr) (void));		//attach user isr

void int3Init(void);							//initialize the module
void int3AttachISR(void (*isrptr) (void));		//attach user isr

void int4Init(void);							//initialize the module
void int4AttachISR(void (*isrptr) (void));		//attach user isr
//end int

//spi
void spi1Init(uint32_t br);							//reset the spi
#define spi1Busy()			(SPI1->SR & SPI_SR_BSY)	//transmit buffer full, must wait before writing to SPIxBUF
#define spi1Avail()			(SPI1->SR & SPI_SR_RXNE)	//receive buffer not empty -> there is data
#define spi1Wait()			while (spi1Busy()) continue
#define spi1Write(dat)		do {spi1Wait(); SPI1->DR = (dat);} while (0)
#define spi1Read()			(SPI1->DR)				//read from the buffer

void spi2Init(uint32_t br);							//reset the spi
#define spi2Busy()			(SPI2->SR & SPI_SR_BSY)	//transmit buffer full, must wait before writing to SPIxBUF
#define spi2Avail()			(SPI2->SR & SPI_SR_RXNE)	//receive buffer not empty -> there is data
#define spi2Wait()			while (spi2Busy()) continue
#define spi2Write(dat)		do {spi2Wait(); SPI2->DR = (dat);} while (0)
#define spi2Read()			(SPI2->DR)				//read from the buffer
//end spi


//i2c
void i2c1Init(uint32_t br);							//i2c1 initialization
//end i2c

//rtc
//bcd to dec conversion
#define BCD2DEC(bcd)				((((bcd) & 0xf0)>>4)*10+((bcd) & 0x0f))		//convert bcd to int
#define DEC2BCD(dec)				(((((dec) / 10)<<4) +((dec) % 10)) & 0xff)	//convert int to bcd
//initialize the rtc
//prep: see RTC_PREP in the datasheet
//rtc_clk: RCC_BDCR_RTCSEL_LSI, RCC_BDCR_RTCSEL_LSE and RCC_BDCR_RTCSEL_HSE
//prep consists of a 7-bit prediv_a (msb) and 15-bit prediv_b (lsb)
void RTCInit(uint32_t rtc_clk, uint32_t prep);					//initialize rtc
#define RTCInitLSI()				RTCInit(RCC_BDCR_RTCSEL_LSI, F_LSI)
#define RTCInitLSE()				RTCInit(RCC_BDCR_RTCSEL_LSE, F_LSE)
#define RTCInitHSE()				RTCInit(RCC_BDCR_RTCSEL_HSE, F_HSE/32)
void RTCSetTime(uint32_t val);									//set rtc time
#define RTCGetTime()				(RTC->TR)					//get rtc time
#define RTCGetSec()					BCD2DEC(((RTCGetTime() >> 0) & 0x7f))	//get rtc sec
#define RTCGetMin()					BCD2DEC(((RTCGetTime() >> 8) & 0x7f))	//get rtc min
#define RTCGetHour()				BCD2DEC(((RTCGetTime() >>16) & 0x3f))	//get rtc hour
void RTCSetDate(uint32_t val);									//set rtc date
#define RTCGetDate()				(RTC->DR)					//get rtc date
#define RTCGetDay()					BCD2DEC(((RTCGetDate() >> 0) & 0x3f))	//get rtc day
#define RTCGetMonth()				BCD2DEC(((RTCGetDate() >> 8) & 0x1f))	//get rtc month
#define RTCGetWDay()				BCD2DEC(((RTCGetDate() >>13) & 0x07))	//get rtc wday (1..7, 0 forbidden)
#define RTCGetYear()				BCD2DEC(((RTCGetDate() >>16) & 0xff))	//get rtc year
time_t RTC2time(time_t *t);			//convert rtcc to time_t
time_t time2RTC(time_t t);			//turn time (=time_t) to RTCC
int16_t RTCSetCal(int16_t cal);		//set calibration
int16_t RTCGetCal(void);			//set calibration
uint8_t RTCHalfsec(void);			//test for subsecond: 0->first half of a second, 1->second half of a second
//end rtcc

//software rtc

//global variables
typedef struct {
	time_t time;						//second counter since 1/1/1970
	uint32_t tick;						//tick counter at last update
	int16_t cal;						//rtc calibration, in ppm. +=faster, -=slower
	uint8_t halfsec;					//0=first half sec, 1=2nd half sec
} sRTC_TypeDef;

void sRTCInit(void);					//initialize software counter //calibration from -128ppm to +128ppm, if sRTC_RATE = 1M
void sRTCSetCal(int16_t cal);			//set sRTC calibration
void sRTCISR(void);						//increment -> called sRTC_CALLRATE times per second
#define sRTCUpdate()	sRTCISR()		//for compatability
uint32_t sRTCTick(void);				//read rtc tick
time_t sRTC2time(time_t *t);			//read sRTC second counter
time_t time2sRTC(time_t t);				//set sRTC second counter
uint8_t sRTCHalfsec(void);				//return 0: first half of a sec, 1: 2nd half of a sec
#define sRTCGetSec()	(sRTC2time(NULL) % 60)	//for compatability
//end software RTC

//extint
#define EXTI_FALLING	FALLING				//trigger on falling edge
#define EXTI_RISING		RISING				//trigger on rising edge
#define EXTI_BOTH		CHANGE				//trigger on falling and rising edges

//pin: one pin only
//gpio: GPIOA..GPIOG
void extiInit(PIN_TypeDef PINx, uint8_t edge);
void extiAttachISR(PIN_TypeDef PINx, void (*isr_ptr)(void));		//install user handler
//end extint

//analog random number generator
//random number generators
#define arand1()			(analogRead(ADC_ARAND) & 0x01)	//generate 1-bit random number
uint8_t arand4(void);							//generate 4-bit random numbers
uint8_t arand8(void);							//generate 8-bit random numbers
uint16_t arand16(void);							//generate 16-bit random numbers
uint32_t arand32(void);							//generate 32-bit random numbers
//end analog random number generator

//circular buffer

//circular buffer to store char
typedef struct {
    cbuffer_t buffer[cBUFF_SIZE];		//buffer
    uint8_t writeIndex;					//index for the current write-> advance first and then write
    uint8_t readIndex;					//index for the current read -> advance first and then read
} CB_TypeDef;

void cbInit(CB_TypeDef *cbuffer);		//reset the cbuffer
char cbEmpty(CB_TypeDef *cbuffer);		//returns true if cbuffer is empty
char cbFull(CB_TypeDef *cbuffer);		//returns true if cbuffer is full;
cbuffer_t cbWrite(CB_TypeDef *cbuffer, cbuffer_t dat);	//write to the buffer - needs to test if the buffer is full first
cbuffer_t cbRead(CB_TypeDef *cbuffer);	//read from the buffer - needs to test if the buffer is empty
void str2cb(CB_TypeDef *cb, char *str);	//write string to CB
void cb2str(char *str, CB_TypeDef *cb);	//write CB to string
//end circular buffer

//tamper backup registers
//unlock the domain
//on some chips, it requires a set of magic numbers
#define bkpUnlock()		do {PWR->CR |= PWR_CR_DBP;} while (!(PWR->CR & PWR_CR_DBP))	//1->enable write assess, 0->disable write assess
#define bkpLock()		do {PWR->CR &=~PWR_CR_DBP;} while ( (PWR->CR & PWR_CR_DBP))	//1->enable write assess, 0->disable write assess

//reset the tamper to use the backup registers
void bkpInit(void);


//read backup register: 0..4 on G030
#define bkp0Get(n)		(RTC->BKP0R)			//read bkp0
#define bkp0Set(val)	do {bkpUnlock(); RTC->BKP0R = (val); bkpLock();} while (0)		//write bkp0
#define bkp1Get(n)		(RTC->BKP1R)			//read bkp1
#define bkp1Set(val)	do {bkpUnlock(); RTC->BKP1R = (val); bkpLock();} while (0)		//write bkp1
#define bkp2Get(n)		(RTC->BKP2R)			//read bkp2
#define bkp2Set(val)	do {bkpUnlock(); RTC->BKP2R = (val); bkpLock();} while (0)		//write bkp2
#define bkp3Get(n)		(RTC->BKP3R)			//read bkp3
#define bkp3Set(val)	do {bkpUnlock(); RTC->BKP3R = (val); bkpLock();} while (0)		//write bkp3
#define bkp4Get(n)		(RTC->BKP4R)			//read bkp4
#define bkp4Set(val)	do {bkpUnlock(); RTC->BKP4R = (val); bkpLock();} while (0)		//write bkp4

#endif
