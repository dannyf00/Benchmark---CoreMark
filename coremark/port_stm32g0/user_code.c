//STM32duino code
// - using STM32G030F / STM32G031F chips
// - free running systick for ticks
// - 
// - version history
// - v0.1a, 02/11/2023: initial port from stm32f0 code base. GPIO + ticks work
// - v0.1b, 03/04/2023: timers, pwm, uart and rtc now working
// - v0.1c, 03/25/2023: added support for chained (32-bit) timers
// - v0.1d, 03/19/2023: streamlined the pwm initialization code
// - v0.1e, 08/23/2023: refined lptim1/2 and lpuart code
//
//
//               STM32G030F/031F
//      Vdd     |=====================|
//       |      |                     |
//       +------| Vdd            PA14 |<----- SWCLK (Pin20)
//              |                     |
//       +------| BOOT0          PA13 |<----> SWDIO (Pin19)
//              |                     |
//              |                     |
// GND<---------| Vss             PA7 |--+--> GND/LED1
//              |                     |  |
//              |                 PA6 |--+--> LED
//              |                     |
//              |                 PA3 |>----> VDD
//              |                     |
//              |                 PA2 |>----> U2TX/LED2
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

#include "stm32duino.h"						//we use stm32g0
#include "coremark.h"						//we use coremark

//hardware configuration
#define LED			PA6						//led pin
#define LED_DLY		(F_CPU / 2)				//half a second

#define VDD			PA3
#define GND			PA7						//pin grounded
//end hardware configuration

//global defines

//global variables
uint32_t tick0, tick1;
char *str="abcdefg.....0123456789";


//Use RTC to measure LSI: capture the ticks elapsed based on RTC seconds
uint32_t LSICalRTC(uint32_t sec) {
	uint32_t tmp0, tmp1, i=sec;
	uint32_t tmp;
	
	//strat the lsi
	RCC->CSR |= RCC_CSR_LSION; while ((RCC->CSR & RCC_CSR_LSIRDY) == 0) continue;	//turn on lsi and wait for it to be ready
	
	RTCInitLSI();												//initialize RTC on lsi
	tmp  = RTCGetSec(); while (tmp == RTCGetSec()) continue;	//wait for the second to turn
	tmp0 = ticks();												//time stamp tick
	while (i--) {
		tmp = RTCGetSec(); while (tmp == RTCGetSec()) continue;	//wait for the second to turn 
		tmp1 = ticks();											//time stamp tick
	}
	//return tmp1 - tmp0;										//return the ticks elapsed
	//scaling so that F_CPU * F_LSI doesn't overflow 2^32
	return (F_CPU >> 8) * F_LSI / ((tmp1 - tmp0) >> 8) * sec;	//return the measured frequency. ">> 8" for scalling
}

//Use TIM14 to measure LSI: feeding LSI to TIM14 Input capture through MCO
uint32_t LSICalT14(uint32_t cnt) {
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
	TIM14->TISEL = (TIM14->TISEL &~TIM_TISEL_TI1SEL) | (((3) << TIM_TISEL_TI1SEL_Pos) & TIM_TISEL_TI1SEL);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM14->EGR |=TIM_EGR_UG;								//force an update

	//clear the first pulse
	while ((TIM14->SR & TIM_SR_CC1IF) == 0) continue;		//wait for a pulse to arrive
	TIM14->SR &=~TIM_SR_CC1IF;								//clear the flag
	tmp0 = ticks();	//TIM14->CCR1;							//time stamp with ticks() or CCR1
	while (i--) {
		while ((TIM14->SR & TIM_SR_CC1IF) == 0) continue;	//wait for a pulse to arrive
		tmp1 = ticks();	//TIM14->CCR1;						//time stamp with ticks() or CCR1
		TIM14->SR &=~TIM_SR_CC1IF;							//clear the flag
	};
	return tmp1 - tmp0;										//return the ticks elapsed
	//need to make sure that F_CPU * cnt doesn't overflow 2^32
	return ((F_CPU * cnt) << ((RCC->CFGR & RCC_CFGR_MCOPRE) >> 28)) / (tmp1 - tmp0);	//return the measured frequency
}


//flip the led
void led_flp(void) {
	pinFlip(LED);
}

//user defined set up code
void setup(void) {
	//configure the system clock
	//SystemCoreClockHSI();						//hsi as clock
	//SystemCoreClockHSIPLL();					//hsixpll as clock
	//SystemCoreClockHSIPLL4M();

	//configure pins
#if defined(VDD)
	pinMode(VDD, OUTPUT); digitalWrite(VDD, HIGH);
#endif
#if defined(GND)
	pinMode(GND, OUTPUT); digitalWrite(GND, LOW);
#endif
	pinMode(LED, OUTPUT);						//led as output pin

	//initialize the uart
	//uart1Init(UART_BR115K2);					//initialize uart1
	uart2Init(UART_BR115K2);					//initialize uart2
	//lpuart1Init(UART_BR115K2);				//initialize lpuart1

	//tmr initialization
	//tmr2Init(1); 
	//tmr2OC1SetPR(10000); tmr2OC1AttachISR(led_flp);
	//tmr2OC2SetPR(10100); tmr2OC2AttachISR(led_flp);
	//tmr3Init(10); 
	//tmr3OC1SetPR(10000); tmr3OC1AttachISR(led_flp);
	//tmr3OC2SetPR(10100); tmr3OC2AttachISR(led_flp);
	//lptmr2Init(LPTIM_PS64x); /*lptmr2AttachISR(led_flp); */lptmr2Start();
	//tmr16Init(1000); 
	//tmr31Init(1);
	
	//pwm
	//pwm16Init(1); pwm16SetDC1(10); 

	//initialize pins to AFIO
	//pin2AFIO2(PB13); 
	//pin2AFIO(PA10, AFIO3);

	//reset the rtc
	//RTCInit(RCC_BDCR_RTCSEL_LSI, F_LSI); time2RTC(1234567890ul);
	//sRTCInit(); time2sRTC(RTC2time(NULL));

	//initialize rng
	//rngInit();
	
	//aesInit();
	
	ei();										//enable interrupts	
}

//user defined main loop
void loop(void) {
	static uint32_t tmp0=0, tmp;
	static uint32_t sec0, sec1;

	//update software rtc
	//sRTCUpdate();
	
	
	if (ticks() - tick0 > LED_DLY) {tick0 += LED_DLY;						//advance to the next match point
	//if (tmr2Get() - tick0 > LED_DLY) {tick0 += LED_DLY;						//advance to the next match point
	//if (lptmr2OVF()) {lptmr2OVFCLR(); lptmr2Start();	//tick0 += LED_DLY;						//advance to the next match point
	//if (tmr16Get() - tick0 > 10000) {tick0 += 10000;
	//if (tick0++ > LED_DLY / 500) {tick0=0;
		pinFlip(LED);							//flip led, 105 ticks

		//benchmark
		tmp0 = ticks();							//stamp tick1
		//do something
		//digitalRead(PA5);						//read a pin, 59 ticks (base case = 29 ticks, if there is nothing)
		//uart1Init(UART_BR9600);					//in   itial uart, 1328 ticks
		//digitalWrite(LED, !digitalRead(LED));	//flip led, 105 ticks
		//tmp=analogRead(ADC_TS);
		//for (tmp=0; tmp<1000; tmp++) digitalWrite(LED, !digitalRead(LED));	//flip led, 48K/1K ticks
		//for (tmp=0; tmp<1000; tmp++) IO_FLP(GPIOB, 1<<7);					//flip led, 11K/1K ticks
		//for (tmp=0; tmp<1000/5; tmp++) {digitalWrite(LED, !digitalRead(LED));digitalWrite(LED, !digitalRead(LED));digitalWrite(LED, !digitalRead(LED));digitalWrite(LED, !digitalRead(LED));digitalWrite(LED, !digitalRead(LED));}	//flip led, 42.1K/1K ticks
		//for (tmp=0; tmp<1000/5; tmp++) {IO_FLP(GPIOB, 1<<7);	IO_FLP(GPIOB, 1<<7);	IO_FLP(GPIOB, 1<<7);	IO_FLP(GPIOB, 1<<7);	IO_FLP(GPIOB, 1<<7);	}				//flip led, 4.6K/1K ticks
		//tmp=ticks() - tmp0;
		coremark_main();						//coremark benchmark
		tmp0 = ticks() - tmp0;					//calculate time elapsed

		//display something
		//u2Print("F_CORE=                    ", SystemCoreClock);
		u2Print("F_CPU =                    ", F_CPU);
		//u2Print("F_UART=                    ", F_UART);
		//u2Print("F_PCLK=                    ", F_PCLK);
		u2Print("ticks =                    ", ticks());
		//u2Print("T31CNT=                    ", tmr16Get());
		//u2Print("T2CNT =                    ", tmr2Get());
		//u2Print("brr =                      ", USART2->BRR);
		//u2Print("CalRTC=                    ", LSICalRTC(1));
		u2Print("CalT14=                    ", LSICalT14(4));
		u2Print("u2bps =                    ", u2bps());
		//u2Print("ticks =                    ", tick0);
		//u2Print("tmp0  =                    ", tmp0);
		//u2Print("adc   =                    ", analogRead(ADC_VBG));
		//u2Print("adc_e =                    \r\n", analogRead(ADC_VBG2));
		//u2Print("ticks =                    ", tmp1-tmp0);
		//u2Print("rng   =                    ", rngGet());		
		//lpuart1Puts(aesCipher(str));
		u2Println();

		//rtt
		//SEGGER_RTT_WriteString(0, "###### Testing SEGGER_printf() ######\r\n");
	}
}
