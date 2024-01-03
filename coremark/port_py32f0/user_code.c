//PY32F002A - programmable clock generator / frequency divider
//
//PY32duino code
// - using PY32F03002/003/030 chip
// - free running systick for ticks
// - 
// - version history
// - v0.1, 07/02/2023: initial port from stm32f0
// - v0.2, 08/15/2023: implemented gpio, timer, and pwm functionalities
// - v0.2a,08/19/2023: added hardware and software RTC support
// v v0.3, 08/20/2023: implemented PLL
//
//
//               PY32F002AF/TSSOP20
//      GND     |=====================|    Vdd
//       |      |                     |     |
//       +------| GND            Vdd  |-----+
//              |                     |
//              |                PA14 |<----- SWCLK (Pin3)
//              |                     |
//       +------| BOOT0          PA13 |<----> SWDIO (Pin2)
//              |                     |
//              |                     |
//              |                PA4  |--+--> GND
//              |                     |  |
//       +----->| OSCin/PF0      PA3  |--+--> LED
//    [Xtal]    |                     |
//       +-----<| OSCout/PF1          |
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

#include "py32duino.h"						//we use py32f0
#include "coremark.h"						//we use coremark

//hardware configuration
#define LED0		PA3						//led pin
#define GND			PA4						//pin grounded
#define LED_DLY		(F_CPU / 2)				//half a second

//for uart debugging
#define VDD			PA1						//pa1 high
#define LEDR		PA2						//led red
//end hardware configuration

//global defines

//global variables
uint32_t tick0;


//flip the led
void led_flp(void) {
	pinFlip(LED0);
}

//user defined set up code
void setup(void) {
	//set up the clock - default HSI@8M
	//SystemCoreClockHSI4M();						//select hsi clock
	//SystemCoreClockHSI48M();					//select hsixpll as clock
	//SystemCoreClockHSE();						//systemcoreclock to HSE
	//SystemCoreClockHSIPLL();					//systemcoreclock to HSExpll
	//LSITrimSet(+2);
	
#if defined(GND)
	pinMode(GND, OUTPUT); digitalWrite(GND, LOW);	//gnd pin grounded
#endif
#if defined(VDD)
	pinMode(VDD, OUTPUT); digitalWrite(VDD, HIGH);	//vdd pulled high
#endif
	pinMode(LED0,OUTPUT); digitalWrite(LED0,HIGH);	//led as output pin

	//initialize the uart
	uart1Init(UART_BR115K2);					//initialize uart1
	//uart2Init(UART_BR115K2);					//initialize uart2
	
	//16-bit timers
	//tmr3Init(100); tmr3OC1SetPR(1000); tmr3OC1AttachISR(led_flp); tmr3OC2SetPR(1010); tmr3OC2AttachISR(led_flp);
	//tmr16Init(10); tmr16OC1SetPR(1010); tmr16OC1AttachISR(led_flp);
	
	//configure mco
	//MCO2LSI(4);									//map mco to LSI (32768Hz nominal)

	tick0=ticks();								//initialize tick0
	
	ei();										//enable interrupts
}

//user defined main loop
void loop(void) {
	uint32_t tmp0, tmp;

	//if (tmr16Get() - tick16 > LED_DLY / tmr16GetPS()) {tick16 += LED_DLY / tmr16GetPS();
	//if (tick0++ > 10000ul) { tick0 = 0;						//reset tick0
	if (ticks() - tick0 > LED_DLY) { tick0 += LED_DLY;						//advance to the next match point
		pinFlip(LED0);							//flip led, 105 ticks
		
		//benchmark
		tmp0 = ticks();							//stamp tick1
		//do something
		coremark_main();						//coremark benchmark
		tmp0 = ticks() - tmp0;					//calculate time elapsed

		//display something
		//u1Print("F_PLL =                    ", F_PLL);
		u1Print("F_CPU =                    ", F_APB);
		u1Print("ticks =                    ", ticks());
		//u1Print("tick0 =                    ", tick0);
		//u1Print("tick16=                    ", tick16);
		//u1Print("tmp0  =                    ", tmp0);
		//u1Print("LSITun=                    ", LSITune2(F_HSI));
		//u1Print("u1brr =                    ", USART1->BRR);
		//u1Print("RTCF  =                    ", LSICalRTC(2));
		//u1Print("T14F  =                    ", LSICalT14(4));
		u1Print("u1bps =                    ", u1bps());
		//u1Print("TIMCLK=                    ", TIMClock());
		//u1Print("T14Tks=                    ", T14Tks(8));
		//u1Print("TSCAL1=                    ", TSCAL1);		//941
		//u1Print("TSCAL2=                    ", TSCAL2);		//1130
		//u1Print("TempF =                    ", ADC2Fx100(analogRead(ADC_TEMP)));
		//u1Print("Vref  =                    ", ADC2mv(analogRead(ADC_VREF)));
		//u1Print("AIN0  =                    ", analogRead(ADC_CH0));
		//u1Print("adc_e=                    \r\n", analogRead(ADC_VBG2));
		//u1Print("ticks=                     ", tmp1-tmp0);
		//u1Print("hRTCSec=                   ", RTC2time(NULL));
		//u1Print("sRTCtim=                   ",sRTC2time(NULL));
		//u1Print("hRTCSec=                   ", RTCTicks(2));		//@trim=0, 4.030M vs. 4M; 
		//u1Print("sRTCSec=                   ",sRTCGetSec());
		//u1Print("d_time =                   ", RTC2time(NULL) - sRTC2time(NULL));
		//u1Print("rtcTks =                   ", rtcTks(4)/4);
		//uart1Puts(asctime(&tmp1));
		u1Println();
		
		//segger rtt
		//SEGGER_RTT_printf(0, "printf Test: %%d,      -12345 : %d.\r\n", tick0);	//1kb in flash
	}
}
