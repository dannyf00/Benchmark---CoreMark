//dsPIC33duino code
// - supported chips: dspic33fj32GP302/304, dspic33fj64gp202/204/802/804, dspic33fj128gp202/204/802/804
// - free running timer2 for ticks, pwm and input capture
// - details: https://github.com/dannyf00/Minimalist-16-bit-Arduino-Clone
// - only XC16 support is provided
//
// - version history
// - v0.1, 12/29/2022: initial porting from pic24duino
//
//
//               dsPIC33FJ
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
//              |                 RB0 |>---------->Uart2TX
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

#include "dspic33duino.h"				//we use dspic33duino
#include "coremark.h"

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
	//select main clock
	SystemCoreClockFRC();				//use frc
	//SystemCoreClockFRCPLL();			//use frcpll
	//SystemCoreClockPOSC();				//use posc
	//SystemCoreClockPOSCPLL();			//use poscpll


    pinMode(LED, OUTPUT);				//led as output pin

    //initialize the uart
    //uart1Init(UART_BR9600);			//initialize uart1
    uart1Init(UART_BR38K4);				//initialize uart2

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
		coremark_main();						//run the benchmark
        tmp0=ticks() - tmp0;

        //display something
        u1Print("F_CPU =                    ", F_CPU);
        u1Print("ticks =                    ", ticks());
        u1Print("tmp0  =                    ", tmp0);
        u1Print("u2bps =                    ", u2bps());
        u1Println();
    }
}
