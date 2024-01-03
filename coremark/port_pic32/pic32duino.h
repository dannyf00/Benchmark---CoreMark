#ifndef _PIC32DUINO_H
#define _PIC32DUINO_H

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
// - v3.1a,11/25/2022: added circular buffer
// - v3.1b,12/25/2022: added true random number generators using ADC's lsb
// - v3.1c,12/31/2022: added support for reference oscillator
// - v3.1d,02/24/2023: added support for software rtc
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

#if defined(__XC32__)							//if we are using xc32
#include <xc.h>								//we use xc32
#elif defined(__C32__)						//otherwise, use c32
#include <p32xxxx.h>						//we use c32
#include <plib.h>							//plib functions on interrupts
#else
#error "PIC32Duino.h: unsupported compiler!"
#endif
#include <sys/attribs.h>					//attributes for interrupts
#include <stdint.h>							//we use uint types
#include <string.h>							//we use strcpy()
#include <time.h>							//we use gmtime()

//hardware configuration
#define USE_CORETICK						//comment out if you want to use timer2 for systick generation
#define F_XTAL				20000000ul		//crystal frequency, user-specified
#define F_SOSC				32768			//SOSC = 32768Hz, user-specified
//#define UART1_TXISR							//comment out if uart polling transmission is used
//#define UART2_TXISR							//comment out if uart polling transmission is used
#define uRAM_SIZE			40				//uRAM size

//configuration for circular buffer
/*******NOTE*************/
/******cBUFF_SIZE********/
/***must be power of 2***/
/************************/
#define cBUFF_SIZE 			256				//must be power of 2, 0..256 -> for longer buffers, change data type for writeIndex/readIndex
typedef char cbuffer_t;						//storage unit for the buffer
//end configuration for circular buffer

//end user specification

//uart1 pin configuration
#define U1TX2RP()			PPS_U1TX_TO_RPB3()			//map u1tx pin to an rp pin: A0, B3, B4, B15, B7, C7, C0, C5
#define U1RX2RP()			PPS_U1RX_TO_RPA2()			//map u1rx pin to an rp pin: A2, B6, A4, B13, B2, C6, C1, C3

//uart2 pin configuration
#define U2TX2RP()			PPS_U2TX_TO_RPB0()			//u2tx pin: A3, B14, B0, B10, B9, C9, C2, C4
//#define U2RX2RP()			PPS_U2RX_TO_RPB1()			//u2rx pin: A1, B5, B1, B11, B8, A8, C8, A9

//pwm/oc pin configuration
#define PWM12RP()			PPS_OC1_TO_RPB7()			//oc1 pin: A0, B3, B4, B15, B7, C7, C0, C5
#define PWM22RP()			PPS_OC2_TO_RPB8()			//oc2 pin: A1, B5, B1, B11, B8, A8, C8, A9
#define PWM32RP()			PPS_OC3_TO_RPB9()			//oc3 pin: A3, B14, B0, B10, B9, C9, C2, C4
#define PWM42RP()			PPS_OC4_TO_RPB2()			//oc4 pin: A2, B6, A4, B13, B2, C6, C1, C3
#define PWM52RP()			PPS_OC5_TO_RPA4()			//oc5 pin: A2, B6, A4, B13, B2, C6, C1, C3

//TxCK pin - default: comment out
//#define T1CK2RP()										//T1CK pin: RA4 (not remappable)
//#define T2CK2RP()			PPS_T2CK_TO_RPA0()			//T2CK pin: A0, B3, B4, B15, B7, C7, C0, C5
//#define T3CK2RP()			PPS_T3CK_TO_RPA1()			//T3CK pin: A1, B5, B1, B11, B8, A8, C8, A9
//#define T4CK2RP()			PPS_T4CK_TO_RPA2()			//T4CK pin: A2, B6, A4, B13, B2, C6, C1, C3
//#define T5CK2RP()			PPS_T5CK_TO_RPB9()			//T5CK pin: A3, B14, B0, B10, B9, C9, C2, C4

//input capture pin configuration
#define IC12RP()			PPS_IC1_TO_RPB6()			//ic1 pin: A2, B6, A4, B13, B2, C6, C1, C3
#define IC22RP()			PPS_IC2_TO_RPA3()			//ic2 pin: A3, B14, B0, B10, B9, C9, C2, C4
#define IC32RP()			PPS_IC3_TO_RPA1()			//ic3 pin: A1, B5, B1, B11, B8, A8, C8, A9
#define IC42RP()			PPS_IC4_TO_RPA0()			//ic4 pin: A0, B3, B4, B15, B7, C7, C0, C5
#define IC52RP()			PPS_IC5_TO_RPA2()			//ic5 pin: A2, B6, A4, B13, B2, C6, C1, C3

//spi
#define SCK1RP()										//not remappable
#define SDO1RP()			PPS_SDO1_TO_RPB1()			//sdo1 pin: A1, B5, B1, B11, B8, A8, C8, A9, A2, B6, A4, B13, B2, C6, C1, C3
#define SDI1RP()			PPS_SDI1_TO_RPA1()			//SDI1 pin: A1, B5, B1, B11, B8, A8, C8, A9
#define SCK2RP()										//not remappable
#define SDO2RP()			PPS_SDO2_TO_RPB1()			//sdo1 pin: A1, B5, B1, B11, B8, A8, C8, A9, A2, B6, A4, B13, B2, C6, C1, C3
#define SDI2RP()			PPS_SDI2_TO_RPA2()			//SDI1 pin: A2, B6, A4, B13, B2, C6, C1, C3

//extint pin configuration
//#define INT02RP()			PPS_INT1_TO_RPA3()			//int0 pin: fixed to rp7
#define INT12RP()			PPS_INT1_TO_RPB9()			//int0 pin: A3, B14, B0, B10, B9, C9, C2, C4
#define INT22RP()			PPS_INT2_TO_RPA2()			//int0 pin: A2, B6, A4, B13, B2, C6, C1, C3
#define INT32RP()			PPS_INT3_TO_RPA1()			//int0 pin: A1, B5, B1, B11, B8, A8, C8, A9
#define INT42RP()			PPS_INT4_TO_RPA0()			//int0 pin: A0, B3, B4, B15, B7, C7, C0, C5

//refcon input pins
#define REFCLKI2RP()		PPS_REFCLKI_TO_RPA0()		//refclki pin: A0, B3, B4, B15, B7, C7, C0, C5
#define REFCLKO2RP()		PPS_REFCLKO_TO_RPA2()		//refclko pin: A2, B6, A4, B13, B2, C6, C1, C3
//software i2c
#define sI2CSCLPIN			PB2
#define sI2CSDAPIN			PB1
//end software i2c

//software uart
#define UARTs_TX			PB1							//software uart tx on this pin
//end software uart
//end pin configuration

#define F_CPU				(SystemCoreClock)			//=SYSCLK: cpu runs at this speed
#define F_PHB				((F_CPU) >> (OSCCONbits.PBDIV))		//peripheral block runs at F_PB - default = F_CPU / 8
#define F_FRC				7991000ul					//frequency for internal RC oscillator. nominal 8000000ul, calibrated value. 7991000ul					//FRC frequency = 8Mhz, fixed
#define F_LPRC				(31250ul)					//LPRC frequency=31.25Khz, fixed
#define F_I2C1				1000000ul					//frequency for i2c
#define F_I2C2				1000000ul					//frequency for i2c
#define F_sI2C				1000000ul					//frequency for software i2c
#define FRCTRIM				(+3)						//+/-64. chip specific. ~1Khz/increment. +->speed up, -->slow down
#define FRCSetTrim(trim)	OSCTUNbits.TUN = (trim)			//OSCTUN = (trim)					//+/- 64
#define FRCGetTrim()		(OSCTUNbits.TUN)				//(OSCTUN & 0x3f)

#define PWM_PR				0xffff						//pwm period - do not change

//operate on a var/register
#define REG_EQU(var, bits)			var  = (bits)
#define REG_SET(var, bits)			var |= (bits)
#define REG_CLR(var, bits)			var &=~(bits)
#define REG_FLP(var, bits)			var ^= (bits)
#define REG_GET(var, bits)			((var) & (bits))
#define REG_MOD(var, bits, mask)	(var = ((var) &~(mask)) | ((bits) & (mask)))

//port manipulation macros for PIC.
#define IO_SET(port, bits)			REG_SET(port->LAT, bits)			//set bits on port
#define IO_CLR(port, bits)			REG_CLR(port->LAT, bits)			//clear bits on port
#define IO_FLP(port, bits)			REG_FLP(port->LAT, bits)			//flip bits on port
#define IO_GET(port, bits)			REG_GET(port->PORT,bits))			//return bits on port
#define IO_OUT(port, bits)			REG_CLR(port->TRIS,bits)			//set bits as output
#define IO_IN(port, bits)			REG_SET(port->TRIS,bits)			//set bits as input

//if gpio_typedef is used
#define GIO_SET(port, bits)			IO_SET(port, bits)			//set bits on port
#define GIO_CLR(port, bits)			IO_CLR(port, bits)			//clear bits on port
#define GIO_FLP(port, bits)			IO_FLP(port, bits)			//flip bits on port
#define GIO_GET(port, bits)			IO_GET(port, bits)		//return bits on port
#define GIO_OUT(port, bits)			IO_OUT(port, bits)			//set bits as output
#define GIO_IN(port, bits)			IO_IN(port,  bits)			//set bits as input

//fast port operations
#define FIO_SET(port, bits)			port->LATSET = (bits)		//set bits on port
#define FIO_CLR(port, bits)			port->LATCLR = (bits)		//clear bits on port
#define FIO_FLP(port, bits)			port->LATINV = (bits)		//flip bits on port
#define FIO_GET(port, bits)			((port->PORT) & (bits))		//return bits on port
#define FIO_OUT(port, bits)			port->TRISCLR = (bits)		//set bits as output
#define FIO_IN(port, bits)			port->TRISSET = (bits)		//set bits as input

//tiny scheduler macro
#define TS_RUN_WHILE(cs)	if (cs)						//tiny scheduler macro
#define tsWhile(cs)			TS_RUN_WHILE(cs)			//shorter notation


#define NOP()				Nop()						   //asm("nop")					//nop()
#define NOP2()				{NOP(); NOP();}
#define NOP4()				{NOP2(); NOP2();}
#define NOP8()				{NOP4(); NOP4();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP24()				{NOP16(); NOP8();}
#define NOP32()				{NOP16(); NOP16();}
#define NOP40()				{NOP32(); NOP8();}
#define NOP64()				{NOP32(); NOP32();}
#define NOP128()			{NOP64(); NOP64();}

#define sleep()				asm("sleep")					//put the mcu into sleep

#ifndef ei
#if defined(__XC__)
#define ei()				__builtin_enable_interrupts();	//asm volatile ("ei");	do {INTEnableInterrupts();	INTEnableSystemMultiVectoredInt();} while (0)	//__builtin_enable_interrupts()
#else
#define ei()				do {INTEnableInterrupts();	INTEnableSystemMultiVectoredInt();} while (0)	//__builtin_enable_interrupts()
#endif //__XC__
#endif

#ifndef di
#if defined(__XC__)
#define di()				__builtin_enable_interrupts();	//asm volatile ("di")	INTDisableInterrupts()			//__builtin_disable_interrupts()	//
#else
#define di()				do {INTDisableInterrupts(); /*INTDisableSystemMultiVectoredInt();*/} while (0)			//__builtin_disable_interrupts()	//
#endif		//__XC__
#endif

//for int status - C32 lacks certain functions available in XC32 as built-in functions
#if defined(__C32__)
#define __builtin_get_isr_state()			INTDisableInterrupts()
#define __builtin_set_isr_state(intStatus)	INTRestoreInterrupts(intStatus)
#endif		//__C32__

//unlock sysLOCK
#define SYS_UNLOCK(){SYSKEY=0x0; SYSKEY=0xAA996655; SYSKEY=0x556699AA; }

//lock sysLOCK
#define SYS_LOCK()	{SYSKEY=0x0; }

//unlock IOLOCK
#define IO_UNLOCK()	{SYSKEY=0x0; SYSKEY=0xAA996655; SYSKEY=0x556699AA; CFGCONbits.IOLOCK=0;}

//lock IOLOCK
#define IO_LOCK()	{SYSKEY=0x0; SYSKEY=0xAA996655; SYSKEY=0x556699AA; CFGCONbits.IOLOCK=1;}

//pps macros
//more on macro
//macros for remappable pins
//PPS input pins

//group 1
#define PPS_INT4_TO_RPA0()		INT4R = 0
#define PPS_INT4_TO_RPB3()		INT4R = 1
#define PPS_INT4_TO_RPB4()		INT4R = 2
#define PPS_INT4_TO_RPB15()		INT4R = 3
#define PPS_INT4_TO_RPB7()		INT4R = 4
#define PPS_INT4_TO_RPC7()		INT4R = 5
#define PPS_INT4_TO_RPC0()		INT4R = 6
#define PPS_INT4_TO_RPC5()		INT4R = 7

#define PPS_T2CK_TO_RPA0()		T2CKR = 0
#define PPS_T2CK_TO_RPB3()		T2CKR = 1
#define PPS_T2CK_TO_RPB4()		T2CKR = 2
#define PPS_T2CK_TO_RPB15()		T2CKR = 3
#define PPS_T2CK_TO_RPB7()		T2CKR = 4
#define PPS_T2CK_TO_RPC7()		T2CKR = 5
#define PPS_T2CK_TO_RPC0()		T2CKR = 6
#define PPS_T2CK_TO_RPC5()		T2CKR = 7

#define PPS_IC4_TO_RPA0()		IC4R = 0
#define PPS_IC4_TO_RPB3()		IC4R = 1
#define PPS_IC4_TO_RPB4()		IC4R = 2
#define PPS_IC4_TO_RPB15()		IC4R = 3
#define PPS_IC4_TO_RPB7()		IC4R = 4
#define PPS_IC4_TO_RPC7()		IC4R = 5
#define PPS_IC4_TO_RPC0()		IC4R = 6
#define PPS_IC4_TO_RPC5()		IC4R = 7

#define PPS_SS1I_TO_RPA0()		SS1R = 0
#define PPS_SS1I_TO_RPB3()		SS1R = 1
#define PPS_SS1I_TO_RPB4()		SS1R = 2
#define PPS_SS1I_TO_RPB15()		SS1R = 3
#define PPS_SS1I_TO_RPB7()		SS1R = 4
#define PPS_SS1I_TO_RPC7()		SS1R = 5
#define PPS_SS1I_TO_RPC0()		SS1R = 6
#define PPS_SS1I_TO_RPC5()		SS1R = 7

#define PPS_REFCLKI_TO_RPA0()	REFCLKIR = 0
#define PPS_REFCLKI_TO_RPB3()	REFCLKIR = 1
#define PPS_REFCLKI_TO_RPB4()	REFCLKIR = 2
#define PPS_REFCLKI_TO_RPB15()	REFCLKIR = 3
#define PPS_REFCLKI_TO_RPB7()	REFCLKIR = 4
#define PPS_REFCLKI_TO_RPC7()	REFCLKIR = 5
#define PPS_REFCLKI_TO_RPC0()	REFCLKIR = 6
#define PPS_REFCLKI_TO_RPC5()	REFCLKIR = 7


//group 2
#define PPS_INT3_TO_RPA1()		INT3R = 0
#define PPS_INT3_TO_RPB5()		INT3R = 1
#define PPS_INT3_TO_RPB1()		INT3R = 2
#define PPS_INT3_TO_RPB11()		INT3R = 3
#define PPS_INT3_TO_RPB8()		INT3R = 4
#define PPS_INT3_TO_RPA8()		INT3R = 5
#define PPS_INT3_TO_RPC8()		INT3R = 6
#define PPS_INT3_TO_RPA9()		INT3R = 7


#define PPS_T3CK_TO_RPA1()		T3CKR = 0
#define PPS_T3CK_TO_RPB5()		T3CKR = 1
#define PPS_T3CK_TO_RPB1()		T3CKR = 2
#define PPS_T3CK_TO_RPB11()		T3CKR = 3
#define PPS_T3CK_TO_RPB8()		T3CKR = 4
#define PPS_T3CK_TO_RPA8()		T3CKR = 5
#define PPS_T3CK_TO_RPC8()		T3CKR = 6
#define PPS_T3CK_TO_RPA9()		T3CKR = 7

#define PPS_IC3_TO_RPA1()		IC3R = 0
#define PPS_IC3_TO_RPB5()		IC3R = 1
#define PPS_IC3_TO_RPB1()		IC3R = 2
#define PPS_IC3_TO_RPB11()		IC3R = 3
#define PPS_IC3_TO_RPB8()		IC3R = 4
#define PPS_IC3_TO_RPA8()		IC3R = 5
#define PPS_IC3_TO_RPC8()		IC3R = 6
#define PPS_IC3_TO_RPA9()		IC3R = 7

#define PPS_U1CTS_TO_RPA1()		U1CTSR = 0
#define PPS_U1CTS_TO_RPB5()		U1CTSR = 1
#define PPS_U1CTS_TO_RPB1()		U1CTSR = 2
#define PPS_U1CTS_TO_RPB11()	U1CTSR = 3
#define PPS_U1CTS_TO_RPB8()		U1CTSR = 4
#define PPS_U1CTS_TO_RPA8()		U1CTSR = 5
#define PPS_U1CTS_TO_RPC8()		U1CTSR = 6
#define PPS_U1CTS_TO_RPA9()		U1CTSR = 7

#define PPS_U2RX_TO_RPA1()		U2RXR = 0
#define PPS_U2RX_TO_RPB5()		U2RXR = 1
#define PPS_U2RX_TO_RPB1()		U2RXR = 2
#define PPS_U2RX_TO_RPB11()		U2RXR = 3
#define PPS_U2RX_TO_RPB8()		U2RXR = 4
#define PPS_U2RX_TO_RPA8()		U2RXR = 5
#define PPS_U2RX_TO_RPC8()		U2RXR = 6
#define PPS_U2RX_TO_RPA9()		U2RXR = 7

#define PPS_SDI1_TO_RPA1()		SDI1R = 0
#define PPS_SDI1_TO_RPB5()		SDI1R = 1
#define PPS_SDI1_TO_RPB1()		SDI1R = 2
#define PPS_SDI1_TO_RPB11()		SDI1R = 3
#define PPS_SDI1_TO_RPB8()		SDI1R = 4
#define PPS_SDI1_TO_RPA8()		SDI1R = 5
#define PPS_SDI1_TO_RPC8()		SDI1R = 6
#define PPS_SDI1_TO_RPA9()		SDI1R = 7


//group 3
#define PPS_INT2_TO_RPA2()		INT2R = 0
#define PPS_INT2_TO_RPB6()		INT2R = 1
#define PPS_INT2_TO_RPA4()		INT2R = 2
#define PPS_INT2_TO_RPB13()		INT2R = 3
#define PPS_INT2_TO_RPB2()		INT2R = 4
#define PPS_INT2_TO_RPC6()		INT2R = 5
#define PPS_INT2_TO_RPC1()		INT2R = 6
#define PPS_INT2_TO_RPA3()		INT2R = 7


#define PPS_T4CK_TO_RPA2()		T4CKR = 0
#define PPS_T4CK_TO_RPB6()		T4CKR = 1
#define PPS_T4CK_TO_RPA4()		T4CKR = 2
#define PPS_T4CK_TO_RPB13()		T4CKR = 3
#define PPS_T4CK_TO_RPB2()		T4CKR = 4
#define PPS_T4CK_TO_RPC6()		T4CKR = 5
#define PPS_T4CK_TO_RPC1()		T4CKR = 6
#define PPS_T4CK_TO_RPA3()		T4CKR = 7

#define PPS_IC1_TO_RPA2()		IC1R = 0
#define PPS_IC1_TO_RPB6()		IC1R = 1
#define PPS_IC1_TO_RPA4()		IC1R = 2
#define PPS_IC1_TO_RPB13()		IC1R = 3
#define PPS_IC1_TO_RPB2()		IC1R = 4
#define PPS_IC1_TO_RPC6()		IC1R = 5
#define PPS_IC1_TO_RPC1()		IC1R = 6
#define PPS_IC1_TO_RPA3()		IC1R = 7

#define PPS_IC5_TO_RPA2()		IC5R = 0
#define PPS_IC5_TO_RPB6()		IC5R = 1
#define PPS_IC5_TO_RPA4()		IC5R = 2
#define PPS_IC5_TO_RPB13()		IC5R = 3
#define PPS_IC5_TO_RPB2()		IC5R = 4
#define PPS_IC5_TO_RPC6()		IC5R = 5
#define PPS_IC5_TO_RPC1()		IC5R = 6
#define PPS_IC5_TO_RPA3()		IC5R = 7

#define PPS_U1RX_TO_RPA2()		U1RXR = 0
#define PPS_U1RX_TO_RPB6()		U1RXR = 1
#define PPS_U1RX_TO_RPA4()		U1RXR = 2
#define PPS_U1RX_TO_RPB13()		U1RXR = 3
#define PPS_U1RX_TO_RPB2()		U1RXR = 4
#define PPS_U1RX_TO_RPC6()		U1RXR = 5
#define PPS_U1RX_TO_RPC1()		U1RXR = 6
#define PPS_U1RX_TO_RPA3()		U1RXR = 7

#define PPS_U2CTS_TO_RPA2()		U2CTSR = 0
#define PPS_U2CTS_TO_RPB6()		U2CTSR = 1
#define PPS_U2CTS_TO_RPA4()		U2CTSR = 2
#define PPS_U2CTS_TO_RPB13()	U2CTSR = 3
#define PPS_U2CTS_TO_RPB2()		U2CTSR = 4
#define PPS_U2CTS_TO_RPC6()		U2CTSR = 5
#define PPS_U2CTS_TO_RPC1()		U2CTSR = 6
#define PPS_U2CTS_TO_RPA3()		U2CTSR = 7

#define PPS_SDI2_TO_RPA2()		SDI2R = 0
#define PPS_SDI2_TO_RPB6()		SDI2R = 1
#define PPS_SDI2_TO_RPA4()		SDI2R = 2
#define PPS_SDI2_TO_RPB13()		SDI2R = 3
#define PPS_SDI2_TO_RPB2()		SDI2R = 4
#define PPS_SDI2_TO_RPC6()		SDI2R = 5
#define PPS_SDI2_TO_RPC1()		SDI2R = 6
#define PPS_SDI2_TO_RPA3()		SDI2R = 7

#define PPS_OCFB_TO_RPA2()		OCFBR = 0
#define PPS_OCFB_TO_RPB6()		OCFBR = 1
#define PPS_OCFB_TO_RPA4()		OCFBR = 2
#define PPS_OCFB_TO_RPB13()		OCFBR = 3
#define PPS_OCFB_TO_RPB2()		OCFBR = 4
#define PPS_OCFB_TO_RPC6()		OCFBR = 5
#define PPS_OCFB_TO_RPC1()		OCFBR = 6
#define PPS_OCFB_TO_RPA3()		OCFBR = 7

//group 4
#define PPS_INT1_TO_RPA3()		INT1R = 0
#define PPS_INT1_TO_RPB14()		INT1R = 1
#define PPS_INT1_TO_RPB0()		INT1R = 2
#define PPS_INT1_TO_RPB10()		INT1R = 3
#define PPS_INT1_TO_RPB9()		INT1R = 4
#define PPS_INT1_TO_RPC9()		INT1R = 5
#define PPS_INT1_TO_RPC2()		INT1R = 6
#define PPS_INT1_TO_RPC4()		INT1R = 7

#define PPS_T5CK_TO_RPA3()		T5CKR = 0
#define PPS_T5CK_TO_RPB14()		T5CKR = 1
#define PPS_T5CK_TO_RPB0()		T5CKR = 2
#define PPS_T5CK_TO_RPB10()		T5CKR = 3
#define PPS_T5CK_TO_RPB9()		T5CKR = 4
#define PPS_T5CK_TO_RPC9()		T5CKR = 5
#define PPS_T5CK_TO_RPC2()		T5CKR = 6
#define PPS_T5CK_TO_RPC4()		T5CKR = 7

#define PPS_IC2_TO_RPA3()		IC2R = 0
#define PPS_IC2_TO_RPB14()		IC2R = 1
#define PPS_IC2_TO_RPB0()		IC2R = 2
#define PPS_IC2_TO_RPB10()		IC2R = 3
#define PPS_IC2_TO_RPB9()		IC2R = 4
#define PPS_IC2_TO_RPC9()		IC2R = 5
#define PPS_IC2_TO_RPC2()		IC2R = 6
#define PPS_IC2_TO_RPC4()		IC2R = 7

#define PPS_SS2I_TO_RPA3()		SS2R = 0
#define PPS_SS2I_TO_RPB14()		SS2R = 1
#define PPS_SS2I_TO_RPB0()		SS2R = 2
#define PPS_SS2I_TO_RPB10()		SS2R = 3
#define PPS_SS2I_TO_RPB9()		SS2R = 4
#define PPS_SS2I_TO_RPC9()		SS2R = 5
#define PPS_SS2I_TO_RPC2()		SS2R = 6
#define PPS_SS2I_TO_RPC4()		SS2R = 7

#define PPS_OCFA_TO_RPA3()		OCFAR = 0
#define PPS_OCFA_TO_RPB14()		OCFAR = 1
#define PPS_OCFA_TO_RPB0()		OCFAR = 2
#define PPS_OCFA_TO_RPB10()		OCFAR = 3
#define PPS_OCFA_TO_RPB9()		OCFAR = 4
#define PPS_OCFA_TO_RPC9()		OCFAR = 5
#define PPS_OCFA_TO_RPC2()		OCFAR = 6
#define PPS_OCFA_TO_RPC4()		OCFAR = 7

//PPS output pins
//group 1
#define PPS_NC_TO_RPA0()		RPA0R = 0
#define PPS_U1TX_TO_RPA0()		RPA0R = 1
#define PPS_U2RTS_TO_RPA0()		RPA0R = 2
#define PPS_SS1_TO_RPA0()		RPA0R = 3
#define PPS_OC1_TO_RPA0()		RPA0R = 0b0101
#define PPS_C2OUT_TO_RPA0()		RPA0R = 0b0111

#define PPS_NC_TO_RPB3()		RPB3R = 0
#define PPS_U1TX_TO_RPB3()		RPB3R = 1
#define PPS_U2RTS_TO_RPB3()		RPB3R = 2
#define PPS_SS1_TO_RPB3()		RPB3R = 3
#define PPS_OC1_TO_RPB3()		RPB3R = 0b0101
#define PPS_C2OUT_TO_RPB3()		RPB3R = 0b0111

#define PPS_NC_TO_RPB4()		RPB4R = 0
#define PPS_U1TX_TO_RPB4()		RPB4R = 1
#define PPS_U2RTS_TO_RPB4()		RPB4R = 2
#define PPS_SS1_TO_RPB4()		RPB4R = 3
#define PPS_OC1_TO_RPB4()		RPB4R = 0b0101
#define PPS_C2OUT_TO_RPB4()		RPB4R = 0b0111

#define PPS_NC_TO_RPB15()		RPB15R = 0
#define PPS_U1TX_TO_RPB15()		RPB15R = 1
#define PPS_U2RTS_TO_RPB15()	RPB15R = 2
#define PPS_SS1_TO_RPB15()		RPB15R = 3
#define PPS_OC1_TO_RPB15()		RPB15R = 0b0101
#define PPS_C2OUT_TO_RPB15()		RPB15R = 0b0111

#define PPS_NC_TO_RPB7()		RPB7R = 0
#define PPS_U1TX_TO_RPB7()		RPB7R = 1
#define PPS_U2RTS_TO_RPB7()		RPB7R = 2
#define PPS_SS1_TO_RPB7()		RPB7R = 3
#define PPS_OC1_TO_RPB7()		RPB7R = 0b0101
#define PPS_C2OUT_TO_RPB7()		RPB7R = 0b0111

#define PPS_NC_TO_RPC7()		RPC7R = 0
#define PPS_U1TX_TO_RPC7()		RPC7R = 1
#define PPS_U2RTS_TO_RPC7()		RPC7R = 2
#define PPS_SS1_TO_RPC7()		RPC7R = 3
#define PPS_OC1_TO_RPC7()		RPC7R = 0b0101
#define PPS_C2OUT_TO_RPC7()		RPC7R = 0b0111

#define PPS_NC_TO_RPC0()		RPC0R = 0
#define PPS_U1TX_TO_RPC0()		RPC0R = 1
#define PPS_U2RTS_TO_RPC0()		RPC0R = 2
#define PPS_SS1_TO_RPC0()		RPC0R = 3
#define PPS_OC1_TO_RPC0()		RPC0R = 0b0101
#define PPS_C2OUT_TO_RPC0()		RPC0R = 0b0111

#define PPS_NC_TO_RPC5()		RPC5R = 0
#define PPS_U1TX_TO_RPC5()		RPC5R = 1
#define PPS_U2RTS_TO_RPC5()		RPC5R = 2
#define PPS_SS1_TO_RPC5()		RPC5R = 3
#define PPS_OC1_TO_RPC5()		RPC5R = 0b0101
#define PPS_C2OUT_TO_RPC5()		RPC5R = 0b0111


//group 2
#define PPS_NC_TO_RPA1()		RPA1R = 0
#define PPS_SDO1_TO_RPA1()		RPA1R = 0b0011
#define PPS_SDO2_TO_RPA1()		RPA1R = 0b0100
#define PPS_OC2_TO_RPA1()		RPA1R = 0b0101
#define PPS_C3OUT_TO_RPA1()		RPA1R = 0b0111

#define PPS_NC_TO_RPB5()		RPB5R = 0
#define PPS_SDO1_TO_RPB5()		RPB5R = 0b0011
#define PPS_SDO2_TO_RPB5()		RPB5R = 0b0100
#define PPS_OC2_TO_RPB5()		RPB5R = 0b0101
#define PPS_C3OUT_TO_RPB5()		RPB5R = 0b0111

#define PPS_NC_TO_RPB1()		RPB1R = 0
#define PPS_SDO1_TO_RPB1()		RPB1R = 0b0011
#define PPS_SDO2_TO_RPB1()		RPB1R = 0b0100
#define PPS_OC2_TO_RPB1()		RPB1R = 0b0101
#define PPS_C3OUT_TO_RPB1()		RPB1R = 0b0111

#define PPS_NC_TO_RPB11()		RPB11R = 0
#define PPS_SDO1_TO_RPB11()		RPB11R = 0b0011
#define PPS_SDO2_TO_RPB11()		RPB11R = 0b0100
#define PPS_OC2_TO_RPB11()		RPB11R = 0b0101
#define PPS_C3OUT_TO_RPB11()	RPB11R = 0b0111

#define PPS_NC_TO_RPB8()		RPB8R = 0
#define PPS_SDO1_TO_RPB8()		RPB8R = 0b0011
#define PPS_SDO2_TO_RPB8()		RPB8R = 0b0100
#define PPS_OC2_TO_RPB8()		RPB8R = 0b0101
#define PPS_C3OUT_TO_RPB8()		RPB8R = 0b0111

#define PPS_NC_TO_RPA8()		RPA8R = 0
#define PPS_SDO1_TO_RPA8()		RPA8R = 0b0011
#define PPS_SDO2_TO_RPA8()		RPA8R = 0b0100
#define PPS_OC2_TO_RPA8()		RPA8R = 0b0101
#define PPS_C3OUT_TO_RPA8()		RPA8R = 0b0111

#define PPS_NC_TO_RPC8()		RPC8R = 0
#define PPS_SDO1_TO_RPC8()		RPC8R = 0b0011
#define PPS_SDO2_TO_RPC8()		RPC8R = 0b0100
#define PPS_OC2_TO_RPC8()		RPC8R = 0b0101
#define PPS_C3OUT_TO_RPC8()		RPA1R = 0b0111

#define PPS_NC_TO_RPA9()		RPA9R = 0
#define PPS_SDO1_TO_RPA9()		RPA9R = 0b0011
#define PPS_SDO2_TO_RPA9()		RPA9R = 0b0100
#define PPS_OC2_TO_RPA9()		RPA9R = 0b0101
#define PPS_C3OUT_TO_RPA9()		RPA9R = 0b0111


//group 3
#define PPS_NC_TO_RPA2()		RPA2R = 0
#define PPS_SDO1_TO_RPA2()		RPA2R = 0b0011
#define PPS_SDO2_TO_RPA2()		RPA2R = 0b0100
#define PPS_OC4_TO_RPA2()		RPA2R = 0b0101
#define PPS_OC5_TO_RPA2()		RPA2R = 0b0110
#define PPS_REFCLKO_TO_RPA2()	RPA2R = 0b0111

#define PPS_NC_TO_RPB6()		RPB6R = 0
#define PPS_SDO1_TO_RPB6()		RPB6R = 0b0011
#define PPS_SDO2_TO_RPB6()		RPB6R = 0b0100
#define PPS_OC4_TO_RPB6()		RPB6R = 0b0101
#define PPS_OC5_TO_RPB6()		RPB6R = 0b0110
#define PPS_REFCLKO_TO_RPB6()	RPB6R = 0b0111

#define PPS_NC_TO_RPA4()		RPA4R = 0
#define PPS_SDO1_TO_RPA4()		RPA4R = 0b0011
#define PPS_SDO2_TO_RPA4()		RPA4R = 0b0100
#define PPS_OC4_TO_RPA4()		RPA4R = 0b0101
#define PPS_OC5_TO_RPA4()		RPA4R = 0b0110
#define PPS_REFCLKO_TO_RPA4()	RPA4R = 0b0111

#define PPS_NC_TO_RPB13()		RPB13R = 0
#define PPS_SDO1_TO_RPB13()		RPB13R = 0b0011
#define PPS_SDO2_TO_RPB13()		RPB13R = 0b0100
#define PPS_OC4_TO_RPB13()		RPB13R = 0b0101
#define PPS_OC5_TO_RPB13()		RPB13R = 0b0110
#define PPS_REFCLKO_TO_RPB13()	RPB13R = 0b0111

#define PPS_NC_TO_RPB2()		RPB2R = 0
#define PPS_SDO1_TO_RPB2()		RPB2R = 0b0011
#define PPS_SDO2_TO_RPB2()		RPB2R = 0b0100
#define PPS_OC4_TO_RPB2()		RPB2R = 0b0101
#define PPS_OC5_TO_RPB2()		RPB2R = 0b0110
#define PPS_REFCLKO_TO_RPB2()	RPB2R = 0b0111

#define PPS_NC_TO_RPC6()		RPC6R = 0
#define PPS_SDO1_TO_RPC6()		RPC6R = 0b0011
#define PPS_SDO2_TO_RPC6()		RPC6R = 0b0100
#define PPS_OC4_TO_RPC6()		RPC6R = 0b0101
#define PPS_OC5_TO_RPC6()		RPC6R = 0b0110
#define PPS_REFCLKO_TO_RPC6()	RPC6R = 0b0111

#define PPS_NC_TO_RPC1()		RPC1R = 0
#define PPS_SDO1_TO_RPC1()		RPC1R = 0b0011
#define PPS_SDO2_TO_RPC1()		RPC1R = 0b0100
#define PPS_OC4_TO_RPC1()		RPC1R = 0b0101
#define PPS_OC5_TO_RPC1()		RPC1R = 0b0110
#define PPS_REFCLKO_TO_RPC1()	RPC1R = 0b0111

#define PPS_NC_TO_RPC3()		RPC3R = 0
#define PPS_SDO1_TO_RPC3()		RPC3R = 0b0011
#define PPS_SDO2_TO_RPC3()		RPC3R = 0b0100
#define PPS_OC4_TO_RPC3()		RPC3R = 0b0101
#define PPS_OC5_TO_RPC3()		RPC3R = 0b0110
#define PPS_REFCLKO_TO_RPC3()	RPC3R = 0b0111

//group 4
#define PPS_NC_TO_RPA3()		RPA3R = 0
#define PPS_U1RTS_TO_RPA3()		RPA3R = 0b0001
#define PPS_U2TX_TO_RPA3()		RPA3R = 0b0010
#define PPS_SS2_TO_RPA3()		RPA3R = 0b0100
#define PPS_OC3_TO_RPA3()		RPA3R = 0b0101
#define PPS_C1OUT_TO_RPA3()		RPA3R = 0b0111

#define PPS_NC_TO_RPB14()		RPB14R = 0
#define PPS_U1RTS_TO_RPB14()	RPB14R = 0b0001
#define PPS_U2TX_TO_RPB14()		RPB14R = 0b0010
#define PPS_SS2_TO_RPB14()		RPB14R = 0b0100
#define PPS_OC3_TO_RPB14()		RPB14R = 0b0101
#define PPS_C1OUT_TO_RPB14()	RPB14R = 0b0111

#define PPS_NC_TO_RPB0()		RPB0R = 0
#define PPS_U1RTS_TO_RPB0()		RPB0R = 0b0001
#define PPS_U2TX_TO_RPB0()		RPB0R = 0b0010
#define PPS_SS2_TO_RPB0()		RPB0R = 0b0100
#define PPS_OC3_TO_RPB0()		RPB0R = 0b0101
#define PPS_C1OUT_TO_RPB0()		RPB0R = 0b0111

#define PPS_NC_TO_RPB10()		RPB10R = 0
#define PPS_U1RTS_TO_RPB10()	RPB10R = 0b0001
#define PPS_U2TX_TO_RPB10()		RPB10R = 0b0010
#define PPS_SS2_TO_RPB10()		RPB10R = 0b0100
#define PPS_OC3_TO_RPB10()		RPB10R = 0b0101
#define PPS_C1OUT_TO_RPB10()	RPB10R = 0b0111

#define PPS_NC_TO_RPB9()		RPB9R = 0
#define PPS_U1RTS_TO_RPB9()		RPB9R = 0b0001
#define PPS_U2TX_TO_RPB9()		RPB9R = 0b0010
#define PPS_SS2_TO_RPB9()		RPB9R = 0b0100
#define PPS_OC3_TO_RPB9()		RPB9R = 0b0101
#define PPS_C1OUT_TO_RPB9()		RPB9R = 0b0111

#define PPS_NC_TO_RPC9()		RPC9R = 0
#define PPS_U1RTS_TO_RPC9()		RPC9R = 0b0001
#define PPS_U2TX_TO_RPC9()		RPC9R = 0b0010
#define PPS_SS2_TO_RPC9()		RPC9R = 0b0100
#define PPS_OC3_TO_RPC9()		RPC9R = 0b0101
#define PPS_C1OUT_TO_RPC9()		RPC9R = 0b0111

#define PPS_NC_TO_RPC2()		RPC2R = 0
#define PPS_U1RTS_TO_RPC2()		RPC2R = 0b0001
#define PPS_U2TX_TO_RPC2()		RPC2R = 0b0010
#define PPS_SS2_TO_RPC2()		RPC2R = 0b0100
#define PPS_OC3_TO_RPC2()		RPC2R = 0b0101
#define PPS_C1OUT_TO_RPC2()		RPC2R = 0b0111

#define PPS_NC_TO_RPC4()		RPC4R = 0
#define PPS_U1RTS_TO_RPC4()		RPC4R = 0b0001
#define PPS_U2TX_TO_RPC4()		RPC4R = 0b0010
#define PPS_SS2_TO_RPC4()		RPC4R = 0b0100
#define PPS_OC3_TO_RPC4()		RPC4R = 0b0101
#define PPS_C1OUT_TO_RPC4()		RPC4R = 0b0111

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

//gpio
//port structure
typedef struct {
	volatile uint32_t ANSEL;			//analog select
	volatile uint32_t ANSELCLR;		//set to clear
	volatile uint32_t ANSELSET;		//set to set
	volatile uint32_t ANSELINV;		//set to flip

	volatile uint32_t TRIS;			//data direction register -> 0ffset 0x0000, little endian
	//volatile uint32_t RESERVED0[3];   //fill the space
	volatile uint32_t TRISCLR;		  	//set to clear
	volatile uint32_t TRISSET;		  	//set to set
	volatile uint32_t TRISINV;		  	//set to flip

	volatile uint32_t PORT;			//input data register
	//volatile uint32_t RESERVED1[3];	//fill the space
	volatile uint32_t PORTCLR;		  	//set to clear
	volatile uint32_t PORTSET;		  	//set to set
	volatile uint32_t PORTINV;		  	//set to flip

	volatile uint32_t LAT;			  	//output data register
	//volatile uint32_t RESERVED2[3];   //fill the space
	volatile uint32_t LATCLR;		  	//set to clear
	volatile uint32_t LATSET;		  	//set to set
	volatile uint32_t LATINV;		  	//set to flip

	volatile uint32_t ODC;			  	//open drain configuration register. set to activate open drain
	//volatile uint32_t RESERVED3[3];	//fill the space
	volatile uint32_t ODCCLR;		  	//set to clear
	volatile uint32_t ODCSET;		  	//set to set
	volatile uint32_t ODCINV;		  	//set to flip

	volatile uint32_t CNPU;			//change notification weak pull-up
	//volatile uint32_t RESERVED4[3];   //fill the space
	volatile uint32_t CNPUCLR;		  	//set to clear
	volatile uint32_t CNPUSET;		  	//set to set
	volatile uint32_t CNPUINV;		  	//set to flip

	volatile uint32_t CNPD;			//change notification weak pull-down
	//volatile uint32_t RESERVED5[3];   //fill the space
	volatile uint32_t CNPDCLR;		  	//set to clear
	volatile uint32_t CNPDSET;		  	//set to set
	volatile uint32_t CNPDINV;		  	//set to flip

	volatile uint32_t CNCON;			//change notification control register (1<<15 to enable, 0<<15 to disable)
	volatile uint32_t RESERVED6[3];	//fill the space

	volatile uint32_t CNEN;			//change notification enable register (1->enable, 0->disable)
	//volatile uint32_t RESERVED7[3];   //fill the space
	volatile uint32_t CNENCLR;		  	//set to clear
	volatile uint32_t CNENSET;		  	//set to set
	volatile uint32_t CNENINV;		  	//set to flip

	volatile uint32_t CNSTAT;			//change notification status register (1->changed, 0->not changed)
	volatile uint32_t RESERVED8[3];	 //fill the space

} GPIO_TypeDef;						 //port definition registers

#if defined(_PORTA)
#define GPIOA						   ((GPIO_TypeDef *) &ANSELA)
#endif

#if defined(_PORTB)
#define GPIOB						   ((GPIO_TypeDef *) &ANSELB)
#endif

#if defined(_PORTC)
#define GPIOC						   ((GPIO_TypeDef *) &ANSELC)
#endif

#if defined(_PORTD)
#define GPIOD						   ((GPIO_TypeDef *) &ANSELD)
#endif

#if defined(_PORTE)
#define GPIOE						   ((GPIO_TypeDef *) &ANSELE)
#endif

#if defined(_PORTF)
#define GPIOF						   ((GPIO_TypeDef *) &ANSELF)
#endif

#if defined(_PORTG)
#define GPIOG						   ((GPIO_TypeDef *) &ANSELG)
#endif
//end GPIO

//DevID
typedef struct {
	uint32_t DEVID:28;					//device id
	uint8_t  VER:4;						//version
} DevID_TypeDef;

#define PIC32ID							((DevID_TypeDef *) &DEVID)
//see https://github.com/sergev/pic32prog/blob/master/target.c for a list of PIC32 device IDs
//end devid

//pre-requisite: FCKSM = CSECMD.
//NOSC bits 10..8
#define CLKNOSC_FRCDIV		(0b111 << 8)	//clock source = frc/
#define CLKNOSC_FRC16		(0b110 << 8)	//clock source = frc/16
#define CLKNOSC_LPRC		(0b101 << 8)	//clock source = lprc
#define CLKNOSC_SOSC		(0b100 << 8)	//clock source = sosc
#define CLKNOSC_POSCPLL		(0b011 << 8)	//clock source = hs, xt, ec + PLL
#define CLKNOSC_POSC		(0b010 << 8)	//clock source = hs, xt, ec
#define CLKNOSC_FRCPLL		(0b001 << 8)	//clock source = frc + PLL
#define CLKNOSC_FRC			(0b000 << 8)	//clock source = frc

//COSC bits 14..12
#define CLKCOSC_FRCDIV		(0b111 << 12)	//clock source = frc/
#define CLKCOSC_FRC16		(0b110 << 12)	//clock source = frc/16
#define CLKCOSC_LPRC		(0b101 << 12)	//clock source = lprc
#define CLKCOSC_SOSC		(0b100 << 12)	//clock source = sosc
#define CLKCOSC_POSCPLL		(0b011 << 12)	//clock source = hs, xt, ec + PLL
#define CLKCOSC_POSC		(0b010 << 12)	//clock source = hs, xt, ec
#define CLKCOSC_FRCPLL		(0b001 << 12)	//clock source = frc + PLL
#define CLKCOSC_FRC			(0b000 << 12)	//clock source = frc

//CLK FRCDIV bit 26..24
#define CLKFRCDIV_256		(0b111 << 24)	//frc divider = 256
#define CLKFRCDIV_64		(0b110 << 24)	//frc divider = 64
#define CLKFRCDIV_32		(0b101 << 24)	//frc divider = 32
#define CLKFRCDIV_16		(0b100 << 24)	//frc divider = 16
#define CLKFRCDIV_8			(0b011 << 24)	//frc divider = 8
#define CLKFRCDIV_4			(0b010 << 24)	//frc divider = 4
#define CLKFRCDIV_2			(0b001 << 24)	//frc divider = 2
#define CLKFRCDIV_1			(0b000 << 24)	//frc divider = 1

//CLK PLLDIV bit 29..27
#define CLKPLLDIV_256		(0b111 << 27)	//frc divider = 256
#define CLKPLLDIV_64		(0b110 << 27)	//frc divider = 64
#define CLKPLLDIV_32		(0b101 << 27)	//frc divider = 32
#define CLKPLLDIV_16		(0b100 << 27)	//frc divider = 16
#define CLKPLLDIV_8			(0b011 << 27)	//frc divider = 8
#define CLKPLLDIV_4			(0b010 << 27)	//frc divider = 4
#define CLKPLLDIV_2			(0b001 << 27)	//frc divider = 2
#define CLKPLLDIV_1			(0b000 << 27)	//frc divider = 1

//CLK PLLMULT bit 18..16
#define CLKPLLMULT_24		(0b111 << 16)	//frc divider = 256
#define CLKPLLMULT_21		(0b110 << 16)	//frc divider = 64
#define CLKPLLMULT_20		(0b101 << 16)	//frc divider = 32
#define CLKPLLMULT_19		(0b100 << 16)	//frc divider = 16
#define CLKPLLMULT_18		(0b011 << 16)	//frc divider = 8
#define CLKPLLMULT_17		(0b010 << 16)	//frc divider = 4
#define CLKPLLMULT_16		(0b001 << 16)	//frc divider = 2
#define CLKPLLMULT_15		(0b000 << 16)	//frc divider = 1

//global defines
extern uint32_t SystemCoreClock;			//sysclk = system core clock, updated by SystemCoreClockUpdate() after clock reconfiguration

//read sysclock back
//needs to be executed during mcu initialization or after oscillator reconfiguration
//returns SystemCoreClock
//Need to set fuse settings to ensure correct PLL operations
uint32_t SystemCoreClockUpdate(void);
#define FRCTUNE(trim)		OSCTUN = (trim)					//+/- 64

//pll constants
#define PLLMULT15x			0
#define PLLMULT16x			1
#define PLLMULT17x			2
#define PLLMULT18x			3
#define PLLMULT19x			4
#define PLLMULT20x			5
#define PLLMULT21x			6
#define PLLMULT24x			7
#define PLLODIV1			0
#define PLLODIV2			1
#define PLLODIV4			2
#define PLLODIV8			3
#define PLLODIV16			4
#define PLLODIV32			5
#define PLLODIV64			6
#define PLLODIV256			7

//assumes fpllidiv=1 (2:1)
#define pll0x125()			pllSet(PLLMULT16x, PLLODIV64)	//1/2*16/64
#define pll0x25()			pllSet(PLLMULT16x, PLLODIV32)	//1/2*16/32
#define pll0x5()			pllSet(PLLMULT16x, PLLODIV16)	//1/2*16/16
#define pll0x625()			pllSet(PLLMULT20x, PLLODIV16)	//1/2*20/16
#define pll0x75()			pllSet(PLLMULT24x, PLLODIV16)	//1/2*24/16
#define pll1x()				pllSet(PLLMULT16x, PLLODIV8)	//1/2*16/8
#define pll1x5()			pllSet(PLLMULT24x, PLLODIV8)	//1/2*24/8
#define pll2x()				pllSet(PLLMULT16x, PLLODIV4)	//1/2*16/4
#define pll2x5()			pllSet(PLLMULT20x, PLLODIV4)	//1/2*20/4
#define pll3x()				pllSet(PLLMULT24x, PLLODIV4)	//1/2*24/4
#define pll4x()				pllSet(PLLMULT16x, PLLODIV2)	//1/2*16/2
#define pll5x()				pllSet(PLLMULT20x, PLLODIV2)	//1/2*20/2
#define pll6x()				pllSet(PLLMULT24x, PLLODIV2)	//1/2*24/2
#define pll8x()				pllSet(PLLMULT16x, PLLODIV1)	//1/2*16/1
#define pll9x()				pllSet(PLLMULT18x, PLLODIV1)	//1/2*18/1
//set pll
void pllSet(uint32_t pll_mul, uint32_t pll_odiv);
#define pllWait()			while (OSCCONbits.SLOCK==0) continue	//wait for pll to lock

//switch sysclock back
//return SystemCoreClock frequency
//bit 10-8 NOSC<2:0>: New Oscillator Selection bits
//111 = Internal Fast RC Oscillator (FRC) divided by OSCCON<FRCDIV> bits
//110 = Internal Fast RC Oscillator (FRC) divided by 16
//101 = Internal Low-Power RC (LPRC) Oscillator
//100 = Secondary Oscillator (SOSC)
//011 = Primary Oscillator with PLL module (XTPLL, HSPLL or ECPLL)
//010 = Primary Oscillator (XT, HS or EC)
//001 = Internal Fast Internal RC Oscillator with PLL module via Postscaler (FRCPLL)
//000 = Internal Fast Internal RC Oscillator (FRC)
//On Reset, these bits are set to the value of the FNOSC Configuration bits (DEVCFG1<2:0>).
uint32_t SystemCoreClockSwitch(uint8_t nosc);
#define SystemCoreClockFRC()		do {SystemCoreClockSwitch(0b000);} while (0)
#define SystemCoreClockFRCPLL()		do {SystemCoreClockFRC();		   SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL1x()	do {SystemCoreClockFRC(); pll1x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL1x5()	do {SystemCoreClockFRC(); pll1x5();SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL2x()	do {SystemCoreClockFRC(); pll2x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL2x5()	do {SystemCoreClockFRC(); pll2x5();SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL3x()	do {SystemCoreClockFRC(); pll3x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL4x()	do {SystemCoreClockFRC(); pll4x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL5x()	do {SystemCoreClockFRC(); pll5x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL6x()	do {SystemCoreClockFRC(); pll6x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL8x()	do {SystemCoreClockFRC(); pll8x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockFRCPLL9x()	do {SystemCoreClockFRC(); pll9x(); SystemCoreClockSwitch(0b001); pllWait();} while (0)
#define SystemCoreClockPOSC()		do {SystemCoreClockSwitch(0b010);} while (0)
#define SystemCoreClockPOSCPLL()	do {SystemCoreClockFRC();		   SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL1x()	do {SystemCoreClockFRC(); pll1x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL1x5()	do {SystemCoreClockFRC(); pll1x5();SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL2x()	do {SystemCoreClockFRC(); pll2x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL2x5()	do {SystemCoreClockFRC(); pll2x5();SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL3x()	do {SystemCoreClockFRC(); pll3x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL4x()	do {SystemCoreClockFRC(); pll4x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL5x()	do {SystemCoreClockFRC(); pll5x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL6x()	do {SystemCoreClockFRC(); pll6x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL8x()	do {SystemCoreClockFRC(); pll8x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockPOSCPLL9x()	do {SystemCoreClockFRC(); pll9x(); SystemCoreClockSwitch(0b011); pllWait();} while (0)
#define SystemCoreClockSOSC()		do {SystemCoreClockSwitch(0b100);} while (0)
#define SystemCoreClockLPRC()		do {SystemCoreClockSwitch(0b101);} while (0)
#define SystemCoreClockFRC16()		do {SystemCoreClockSwitch(0b110);} while (0)
#define SystemCoreClockFRCDIV()		do {SystemCoreClockSwitch(0b111);} while (0)

//gpio definitions

//pin enum - matches GPIO_PinDef[]
typedef enum {
#if defined(GPIOA)
	PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
#endif		//GPIOA
#if defined(GPIOB)
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
#endif		//GPIOB
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

#define INPUT				0			//input pin
#define OUTPUT				1			//push-pull output pins
#define INPUT_PULLUP		2			//input with pull-up
#define INPUT_PULLDOWN		3			//input with pull-down
#define OUTPUT_OD			4			//output with open drain
#define INPUT_PU			INPUT_PULLUP
#define INPUT_PD			INPUT_PULLDOWN

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
#define round(x)	 		((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
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
//flip the pin
#define pinFlip(pin)		digitalWrite(pin, !digitalRead(pin))
void pinMode(PIN_TypeDef pin, uint8_t mode);
void digitalWrite(PIN_TypeDef pin, uint8_t mode);
int digitalRead(PIN_TypeDef pin);

//time base
#if defined(USE_CORETICK)
#define ticks()				coreticks()			//use core timer as tick generator
#else
#define ticks()				systicks()			//use tmr2 as tick / systick generator
#endif	//USE_CORETICK

#define coreticks()			(2*_CP0_GET_COUNT())	//core timer advances every 2 ticks
#define coretickInit()		coretimerInit()		//for compatability with older syntax
uint32_t systicks(void);							//use tmr2 as systick
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
#define cyclesPerMillisecond()	(clockCyclesPerMillisecond())
#define cyclesPerMicrosecond()	(clockCyclesPerMicrosecond())

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

//adc module
//rest the adc
//automatic sampling (ASAM=1), manual conversion
void adcInit(void);
//analog read on ADC1
//read DRL first for right aligned results
uint16_t analogRead(uint16_t pin);

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

//core timer
//initialize core timer - used for ticks()
void coretimerInit(void);
//set core timer period
uint32_t coretimerSetPR(uint32_t pr);
uint32_t coretimerGetPR();
//install core timer isr
void coretimerAttachISR(void (*isrptr)(void));

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

//for uart1
void uart1Init(unsigned long baud_rate);	//initiate the hardware usart
#define uart1Putch(ch)		do {uart1Wait(); U1TXREG=(ch);} while (0)	//void uart1Putch(char ch);					//send a char
void uart1Puts(char *str);					//send a string
//void uart1Putline(char *ln);				//send a string + line return
#define uart1Putline(str)	do {uart1Puts(str); uart1Puts("\r\n");} while (0)
#define uart1Getch()		U1RXREG			//uint8_t uart1Getch(void);					//read a char from usart
#define uart1Available()	U1STAbits.URXDA	//uint16_t uart1Available(void);				//test if data rx is available
#if defined(UART_TXISR)
#define uart1Busy()			(IEC1bits.U1TXIE)	//(!U1STAbits.TRMT)	//uint16_t uart1Busy(void);					//test if uart tx is busy
#else
#define uart1Busy()			(U1STAbits.UTXBF)	//(!U1STAbits.TRMT)	//(U1STAbits.UTXBF)	//(IEC1bits.U2TXIE)	//(!U1STAbits.TRMT)	//uint16_t uart1Busy(void);					//test if uart tx is busy
#endif	//isr
#define uart1Wait()			while (uart1Busy())
void u1Print(char *str, int32_t dat);		//print to uart1
#define u1Println()			uart1Puts("\r\n")
//for compatability
#define uart1Put(ch)		uart1Putch(ch)
#define uart1Get()			uart1Getch()
#define uart1bps()			((U1MODEbits.BRGH==1)?(F_UART / 4 / (U1BRG+1)):(F_UART / 16 / (U1BRG+1)))
#define u1bps()				uart1bps()

//for uart2
void uart2Init(unsigned long baud_rate);	//initiate the hardware usart
#define uart2Putch(ch)		do {uart2Wait(); U2TXREG=(ch);} while (0)	//void uart2Putch(char ch);					//send a char
void uart2Puts(char *str);					//send a string
//void uart2Putline(char *ln);				//send a string + line return
#define uart2Putline(str)	do {uart2Puts(str); uart2Puts("\r\n");} while (0)
#define uart2Getch()		U2RXREG			//uint8_t uart2Getch(void);					//read a char from usart
#define uart2Available()	U2STAbits.URXDA	//uint16_t uart2Available(void);				//test if data rx is available
#if defined(UART_TXISR)
#define uart2Busy()			(IEC1bits.U2TXIE)	//U2STAbits.UTXBF		//(!U2STAbits.TRMT)	//uint16_t uart2Busy(void);					//test if uart tx is busy
#else
#define uart2Busy()			(U2STAbits.UTXBF)	//(!U2STAbits.TRMT)	//(IEC1bits.U2TXIE)	//U2STAbits.UTXBF		//(!U2STAbits.TRMT)	//uint16_t uart2Busy(void);					//test if uart tx is busy
#endif	//isr
#define uart2Wait()			while (uart2Busy())
void u2Print(char *str, int32_t dat);		//print to uart2
#define u2Println()			uart2Puts("\r\n")
//for compatability
#define uart2Put(ch)		uart2Putch(ch)
#define uart2Get()			uart2Getch()
#define uart2bps()			((U2MODEbits.BRGH==1)?(F_UART / 4 / (U2BRG+1)):(F_UART / 16 / (U2BRG+1)))
#define u2bps()				uart2bps()
//end Serial

//software uart
#define UARTs_busy() 	(_UARTs_busy)		//1->software uart busy, 0->software uart not busy
#define UARTs_start()	_UARTs_busy=1		//start software uart
#define UARTs_stop()	_UARTs_busy=0		//stop software uart
#define UARTs_tick()	(_UARTs_tick)		//uart offset for each bit

extern uint32_t _UARTs_tick;				//timer ticks for each bit
extern volatile char _UARTs_busy;			//1=uart busy, 0->not busy

//software uart transmission routine
//how fast this routine is called determins the baudrate
void UARTs_tx(void);

//reset the software uart
void UARTs_init(uint16_t baudrate);

//start transmit
void UARTs_puts(char *str);

//end software uart

//tmr1 prescaler
#define TMR1_PS1x			0x00
#define TMR1_PS8x			0x01
#define TMR1_PS64x			0x02
#define TMR1_PS256x			0x03
#define TMR1_PSMASK			TMR1_PS256x

//tmr2-5 prescaler
#define TMR_PS1x			0x00
#define TMR_PS2x			0x01
#define TMR_PS4x			0x02
#define TMR_PS8x			0x03
#define TMR_PS16x			0x04
#define TMR_PS32x			0x05
#define TMR_PS64x			0x06
#define TMR_PS256x			0x07
#define TMR_PSMASK			TMR_PS256x

#define TMR_IPDEFAULT		2
#define TMR_ISDEFAULT		0

//timer structure
typedef struct {
	volatile uint32_t TMR;			//timer counter register
	volatile uint32_t TMRCLR;		//timer counter register
	volatile uint32_t TMRSET;		//timer counter register
	volatile uint32_t TMRINV;		//timer counter register
	volatile uint32_t PR;			//period register
	volatile uint32_t PRCLR;		//period register
	volatile uint32_t PRSET;		//period register
	volatile uint32_t PRINV;		//period register
	volatile uint32_t CON;			//timer control register
	volatile uint32_t CONCLR;		//timer control register
	volatile uint32_t CONSET;		//timer control register
	volatile uint32_t CONINV;		//timer control register
} TIM_TypeDef;						//timer definition registers

#define TIM1				((TIM_TypeDef *) &TMR1)
#define TIM2				((TIM_TypeDef *) &TMR2)
#define TIM3				((TIM_TypeDef *) &TMR3)
#define TIM4				((TIM_TypeDef *) &TMR4)
#define TIM5				((TIM_TypeDef *) &TMR5)

void tmrInit(TIM_TypeDef *TIMx, uint8_t ps);	//generic timer reset routine
void tmr1Init(uint8_t ps);		//initialize the timer1 (16bit)
#define tmr1SetPS(ps)		T1CONbits.TCKPS = (ps)
#define tmr1GetPS()			((T1CONbits.TCKPS == 0)?1:((T1CONbits.TCKPS == 1)?8:((T1CONbits.TCKPS == 2)?64:256)))
#define tmr1SetPR(pr)		do {PR1 = (pr) - 1;} while (0)
#define tmr1GetPR()			(PR1 + 1l)
#define tmr1Get()			(TMR1)
void tmr1AttachISR(void (*isrptr)(void));		//activate the isr handler

void tmr2Init(uint8_t ps);		//initialize the timer2 (16bit)
#define tmr2SetPS(ps)		T2CONbits.TCKPS = (ps)
#define tmr2GetPS()			((T2CONbits.TCKPS == 0)?1:((T2CONbits.TCKPS == 1)?8:((T2CONbits.TCKPS == 2)?64:256)))
#define tmr2SetPR(pr)		do {PR2 = (pr) - 1;} while (0)
#define tmr2GetPR()			(PR2 + 1l)
#define tmr2Get()			(TMR2)
void tmr2AttachISR(void (*isrptr)(void));		//activate the isr handler

void tmr3Init(uint8_t ps);		//initialize the timer1 (16bit)
#define tmr3SetPS(ps)		T3CONbits.TCKPS = (ps)
#define tmr3GetPS()			((T3CONbits.TCKPS == 0)?1:((T3CONbits.TCKPS == 1)?8:((T3CONbits.TCKPS == 2)?64:256)))
#define tmr3SetPR(pr)		do {PR3 = (pr) - 1;} while (0)
#define tmr3GetPR()			(PR3 + 1l)
#define tmr3Get()			(TMR3)
void tmr3AttachISR(void (*isrptr)(void));		//activate the isr handler

void tmr4Init(uint8_t ps);		//initialize the timer2 (16bit)
#define tmr4SetPS(ps)		T4CONbits.TCKPS = (ps)
#define tmr4GetPS()			((T4CONbits.TCKPS == 0)?1:((T4CONbits.TCKPS == 1)?8:((T4CONbits.TCKPS == 2)?64:256)))
#define tmr4SetPR(pr)		do {PR4 = (pr) - 1;} while (0)
#define tmr4GetPR()			(PR4 + 1l)
#define tmr4Get()			(TMR4)
void tmr4AttachISR(void (*isrptr)(void));		//activate the isr handler

void tmr5Init(uint8_t ps);		//initialize the timer1 (16bit)
#define tmr5SetPS(ps)		T5CONbits.TCKPS = (ps)
#define tmr5GetPS()			((T5CONbits.TCKPS == 0)?1:((T5CONbits.TCKPS == 1)?8:((T5CONbits.TCKPS == 2)?64:256)))
#define tmr5SetPR(pr)		do {PR5 = (pr) - 1;} while (0)
#define tmr5GetPR()			(PR5 + 1l)
#define tmr5Get()			(TMR5)
void tmr5AttachISR(void (*isrptr)(void));		//activate the isr handler

void tmr23Init(uint8_t ps);		//initialize the timer1 (16bit)
#define tmr23SetPS(ps)		tmr2SetPS(ps)	//do {tmr2SetPS(ps); tmr3SetPS(ps)} while (0)
#define tmr23GetPS()		tmr2GetPS()
#define tmr23SetPR(pr)		do {PR3 = ((pr) - 1) >> 16; PR2 = (pr) - 1;} while (0)
//#define tmr23SetPR(pr)		do {tmr2SetPR((pr)); tmr3SetPR((pr)>>16);} while (0)
#define tmr23GetPR()		((((uint32_t) PR3) << 16) | tmr2GetPR())
void tmr23AttachISR(void (*isrptr)(void));		//activate the isr handler
uint32_t tmr23Get(void);						//read tmr23

void tmr45Init(uint8_t ps);		//initialize the timer1 (16bit)
#define tmr45SetPS(ps)		tmr4SetPS(ps)	//do {tmr2SetPS(ps); tmr3SetPS(ps)} while (0)
#define tmr45GetPS()		tmr4GetPS()
#define tmr45SetPR(pr)		do {PR5 = ((pr) - 1) >> 16; PR4 = (pr) - 1;} while (0)
//#define tmr45SetPR(pr)		do {tmr4SetPR(pr); tmr5SetPR((pr)>>16);} while (0)
#define tmr45GetPR()		((((uint32_t) PR5) << 16) | tmr4GetPR())
void tmr45AttachISR(void (*isrptr)(void));		//activate the isr handler
uint32_t tmr45Get(void);						//read tmr45

//pwm / oc
//initialize pwm1
void pwm1Init(void);
#define pwm1SetDC(dc)			do {OC1RS = (dc) & 0xffff;} while (0)
#define pwm1GetDC()				(OC1RS)
#define pwm1SetPR(pr)			do {if (OC1CONbits.OCTSEL) PR3 = (pr) - 1; else PR2 = (pr) - 1;} while (0)
#define pwm1GetPR()				((OC1CONbits.OCTSEL)?tmr3GetPR():tmr2GetPR())
#define pwm1SetPS(ps)			((OC1CONbits.OCTSEL)?tmr3SetPS(ps):tmr2SetPS(ps))
#define pwm1GetPS()				((OC1CONbits.OCTSEL)?tmr3GetPS():tmr2GetPS())

//initialize pwm2
void pwm2Init(void);
#define pwm2SetDC(dc)			do {OC2RS = (dc) & 0xffff;} while (0)
#define pwm2GetDC()				(OC2RS)
#define pwm2SetPR(pr)			do {if (OC2CONbits.OCTSEL) PR3 = (pr) - 1; else PR2 = (pr) - 1;} while (0)
#define pwm2GetPR()				((OC2CONbits.OCTSEL)?tmr3GetPR():tmr2GetPR())
#define pwm2SetPS(ps)			((OC2CONbits.OCTSEL)?tmr3SetPS(ps):tmr2SetPS(ps))
#define pwm2GetPS()				((OC2CONbits.OCTSEL)?tmr3GetPS():tmr2GetPS())

//initialize pwm3
void pwm3Init(void);
#define pwm3SetDC(dc)			do {OC3RS = (dc) & 0xffff;} while (0)
#define pwm3GetDC()				(OC3RS)
#define pwm3SetPR(pr)			do {if (OC3CONbits.OCTSEL) PR3 = (pr) - 1; else PR2 = (pr) - 1;} while (0)
#define pwm3GetPR()				((OC3CONbits.OCTSEL)?tmr3GetPR():tmr2GetPR())
#define pwm3SetPS(ps)			((OC3CONbits.OCTSEL)?tmr3SetPS(ps):tmr2SetPS(ps))
#define pwm3GetPS()				((OC3CONbits.OCTSEL)?tmr3GetPS():tmr2GetPS())

//initialize pwm4
void pwm4Init(void);
#define pwm4SetDC(dc)			do {OC4RS = (dc) & 0xffff;} while (0)
#define pwm4GetDC()				(OC4RS)
#define pwm4SetPR(pr)			do {if (OC4CONbits.OCTSEL) PR3 = (pr) - 1; else PR2 = (pr) - 1;} while (0)
#define pwm4GetPR()				((OC4CONbits.OCTSEL)?tmr3GetPR():tmr2GetPR())
#define pwm4SetPS(ps)			((OC4CONbits.OCTSEL)?tmr3SetPS(ps):tmr2SetPS(ps))
#define pwm4GetPS()				((OC4CONbits.OCTSEL)?tmr3GetPS():tmr2GetPS())

//initialize pwm5
void pwm5Init(void);
#define pwm5SetDC(dc)			do {OC5RS = (dc) & 0xffff;} while (0)
#define pwm5GetDC()				(OC5RS)
#define pwm5SetPR(pr)			do {if (OC5CONbits.OCTSEL) PR3 = (pr) - 1; else PR2 = (pr) - 1;} while (0)
#define pwm5GetPR()				((OC5CONbits.OCTSEL)?tmr3GetPR():tmr2GetPR())
#define pwm5SetPS(ps)			((OC5CONbits.OCTSEL)?tmr3SetPS(ps):tmr2SetPS(ps))
#define pwm5GetPS()				((OC5CONbits.OCTSEL)?tmr3GetPS():tmr2GetPS())

//adc
//adc channels
#define ADC_AN0						0			//AN0 / RA0
#define ADC_AN1						1			//AN1 / RA1
#define ADC_AN2						2			//AN2 / RB0
#define ADC_AN3						3			//AN3 / RB1
#define ADC_AN4						4			//AN4 / RB2
#define ADC_AN5						5			//AN5 / RB3
#define ADC_AN6						6			//AN6 / RC0
#define ADC_AN7						7			//AN7 / RC1
#define ADC_AN8						8			//AN8 / RC2
#define ADC_AN9						9			//AN9 / RB15
#define ADC_AN10					10			//AN10/ RB14
#define ADC_AN11					11			//AN11/ RB13
#define ADC_AN12					12			//AN12/ RB12
#define ADC_AN13					13			//CTMUT
#define ADC_AN14					14			//internal reference IVref
#define ADC_AN15					15			//Open - tend to generate odd numbers
#define ADC_VREF					ADC_AN14	//internal reference IVref
#define ADC_ARAND					ADC_VREF	//the channel for random number generators
#define ADC_DLY						100			//typical wait for the adc to charge up at 8Mhz
//rest the adc
//automatic sampling (ASAM=1), manual conversion
void adcInit(void);

//read the adc
uint16_t analogRead(uint16_t ch);

//random number generators
#define arand1()			(analogRead(ADC_ARAND) & 0x01)	//generate 1-bit random number
uint8_t arand4(void);							//generate 4-bit random numbers
uint8_t arand8(void);							//generate 8-bit random numbers
uint16_t arand16(void);							//generate 16-bit random numbers
uint32_t arand32(void);							//generate 32-bit random numbers
//end ADC

//output compare
#define OC_IPDEFAULT		2
#define OC_ISDEFAULT		0

void oc1Init(uint16_t pr);						//initialize output compare
void oc1AttachISR(void (*isrptr)(void));		//activate usr isr

void oc2Init(uint16_t pr);						//initialize output compare
void oc2AttachISR(void (*isrptr)(void));		//activate usr isr

void oc3Init(uint16_t pr);						//initialize output compare
void oc3AttachISR(void (*isrptr)(void));		//activate usr isr

void oc4Init(uint16_t pr);						//initialize output compare
void oc4AttachISR(void (*isrptr)(void));		//activate usr isr

void oc5Init(uint16_t pr);						//initialize output compare
void oc5AttachISR(void (*isrptr)(void));		//activate usr isr

//input capture

#define IC_IPDEFAULT		1
#define IC_ISDEFAULT		0

//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic1Init(void);
void ic1AttachISR(void (*isrptr)(void));		//activate user ptr
//uint16_t ic1Get(void);						//read buffer value
#define ic1Get()			IC1BUF				//read buffer value

void ic2Init(void);
void ic2AttachISR(void (*isrptr)(void));		//activate user ptr
//uint16_t ic2Get(void);						//read buffer value
#define ic2Get()			IC2BUF				//read buffer value

void ic3Init(void);
void ic3AttachISR(void (*isrptr)(void));		//activate user ptr
//uint16_t ic3Get(void);						//read buffer value
#define ic3Get()			IC3BUF				//read buffer value

void ic4Init(void);
void ic4AttachISR(void (*isrptr)(void));		//activate user ptr
//uint16_t ic4Get(void);						//read buffer value
#define ic4Get()			IC4BUF				//read buffer value

void ic5Init(void);
void ic5AttachISR(void (*isrptr)(void));		//activate user ptr
//uint16_t ic5Get(void);						//read buffer value
#define ic5Get()			IC5BUF				//read buffer value
//end input capture

//extint
#define INT_IPDEFAULT		6
#define INT_ISDEFAULT		0

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

void spi1Init(uint32_t br);						//reset the spi
#define spi1Busy()			(SPI1STATbits.SPITBF)	//transmit buffer full, must wait before writing to SPIxBUF
#define spi1Available()		(!SPI1STATbits.SPIRBE)	//receive buffer not empty -> there is data
#define spi1Write(dat)		SPI1BUF = (dat)		//send data via spi
#define spi1Read()			(SPI1BUF)			//read from the buffer

void spi2Init(uint32_t br);						//reset the spi
#define spi2Busy()			(SPI2STATbits.SPITBF)	//transmit buffer full, must wait before writing to SPIxBUF
#define spi2Available()		(!SPI2STATbits.SPIRBE)	//receive buffer not empty -> there is data
#define spi2Write(dat)		SPI2BUF = (dat)		//send data via spi
#define spi2Read()			(SPI2BUF)			//read from the buffer

//end spi

//i2c
#define I2C_ACK			0
#define I2C_NOACK		1
#define I2C_CMD_WRITE	0
#define I2C_CMD_READ	1
#define I2C_ACK_ERROR	0x09						//max number of loops before ack times out

//i2c1
//#define F_I2C1			100000ul	//I2C frequency
void i2c1Init(uint32_t bps);			//initialize the i2c
void i2c1Start(void);					//send a start condition
void i2c1Stop(void);					//send a stop condition
void i2c1Restart(void);					//send a restart condition
//#define i2c1Wait()		do {while (I2C1CON & 0x1f); while (I2C1STATbits.TRSTAT);} while (0)		//wait for i2c
uint8_t i2c1Write(uint8_t dat);			//send i2c
uint8_t i2c1Read(uint8_t ack);			//read i2c
//write from a buffer
uint8_t i2c1Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite);
//read to a buffer
uint8_t i2c1Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead);

//I2C2
//#define F_I2C2			100000ul		//I2C frequency
void I2C2Init(uint32_t bps);			//initialize the I2C
void I2C2Start(void);					//send a start condition
void I2C2Stop(void);					//send a stop condition
void I2C2Restart(void);					//send a restart condition
//#define I2C1Wait()		do {while (I2C2CON & 0x1f); while (I2C2STATbits.TRSTAT);} while (0)		//wait for I2C
uint8_t I2C2Write(uint8_t dat);			//send I2C
uint8_t I2C2Read(uint8_t ack);			//read I2C
//write from a buffer
uint8_t I2C2Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite);
//read to a buffer
uint8_t I2C2Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead);
//end I2C

//software i2c
void sI2CInit(void);									//reset the software i2c
void sI2CStart(void);									//send a start condition
void sI2CStop(void);									//send a stop condition
#define sI2CRestart()		si2cStart()					//send a restart condition
uint8_t sI2CWrite(uint8_t dat);							//send a i2c byte
uint8_t sI2CRead(uint8_t ack);							//read i2c data
//write from a buffer
uint8_t sI2CWrites(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite);
//read to a buffer
uint8_t sI2CReads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead);
//end software i2c

//RTCC
//bcd to dec conversion
#define BCD2DEC(bcd)				((((bcd) & 0xf0)>>4)*10+((bcd) & 0x0f))		//convert bcd to int
#define DEC2BCD(dec)				(((((dec) / 10)<<4) +((dec) % 10)) & 0xff)	//convert int to bcd

//allows write to rtc registers
#define RTCC_WREN()				do {di(); SYSKEY=0xaa996655ul; SYSKEY=0x556699aaul; RTCCONbits.RTCWREN = 1; ei();} while (RTCCONbits.RTCWREN == 0)
//do not allow any write to rtc registers - assumes the nvmkey sequence has been sent
#define RTCC_WRDIS()			do {RTCCONbits.RTCWREN = 0;} while (RTCCONbits.RTCWREN == 1)
void RTCInit(void);							//initialize the RTCC
#define RTCGetTime()			(RTCTIME)			//get rtc time
#define RTCGetSec()				((RTCTIME >>  8)& 0xff)
#define RTCGetMin()				((RTCTIME >> 16)& 0xff)
#define RTCGetHour()			((RTCTIME >> 24)& 0xff)
uint32_t RTCSetTime(uint32_t val);				//set time
#define RTCGetDate()			(RTCDATE)			//get rtc date
#define RTCGetWDay()			((RTCDATE >>  0)& 0xff)
#define RTCGetDay()				((RTCDATE >>  8)& 0xff)
#define RTCGetMonth()			((RTCDATE >> 16)& 0xff)
#define RTCGetYear()			((RTCDATE >> 24)& 0xff)

uint32_t RTCSetDate(uint32_t val);				//set date
 int32_t RTCSetCal(int32_t offset);				//set calibration, -512 .. +511. number of RTC pulses to subtract / add every minute (+/- 260ppm)
//int32_t rtcGetCal(void);						//read the calibration
#define RTCGetCal()				(RTCCONbits.CAL)

time_t RTC2time(time_t *t);						//convert rtcc to time_t
time_t time2RTC(time_t t);						//turn mktime (=time_t) to RTCC
#define RTCHalfsec()			(RTCCONbits.HALFSEC)	//half sec: 0->first half sec and 1->second half sec
//end RTCC

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
//cnint
#define CN_IPDEFAULT		1
#define CN_ISDEFAULT		0

void cnaInit(uint16_t pins);					//initialize change notification
void cnaAttachISR(void (*isrptr) (void));		//attach user isr
void cnbInit(uint16_t pins);					//initialize change notification
void cnbAttachISR(void (*isrptr) (void));		//attach user isr
#if defined(_PORTC)
void cncInit(uint16_t pins);					//initialize change notification
void cncAttachISR(void (*isrptr) (void));		//attach user isr
#endif		//_PORTC
//end cnint

//comparator voltage reference
//initialize the comparator
void CVrefInit(void);
#define CVrefSet(range)		CVRCONbits.CVR=(range)
#define CVrefGet()			(CVRCONbits.CVR)
#define CVrefOE()			CVRCONbits.CVROE=1
#define CVrefOD()			CVRCONbits.CVROE=0
//end comparator voltage reference

//comparator
//end comparator
//initialize comparator
void CM1Init(void);
#define CM1OUT()			(CM1CONbits.COUT)	//comparator output status
#define CM1INA()			CM1CONbits.CREF= 0	//non-inverting input. 0->CxINA, 1->CVref
#define CM1CVref()			CM1CONbits.CREF= 1	//non-inverting input. 0->CxINA, 1->CVref
#define CM1INB()			CM1CONbits.CCH = 0	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM1INC()			CM1CONbits.CCH = 1	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM1IND()			CM1CONbits.CCH = 2	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM1INIref()			CM1CONbits.CCH = 3	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM1OE()				CM1CONbits.COE = 1	//1->enaboe the output, 0->disable the output
#define CM1OD()				CM1CONbits.COE = 0	//1->enaboe the output, 0->disable the output

//initialize comparator
void CM2Init(void);
#define CM2OUT()			(CM2CONbits.COUT)	//comparator output status
#define CM2INA()			CM2CONbits.CREF= 0	//non-inverting input. 0->CxINA, 1->CVref
#define CM2CVref()			CM2CONbits.CREF= 1	//non-inverting input. 0->CxINA, 1->CVref
#define CM2INB()			CM2CONbits.CCH = 0	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM2INC()			CM2CONbits.CCH = 1	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM2IND()			CM2CONbits.CCH = 2	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM2INIref()			CM2CONbits.CCH = 3	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM2OE()				CM2CONbits.COE = 1	//1->enaboe the output, 0->disable the output
#define CM2OD()				CM2CONbits.COE = 0	//1->enaboe the output, 0->disable the output

//initialize comparator
void CM3Init(void);
#define CM3OUT()			(CM3CONbits.COUT)	//comparator output status
#define CM3INA()			CM3CONbits.CREF= 0	//non-inverting input. 0->CxINA, 1->CVref
#define CM3CVref()			CM3CONbits.CREF= 1	//non-inverting input. 0->CxINA, 1->CVref
#define CM3INB()			CM3CONbits.CCH = 0	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM3INC()			CM3CONbits.CCH = 1	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM3IND()			CM3CONbits.CCH = 2	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM3INIref()			CM3CONbits.CCH = 3	//inverting input. 0->CxINB, 1->CxINC, 2->CxIND, 3->CxIref
#define CM3OE()				CM3CONbits.COE = 1	//1->enaboe the output, 0->disable the output
#define CM3OD()				CM3CONbits.COE = 0	//1->enaboe the output, 0->disable the output

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

//ref con
//ref con input source
#define REFSEL_CPU		0				//sysclk
#define REFSEL_PHB		1				//pheriphal clock
#define REFSEL_OSC		2				//primary oscillator
#define REFSEL_FRC		3				//frc
#define REFSEL_LPRC		4				//lprc
#define REFSEL_SOSC		5				//secondary oscillator
#define REFSEL_USBPLL	6				//usb pll output
#define REFSEL_PLL		7				//system pll output
#define REFSEL_REFCLKI	8				//refclki pin input

//ref frequency output
//Ref output = F_refsel / 2 / (N + M / 512)
//N: 15 bits (0..32767)
//M: 9 bits (0..511)
void refinit(uint32_t refsel, uint32_t N, uint32_t M);
void refOutput(char enable);			//1->enable the output, 0->disable the output

#endif
