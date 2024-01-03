//PIC24duino code
// - using PIC24FJxxGA004/104, and GB004 family (GA002/004, GA102/104, and GB002/004 families)
// - free running timer2 for ticks, pwm and input capture
// - details: https://github.com/dannyf00/Minimalist-16-bit-Arduino-Clone
//
// - version history
// - v2.0, 5/15/2021: simplified port
// - v2.1, 5/26/2021: implemented SystemCoreClockUpdate() - to be executed during mcu initialization or after oscillator reconfiguration
// - v2.2, 6/06/2021: implemented hardware CRC (16-bit only).
// - v2.3, 6/07/2021: revised rtcc implementation
// - v2.4, 6/16/2021: updated to support GB002/004 chips
// - v2.5, 6/19/2021: implemented output compare (dah!)
// - v2.6, 5/19/2022: output compare routines no longer advance compare registers
// - v2.7, 5/24/2022: simplified support for GA00x, GA10x, and GB00x devices
// - v2.8, 5/24/2022: added support for C30 compiler
// - v2.9, 6/04/2022: support IO port A..G
// - v3.0, 6/11/2022: added TinySchedler macro
// - v3.1, 6/16/2022: added support for PIC24FJxxxGA110 and PIC24FJxxxGB110 chips (IC6..9, OC6..9, UART3..4 not supported)
// - v3.2, 10/15/2022: changed naming convention for the timing / delay functions
//
//
//
//               PIC24FJ
//              |=====================|
//    Vcc       |                     |
//     |        |                Vcap |>--[.1u]-+->GND
//     |        |                     |         |
//     +-[10K]-<| MCLR        DISVreg |>--------+
//              |                     |
//              |                     |
//     +------->| OSCI            Vdd |>--+------>Vcc
//  [Xtal]      |                     | [.1u]
//     +-------<| OSCO            Vss |>--+------>GND
//              |                     |
//              |                 RP0 |>---------->Uart2TX
//              |                     |
//              |                 RB5 |>---------->LED
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

#include "pic24duino.h"					//we use pic24duino

//hardware configuration
#define LED			PB5					//led pin
#define LED_DLY		(F_CPU / 2)			//half a second
//end hardware configuration

//global defines

//global variables

//flip led
void led_flp(void) {
	pinFlip(LED);						//flip led
}

//user defined set up code
void setup(void) {
	//switch clock - not all clock sources shown (LPRC)
	//SystemCoreClockFRC();						//switch to FRC
	//SystemCoreClockFRCPLL();					//switch to FRCxPLL
	//SystemCoreClockPOSC();					//switch to primary oscillator
	//SystemCoreClockPOSCPLL();					//switch to primary oscillator x PLL

    pinMode(LED, OUTPUT);				//led as output pin

    //initialize the uart
    //uart1Init(UART_BR9600);			//initialize uart1
    uart2Init(UART_BR38K4);				//initialize uart2

    ei();								//enable interrupts

}


//user defined main loop
void loop(void) {
    static uint32_t tick0=0;
    uint32_t tmp0;

    //if enough time has elapsed
    if (ticks() - tick0 > LED_DLY) {			//if enough time has passed
        tick0 += LED_DLY;						//advance to the next match point
        pinFlip(LED);							//digitalWrite(LED, !digitalRead(LED));	//flip led, 105 ticks

        //measure timing
        tmp0=ticks();
        //put some tasks here
        coremark_main();						//coremark benchmark:
        tmp0=ticks() - tmp0;

        //display something
        u2Print("F_CPU=                    ", F_CPU);
        u2Print("F_PHB=                    ", F_PHB);
        u2Print("ticks=                    ", ticks());
        u2Print("tmp0 =                    ", tmp0);
        u2Println();
    }
}
