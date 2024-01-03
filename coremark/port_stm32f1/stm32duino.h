#ifndef _STM32DUINO_H
#define _STM32DUINO_H

//STM32duino code
// - using STM32F100 / STM32F103 chips
// - free running systick for ticks
// - 
// - version history
// - v2.0, 5/22/2021: simplified port
// - v2.1, 9/17/2022: updated port
// - v2.2, 9/23/2022: support STM32F100 chips
// - v2.2a,10/29/2022:implemented clock switching
// - v2.2b,12/04/2022:implemented circular buffer + analog random number generator
// - v2.2c,01/28/2023:fixed pll errors
// - v2.2d,02/18/2023:added support for rtc
// - v2.2e,03/25/2023:added support for chained 32-bit timers
// - v2.2f,10/21/2023:added support for tamper / backup registers
// - v2.2g,12/07/2023:unified support for value-line chips
//
//
//
//               STM32F103
//      Vdd     |=====================|
//       |      |                     |
//       +------| Vdd            PA14 |<----- SWCLK
//              |                     |
//       +------| BOOT0          PA13 |<----> SWDIO
//              |                     |
//              |                     |
//   GND<-------| Vss            PC13 |>----> LED [must disable to use LSE]
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
//              |                     |
//              |=====================|
//
//
//

#include <stm32f10x.h>								//we use STM32F100/103
#include <string.h>									//we use strcpy()
#include <stdint.h>									//we use standard datatypes
#include <time.h>									//we use time routines

//hardware configuration
#if defined(DWT)									//if dwt is present, use it for tick time base
#define USE_CORETICK								//use coretick/DWT as time base. comment out if DWT is used
#endif
#define uRAM_SIZE			40						//uart transmission buffer size

//oscillator configuration
#define F_XTAL				8000000ul				//crystal frequency, user-specified
#define F_LSE				32768					//LSE frequency - user-specified

//configuration for circular buffer
/*******NOTE********************************/
/******cBUFF_SIZE: must be power of 2*******/
/*******************************************/
#define cBUFF_SIZE 			32						//must be power of 2: 0..256 -> for buffers with more than 256 elements, change data type for writeIndex/readIndex
typedef char cbuffer_t;								//storage unit for the buffer
//end configuration for circular buffer
//end user specification

//pin configuration
#define U1TX2PIN()			U1TX2PA9()				//PA9, PB6
//#define U1RX2PIN()			U1RX2PA10()				//PA10,PB7
#define U2TX2PIN()			U2TX2PA2()				//PA2, PD5 (remap)
//#define U2RX2PIN()			U2RX2PA3()				//PA3, PD6 (remap)
#define U3TX2PIN()			U3TX2PB10()				//PB10,PC10, PD8
//#define U3RX2PIN()			U3RX2PB11()				//PB11,PC11, PD9
//#define U4TX2PIN()			U4TX2PB10()				//to be defined
//#define U4RX2PIN()			U4RX2PB11()				//to be defined
//#define U5TX2PIN()			U5TX2PB10()				//to be defined
//#define U5RX2PIN()			U5RX2PB11()				//to be defined

//pin configuration for timer IC/OC/PWM output pins
//tim1: 
//#define TIM1CH1toPIN()		TIM1CH1toPA8()			//PA8, PE9
//#define TIM1CH2toPIN()		TIM1CH2toPA9()			//PA9, PE11
//#define TIM1CH3toPIN()		TIM1CH3toPA10()			//PA10,PE13
//#define TIM1CH4toPIN()		TIM1CH4toPA11()			//PA11,PE14
//#define TIM1CH1NtoPIN()		TIM1CH1NtoPA7()			//PA7, PE8, PB13
//#define TIM1CH2NtoPIN()		TIM1CH2NtoPB0()			//PB0, PE10,PB14
//#define TIM1CH3NtoPIN()		TIM1CH3NtoPB1()			//PB1, PE12,PB15
//#define TIM1CH4NtoPIN()								//no pin out

//tim2
//#define TIM2CH1toPIN()		TIM2CH1toPA0()			//PA0, PA15
//#define TIM2CH2toPIN()		TIM2CH2toPA1()			//PA1, PB3
//#define TIM2CH3toPIN()		TIM2CH3toPA2()			//PA2, PB10
//#define TIM2CH4toPIN()		TIM2CH4toPA3()			//PA3, PB11

//tim3
//#define TIM3CH1toPIN()		TIM3CH1toPA6()			//PA6, PC6, PB4
//#define TIM3CH2toPIN()		TIM3CH2toPA7()			//PA7, PC7, PB5
//#define TIM3CH3toPIN()		TIM3CH3toPC8()			//PB0, PC8, 
//#define TIM3CH4toPIN()		TIM3CH4toPC9()			//PB1, PC9

//tim4
//#define TIM4CH1toPIN()		TIM4CH1toPB6()			//PB6, PD12
//#define TIM4CH2toPIN()		TIM4CH2toPB7()			//PB7, PD13
//#define TIM4CH3toPIN()		TIM4CH3toPB8()			//PB8, PD14
//#define TIM4CH4toPIN()		TIM4CH4toPB9()			//PB9, PD15

//tim15/16/17
//#define TIM15CH1toPIN()		TIM15CH1toPA2()			//PA2, PB14
//#define TIM15CH2toPIN()		TIM15CH2toPA3()			//PA3, PB15
//#define TIM15CH1NtoPIN()		TIM15CH1NtoPB15()		//PB15

//#define TIM16CH1toPIN()		TIM16CH1toPB8()			//PB8, PA6
//#define TIM16CH1NtoPIN()		TIM16CH1NtoPB6()		//PB6

//#define TIM17CH1toPIN()		TIM17CH1toPB9()			//PB9, PA7
//#define TIM17CH1NtoPIN()		TIM17CH1NtoPB7()		//PB7

//deprecated
//#define TIM1REMAP				TIM1REMAP3				//select TIMER1 remap scheme 0..3
//#define TIM2REMAP				TIM2REMAP3				//select TIMER2 remap scheme 0..3
//#define TIM3REMAP				TIM3REMAP3				//select TIMER3 remap scheme 0..3
//#define TIM4REMAP				TIM4REMAP1				//select TIMER4 remap scheme 0..3

//i2c
//#define SCL1toPIN()			SCL1toPB6()				//PB4, PB8
//#define SDA1toPIN()			SDA1toPB7()				//PB7, PB9

//spi1
//#define NSS1toPIN()			NSS1toPA4()				//PA4, PA15
//#define SCK1toPIN()			SCK1toPA5()				//PA5, PB3
//#define MISO1toPIN()			MISO1toPA6()			//PA6, PB3
//#define MOSItoPIN()			MOSI1toPA7()			//PA7, PB5

//spi2

//spi3
//#define NSS3toPIN()			NSS3toPA15()			//PA15, PA4
//#define SCK3toPIN()			SCK3toPB3()				//PB3, PC10
//#define MISO3toPIN()			MISO3toPB4()			//PB4, PC11
//#define MOSI3toPIN()			MOSI3toPB5()			//PB5, PC12

//othres
//mco
#define MCOtoPA8()			do {GIO_AFPP(GPIOA, 1<< 8);} while (0)
//enable pb3/4 for gpio on afio - no swd after this
#define SWD2GPIO()			do {RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_SWJ_CFG) | AFIO_MAPR_SWJ_CFG_JTAGDISABLE;} while (0)
#define SWD2Reset()			do {RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_SWJ_CFG) | AFIO_MAPR_SWJ_CFG_RESET;} while (0)		//restore pins to swd
//end pin configuration

uint32_t AHBClock(void);							//ahb clock
uint32_t APB1Clock(void);							//apb1 clock
uint32_t APB2Clock(void);							//apb2 clock
#define F_PHB				(F_APB1)				//cpu runs at 8Mhz/2 by default -> Fxtal = 8Mhz. *4 for PLL. RCDIV set to 0 (1:1 postscaler)
#define F_CPU				(SystemCoreClock)		//peripheral block runs at F_PHB - default = F_CPU / 1
#define F_AHB				(AHBClock())			//ahb frequency, in hz
#define F_APB1				(APB1Clock())			//apb1 frequency, in hz
#define F_APB2				(APB2Clock())			//apb2 frequency, in hz
#define F_LSI				39863ul					//LSI frequency - calibrated for this particular chip: 39860Hz vs HSE. nominal 40Khz, from 30K - 60Khz, per ST
#define F_HSI				8000000ul				//HSI frequency, 8Mhz nominal. measured to be 7979100Hz on this particular chip. +/- 1%, per datasheet
#define F_HSE				F_XTAL					//HSE frequency
//#define HSITRIM				(+0)					//hsi trim, from -16 to 15, ~40Khz/step. use negative values if HSI is too fast. 
#define HSITrimSet(trim)	RCC->CR = (RCC->CR &~RCC_CR_HSITRIM) + (((16+(trim)) << 3) & RCC_CR_HSITRIM)	//16 is the default value
#define HSITrimGet()		((RCC->CR & RCC_CR_HSITRIM) >> 3)	//16 is the default value
#define HSICalGet()			((RCC->CR & RCC_CR_HSICAL) >> 8)	//factory calibration rating
#define PWM_PR				0xffff					//pwm period - don't change

//tiny scheduler macro
#define TS_RUN_WHILE(cs)	if (cs)						//tiny scheduler macro
#define TSwhile(cs)			TS_RUN_WHILE(cs)			//shorter macro

//port manipulation macros for PIC.
//operate on a var
#define REG_EQU(var, bits)					var  = (bits)
#define REG_SET(var, bits)					var |= (bits)
#define REG_CLR(var, bits)					var &=~(bits)
#define REG_FLP(var, bits)					var ^= (bits)
#define REG_GET(var, bits)					((var) & (bits))
#define REG_MOD(var, bits, mask)			(var = ((var) &~(mask)) | ((bits) & (mask)))

//port/gpio oriented macros
#define IO_SET(port, pins)					GIO_SET(port, pins)				//set bits on port
#define IO_CLR(port, pins)					GIO_CLR(port, pins)				//clear bits on port
#define IO_FLP(port, pins)					GIO_FLP(port, pins)				//flip bits on port
#define IO_GET(port, pins)					GIO_GET(port, pins)				//return bits on port
#define IO_OUT(port, pins)					IO_OUTPP(port, pins)
#define IO_OUTPP(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTPP)
#define IO_OUTPP10M(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTPP10M)
#define IO_OUTPP2M(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTPP2M)
#define IO_OUTPP50M(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTPP50M)
#define IO_OUTOD(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTOD)
#define IO_IN(port, pins)					IO_INFL(port, pins)
#define IO_INFL(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INFL)
#define IO_INPU(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INPU)	
#define IO_INPD(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INPD)	
#define IO_AFPP(port, pins)					GPIO_DDR(port, pins, GPIOMODE_AFPP)		//configure pin for alternative function output, push-pull, 10Mhz
#define IO_AFOD(port, pins)					GPIO_DDR(port, pins, GPIOMODE_AFOD)		//configure pin for alternative function output, open-drain, 10Mhz
#define IO_AN(port, pins)					GPIO_DDR(port, pins, GPIOMODE_INAN)

//fast routines through BRR/BSRR registers
#define FIO_SET(port, pins)					port->BSRR = (pins)
#define FIO_CLR(port, pins)					port->BRR  = (pins)
#define FIO_FLP(port, pins)					IO_FLP(port, pins)						//(IO_GET(port, pins)?FIO_CLR(port, pins):FIO_SET(port, pins))	//IO_FLP(port, pins)
#define FIO_GET(port, pins)					IO_GET(port, pins)

//gpio port based - deprecated
#define GIO_SET(port, pins)					REG_SET(port->ODR, pins)		//set bits on port
#define GIO_CLR(port, pins)					REG_CLR(port->ODR, pins)		//clear bits on port
#define GIO_FLP(port, pins)					REG_FLP(port->ODR, pins)		//flip bits on port
#define GIO_GET(port, pins)					REG_GET(port->IDR, pins)		//return bits on port
//set a pin to output/input
#define GIO_OUTPP(port, pins)				IO_OUTPP(port, pins)			//push-pull mode (CR1 set, CR2 cleared)	//IO_OUTPP(GPIOx, GPIO_Pins).
#define GIO_OUTOD(port, pins)				IO_OUTOD(port, pins)			//open drain mode (cr1 + cr2 cleared)	//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_OUT_OD_LOW_FAST)
#define GIO_OUT(port, pins)					IO_OUT(port, pins)				//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_OUT_PP_LOW_FAST)
#define GIO_INFL(port, pins)				IO_INFL(port, pins)				//floating input, no interrupt			//IO_INFL(GPIOx, GPIO_Pins)
#define GIO_INPU(port, pins)				IO_INPU(port, pins)				//pull-up, no interrupt					//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_PU_NO_IT)
#define GIO_INPD(port, pins)				IO_INPD(port, pins)				//pull-up, no interrupt					//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_PU_NO_IT)
#define GIO_IN(port, pins)					IO_IN(port, pins)				//IO_IN(port, pins)				//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_FL_NO_IT)
#define GIO_AFPP(port, pins)				IO_AFPP(port, pins)				//configure pin for alternative function output, push-pull, 10Mhz
#define GIO_AFOD(port, pins)				IO_AFOD(port, pins)				//configure pin for alternative function output, open-drain, 10Mhz
#define GIO_AN(port, pins)					IO_AN(port, pins)

//bit-banding on peripherals
#define PERI_BASE			PERIPH_BASE		//0x40000000
#define PERI_BB_BASE		PERIPH_BB_BASE	//(PERI_BASE + 0x02000000)
#define BIO2BB(addr, bit)	( (volatile uint32_t *) (PERI_BB_BASE | (((addr) - PERI_BASE) << 5) | ((bit) << 2)))
#define BIO_GET(port, bit)	(*BIO2BB((uint32_t) & (port->IDR), bit))
#define BIO_SET(port, bit)	(*BIO2BB((uint32_t) & (port->ODR), bit) = 1)
#define BIO_CLR(port, bit)	(*BIO2BB((uint32_t) & (port->ODR), bit) = 0)
#define BIO_FLP(port, bit)	( BIO_GET(port, bit)?BIO_CLR(port, bit):BIO_SET(port, bit))

//Arduino GPIO port
//gpio cnf1..0 + mod1..0
#define GPIOMODE_INAN		0x00			//0b0000->analog input
#define GPIOMODE_INFL		0x04			//0b0100->floating input
#define GPIOMODE_INPU		0x08			//0b1000->input, pull-up (odr=1)
#define GPIOMODE_INPD		0x08			//0b1000->input, pull-dn (odr=0)
#define GPIOMODE_OUTPP		GPIOMODE_OUTPP10M			//0b0001->pushpull output @ 10Mhz
#define GPIOMODE_OUTPP10M	0x01			//0b0001->pushpull output @ 10Mhz
#define GPIOMODE_OUTPP2M	0x02			//0b0001->pushpull output @ 2Mhz
#define GPIOMODE_OUTPP50M	0x03			//0b0001->pushpull output @ 50Mhz
#define GPIOMODE_OUTOD		0x09			//0b1001->open drain output @ 10Mhz
#define GPIOMODE_AFPP		0x09			//0b1001->alternative function output, push-pull, 10Mhz
#define GPIOMODE_AFOD		0x0d			//0b1101->alternative function output, open-drain, 10Mhz

//pin alternative config
//configure the RX-PA9/TX-PA10 pins - GPIO clock assumed enabled here previously
//uart1
#define U1TX2PA9()		    do {GIO_AFPP(GPIOA, 1<< 9); AFIO->MAPR &=~AFIO_MAPR_USART1_REMAP;} while (0)			//TX as AFPP
#define U1RX2PA10()			do {GIO_INFL(GPIOA, 1<<10); AFIO->MAPR &=~AFIO_MAPR_USART1_REMAP;} while (0)			//RX as floating input/AF input
#define U1TX2PB6()		    do {GIO_AFPP(GPIOB, 1<< 6); AFIO->MAPR |= AFIO_MAPR_USART1_REMAP;} while (0)			//TX as AFPP
#define U1RX2PB7()			do {GIO_INFL(GPIOB, 1<< 7); AFIO->MAPR |= AFIO_MAPR_USART1_REMAP;} while (0)			//RX as floating input/AF input
//uart2
#define U2TX2PA2()		    do {GIO_AFPP(GPIOA, 1<< 2); AFIO->MAPR &=~AFIO_MAPR_USART2_REMAP;} while (0)			//TX as AFPP
#define U2RX2PA3()			do {GIO_INFL(GPIOA, 1<< 3); AFIO->MAPR &=~AFIO_MAPR_USART2_REMAP;} while (0)			//RX as floating input/AF input
#define U2TX2PD5()		    do {GIO_AFPP(GPIOD, 1<< 5); AFIO->MAPR |= AFIO_MAPR_USART2_REMAP;} while (0)			//remap uart2tx to pd5
#define U2RX2PD6()			do {GIO_INFL(GPIOD, 1<< 6); AFIO->MAPR |= AFIO_MAPR_USART2_REMAP;} while (0)			//remap uart2rx to pd6			//RX as floating input/AF input
//uart3
#define U3TX2PB10()		    do {GIO_AFPP(GPIOB, 1<<10); AFIO->MAPR =(AFIO->MAPR &~AFIO_MAPR_USART3_REMAP) | (0x00 << 4);} while (0)			//TX as AFPP
#define U3RX2PB11()			do {GIO_INFL(GPIOB, 1<<11); AFIO->MAPR =(AFIO->MAPR &~AFIO_MAPR_USART3_REMAP) | (0x00 << 4);} while (0)			//RX as floating input/AF input
#define U3TX2PC10()		    do {GIO_AFPP(GPIOC, 1<<10); AFIO->MAPR =(AFIO->MAPR &~AFIO_MAPR_USART3_REMAP) | (0x01 << 4);} while (0)			//TX as AFPP
#define U3RX2PC11()			do {GIO_INFL(GPIOC, 1<<11); AFIO->MAPR =(AFIO->MAPR &~AFIO_MAPR_USART3_REMAP) | (0x01 << 4);} while (0)			//RX as floating input/AF input
#define U3TX2PD8()		    do {GIO_AFPP(GPIOD, 1<< 8); AFIO->MAPR =(AFIO->MAPR &~AFIO_MAPR_USART3_REMAP) | (0x03 << 4);} while (0)			//TX as AFPP
#define U3RX2PD9()			do {GIO_INFL(GPIOD, 1<< 9); AFIO->MAPR =(AFIO->MAPR &~AFIO_MAPR_USART3_REMAP) | (0x03 << 4);} while (0)			//RX as floating input/AF input

//timers
#define TIM1CH1toPA8()		do {GIO_AFPP(GPIOA, 1<< 8); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x00 << 6);} while (0)
#define TIM1CH1toPE9()		do {GIO_AFPP(GPIOE, 1<< 9); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x03 << 6);} while (0)
#define TIM1CH2toPA9()		do {GIO_AFPP(GPIOA, 1<< 9); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x00 << 6);} while (0)
#define TIM1CH2toPE11()		do {GIO_AFPP(GPIOE, 1<<11); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x03 << 6);} while (0)
#define TIM1CH3toPA10()		do {GIO_AFPP(GPIOA, 1<<10); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x00 << 6);} while (0)
#define TIM1CH3toPE13()		do {GIO_AFPP(GPIOE, 1<<13); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x03 << 6);} while (0)
#define TIM1CH4toPA11()		do {GIO_AFPP(GPIOA, 1<<11); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x00 << 6);} while (0)
#define TIM1CH4toPE14()		do {GIO_AFPP(GPIOE, 1<<14); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x03 << 6);} while (0)
#define TIM1CH1NtoPA7()		do {GIO_AFPP(GPIOA, 1<< 7); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x01 << 6);} while (0)
#define TIM1CH1NtoPB13()	do {GIO_AFPP(GPIOB, 1<<13); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x00 << 6);} while (0)
#define TIM1CH1NtoPE8()		do {GIO_AFPP(GPIOE, 1<< 8); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x03 << 6);} while (0)
#define TIM1CH2NtoPB0()		do {GIO_AFPP(GPIOB, 1<< 0); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x01 << 6);} while (0)
#define TIM1CH2NtoPB14()	do {GIO_AFPP(GPIOB, 1<<14); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x00 << 6);} while (0)
#define TIM1CH2NtoPE10()	do {GIO_AFPP(GPIOE, 1<<10); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x03 << 6);} while (0)
#define TIM1CH3NtoPB15()	do {GIO_AFPP(GPIOB, 1<<15); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x00 << 6);} while (0)
#define TIM1CH3NtoPE12()	do {GIO_AFPP(GPIOE, 1<<12); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x03 << 6);} while (0)
#define TIM1CH3NtoPB1()		do {GIO_AFPP(GPIOB, 1<< 1); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (0x01 << 6);} while (0)

#define TIM2CH1toPA0()		do {GIO_AFPP(GPIOA, 1<< 0); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (0x00 << 8);} while (0)
#define TIM2CH2toPA1()		do {GIO_AFPP(GPIOA, 1<< 1); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (0x00 << 8);} while (0)
#define TIM2CH2toPB3()		do {GIO_AFPP(GPIOB, 1<< 3); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (0x01 << 8);} while (0)
#define TIM2CH3toPA2()		do {GIO_AFPP(GPIOA, 1<< 2); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (0x00 << 8);} while (0)
#define TIM2CH3toPB10()		do {GIO_AFPP(GPIOB, 1<<10); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (0x01 << 8);} while (0)
#define TIM2CH4toPA3()		do {GIO_AFPP(GPIOA, 1<< 3); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (0x00 << 8);} while (0)
#define TIM2CH4toPB11()		do {GIO_AFPP(GPIOB, 1<<11); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (0x01 << 8);} while (0)

#define TIM3CH1toPA6()		do {GIO_AFPP(GPIOA, 1<< 6); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x00 <<10);} while (0)
#define TIM3CH1toPC6()		do {GIO_AFPP(GPIOC, 1<< 6); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x03 <<10);} while (0)
#define TIM3CH2toPA7()		do {GIO_AFPP(GPIOA, 1<< 7); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x00 <<10);} while (0)
#define TIM3CH2toPB5()		do {GIO_AFPP(GPIOB, 1<< 5); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x02 <<10);} while (0)
#define TIM3CH2toPC7()		do {GIO_AFPP(GPIOC, 1<< 7); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x03 <<10);} while (0)
#define TIM3CH3toPB0()		do {GIO_AFPP(GPIOB, 1<< 0); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x00 <<10);} while (0)
#define TIM3CH3toPC8()		do {GIO_AFPP(GPIOC, 1<< 8); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x03 <<10);} while (0)
#define TIM3CH4toPB1()		do {GIO_AFPP(GPIOB, 1<< 1); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x00 <<10);} while (0)
#define TIM3CH4toPC9()		do {GIO_AFPP(GPIOC, 1<< 9); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (0x03 <<10);} while (0)

#define TIM4CH1toPB6()		do {GIO_AFPP(GPIOB, 1<< 6); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x00 <<12);} while (0)
#define TIM4CH2toPB7()		do {GIO_AFPP(GPIOB, 1<< 7); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x00 <<12);} while (0)
#define TIM4CH3toPB8()		do {GIO_AFPP(GPIOB, 1<< 8); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x00 <<12);} while (0)
#define TIM4CH4toPB9()		do {GIO_AFPP(GPIOB, 1<< 9); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x00 <<12);} while (0)
#define TIM4CH1toPD12()		do {GIO_AFPP(GPIOD, 1<<12); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x01 <<12);} while (0)
#define TIM4CH2toPD13()		do {GIO_AFPP(GPIOD, 1<<13); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x01 <<12);} while (0)
#define TIM4CH3toPD14()		do {GIO_AFPP(GPIOD, 1<<14); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x01 <<12);} while (0)
#define TIM4CH4toPD15()		do {GIO_AFPP(GPIOD, 1<<15); AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (0x01 <<12);} while (0)

#define TIM15CH1toPA2()		do {GIO_AFPP(GPIOA, 1<< 2); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM15_REMAP)|(0x00 << 0);} while (0)
#define TIM15CH1toPB14()	do {GIO_AFPP(GPIOB, 1<<14); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM15_REMAP)|(0x01 << 0);} while (0)
#define TIM15CH2toPA3()		do {GIO_AFPP(GPIOA, 1<< 3); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM15_REMAP)|(0x00 << 0);} while (0)
#define TIM15CH2toPB15()	do {GIO_AFPP(GPIOB, 1<<15); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM15_REMAP)|(0x01 << 0);} while (0)
#define TIM15CH1NtoPB15()	do {GIO_AFPP(GPIOB, 1<<15); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM15_REMAP)| (0x00 << 0);} while (0)

#define TIM16CH1toPA6()		do {GIO_AFPP(GPIOA, 1<< 6); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM16_REMAP)|(0x01 << 1);} while (0)
#define TIM16CH1toPB8()		do {GIO_AFPP(GPIOB, 1<< 8); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM16_REMAP)|(0x00 << 1);} while (0)
#define TIM16CH1NtoPB6()	do {GIO_AFPP(GPIOB, 1<< 6); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM16_REMAP)|(0x00 << 1);} while (0)

#define TIM17CH1toPA7()		do {GIO_AFPP(GPIOA, 1<< 7); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM17_REMAP)|(0x01 << 2);} while (0)
#define TIM17CH1toPB9()		do {GIO_AFPP(GPIOB, 1<< 9); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM17_REMAP)|(0x00 << 2);} while (0)
#define TIM17CH1NtoPB7()	do {GIO_AFPP(GPIOB, 1<< 7); AFIO->MAPR2= (AFIO->MAPR2&~AFIO_MAPR2_TIM17_REMAP)|(0x00 << 2);} while (0)

//i2c
#define SCL1toPB6()			do {GIO_AFPP(GPIOB, 1<< 6); AFIO->MAPR&=~AFIO_MAPR_I2C1_REMAP);} while (0)
#define SCL1toPB8()			do {GIO_AFPP(GPIOB, 1<< 8); AFIO->MAPR|= AFIO_MAPR_I2C1_REMAP);} while (0)
#define SDA1toPB7()			do {GIO_AFPP(GPIOB, 1<< 7); AFIO->MAPR&=~AFIO_MAPR_I2C1_REMAP);} while (0)
#define SDa1toPB9()			do {GIO_AFPP(GPIOB, 1<< 9); AFIO->MAPR|= AFIO_MAPR_I2C1_REMAP);} while (0)

//spi1
#define NSS1toPA4()			do {GIO_AFPP(GPIOA, 1<< 4); AFIO->MAPR&=~AFIO_MAPR_SPI1_REMAP);} while (0)
#define NSS1toPA15()		do {GIO_AFPP(GPIOA, 1<<15); AFIO->MAPR|= AFIO_MAPR_SPI1_REMAP);} while (0)
#define SCK1toPA5()			do {GIO_AFPP(GPIOA, 1<< 5); AFIO->MAPR&=~AFIO_MAPR_SPI1_REMAP);} while (0)
#define SCK1toPB3()			do {GIO_AFPP(GPIOB, 1<< 3); AFIO->MAPR|= AFIO_MAPR_SPI1_REMAP);} while (0)
#define MISO1toPA6()		do {GIO_AFPP(GPIOA, 1<< 6); AFIO->MAPR&=~AFIO_MAPR_SPI1_REMAP);} while (0)
#define MISO1toPB4()		do {GIO_AFPP(GPIOB, 1<< 4); AFIO->MAPR|= AFIO_MAPR_SPI1_REMAP);} while (0)
#define MOSI1toPA7()		do {GIO_AFPP(GPIOA, 1<< 7); AFIO->MAPR&=~AFIO_MAPR_SPI1_REMAP);} while (0)
#define MOSI1toPB5()		do {GIO_AFPP(GPIOB, 1<< 5); AFIO->MAPR|= AFIO_MAPR_SPI1_REMAP);} while (0)

//spi2

//spi3
#define NSS3toPA15()		do {GIO_AFPP(GPIOA, 1<<15); AFIO->MAPR&=~AFIO_MAPR_SPI3_REMAP);} while (0)
#define NSS3toPA4()			do {GIO_AFPP(GPIOA, 1<< 4); AFIO->MAPR|= AFIO_MAPR_SPI3_REMAP);} while (0)
#define SCK3toPB3()			do {GIO_AFPP(GPIOB, 1<< 3); AFIO->MAPR&=~AFIO_MAPR_SPI3_REMAP);} while (0)
#define SCK3toPC10()		do {GIO_AFPP(GPIOC, 1<<10); AFIO->MAPR|= AFIO_MAPR_SPI3_REMAP);} while (0)
#define MISO3toPB4()		do {GIO_AFPP(GPIOB, 1<< 4); AFIO->MAPR&=~AFIO_MAPR_SPI3_REMAP);} while (0)
#define MISO3toPC11()		do {GIO_AFPP(GPIOC, 1<<11); AFIO->MAPR|= AFIO_MAPR_SPI3_REMAP);} while (0)
#define MOSI3toPB5()		do {GIO_AFPP(GPIOB, 1<< 5); AFIO->MAPR&=~AFIO_MAPR_SPI3_REMAP);} while (0)
#define MOSI3toPC12()		do {GIO_AFPP(GPIOC, 1<<12); AFIO->MAPR|= AFIO_MAPR_SPI3_REMAP);} while (0)

//end pin alternative config

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
#endif		//gpioa
#if defined(GPIOB)
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
#endif		//gpiob
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
void pinMode(PIN_TypeDef pin, uint8_t mode);
void digitalWrite(PIN_TypeDef pin, uint8_t mode);
int digitalRead(PIN_TypeDef pin);
#define pinFlip(pin)		digitalWrite(pin, !digitalRead(pin))

//time base
#if defined(USE_CORETICK)
  #define ticks()			coreticks()				//use systick for timing / tick generation
#else
  #define ticks()			systicks()				//use coretick / dwt for timing / tick generation
#endif

#define coreticks()			(DWT->CYCCNT)			//use dwt/coretick as time base
uint32_t systicks(void);							//use systick as time base

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

//install systick isr
//activate the isr handler
void systickAttachISR(void (*isrptr)(void));

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
void analogWrite(uint8_t pin, uint16_t dc);			//not implemented - could use a wrapper however.

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

//clock switching
void SystemCoreClockHSI(void);			//reset clock to HSI
void SystemCoreClockHSE(void);			//reset clock to HSE
void SystemCoreClockHSIPLL(uint32_t PLLMul_x);		//switch to HSIxPLL
#define SystemCoreClockHSIPLL1x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL2)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL1x5()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL3)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL2x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL4)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL2x5()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL5)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL3x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL6)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL3x5()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL7)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL4x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL8)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL4x5()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL9)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL5x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL10)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL5x5()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL11)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL6x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL12)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL6x5()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL13)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL7x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL14)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL7x5()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL15)		//switch to HSIxPLL
#define SystemCoreClockHSIPLL8x()		SystemCoreClockHSIPLL(RCC_CFGR_PLLMULL16)		//switch to HSIxPLL
#define SystemCoreClockHSI8Mhz()		SystemCoreClockHSIPLL1x()
#define SystemCoreClockHSI12Mhz()		SystemCoreClockHSIPLL1x5()
#define SystemCoreClockHSI16Mhz()		SystemCoreClockHSIPLL2x()
#define SystemCoreClockHSI20Mhz()		SystemCoreClockHSIPLL2x5()
#define SystemCoreClockHSI24Mhz()		SystemCoreClockHSIPLL3x()
#define SystemCoreClockHSI28Mhz()		SystemCoreClockHSIPLL3x5()
#define SystemCoreClockHSI32Mhz()		SystemCoreClockHSIPLL4x()
#define SystemCoreClockHSI36Mhz()		SystemCoreClockHSIPLL4x5()
#define SystemCoreClockHSI40Mhz()		SystemCoreClockHSIPLL5x()
#define SystemCoreClockHSI44Mhz()		SystemCoreClockHSIPLL5x5()
#define SystemCoreClockHSI48Mhz()		SystemCoreClockHSIPLL6x()
#define SystemCoreClockHSI52Mhz()		SystemCoreClockHSIPLL6x5()
#define SystemCoreClockHSI56Mhz()		SystemCoreClockHSIPLL7x()
#define SystemCoreClockHSI60Mhz()		SystemCoreClockHSIPLL7x5()
#define SystemCoreClockHSI64Mhz()		SystemCoreClockHSIPLL8x()
#define SystemCoreClockHSI68Mhz()		SystemCoreClockHSIPLL8x5()
//Predivx makes sure that PLL output frequency is less than 24Mhz
void SystemCoreClockHSEPLL(uint32_t PLLMul_x/*, uint32_t PREDIV_x*/);	//switch to HSExPLL
#define SystemCoreClockHSEPLL1x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL1)		//switch to HSExPLL
#define SystemCoreClockHSEPLL1x5()		do {RCC->CR &=~RCC_CR_PLLON; RCC->CFGR |= RCC_CFGR_PLLXTPRE; SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL3);} while (0)		//switch to HSExPLL
#define SystemCoreClockHSEPLL2x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL2)		//switch to HSExPLL
#define SystemCoreClockHSEPLL2x5()		do {RCC->CR &=~RCC_CR_PLLON; RCC->CFGR |= RCC_CFGR_PLLXTPRE; SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL5);} while (0)		//switch to HSExPLL
#define SystemCoreClockHSEPLL3x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL3)		//switch to HSExPLL
#define SystemCoreClockHSEPLL3x5()		do {RCC->CR &=~RCC_CR_PLLON; RCC->CFGR |= RCC_CFGR_PLLXTPRE; SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL7);} while (0)		//switch to HSExPLL
#define SystemCoreClockHSEPLL4x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL4)		//switch to HSExPLL
#define SystemCoreClockHSEPLL4x5()		do {RCC->CR &=~RCC_CR_PLLON; RCC->CFGR |= RCC_CFGR_PLLXTPRE; SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL9);} while (0)		//switch to HSExPLL
#define SystemCoreClockHSEPLL5x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL5)		//switch to HSExPLL
#define SystemCoreClockHSEPLL5x5()		do {RCC->CR &=~RCC_CR_PLLON; RCC->CFGR |= RCC_CFGR_PLLXTPRE; SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL11);} while (0)		//switch to HSExPLL
#define SystemCoreClockHSEPLL6x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL6)		//switch to HSExPLL
#define SystemCoreClockHSEPLL6x5()		do {RCC->CR &=~RCC_CR_PLLON; RCC->CFGR |= RCC_CFGR_PLLXTPRE; SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL13);} while (0)		//switch to HSExPLL
#define SystemCoreClockHSEPLL7x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL7)		//switch to HSExPLL
#define SystemCoreClockHSEPLL7x5()		do {RCC->CR &=~RCC_CR_PLLON; RCC->CFGR |= RCC_CFGR_PLLXTPRE; SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL15);} while (0)		//switch to HSExPLL
#define SystemCoreClockHSEPLL8x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL8)		//switch to HSExPLL
#define SystemCoreClockHSEPLL9x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL9)		//switch to HSExPLL
#define SystemCoreClockHSEPLL10x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL10)		//switch to HSExPLL
#define SystemCoreClockHSEPLL12x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL12)		//switch to HSExPLL
#define SystemCoreClockHSEPLL14x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL14)		//switch to HSExPLL
#define SystemCoreClockHSEPLL15x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL15)		//switch to HSExPLL
#define SystemCoreClockHSEPLL16x()		SystemCoreClockHSEPLL(RCC_CFGR_PLLMULL16)		//switch to HSExPLL

//mco output - mco output has no prescaler / divisor
#define MCO2NOCLK()						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_NOCLOCK);} while (0)									//mco to pllclk/2
#define MCO2SYSCLK()					do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_SYSCLK);} while (0)									//mco to pllclk/2
#define MCO2HSI()						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_HSI);} while (0)									//mco to pllclk/2
#define MCO2HSE()						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_HSE);} while (0)									//mco to pllclk/2
#define MCO2PLL()						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_PLL);} while (0)									//mco to pllclk/2
#define MCO2PLL2()						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_PLL2CLK);} while (0)									//mco to pllclk/2
#define MCO2PLL3_2()					do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_PLL3CLK_Div2);} while (0)									//mco to pllclk/2
#define MCO2ExtHSE()					do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_Ext_HSE);} while (0)									//mco to pllclk/2
#define MCO2PLL3()						do {RCC->CFGR = (RCC->CFGR &~RCC_CFGR_MCO) | (RCC_CFGR_MCO_PLL3CLK);} while (0)									//mco to pllclk/2

//global defines
#define IDCODE				(DBGMCU->IDCODE)
#define CPUID				(SCB->CPUID)
#define UID					((char *) 0x1ffff7e8)		//96bit/12byte unique id. UID[0]..UID[11]

//global variables

//reset the mcu
void mcuInit(void);


//empty interrupt handler
void empty_handler(void);


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
#define UART_BR1M			UART_BR1000000
#define UART_BR1M25			UART_BR1250000
#define UART_BR1M5			UART_BR1500000
#define UART_BR2M			UART_BR2000000

//initiate the hardware usart
//for uart1
void uart1Init(unsigned long baud_rate);
void uart1Putch(char ch);
void uart1Puts(char *str);
uint16_t uart1Available(void);
uint16_t uart1Busy(void);

void uart1Putline(char *ln);
//read a char from usart
uint8_t uart1Getch(void);
void u1Print(char *str, int32_t dat);
#define u1Println()			uart1Puts("\r\n")

//for compatability
#define uart1Put(ch)		uart1Putch(ch)
#define uart1Get()			uart1Getch()
#define uart1bps()			(F_UART * 2 / USART1->BRR / ((USART1->CR1 & (1<<15))?1:2))
#define u1bps()				uart1bps()

//for uart2
//initiate the hardware usart
void uart2Init(unsigned long baud_rate);
void uart2Putch(char ch);
void uart2Puts(char *str);
uint16_t uart2Available(void);
uint16_t uart2Busy(void);
void uart2Putline(char *ln);

//read a char from usart
uint8_t uart2Getch(void);
void u2Print(char *str, int32_t dat);
#define u2Println()			uart2Puts("\r\n")

//for compatability
#define uart2Put(ch)		uart2Putch(ch)
#define uart2Get()			uart2Getch()
#define uart2bps()			(F_UART * 2 / USART2->BRR / ((USART2->CR1 & (1<<15))?1:2))
#define u2bps()				uart2bps()

//for uart3
//initiate the hardware usart
void uart3Init(unsigned long baud_rate);
void uart3Putch(char ch);
void uart3Puts(char *str);
uint16_t uart3Available(void);
uint16_t uart3Busy(void);
void uart3Putline(char *ln);

//read a char from usart
uint8_t uart3Getch(void);
void u3Print(char *str, int32_t dat);

//for compatability
#define uart3Put(ch)		uart3Putch(ch)
#define uart3Get()			uart3Getch()
#define uart3bps()			(F_UART * 2 / USART3->BRR / ((USART3->CR1 & (1<<15))?1:2))
#define u3bps()				uart3bps()

//for uart4
//initiate the hardware usart
void uart4Init(unsigned long baud_rate);
void uart4Putch(char ch);
void uart4Puts(char *str);
uint16_t uart4Available(void);
uint16_t uart4Busy(void);
void uart4Putline(char *ln);

//read a char from usart
uint8_t uart4Getch(void);
void u4Print(char *str, int32_t dat);

//for compatability
#define uart4Put(ch)		uart4Putch(ch)
#define uart4Get()			uart4Getch()
#define uart4bps()			(F_UART * 2 / USART4->BRR / ((USART4->CR1 & (1<<15))?1:2))
#define u4bps()				uart4bps()

//for uart5
//initiate the hardware usart
void uart5Init(unsigned long baud_rate);
void uart5Putch(char ch);
void uart5Puts(char *str);
uint16_t uart5Available(void);
uint16_t uart5Busy(void);
void uart5Putline(char *ln);

//read a char from usart
uint8_t uart5Getch(void);
void u3Print(char *str, int32_t dat);

//for compatability
#define uart5Put(ch)		uart5Putch(ch)
#define uart5Get()			uart5Getch()
#define uart5bps()			(F_UART * 2 / USART5->BRR / ((USART5->CR1 & (1<<15))?1:2))
#define u5bps()				uart5bps()

//end Serial

#define TIM_CCMR1_IC1PSC_Pos	2
#define TIM_CCMR1_IC2PSC_Pos	10
#define TIM_CCMR2_IC3PSC_Pos	2
#define TIM_CCMR2_IC4PSC_Pos	10
#define tmrCC1Get(tmr)		(tmr->CCR1)			//get capture / compare value
#define tmrCC2Get(tmr)		(tmr->CCR2)			//get capture / compare value
#define tmrCC3Get(tmr)		(tmr->CCR3)			//get capture / compare value
#define tmrCC4Get(tmr)		(tmr->CCR4)			//get capture / compare value

//initialize the timer1 (16bit)
void tmr1Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr1Get()			(TIM1->CNT)			//read timer counter value
#define tmr1SetPS(ps)		TIM1->PSC = (ps) - 1ul
#define tmr1GetPS()			(TIM1->PSC + 1ul)
#define tmr1SetPR(pr)		TIM1->ARR = (pr) - 1ul
#define tmr1GetPR()			(TIM1->ARR + 1ul)
void tmr1OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr1OC1SetPR(uint16_t pr);					//set period
void tmr1OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr1OC2SetPR(uint16_t pr);					//set period
void tmr1OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr1OC3SetPR(uint16_t pr);					//set period
void tmr1OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr1OC4SetPR(uint16_t pr);					//set period
void tmr1OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr1IC1Init(uint8_t ps);								//activate input capture
#define tmr1CC1Get()		tmrCC1Get(TIM1)			//get capture / compare value
void tmr1IC2Init(uint8_t ps);								//activate input capture
#define tmr1CC2Get()		tmrCC2Get(TIM1)			//get capture / compare value
void tmr1IC3Init(uint8_t ps);								//activate input capture
#define tmr1CC3Get()		tmrCC3Get(TIM1)			//get capture / compare value
void tmr1IC4Init(uint8_t ps);								//activate input capture
#define tmr1CC4Get()		tmrCC4Get(TIM1)			//get capture / compare value

//initialize the timer2 (16bit)
void tmr2Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr2Get()			(TIM2->CNT)			//read timer counter value
#define tmr2SetPS(ps)		TIM2->PSC = (ps) - 1ul
#define tmr2GetPS()			(TIM2->PSC + 1l)
#define tmr2SetPR(pr)		TIM2->ARR = (pr) - 1ul
#define tmr2GetPR()			(TIM2->ARR + 1l)
void tmr2OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr2OC1SetPR(uint16_t pr);					//set period
void tmr2OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr2OC2SetPR(uint16_t pr);					//set period
void tmr2OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr2OC3SetPR(uint16_t pr);					//set period
void tmr2OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr2OC4SetPR(uint16_t pr);					//set period
void tmr2OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr2IC1Init(uint8_t ps);								//activate input capture
#define tmr2CC1Get()		tmrCC1Get(TIM2)			//get capture / compare value
void tmr2IC2Init(uint8_t ps);								//activate input capture
#define tmr2CC2Get()		tmrCC2Get(TIM2)			//get capture / compare value
void tmr2IC3Init(uint8_t ps);								//activate input capture
#define tmr2CC3Get()		tmrCC3Get(TIM2)			//get capture / compare value
void tmr2IC4Init(uint8_t ps);								//activate input capture
#define tmr2CC4Get()		tmrCC4Get(TIM2)			//get capture / compare value

//initialize the timer3 (16bit)
void tmr3Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr3Get()			(TIM3->CNT)			//read timer counter value
#define tmr3SetPS(ps)		TIM3->PSC = (ps) - 1l
#define tmr3GetPS()			(TIM3->PSC + 1l)
#define tmr3SetPR(pr)		TIM3->ARR = (pr) - 1l
#define tmr3GetPR()			(TIM3->ARR + 1l)
void tmr3OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr3OC1SetPR(uint16_t pr);					//set period
void tmr3OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr3OC2SetPR(uint16_t pr);					//set period
void tmr3OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr3OC3SetPR(uint16_t pr);					//set period
void tmr3OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr3OC4SetPR(uint16_t pr);					//set period
void tmr3OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr3IC1Init(uint8_t ps);								//activate input capture
#define tmr3CC1Get()		tmrCC1Get(TIM3)			//get capture / compare value
void tmr3IC2Init(uint8_t ps);								//activate input capture
#define tmr3CC2Get()		tmrCC2Get(TIM3)			//get capture / compare value
void tmr3IC3Init(uint8_t ps);								//activate input capture
#define tmr3CC3Get()		tmrCC3Get(TIM3)			//get capture / compare value
void tmr3IC4Init(uint8_t ps);								//activate input capture
#define tmr3CC4Get()		tmrCC4Get(TIM3)			//get capture / compare value

//initialize the timer4 (16bit)
void tmr4Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr4Get()			(TIM4->CNT)			//read timer counter value
#define tmr4SetPS(ps)		TIM4->PSC = (ps) - 1l
#define tmr4GetPS()			(TIM4->PSC + 1l)
#define tmr4SetPR(pr)		TIM4->ARR = (pr) - 1l
#define tmr4GetPR()			(TIM4->ARR + 1l)
void tmr4OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr4OC1SetPR(uint16_t pr);					//set period
void tmr4OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr4OC2SetPR(uint16_t pr);					//set period
void tmr4OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr4OC3SetPR(uint16_t pr);					//set period
void tmr4OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr4OC4SetPR(uint16_t pr);					//set period
void tmr4OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr4IC1Init(uint8_t ps);								//activate input capture
#define tmr4CC1Get()		tmrCC1Get(TIM4)			//get capture / compare value
void tmr4IC2Init(uint8_t ps);								//activate input capture
#define tmr4CC2Get()		tmrCC2Get(TIM4)			//get capture / compare value
void tmr4IC3Init(uint8_t ps);								//activate input capture
#define tmr4CC3Get()		tmrCC3Get(TIM4)			//get capture / compare value
void tmr4IC4Init(uint8_t ps);								//activate input capture
#define tmr4CC4Get()		tmrCC4Get(TIM4)			//get capture / compare value

//TiM5 does not exist on STM32F103
//#define  RCC_APB1ENR_TIM5EN                 ((uint32_t)0x00000008)        /*!< Timer 5 clock enable */
//#define TIM5_IRQn							50
//initialize the timer5 (16bit)
void tmr5Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr5Get()			(TIM5->CNT)			//read timer counter value
#define tmr5SetPS(ps)		TIM5->PSC = (ps) - 1l
#define tmr5GetPS()			(TIM5->PSC + 1l)
#define tmr5SetPR(pr)		TIM5->ARR = (pr) - 1l
#define tmr5GetPR()			(TIM5->ARR + 1l)
void tmr5OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr5OC1SetPR(uint16_t pr);					//set period
void tmr5OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr5OC2SetPR(uint16_t pr);					//set period
void tmr5OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr5OC3SetPR(uint16_t pr);					//set period
void tmr5OC3AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr5OC4SetPR(uint16_t pr);					//set period
void tmr5OC4AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr5IC1Init(uint8_t ps);								//activate input capture
#define tmr5CC1Get()		tmrCC1Get(TIM5)			//get capture / compare value
void tmr5IC2Init(uint8_t ps);								//activate input capture
#define tmr5CC2Get()		tmrCC2Get(TIM5)			//get capture / compare value
void tmr5IC3Init(uint8_t ps);								//activate input capture
#define tmr5CC3Get()		tmrCC3Get(TIM5)			//get capture / compare value
void tmr5IC4Init(uint8_t ps);								//activate input capture
#define tmr5CC4Get()		tmrCC4Get(TIM5)			//get capture / compare value

//initialize the timer6 (16bit) - cnfirmed to not exist on stm32f103
//#define  RCC_APB1ENR_TIM6EN                 ((uint32_t)0x00000010)        /*!< Timer 6 clock enable */
//#define TIM6_IRQn			54
void tmr6Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr6Get()			(TIM6->CNT)			//read timer counter value
#define tmr6SetPS(ps)		TIM6->PSC = (ps) - 1l
#define tmr6GetPS()			(TIM6->PSC + 1l)
#define tmr6SetPR(pr)		TIM6->ARR = (pr) - 1l
#define tmr6GetPR()			(TIM6->ARR + 1l)
void tmr6OVFAttachISR(void (*isrptr)(void));		//activate the isr handler

//initialize the timer7 (16bit) - confirmed to not exist on stm32f103
//#define  RCC_APB1ENR_TIM7EN                 ((uint32_t)0x00000020)        /*!< Timer 7 clock enable */
//#define TIM7_IRQn			55
void tmr7Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr7Get()			(TIM7->CNT)			//read timer counter value
#define tmr7SetPS(ps)		TIM7->PSC = (ps) - 1l
#define tmr7GetPS()			(TIM7->PSC + 1l)
#define tmr7SetPR(pr)		TIM7->ARR = (pr) - 1l
#define tmr7GetPR()			(TIM7->ARR + 1l)
void tmr7OVFAttachISR(void (*isrptr)(void));		//activate the isr handler

//initialize the timer8 (16bit) - confirmed to not exist on stm32f103
//#define  RCC_APB1ENR_TIM8EN                 ((uint32_t)0x00000020)        /*!< Timer 7 clock enable */
//#define TIM8_IRQn			55
void tmr8Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr8Get()			(TIM8->CNT)			//read timer counter value
#define tmr8SetPS(ps)		TIM8->PSC = (ps) - 1l
#define tmr8GetPS()			(TIM8->PSC + 1l)
#define tmr8SetPR(pr)		TIM8->ARR = (pr) - 1l
#define tmr8GetPR()			(TIM8->ARR + 1l)
void tmr8OVFAttachISR(void (*isrptr)(void));		//activate the isr handler

//initialize the timer8 (16bit) - confirmed to not exist on stm32f103
//#define  RCC_APB1ENR_TIM9EN                 ((uint32_t)0x00000020)        /*!< Timer 7 clock enable */
//#define TIM9_IRQn			55
void tmr9Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr9Get()			(TIM9->CNT)			//read timer counter value
#define tmr9SetPS(ps)		TIM9->PSC = (ps) - 1l
#define tmr9GetPS()			(TIM9->PSC + 1l)
#define tmr9SetPR(pr)		TIM9->ARR = (pr) - 1l
#define tmr9GetPR()			(TIM9->ARR + 1l)
void tmr9OVFAttachISR(void (*isrptr)(void));		//activate the isr handler

//initialize the timer10 (16bit) - confirmed to not exist on stm32f103
//#define  RCC_APB1ENR_TIM10EN                 ((uint32_t)0x00000020)        /*!< Timer 7 clock enable */
//#define TIM10_IRQn			55
void tmr10Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr10Get()			(TIM10->CNT)			//read timer counter value
#define tmr10SetPS(ps)		TIM10->PSC = (ps) - 1l
#define tmr10GetPS()		(TIM10->PSC + 1l)
#define tmr10SetPR(pr)		TIM10->ARR = (pr) - 1l
#define tmr10GetPR()		(TIM10->ARR + 1l)
void tmr10OVFAttachISR(void (*isrptr)(void));		//activate the isr handler

//initialize the timer11 (16bit) - confirmed to not exist on stm32f103
//#define  RCC_APB1ENR_TIM11EN                 ((uint32_t)0x00000020)        /*!< Timer 7 clock enable */
//#define TIM11_IRQn			55
void tmr11Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr11Get()			(TIM11->CNT)			//read timer counter value
#define tmr11SetPS(ps)		TIM11->PSC = (ps) - 1l
#define tmr11GetPS()		(TIM11->PSC + 1l)
#define tmr11SetPR(pr)		TIM11->ARR = (pr) - 1l
#define tmr11GetPR()		(TIM11->ARR + 1l)
void tmr11OVFAttachISR(void (*isrptr)(void));		//activate the isr handler

#if defined(RCC_APB1ENR_TIM12EN)
//initialize the timer12 (16bit)
void tmr12Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr12Get()			(TIM12->CNT)			//read timer counter value
#define tmr12SetPS(ps)		TIM12->PSC = (ps) - 1l
#define tmr12GetPS()		(TIM12->PSC + 1l)
#define tmr12SetPR(pr)		TIM12->ARR = (pr) - 1l
#define tmr12GetPR()		(TIM12->ARR + 1l)
void tmr12OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr12OC1SetPR(uint16_t pr);					//set period
void tmr12OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr12OC2SetPR(uint16_t pr);					//set period
void tmr12OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr12IC1Init(uint8_t ps);								//activate input capture
#define tmr12CC1Get()		tmrCC1Get(TIM12)			//get capture / compare value
void tmr12IC2Init(uint8_t ps);								//activate input capture
#define tmr12CC2Get()		tmrCC2Get(TIM12)			//get capture / compare value
#endif	//tim12

#if defined(RCC_APB1ENR_TIM13EN)
//initialize the timer15 (16bit)
void tmr13Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr13Get()			(TIM13->CNT)			//read timer counter value
#define tmr13SetPS(ps)		TIM13->PSC = (ps) - 1l
#define tmr13GetPS()		(TIM13->PSC + 1l)
#define tmr13SetPR(pr)		TIM13->ARR = (pr) - 1l
#define tmr13GetPR()		(TIM13->ARR + 1l)
void tmr13OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr13OC1SetPR(uint16_t pr);					//set period
void tmr13OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr13OC2SetPR(uint16_t pr);					//set period
void tmr13OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr13IC1Init(uint8_t ps);								//activate input capture
#define tmr13CC1Get()		tmrCC1Get(TIM13)			//get capture / compare value
void tmr13IC2Init(uint8_t ps);								//activate input capture
#define tmr13CC2Get()		tmrCC2Get(TIM13)			//get capture / compare value
#endif	//tim13

#if defined(RCC_APB1ENR_TIM14EN)
//initialize the timer15 (16bit)
void tmr14Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr14Get()			(TIM14->CNT)			//read timer counter value
#define tmr14SetPS(ps)		TIM14->PSC = (ps) - 1l
#define tmr14GetPS()		(TIM14->PSC + 1l)
#define tmr14SetPR(pr)		TIM14->ARR = (pr) - 1l
#define tmr14GetPR()		(TIM14->ARR + 1l)
void tmr14OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr14OC1SetPR(uint16_t pr);					//set period
void tmr14OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr14OC2SetPR(uint16_t pr);					//set period
void tmr14OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr14IC1Init(uint8_t ps);								//activate input capture
#define tmr14CC1Get()		tmrCC1Get(TIM14)			//get capture / compare value
void tmr14IC2Init(uint8_t ps);								//activate input capture
#define tmr14CC2Get()		tmrCC2Get(TIM14)			//get capture / compare value
#endif	//tim14

//initialize the timer15 (16bit)
void tmr15Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr15Get()			(TIM15->CNT)			//read timer counter value
#define tmr15SetPS(ps)		TIM15->PSC = (ps) - 1l
#define tmr15GetPS()		(TIM15->PSC + 1l)
#define tmr15SetPR(pr)		TIM15->ARR = (pr) - 1l
#define tmr15GetPR()		(TIM15->ARR + 1l)
void tmr15OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr15OC1SetPR(uint16_t pr);					//set period
void tmr15OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr15OC2SetPR(uint16_t pr);					//set period
void tmr15OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr15IC1Init(uint8_t ps);								//activate input capture
#define tmr15CC1Get()		tmrCC1Get(TIM15)			//get capture / compare value
void tmr15IC2Init(uint8_t ps);								//activate input capture
#define tmr15CC2Get()		tmrCC2Get(TIM15)			//get capture / compare value

//initialize the timer16 (16bit)
void tmr16Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr16Get()			(TIM16->CNT)			//read timer counter value
#define tmr16SetPS(ps)		TIM16->PSC = (ps) - 1l
#define tmr16GetPS()		(TIM16->PSC + 1l)
#define tmr16SetPR(pr)		TIM16->ARR = (pr) - 1l
#define tmr16GetPR()		(TIM16->ARR + 1l)
void tmr16OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr16OC1SetPR(uint16_t pr);					//set period
void tmr16OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr16OC2SetPR(uint16_t pr);					//set period
void tmr16OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr16IC1Init(uint8_t ps);								//activate input capture
#define tmr16CC1Get()		tmrCC1Get(TIM16)			//get capture / compare value
void tmr16IC2Init(uint8_t ps);								//activate input capture
#define tmr16CC2Get()		tmrCC2Get(TIM16)			//get capture / compare value

//initialize the timer17 (16bit)
void tmr17Init(uint16_t ps);						//initialize timer with a prescaler
#define tmr17Get()			(TIM17->CNT)			//read timer counter value
#define tmr17SetPS(ps)		TIM17->PSC = (ps) - 1l
#define tmr17GetPS()		(TIM17->PSC + 1l)
#define tmr17SetPR(pr)		TIM17->ARR = (pr) - 1l
#define tmr17GetPR()		(TIM17->ARR + 1l)
void tmr17OVFAttachISR(void (*isrptr)(void));		//activate the isr handler
//output compare
void tmr17OC1SetPR(uint16_t pr);					//set period
void tmr17OC1AttachISR(void (*isrptr)(void));		//activate the isr handler
void tmr17OC2SetPR(uint16_t pr);					//set period
void tmr17OC2AttachISR(void (*isrptr)(void));		//activate the isr handler
//input capture
void tmr17IC1Init(uint8_t ps);								//activate input capture
#define tmr17CC1Get()		tmrCC1Get(TIM17)			//get capture / compare value
void tmr17IC2Init(uint8_t ps);								//activate input capture
#define tmr17CC2Get()		tmrCC2Get(TIM17)			//get capture / compare value

//32-bit timers by chaining them
//initialize tim12 as a synchronized 32-bit timer
//tim1 as master / lsw (including prescaler) to tim2 / msw of the 32-bit timer
//tim2 as slave / msw of the 32-bit timer
void tmr12Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr12Get(void);				//read 32-bit timer value
uint32_t tmr12SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr12GetPR(void);				//read 32-bit timer period
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

//initialize tim14 as a synchronized 32-bit timer
//tim1 as master / lsw (including prescaler) to tim4 / msw of the 32-bit timer
//tim4 as slave / msw of the 32-bit timer
void tmr14Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr14Get(void);				//read 32-bit timer value
uint32_t tmr14SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr14GetPR(void);				//read 32-bit timer period
#define tmr14SetPS(ps)					tmr1SetPS(ps)
#define tmr14GetPS()					tmr1GetPS()
#define tmr14OVFAttachISR(isrptr)		tmr4OVFAttachISR(isrptr)		//activate the isr handler

//initialize tim21 as a synchronized 32-bit timer
//tim2 as master / lsw (including prescaler) to tim3 / msw of the 32-bit timer
//tim1 as slave / msw of the 32-bit timer
void tmr21Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr21Get(void);				//read 32-bit timer value
uint32_t tmr21SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr21GetPR(void);				//read 32-bit timer period
#define tmr21SetPS(ps)					tmr2SetPS(ps)
#define tmr21GetPS()					tmr2GetPS()
#define tmr21OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr23Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr23Get(void);				//read 32-bit timer value
uint32_t tmr23SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr23GetPR(void);				//read 32-bit timer period
#define tmr23SetPS(ps)					tmr2SetPS(ps)
#define tmr23GetPS()					tmr2GetPS()
#define tmr23OVFAttachISR(isrptr)		tmr3OVFAttachISR(isrptr)		//activate the isr handler

void tmr24Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr24Get(void);				//read 32-bit timer value
uint32_t tmr24SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr24GetPR(void);				//read 32-bit timer period
#define tmr24SetPS(ps)					tmr2SetPS(ps)
#define tmr24GetPS()					tmr2GetPS()
#define tmr24OVFAttachISR(isrptr)		tmr4OVFAttachISR(isrptr)		//activate the isr handler

void tmr25Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr25Get(void);				//read 32-bit timer value
uint32_t tmr25SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr25GetPR(void);				//read 32-bit timer period
#define tmr25SetPS(ps)					tmr2SetPS(ps)
#define tmr25GetPS()					tmr2GetPS()
#define tmr25OVFAttachISR(isrptr)		tmr5OVFAttachISR(isrptr)		//activate the isr handler

void tmr31Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr31Get(void);				//read 32-bit timer value
uint32_t tmr31SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr31GetPR(void);				//read 32-bit timer period
#define tmr31SetPS(ps)					tmr3SetPS(ps)
#define tmr31GetPS()					tmr3GetPS()
#define tmr31OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr32Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr32Get(void);				//read 32-bit timer value
uint32_t tmr32SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr32GetPR(void);				//read 32-bit timer period
#define tmr32SetPS(ps)					tmr3SetPS(ps)
#define tmr32GetPS()					tmr3GetPS()
#define tmr32OVFAttachISR(isrptr)		tmr2OVFAttachISR(isrptr)		//activate the isr handler

void tmr34Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr34Get(void);				//read 32-bit timer value
uint32_t tmr34SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr34GetPR(void);				//read 32-bit timer period
#define tmr34SetPS(ps)					tmr3SetPS(ps)
#define tmr34GetPS()					tmr3GetPS()
#define tmr34OVFAttachISR(isrptr)		tmr4OVFAttachISR(isrptr)		//activate the isr handler

void tmr35Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr35Get(void);				//read 32-bit timer value
uint32_t tmr35SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr35GetPR(void);				//read 32-bit timer period
#define tmr35SetPS(ps)					tmr3SetPS(ps)
#define tmr35GetPS()					tmr3GetPS()
#define tmr35OVFAttachISR(isrptr)		tmr5OVFAttachISR(isrptr)		//activate the isr handler

void tmr41Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr41Get(void);				//read 32-bit timer value
uint32_t tmr41SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr41GetPR(void);				//read 32-bit timer period
#define tmr41SetPS(ps)					tmr4SetPS(ps)
#define tmr41GetPS()					tmr4GetPS()
#define tmr41OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr42Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr42Get(void);				//read 32-bit timer value
uint32_t tmr42SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr42GetPR(void);				//read 32-bit timer period
#define tmr42SetPS(ps)					tmr4SetPS(ps)
#define tmr42GetPS()					tmr4GetPS()
#define tmr42OVFAttachISR(isrptr)		tmr2OVFAttachISR(isrptr)		//activate the isr handler

void tmr43Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr43Get(void);				//read 32-bit timer value
uint32_t tmr43SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr43GetPR(void);				//read 32-bit timer period
#define tmr43SetPS(ps)					tmr4SetPS(ps)
#define tmr43GetPS()					tmr4GetPS()
#define tmr43OVFAttachISR(isrptr)		tmr3OVFAttachISR(isrptr)		//activate the isr handler

void tmr45Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr45Get(void);				//read 32-bit timer value
uint32_t tmr45SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr45GetPR(void);				//read 32-bit timer period
#define tmr45SetPS(ps)					tmr4SetPS(ps)
#define tmr45GetPS()					tmr4GetPS()
#define tmr45OVFAttachISR(isrptr)		tmr5OVFAttachISR(isrptr)		//activate the isr handler

void tmr125Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr125Get(void);				//read 32-bit timer value
uint32_t tmr125SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr125GetPR(void);				//read 32-bit timer period
#define tmr125SetPS(ps)					tmr12SetPS(ps)
#define tmr125GetPS()					tmr12GetPS()
#define tmr125OVFAttachISR(isrptr)		tmr5OVFAttachISR(isrptr)		//activate the isr handler

void tmr151Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr151Get(void);				//read 32-bit timer value
uint32_t tmr151SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr151GetPR(void);				//read 32-bit timer period
#define tmr151SetPS(ps)					tmr15SetPS(ps)
#define tmr151GetPS()					tmr15GetPS()
#define tmr151OVFAttachISR(isrptr)		tmr1OVFAttachISR(isrptr)		//activate the isr handler

void tmr152Init(uint16_t ps);			//initialize tmr, default period is 0x100000000ul
uint32_t tmr152Get(void);				//read 32-bit timer value
uint32_t tmr152SetPR(uint32_t pr);		//set 32-bit timer period
uint32_t tmr152GetPR(void);				//read 32-bit timer period
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


//pwm / oc
//global defines
///TMR1 remap macros
/*
MAPR Bits 7:6 TIM1_REMAP[1:0]: TIM1 remapping
These bits are set and cleared by software. They control the mapping of TIM1 channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN) on the GPIO ports.
00: No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
01: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1)
10: not used
11: Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12)
*/
#define TIM1REMAP0		(0<<6)
#define TIM1REMAP1		(1<<6)
#define TIM1REMAP2		(2<<6)
#define TIM1REMAP3		(3<<6)

/*
MAPR Bits 9:8 TIM2_REMAP[1:0]: TIM2 remapping
These bits are set and cleared by software. They control the mapping of TIM2 channels 1 to 4 and external trigger (ETR) on the GPIO ports.
00: No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
01: Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
10: Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
11: Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
*/
#define TIM2REMAP0		(0<< 8)
#define TIM2REMAP1		(1<< 8)
#define TIM2REMAP2		(2<< 8)
#define TIM2REMAP3		(3<< 8)

/*
MAPR Bits 11:10 TIM3_REMAP[1:0]: TIM3 remapping
These bits are set and cleared by software. They control the mapping of TIM3 channels 1 to 4 on the GPIO ports.
00: No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
01: Not used
10: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
11: Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
Note: TIM3_ETR on PE0 is not re-mapped.
*/
#define TIM3REMAP0		(0<<10)
#define TIM3REMAP1		(1<<10)
#define TIM3REMAP2		(2<<10)
#define TIM3REMAP3		(3<<10)

/*
MAPR Bits 11:10 TIM4_REMAP[1:0]: TIM3 remapping
These bits are set and cleared by software. They control the mapping of TIM4 channels 1 to 4 on the GPIO ports.
0: No remap (TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9)
1: Full remap (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
Note: TIM4_ETR on PE0 is not re-mapped.
*/
#define TIM4REMAP0			(0<<12)
#define TIM4REMAP1			(1<<12)
//#define TIM4REMAP2		(2<<12)
//#define TIM4REMAP3		(3<<12)

//global variables

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm1Init(uint16_t TxCCP_PS);
#define pwm1GetPS()			(TIM1->PSC + 1ul)
#define pwm1SetPS(ps)		TIM1->PSC = (ps) - 1
#define pwm1GetPR()			(TIM1->ARR + 1ul)
#define pwm1SetPR(pr)		TIM1->ARR = (ps) - 1
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
void pwm2Init(uint16_t TxCCP_PS);
#define pwm2GetPS()			(TIM2->PSC + 1ul)
#define pwm2SetPS(ps)		TIM2->PSC = (ps) - 1
#define pwm2GetPR()			(TIM2->ARR + 1ul)
#define pwm2SetPR(pr)		TIM2->ARR = (ps) - 1
//set duty cycle
#define pwm2SetDC1(dc)		TIM2->CCR1 = (dc)
#define pwm2SetDC2(dc)		TIM2->CCR2 = (dc)
#define pwm2SetDC3(dc)		TIM2->CCR3 = (dc)
#define pwm2SetDC4(dc)		TIM2->CCR4 = (dc)
#define pwm2GetDC1()		(TIM2->CCR1)
#define pwm2GetDC2()		(TIM2->CCR2)
#define pwm2GetDC3()		(TIM2->CCR3)
#define pwm2GetDC4()		(TIM2->CCR4)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm3Init(uint16_t TxCCP_PS);
#define pwm3GetPS()			(TIM3->PSC + 1ul)
#define pwm3SetPS(ps)		TIM3->PSC = (ps) - 1
#define pwm3GetPR()			(TIM3->ARR + 1ul)
#define pwm3SetPR(pr)		TIM3->ARR = (ps) - 1
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
void pwm4Init(uint16_t TxCCP_PS);
#define pwm4GetPS()			(TIM4->PSC + 1ul)
#define pwm4SetPS(ps)		TIM4->PSC = (ps) - 1
#define pwm4GetPR()			(TIM4->ARR + 1ul)
#define pwm4SetPR(pr)		TIM4->ARR = (ps) - 1
//set duty cycle
#define pwm4SetDC1(dc)		TIM4->CCR1 = (dc)
#define pwm4SetDC2(dc)		TIM4->CCR2 = (dc)
#define pwm4SetDC3(dc)		TIM4->CCR3 = (dc)
#define pwm4SetDC4(dc)		TIM4->CCR4 = (dc)
#define pwm4GetDC1()		(TIM4->CCR1)
#define pwm4GetDC2()		(TIM4->CCR2)
#define pwm4GetDC3()		(TIM4->CCR3)
#define pwm4GetDC4()		(TIM4->CCR4)

//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm14Init(uint16_t TxCCP_PS);
#define pwm14GetPS()		(TIM14->PSC + 1ul)
#define pwm14SetPS(ps)		TIM14->PSC = (ps) - 1
#define pwm14GetPR()		(TIM14->ARR + 1ul)
#define pwm14SetPR(pr)		TIM14->ARR = (ps) - 1
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
#define pwm15GetPS()		(TIM15->PSC + 1ul)
#define pwm15SetPS(ps)		TIM15->PSC = (ps) - 1
#define pwm15GetPR()		(TIM15->ARR + 1ul)
#define pwm15SetPR(pr)		TIM15->ARR = (ps) - 1
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
#define pwm16GetPS()		(TIM16->PSC + 1ul)
#define pwm16SetPS(ps)		TIM16->PSC = (ps) - 1
#define pwm16GetPR()		(TIM16->ARR + 1ul)
#define pwm16SetPR(pr)		TIM16->ARR = (ps) - 1
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
#define pwm17GetPS()		(TIM17->PSC + 1ul)
#define pwm17SetPS(ps)		TIM17->PSC = (ps) - 1
#define pwm17GetPR()		(TIM17->ARR + 1ul)
#define pwm17SetPR(pr)		TIM17->ARR = (ps) - 1
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
//configuration adc
#define ADC_SMPR		7				//ADC sample time, 0b000(1.5us)..0b111(239.5us), applied to all channels
//end configuration adc

#define ADC_CH0			0
#define ADC_CH1			1
#define ADC_CH2			2
#define ADC_CH3			3
#define ADC_CH4			4
#define ADC_CH5			5
#define ADC_CH6			6
#define ADC_CH7			7
#define ADC_CH8			8
#define ADC_CH9			9
#define ADC_CH10		10
#define ADC_CH11		11
#define ADC_CH12		12
#define ADC_CH13		13
#define ADC_CH14		14
#define ADC_CH15		15
#define ADC_CH16		16
#define ADC_CH17		17
#define ADC_TS			ADC_CH16				//tempeature sensor on CH16
#define ADC_VREFINT		ADC_CH17				//internal reference on CH17 @ 1.20v
#define ADC_TEMP		ADC_TS
#define ADC_VREF		ADC_VREFINT
#define ADC_ARAND		ADC_VREFINT				//the channel for random number generators
//convert temperature sensor adc reading into temperaturex10
//follow the datasheet. 3.3v Vref (3.0v for my board), 12bit adc
//#define ADC2Tx10(adc)	(3529 - ((uint32_t) (VREF*10*10/43 * (adc)) >> 12))
#define ADC2Cx100(adc)	((1430 - ADC2mv(adc)) * 10 * 100 / (43) + 2500)			//((8500 - 3000) * ((adc) - TSCAL1) / (TSCAL2 - TSCAL1) + 3000)	//need to rewrite this
#define ADC2Fx100(adc)	(ADC2Cx100(adc) * 9 / 5 + 3200)
#define VREFadc			1602l					//VREF ADC reading on target system
#define VREFmv			1200l					//Vref voltage in mv
#define VDDAmv			(VREFmv * 4096 / VREFadc)	//VADD=3.3v
#define ADC2mv(adc)		((adc) * VDDAmv / 4096)	//convert 12-bit adc to mv
//rest the adc
//automatic sampling (ASAM=1), manual conversion
void adc1Init(void);
uint16_t adc1Read(uint32_t adc_ch);

//map analogRead() to adc1Read
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

//extint
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
//end extint

//spi

void spi1Init(uint16_t br);							//reset spi1. br=0..7
#define spi1Busy()			(SPI1->SR & SPI_SR_BSY)
#define spi1Avail()			(SPI1->SR & SPI_SR_RXNE)
#define spi1Wait()			while (spi1Busy()) continue
#define spiWrite(dat)		do {spi1Wait(); SPI1->DR = (dat);} while (0)
#define spiRead()			(SPI1->DR)

void spi2Init(uint16_t br);							//reset spi2. br=0..7
#define spi2Busy()			(SPI1->SR & SPI_SR_BSY)
#define spi1Avail()			(SPI1->SR & SPI_SR_RXNE)
#define spi1Wait()			while (spi1Busy()) continue
#define spiWrite(dat)		do {spi1Wait(); SPI1->DR = (dat);} while (0)
#define spiRead()			(SPI1->DR)

//end spi

//i2c
//i2c commands
#define I2C_CMD_WRITE		0
#define I2C_CMD_READ		1

//i2c1
void i2c1Init(void);		//reset i2c1
#define i2c1Busy()			(I2C1->SR2 & I2C_SR2_BUSY)
#define i2c1Wait()			while (i2c1Busy()) continue
#define i2c1Avail()			(I2C1->SR1 & I2C_SR1_RXNE)
#define i2c1Start()			do {I2C1->CR1 |= I2C_CR1_START; while (!I2C1->SR1 & I2C_SR1_SB) continue; I2C1->SR1;} while (0)
#define i2c1WriteAddr(dat)	do {I2C1->DR = (dat); while (!I2C1->SR1 & I2C_SR1_ADDR) continue; I2C1->SR1; I2C1->SR2;} while (0)
#define i2c1Write(dat)		do {I2C1->DR = (dat); while (!I2C1->SR1 & I2C_SR1_TXE) continue; } while (0)
#define i2c1Stop()			do {I2C1->CR1 |= I2C_CR1_STOP;} while (0)
#define i2c1Ack()			do {I2C1->CR1 |= I2C_CR1_ACK;} while (0)
#define i2c1NoAck()			do {I2C1->CR1 &=~I2C_CR1_ACK;} while (0)
int16_t i2c1Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToWrite);	//WRITE_REG multiple bytes
int16_t i2c1Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToRead);	//READ_BIT multiple bytes

//i2c2
void i2c2Init(void);		//reset i2c2
#define i2c2Busy()			(I2C2->SR2 & I2C_SR2_BUSY)
#define i2c2Wait()			while (i2c2Busy()) continue
#define i2c2Avail()			(I2C2->SR1 & I2C_SR1_RXNE)
#define i2c2Start()			do {I2C2->CR1 |= I2C_CR1_START; while (!I2C2->SR1 & I2C_SR1_SB) continue; I2C2->SR1;} while (0)
#define i2c2WriteAddr(dat)	do {I2C2->DR = (dat); while (!I2C2->SR1 & I2C_SR1_ADDR) continue; I2C2->SR1; I2C2->SR2;} while (0)
#define i2c2Write(dat)		do {I2C2->DR = (dat); while (!I2C2->SR1 & I2C_SR1_TXE) continue; } while (0)
#define i2c2Stop()			do {I2C2->CR1 |= I2C_CR1_STOP;} while (0)
#define i2c2Ack()			do {I2C2->CR1 |= I2C_CR1_ACK;} while (0)
#define i2c2NoAck()			do {I2C2->CR1 &=~I2C_CR1_ACK;} while (0)
int16_t i2c2Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToWrite);	//WRITE_REG multiple bytes
int16_t i2c2Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToRead);	//READ_BIT multiple bytes
//end i2c

//rtc
//reset the rtc
//ps = prescaler
//pr = period for alarm
//alarm isr is enabled
//rtcc_clk is clock source:
//RCC_BDCR_RTCSEL_LSI, RCC_BDCR_RTCSEL_LSE and RCC_BDCR_RTCSEL_HSE (HSE/128)
void RTCInit(uint32_t rtc_clk, uint32_t ps);	//initialize the RTCC
void RTCOVFAttachISR(void (*isr_ptr)(void));			//install rtc overflow isr
void RTCALRAttachISR(void (*isr_ptr)(void));			//install rtc alarm isr
void RTCSECAttachISR(void (*isr_ptr)(void));			//install rtc second isr
uint32_t RTCSetCNT(uint32_t val);				//set rtc counter
uint32_t RTCGetCNT(void);						//read rtc counter
uint32_t RTCSetALR(uint32_t val);				//set rtc alarm counter
uint32_t RTCGetALR(void);						//read rtc alarm counter
#define	isRTCALR()				(RTC->CRL & RTC_CRL_ALRF)
#define	isRTCSEC()				(RTC->CRL & RTC_CRL_SECF)
#define	isRTCOW()				(RTC->CRL & RTC_CRL_OWF)
#define RTCClrALR()				do {PWR->CR |= PWR_CR_DBP; RTC->CRL |= RTC_CRL_CNF; RTC->CRL &=~RTC_CRL_ALRF; RTC->CRL &=~RTC_CRL_CNF; PWR->CR &=~PWR_CR_DBP;	} while (0)
#define RTCClrSEC()				do {PWR->CR |= PWR_CR_DBP; RTC->CRL |= RTC_CRL_CNF; RTC->CRL &=~RTC_CRL_SECF; RTC->CRL &=~RTC_CRL_CNF; PWR->CR &=~PWR_CR_DBP;	} while (0)
#define RTCClrOW()				do {PWR->CR |= PWR_CR_DBP; RTC->CRL |= RTC_CRL_CNF; RTC->CRL &=~RTC_CRL_OWF;  RTC->CRL &=~RTC_CRL_CNF; PWR->CR &=~PWR_CR_DBP;	} while (0)
#define RTCGetSec()				RTCGetCNT()
#define RTCSetSec(sec)			RTCSetCNT(sec)
#define RTCInitNoCLK()			RTCInit(RCC_BDCR_RTCSEL_NOCLOCK, F_LSI)
#define RTCInitLSI()			RTCInit(RCC_BDCR_RTCSEL_LSI, F_LSI)
#define RTCInitLSE()			RTCInit(RCC_BDCR_RTCSEL_LSE, F_LSE)
#define RTCInitHSE()			RTCInit(RCC_BDCR_RTCSEL_HSE, F_HSE/128)

time_t RTC2time(time_t *t);						//read rtc into time_t
time_t time2RTC(time_t t);						//initialize rtc with time_t

uint32_t RTCGetPRL(void);						//read prll and prlh
uint32_t RTCGetDIV(void);						//read divl and divh
uint8_t RTCHalfsec(void);							//returns 0: if 1st half second, 1: if 2nd half second
//set calibration register
void RTCSetCal(uint8_t cal);					//set calibration: number of ticks to be ignored every 2^20 ticks (it slows down the rtc)
//end rtc

//software rtc
//software RTC
//global defines

//global variables
typedef struct {
	time_t time;						//second counter since 1/1/1970
	uint32_t tick;						//tick counter
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
#define sRTCGetSec()	sRTC2time(NULL)		//for compatability
//end software RTC

//extint
//pin: one pin only
//gpio: GPIOA..GPIOG
void extiInit(PIN_TypeDef pinx, uint8_t edge);
void extiAttachISR(PIN_TypeDef pinx, void (*isr_ptr)(void));		//install user handler

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
    uint16_t writeIndex;				//index for the current write-> advance first and then write
    uint16_t readIndex;					//index for the current read -> advance first and then read
} CB_TypeDef;

void cbInit(CB_TypeDef *cbuffer);		//reset the cbuffer
char cbEmpty(CB_TypeDef *cbuffer);		//returns true if cbuffer is empty
char cbFull(CB_TypeDef *cbuffer);		//returns true if cbuffer is full;
cbuffer_t cbWrite(CB_TypeDef *cbuffer, cbuffer_t dat);	//write to the buffer - needs to test if the buffer is full first
cbuffer_t cbRead(CB_TypeDef *cbuffer);	//read from the buffer - needs to test if the buffer is empty
void str2cb(CB_TypeDef *cb, char *str);	//write string to CB
void cb2str(char *str, CB_TypeDef *cb);	//write CB to string
//end circular buffer

//tamper
//tamper backup registers
//unlock the domain
//on some chips, it requires a set of magic numbers
#define bkpUnlock()		do {PWR->CR |= PWR_CR_DBP;} while (!(PWR->CR & PWR_CR_DBP))	//1->enable write assess, 0->disable write assess
#define bkpLock()		do {PWR->CR &=~PWR_CR_DBP;} while ( (PWR->CR & PWR_CR_DBP))	//1->enable write assess, 0->disable write assess

//reset the tamper to use the backup registers
void bkpInit(void);

//read backup register: 1..10 on medium density devices and 1..42/45 on high density devices
#if 1
#define bkp1Get(n)		(BKP->DR1)				//read bkp1
#define bkp1Set(val)	do {bkpUnlock(); BKP->DR1 = (val); bkpLock();} while (0)		//write bkp1
#define bkp2Get(n)		(BKP->DR2)				//read bkp2
#define bkp2Set(val)	do {bkpUnlock(); BKP->DR2 = (val); bkpLock();} while (0)		//write bkp2
#define bkp3Get(n)		(BKP->DR3)				//read bkp3
#define bkp3Set(val)	do {bkpUnlock(); BKP->DR3 = (val); bkpLock();} while (0)		//write bkp3
#define bkp4Get(n)		(BKP->DR4)				//read bkp4
#define bkp4Set(val)	do {bkpUnlock(); BKP->DR4 = (val); bkpLock();} while (0)		//write bkp4
#define bkp5Get(n)		(BKP->DR5)				//read bkp5
#define bkp5Set(val)	do {bkpUnlock(); BKP->DR5 = (val); bkpLock();} while (0)		//write bkp5
#define bkp6Get(n)		(BKP->DR6)				//read bkp6
#define bkp6Set(val)	do {bkpUnlock(); BKP->DR6 = (val); bkpLock();} while (0)		//write bkp6
#define bkp7Get(n)		(BKP->DR7)				//read bkp7
#define bkp7Set(val)	do {bkpUnlock(); BKP->DR7 = (val); bkpLock();} while (0)		//write bkp7
#define bkp8Get(n)		(BKP->DR8)				//read bkp8
#define bkp8Set(val)	do {bkpUnlock(); BKP->DR8 = (val); bkpLock();} while (0)		//write bkp8
#define bkp9Get(n)		(BKP->DR9)				//read bkp9
#define bkp9Set(val)	do {bkpUnlock(); BKP->DR9 = (val); bkpLock();} while (0)		//write bkp9
#define bkp10Get(n)		(BKP->DR10)				//read bkp10
#define bkp10Set(val)	do {bkpUnlock(); BKP->DR10= (val); bkpLock();} while (0)		//write bkp10
#define bkp11Get(n)		(BKP->DR11)				//read bkp11
#define bkp11Set(val)	do {bkpUnlock(); BKP->DR11= (val); bkpLock();} while (0)		//write bkp11
#define bkp12Get(n)		(BKP->DR12)				//read bkp12
#define bkp12Set(val)	do {bkpUnlock(); BKP->DR12= (val); bkpLock();} while (0)		//write bkp12
#define bkp13Get(n)		(BKP->DR13)				//read bkp13
#define bkp13Set(val)	do {bkpUnlock(); BKP->DR13= (val); bkpLock();} while (0)		//write bkp13
#define bkp14Get(n)		(BKP->DR14)				//read bkp14
#define bkp14Set(val)	do {bkpUnlock(); BKP->DR14= (val); bkpLock();} while (0)		//write bkp14
#define bkp15Get(n)		(BKP->DR15)				//read bkp15
#define bkp15Set(val)	do {bkpUnlock(); BKP->DR15= (val); bkpLock();} while (0)		//write bkp15
#define bkp16Get(n)		(BKP->DR16)				//read bkp16
#define bkp16Set(val)	do {bkpUnlock(); BKP->DR16= (val); bkpLock();} while (0)		//write bkp16
#define bkp17Get(n)		(BKP->DR17)				//read bkp17
#define bkp17Set(val)	do {bkpUnlock(); BKP->DR17= (val); bkpLock();} while (0)		//write bkp17
#define bkp18Get(n)		(BKP->DR18)				//read bkp18
#define bkp18Set(val)	do {bkpUnlock(); BKP->DR18= (val); bkpLock();} while (0)		//write bkp18
#define bkp19Get(n)		(BKP->DR19)				//read bkp19
#define bkp19Set(val)	do {bkpUnlock(); BKP->DR19= (val); bkpLock();} while (0)		//write bkp19
#define bkp20Get(n)		(BKP->DR20)				//read bkp20
#define bkp20Set(val)	do {bkpUnlock(); BKP->DR20= (val); bkpLock();} while (0)		//write bkp20
#else	//simpler approach also works
#define bkpGet(n)		(BKP->DR##n##)				//read bkp20
#define bkpSet(n, val)	do {bkpUnlock(); BKP->DR##n##= (val); bkpLock();} while (0)		//write bkp20
#define bkp1Get()		bkpGet(1)
#define bkp1Set(val)	bkpSet(1, val)
#define bkp2Get()		bkpGet(2)
#define bkp2Set(val)	bkpSet(2, val)
#define bkp3Get()		bkpGet(3)
#define bkp3Set(val)	bkpSet(3, val)
#define bkp4Get()		bkpGet(4)
#define bkp4Set(val)	bkpSet(4, val)
#define bkp5Get()		bkpGet(5)
#define bkp5Set(val)	bkpSet(5, val)
#define bkp6Get()		bkpGet(6)
#define bkp6Set(val)	bkpSet(6, val)
#define bkp7Get()		bkpGet(7)
#define bkp7Set(val)	bkpSet(7, val)
#define bkp8Get()		bkpGet(8)
#define bkp8Set(val)	bkpSet(8, val)
#define bkp9Get()		bkpGet(9)
#define bkp9Set(val)	bkpSet(9, val)
#define bkp10Get()		bkpGet(10)
#define bkp10Set(val)	bkpSet(10, val)
#define bkp11Get()		bkpGet(11)
#define bkp11Set(val)	bkpSet(11, val)
#define bkp12Get()		bkpGet(12)
#define bkp12Set(val)	bkpSet(12, val)
#define bkp13Get()		bkpGet(13)
#define bkp13Set(val)	bkpSet(13, val)
#define bkp14Get()		bkpGet(14)
#define bkp14Set(val)	bkpSet(14, val)
#define bkp15Get()		bkpGet(15)
#define bkp15Set(val)	bkpSet(15, val)
#define bkp16Get()		bkpGet(16)
#define bkp16Set(val)	bkpSet(16, val)
#define bkp17Get()		bkpGet(17)
#define bkp17Set(val)	bkpSet(17, val)
#define bkp18Get()		bkpGet(18)
#define bkp18Set(val)	bkpSet(18, val)
#define bkp19Get()		bkpGet(19)
#define bkp19Set(val)	bkpSet(19, val)
#define bkp20Get()		bkpGet(20)
#define bkp20Set(val)	bkpSet(20, val)
#endif

//crc
void crcInit(void);					//initialize crc
#define crcSet(dat)		CRC->DR = (dat)		//load up crc with data
//end crc


#endif
