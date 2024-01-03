//PIC32duino code
// - using PIC32MX1xx/2xx
// - free running core timer for ticks() (or tmr2, selected by the user)
// - free running tmr2 for pwm / output compare / input capture
// - details available here: https://github.com/dannyf00/Minimalist-32-bit-Arduino-Clone
//
// - version history
// - v2.0, 5/13/2021: original port
// - v2.1, 5/26/2021: implemented SystemCoreClockUpdate() that updates SystemCoreClock during initialization
//                    implemented systicks() from TMR2 ISR - optional (in addition to core timer)
// - v2.2, 5/27/2021: implemented i2c/rtcc
// - v2.3, 6/19/2021: added support for output compare (dah!)
// - v2.4, 5/29/2021: output compare routines no longer advance compare registers
// - v2.5, 5/24/2022: added support for C32 compiler
// - v2.6, 6/04/2022: support IO port A..G
// - v2.7, 6/11/2022: added TinyScheduler macro
// - v2.6, 7/04/2022: uart transmission now via interrupts
// - v2.7, 9/03/2022: changed syntax for ocNInit()
// - v2.8, 9/18/2022: updated SystemCoreClockUpdate() to save 1KB
// - v2.9, 9/23/2022: implemented coretimer compare / match routines
// - v3.0, 10/9/2022: unified ticks() now that coreticks() and systicks() are comparable
// - v3.1, 10/22/2022: added software i2c
//
//
//hardware configuration
//
//               PIC32MX1/2xx
//              |=====================|
//    Vcc       |                     |
//     |        |                AVdd |>---+--[1k]-->Vcc
//     |        |                     |  [.1u]
//     +-[10K]-<| MCLR           AVss |>---+-------->GND
//              |                     |
//              |                     |
//     +------->| OSCI           Vcap |>--[.1u]-+->GND
//  [Xtal]      |                     |         |
//     +-------<| OSCO           Vss  |>--------+
//              |                     |
//     +------->| SOSCI          RPB0 |>---------->Uart2TX
// [32,768Hz]   |                     |
//     +-------<| SOSCO           RB7 |>---------->LED
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

#include "pic32duino.h"					//we use pic32duino

//hardware configuration
#define LED			PB7					//led pin
#define LED_DLY		(F_CPU / 2)			//duration of delay
//end hardware configuration

//global defines

//global variables

//user defined set up code
void setup(void) {
	//select main clock
	//SystemCoreClockFRC();				//use frc
	//SystemCoreClockFRCPLL();			//use frcpll
	//SystemCoreClockPOSC();				//use posc
	//SystemCoreClockPOSCPLL();			//use poscpll

    pinMode(LED, OUTPUT);				//led as output pin

    //initialize the uart
    //uart1Init(UART_BR38K4);				//initialize uart1
    uart2Init(UART_BR38K4);				//initialize uart2

    ei();								//enable interrupts
}

//user defined main loop
void loop(void) {
    static uint32_t tick0=0;
    static uint32_t tmp0;


    //if enough time has elapsed
    if (ticks() - tick0 > LED_DLY) {	//if enough time has passed
        tick0 += LED_DLY;				//advance to the next match point
        pinFlip(LED);					//digitalWrite(LED, !digitalRead(LED));	//flip led, 96 - 100 ticks

        //benchmarking
        tmp0=ticks();
        //something to measure
        coremark_main();				//coremark benchmark: 118454530 ticks/200 iterations
        tmp0=ticks() - tmp0;

        //display information
        u2Print("F_CPU=                 ", F_CPU);
        u2Print("ticks=                 ", ticks());
        u2Print("tmp0 =                 ", tmp0);
        //u2Print("DevID=                 ", PIC32ID->DEVID);
        //u2Print("TMR2 =                 ", TMR2);
        //u2Print("OC1R =                 ", OC1R);
        //u2Print("lcnt =                 ", led_cnt);
        //u2Print("F_SYS=                 ", SystemCoreClock);
        //u2Print("F_PHB=                 ", F_PHB);
        //u2Print("ticks=                 ", tmp1=ticks());
        //u2Print("ticks=                 ", tmp1-tmp0);
        //u2Print("RTCT =                 ", RTCCGetSec());
        //u2Print("RTCCK=                 ", RTCCONbits.RTCCLKON);
        //u2Print("RTCHS=                 ", RTCCONbits.HALFSEC);
        u2Println();
    }

}
