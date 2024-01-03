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
//   GND<-------| Vss            PC13 |>----> LED
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
//STM32F100RB_VL Discovery
//              |=====================|
//              |                     |
//              |                PC8  |>-----------> LEDB
//              |                     |
//              |                PC9  |>-----------> LEDG
//              |                     |
//              |                     |
//              |=====================|
//
//

#include "stm32duino.h"					//we use pic24duino
//#include "led4x7seg.h"					//we use 4x7seg led
#include "coremark.h"						//we use coremark

//hardware configuration
#define LED			PC13				//pin grounded
#define LEDB		PC8					//blue led
#define LEDG		PC9					//green led
#define GND			PB13				//led pin
#define LED_DLY		(F_PHB / 1)			//half a second
//end hardware configuration

//global defines

//global variables
volatile uint32_t tmp0, tmp;							//temporary variable


//Use RTC to measure LSI: capture the ticks elapsed based on RTC seconds
uint32_t rtcCal(uint32_t sec) {
	uint32_t tmp0, i=sec;
	
	tmp0  = RTCGetSec(); while (tmp0 == RTCGetSec()) continue;	//wait for the second to turn
	tmp0 = ticks();												//time stamp tick
	while (RTCGetSec() <= tmp + sec) continue;					//wait for the time to pass
	tmp0 = ticks() - tmp0;										//time stamp tick
	return tmp0 / sec;											//return the ticks elapsed in a second
}

//flip the led
void led_flp(void) {
	pinFlip(LED);												//flip te led
}

//user defined set up code
void setup(void) {
	//configure clock
	//SystemCoreClockHSI(); HSITrimSet(-2);			//hsi as clock
	//SystemCoreClockHSI48Mhz();					//hsixpll as clock
	SystemCoreClockHSE();							//hse as clock
	//SystemCoreClockHSEPLL4x();					//hsexpll
	//SystemCoreClock2HSE();
	
	//configure gpio pins
#if defined(VCC)
	pinMode(VCC, OUTPUT); digitalWrite(VCC, HIGH);	//gnd pin grounded
#endif	//vcc
#if defined(GND)
	pinMode(GND, OUTPUT); digitalWrite(GND, LOW);	//gnd pin grounded
#endif	//gnd
#if defined(LED)
	pinMode(LED, OUTPUT); digitalWrite(LED, HIGH);	//led as output pin, active LOW
	//IO_OUTPP2M(GPIOC, 1<<13);
#endif	//led
	//initialize the uart
	uart1Init(UART_BR115K2);						//initialize uart1
	//uart2Init(UART_BR115K2);						//initialize uart2
	//uart3Init(UART_BR115K2);						//initialize uart3
	
	//16-bit timers
	tmr2Init(F_CPU / 100000ul); //tmr3OVFAttachISR(led_flp);			//prescaler has no effect on tim14
	//tmr2OC3SetPR(1000+00); tmr2OC3AttachISR(led_flp);
	//tmr2OC4SetPR(1000+10); tmr2OC4AttachISR(led_flp);
	//tmr4Init(1);

	//32-bit timers
	//tmr23Init(1); //tmr23OVFAttachISR(led_flp);		//prescaler has no effect on tim14
	
	//configure led
	//initialize 4-digit, 7-segment led display
	//led_init(); lRAM[0]=lRAM[1]=lRAM[2]=lRAM[3]=8;		//display '8' on all digits
	//install a periodic timer / driver and enable pb3/4 for gpio on afio - no swd after this
	//tmr2OC1SetPR(20000); tmr2OC1AttachISR(led_display); //SWD2GPIO();									
	
	//RTCInitLSE(); //RTCSetCNT(0x12345678ul);
	//RTCSECAttachISR(led_flp);			//configure rtc
	//RTCSetALR(RTCGetCNT() + 2); //RTCALRAttachISR(led_flp);
	//adc1Init();										//configure adc

	//bkpInit(); if (bkp1Get() == 0) bkp1Set(1);		//configure bkp for persistent memory
	
	//odrptr=(uint32_t *)BIO2BB((uint32_t) &(GPIOC->ODR), 13);
	
	ei();												//enable interrupts
}

//user defined main loop
void loop(void) {
	volatile static uint32_t tick0=0;					//keep track of ticks
	static uint16_t tick16=0;
	static char cnt=0;
	uint32_t tmp;

	//if (tick0++ > 10000ul) {tick0 = 0;
	//if (tmr2Get() - tick16 > LED_DLY / 1000) {tick16 += LED_DLY / 1000;						//advance to the next match point
	if (ticks() - tick0 > LED_DLY) {tick0 += LED_DLY;						//advance to the next match point
		pinFlip(LED);							//flip led, 105 ticks
		//if (cnt&0x01) PB13toPU(); else PB13toPP();
		//BIO_FLP(GPIOC, 13);


		//benchmark
		tmp0=ticks(); 
		//digitalRead(PA5);						//read a pin, 59 ticks (base case = 29 ticks, if there is nothing)
		//uart1Init(UART_BR9600);				//initial uart, 1328 ticks
		//digitalWrite(LED, !digitalRead(LED));	//flip led, 105 ticks
		//tmp=analogRead(ADC_TS);
		//for (tmp=0; tmp<1000; tmp++) pinFlip(LED);	//flip led, 116.6k/1k ticks
		//for (tmp=0; tmp<1000/5; tmp++) {pinFlip(LED); pinFlip(LED); pinFlip(LED); pinFlip(LED); pinFlip(LED); }	//flip led, 106.5k/1k ticks
		//for (tmp=0; tmp<1000; tmp++) GIO_FLP(GPIOB, 1<<7);					//flip led, 20.5k/1k ticks
		//for (tmp=0; tmp<1000/5; tmp++) {GIO_FLP(GPIOB, 1<<7);GIO_FLP(GPIOB, 1<<7);GIO_FLP(GPIOB, 1<<7);GIO_FLP(GPIOB, 1<<7);GIO_FLP(GPIOB, 1<<7);}					//flip led, 12.1k/1000 ticks
		//for (tmp=0; tmp<1000/5; tmp++) {FIO_SET(GPIOB, 1<<7); FIO_CLR(GPIOB, 1<<7); FIO_SET(GPIOB, 1<<7); FIO_CLR(GPIOB, 1<<7); FIO_SET(GPIOB, 1<<7); FIO_CLR(GPIOB, 1<<7); FIO_SET(GPIOB, 1<<7); FIO_CLR(GPIOB, 1<<7); FIO_SET(GPIOB, 1<<7); FIO_CLR(GPIOB, 1<<7); }	//6.7K/1k
		//for (tmp=0; tmp<1000/5; tmp++) {BIO_SET(GPIOB, 1<<7); BIO_CLR(GPIOB, 1<<7); BIO_SET(GPIOB, 1<<7); BIO_CLR(GPIOB, 1<<7); BIO_SET(GPIOB, 1<<7); BIO_CLR(GPIOB, 1<<7); BIO_SET(GPIOB, 1<<7); BIO_CLR(GPIOB, 1<<7); BIO_SET(GPIOB, 1<<7); BIO_CLR(GPIOB, 1<<7); }	//15.7K/1k
		//for (tmp=0; tmp<1000/5; tmp++) {*odrptr = 1; *odrptr = 0;*odrptr = 1; *odrptr = 0;*odrptr = 1; *odrptr = 0;*odrptr = 1; *odrptr = 0;*odrptr = 1; *odrptr = 0;}	//3.7K/1K
		//PC13FLPx1K();	//FIO: 4.0K/1K on BRR/BSRR, 9.0K/1K on ^ODR
		//PB13FLPx1k();		//19k/1k. 310.9K/1k using pinMode()
		//tmp0 = ticks();												//time stamp tick
		coremark_main();						//coremark benchmark
		tmp0=ticks() - tmp0;
		
		//bkp1Set(bkp1Get() + 1);
		//display information
		//u1Print("F_CPU=                    ", F_CPU);
		//u1Print("tick0=                    ", tick0);
		//u1Print("tmp0 =                    ", tmp0);
		//u1Print("adc  =                    ", analogRead(ADC_VBG));
		//u1Print("adc_e=                    ", analogRead(ADC_VBG2));
		//u1Print("ticks=                    ", tmp0=ticks());
		//u1Print("ticks=                    ", tmp1=ticks());
		//u1Print("ticks=                    \r\n", tmp1-tmp0);
		//u1Println();
		//bkp1Set(bkp1Get() + 1);
		
		//display something on the led4x7
		//tmp = (analogRead(ADC_VREF));						//value to be displayed
		//tmp = ADC2Fx100(analogRead(ADC_TEMP));						//value to be displayed
		//tmp = bkp1Get();
		//RTCInitLSE(); tmp = rtcCal(10);
		//tmp = tmp0;
		//if (cnt++ & 0x01) tmp = tmp % 10000; else tmp = (tmp / 10000) % 10000;	//alternating between the first 4 digits / last 4 digits
		//lRAM[3]=tmp % 10; tmp /= 10;
		//lRAM[2]=tmp % 10; tmp /= 10;
		//lRAM[1]=tmp % 10; tmp /= 10;
		//lRAM[0]=tmp % 10; tmp /= 10;
	}	
	
}
