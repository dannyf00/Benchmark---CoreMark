#include <stdint.h>
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
// - v2.2f,09/04/2023:added support for hardware 48-bit timers (tmr23 and tmr32 for now)
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

#include "stm32duino.h"						//we use pic24duino
#include "coremark.h"						//we use coremark benchmark

//hardware configuration
#define VDD			PA3						//pin grounded
#define LED			PA4						//led pin
#define LED_DLY		(F_PHB / 2)				//half a second
//end hardware configuration

//global defines

//global variables
uint32_t tick0, tick1;
volatile uint32_t bkp=0;

//Use HSE to measure LSI: capture the ticks elapsed based on RTC seconds
//master clock on HSE, RTC on LSI
//return: estimated LSI frequency
uint32_t rtcCal(uint32_t cnt) {
	uint32_t tmp0, i=cnt;
	uint32_t tmp;
	
	//strat the lsi
	//RCC->CSR |= RCC_CSR_LSION; while ((RCC->CSR & RCC_CSR_LSIRDY) == 0) continue;	//turn on lsi and wait for it to be ready
	
	//RTCInitLSI();												//initialize RTC on lsi
	tmp  = RTCGetSec(); while (tmp == RTCGetSec()) continue;	//wait for the second to turn
	tmp0 = ticks();												//time stamp tick
#if 0
	while (i--) {
		tmp = RTCGetSec(); while (tmp == RTCGetSec()) continue;	//wait for the second to turn 
	}
#else
	while (RTCGetSec() < tmp + i) continue;
#endif
	tmp0 = ticks() - tmp0;
	return tmp0 / cnt;						//time stamp tick
}


//Use TIM14 to measure LSI: feeding LSI to TIM14 Input capture through MCO
uint32_t t14Cal(uint32_t cnt) {
	uint32_t tmp0, tmp1, i=cnt;
	
	//strat the lsi
	RCC->CSR |= RCC_CSR_LSION; while ((RCC->CSR & RCC_CSR_LSIRDY) == 0) continue;	//turn on lsi and wait for it to be ready
	
	//configure mco output, 128:1 prescaler
	MCO2LSI(6);												//map mco to lsi, 7->128:1 prescaler max
	
	//set up the timer / input capture
	tmr14Init(1);											//initialize tmr14, 1:1 prescaler
#if 1
	tmr14IC1Init(0);
#else
	//set up the capture channel 1
	TIM14->CCMR1 = (TIM14->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM14->CCMR1 = (TIM14->CCMR1 &~TIM_CCMR1_IC1PSC) | ((0<<2) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM14->SR &=~TIM_SR_CC1IF; TIM14->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM14->CCER |= TIM_CCER_CC1E;							//ENABLE input capture
	//map tim14 rmp to MCO (=3)
#endif
	TIM14->OR = (TIM14->OR &~TIM14_OR_TI1_RMP) | (((3) << 0) & TIM14_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	TIM14->EGR |=TIM_EGR_UG;								//force an update

	//clear the first pulse
	while ((TIM14->SR & TIM_SR_CC1IF) == 0) continue;		//wait for a pulse to arrive
	TIM14->SR &=~TIM_SR_CC1IF;								//clear the flag
	tmp0 = ticks();	//TIM14->CCR1;							//time stamp with ticks() or CCR1
	while (i--) {
		while ((TIM14->SR & TIM_SR_CC1IF) == 0) continue;	//wait for a pulse to arrive
		tmp1 = ticks();	//TIM14->CCR1;						//time stamp with ticks() or CCR1
		TIM14->SR &=~TIM_SR_CC1IF;							//clear the flag
	};
	//return tmp1 - tmp0;										//return the ticks elapsed
	//need to make sure that F_CPU * cnt doesn't overflow 2^32
	return ((F_CPU * cnt) << ((RCC->CFGR & RCC_CFGR_MCO_PRE) >> 28)) / (tmp1 - tmp0);	//return the measured frequency
}

//flip the led
void led_flp(void) {
	pinFlip(LED);
}

//user defined set up code
void setup(void) {
	//select the clock source, or use default clock = 8Mhz FRC
	//SystemCoreClockHSI();						//HSI - default clock @ 8Mhz
	//SystemCoreClockHSI20Mhz();					//HSIPLL - default pll4x->32Mhz
	//SystemCoreClockHSIPLL();					//HSIPLL to 32Mhz
	//SystemCoreClockHSE();						//HSE
	//SystemCoreClockHSEPLL2x();				//HSExpll

	//initialize the pins
#if defined(VDD)
	pinMode(VDD, OUTPUT); digitalWrite(VDD, HIGH);	//vcc pin pulled high
#endif
#if defined(GND)
	pinMode(GND, OUTPUT); digitalWrite(GND, LOW);	//gnd pin grounded
#endif
#if defined(LED)
	pinMode(LED, OUTPUT); digitalWrite(LED, LOW);	//led pin grounded
#endif
	
	//initialize the uart
	uart1Init(UART_BR115K2);					//initialize uart1
	//uart2Init(UART_BR115K2);					//initialize uart2
	
	//systick timer isr
	//systickAttachISR(led_flp);
	
	//16-bit timer
	//tmr1Init(100);
	//tmr1OC1SetPR(1000); tmr1OC1AttachISR(led_flp);
	//tmr1OC2SetPR(1010); tmr1OC2AttachISR(led_flp);
	
	//32-bit timers
	//tmr31Init(1); //tmr171SetPR(100000000ul);
	//tmr32Init(4); 
	
	//enable the adc
	//adc1Init();
	
	//bkpInit();									//initialize bkp
	
	ei();										//enable interrupts
}

//user defined main loop
void loop(void) {
	volatile uint32_t tmp0=0; 
	//static uint32_t tmp=0;
	//volatile uint32_t i;
	//static uint16_t tmrcnt=0;
	
	//if (tick0++ > 100000ul) {tick0=0;			//reaset the counter
	//if (tmr2Get() - tick0 > LED_DLY) {tick0 += LED_DLY;
	if (ticks() - tick0 > LED_DLY) {tick0 += LED_DLY;						//advance to the next match point
		pinFlip(LED);							//flip led, 105 ticks
		
		//backup register testing
		//bkp0Set(bkp = bkp0Get() +1); 

		//benchmark
		tmp0 = ticks();							//stamp tick1
		//do something
		//i=100000ul; while (i--) continue;		//1.4M/0.1M
		//digitalRead(PA5);						//read a pin, 59 ticks (base case = 29 ticks, if there is nothing)
		//uart1Init(UART_BR9600);				//initial uart, 1328 ticks
		//digitalWrite(LED, !digitalRead(LED));	//flip led, 74 ticks
		//tmp=analogRead(ADC_TS);
		//for (tmp=0; tmp<1000; tmp++) digitalWrite(LED, !digitalRead(LED));	//flip led, 53528/1000 ticks
		//for (tmp=0; tmp<1000; tmp++) IO_FLP(GPIOB, 1<<7);					//flip led, 10031 ticks /1000 iterations
		//for (tmp=0; tmp<1000/5; tmp++) {IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);}				//flip led, 6028 ticks/1000 iterations
		//for (tmp=0; tmp<1000/10; tmp++) {IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);IO_FLP(GPIOB, 1<<7);}				//flip led, 6028 ticks/1000 iterations
		//for (tmp=1000/5, bufPtr=datBuffer; tmp--;) {GPIOA->ODR = *bufPtr++; GPIOA->ODR = *bufPtr++; GPIOA->ODR = *bufPtr++; GPIOA->ODR = *bufPtr++; GPIOA->ODR = *bufPtr++; }
		//tmp=ticks() - tmp0;
		//analogRead(ADC_VREF);					//243-38
		//LSICalT14(8);
		//analogRead(ADC_CH0);
		//tmr2Get();
		coremark_main();							//coremark benchmark
		tmp0 = ticks() - tmp0;					//calculate time elapsed
		
		//tmp0 = ADC2mv(analogRead(ADC_VREF));			//read vrefint
		//tmp0 = ADC2Fx100(analogRead(ADC_TEMP));			//read temp
		
		//display something
		//u1Print("F_CPU =                    ", F_CPU);
		//u1Print("ticks =                    ", ticks());
		//u1Print("tick0 =                    ", tick0);
		//u1Print("tmp0  =                    ", tmp0);
		//u1Print("Vref  =                    ", ADC2mv((analogRead(ADC_VREF))));
		//u1Print("T31CN =                    ", tmr3Get());
		//u1Print("T3CNT =                    ", tmr3Get());
		//u1Print("T1CNT =                    ", tmr1Get());
		//u1Print("TempF =                    ", ADC2Fx100((analogRead(ADC_TEMP))));
		//u1Print("ADC14 =                    ", ADC2mv(analogRead(ADC_CH1)));
		//RTCInitLSE(); u1Print("F_HSI =                    ", rtcCal(10));
		//u1Print("F_HSI =                    ", HSICalRTC(10));
		//u1Print("T14F  =                    ", LSICalT14(8));
		//u1Print("ticks =                    ", tmp1-tmp0);
		//u1Print("u1brr =                    ", USART1->BRR);
		//u1Print("u1bps =                    ", u1bps());
		//u1Println();
	}
}
