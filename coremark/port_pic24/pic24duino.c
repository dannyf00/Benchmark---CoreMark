#include "pic24duino.h"						//pic24duino

//mcus supported
//PIC24GA00x: PIC24FJxxGA002, PIC24FJxxGA004
//PIC24GB00x: PIC24FJxxGB002, PIC24FJxxGB004
//PIC24GA10x: PIC24FJxxGA102, PIC24FJxxGA104
//PIC24GA11x: PIC24FJxxGA106, PIC24FJxxGA108, PIC24FJGAxx110
//PIC24GB11x: PIC24FJxxGB106, PIC24FJxxGB108, PIC24FJGBxx110



//************XC********************
//config words settings
#if defined(__XC16__)					//for XC16
//PIC24FJxxGA104 family
#if defined(__PIC24GA10x__)
/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | */
/*		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) */

//config fues settings for 24fj64ga102
///config fues settings
//CONFIG1
#pragma config JTAGEN = OFF
#pragma config GCP = OFF
#pragma config GWRP = OFF
#pragma config ICS = PGx2
#pragma config FWDTEN = OFF
#pragma config WINDIS = OFF
#pragma config FWPSA = PR128
#pragma config WDTPS = PS32768

//CONFIG2
#pragma config IESO = OFF
#pragma config FNOSC = FRC		//FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
#pragma config FCKSM = CSECMD
#pragma config OSCIOFNC = OFF
#pragma config IOL1WAY = OFF
#pragma config POSCMOD = HS		//EC, XT, HS, NONE
#pragma config I2C1SEL = PRI

//CONFIG3
#pragma config WPFP = WPFP0
#pragma config SOSCSEL = SOSC		//IO, LPSOSC, SOSC
#pragma config WUTSEL = LEG
#pragma config WPDIS = WPDIS
#pragma config WPCFG = WPCFGDIS
#pragma config WPEND = WPENDMEM

//CONFIG4
#pragma config DSWDTPS = DSWDTPSF
#pragma config DSWDTOSC = LPRC
#pragma config RTCOSC = SOSC			//LPRC, SOSC
#pragma config DSBOREN = OFF
#pragma config DSWDTEN = OFF


/*
 DSWDT Postscale Select
DSWDTPS = DSWDTPS0	 1 : 2 (2.1 ms)
DSWDTPS = DSWDTPS1	 1 : 8 (8.3 ms)
DSWDTPS = DSWDTPS2	 1 : 32 (33 ms)
DSWDTPS = DSWDTPS3	 1 : 128 (132 ms)
DSWDTPS = DSWDTPS4	 1 : 512 (528 ms)
DSWDTPS = DSWDTPS5	 1 : 2,048 (2.1 seconds)
DSWDTPS = DSWDTPS6	 1 : 8,192 (8.5 seconds)
DSWDTPS = DSWDTPS7	 1 : 32,768 (34 seconds)
DSWDTPS = DSWDTPS8	 1 : 131,072 (135 seconds)
DSWDTPS = DSWDTPS9	 1 : 524,288 (9 minutes)
DSWDTPS = DSWDTPSA	 1 : 2,097,152 (36 minutes)
DSWDTPS = DSWDTPSB	 1 : 8,388,608 (2.4 hours)
DSWDTPS = DSWDTPSC	 1 : 33,554,432 (9.6 hours)
DSWDTPS = DSWDTPSD	 1 : 134,217,728 (38.5 hours)
DSWDTPS = DSWDTPSE	 1 : 536,870,912 (6.4 days)
DSWDTPS = DSWDTPSF	 1 : 2,147,483,648 (25.7 days)

Deep Sleep Watchdog Timer Oscillator Select
DSWDTOSC = SOSC	 DSWDT uses Secondary Oscillator (SOSC)
DSWDTOSC = LPRC	 DSWDT uses Low Power RC Oscillator (LPRC)

RTCC Reference Oscillator Select
RTCOSC = LPRC	 RTCC uses Low Power RC Oscillator (LPRC)
RTCOSC = SOSC	 RTCC uses Secondary Oscillator (SOSC)

Deep Sleep BOR Enable bit
DSBOREN = OFF	 BOR disabled in Deep Sleep
DSBOREN = ON	 BOR enabled in Deep Sleep

Deep Sleep Watchdog Timer
DSWDTEN = OFF	 DSWDT disabled
DSWDTEN = ON	 DSWDT enabled

Write Protection Flash Page Segment Boundary
WPFP = WPFP0	 Page 0 (0x0)
WPFP = WPFP1	 Page 1 (0x400)
WPFP = WPFP2	 Page 2 (0x800)
WPFP = WPFP3	 Page 3 (0xC00)
WPFP = WPFP4	 Page 4 (0x1000)
WPFP = WPFP5	 Page 5 (0x1400)
WPFP = WPFP6	 Page 6 (0x1800)
WPFP = WPFP7	 Page 7 (0x1C00)
WPFP = WPFP8	 Page 8 (0x2000)
WPFP = WPFP9	 Page 9 (0x2400)
WPFP = WPFP10	 Page 10 (0x2800)
WPFP = WPFP11	 Page 11 (0x2C00)
WPFP = WPFP12	 Page 12 (0x3000)
WPFP = WPFP13	 Page 13 (0x3400)
WPFP = WPFP14	 Page 14 (0x3800)
WPFP = WPFP15	 Page 15 (0x3C00)
WPFP = WPFP16	 Page 16 (0x4000)
WPFP = WPFP17	 Page 17 (0x4400)
WPFP = WPFP18	 Page 18 (0x4800)
WPFP = WPFP19	 Page 19 (0x4C00)
WPFP = WPFP20	 Page 20 (0x5000)
WPFP = WPFP21	 Page 21 (0x5400)
WPFP = WPFP22	 Page 22 (0x5800)
WPFP = WPFP23	 Page 23 (0x5C00)
WPFP = WPFP24	 Page 24 (0x6000)
WPFP = WPFP25	 Page 25 (0x6400)
WPFP = WPFP26	 Page 26 (0x6800)
WPFP = WPFP27	 Page 27 (0x6C00)
WPFP = WPFP28	 Page 28 (0x7000)
WPFP = WPFP29	 Page 29 (0x7400)
WPFP = WPFP30	 Page 30 (0x7800)
WPFP = WPFP31	 Page 31 (0x7C00)
WPFP = WPFP32	 Page 32 (0x8000)
WPFP = WPFP33	 Page 33 (0x8400)
WPFP = WPFP34	 Page 34 (0x8800)
WPFP = WPFP35	 Page 35 (0x8C00)
WPFP = WPFP36	 Page 36 (0x9000)
WPFP = WPFP37	 Page 37 (0x9400)
WPFP = WPFP38	 Page 38 (0x9800)
WPFP = WPFP39	 Page 39 (0x9C00)
WPFP = WPFP40	 Page 40 (0xA000)
WPFP = WPFP41	 Page 41 (0xA400)
WPFP = WPFP42	 Page 42 (0xA800)
WPFP = WPFP63	 Highest Page (same as page 42)

 * Secondary Oscillator Pin Mode Select
SOSCSEL = IO	 SOSC pins have digital I/O functions (RA4, RB4)
SOSCSEL = LPSOSC	 SOSC pins in Low-Power (low drive-strength) Oscillator Mode
SOSCSEL = SOSC	 SOSC pins in Default (high drive-strength) Oscillator Mode

Voltage Regulator Wake-up Time Select
WUTSEL = FST	 Fast regulator start-up time used
WUTSEL = LEG	 Default regulator start-up time used

Segment Write Protection Disable
WPDIS = WPEN	 Segmented code protection enabled
WPDIS = WPDIS	 Segmented code protection disabled

Write Protect Configuration Page Select
WPCFG = WPCFGEN	 Last page and Flash Configuration words are code-protected
WPCFG = WPCFGDIS	 Last page and Flash Configuration words are unprotected

Segment Write Protection End Page Select
WPEND = WPSTARTMEM	 Write Protect from page 0 to WPFP
WPEND = WPENDMEM	 Write Protect from WPFP to the last page of memory

Primary Oscillator Select
POSCMOD = EC	 EC Oscillator mode selected
POSCMOD = XT	 XT Oscillator mode selected
POSCMOD = HS	 HS Oscillator mode selected
POSCMOD = NONE	 Primary Oscillator disabled

I2C1 Pin Select bit
I2C1SEL = SEC	 Use alternate SCL1/SDA1 pins for I2C1
I2C1SEL = PRI	 Use default SCL1/SDA1 pins for I2C1

IOLOCK One-Way Set Enable
IOL1WAY = OFF	 The IOLOCK bit can be set and cleared using the unlock sequence
IOL1WAY = ON	 Once set, the IOLOCK bit cannot be cleared

 * OSCO Pin Configuration
OSCIOFNC = ON	 OSCO pin functions as port I/O (RA3)
OSCIOFNC = OFF	 OSCO pin functions as clock output (CLKO)

Clock Switching and Fail-Safe Clock Monitor
FCKSM = CSECME	 Sw Enabled, Mon Enabled
FCKSM = CSECMD	 Sw Enabled, Mon Disabled
FCKSM = CSDCMD	 Sw Disabled, Mon Disabled

Initial Oscillator Select
FNOSC = FRC	 Fast RC Oscillator (FRC)
FNOSC = FRCPLL	 Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
FNOSC = PRI	 Primary Oscillator (XT, HS, EC)
FNOSC = PRIPLL	 Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
FNOSC = SOSC	 Secondary Oscillator (SOSC)
FNOSC = LPRC	 Low-Power RC Oscillator (LPRC)
FNOSC = FRCDIV	 Fast RC Oscillator with Postscaler (FRCDIV)

Internal External Switchover
IESO = OFF	 IESO mode (Two-Speed Start-up) disabled
IESO = ON	 IESO mode (Two-Speed Start-up) enabled

Watchdog Timer Postscaler
WDTPS = PS1	 1 : 1
WDTPS = PS2	 1 : 2
WDTPS = PS4	 1 : 4
WDTPS = PS8	 1 : 8
WDTPS = PS16	 1 : 16
WDTPS = PS32	 1 : 32
WDTPS = PS64	 1 : 64
WDTPS = PS128	 1 : 128
WDTPS = PS256	 1 : 256
WDTPS = PS512	 1 : 512
WDTPS = PS1024	 1 : 1,024
WDTPS = PS2048	 1 : 2,048
WDTPS = PS4096	 1 : 4,096
WDTPS = PS8192	 1 : 8,192
WDTPS = PS16384	 1 : 16,384
WDTPS = PS32768	 1 : 32,768

WDT Prescaler
FWPSA = PR32	 Prescaler ratio of 1 : 32
FWPSA = PR128	 Prescaler ratio of 1 : 128

Windowed WDT
WINDIS = ON	 Windowed Watchdog Timer enabled; FWDTEN must be 1
WINDIS = OFF	 Standard Watchdog Timer enabled,(Windowed-mode is disabled)

Watchdog Timer
FWDTEN = OFF	 Watchdog Timer is disabled
FWDTEN = ON	 Watchdog Timer is enabled

Emulator Pin Placement Select bits
ICS = PGx3	 Emulator functions are shared with PGEC3/PGED3
ICS = PGx2	 Emulator functions are shared with PGEC2/PGED2
ICS = PGx1	 Emulator functions are shared with PGEC1/PGED1

General Segment Write Protect
GWRP = ON	 Writes to program memory are disabled
GWRP = OFF	 Writes to program memory are allowed

General Segment Code Protect
GCP = ON	 Code protection is enabled for the entire program memory space
GCP = OFF	 Code protection is disabled

JTAG Port Enable
JTAGEN = OFF	 JTAG port is disabled
JTAGEN = ON	 JTAG port is enabled
 */
#endif

//pic24fj64ga004 family
#if defined(__PIC24GA00x__)
/*#elif 	defined(__PIC24FJ64GA002__) | defined (__PIC24FJ64GA004__) | \*/
/*		defined(__PIC24FJ48GA002__) | defined (__PIC24FJ48GA004__) | \*/
/*		defined(__PIC24FJ32GA002__) | defined (__PIC24FJ32GA004__) | \*/
/*		defined(__PIC24FJ16GA002__) | defined (__PIC24FJ16GA004__)*/

/*config fues settings for everything else - need customization*/
//CONFIG1
#pragma config JTAGEN = OFF
#pragma config GCP = OFF
#pragma config GWRP = OFF
#pragma config BKBUG = OFF
#pragma config COE = OFF
#pragma config ICS = PGx2
#pragma config FWDTEN = OFF
#pragma config WINDIS = OFF
#pragma config FWPSA = PR128
#pragma config WDTPS = PS32768

//CONFIG2
#pragma config IESO = OFF
#pragma config SOSCSEL = SOSC			//IO, LPSOSC, SOSC
#pragma config WUTSEL = LEG
#pragma config FCKSM = CSDCMD
#pragma config OSCIOFNC = OFF
#pragma config IOL1WAY = OFF
#pragma config I2C1SEL = PRI
#pragma config POSCMOD = NONE				//EC/XT/HS/NONE
#pragma config FNOSC = FRC				//FRC/FRCPLL/FRCDIV/PRI/PRIPLL/SOSC/LPRC

/*
 Primary Oscillator Select
POSCMOD = EC	 EC Oscillator mode selected
POSCMOD = XT	 XT Oscillator mode selected
POSCMOD = HS	 HS Oscillator mode selected
POSCMOD = NONE	 Primary oscillator disabled

I2C1 Pin Location Select
I2C1SEL = SEC	 Use alternate SCL1/SDA1 pins
I2C1SEL = PRI	 Use default SCL1/SDA1 pins

IOLOCK Protection
IOL1WAY = OFF	 IOLOCK may be changed via unlocking seq
IOL1WAY = ON	 Once IOLOCK is set, cannot be changed

Primary Oscillator Output Function
OSCIOFNC = ON	 OSC2/CLKO/RC15 functions as port I/O (RC15)
OSCIOFNC = OFF	 OSC2/CLKO/RC15 functions as CLKO (FOSC/2)

Clock Switching and Monitor
FCKSM = CSECME	 Clock switching is enabled, Fail-Safe Clock Monitor is enabled
FCKSM = CSECMD	 Clock switching is enabled, Fail-Safe Clock Monitor is disabled
FCKSM = CSDCMD	 Clock switching and Fail-Safe Clock Monitor are disabled

Oscillator Select
FNOSC = FRC	 Fast RC Oscillator (FRC)
FNOSC = FRCPLL	 Fast RC Oscillator with PLL module (FRCPLL)
FNOSC = PRI	 Primary Oscillator (XT, HS, EC)
FNOSC = PRIPLL	 Primary Oscillator with PLL module (HSPLL, ECPLL)
FNOSC = SOSC	 Secondary Oscillator (SOSC)
FNOSC = LPRC	 Low-Power RC Oscillator (LPRC)
FNOSC = FRCDIV	 Fast RC Oscillator with Postscaler (FRCDIV)

Sec Oscillator Select
SOSCSEL = LPSOSC	 Low Power Secondary Oscillator (LPSOSC)
SOSCSEL = SOSC	 Default Secondary Oscillator (SOSC)

Wake-up timer Select
WUTSEL = FST	 Fast Wake-up Timer
WUTSEL = LEG	 Legacy Wake-up Timer

Internal External Switch Over Mode
IESO = OFF	 IESO mode (Two-Speed Start-up) disabled
IESO = ON	 IESO mode (Two-Speed Start-up) enabled

Watchdog Timer Postscaler
WDTPS = PS1	 1 : 1
WDTPS = PS2	 1 : 2
WDTPS = PS4	 1 : 4
WDTPS = PS8	 1 : 8
WDTPS = PS16	 1 : 16
WDTPS = PS32	 1 : 32
WDTPS = PS64	 1 : 64
WDTPS = PS128	 1 : 128
WDTPS = PS256	 1 : 256
WDTPS = PS512	 1 : 512
WDTPS = PS1024	 1 : 1,024
WDTPS = PS2048	 1 : 2,048
WDTPS = PS4096	 1 : 4,096
WDTPS = PS8192	 1 : 8,192
WDTPS = PS16384	 1 : 16,384
WDTPS = PS32768	 1 : 32,768

WDT Prescaler
FWPSA = PR32	 Prescaler ratio of 1 : 32
FWPSA = PR128	 Prescaler ratio of 1 : 128

Watchdog Timer Window
WINDIS = OFF	 Windowed Watchdog Timer enabled; FWDTEN must be 1
WINDIS = ON	 Standard Watchdog Timer enabled,(Windowed-mode is disabled)

Watchdog Timer Enable
FWDTEN = OFF	 Watchdog Timer is disabled
FWDTEN = ON	 Watchdog Timer is enabled

Comm Channel Select
ICS = PGx3	 Emulator EMUC3/EMUD3 pins are shared with PGC3/PGD3
ICS = PGx2	 Emulator EMUC2/EMUD2 pins are shared with PGC2/PGD2
ICS = PGx1	 Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1

Set Clip On Emulation Mode
COE = ON	 Reset Into Clip On Emulation Mode
COE = OFF	 Reset Into Operational Mode

Background Debug
BKBUG = ON	 Device resets into Debug mode
BKBUG = OFF	 Device resets into Operational mode

General Code Segment Write Protect
GWRP = ON	 Writes to program memory are disabled
GWRP = OFF	 Writes to program memory are allowed

General Code Segment Code Protect
GCP = ON	 Code protection is enabled for the entire program memory space
GCP = OFF	 Code protection is disabled

JTAG Port Enable
JTAGEN = OFF	 JTAG port is disabled
JTAGEN = ON	 JTAG port is enabled
 */
#endif

//pic24fjgb004 family
#if defined(__PIC24GB00x__)
/*#elif 	defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \*/
/*		defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \*/
/*		defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/

//CONFIG1
#pragma config JTAGEN = OFF
#pragma config GCP = OFF
#pragma config GWRP = OFF
#pragma config ICS = PGx2
#pragma config FWDTEN = OFF
#pragma config WINDIS = OFF
#pragma config FWPSA = PR128
#pragma config WDTPS = PS32768

//CONFIG2
#pragma config IESO = OFF
#pragma config PLLDIV = DIV12
#pragma config PLL96MHZ = ON
#pragma config FNOSC = PRI					//FRC, FRCPLL, PRI, PRIPLL, SOSC, LSOC
#pragma config FCKSM = CSDCMD
#pragma config OSCIOFNC = OFF
#pragma config IOL1WAY = OFF
#pragma config POSCMOD = HS					//EC, HS, XT, NONE
#pragma config I2C1SEL = PRI

//CONFIG3
#pragma config WPFP = WPFP0
#pragma config SOSCSEL = IO					//IO, LPSOSC, SOSC
#pragma config WUTSEL = LEG
#pragma config WPDIS = WPDIS
#pragma config WPCFG = WPCFGDIS
#pragma config WPEND = WPENDMEM

//CONFIG4
#pragma config DSWDTPS = DSWDTPSF
#pragma config DSWDTOSC = LPRC
#pragma config RTCOSC = SOSC				//LPRC, SOSC
#pragma config DSBOREN = OFF
#pragma config DSWDTEN = OFF




/*DSWDT Postscale Select
DSWDTPS = DSWDTPS0	 1 : 2 (2.1 ms)
DSWDTPS = DSWDTPS1	 1 : 8 (8.3 ms)
DSWDTPS = DSWDTPS2	 1 : 32 (33 ms)
DSWDTPS = DSWDTPS3	 1 : 128 (132 ms)
DSWDTPS = DSWDTPS4	 1 : 512 (528 ms)
DSWDTPS = DSWDTPS5	 1 : 2,048 (2.1 seconds)
DSWDTPS = DSWDTPS6	 1 : 8,192 (8.5 seconds)
DSWDTPS = DSWDTPS7	 1 : 32,768 (34 seconds)
DSWDTPS = DSWDTPS8	 1 : 131,072 (135 seconds)
DSWDTPS = DSWDTPS9	 1 : 524,288 (9 minutes)
DSWDTPS = DSWDTPSA	 1 : 2,097,152 (36 minutes)
DSWDTPS = DSWDTPSB	 1 : 8,388,608 (2.4 hours)
DSWDTPS = DSWDTPSC	 1 : 33,554,432 (9.6 hours)
DSWDTPS = DSWDTPSD	 1 : 134,217,728 (38.5 hours)
DSWDTPS = DSWDTPSE	 1 : 536,870,912 (6.4 days)
DSWDTPS = DSWDTPSF	 1 : 2,147,483,648 (25.7 days)

Deep Sleep Watchdog Timer Oscillator Select
DSWDTOSC = SOSC	 DSWDT uses Secondary Oscillator (SOSC)
DSWDTOSC = LPRC	 DSWDT uses Low Power RC Oscillator (LPRC)

RTCC Reference Oscillator Select
RTCOSC = LPRC	 RTCC uses Low Power RC Oscillator (LPRC)
RTCOSC = SOSC	 RTCC uses Secondary Oscillator (SOSC)

Deep Sleep BOR Enable bit
DSBOREN = OFF	 BOR disabled in Deep Sleep
DSBOREN = ON	 BOR enabled in Deep Sleep

Deep Sleep Watchdog Timer
DSWDTEN = OFF	 DSWDT disabled
DSWDTEN = ON	 DSWDT enabled

Write Protection Flash Page Segment Boundary
WPFP = WPFP0	 Page 0 (0x0)
WPFP = WPFP1	 Page 1 (0x400)
WPFP = WPFP2	 Page 2 (0x800)
WPFP = WPFP3	 Page 3 (0xC00)
WPFP = WPFP4	 Page 4 (0x1000)
WPFP = WPFP5	 Page 5 (0x1400)
WPFP = WPFP6	 Page 6 (0x1800)
WPFP = WPFP7	 Page 7 (0x1C00)
WPFP = WPFP8	 Page 8 (0x2000)
WPFP = WPFP9	 Page 9 (0x2400)
WPFP = WPFP10	 Page 10 (0x2800)
WPFP = WPFP11	 Page 11 (0x2C00)
WPFP = WPFP12	 Page 12 (0x3000)
WPFP = WPFP13	 Page 13 (0x3400)
WPFP = WPFP14	 Page 14 (0x3800)
WPFP = WPFP15	 Page 15 (0x3C00)
WPFP = WPFP16	 Page 16 (0x4000)
WPFP = WPFP17	 Page 17 (0x4400)
WPFP = WPFP18	 Page 18 (0x4800)
WPFP = WPFP19	 Page 19 (0x4C00)
WPFP = WPFP20	 Page 20 (0x5000)
WPFP = WPFP21	 Page 21 (0x5400)
WPFP = WPFP22	 Page 22 (0x5800)
WPFP = WPFP23	 Page 23 (0x5C00)
WPFP = WPFP24	 Page 24 (0x6000)
WPFP = WPFP25	 Page 25 (0x6400)
WPFP = WPFP26	 Page 26 (0x6800)
WPFP = WPFP27	 Page 27 (0x6C00)
WPFP = WPFP28	 Page 28 (0x7000)
WPFP = WPFP29	 Page 29 (0x7400)
WPFP = WPFP30	 Page 30 (0x7800)
WPFP = WPFP31	 Page 31 (0x7C00)
WPFP = WPFP32	 Page 32 (0x8000)
WPFP = WPFP33	 Page 33 (0x8400)
WPFP = WPFP34	 Page 34 (0x8800)
WPFP = WPFP35	 Page 35 (0x8C00)
WPFP = WPFP36	 Page 36 (0x9000)
WPFP = WPFP37	 Page 37 (0x9400)
WPFP = WPFP38	 Page 38 (0x9800)
WPFP = WPFP39	 Page 39 (0x9C00)
WPFP = WPFP40	 Page 40 (0xA000)
WPFP = WPFP41	 Page 41 (0xA400)
WPFP = WPFP42	 Page 42 (0xA800)
WPFP = WPFP63	 Highest Page (same as page 42)

Secondary Oscillator Pin Mode Select
SOSCSEL = IO	 SOSC pins have digital I/O functions (RA4, RB4)
SOSCSEL = LPSOSC	 SOSC pins in Low-Power (low drive-strength) Oscillator Mode
SOSCSEL = SOSC	 SOSC pins in Default (high drive-strength) Oscillator Mode

Voltage Regulator Wake-up Time Select
WUTSEL = FST	 Fast regulator start-up time used
WUTSEL = LEG	 Default regulator start-up time used

Segment Write Protection Disable
WPDIS = WPEN	 Segmented code protection enabled
WPDIS = WPDIS	 Segmented code protection disabled

Write Protect Configuration Page Select
WPCFG = WPCFGEN	 Last page and Flash Configuration words are code-protected
WPCFG = WPCFGDIS	 Last page and Flash Configuration words are unprotected

Segment Write Protection End Page Select
WPEND = WPSTARTMEM	 Write Protect from page 0 to WPFP
WPEND = WPENDMEM	 Write Protect from WPFP to the last page of memory

Primary Oscillator Select
POSCMOD = EC	 EC Oscillator mode selected
POSCMOD = XT	 XT Oscillator mode selected
POSCMOD = HS	 HS Oscillator mode selected
POSCMOD = NONE	 Primary Oscillator disabled

I2C1 Pin Select bit
I2C1SEL = SEC	 Use alternate SCL1/SDA1 pins for I2C1
I2C1SEL = PRI	 Use default SCL1/SDA1 pins for I2C1

IOLOCK One-Way Set Enable
IOL1WAY = OFF	 The IOLOCK bit can be set and cleared using the unlock sequence
IOL1WAY = ON	 Once set, the IOLOCK bit cannot be cleared

OSCO Pin Configuration
OSCIOFNC = ON	 OSCO pin functions as port I/O (RA3)
OSCIOFNC = OFF	 OSCO pin functions as clock output (CLKO)

Clock Switching and Fail-Safe Clock Monitor
FCKSM = CSECME	 Sw Enabled, Mon Enabled
FCKSM = CSECMD	 Sw Enabled, Mon Disabled
FCKSM = CSDCMD	 Sw Disabled, Mon Disabled

Initial Oscillator Select
FNOSC = FRC	 Fast RC Oscillator (FRC)
FNOSC = FRCPLL	 Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
FNOSC = PRI	 Primary Oscillator (XT, HS, EC)
FNOSC = PRIPLL	 Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
FNOSC = SOSC	 Secondary Oscillator (SOSC)
FNOSC = LPRC	 Low-Power RC Oscillator (LPRC)
FNOSC = FRCDIV	 Fast RC Oscillator with Postscaler (FRCDIV)

96MHz PLL Startup Select
PLL96MHZ = OFF	 96 MHz PLL Startup is enabled by user in software( controlled with the PLLEN bit)
PLL96MHZ = ON	 96 MHz PLL Startup is enabled automatically on start-up

USB 96 MHz PLL Prescaler Select
PLLDIV = NODIV	 Oscillator input used directly (4 MHz input)
PLLDIV = DIV2	 Oscillator input divided by 2 (8 MHz input)
PLLDIV = DIV3	 Oscillator input divided by 3 (12 MHz input)
PLLDIV = DIV4	 Oscillator input divided by 4 (16 MHz input)
PLLDIV = DIV5	 Oscillator input divided by 5 (20 MHz input)
PLLDIV = DIV6	 Oscillator input divided by 6 (24 MHz input)
PLLDIV = DIV8	 Oscillator input divided by 8 (32 MHz input)
PLLDIV = DIV12	 Oscillator input divided by 12 (48 MHz input)

Internal External Switchover
IESO = OFF	 IESO mode (Two-Speed Start-up) disabled
IESO = ON	 IESO mode (Two-Speed Start-up) enabled

Watchdog Timer Postscaler
WDTPS = PS1	 1 : 1
WDTPS = PS2	 1 : 2
WDTPS = PS4	 1 : 4
WDTPS = PS8	 1 : 8
WDTPS = PS16	 1 : 16
WDTPS = PS32	 1 : 32
WDTPS = PS64	 1 : 64
WDTPS = PS128	 1 : 128
WDTPS = PS256	 1 : 256
WDTPS = PS512	 1 : 512
WDTPS = PS1024	 1 : 1,024
WDTPS = PS2048	 1 : 2,048
WDTPS = PS4096	 1 : 4,096
WDTPS = PS8192	 1 : 8,192
WDTPS = PS16384	 1 : 16,384
WDTPS = PS32768	 1 : 32,768

WDT Prescaler
FWPSA = PR32	 Prescaler ratio of 1 : 32
FWPSA = PR128	 Prescaler ratio of 1 : 128

Windowed WDT
WINDIS = ON	 Windowed Watchdog Timer enabled; FWDTEN must be 1
WINDIS = OFF	 Standard Watchdog Timer enabled,(Windowed-mode is disabled)

Watchdog Timer
FWDTEN = OFF	 Watchdog Timer is disabled
FWDTEN = ON	 Watchdog Timer is enabled

Emulator Pin Placement Select bits
ICS = PGx3	 Emulator functions are shared with PGEC3/PGED3
ICS = PGx2	 Emulator functions are shared with PGEC2/PGED2
ICS = PGx1	 Emulator functions are shared with PGEC1/PGED1

General Segment Write Protect
GWRP = ON	 Writes to program memory are disabled
GWRP = OFF	 Writes to program memory are allowed

General Segment Code Protect
GCP = ON	 Code protection is enabled for the entire program memory space
GCP = OFF	 Code protection is disabled

JTAG Port Enable
JTAGEN = OFF	 JTAG port is disabled
JTAGEN = ON	 JTAG port is enabled
 */
#endif			//pic24gb00x

#if defined(__PIC24GA11x__)
//ga110 config bits
//config1
//_CONFIG1(
#pragma config JTAGEN =	OFF;		//Disable JTAG port
#pragma config GCP	=	OFF;		//Disable code protect
#pragma config GWRP   =	OFF;		//Disable write protect
#pragma config ICS	=	PGx1;		//EMUC/EMUD share PGC2/PGD2
#pragma config FWDTEN = OFF;		//Disable watchdog timer (WDT)
#pragma config WINDIS = OFF;		//Use standard WDT (if it is enabled)
#pragma config FWPSA  = PR128;		//Use WDT prescaler ratio of 1:128
#pragma config WDTPS  = PS32768;	//Use WDT postscaler ratio of 1:32,768
//)
//config2
//_CONFIG2(
#pragma config FNOSC  = FRC;		//Primary oscillator: FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
#pragma config POSCMOD= HS;			//External oscillator: HS, XT, EC, NONE
#pragma config IESO   = OFF;		//Disabled
#pragma config FCKSM  = CSDCMD;		//Clock switching and clock monitor disabled
#pragma config OSCIOFNC=OFF;		//OSCO or Fosc/2
#pragma config IOL1WAY= OFF;		//Unlimited Writes To RP Registers
//	I2C1SEL_PRI						//Use Primary I2C1 pins
//	SOSCSEL_SOSC &					//Default Secondary Oscillator
//	WUTSEL_LEG &					//Legacy Wake-up timer selected
//)
//config3
//_CONFIG3(
#pragma config WPFP   = WPFP0;		//Highest Page (same as page 42)
//	SOSCSEL_IO &					//SOSC pins have digital I/O functions (RA4, RB4)
//	WUTSEL_LEG &					//Default regulator start-up time used
#pragma config WPDIS  = WPDIS;		//Segmented code protection disabled
#pragma config WPCFG  = WPCFGDIS;	//Last page and Flash Configuration words are unprotected
#pragma config WPEND  = WPENDMEM;	//Write Protect from WPFP to the last page of memory
//)


/* -------------------------------------------------------- */
/* Macros for setting device configuration registers		*/
/* -------------------------------------------------------- */

/* Register CONFIG3 (0xabfa)							   */

//extern __attribute__((space(prog))) int _CONFIG3;
//#define _CONFIG3(x) __attribute__((section("__CONFIG3.sec"),space(prog))) int _CONFIG3 = (x);

/*
** Only one invocation of CONFIG3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG3.
** Multiple options may be combined, as shown:
**
** _CONFIG3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Write Protection Flash Page Segment Boundary:
**	 WPFP_WPFP0		   Page 0 (0x00)
**	 WPFP_WPFP1		   Page 1 (0x400)
**	 WPFP_WPFP2		   Page 2 (0x800)
**	 WPFP_WPFP3		   Page 3 (0xC00)
**	 WPFP_WPFP4		   Page 4 (0x1000)
**	 WPFP_WPFP5		   Page 5 (0x1400)
**	 WPFP_WPFP6		   Page 6 (0x1800)
**	 WPFP_WPFP7		   Page 7 (0x1C00)
**	 WPFP_WPFP8		   Page 8 (0x2000)
**	 WPFP_WPFP9		   Page 9 (0x2400)
**	 WPFP_WPFP10		  Page 10 (0x2800)
**	 WPFP_WPFP11		  Page 11 (0x2C00)
**	 WPFP_WPFP12		  Page 12 (0x3000)
**	 WPFP_WPFP13		  Page 13 (0x3400)
**	 WPFP_WPFP14		  Page 14 (0x3800)
**	 WPFP_WPFP15		  Page 15 (0x3C00)
**	 WPFP_WPFP16		  Page 16 (0x4000)
**	 WPFP_WPFP17		  Page 17 (0x4400)
**	 WPFP_WPFP18		  Page 18 (0x4800)
**	 WPFP_WPFP19		  Page 19 (0x4C00)
**	 WPFP_WPFP20		  Page 20 (0x5000)
**	 WPFP_WPFP21		  Page 21 (0x5400)
**	 WPFP_WPFP22		  Page 22 (0x5800)
**	 WPFP_WPFP23		  Page 23 (0x5C00)
**	 WPFP_WPFP24		  Page 24 (0x6000)
**	 WPFP_WPFP25		  Page 25 (0x6400)
**	 WPFP_WPFP26		  Page 26 (0x6800)
**	 WPFP_WPFP27		  Page 27 (0x6C00)
**	 WPFP_WPFP28		  Page 28 (0x7000)
**	 WPFP_WPFP29		  Page 29 (0x7400)
**	 WPFP_WPFP30		  Page 30 (0x7800)
**	 WPFP_WPFP31		  Page 31 (0x7C00)
**	 WPFP_WPFP32		  Page 32 (0x8000)
**	 WPFP_WPFP33		  Page 33 (0x8400)
**	 WPFP_WPFP34		  Page 34 (0x8800)
**	 WPFP_WPFP35		  Page 35 (0x8C00)
**	 WPFP_WPFP36		  Page 36 (0x9000)
**	 WPFP_WPFP37		  Page 37 (0x9400)
**	 WPFP_WPFP38		  Page 38 (0x9800)
**	 WPFP_WPFP39		  Page 39 (0x9C00)
**	 WPFP_WPFP40		  Page 40 (0xA000)
**	 WPFP_WPFP41		  Page 41 (0xA400)
**	 WPFP_WPFP42		  Page 42 (0xA800)
**	 WPFP_WPFP511		 Highest Page (same as page 42)
**
**   Segment Write Protection Disable bit:
**	 WPDIS_WPEN		   Segmented code protection enabled
**	 WPDIS_WPDIS		  Segmented code protection disabled
**
**   Configuration Word Code Page Protection Selectbit:
**	 WPCFG_WPCFGEN		Last page and Flash configuration words are code-protected
**	 WPCFG_WPCFGDIS	   Last page(at the top of program memory) and Flash configuration words are not protected
**
**   Segment Write Protection End Page Select bit:
**	 WPEND_WPSTARTMEM	 Write Protect from page 0 to WPFP
**	 WPEND_WPENDMEM	   Write Protect from WPFP to the last page of memory
**
*/

/* Register CONFIG2 (0xabfc)							   */

//extern __attribute__((space(prog))) int _CONFIG2;
//#define _CONFIG2(x) __attribute__((section("__CONFIG2.sec"),space(prog))) int _CONFIG2 = (x);

/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Select:
**	 POSCMOD_EC		   EC Oscillator mode Selected
**	 POSCMOD_XT		   XT Oscillator mode selected
**	 POSCMOD_HS		   HS Oscillator mode selected
**	 POSCMOD_NONE		 Primary Oscillator disabled
**
**   IOLOCK One-Way Set Enable bit:
**	 IOL1WAY_OFF		  Unlimited Writes To RP Registers
**	 IOL1WAY_ON		   Write RP Registers Once
**
**   Primary Oscillator Output Function:
**	 OSCIOFNC_ON		  OSCO functions as port I/O (RC15)
**	 OSCIOFNC_OFF		 OSCO functions as CLKO (FOSC/2)
**
**   Clock Switching and Monitor:
**	 FCKSM_CSECME		 Clock switching and Fail-safe Clock Monitor are enabled
**	 FCKSM_CSECMD		 Clock switching is enabled, Fail-safe Clock Monitor is disabled
**	 FCKSM_CSDCMD		 Both Clock Switching and Fail-safe Clock Monitor are disabled
**
**   Oscillator Select:
**	 FNOSC_FRC			Fast RC oscillator
**	 FNOSC_FRCPLL		 Fast RC oscillator with Postscaler and PLL module (FRCPLL)
**	 FNOSC_PRI			Primary oscillator (XT, HS, EC)
**	 FNOSC_PRIPLL		 Primary oscillator (XT, HS, EC) with PLL module (XTPLL, HSPLL, ECPLL)
**	 FNOSC_SOSC		   Secondary oscillator (SOSC)
**	 FNOSC_LPRC		   Low-Power RC oscillator (LPRC)
**	 FNOSC_FRCDIV		 Fast RC oscillator with Postscaler
**
**   Internal External Switch Over Mode:
**	 IESO_OFF			 IESO mode (Two-speed start-up)disabled
**	 IESO_ON			  IESO mode (Two-speed start-up) enabled
**
*/

/* Register CONFIG1 (0xabfe)							   */

//extern __attribute__((space(prog))) int _CONFIG1;
//#define _CONFIG1(x) __attribute__((section("__CONFIG1.sec"),space(prog))) int _CONFIG1 = (x);

/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**	 WDTPS_PS1			1:1
**	 WDTPS_PS2			1:2
**	 WDTPS_PS4			1:4
**	 WDTPS_PS8			1:8
**	 WDTPS_PS16		   1:16
**	 WDTPS_PS32		   1:32
**	 WDTPS_PS64		   1:64
**	 WDTPS_PS128		  1:128
**	 WDTPS_PS256		  1:256
**	 WDTPS_PS512		  1:512
**	 WDTPS_PS1024		 1:1,024
**	 WDTPS_PS2048		 1:2,048
**	 WDTPS_PS4096		 1:4,096
**	 WDTPS_PS8192		 1:8,192
**	 WDTPS_PS16384		1:16,384
**	 WDTPS_PS32768		1:32,768
**
**   WDT Prescaler:
**	 FWPSA_PR32		   1:32
**	 FWPSA_PR128		  1:128
**
**   Watchdog Timer Window:
**	 WINDIS_ON			Windowed watchdog timer is enabled
**	 WINDIS_OFF		   Standard Watchdog timer is enabled(Windowed mode is disabled)
**
**   Watchdog Timer Enable:
**	 FWDTEN_OFF		   Watchdog timer is disabled
**	 FWDTEN_ON			Watchdog timer is enabled
**
**   Comm Channel Select:
**	 ICS_PGx3			 EMUC/EMUD share PGC3/PGD3
**	 ICS_PGx2			 EMUC/EMUD share PGC2/PGD2
**	 ICS_PGx1			 EMUC/EMUD share PGC1/PGD1
**
**   General Code Segment Write Protect:
**	 GWRP_ON			  Writes to program memory are disabled
**	 GWRP_OFF			 Writes to program memory are allowed
**
**   General Code Segment Code Protect:
**	 GCP_ON			   Code protection is enabled
**	 GCP_OFF			  Code protection is disabled
**
**   JTAG Port Enable:
**	 JTAGEN_OFF		   JTAG port is disabled
**	 JTAGEN_ON			JTAG port is enabled
**
*/
#endif			//ga110

//gb110
#if defined(__PIC24GB11x__)
//gb110

//_CONFIG1(
#pragma config WDTPS   = PS32768;	//1:32,768
#pragma config FWPSA   = PR128;		//1:128
#pragma config WINDIS  = OFF;		//Standard Watchdog Timer is enabled
#pragma config FWDTEN  = OFF;		//Watchdog Timer is disabled
#pragma config ICS	 = PGx1;		//Emulator functions are shared with PGEC1/PGED1
#pragma config COE	 = OFF;		//Set Clip On Emulation Mode:, ON or OFF
#pragma config BKBUG   = OFF;		//Background Debug: ON or OFF
#pragma config GWRP	= OFF;		//Writes to program memory are disabled
#pragma config GCP	 = OFF;		//Code protection is disabled
#pragma config JTAGEN  = OFF;		//JTAG port is Disabled
//)

//_CONFIG2(
#pragma config FNOSC   = FRC;		//Primary oscillator: FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
#pragma config POSCMOD = HS;		//External oscillator: HS, XT, EC, NONE
#pragma config DISUVREG= OFF;		//Internal USB 3.3V Regulator Disable bit: ON or OFF
//	I2C1SEL_PRI &					//Use default SCL1/SDA1 pins for I2C1
#pragma config IOL1WAY = OFF;		//The IOLOCK bit can be set and cleared using the unlock sequence
#pragma config OSCIOFNC= OFF;		//OSCO pin functions as clock output (CLKO)
#pragma config FCKSM   = CSDCMD;	//Sw Disabled, Mon Disabled
#pragma config PLL_96MHZ=ON;		//96 MHz PLL Startup is enabled automatically on start-up
#pragma config PLLDIV  = DIV12;		//Oscillator input divided by 12 (48 MHz input)
#pragma config IESO	= OFF;						//IESO mode (Two-Speed Start-up) disabled
//)

//_CONFIG3(
#pragma config WPFP	= WPFP0;		//Highest Page (same as page 42)
//	SOSCSEL_IO &					//SOSC pins have digital I/O functions (RA4, RB4)
//	WUTSEL_LEG &					//Default regulator start-up time used
#pragma config WPDIS   = WPDIS;		//Segmented code protection disabled
#pragma config WPCFG   = WPCFGDIS;	//Last page and Flash Configuration words are unprotected
#pragma config WPEND   = WPSTARTMEM;//Write Protect from page 0 to WPFP
//)


/* -------------------------------------------------------- */
/* Macros for setting device configuration registers		*/
/* -------------------------------------------------------- */

/* Register CONFIG3 (0x2abfa)							   */

//extern __attribute__((space(prog))) int _CONFIG3;
//#define _CONFIG3(x) __attribute__((section("__CONFIG3.sec"),space(prog))) int _CONFIG3 = (x);

/*
** Only one invocation of CONFIG3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG3.
** Multiple options may be combined, as shown:
**
** _CONFIG3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Write Protection Flash Page Segment Boundary:
**	 WPFP_WPFP0		   Page 0 (0x00)
**	 WPFP_WPFP1		   Page 1 (0x400)
**	 WPFP_WPFP2		   Page 2 (0x800)
**	 WPFP_WPFP3		   Page 3 (0xC00)
**	 WPFP_WPFP4		   Page 4 (0x1000)
**	 WPFP_WPFP5		   Page 5 (0x1400)
**	 WPFP_WPFP6		   Page 6 (0x1800)
**	 WPFP_WPFP7		   Page 7 (0x1C00)
**	 WPFP_WPFP8		   Page 8 (0x2000)
**	 WPFP_WPFP9		   Page 9 (0x2400)
**	 WPFP_WPFP10		  Page 10 (0x2800)
**	 WPFP_WPFP11		  Page 11 (0x2C00)
**	 WPFP_WPFP12		  Page 12 (0x3000)
**	 WPFP_WPFP13		  Page 13 (0x3400)
**	 WPFP_WPFP14		  Page 14 (0x3800)
**	 WPFP_WPFP15		  Page 15 (0x3C00)
**	 WPFP_WPFP16		  Page 16 (0x4000)
**	 WPFP_WPFP17		  Page 17 (0x4400)
**	 WPFP_WPFP18		  Page 18 (0x4800)
**	 WPFP_WPFP19		  Page 19 (0x4C00)
**	 WPFP_WPFP20		  Page 20 (0x5000)
**	 WPFP_WPFP21		  Page 21 (0x5400)
**	 WPFP_WPFP22		  Page 22 (0x5800)
**	 WPFP_WPFP23		  Page 23 (0x5C00)
**	 WPFP_WPFP24		  Page 24 (0x6000)
**	 WPFP_WPFP25		  Page 25 (0x6400)
**	 WPFP_WPFP26		  Page 26 (0x6800)
**	 WPFP_WPFP27		  Page 27 (0x6C00)
**	 WPFP_WPFP28		  Page 28 (0x7000)
**	 WPFP_WPFP29		  Page 29 (0x7400)
**	 WPFP_WPFP30		  Page 30 (0x7800)
**	 WPFP_WPFP31		  Page 31 (0x7C00)
**	 WPFP_WPFP32		  Page 32 (0x8000)
**	 WPFP_WPFP33		  Page 33 (0x8400)
**	 WPFP_WPFP34		  Page 34 (0x8800)
**	 WPFP_WPFP35		  Page 35 (0x8C00)
**	 WPFP_WPFP36		  Page 36 (0x9000)
**	 WPFP_WPFP37		  Page 37 (0x9400)
**	 WPFP_WPFP38		  Page 38 (0x9800)
**	 WPFP_WPFP39		  Page 39 (0x9C00)
**	 WPFP_WPFP40		  Page 40 (0xA000)
**	 WPFP_WPFP41		  Page 41 (0xA400)
**	 WPFP_WPFP42		  Page 42 (0xA800)
**	 WPFP_WPFP43		  Page 43 (0xAC00)
**	 WPFP_WPFP44		  Page 44 (0xB000)
**	 WPFP_WPFP45		  Page 45 (0xB400)
**	 WPFP_WPFP46		  Page 46 (0xB800)
**	 WPFP_WPFP47		  Page 47 (0xBC00)
**	 WPFP_WPFP48		  Page 48 (0xC000)
**	 WPFP_WPFP49		  Page 49 (0xC400)
**	 WPFP_WPFP50		  Page 50 (0xC800)
**	 WPFP_WPFP51		  Page 51 (0xCC00)
**	 WPFP_WPFP52		  Page 52 (0xD000)
**	 WPFP_WPFP53		  Page 53 (0xD400)
**	 WPFP_WPFP54		  Page 54 (0xD800)
**	 WPFP_WPFP55		  Page 55 (0xDC00)
**	 WPFP_WPFP56		  Page 56 (0xE000)
**	 WPFP_WPFP57		  Page 57 (0xE400)
**	 WPFP_WPFP58		  Page 58 (0xE800)
**	 WPFP_WPFP59		  Page 59 (0xEC00)
**	 WPFP_WPFP60		  Page 60 (0xF000)
**	 WPFP_WPFP61		  Page 61 (0xF400)
**	 WPFP_WPFP62		  Page 62 (0xF800)
**	 WPFP_WPFP63		  Page 63 (0xFC00)
**	 WPFP_WPFP64		  Page 64 (0x10000)
**	 WPFP_WPFP65		  Page 65 (0x10400)
**	 WPFP_WPFP66		  Page 66 (0x10800)
**	 WPFP_WPFP67		  Page 67 (0x10C00)
**	 WPFP_WPFP68		  Page 68 (0x11000)
**	 WPFP_WPFP69		  Page 69 (0x11400)
**	 WPFP_WPFP70		  Page 70 (0x11800)
**	 WPFP_WPFP71		  Page 71 (0x11C00)
**	 WPFP_WPFP72		  Page 72 (0x12000)
**	 WPFP_WPFP73		  Page 73 (0x12400)
**	 WPFP_WPFP74		  Page 74 (0x12800)
**	 WPFP_WPFP75		  Page 75 (0x12C00)
**	 WPFP_WPFP76		  Page 76 (0x13000)
**	 WPFP_WPFP77		  Page 77 (0x13400)
**	 WPFP_WPFP78		  Page 78 (0x13800)
**	 WPFP_WPFP79		  Page 79 (0x13C00)
**	 WPFP_WPFP80		  Page 80 (0x14000)
**	 WPFP_WPFP81		  Page 81 (0x14400)
**	 WPFP_WPFP82		  Page 82 (0x14800)
**	 WPFP_WPFP83		  Page 83 (0x14C00)
**	 WPFP_WPFP84		  Page 84 (0x15000)
**	 WPFP_WPFP85		  Page 85 (0x15400)
**	 WPFP_WPFP86		  Page 86 (0x15800)
**	 WPFP_WPFP87		  Page 87 (0x15C00)
**	 WPFP_WPFP88		  Page 88 (0x16000)
**	 WPFP_WPFP89		  Page 89 (0x16400)
**	 WPFP_WPFP90		  Page 90 (0x16800)
**	 WPFP_WPFP91		  Page 91 (0x16C00)
**	 WPFP_WPFP92		  Page 92 (0x17000)
**	 WPFP_WPFP93		  Page 93 (0x17400)
**	 WPFP_WPFP94		  Page 94 (0x17800)
**	 WPFP_WPFP95		  Page 95 (0x17C00)
**	 WPFP_WPFP96		  Page 96 (0x18000)
**	 WPFP_WPFP97		  Page 97 (0x18400)
**	 WPFP_WPFP98		  Page 98 (0x18800)
**	 WPFP_WPFP99		  Page 99 (0x18C00)
**	 WPFP_WPFP100		 Page 100 (0x19000)
**	 WPFP_WPFP101		 Page 101 (0x19400)
**	 WPFP_WPFP102		 Page 102 (0x19800)
**	 WPFP_WPFP103		 Page 103 (0x19C00)
**	 WPFP_WPFP104		 Page 104 (0x1A000)
**	 WPFP_WPFP105		 Page 105 (0x1A400)
**	 WPFP_WPFP106		 Page 106 (0x1A800)
**	 WPFP_WPFP107		 Page 107 (0x1AC00)
**	 WPFP_WPFP108		 Page 108 (0x1B000)
**	 WPFP_WPFP109		 Page 109 (0x1B400)
**	 WPFP_WPFP110		 Page 110 (0x1B800)
**	 WPFP_WPFP111		 Page 111 (0x1BC00)
**	 WPFP_WPFP112		 Page 112 (0x1C000)
**	 WPFP_WPFP113		 Page 113 (0x1C400)
**	 WPFP_WPFP114		 Page 114 (0x1C800)
**	 WPFP_WPFP115		 Page 115 (0x1CC00)
**	 WPFP_WPFP116		 Page 116 (0x1D000)
**	 WPFP_WPFP117		 Page 117 (0x1D400)
**	 WPFP_WPFP118		 Page 118 (0x1D800)
**	 WPFP_WPFP119		 Page 119 (0x1DC00)
**	 WPFP_WPFP120		 Page 120 (0x1E000)
**	 WPFP_WPFP121		 Page 121 (0x1E400)
**	 WPFP_WPFP122		 Page 122 (0x1E800)
**	 WPFP_WPFP123		 Page 123 (0x1EC00)
**	 WPFP_WPFP124		 Page 124 (0x1F000)
**	 WPFP_WPFP125		 Page 125 (0x1F400)
**	 WPFP_WPFP126		 Page 126 (0x1F800)
**	 WPFP_WPFP127		 Page 127 (0x1FC00)
**	 WPFP_WPFP128		 Page 128 (0x20000)
**	 WPFP_WPFP129		 Page 129 (0x20400)
**	 WPFP_WPFP130		 Page 130 (0x20800)
**	 WPFP_WPFP131		 Page 131 (0x20C00)
**	 WPFP_WPFP132		 Page 132 (0x21000)
**	 WPFP_WPFP133		 Page 133 (0x21400)
**	 WPFP_WPFP134		 Page 134 (0x21800)
**	 WPFP_WPFP135		 Page 135 (0x21C00)
**	 WPFP_WPFP136		 Page 136 (0x22000)
**	 WPFP_WPFP137		 Page 137 (0x22400)
**	 WPFP_WPFP138		 Page 138 (0x22800)
**	 WPFP_WPFP139		 Page 139 (0x22C00)
**	 WPFP_WPFP140		 Page 140 (0x23000)
**	 WPFP_WPFP141		 Page 141 (0x23400)
**	 WPFP_WPFP142		 Page 142 (0x23800)
**	 WPFP_WPFP143		 Page 143 (0x23C00)
**	 WPFP_WPFP144		 Page 144 (0x24000)
**	 WPFP_WPFP145		 Page 145 (0x24400)
**	 WPFP_WPFP146		 Page 146 (0x24800)
**	 WPFP_WPFP147		 Page 147 (0x24C00)
**	 WPFP_WPFP148		 Page 148 (0x25000)
**	 WPFP_WPFP149		 Page 149 (0x25400)
**	 WPFP_WPFP150		 Page 150 (0x25800)
**	 WPFP_WPFP151		 Page 151 (0x25C00)
**	 WPFP_WPFP152		 Page 152 (0x26000)
**	 WPFP_WPFP153		 Page 153 (0x26400)
**	 WPFP_WPFP154		 Page 154 (0x26800)
**	 WPFP_WPFP155		 Page 155 (0x26C00)
**	 WPFP_WPFP156		 Page 156 (0x27000)
**	 WPFP_WPFP157		 Page 157 (0x27400)
**	 WPFP_WPFP158		 Page 158 (0x27800)
**	 WPFP_WPFP159		 Page 159 (0x27C00)
**	 WPFP_WPFP160		 Page 160 (0x28000)
**	 WPFP_WPFP161		 Page 161 (0x28400)
**	 WPFP_WPFP162		 Page 162 (0x28800)
**	 WPFP_WPFP163		 Page 163 (0x28C00)
**	 WPFP_WPFP164		 Page 164 (0x29000)
**	 WPFP_WPFP165		 Page 165 (0x29400)
**	 WPFP_WPFP166		 Page 166 (0x29800)
**	 WPFP_WPFP167		 Page 167 (0x29C00)
**	 WPFP_WPFP168		 Page 168 (0x2A000)
**	 WPFP_WPFP169		 Page 169 (0x2A400)
**	 WPFP_WPFP170		 Page 170 (0x2A800)
**	 WPFP_WPFP511		 Highest Page (same as page 170)
**
**   Segment Write Protection Disable bit:
**	 WPDIS_WPEN		   Segmented code protection enabled
**	 WPDIS_WPDIS		  Segmented code protection disabled
**
**   Configuration Word Code Page Protection Select bit:
**	 WPCFG_WPCFGEN		Last page and Flash configuration words are code-protected
**	 WPCFG_WPCFGDIS	   Last page(at the top of program memory) and Flash configuration words are not protected
**
**   Segment Write Protection End Page Select bit:
**	 WPEND_WPSTARTMEM	 Write Protect from page 0 to WPFP
**	 WPEND_WPENDMEM	   Write Protect from WPFP to the last page of memory
**
*/

/* Register CONFIG2 (0x2abfc)							   */

//extern __attribute__((space(prog))) int _CONFIG2;
//#define _CONFIG2(x) __attribute__((section("__CONFIG2.sec"),space(prog))) int _CONFIG2 = (x);

/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Select:
**	 POSCMOD_EC		   EC oscillator mode selected
**	 POSCMOD_XT		   XT oscillator mode selected
**	 POSCMOD_HS		   HS oscillator mode selected
**	 POSCMOD_NONE		 Primary oscillator disabled
**
**   Internal USB 3.3V Regulator Disable bit:
**	 DISUVREG_ON		  Regulator is enabled
**	 DISUVREG_OFF		 Regulator is disabled
**
**   IOLOCK One-Way Set Enable bit:
**	 IOL1WAY_OFF		  Unlimited Writes To RP Registers
**	 IOL1WAY_ON		   Write RP Registers Once
**
**   Primary Oscillator Output Function:
**	 OSCIOFNC_ON		  OSCO functions as port I/O (RC15)
**	 OSCIOFNC_OFF		 OSCO functions as CLKO (FOSC/2)
**
**   Clock Switching and Monitor:
**	 FCKSM_CSECME		 Both Clock switching and Fail-safe Clock Monitor are enabled
**	 FCKSM_CSECMD		 Clock switching is enabled, Fail-safe Clock Monitor is disabled
**	 FCKSM_CSDCMD		 Both Clock Switching and Fail-safe Clock Monitor are disabled
**
**   Oscillator Select:
**	 FNOSC_FRC			Fast RC Oscillator (FRC)
**	 FNOSC_FRCPLL		 Fast RC oscillator with Postscaler and PLL module (FRCPLL)
**	 FNOSC_PRI			Primary oscillator (XT, HS, EC)
**	 FNOSC_PRIPLL		 Primary oscillator (XT, HS, EC) with PLL module (XTPLL,HSPLL, ECPLL)
**	 FNOSC_SOSC		   Secondary oscillator (SOSC)
**	 FNOSC_LPRC		   Low-Power RC oscillator (LPRC)
**	 FNOSC_FRCDIV		 Fast RC oscillator with Postscaler (FRCDIV)
**
**   96MHz PLL Disable:
**	 PLL_96MHZ_ON		 Enabled
**
**   USB 96 MHz PLL Prescaler Select bits:
**	 PLLDIV_NODIV		 Oscillator input used directly (4MHz input)
**	 PLLDIV_DIV2		  Oscillator input divided by 2 (8MHz input)
**	 PLLDIV_DIV3		  Oscillator input divided by 3 (12MHz input)
**	 PLLDIV_DIV4		  Oscillator input divided by 4 (16MHz input)
**	 PLLDIV_DIV5		  Oscillator input divided by 5 (20MHz input)
**	 PLLDIV_DIV6		  Oscillator input divided by 6 (24MHz input)
**	 PLLDIV_DIV10		 Oscillator input divided by 10 (40MHz input)
**	 PLLDIV_DIV12		 Oscillator input divided by 12 (48MHz input)
**
**   Internal External Switch Over Mode:
**	 IESO_OFF			 IESO mode (Two-speed start-up)disabled
**	 IESO_ON			  IESO mode (Two-speed start-up) enabled
**
*/

/* Register CONFIG1 (0x2abfe)							   */

//extern __attribute__((space(prog))) int _CONFIG1;
//#define _CONFIG1(x) __attribute__((section("__CONFIG1.sec"),space(prog))) int _CONFIG1 = (x);

/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**	 WDTPS_PS1			1:1
**	 WDTPS_PS2			1:2
**	 WDTPS_PS4			1:4
**	 WDTPS_PS8			1:8
**	 WDTPS_PS16		   1:16
**	 WDTPS_PS32		   1:32
**	 WDTPS_PS64		   1:64
**	 WDTPS_PS128		  1:128
**	 WDTPS_PS256		  1:256
**	 WDTPS_PS512		  1:512
**	 WDTPS_PS1024		 1:1,024
**	 WDTPS_PS2048		 1:2,048
**	 WDTPS_PS4096		 1:4,096
**	 WDTPS_PS8192		 1:8,192
**	 WDTPS_PS16384		1:16,384
**	 WDTPS_PS32768		1:32,768
**
**   WDT Prescaler:
**	 FWPSA_PR32		   Prescaler ratio of 1:32
**	 FWPSA_PR128		  Prescaler ratio of 1:128
**
**   Watchdog Timer Window:
**	 WINDIS_ON			Windowed Watchdog Timer enabled; FWDTEN must be 1
**	 WINDIS_OFF		   Standard Watchdog Timer enabled,(Windowed-mode is disabled)
**
**   Watchdog Timer Enable:
**	 FWDTEN_OFF		   Watchdog Timer is disabled
**	 FWDTEN_ON			Watchdog Timer is enabled
**
**   Comm Channel Select:
**	 ICS_PGx3			 Emulator functions are shared with PGEC3/PGED3
**	 ICS_PGx2			 Emulator functions are shared with PGEC2/PGED2
**	 ICS_PGx1			 Emulator functions are shared with PGEC1/PGED1
**
**   Set Clip On Emulation Mode:
**	 COE_ON			   Enabled
**	 COE_OFF			  Disabled
**
**   Background Debug:
**	 BKBUG_ON			 Device resets into Debug mode
**	 BKBUG_OFF			Device resets into Operational mode
**
**   General Code Segment Write Protect:
**	 GWRP_ON			  Writes to program memory are disabled
**	 GWRP_OFF			 Writes to program memory are allowed
**
**   General Code Segment Code Protect:
**	 GCP_ON			   Code protection is enabled for the entire program memory space
**	 GCP_OFF			  Code protection is disabled
**
**   JTAG Port Enable:
**	 JTAGEN_OFF		   JTAG port is disabled
**	 JTAGEN_ON			JTAG port is enabled
**
*/
#endif


//#endif 			//xc16

//config for C30
//***********C30*******************
//#if defined(__C30__)				//for C30 compiler
#else

#if defined(__PIC24GA10x__)			//for pic24ga10x


//config fues settings for 24fj64ga102
///config fues settings
_CONFIG1(
	JTAGEN_OFF &					//Disable JTAG port
	GCP_OFF &						//Disable code protect
	GWRP_OFF &						//Disable write protect
	ICS_PGx2 &						//EMUC/EMUD share PGC2/PGD2
	FWDTEN_OFF &					//Disable watchdog timer (WDT)
	WINDIS_OFF &					//Use standard WDT (if it is enabled)
	FWPSA_PR128 &					//Use WDT prescaler ratio of 1:128
	WDTPS_PS32768					//Use WDT postscaler ratio of 1:32,768
)

_CONFIG2(
	FNOSC_FRC &						//Primary oscillator: FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
	POSCMOD_HS &					//External oscillator: HS, XT, EC, NONE
	IESO_OFF &						//Disabled
	FCKSM_CSECMD &					//Clock switching and clock monitor disabled
	OSCIOFNC_OFF &					//OSCO or Fosc/2
	IOL1WAY_OFF &					//Unlimited Writes To RP Registers
	I2C1SEL_PRI	&					//Use Primary I2C1 pins
	WUTSEL_LEG 						//Legacy Wake-up timer selected
)

_CONFIG3(
	WPFP_WPFP63 &					//Highest Page (same as page 42)
	SOSCSEL_SOSC &					//Default Secondary Oscillator or LPRC
	WUTSEL_LEG &					//Default regulator start-up time used
	WPDIS_WPDIS &					//Segmented code protection disabled
	WPCFG_WPCFGDIS &				//Last page and Flash Configuration words are unprotected
	WPEND_WPENDMEM					//Write Protect from WPFP to the last page of memory
)

_CONFIG4(
	DSWDTPS_DSWDTPSF &				//1:2,147,483,648 (25.7 days)
	DSWDTOSC_LPRC &					//DSWDT uses Low Power RC Oscillator (LPRC)
	RTCOSC_SOSC &					//RTCC uses Low Power RC Oscillator (LPRC)
	DSBOREN_OFF &					//BOR disabled in Deep Sleep
	DSWDTEN_OFF 					//DSWDT disabled
)

/* -------------------------------------------------------- */
/* Macros for setting device configuration registers		*/
/* -------------------------------------------------------- */

/* Register CONFIG4 (0xabf8)							   */

/*
** Only one invocation of CONFIG4 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG4.
** Multiple options may be combined, as shown:
**
** _CONFIG4( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   DSWDT Postscale Select:
**	 DSWDTPS_DSWDTPS0	 1:2 (2.1 ms)
**	 DSWDTPS_DSWDTPS1	 1:8 (8.3 ms)
**	 DSWDTPS_DSWDTPS2	 1:32 (33 ms)
**	 DSWDTPS_DSWDTPS3	 1:128 (132 ms)
**	 DSWDTPS_DSWDTPS4	 1:512 (528 ms)
**	 DSWDTPS_DSWDTPS5	 1:2,048 (2.1 seconds)
**	 DSWDTPS_DSWDTPS6	 1:8,192 (8.5 seconds)
**	 DSWDTPS_DSWDTPS7	 1:32,768 (34 seconds)
**	 DSWDTPS_DSWDTPS8	 1:131,072 (135 seconds)
**	 DSWDTPS_DSWDTPS9	 1:524,288 (9 minutes)
**	 DSWDTPS_DSWDTPSA	 1:2,097,152 (36 minutes)
**	 DSWDTPS_DSWDTPSB	 1:8,388,608 (2.4 hours)
**	 DSWDTPS_DSWDTPSC	 1:33,554,432 (9.6 hours)
**	 DSWDTPS_DSWDTPSD	 1:134,217,728 (38.5 hours)
**	 DSWDTPS_DSWDTPSE	 1:536,870,912 (6.4 days)
**	 DSWDTPS_DSWDTPSF	 1:2,147,483,648 (25.7 days)
**
**   Deep Sleep Watchdog Timer Oscillator Select:
**	 DSWDTOSC_SOSC		DSWDT uses Secondary Oscillator (SOSC)
**	 DSWDTOSC_LPRC		DSWDT uses Low Power RC Oscillator (LPRC)
**
**   RTCC Reference Oscillator  Select:
**	 RTCOSC_LPRC		  RTCC uses Low Power RC Oscillator (LPRC)
**	 RTCOSC_SOSC		  RTCC uses Secondary Oscillator (SOSC)
**
**   Deep Sleep BOR Enable bit:
**	 DSBOREN_OFF		  BOR disabled in Deep Sleep
**	 DSBOREN_ON		   BOR enabled in Deep Sleep
**
**   Deep Sleep Watchdog Timer:
**	 DSWDTEN_OFF		  DSWDT disabled
**	 DSWDTEN_ON		   DSWDT enabled
**
*/

/* Register CONFIG3 (0xabfa)							   */

/*
** Only one invocation of CONFIG3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG3.
** Multiple options may be combined, as shown:
**
** _CONFIG3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Write Protection Flash Page Segment Boundary:
**	 WPFP_WPFP0		   Page 0 (0x0)
**	 WPFP_WPFP1		   Page 1 (0x400)
**	 WPFP_WPFP2		   Page 2 (0x800)
**	 WPFP_WPFP3		   Page 3 (0xC00)
**	 WPFP_WPFP4		   Page 4 (0x1000)
**	 WPFP_WPFP5		   Page 5 (0x1400)
**	 WPFP_WPFP6		   Page 6 (0x1800)
**	 WPFP_WPFP7		   Page 7 (0x1C00)
**	 WPFP_WPFP8		   Page 8 (0x2000)
**	 WPFP_WPFP9		   Page 9 (0x2400)
**	 WPFP_WPFP10		  Page 10 (0x2800)
**	 WPFP_WPFP11		  Page 11 (0x2C00)
**	 WPFP_WPFP12		  Page 12 (0x3000)
**	 WPFP_WPFP13		  Page 13 (0x3400)
**	 WPFP_WPFP14		  Page 14 (0x3800)
**	 WPFP_WPFP15		  Page 15 (0x3C00)
**	 WPFP_WPFP16		  Page 16 (0x4000)
**	 WPFP_WPFP17		  Page 17 (0x4400)
**	 WPFP_WPFP18		  Page 18 (0x4800)
**	 WPFP_WPFP19		  Page 19 (0x4C00)
**	 WPFP_WPFP20		  Page 20 (0x5000)
**	 WPFP_WPFP21		  Page 21 (0x5400)
**	 WPFP_WPFP22		  Page 22 (0x5800)
**	 WPFP_WPFP23		  Page 23 (0x5C00)
**	 WPFP_WPFP24		  Page 24 (0x6000)
**	 WPFP_WPFP25		  Page 25 (0x6400)
**	 WPFP_WPFP26		  Page 26 (0x6800)
**	 WPFP_WPFP27		  Page 27 (0x6C00)
**	 WPFP_WPFP28		  Page 28 (0x7000)
**	 WPFP_WPFP29		  Page 29 (0x7400)
**	 WPFP_WPFP30		  Page 30 (0x7800)
**	 WPFP_WPFP31		  Page 31 (0x7C00)
**	 WPFP_WPFP32		  Page 32 (0x8000)
**	 WPFP_WPFP33		  Page 33 (0x8400)
**	 WPFP_WPFP34		  Page 34 (0x8800)
**	 WPFP_WPFP35		  Page 35 (0x8C00)
**	 WPFP_WPFP36		  Page 36 (0x9000)
**	 WPFP_WPFP37		  Page 37 (0x9400)
**	 WPFP_WPFP38		  Page 38 (0x9800)
**	 WPFP_WPFP39		  Page 39 (0x9C00)
**	 WPFP_WPFP40		  Page 40 (0xA000)
**	 WPFP_WPFP41		  Page 41 (0xA400)
**	 WPFP_WPFP42		  Page 42 (0xA800)
**	 WPFP_WPFP63		  Highest Page (same as page 42)
**
**   Secondary Oscillator Pin Mode Select:
**	 SOSCSEL_IO		   SOSC pins have digital I/O functions (RA4, RB4)
**	 SOSCSEL_LPSOSC	   SOSC pins in Low-Power (low drive-strength) Oscillator Mode
**	 SOSCSEL_SOSC		 SOSC pins in Default (high drive-strength) Oscillator Mode
**
**   Voltage Regulator Wake-up Time Select:
**	 WUTSEL_FST		   Fast regulator start-up time used
**	 WUTSEL_LEG		   Default regulator start-up time used
**
**   Segment Write Protection Disable:
**	 WPDIS_WPEN		   Segmented code protection enabled
**	 WPDIS_WPDIS		  Segmented code protection disabled
**
**   Write Protect Configuration Page Select:
**	 WPCFG_WPCFGEN		Last page and Flash Configuration words are code-protected
**	 WPCFG_WPCFGDIS	   Last page and Flash Configuration words are unprotected
**
**   Segment Write Protection End Page Select:
**	 WPEND_WPSTARTMEM	 Write Protect from page 0 to WPFP
**	 WPEND_WPENDMEM	   Write Protect from WPFP to the last page of memory
**
*/

/* Register CONFIG2 (0xabfc)							   */

/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Select:
**	 POSCMOD_EC		   EC Oscillator mode selected
**	 POSCMOD_XT		   XT Oscillator mode selected
**	 POSCMOD_HS		   HS Oscillator mode selected
**	 POSCMOD_NONE		 Primary Oscillator disabled
**
**   I2C1 Pin Select bit:
**	 I2C1SEL_SEC		  Use alternate SCL1/SDA1 pins for I2C1
**	 I2C1SEL_PRI		  Use default SCL1/SDA1 pins for I2C1
**
**   IOLOCK One-Way Set Enable:
**	 IOL1WAY_OFF		  The IOLOCK bit can be set and cleared using the unlock sequence
**	 IOL1WAY_ON		   Once set, the IOLOCK bit cannot be cleared
**
**   OSCO Pin Configuration:
**	 OSCIOFNC_ON		  OSCO pin functions as port I/O (RA3)
**	 OSCIOFNC_OFF		 OSCO pin functions as clock output (CLKO)
**
**   Clock Switching and Fail-Safe Clock Monitor:
**	 FCKSM_CSECME		 Sw Enabled, Mon Enabled
**	 FCKSM_CSECMD		 Sw Enabled, Mon Disabled
**	 FCKSM_CSDCMD		 Sw Disabled, Mon Disabled
**
**   Initial Oscillator Select:
**	 FNOSC_FRC			Fast RC Oscillator (FRC)
**	 FNOSC_FRCPLL		 Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
**	 FNOSC_PRI			Primary Oscillator (XT, HS, EC)
**	 FNOSC_PRIPLL		 Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
**	 FNOSC_SOSC		   Secondary Oscillator (SOSC)
**	 FNOSC_LPRC		   Low-Power RC Oscillator (LPRC)
**	 FNOSC_FRCDIV		 Fast RC Oscillator with Postscaler (FRCDIV)
**
**   Internal External Switchover:
**	 IESO_OFF			 IESO mode (Two-Speed Start-up) disabled
**	 IESO_ON			  IESO mode (Two-Speed Start-up) enabled
**
*/

/* Register CONFIG1 (0xabfe)							   */

/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**	 WDTPS_PS1			1:1
**	 WDTPS_PS2			1:2
**	 WDTPS_PS4			1:4
**	 WDTPS_PS8			1:8
**	 WDTPS_PS16		   1:16
**	 WDTPS_PS32		   1:32
**	 WDTPS_PS64		   1:64
**	 WDTPS_PS128		  1:128
**	 WDTPS_PS256		  1:256
**	 WDTPS_PS512		  1:512
**	 WDTPS_PS1024		 1:1,024
**	 WDTPS_PS2048		 1:2,048
**	 WDTPS_PS4096		 1:4,096
**	 WDTPS_PS8192		 1:8,192
**	 WDTPS_PS16384		1:16,384
**	 WDTPS_PS32768		1:32,768
**
**   WDT Prescaler:
**	 FWPSA_PR32		   1:32
**	 FWPSA_PR128		  1:128
**
**   Windowed WDT:
**	 WINDIS_ON			Windowed Watchdof timer enabled
**	 WINDIS_OFF		   Standard Watchdog Timer is enabled
**
**   Watchdog Timer:
**	 FWDTEN_OFF		   Watchdog Timer is disabled
**	 FWDTEN_ON			Watchdog Timer is enabled
**
**   Emulator Pin Placement Select bits:
**	 ICS_PGx3			 Emulator functions are shared with PGEC3/PGED3
**	 ICS_PGx2			 Emulator functions are shared with PGEC2/PGED2
**	 ICS_PGx1			 Emulator functions are shared with PGEC1/PGED1
**
**   General Segment Write Protect:
**	 GWRP_ON			  Writes to program memory are allowed
**	 GWRP_OFF			 Writes to program memory are disabled
**
**   General Segment Code Protect:
**	 GCP_ON			   Code protection is enabled
**	 GCP_OFF			  Code protection is disabled
**
**   JTAG Port Enable:
**	 JTAGEN_OFF		   JTAG port is Disabled
**	 JTAGEN_ON			JTAG port is Enabled
**
*/
#endif			//ga10x

#if defined(__PIC24GA00x__)			//fro pic24ga00x
//config fues settings for everything else - need customization
_CONFIG1(
	JTAGEN_OFF &					//Disable JTAG port
	GCP_OFF &						//Disable code protect
	GWRP_OFF &						//Disable write protect
	BKBUG_OFF &						//Enable background debugger
	COE_OFF &						//Device resets into operational mode
	ICS_PGx2 &						//EMUC/EMUD share PGC2/PGD2
	FWDTEN_OFF &					//Disable watchdog timer (WDT)
	WINDIS_OFF &					//Use standard WDT (if it is enabled)
	FWPSA_PR128 &					//Use WDT prescaler ratio of 1:128
	WDTPS_PS32768					//Use WDT postscaler ratio of 1:32,768
)

_CONFIG2(
	FNOSC_FRC &						//Primary oscillator: FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
	POSCMOD_HS &					//High speed seeting for external oscillator: HS, XT, EC and NONE
	IESO_OFF &						//Disabled
	SOSCSEL_SOSC &					//Default Secondary Oscillator
	WUTSEL_LEG &					//Legacy Wake-up timer selected
	FCKSM_CSDCMD &					//Clock switching and clock monitor disabled
	OSCIOFNC_OFF &					//OSCO or Fosc/2
	IOL1WAY_OFF &					//Unlimited Writes To RP Registers
	I2C1SEL_PRI 					//Use Primary I2C1 pins
)
/* Register CONFIG2 (0xabfc)							   */

/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Two Speed Start-up:
**	 IESO_OFF			 Disabled
**	 IESO_ON			  Enabled
**
**   Secondary Oscillator:
**	 SOSCSEL_LPSOSC	   Low Power Secondary Oscillator
**	 SOSCSEL_SOSC		 Default Secondary Oscillator
**
**   Voltage Regulator Standby-mode Wake-up Timer:
**	 WUTSEL_FST		   Fast Wake-up timer selected
**	 WUTSEL_LEG		   Legacy Wake-up timer selected
**
**   Oscillator Selection:
**	 FNOSC_FRC			Fast RC oscillator
**	 FNOSC_FRCPLL		 Fast RC oscillator w/ divide and PLL
**	 FNOSC_PRI			Primary oscillator (XT, HS, EC)
**	 FNOSC_PRIPLL		 Primary oscillator (XT, HS, EC) w/ PLL
**	 FNOSC_SOSC		   Secondary oscillator
**	 FNOSC_LPRC		   Low power RC oscillator
**	 FNOSC_FRCDIV		 Fast RC oscillator with divide
**
**   Clock switching and clock monitor:
**	 FCKSM_CSECME		 Both enabled
**	 FCKSM_CSECMD		 Only clock switching enabled
**	 FCKSM_CSDCMD		 Both disabled
**
**   OSCO/RC15 function:
**	 OSCIOFNC_ON		  RC15
**	 OSCIOFNC_OFF		 OSCO or Fosc/2
**
**   RP Register Protection:
**	 IOL1WAY_OFF		  Unlimited Writes To RP Registers
**	 IOL1WAY_ON		   Write RP Registers Once
**
**   I2C1 pins Select:
**	 I2C1SEL_SEC		  Use Secondary I2C1 pins
**	 I2C1SEL_PRI		  Use Primary I2C1 pins
**
**   Oscillator Selection:
**	 POSCMOD_EC		   External clock
**	 POSCMOD_XT		   XT oscillator
**	 POSCMOD__S		   HS oscillator
**	 POSCMOD_NONE		 Primary disabled
**
*/

/* Register CONFIG1 (0xabfe)							   */


/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   JTAG:
**	 JTAGEN_OFF		   Disabled
**	 JTAGEN_ON			Enabled
**
**   Code Protect:
**	 GCP_ON			   Enabled
**	 GCP_OFF			  Disabled
**
**   Write Protect:
**	 GWRP_ON			  Enabled
**	 GWRP_OFF			 Disabled
**
**   Background Debugger:
**	 BKBUG_ON			 Enabled
**	 BKBUG_OFF			Disabled
**
**   Clip-on Emulation mode:
**	 COE_ON			   Enabled
**	 COE_OFF			  Disabled
**
**   ICD pins select:
**	 ICS_PGx3			 EMUC/EMUD share PGC3/PGD3
**	 ICS_PGx2			 EMUC/EMUD share PGC2/PGD2
**	 ICS_PGx1			 EMUC/EMUD share PGC1/PGD1
**
**   Watchdog Timer:
**	 FWDTEN_OFF		   Disabled
**	 FWDTEN_ON			Enabled
**
**   Windowed WDT:
**	 WINDIS_ON			Enabled
**	 WINDIS_OFF		   Disabled
**
**   Watchdog prescaler:
**	 FWPSA_PR32		   1:32
**	 FWPSA_PR128		  1:128
**
**   Watchdog postscale:
**	 WDTPS_PS1			1:1
**	 WDTPS_PS2			1:2
**	 WDTPS_PS4			1:4
**	 WDTPS_PS8			1:8
**	 WDTPS_PS16		   1:16
**	 WDTPS_PS32		   1:32
**	 WDTPS_PS64		   1:64
**	 WDTPS_PS128		  1:128
**	 WDTPS_PS256		  1:256
**	 WDTPS_PS512		  1:512
**	 WDTPS_PS1024		 1:1,024
**	 WDTPS_PS2048		 1:2,048
**	 WDTPS_PS4096		 1:4,096
**	 WDTPS_PS8192		 1:8,192
**	 WDTPS_PS16384		1:16,384
**	 WDTPS_PS32768		1:32,768
**
*/
#endif				//GA00x

//gb00x
#if defined(__PIC24GB00x__)		//for pic24gb00x



_CONFIG1(
	WDTPS_PS32768 &			//1:32,768
	FWPSA_PR128 &			//1:128
	WINDIS_OFF &			//Standard Watchdog Timer is enabled
	FWDTEN_OFF &			//Watchdog Timer is disabled
	ICS_PGx1 &				//Emulator functions are shared with PGEC1/PGED1
	GWRP_OFF &				//Writes to program memory are disabled
	GCP_OFF	&				//Code protection is disabled
	JTAGEN_OFF				//JTAG port is Disabled
)

_CONFIG2(
	FNOSC_FRC &				//Primary Oscillator: FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
	POSCMOD_HS &			//HS Oscillator mode selected: HS, XT, EC and NONE
	I2C1SEL_PRI &			//Use default SCL1/SDA1 pins for I2C1
	IOL1WAY_OFF &			//The IOLOCK bit can be set and cleared using the unlock sequence
	OSCIOFNC_OFF &			//OSCO pin functions as clock output (CLKO)
	FCKSM_CSDCMD &			//Sw Disabled, Mon Disabled
	PLL96MHZ_ON &			//96 MHz PLL Startup is enabled automatically on start-up
	PLLDIV_DIV12 &			//Oscillator input divided by 12 (48 MHz input)
	IESO_OFF			//IESO mode (Two-Speed Start-up) disabled
)

_CONFIG3(
	WPFP_WPFP63 &			//Highest Page (same as page 42)
	SOSCSEL_IO &			//SOSC pins have digital I/O functions (RA4, RB4)
	WUTSEL_LEG &			//Default regulator start-up time used
	WPDIS_WPDIS &			//Segmented code protection disabled
	WPCFG_WPCFGDIS &		//Last page and Flash Configuration words are unprotected
	WPEND_WPSTARTMEM		//Write Protect from page 0 to WPFP
)

_CONFIG4(
	DSWDTPS_DSWDTPSF &		//1:2,147,483,648 (25.7 days)
	DSWDTOSC_SOSC &			//DSWDT uses Secondary Oscillator (SOSC)
	RTCOSC_SOSC &			//RTCC uses Low Power RC Oscillator (LPRC)
	DSBOREN_OFF &			//BOR disabled in Deep Sleep
	DSWDTEN_OFF			//DSWDT disabled
)
/* -------------------------------------------------------- */
/* Macros for setting device configuration registers		*/
/* -------------------------------------------------------- */

/* Register CONFIG4 (0xabf8)							   */

/*
** Only one invocation of CONFIG4 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG4.
** Multiple options may be combined, as shown:
**
** _CONFIG4( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   DSWDT Postscale Select:
**	 DSWDTPS_DSWDTPS0	 1:2 (2.1 ms)
**	 DSWDTPS_DSWDTPS1	 1:8 (8.3 ms)
**	 DSWDTPS_DSWDTPS2	 1:32 (33 ms)
**	 DSWDTPS_DSWDTPS3	 1:128 (132 ms)
**	 DSWDTPS_DSWDTPS4	 1:512 (528 ms)
**	 DSWDTPS_DSWDTPS5	 1:2,048 (2.1 seconds)
**	 DSWDTPS_DSWDTPS6	 1:8,192 (8.5 seconds)
**	 DSWDTPS_DSWDTPS7	 1:32,768 (34 seconds)
**	 DSWDTPS_DSWDTPS8	 1:131,072 (135 seconds)
**	 DSWDTPS_DSWDTPS9	 1:524,288 (9 minutes)
**	 DSWDTPS_DSWDTPSA	 1:2,097,152 (36 minutes)
**	 DSWDTPS_DSWDTPSB	 1:8,388,608 (2.4 hours)
**	 DSWDTPS_DSWDTPSC	 1:33,554,432 (9.6 hours)
**	 DSWDTPS_DSWDTPSD	 1:134,217,728 (38.5 hours)
**	 DSWDTPS_DSWDTPSE	 1:536,870,912 (6.4 days)
**	 DSWDTPS_DSWDTPSF	 1:2,147,483,648 (25.7 days)
**
**   Deep Sleep Watchdog Timer Oscillator Select:
**	 DSWDTOSC_SOSC		DSWDT uses Secondary Oscillator (SOSC)
**	 DSWDTOSC_LPRC		DSWDT uses Low Power RC Oscillator (LPRC)
**
**   RTCC Reference Oscillator  Select:
**	 RTCOSC_LPRC		  RTCC uses Low Power RC Oscillator (LPRC)
**	 RTCOSC_SOSC		  RTCC uses Secondary Oscillator (SOSC)
**
**   Deep Sleep BOR Enable bit:
**	 DSBOREN_OFF		  BOR disabled in Deep Sleep
**	 DSBOREN_ON		   BOR enabled in Deep Sleep
**
**   Deep Sleep Watchdog Timer:
**	 DSWDTEN_OFF		  DSWDT disabled
**	 DSWDTEN_ON		   DSWDT enabled
**
*/

/* Register CONFIG3 (0xabfa)							   */

/*
** Only one invocation of CONFIG3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG3.
** Multiple options may be combined, as shown:
**
** _CONFIG3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Write Protection Flash Page Segment Boundary:
**	 WPFP_WPFP0		   Page 0 (0x0)
**	 WPFP_WPFP1		   Page 1 (0x400)
**	 WPFP_WPFP2		   Page 2 (0x800)
**	 WPFP_WPFP3		   Page 3 (0xC00)
**	 WPFP_WPFP4		   Page 4 (0x1000)
**	 WPFP_WPFP5		   Page 5 (0x1400)
**	 WPFP_WPFP6		   Page 6 (0x1800)
**	 WPFP_WPFP7		   Page 7 (0x1C00)
**	 WPFP_WPFP8		   Page 8 (0x2000)
**	 WPFP_WPFP9		   Page 9 (0x2400)
**	 WPFP_WPFP10		  Page 10 (0x2800)
**	 WPFP_WPFP11		  Page 11 (0x2C00)
**	 WPFP_WPFP12		  Page 12 (0x3000)
**	 WPFP_WPFP13		  Page 13 (0x3400)
**	 WPFP_WPFP14		  Page 14 (0x3800)
**	 WPFP_WPFP15		  Page 15 (0x3C00)
**	 WPFP_WPFP16		  Page 16 (0x4000)
**	 WPFP_WPFP17		  Page 17 (0x4400)
**	 WPFP_WPFP18		  Page 18 (0x4800)
**	 WPFP_WPFP19		  Page 19 (0x4C00)
**	 WPFP_WPFP20		  Page 20 (0x5000)
**	 WPFP_WPFP21		  Page 21 (0x5400)
**	 WPFP_WPFP22		  Page 22 (0x5800)
**	 WPFP_WPFP23		  Page 23 (0x5C00)
**	 WPFP_WPFP24		  Page 24 (0x6000)
**	 WPFP_WPFP25		  Page 25 (0x6400)
**	 WPFP_WPFP26		  Page 26 (0x6800)
**	 WPFP_WPFP27		  Page 27 (0x6C00)
**	 WPFP_WPFP28		  Page 28 (0x7000)
**	 WPFP_WPFP29		  Page 29 (0x7400)
**	 WPFP_WPFP30		  Page 30 (0x7800)
**	 WPFP_WPFP31		  Page 31 (0x7C00)
**	 WPFP_WPFP32		  Page 32 (0x8000)
**	 WPFP_WPFP33		  Page 33 (0x8400)
**	 WPFP_WPFP34		  Page 34 (0x8800)
**	 WPFP_WPFP35		  Page 35 (0x8C00)
**	 WPFP_WPFP36		  Page 36 (0x9000)
**	 WPFP_WPFP37		  Page 37 (0x9400)
**	 WPFP_WPFP38		  Page 38 (0x9800)
**	 WPFP_WPFP39		  Page 39 (0x9C00)
**	 WPFP_WPFP40		  Page 40 (0xA000)
**	 WPFP_WPFP41		  Page 41 (0xA400)
**	 WPFP_WPFP42		  Page 42 (0xA800)
**	 WPFP_WPFP63		  Highest Page (same as page 42)
**
**   Secondary Oscillator Pin Mode Select:
**	 SOSCSEL_IO		   SOSC pins have digital I/O functions (RA4, RB4)
**	 SOSCSEL_LPSOSC	   SOSC pins in Low-Power (low drive-strength) Oscillator Mode
**	 SOSCSEL_SOSC		 SOSC pins in Default (high drive-strength) Oscillator Mode
**
**   Voltage Regulator Wake-up Time Select:
**	 WUTSEL_FST		   Fast regulator start-up time used
**	 WUTSEL_LEG		   Default regulator start-up time used
**
**   Segment Write Protection Disable:
**	 WPDIS_WPEN		   Segmented code protection enabled
**	 WPDIS_WPDIS		  Segmented code protection disabled
**
**   Write Protect Configuration Page Select:
**	 WPCFG_WPCFGEN		Last page and Flash Configuration words are code-protected
**	 WPCFG_WPCFGDIS	   Last page and Flash Configuration words are unprotected
**
**   Segment Write Protection End Page Select:
**	 WPEND_WPSTARTMEM	 Write Protect from page 0 to WPFP
**	 WPEND_WPENDMEM	   Write Protect from WPFP to the last page of memory
**
*/

/* Register CONFIG2 (0xabfc)							   */
/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Select:
**	 POSCMOD_EC		   EC Oscillator mode selected
**	 POSCMOD_XT		   XT Oscillator mode selected
**	 POSCMOD_HS		   HS Oscillator mode selected
**	 POSCMOD_NONE		 Primary Oscillator disabled
**
**   I2C1 Pin Select bit:
**	 I2C1SEL_SEC		  Use alternate SCL1/SDA1 pins for I2C1
**	 I2C1SEL_PRI		  Use default SCL1/SDA1 pins for I2C1
**
**   IOLOCK One-Way Set Enable:
**	 IOL1WAY_OFF		  The IOLOCK bit can be set and cleared using the unlock sequence
**	 IOL1WAY_ON		   Once set, the IOLOCK bit cannot be cleared
**
**   OSCO Pin Configuration:
**	 OSCIOFNC_ON		  OSCO pin functions as port I/O (RA3)
**	 OSCIOFNC_OFF		 OSCO pin functions as clock output (CLKO)
**
**   Clock Switching and Fail-Safe Clock Monitor:
**	 FCKSM_CSECME		 Sw Enabled, Mon Enabled
**	 FCKSM_CSECMD		 Sw Enabled, Mon Disabled
**	 FCKSM_CSDCMD		 Sw Disabled, Mon Disabled
**
**   Initial Oscillator Select:
**	 FNOSC_FRC			Fast RC Oscillator (FRC)
**	 FNOSC_FRCPLL		 Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
**	 FNOSC_PRI			Primary Oscillator (XT, HS, EC)
**	 FNOSC_PRIPLL		 Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
**	 FNOSC_SOSC		   Secondary Oscillator (SOSC)
**	 FNOSC_LPRC		   Low-Power RC Oscillator (LPRC)
**	 FNOSC_FRCDIV		 Fast RC Oscillator with Postscaler (FRCDIV)
**
**   96MHz PLL Startup Select:
**	 PLL96MHZ_OFF		 96 MHz PLL Startup is enabled by user in software( controlled with the PLLEN bit)
**	 PLL96MHZ_ON		  96 MHz PLL Startup is enabled automatically on start-up
**
**   USB 96 MHz PLL Prescaler Select:
**	 PLLDIV_NODIV		 Oscillator input used directly (4 MHz input)
**	 PLLDIV_DIV2		  Oscillator input divided by 2 (8 MHz input)
**	 PLLDIV_DIV3		  Oscillator input divided by 3 (12 MHz input)
**	 PLLDIV_DIV4		  Oscillator input divided by 4 (16 MHz input)
**	 PLLDIV_DIV5		  Oscillator input divided by 5 (20 MHz input)
**	 PLLDIV_DIV6		  Oscillator input divided by 6 (24 MHz input)
**	 PLLDIV_DIV8		  Oscillator input divided by 8 (32 MHz input)
**	 PLLDIV_DIV12		 Oscillator input divided by 12 (48 MHz input)
**
**   Internal External Switchover:
**	 IESO_OFF			 IESO mode (Two-Speed Start-up) disabled
**	 IESO_ON			  IESO mode (Two-Speed Start-up) enabled
**
*/

/* Register CONFIG1 (0xabfe)							   */
/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**	 WDTPS_PS1			1:1
**	 WDTPS_PS2			1:2
**	 WDTPS_PS4			1:4
**	 WDTPS_PS8			1:8
**	 WDTPS_PS16		   1:16
**	 WDTPS_PS32		   1:32
**	 WDTPS_PS64		   1:64
**	 WDTPS_PS128		  1:128
**	 WDTPS_PS256		  1:256
**	 WDTPS_PS512		  1:512
**	 WDTPS_PS1024		 1:1,024
**	 WDTPS_PS2048		 1:2,048
**	 WDTPS_PS4096		 1:4,096
**	 WDTPS_PS8192		 1:8,192
**	 WDTPS_PS16384		1:16,384
**	 WDTPS_PS32768		1:32,768
**
**   WDT Prescaler:
**	 FWPSA_PR32		   1:32
**	 FWPSA_PR128		  1:128
**
**   Windowed WDT:
**	 WINDIS_ON			Windowed Watchdof timer enabled
**	 WINDIS_OFF		   Standard Watchdog Timer is enabled
**
**   Watchdog Timer:
**	 FWDTEN_OFF		   Watchdog Timer is disabled
**	 FWDTEN_ON			Watchdog Timer is enabled
**
**   Emulator Pin Placement Select bits:
**	 ICS_PGx3			 Emulator functions are shared with PGEC3/PGED3
**	 ICS_PGx2			 Emulator functions are shared with PGEC2/PGED2
**	 ICS_PGx1			 Emulator functions are shared with PGEC1/PGED1
**
**   General Segment Write Protect:
**	 GWRP_ON			  Writes to program memory are allowed
**	 GWRP_OFF			 Writes to program memory are disabled
**
**   General Segment Code Protect:
**	 GCP_ON			   Code protection is enabled
**	 GCP_OFF			  Code protection is disabled
**
**   JTAG Port Enable:
**	 JTAGEN_OFF		   JTAG port is Disabled
**	 JTAGEN_ON			JTAG port is Enabled
**
*/

#endif		//pic24gb00x

//ga110
#if defined(__PIC24GA110__)	//for GA110 family
//ga110 config bits
//config1
_CONFIG1(
	JTAGEN_OFF &					//Disable JTAG port
	GCP_OFF &						//Disable code protect
	GWRP_OFF &						//Disable write protect
	ICS_PGx1 &						//EMUC/EMUD share PGC2/PGD2
	FWDTEN_OFF &					//Disable watchdog timer (WDT)
	WINDIS_OFF &					//Use standard WDT (if it is enabled)
	FWPSA_PR128 &					//Use WDT prescaler ratio of 1:128
	WDTPS_PS32768					//Use WDT postscaler ratio of 1:32,768
)
//config2
_CONFIG2(
	FNOSC_FRC &						//Primary oscillator: FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
	POSCMOD_HS &					//External oscillator: HS, XT, EC, NONE
	IESO_OFF &						//Disabled
	FCKSM_CSDCMD &					//Clock switching and clock monitor disabled
	OSCIOFNC_OFF &					//OSCO or Fosc/2
	IOL1WAY_OFF						//Unlimited Writes To RP Registers
//	I2C1SEL_PRI						//Use Primary I2C1 pins
//	SOSCSEL_SOSC &					//Default Secondary Oscillator
//	WUTSEL_LEG &					//Legacy Wake-up timer selected
)
//config3
_CONFIG3(
	WPFP_WPFP0 &					//Highest Page (same as page 42)
//	SOSCSEL_IO &					//SOSC pins have digital I/O functions (RA4, RB4)
//	WUTSEL_LEG &					//Default regulator start-up time used
	WPDIS_WPDIS &					//Segmented code protection disabled
	WPCFG_WPCFGDIS &				//Last page and Flash Configuration words are unprotected
	WPEND_WPENDMEM					//Write Protect from WPFP to the last page of memory
)


/* -------------------------------------------------------- */
/* Macros for setting device configuration registers		*/
/* -------------------------------------------------------- */

/* Register CONFIG3 (0xabfa)							   */

//extern __attribute__((space(prog))) int _CONFIG3;
//#define _CONFIG3(x) __attribute__((section("__CONFIG3.sec"),space(prog))) int _CONFIG3 = (x);

/*
** Only one invocation of CONFIG3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG3.
** Multiple options may be combined, as shown:
**
** _CONFIG3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Write Protection Flash Page Segment Boundary:
**	 WPFP_WPFP0		   Page 0 (0x00)
**	 WPFP_WPFP1		   Page 1 (0x400)
**	 WPFP_WPFP2		   Page 2 (0x800)
**	 WPFP_WPFP3		   Page 3 (0xC00)
**	 WPFP_WPFP4		   Page 4 (0x1000)
**	 WPFP_WPFP5		   Page 5 (0x1400)
**	 WPFP_WPFP6		   Page 6 (0x1800)
**	 WPFP_WPFP7		   Page 7 (0x1C00)
**	 WPFP_WPFP8		   Page 8 (0x2000)
**	 WPFP_WPFP9		   Page 9 (0x2400)
**	 WPFP_WPFP10		  Page 10 (0x2800)
**	 WPFP_WPFP11		  Page 11 (0x2C00)
**	 WPFP_WPFP12		  Page 12 (0x3000)
**	 WPFP_WPFP13		  Page 13 (0x3400)
**	 WPFP_WPFP14		  Page 14 (0x3800)
**	 WPFP_WPFP15		  Page 15 (0x3C00)
**	 WPFP_WPFP16		  Page 16 (0x4000)
**	 WPFP_WPFP17		  Page 17 (0x4400)
**	 WPFP_WPFP18		  Page 18 (0x4800)
**	 WPFP_WPFP19		  Page 19 (0x4C00)
**	 WPFP_WPFP20		  Page 20 (0x5000)
**	 WPFP_WPFP21		  Page 21 (0x5400)
**	 WPFP_WPFP22		  Page 22 (0x5800)
**	 WPFP_WPFP23		  Page 23 (0x5C00)
**	 WPFP_WPFP24		  Page 24 (0x6000)
**	 WPFP_WPFP25		  Page 25 (0x6400)
**	 WPFP_WPFP26		  Page 26 (0x6800)
**	 WPFP_WPFP27		  Page 27 (0x6C00)
**	 WPFP_WPFP28		  Page 28 (0x7000)
**	 WPFP_WPFP29		  Page 29 (0x7400)
**	 WPFP_WPFP30		  Page 30 (0x7800)
**	 WPFP_WPFP31		  Page 31 (0x7C00)
**	 WPFP_WPFP32		  Page 32 (0x8000)
**	 WPFP_WPFP33		  Page 33 (0x8400)
**	 WPFP_WPFP34		  Page 34 (0x8800)
**	 WPFP_WPFP35		  Page 35 (0x8C00)
**	 WPFP_WPFP36		  Page 36 (0x9000)
**	 WPFP_WPFP37		  Page 37 (0x9400)
**	 WPFP_WPFP38		  Page 38 (0x9800)
**	 WPFP_WPFP39		  Page 39 (0x9C00)
**	 WPFP_WPFP40		  Page 40 (0xA000)
**	 WPFP_WPFP41		  Page 41 (0xA400)
**	 WPFP_WPFP42		  Page 42 (0xA800)
**	 WPFP_WPFP511		 Highest Page (same as page 42)
**
**   Segment Write Protection Disable bit:
**	 WPDIS_WPEN		   Segmented code protection enabled
**	 WPDIS_WPDIS		  Segmented code protection disabled
**
**   Configuration Word Code Page Protection Selectbit:
**	 WPCFG_WPCFGEN		Last page and Flash configuration words are code-protected
**	 WPCFG_WPCFGDIS	   Last page(at the top of program memory) and Flash configuration words are not protected
**
**   Segment Write Protection End Page Select bit:
**	 WPEND_WPSTARTMEM	 Write Protect from page 0 to WPFP
**	 WPEND_WPENDMEM	   Write Protect from WPFP to the last page of memory
**
*/

/* Register CONFIG2 (0xabfc)							   */

//extern __attribute__((space(prog))) int _CONFIG2;
//#define _CONFIG2(x) __attribute__((section("__CONFIG2.sec"),space(prog))) int _CONFIG2 = (x);

/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Select:
**	 POSCMOD_EC		   EC Oscillator mode Selected
**	 POSCMOD_XT		   XT Oscillator mode selected
**	 POSCMOD_HS		   HS Oscillator mode selected
**	 POSCMOD_NONE		 Primary Oscillator disabled
**
**   IOLOCK One-Way Set Enable bit:
**	 IOL1WAY_OFF		  Unlimited Writes To RP Registers
**	 IOL1WAY_ON		   Write RP Registers Once
**
**   Primary Oscillator Output Function:
**	 OSCIOFNC_ON		  OSCO functions as port I/O (RC15)
**	 OSCIOFNC_OFF		 OSCO functions as CLKO (FOSC/2)
**
**   Clock Switching and Monitor:
**	 FCKSM_CSECME		 Clock switching and Fail-safe Clock Monitor are enabled
**	 FCKSM_CSECMD		 Clock switching is enabled, Fail-safe Clock Monitor is disabled
**	 FCKSM_CSDCMD		 Both Clock Switching and Fail-safe Clock Monitor are disabled
**
**   Oscillator Select:
**	 FNOSC_FRC			Fast RC oscillator
**	 FNOSC_FRCPLL		 Fast RC oscillator with Postscaler and PLL module (FRCPLL)
**	 FNOSC_PRI			Primary oscillator (XT, HS, EC)
**	 FNOSC_PRIPLL		 Primary oscillator (XT, HS, EC) with PLL module (XTPLL, HSPLL, ECPLL)
**	 FNOSC_SOSC		   Secondary oscillator (SOSC)
**	 FNOSC_LPRC		   Low-Power RC oscillator (LPRC)
**	 FNOSC_FRCDIV		 Fast RC oscillator with Postscaler
**
**   Internal External Switch Over Mode:
**	 IESO_OFF			 IESO mode (Two-speed start-up)disabled
**	 IESO_ON			  IESO mode (Two-speed start-up) enabled
**
*/

/* Register CONFIG1 (0xabfe)							   */

//extern __attribute__((space(prog))) int _CONFIG1;
//#define _CONFIG1(x) __attribute__((section("__CONFIG1.sec"),space(prog))) int _CONFIG1 = (x);

/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**	 WDTPS_PS1			1:1
**	 WDTPS_PS2			1:2
**	 WDTPS_PS4			1:4
**	 WDTPS_PS8			1:8
**	 WDTPS_PS16		   1:16
**	 WDTPS_PS32		   1:32
**	 WDTPS_PS64		   1:64
**	 WDTPS_PS128		  1:128
**	 WDTPS_PS256		  1:256
**	 WDTPS_PS512		  1:512
**	 WDTPS_PS1024		 1:1,024
**	 WDTPS_PS2048		 1:2,048
**	 WDTPS_PS4096		 1:4,096
**	 WDTPS_PS8192		 1:8,192
**	 WDTPS_PS16384		1:16,384
**	 WDTPS_PS32768		1:32,768
**
**   WDT Prescaler:
**	 FWPSA_PR32		   1:32
**	 FWPSA_PR128		  1:128
**
**   Watchdog Timer Window:
**	 WINDIS_ON			Windowed watchdog timer is enabled
**	 WINDIS_OFF		   Standard Watchdog timer is enabled(Windowed mode is disabled)
**
**   Watchdog Timer Enable:
**	 FWDTEN_OFF		   Watchdog timer is disabled
**	 FWDTEN_ON			Watchdog timer is enabled
**
**   Comm Channel Select:
**	 ICS_PGx3			 EMUC/EMUD share PGC3/PGD3
**	 ICS_PGx2			 EMUC/EMUD share PGC2/PGD2
**	 ICS_PGx1			 EMUC/EMUD share PGC1/PGD1
**
**   General Code Segment Write Protect:
**	 GWRP_ON			  Writes to program memory are disabled
**	 GWRP_OFF			 Writes to program memory are allowed
**
**   General Code Segment Code Protect:
**	 GCP_ON			   Code protection is enabled
**	 GCP_OFF			  Code protection is disabled
**
**   JTAG Port Enable:
**	 JTAGEN_OFF		   JTAG port is disabled
**	 JTAGEN_ON			JTAG port is enabled
**
*/
#endif				//GA110

#if defined(__PIC24GB110__)		//for GB110 family
//gb110

_CONFIG1(
	WDTPS_PS32768 &					//1:32,768
	FWPSA_PR128 &					//1:128
	WINDIS_OFF &					//Standard Watchdog Timer is enabled
	FWDTEN_OFF &					//Watchdog Timer is disabled
	ICS_PGx1 &						//Emulator functions are shared with PGEC1/PGED1
	COE_OFF	&						//Set Clip On Emulation Mode:, ON or OFF
	BKBUG_OFF &						//Background Debug: ON or OFF
	GWRP_OFF &						//Writes to program memory are disabled
	GCP_OFF	&						//Code protection is disabled
	JTAGEN_OFF						//JTAG port is Disabled
)

_CONFIG2(
	FNOSC_FRC &						//Primary oscillator: FRC, FRCPLL, PRI, PRIPLL, SOSC, LPRC, FRCDIV
	POSCMOD_HS &					//External oscillator: HS, XT, EC, NONE
	DISUVREG_OFF &					//Internal USB 3.3V Regulator Disable bit: ON or OFF
//	I2C1SEL_PRI &					//Use default SCL1/SDA1 pins for I2C1
	IOL1WAY_OFF &					//The IOLOCK bit can be set and cleared using the unlock sequence
	OSCIOFNC_OFF &					//OSCO pin functions as clock output (CLKO)
	FCKSM_CSDCMD &					//Sw Disabled, Mon Disabled
	PLL_96MHZ_ON &					//96 MHz PLL Startup is enabled automatically on start-up
	PLLDIV_DIV12 &					//Oscillator input divided by 12 (48 MHz input)
	IESO_OFF						//IESO mode (Two-Speed Start-up) disabled
)

_CONFIG3(
	WPFP_WPFP0 &					//Highest Page (same as page 42)
//	SOSCSEL_IO &					//SOSC pins have digital I/O functions (RA4, RB4)
//	WUTSEL_LEG &					//Default regulator start-up time used
	WPDIS_WPDIS &					//Segmented code protection disabled
	WPCFG_WPCFGDIS &				//Last page and Flash Configuration words are unprotected
	WPEND_WPSTARTMEM				//Write Protect from page 0 to WPFP
)


/* -------------------------------------------------------- */
/* Macros for setting device configuration registers		*/
/* -------------------------------------------------------- */

/* Register CONFIG3 (0x2abfa)							   */

//extern __attribute__((space(prog))) int _CONFIG3;
//#define _CONFIG3(x) __attribute__((section("__CONFIG3.sec"),space(prog))) int _CONFIG3 = (x);

/*
** Only one invocation of CONFIG3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG3.
** Multiple options may be combined, as shown:
**
** _CONFIG3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Write Protection Flash Page Segment Boundary:
**	 WPFP_WPFP0		   Page 0 (0x00)
**	 WPFP_WPFP1		   Page 1 (0x400)
**	 WPFP_WPFP2		   Page 2 (0x800)
**	 WPFP_WPFP3		   Page 3 (0xC00)
**	 WPFP_WPFP4		   Page 4 (0x1000)
**	 WPFP_WPFP5		   Page 5 (0x1400)
**	 WPFP_WPFP6		   Page 6 (0x1800)
**	 WPFP_WPFP7		   Page 7 (0x1C00)
**	 WPFP_WPFP8		   Page 8 (0x2000)
**	 WPFP_WPFP9		   Page 9 (0x2400)
**	 WPFP_WPFP10		  Page 10 (0x2800)
**	 WPFP_WPFP11		  Page 11 (0x2C00)
**	 WPFP_WPFP12		  Page 12 (0x3000)
**	 WPFP_WPFP13		  Page 13 (0x3400)
**	 WPFP_WPFP14		  Page 14 (0x3800)
**	 WPFP_WPFP15		  Page 15 (0x3C00)
**	 WPFP_WPFP16		  Page 16 (0x4000)
**	 WPFP_WPFP17		  Page 17 (0x4400)
**	 WPFP_WPFP18		  Page 18 (0x4800)
**	 WPFP_WPFP19		  Page 19 (0x4C00)
**	 WPFP_WPFP20		  Page 20 (0x5000)
**	 WPFP_WPFP21		  Page 21 (0x5400)
**	 WPFP_WPFP22		  Page 22 (0x5800)
**	 WPFP_WPFP23		  Page 23 (0x5C00)
**	 WPFP_WPFP24		  Page 24 (0x6000)
**	 WPFP_WPFP25		  Page 25 (0x6400)
**	 WPFP_WPFP26		  Page 26 (0x6800)
**	 WPFP_WPFP27		  Page 27 (0x6C00)
**	 WPFP_WPFP28		  Page 28 (0x7000)
**	 WPFP_WPFP29		  Page 29 (0x7400)
**	 WPFP_WPFP30		  Page 30 (0x7800)
**	 WPFP_WPFP31		  Page 31 (0x7C00)
**	 WPFP_WPFP32		  Page 32 (0x8000)
**	 WPFP_WPFP33		  Page 33 (0x8400)
**	 WPFP_WPFP34		  Page 34 (0x8800)
**	 WPFP_WPFP35		  Page 35 (0x8C00)
**	 WPFP_WPFP36		  Page 36 (0x9000)
**	 WPFP_WPFP37		  Page 37 (0x9400)
**	 WPFP_WPFP38		  Page 38 (0x9800)
**	 WPFP_WPFP39		  Page 39 (0x9C00)
**	 WPFP_WPFP40		  Page 40 (0xA000)
**	 WPFP_WPFP41		  Page 41 (0xA400)
**	 WPFP_WPFP42		  Page 42 (0xA800)
**	 WPFP_WPFP43		  Page 43 (0xAC00)
**	 WPFP_WPFP44		  Page 44 (0xB000)
**	 WPFP_WPFP45		  Page 45 (0xB400)
**	 WPFP_WPFP46		  Page 46 (0xB800)
**	 WPFP_WPFP47		  Page 47 (0xBC00)
**	 WPFP_WPFP48		  Page 48 (0xC000)
**	 WPFP_WPFP49		  Page 49 (0xC400)
**	 WPFP_WPFP50		  Page 50 (0xC800)
**	 WPFP_WPFP51		  Page 51 (0xCC00)
**	 WPFP_WPFP52		  Page 52 (0xD000)
**	 WPFP_WPFP53		  Page 53 (0xD400)
**	 WPFP_WPFP54		  Page 54 (0xD800)
**	 WPFP_WPFP55		  Page 55 (0xDC00)
**	 WPFP_WPFP56		  Page 56 (0xE000)
**	 WPFP_WPFP57		  Page 57 (0xE400)
**	 WPFP_WPFP58		  Page 58 (0xE800)
**	 WPFP_WPFP59		  Page 59 (0xEC00)
**	 WPFP_WPFP60		  Page 60 (0xF000)
**	 WPFP_WPFP61		  Page 61 (0xF400)
**	 WPFP_WPFP62		  Page 62 (0xF800)
**	 WPFP_WPFP63		  Page 63 (0xFC00)
**	 WPFP_WPFP64		  Page 64 (0x10000)
**	 WPFP_WPFP65		  Page 65 (0x10400)
**	 WPFP_WPFP66		  Page 66 (0x10800)
**	 WPFP_WPFP67		  Page 67 (0x10C00)
**	 WPFP_WPFP68		  Page 68 (0x11000)
**	 WPFP_WPFP69		  Page 69 (0x11400)
**	 WPFP_WPFP70		  Page 70 (0x11800)
**	 WPFP_WPFP71		  Page 71 (0x11C00)
**	 WPFP_WPFP72		  Page 72 (0x12000)
**	 WPFP_WPFP73		  Page 73 (0x12400)
**	 WPFP_WPFP74		  Page 74 (0x12800)
**	 WPFP_WPFP75		  Page 75 (0x12C00)
**	 WPFP_WPFP76		  Page 76 (0x13000)
**	 WPFP_WPFP77		  Page 77 (0x13400)
**	 WPFP_WPFP78		  Page 78 (0x13800)
**	 WPFP_WPFP79		  Page 79 (0x13C00)
**	 WPFP_WPFP80		  Page 80 (0x14000)
**	 WPFP_WPFP81		  Page 81 (0x14400)
**	 WPFP_WPFP82		  Page 82 (0x14800)
**	 WPFP_WPFP83		  Page 83 (0x14C00)
**	 WPFP_WPFP84		  Page 84 (0x15000)
**	 WPFP_WPFP85		  Page 85 (0x15400)
**	 WPFP_WPFP86		  Page 86 (0x15800)
**	 WPFP_WPFP87		  Page 87 (0x15C00)
**	 WPFP_WPFP88		  Page 88 (0x16000)
**	 WPFP_WPFP89		  Page 89 (0x16400)
**	 WPFP_WPFP90		  Page 90 (0x16800)
**	 WPFP_WPFP91		  Page 91 (0x16C00)
**	 WPFP_WPFP92		  Page 92 (0x17000)
**	 WPFP_WPFP93		  Page 93 (0x17400)
**	 WPFP_WPFP94		  Page 94 (0x17800)
**	 WPFP_WPFP95		  Page 95 (0x17C00)
**	 WPFP_WPFP96		  Page 96 (0x18000)
**	 WPFP_WPFP97		  Page 97 (0x18400)
**	 WPFP_WPFP98		  Page 98 (0x18800)
**	 WPFP_WPFP99		  Page 99 (0x18C00)
**	 WPFP_WPFP100		 Page 100 (0x19000)
**	 WPFP_WPFP101		 Page 101 (0x19400)
**	 WPFP_WPFP102		 Page 102 (0x19800)
**	 WPFP_WPFP103		 Page 103 (0x19C00)
**	 WPFP_WPFP104		 Page 104 (0x1A000)
**	 WPFP_WPFP105		 Page 105 (0x1A400)
**	 WPFP_WPFP106		 Page 106 (0x1A800)
**	 WPFP_WPFP107		 Page 107 (0x1AC00)
**	 WPFP_WPFP108		 Page 108 (0x1B000)
**	 WPFP_WPFP109		 Page 109 (0x1B400)
**	 WPFP_WPFP110		 Page 110 (0x1B800)
**	 WPFP_WPFP111		 Page 111 (0x1BC00)
**	 WPFP_WPFP112		 Page 112 (0x1C000)
**	 WPFP_WPFP113		 Page 113 (0x1C400)
**	 WPFP_WPFP114		 Page 114 (0x1C800)
**	 WPFP_WPFP115		 Page 115 (0x1CC00)
**	 WPFP_WPFP116		 Page 116 (0x1D000)
**	 WPFP_WPFP117		 Page 117 (0x1D400)
**	 WPFP_WPFP118		 Page 118 (0x1D800)
**	 WPFP_WPFP119		 Page 119 (0x1DC00)
**	 WPFP_WPFP120		 Page 120 (0x1E000)
**	 WPFP_WPFP121		 Page 121 (0x1E400)
**	 WPFP_WPFP122		 Page 122 (0x1E800)
**	 WPFP_WPFP123		 Page 123 (0x1EC00)
**	 WPFP_WPFP124		 Page 124 (0x1F000)
**	 WPFP_WPFP125		 Page 125 (0x1F400)
**	 WPFP_WPFP126		 Page 126 (0x1F800)
**	 WPFP_WPFP127		 Page 127 (0x1FC00)
**	 WPFP_WPFP128		 Page 128 (0x20000)
**	 WPFP_WPFP129		 Page 129 (0x20400)
**	 WPFP_WPFP130		 Page 130 (0x20800)
**	 WPFP_WPFP131		 Page 131 (0x20C00)
**	 WPFP_WPFP132		 Page 132 (0x21000)
**	 WPFP_WPFP133		 Page 133 (0x21400)
**	 WPFP_WPFP134		 Page 134 (0x21800)
**	 WPFP_WPFP135		 Page 135 (0x21C00)
**	 WPFP_WPFP136		 Page 136 (0x22000)
**	 WPFP_WPFP137		 Page 137 (0x22400)
**	 WPFP_WPFP138		 Page 138 (0x22800)
**	 WPFP_WPFP139		 Page 139 (0x22C00)
**	 WPFP_WPFP140		 Page 140 (0x23000)
**	 WPFP_WPFP141		 Page 141 (0x23400)
**	 WPFP_WPFP142		 Page 142 (0x23800)
**	 WPFP_WPFP143		 Page 143 (0x23C00)
**	 WPFP_WPFP144		 Page 144 (0x24000)
**	 WPFP_WPFP145		 Page 145 (0x24400)
**	 WPFP_WPFP146		 Page 146 (0x24800)
**	 WPFP_WPFP147		 Page 147 (0x24C00)
**	 WPFP_WPFP148		 Page 148 (0x25000)
**	 WPFP_WPFP149		 Page 149 (0x25400)
**	 WPFP_WPFP150		 Page 150 (0x25800)
**	 WPFP_WPFP151		 Page 151 (0x25C00)
**	 WPFP_WPFP152		 Page 152 (0x26000)
**	 WPFP_WPFP153		 Page 153 (0x26400)
**	 WPFP_WPFP154		 Page 154 (0x26800)
**	 WPFP_WPFP155		 Page 155 (0x26C00)
**	 WPFP_WPFP156		 Page 156 (0x27000)
**	 WPFP_WPFP157		 Page 157 (0x27400)
**	 WPFP_WPFP158		 Page 158 (0x27800)
**	 WPFP_WPFP159		 Page 159 (0x27C00)
**	 WPFP_WPFP160		 Page 160 (0x28000)
**	 WPFP_WPFP161		 Page 161 (0x28400)
**	 WPFP_WPFP162		 Page 162 (0x28800)
**	 WPFP_WPFP163		 Page 163 (0x28C00)
**	 WPFP_WPFP164		 Page 164 (0x29000)
**	 WPFP_WPFP165		 Page 165 (0x29400)
**	 WPFP_WPFP166		 Page 166 (0x29800)
**	 WPFP_WPFP167		 Page 167 (0x29C00)
**	 WPFP_WPFP168		 Page 168 (0x2A000)
**	 WPFP_WPFP169		 Page 169 (0x2A400)
**	 WPFP_WPFP170		 Page 170 (0x2A800)
**	 WPFP_WPFP511		 Highest Page (same as page 170)
**
**   Segment Write Protection Disable bit:
**	 WPDIS_WPEN		   Segmented code protection enabled
**	 WPDIS_WPDIS		  Segmented code protection disabled
**
**   Configuration Word Code Page Protection Select bit:
**	 WPCFG_WPCFGEN		Last page and Flash configuration words are code-protected
**	 WPCFG_WPCFGDIS	   Last page(at the top of program memory) and Flash configuration words are not protected
**
**   Segment Write Protection End Page Select bit:
**	 WPEND_WPSTARTMEM	 Write Protect from page 0 to WPFP
**	 WPEND_WPENDMEM	   Write Protect from WPFP to the last page of memory
**
*/

/* Register CONFIG2 (0x2abfc)							   */

//extern __attribute__((space(prog))) int _CONFIG2;
//#define _CONFIG2(x) __attribute__((section("__CONFIG2.sec"),space(prog))) int _CONFIG2 = (x);

/*
** Only one invocation of CONFIG2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG2.
** Multiple options may be combined, as shown:
**
** _CONFIG2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Primary Oscillator Select:
**	 POSCMOD_EC		   EC oscillator mode selected
**	 POSCMOD_XT		   XT oscillator mode selected
**	 POSCMOD_HS		   HS oscillator mode selected
**	 POSCMOD_NONE		 Primary oscillator disabled
**
**   Internal USB 3.3V Regulator Disable bit:
**	 DISUVREG_ON		  Regulator is enabled
**	 DISUVREG_OFF		 Regulator is disabled
**
**   IOLOCK One-Way Set Enable bit:
**	 IOL1WAY_OFF		  Unlimited Writes To RP Registers
**	 IOL1WAY_ON		   Write RP Registers Once
**
**   Primary Oscillator Output Function:
**	 OSCIOFNC_ON		  OSCO functions as port I/O (RC15)
**	 OSCIOFNC_OFF		 OSCO functions as CLKO (FOSC/2)
**
**   Clock Switching and Monitor:
**	 FCKSM_CSECME		 Both Clock switching and Fail-safe Clock Monitor are enabled
**	 FCKSM_CSECMD		 Clock switching is enabled, Fail-safe Clock Monitor is disabled
**	 FCKSM_CSDCMD		 Both Clock Switching and Fail-safe Clock Monitor are disabled
**
**   Oscillator Select:
**	 FNOSC_FRC			Fast RC Oscillator (FRC)
**	 FNOSC_FRCPLL		 Fast RC oscillator with Postscaler and PLL module (FRCPLL)
**	 FNOSC_PRI			Primary oscillator (XT, HS, EC)
**	 FNOSC_PRIPLL		 Primary oscillator (XT, HS, EC) with PLL module (XTPLL,HSPLL, ECPLL)
**	 FNOSC_SOSC		   Secondary oscillator (SOSC)
**	 FNOSC_LPRC		   Low-Power RC oscillator (LPRC)
**	 FNOSC_FRCDIV		 Fast RC oscillator with Postscaler (FRCDIV)
**
**   96MHz PLL Disable:
**	 PLL_96MHZ_ON		 Enabled
**
**   USB 96 MHz PLL Prescaler Select bits:
**	 PLLDIV_NODIV		 Oscillator input used directly (4MHz input)
**	 PLLDIV_DIV2		  Oscillator input divided by 2 (8MHz input)
**	 PLLDIV_DIV3		  Oscillator input divided by 3 (12MHz input)
**	 PLLDIV_DIV4		  Oscillator input divided by 4 (16MHz input)
**	 PLLDIV_DIV5		  Oscillator input divided by 5 (20MHz input)
**	 PLLDIV_DIV6		  Oscillator input divided by 6 (24MHz input)
**	 PLLDIV_DIV10		 Oscillator input divided by 10 (40MHz input)
**	 PLLDIV_DIV12		 Oscillator input divided by 12 (48MHz input)
**
**   Internal External Switch Over Mode:
**	 IESO_OFF			 IESO mode (Two-speed start-up)disabled
**	 IESO_ON			  IESO mode (Two-speed start-up) enabled
**
*/

/* Register CONFIG1 (0x2abfe)							   */

//extern __attribute__((space(prog))) int _CONFIG1;
//#define _CONFIG1(x) __attribute__((section("__CONFIG1.sec"),space(prog))) int _CONFIG1 = (x);

/*
** Only one invocation of CONFIG1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set CONFIG1.
** Multiple options may be combined, as shown:
**
** _CONFIG1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Watchdog Timer Postscaler:
**	 WDTPS_PS1			1:1
**	 WDTPS_PS2			1:2
**	 WDTPS_PS4			1:4
**	 WDTPS_PS8			1:8
**	 WDTPS_PS16		   1:16
**	 WDTPS_PS32		   1:32
**	 WDTPS_PS64		   1:64
**	 WDTPS_PS128		  1:128
**	 WDTPS_PS256		  1:256
**	 WDTPS_PS512		  1:512
**	 WDTPS_PS1024		 1:1,024
**	 WDTPS_PS2048		 1:2,048
**	 WDTPS_PS4096		 1:4,096
**	 WDTPS_PS8192		 1:8,192
**	 WDTPS_PS16384		1:16,384
**	 WDTPS_PS32768		1:32,768
**
**   WDT Prescaler:
**	 FWPSA_PR32		   Prescaler ratio of 1:32
**	 FWPSA_PR128		  Prescaler ratio of 1:128
**
**   Watchdog Timer Window:
**	 WINDIS_ON			Windowed Watchdog Timer enabled; FWDTEN must be 1
**	 WINDIS_OFF		   Standard Watchdog Timer enabled,(Windowed-mode is disabled)
**
**   Watchdog Timer Enable:
**	 FWDTEN_OFF		   Watchdog Timer is disabled
**	 FWDTEN_ON			Watchdog Timer is enabled
**
**   Comm Channel Select:
**	 ICS_PGx3			 Emulator functions are shared with PGEC3/PGED3
**	 ICS_PGx2			 Emulator functions are shared with PGEC2/PGED2
**	 ICS_PGx1			 Emulator functions are shared with PGEC1/PGED1
**
**   Set Clip On Emulation Mode:
**	 COE_ON			   Enabled
**	 COE_OFF			  Disabled
**
**   Background Debug:
**	 BKBUG_ON			 Device resets into Debug mode
**	 BKBUG_OFF			Device resets into Operational mode
**
**   General Code Segment Write Protect:
**	 GWRP_ON			  Writes to program memory are disabled
**	 GWRP_OFF			 Writes to program memory are allowed
**
**   General Code Segment Code Protect:
**	 GCP_ON			   Code protection is enabled for the entire program memory space
**	 GCP_OFF			  Code protection is disabled
**
**   JTAG Port Enable:
**	 JTAGEN_OFF		   JTAG port is disabled
**	 JTAGEN_ON			JTAG port is enabled
**
*/
#endif		//gb110

#endif		//C30


//global defines

//global variables
//declare pins
//ALL PINS ARE MAPPED, WHETHER THEY EXIST OR NOT
//SO MAKE SURE THAT THE PINS YOU PICKED ACTUALLY EXIST FOR YOUR PACKAGE
//Pin  0.. 7 -> GPIOA
//Pin  8..15 -> GPIOB
const PIN2GPIO GPIO_PinDef[]= {
#if defined(GPIOA)
	{GPIOA, 1<<0},						//PICduino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOA, 1<<1},						//PICduino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOA, 1<<2},						//PICduino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOA, 1<<3},						//PICduino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOA, 1<<4},						//PICduino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOA, 1<<5},						//PICduino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOA, 1<<6},						//PICduino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOA, 1<<7},						//PICduino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOA, 1<<8},						//PICduino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOA, 1<<9},						//PICduino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOA, 1<<10},						//PICduino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOA, 1<<11},						//PICduino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOA, 1<<12},						//PICduino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOA, 1<<13},						//PICduino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOA, 1<<14},						//PICduino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOA, 1<<15},						//PICduino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//gpioa

#if defined(GPIOB)
	{GPIOB, 1<<0},						//PICduino Pin 16 = RP0/PB0/CHIP PIN4
	{GPIOB, 1<<1},						//PICduino Pin 17 = RP1/PB1/CHIP PIN5
	{GPIOB, 1<<2},						//PICduino Pin 18 = RP2/PB2/CHIP PIN6
	{GPIOB, 1<<3},						//PICduino Pin 19 = RP3/PB3/CHIP PIN7
	{GPIOB, 1<<4},						//PICduino Pin 20 = RP4/PB4/CHIP PIN11
	{GPIOB, 1<<5},						//PICduino Pin 21 = RP5/PB5/CHIP PIN14
	{GPIOB, 1<<6},						//PICduino Pin 22 = RP6/PB6/CHIP PIN15
	{GPIOB, 1<<7},						//PICduino Pin 23 = RP7/PB7/CHIP PIN16
	{GPIOB, 1<<8},						//PICduino Pin 24 = RP8/PB8/CHIP PIN17
	{GPIOB, 1<<9},						//PICduino Pin 25 = RP9/PB9/CHIP PIN18
	{GPIOB, 1<<10},						//PICduino Pin 26 = RP10/PB10/CHIP PIN21
	{GPIOB, 1<<11},						//PICduino Pin 27 = RP11/PB11/CHIP PIN22
	{GPIOB, 1<<12},						//PICduino Pin 28 = RP12/PB12/CHIP PIN23
	{GPIOB, 1<<13},						//PICduino Pin 29 = RP13/PB13/CHIP PIN24
	{GPIOB, 1<<14},						//PICduino Pin 30 = RP14/PB14/CHIP PIN25
	{GPIOB, 1<<15},						//PICduino Pin 31 = RP15/PB15/CHIP PIN26
#endif	//gpiob

#if defined(GPIOC)
	{GPIOC, 1<<0},						//PICduino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOC, 1<<1},						//PICduino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOC, 1<<2},						//PICduino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOC, 1<<3},						//PICduino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOC, 1<<4},						//PICduino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOC, 1<<5},						//PICduino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOC, 1<<6},						//PICduino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOC, 1<<7},						//PICduino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOC, 1<<8},						//PICduino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOC, 1<<9},						//PICduino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOC, 1<<10},						//PICduino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOC, 1<<11},						//PICduino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOC, 1<<12},						//PICduino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOC, 1<<13},						//PICduino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOC, 1<<14},						//PICduino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOC, 1<<15},						//PICduino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOC

#if defined(GPIOD)
	{GPIOD, 1<<0},						//PICduino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOD, 1<<1},						//PICduino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOD, 1<<2},						//PICduino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOD, 1<<3},						//PICduino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOD, 1<<4},						//PICduino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOD, 1<<5},						//PICduino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOD, 1<<6},						//PICduino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOD, 1<<7},						//PICduino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOD, 1<<8},						//PICduino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOD, 1<<9},						//PICduino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOD, 1<<10},						//PICduino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOD, 1<<11},						//PICduino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOD, 1<<12},						//PICduino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOD, 1<<13},						//PICduino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOD, 1<<14},						//PICduino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOD, 1<<15},						//PICduino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOD

#if defined(GPIOE)
	{GPIOE, 1<<0},						//PICduino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOE, 1<<1},						//PICduino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOE, 1<<2},						//PICduino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOE, 1<<3},						//PICduino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOE, 1<<4},						//PICduino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOE, 1<<5},						//PICduino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOE, 1<<6},						//PICduino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOE, 1<<7},						//PICduino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOE, 1<<8},						//PICduino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOE, 1<<9},						//PICduino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOE, 1<<10},						//PICduino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOE, 1<<11},						//PICduino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOE, 1<<12},						//PICduino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOE, 1<<13},						//PICduino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOE, 1<<14},						//PICduino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOE, 1<<15},						//PICduino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOE

#if defined(GPIOF)
	{GPIOF, 1<<0},						//PICduino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOF, 1<<1},						//PICduino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOF, 1<<2},						//PICduino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOF, 1<<3},						//PICduino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOF, 1<<4},						//PICduino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOF, 1<<5},						//PICduino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOF, 1<<6},						//PICduino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOF, 1<<7},						//PICduino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOF, 1<<8},						//PICduino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOF, 1<<9},						//PICduino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOF, 1<<10},						//PICduino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOF, 1<<11},						//PICduino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOF, 1<<12},						//PICduino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOF, 1<<13},						//PICduino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOF, 1<<14},						//PICduino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOF, 1<<15},						//PICduino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOF

#if defined(GPIOG)
	{GPIOG, 1<<0},						//PICduino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOG, 1<<1},						//PICduino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOG, 1<<2},						//PICduino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOG, 1<<3},						//PICduino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOG, 1<<4},						//PICduino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOG, 1<<5},						//PICduino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOG, 1<<6},						//PICduino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOG, 1<<7},						//PICduino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOG, 1<<8},						//PICduino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOG, 1<<9},						//PICduino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOG, 1<<10},						//PICduino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOG, 1<<11},						//PICduino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOG, 1<<12},						//PICduino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOG, 1<<13},						//PICduino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOG, 1<<14},						//PICduino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOG, 1<<15},						//PICduino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOG

};

//set up core timer
//global variables
uint32_t SystemCoreClock=F_FRC;			//system core clock, before devided by 2. Updated by SystemCoreClockUpdate()

//for time base off TIMER1 @ 1:1 prescaler
//volatile uint32_t timer1_millis = 0;
volatile uint32_t systick_ovf = 0;
//static uint16_t timer1_fract = 0;
//111 = Fast RC Oscillator with Postscaler (FRCDIV)
//110 = Reserved
//101 = Low-Power RC Oscillator (LPRC)
//100 = Secondary Oscillator (SOSC)
//011 = Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
//010 = Primary Oscillator (XT, HS, EC)
//001 = Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
//000 = Fast RC Oscillator (FRC)
//Needs to be executed during mcu initialization or after oscillator reconfiguration
//updates SystemCoreClock.
uint32_t SystemCoreClockUpdate(void) {
	uint32_t tmp=F_FRC;

	//test for current oscillator configuration
	switch (OSCCONbits.COSC) {
	case 0b111:						//FRCDIV
		tmp = (F_FRC >> CLKDIVbits.RCDIV);
		break;
	case 0b110:						//reserved
		break;
	case 0b101:						//LPRC
		tmp = F_LPRC;
		break;
	case 0b100:						//SOSC
		tmp = F_SOSC;
		break;
	case 0b011:						//POSCxPLL
		tmp = F_XTAL * 4;
		break;
	case 0b010:						//POSC
		tmp = F_XTAL;
		break;
	case 0b001:						//FRCxPLL
		tmp = (F_FRC >> CLKDIVbits.RCDIV) * 4;
		break;
	case 0b000:						//FRC
		tmp = F_FRC;
		break;
	}
	return SystemCoreClock=tmp;
}

//switch oscillator
//return SystemCoreClock in frequency
//111 = Fast RC Oscillator with Postscaler (FRCDIV)
//110 = Reserved
//101 = Low-Power RC Oscillator (LPRC)
//100 = Secondary Oscillator (SOSC)
//011 = Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
//010 = Primary Oscillator (XT, HS, EC)
//001 = Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
//000 = Fast RC Oscillator (FRC)
//Needs to be executed during mcu initialization or after oscillator reconfiguration
//updates SystemCoreClock.
uint32_t SystemCoreClockSwitch(uint8_t nosc) {
	//uint32_t tmp=F_FRC;

	nosc = nosc & 0b111;						//3 bits effective
	//switch oscillator - not yet implemented
	di();										//disable the interrupt
	do {
		__builtin_write_OSCCONH(nosc);
		__builtin_write_OSCCONL(OSCCON | (1<<0));	//set oswen bit -> start the switch
		while (OSCCONbits.OSWEN != 0) continue;		//0->clock switch complete
	} while (OSCCONbits.COSC != nosc);
	ei();										//enable the interrupt
	//if pll is involved, wait for it to lock
	if ((nosc == 0b001) || (nosc == 0b011)) while (OSCCONbits.LOCK == 0) continue;
	return SystemCoreClockUpdate();				//update the core clock
}

//timer1 overflow isr
//void _ISR_PSV _T2Interrupt(void) {
//	IFS0bits.T2IF=0;							//clear tmr1 interrupt flag
//	systick_ovf+=0x10000ul;							//increment overflow count: 16-bit timer
//}

//reset the mcu
void mcuInit(void) {
	volatile uint32_t i=100000ul; while (i--) continue;	//for debugging

	//switch clock - not all clock sources show (LPRC)
	//SystemCoreClockFRC();						//switch to FRC
	//SystemCoreClockFRCPLL();					//switch to FRCxPLL
	//SystemCoreClockPOSC();					//switch to primary oscillator
	//SystemCoreClockPOSCPLL();					//switch to primary oscillator x PLL

#if defined(FRCTRIM)
	FRCSetTrim(FRCTRIM);						//tune the frc
#endif	//frctrim

	//powering up on FRC (default)
	//set poster scaler for FRC (default 2:1), for FRCDIV
	CLKDIVbits.RCDIV=1;							//rc divider (0..7->1:1..128:1): 0->1:1, 1->2:1 (default), 2->4:1, 3=8:1, ...

	//turn off all peripherals by setting the bits to 1
	PMD1=0xffff;
	PMD2=0xffff;
	PMD3=0xffff;
//#if defined(PMD4)		- only on GA102/GB002
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined(__PIC24FJ32GA102__) | \
			defined(__PIC24FJ64GA104__) | defined(__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	PMD4=0xffff;
#endif

	//all pins digital
	AD1PCFG = 0xffff;							//1->all pins digital

#if defined(SYSTICK_TMR1)						//Systick running on tmr1
	//initialize tmr1 for tick/pwm generation - do not stop this
	//PMD1bits.T1MD = 0;							//0->enable the peripheral, 1->disable the peripheral
	tmr1Init(TMR_PS1x);							//reset timer
	IFS0bits.T1IF = 0;							//reset the flag
	IPC0bits.T1IP = TxIP_DEFAULT;
	//IPC0bits.T2IS = TxIS_DEFAULT;
	IEC0bits.T1IE = 1;							//0->disable tmr2 isr, 1->enable tmr2 isr
	//T1CONbits.TON = 1;			 			//turn on the timer
#else											//systick running on tmr2
	//initialize tmr2 for tick/pwm generation - do not stop this
	//PMD1bits.T2MD = 0;							//0->enable the peripheral, 1->disable the peripheral
	tmr2Init(TMR_PS1x);							//reset timer
	IFS0bits.T2IF = 0;							//reset the flag
	IPC1bits.T2IP = TxIP_DEFAULT;
	//IPC1bits.T2IS = TxIS_DEFAULT;
	IEC0bits.T2IE = 1;							//0->disable tmr2 isr, 1->enable tmr2 isr
	//T2CONbits.TON = 1;			 				//turn on the timer
#endif		//systick on tmr1 or tmr2

	//update SystemCoreClock
	SystemCoreClockUpdate();					//update system core clock

	//enable global interrupts
	ei();										//testing

}

//empty interrupt handler
void empty_handler(void) {
	//do nothing here
}

//C main loop
#ifndef USE_MAIN
int main(void) {

	mcuInit();						//reset the mcu
	setup();						//run the setup code
	while (1) {
		loop();						//run the default loop
	}
}
#endif	//use_main

//Arduino Functions: GPIO
void pinPullup(PIN_TypeDef pin) {
   	switch (pin) {
   		case PA4: REG_SET(CNPU1, 1<<0 ); break;	//PA4=CN0
   		case PB4: REG_SET(CNPU1, 1<<1 ); break;	//PB4=CN1
   		case PA0: REG_SET(CNPU1, 1<<2 ); break;	//PA0=CN2
   		case PA1: REG_SET(CNPU1, 1<<3 ); break;	//PA1=CN3
   		case PB0: REG_SET(CNPU1, 1<<4 ); break;	//PB0=CN4
   		case PB1: REG_SET(CNPU1, 1<<5 ); break;	//PB1=CN5
   		case PB2: REG_SET(CNPU1, 1<<6 ); break;	//PB2=CN6
   		case PB3: REG_SET(CNPU1, 1<<7 ); break;	//PB3=CN7
#if defined(GPIOC)
   		case PC0: REG_SET(CNPU1, 1<<8 ); break;	//PC0=CN8
   		case PC1: REG_SET(CNPU1, 1<<9 ); break;	//PC1=CN9
   		case PC2: REG_SET(CNPU1, 1<<10); break;	//PC2=CN10
#endif
   		case PB15:REG_SET(CNPU1, 1<<11); break;	//PB15=CN11
   		case PB14:REG_SET(CNPU1, 1<<12); break;	//PB14=CN12
   		case PB13:REG_SET(CNPU1, 1<<13); break;	//PB13=CN13
   		case PB12:REG_SET(CNPU1, 1<<14); break;	//PB12=CN14
   		case PB11:REG_SET(CNPU1, 1<<15); break;	//PB11=CN15
   		case PB10:REG_SET(CNPU2, 1<<0 ); break;	//PB10=CN16
#if defined(GPIOC)
   		case PC7: REG_SET(CNPU2, 1<<1 ); break;	//PC7=CN17
   		case PC6: REG_SET(CNPU2, 1<<2 ); break;	//PC6=CN18
   		case PC9: REG_SET(CNPU2, 1<<3 ); break;	//PC9=CN19
   		case PC8: REG_SET(CNPU2, 1<<4 ); break;	//PC8=CN20
#endif
   		case PB9: REG_SET(CNPU2, 1<<5 ); break;	//PB9=CN21
   		case PB8: REG_SET(CNPU2, 1<<6 ); break;	//PB8=CN22
   		case PB7: REG_SET(CNPU2, 1<<7 ); break;	//PB7=CN23
   		case PB6: REG_SET(CNPU2, 1<<8 ); break;	//PB6=CN24
#if defined(GPIOC)
   		case PC4: REG_SET(CNPU2, 1<<0 ); break;	//PC4=CN25
   		case PC5: REG_SET(CNPU2, 1<<10); break;	//PC5=CN26
#endif
   		case PB5: REG_SET(CNPU2, 1<<11); break;	//PB5=CN27
#if defined(GPIOC)
   		case PC3: REG_SET(CNPU2, 1<<12); break;	//PC3=CN28
#endif
   		case PA3: REG_SET(CNPU2, 1<<13); break;	//PA3=CN29
   		case PA2: REG_SET(CNPU2, 1<<14); break;	//PA2=CN30
   		//case PB5: REG_SET(CNPU2, 1<<15); break;	//PC3=CN31
   		default: break;							//do nothing if the pin isn't a CN pin
   	};
}

//enable pulldown - not available on pic24
void pinPulldown(PIN_TypeDef pin) {
}


//set a pin mode to INPUT or OUTPUT
//no error checking on PIN
inline void pinMode(PIN_TypeDef pin, uint8_t mode) {
	//if (mode==OUTPUT) GIO_OUT(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
	//else GIO_IN(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
	GPIO_TypeDef *gpio = GPIO_PinDef[pin].gpio;
	uint16_t mask = GPIO_PinDef[pin].mask;

	switch (mode) {
		case INPUT_PULLUP:		pinPullup(pin);	IO_IN(gpio, mask); break;
		case INPUT_PULLDOWN: 	pinPulldown(pin); IO_IN(gpio, mask); break;
		case INPUT:				GIO_IN(gpio, mask); break;
		case OUTPUT_OD:			pinPullup(pin);	REG_SET(gpio->ODC, mask); IO_OUT(gpio, mask); break;
		case OUTPUT:			IO_OUT(gpio, mask); break;
		default: 				break;
	}
}

//set / clear a pin
inline void digitalWrite(PIN_TypeDef pin, uint8_t val) {
	GPIO_TypeDef *gpio = GPIO_PinDef[pin].gpio;
	uint16_t mask = GPIO_PinDef[pin].mask;
	if (val==LOW) GIO_CLR(gpio, mask); else IO_SET(gpio, mask);
}

//read a pin
inline int digitalRead(PIN_TypeDef pin) {
	return (GIO_GET(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask))?HIGH:LOW;
}
//end GPIO

//ticks()
//Arduino Functions: Time
//return timer ticks
uint32_t systicks(void) {
	volatile uint32_t m;					//stores overflow count
	volatile uint16_t f;					//return the fractions / TMR1 value

	//use double reads
	do {
		m = systick_ovf;
#if defined(SYSTICK_TMR1)
		f = TMR1;
#else
		f = TMR2;
#endif
	} while (m != systick_ovf);
	//now m and f are consistent
	return (m | f);
}

//delay millisseconds
//void delay(uint32_t ms) {
//	uint32_t start_time = ticks();
//	ms *= cyclesPerMillisecond();
//	while (ticks() - start_time < ms) continue;
//}

//delay micros seconds
//void delayMicroseconds(uint32_t us) {
//	uint32_t start_time = ticks();
//	us *= cyclesPerMicrosecond();
//	while (ticks() - start_time < us) continue;
//}

//delay ticks
void delayTks(uint32_t tks) {
	uint32_t start_time = ticks();
	while (ticks() - start_time < tks) continue;
}
//end Time

//generic print to uart buffer
void uPrint(char *uRAM, int32_t dat) {
	uint8_t idx=20;						//buffer index
	uint8_t negFlag=0;					//flag for negative sign: 1->negative, 0->positive

	if (dat<0) {negFlag = 1; dat = -dat;}
#if 0	//10k/invocation
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
	uRAM[idx--]=',';	//'0'+(dat % 10); dat /= 10;
	uRAM[idx--]='0'+(dat % 10); dat /= 10;
#else	//6k/invocation
	uint32_t tmp;

	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	                      uRAM[idx--]=',';
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	                      uRAM[idx--]=',';
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
	                      uRAM[idx--]=',';
	tmp = dat; dat /= 10; uRAM[idx--]='0'+(tmp - dat * 10);
#endif
	uRAM[idx--]=negFlag?'-':' ';
}

//static char uRAM[uRAM_SIZE];			//transmission buffer
//uart1
#if defined(UART1_TXISR)
CB_TypeDef U1TXBuf;					//circular buffer for uart tx
//uart2 isr
volatile char *_U1TX_ptr;
//volatile unsigned char _U2TX_BUSY=0;	//0=u1 transmission done, 1=u1 transmission in process

//ux transmit isr
//'\0' is now transmitted
//void _ISR _U1TXInterrupt(void) {
void _ISR_PSV _U1TXInterrupt(void) {
	//char tmp;
	//TX only, RX not implemented
	IFS0bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
	if (!cbEmpty(&U1TXBuf)) {		//if (*_U1TX_ptr) {					//0 indicates the end of the string
		//_UxTX_ptr;					//increment to the next char
		//tmp = *_UxTX_ptr++; UxTXREG = tmp;
		U1TXREG = cbRead(&U1TXBuf);	//U1TXREG = *_U1TX_ptr++;			//load up a char to be transmitted
		//NOP();
		//IFS1bits.U2TXIF = 0;			//UxTXIF = 0;						//clear the flag
	} else {
		//UxSTA.UTXEN = 0;				//turn off the transmission
		IEC0bits.U1TXIE = 0;			//UxTXIE = 0;						//disable the interrupt
		//_U1TX_BUSY = 0;				//transmission done
	}
	//IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
}
#endif		//UART1_TXISR

//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart1Init(unsigned long baud_rate) {
	//enable the pins
#if defined(U1RX2RP)
	U1RX2RP();					//PPS_U1RX_TO_RP(U1RX_RP);
#endif

#if defined(U1TX2RP)
	U1TX2RP();					//PPS_U1TX_TO_RP();
#endif

#if defined(UART1_TXISR)
	cbInit(&U1TXBuf);				//initialize circular buffer for tx
#endif	//txisr

	//disable md bits
	PMD1bits.U1MD = 0;				//power up the module

	//U2MODEbits register
	//bit 15 UARTEN: UARTx Enable bit(1)
	//1 = UARTx is enabled; all UARTx pins are controlled by UARTx as defined by UEN<1:0>
	//0 = UARTx is disabled; all UARTx pins are controlled by PORT latches; UARTx power consumption is	minimal
	U1MODEbits.UARTEN=1;	//enable the uart module
	//bit 14 Unimplemented: Read as `0'
	//bit 13 USIDL: Stop in Idle Mode bit
	//1 = Discontinue module operation when device enters Idle mode
	//0 = Continue module operation in Idle mode
	//bit 12 IREN: IrDAr Encoder and Decoder Enable bit(2)
	//1 = IrDA encoder and decoder enabled
	//0 = IrDA encoder and decoder disabled
	U1MODEbits.IREN = 0;		//disable irda
	U1MODEbits.RTSMD = 0;		//1=in simplex mode. 0 = no flow control
	//bit 11 RTSMD: Mode Selection for UxRTS Pin bit
	//1 = UxRTS pin in Simplex mode
	//0 = UxRTS pin in Flow Control mode
	//bit 10 Unimplemented: Read as `0'
	//bit 9-8 UEN1:UEN0: UARTx Enable bits(3)
	//11 = UxTX, UxRX and BCLKx pins are enabled and used; UxCTS pin controlled by PORT latches
	//10 = UxTX, UxRX, UxCTS and UxRTS pins are enabled and used
	//01 = UxTX, UxRX and UxRTS pins are enabled and used; UxCTS pin controlled by PORT latches
	//00 = UxTX and UxRX pins are enabled and used; UxCTS and UxRTS/BCLKx pins controlled by PORT latches
	U1MODEbits.UEN1=0, U2MODEbits.UEN0=0;
	//bit 7 WAKE: Wake-up on Start Bit Detect During Sleep Mode Enable bit
	//1 = UARTx will continue to sample the UxRX pin; interrupt generated on falling edge, bit cleared in hardware on following rising edge
	//0 = No wake-up enabled
	U1MODEbits.WAKE = 0;
	//bit 6 LPBACK: UARTx Loopback Mode Select bit
	//1 = Enable Loopback mode
	//0 = Loopback mode is disabled
	U1MODEbits.LPBACK = 0;
	//bit 5 ABAUD: Auto-Baud Enable bit
	//1 = Enable baud rate measurement on the next character - requires reception of a Sync field (55h); cleared in hardware upon completion
	//0 = Baud rate measurement disabled or completed
	U1MODEbits.ABAUD = 0;
	//bit 4 RXINV: Receive Polarity Inversion bit
	//1 = UxRX Idle state is `0'
	//0 = UxRX Idle state is `1'
	U1MODEbits.RXINV = 0;
	//bit 3 BRGH: High Baud Rate Enable bit
	//1 = BRG generates 4 clocks per bit period (4x baud clock, High-Speed mode)
	//0 = BRG generates 16 clocks per bit period (16x baud clock, Standard mode)
	U1MODEbits.BRGH = (F_UART / 4 / baud_rate < 0xffff)?1:0;	//U1MODEbits.BRGH = 1;
	//bit 2-1 PDSEL1:PDSEL0: Parity and Data Selection bits
	//11 = 9-bit data, no parity
	//10 = 8-bit data, odd parity
	//01 = 8-bit data, even parity
	//00 = 8-bit data, no parity
	U1MODEbits.PDSEL1=0, U1MODEbits.PDSEL0=0;
	//bit 0 STSEL: Stop Bit Selection bit
	//1 = Two Stop bits
	//0 = One Stop bit
	U1MODEbits.STSEL=0;
	//Note 1: If UARTEN = 1, the peripheral inputs and outputs must be configured to an available RPn pin. See
	//Section 10.4 "Peripheral Pin Select" for more information.
	//2: This feature is only available for the 16x BRG mode (BRGH = 0).
	//3: Bit availability depends on pin availability.


#if 1	//BAUDCON - with rounding up
	if (U1MODEbits.BRGH==1) U1BRG = (F_UART + 2 * baud_rate) / 4 / baud_rate - 1;				//set lower byte of brg
	else U1BRG = (F_UART + 8 * baud_rate) / 16 / baud_rate - 1;
#else	//BAUDCON - without rounding up
	if (U1MODEbits.BRGH==1) U1BRG = (F_UART + 0*2 * baud_rate) / 4 / baud_rate - 1;				//set lower byte of brg
	else U1BRG = (F_UART + 0*8 * baud_rate) / 16 / baud_rate - 1;
#endif	//1
	//disable interrupts

	//set up status register
//#if defined(UxTX2RP)				//tx is used
	IFS0bits.U1TXIF = 0;						//clera the flag
	IEC0bits.U1TXIE = 0;						//disable the interrupt
	IPC3bits.U1TXIP = UxIP_DEFAULT;				//default priority

	//bit 15,13 UTXISEL1:UTXISEL0: Transmission Interrupt Mode Selection bits
	//11 = Reserved; do not use
	//10 = Interrupt when a character is transferred to the Transmit Shift Register (TSR) and as a result, the transmit buffer becomes empty
	//01 = Interrupt when the last character is shifted out of the Transmit Shift Register; all transmit operations are completed
	//00 = Interrupt when a character is transferred to the Transmit Shift Register (this implies there is at least one character open in the transmit buffer)
	U1STAbits.UTXISEL1=0, U1STAbits.UTXISEL0=0;
//#endif
	//bit 14 UTXINV: IrDAr Encoder Transmit Polarity Inversion bit
	//If IREN = 0:
	//1 = UxTX Idle `0'
	//0 = UxTX Idle `1'
	//If IREN = 1:
	//1 = UxTX Idle `1'
	//0 = UxTX Idle `0'
	U1STAbits.UTXINV=0;
	//bit 12 Unimplemented: Read as `0'
	//bit 11 UTXBRK: Transmit Break bit
	//1 = Send Sync Break on next transmission - Start bit, followed by twelve `0' bits, followed by Stop bit;	cleared by hardware upon completion
	//0 = Sync Break transmission disabled or completed
	U1STAbits.UTXBRK=0;
	//bit 10 UTXEN: Transmit Enable bit(1)
	//1 = Transmit enabled, UxTX pin controlled by UARTx
	//0 = Transmit disabled, any pending transmission is aborted and buffer is reset. UxTX pin controlled by the PORT register.
#if defined(U1TX2RP)
	U1STAbits.UTXEN=1;
#else
	U1STAbits.UTXEN=0;
#endif
#if defined(U1RX2RP)
	//U1STAbits.URXEN=1;
#else
	//U1STAbits.URXEN=0;
#endif
	//bit 9 UTXBF: Transmit Buffer Full Status bit (read-only)
	//1 = Transmit buffer is full
	//0 = Transmit buffer is not full, at least one more character can be written
	//bit 8 TRMT: Transmit Shift Register Empty bit (read-only)
	//1 = Transmit Shift Register is empty and transmit buffer is empty (the last transmission has completed)
	//0 = Transmit Shift Register is not empty, a transmission is in progress or queued
//#if defined(UxRX2RP)
	IFS0bits.U1RXIF = 0;						//clear the flag
	IEC0bits.U1RXIE = 0;						//disable the interrupt

	//bit 7-6 URXISEL1:URXISEL0: Receive Interrupt Mode Selection bits
	//11 = Interrupt is set on RSR transfer, making the receive buffer full (i.e., has 4 data characters)
	//10 = Interrupt is set on RSR transfer, making the receive buffer 3/4 full (i.e., has 3 data characters)
	//0x = Interrupt is set when any character is received and transferred from the RSR to the receive buffer. Receive buffer has one or more characters.
	U1STAbits.URXISEL1 = 0, U1STAbits.URXISEL0 = 0;
//#endif
	//bit 5 ADDEN: Address Character Detect bit (bit 8 of received data = 1)
	//1 = Address Detect mode enabled. If 9-bit mode is not selected, this does not take effect.
	//0 = Address Detect mode disabled
	//bit 4 RIDLE: Receiver Idle bit (read-only)
	//1 = Receiver is Idle
	//0 = Receiver is active
	//bit 3 PERR: Parity Error Status bit (read-only)
	//1 = Parity error has been detected for the current character (character at the top of the receive FIFO)
	//0 = Parity error has not been detected
	//bit 2 FERR: Framing Error Status bit (read-only)
	//1 = Framing error has been detected for the current character (character at the top of the receive FIFO)
	//0 = Framing error has not been detected
	//bit 1 OERR: Receive Buffer Overrun Error Status bit (clear/read-only)
	//1 = Receive buffer has overflowed
	//0 = Receive buffer has not overflowed (clearing a previously set OERR bit (1 ? 0 transition) will reset the receiver buffer and the RSR to the empty state)
	//bit 0 URXDA: Receive Buffer Data Available bit (read-only)
	//1 = Receive buffer has data; at least one more character can be read
	//0 = Receive buffer is empty
	//REGISTER 17-2: U1STAbits: UARTx STATUS AND CONTROL REGISTER (CONTINUED)
	//Note 1: If UARTEN = 1, the peripheral inputs and outputs must be configured to an available RPn pin. See
	//Section 10.4 "Peripheral Pin Select" for more information.

}

//put a string
void uart1Puts(char *str) {
#if defined(UART1_TXISR)
	//interrupt transmission
	if (*str) {								//if the string isn't empty to begin with
		//uart1Wait();						//for compatability with polling transmission
		//U1TXREG = 0;						//clear the buffer
		//_U1TX_BUSY  = 1;					//transmission in progress
		str2cb(&U1TXBuf, str);				//_U1TX_ptr=str;						//point to the string to be transmitted
		//U1STAbits.UTXEN = 1;				//enable transmission - always enabled
		//tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
		IFS0bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
		IEC0bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
		U1TXREG = cbRead(&U1TXBuf);			//U1TXREG = *_U1TX_ptr++;
	}
#else
	//polling implementation
	while(*str) {
		uart1Putch(*str++);	//send the ch and advance the pointer
	}
#endif	//uart1_txisr
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
//void uart1Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart1Puts(ln);
//	//USARTWriteString("\r\n");
//	uart1Puts((char *)"\r\n");
//}

//get the received char
//uint8_t uart1Getch(void) {
//	return U1RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart1Available(void) {
//	return U1STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart1Busy(void) {
//	return U1STAbits.UTXBF;
//}


//print to uart1
void u1Print(char *str, int32_t dat) {
	/*static*/ char uRAM[uRAM_SIZE];						//transmission buffer, 40-1 char max

	//uart1Wait();						//wait for uart to free up

	strcpy(uRAM, str);					//copy to uarm
	uPrint(uRAM, dat);					//print to ubuffer
	uart1Puts(uRAM);					//send a message on uart1
}

//uart2
#if defined(UART2_TXISR)

CB_TypeDef U2TXBuf;					//circular buffer for uart tx
//uart2 isr
volatile char *_U2TX_ptr;
//volatile unsigned char _U2TX_BUSY=0;	//0=u1 transmission done, 1=u1 transmission in process

//ux transmit isr
//'\0' is now transmitted
//void _ISR _U1TXInterrupt(void) {
void _ISR_PSV _U2TXInterrupt(void) {
	//char tmp;
	//TX only, RX not implemented
	IFS1bits.U2TXIF = 0;				//UxTXIF = 0;							//clear the flag
	if (!cbEmpty(&U2TXBuf)) {		//if (*_U2TX_ptr) {					//0 indicates the end of the string
		//_UxTX_ptr;					//increment to the next char
		//tmp = *_UxTX_ptr++; UxTXREG = tmp;
		U2TXREG = cbRead(&U2TXBuf);	//U2TXREG = *_U2TX_ptr++;			//load up a char to be transmitted
		//NOP();
		//IFS1bits.U2TXIF = 0;			//UxTXIF = 0;						//clear the flag
	} else {
		//UxSTA.UTXEN = 0;				//turn off the transmission
		IEC1bits.U2TXIE = 0;			//UxTXIE = 0;						//disable the interrupt
		//_U1TX_BUSY = 0;				//transmission done
	}
	//IFS1bits.U2TXIF = 0;				//UxTXIF = 0;							//clear the flag
}
#endif		//UART2_TXISR

//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart2Init(unsigned long baud_rate) {
	//enable the pins
#if defined(U2RX2RP)
	U2RX2RP();					//PPS_U1RX_TO_RP(U1RX_RP);
#endif

#if defined(U2TX2RP)
	U2TX2RP();					//PPS_U1TX_TO_RP();
#endif

#if defined(UART2_TXISR)
	cbInit(&U2TXBuf);				//initialize circular buffer for tx
#endif	//txisr

	//disable md bits
	PMD1bits.U2MD = 0;				//power up the module

	//U2MODEbits register
	//bit 15 UARTEN: UARTx Enable bit(1)
	//1 = UARTx is enabled; all UARTx pins are controlled by UARTx as defined by UEN<1:0>
	//0 = UARTx is disabled; all UARTx pins are controlled by PORT latches; UARTx power consumption is	minimal
	U2MODEbits.UARTEN=1;	//enable the uart module
	//bit 14 Unimplemented: Read as `0'
	//bit 13 USIDL: Stop in Idle Mode bit
	//1 = Discontinue module operation when device enters Idle mode
	//0 = Continue module operation in Idle mode
	//bit 12 IREN: IrDAr Encoder and Decoder Enable bit(2)
	//1 = IrDA encoder and decoder enabled
	//0 = IrDA encoder and decoder disabled
	U2MODEbits.IREN = 0;		//disable irda
	U2MODEbits.RTSMD = 0;		//1=in simplex mode. 0 = no flow control
	//bit 11 RTSMD: Mode Selection for UxRTS Pin bit
	//1 = UxRTS pin in Simplex mode
	//0 = UxRTS pin in Flow Control mode
	//bit 10 Unimplemented: Read as `0'
	//bit 9-8 UEN1:UEN0: UARTx Enable bits(3)
	//11 = UxTX, UxRX and BCLKx pins are enabled and used; UxCTS pin controlled by PORT latches
	//10 = UxTX, UxRX, UxCTS and UxRTS pins are enabled and used
	//01 = UxTX, UxRX and UxRTS pins are enabled and used; UxCTS pin controlled by PORT latches
	//00 = UxTX and UxRX pins are enabled and used; UxCTS and UxRTS/BCLKx pins controlled by PORT latches
	U2MODEbits.UEN1=0, U2MODEbits.UEN0=0;
	//bit 7 WAKE: Wake-up on Start Bit Detect During Sleep Mode Enable bit
	//1 = UARTx will continue to sample the UxRX pin; interrupt generated on falling edge, bit cleared in hardware on following rising edge
	//0 = No wake-up enabled
	U2MODEbits.WAKE = 0;
	//bit 6 LPBACK: UARTx Loopback Mode Select bit
	//1 = Enable Loopback mode
	//0 = Loopback mode is disabled
	U2MODEbits.LPBACK = 0;
	//bit 5 ABAUD: Auto-Baud Enable bit
	//1 = Enable baud rate measurement on the next character - requires reception of a Sync field (55h); cleared in hardware upon completion
	//0 = Baud rate measurement disabled or completed
	U2MODEbits.ABAUD = 0;
	//bit 4 RXINV: Receive Polarity Inversion bit
	//1 = UxRX Idle state is `0'
	//0 = UxRX Idle state is `1'
	U2MODEbits.RXINV = 0;
	//bit 3 BRGH: High Baud Rate Enable bit
	//1 = BRG generates 4 clocks per bit period (4x baud clock, High-Speed mode)
	//0 = BRG generates 16 clocks per bit period (16x baud clock, Standard mode)
	U2MODEbits.BRGH = (F_UART / 4 / baud_rate < 0xffff)?1:0;		//U2MODEbits.BRGH = 1;
	//bit 2-1 PDSEL1:PDSEL0: Parity and Data Selection bits
	//11 = 9-bit data, no parity
	//10 = 8-bit data, odd parity
	//01 = 8-bit data, even parity
	//00 = 8-bit data, no parity
	U2MODEbits.PDSEL1=0, U2MODEbits.PDSEL0=0;
	//bit 0 STSEL: Stop Bit Selection bit
	//1 = Two Stop bits
	//0 = One Stop bit
	U2MODEbits.STSEL=0;
	//Note 1: If UARTEN = 1, the peripheral inputs and outputs must be configured to an available RPn pin. See
	//Section 10.4 "Peripheral Pin Select" for more information.
	//2: This feature is only available for the 16x BRG mode (BRGH = 0).
	//3: Bit availability depends on pin availability.


#if 1	//BAUDCON - with rounding up
	if (U2MODEbits.BRGH==1) U2BRG = (F_UART + 2 * baud_rate) / 4 / baud_rate - 1;				//set lower byte of brg
	else U2BRG = (F_UART + 8 * baud_rate) / 16 / baud_rate - 1;
#else	//BAUDCON - without rounding up
	if (U2MODEbits.BRGH==1) U2BRG = (F_UART + 0*2 * baud_rate) / 4 / baud_rate - 1;				//set lower byte of brg
	else U2BRG = (F_UART + 0*8 * baud_rate) / 16 / baud_rate - 1;
#endif	//1
	//disable interrupts
//#if defined(UxTX2RP)
	IFS1bits.U2TXIF = 0;						//clera the flag
	IEC1bits.U2TXIE = 0;						//disable the interrupt
	IPC7bits.U2TXIP = UxIP_DEFAULT;				//default priority

	//set up status register
	//bit 15,13 UTXISEL1:UTXISEL0: Transmission Interrupt Mode Selection bits
	//11 = Reserved; do not use
	//10 = Interrupt when a character is transferred to the Transmit Shift Register (TSR) and as a result, the transmit buffer becomes empty
	//01 = Interrupt when the last character is shifted out of the Transmit Shift Register; all transmit operations are completed
	//00 = Interrupt when a character is transferred to the Transmit Shift Register (this implies there is at least one character open in the transmit buffer)
	U2STAbits.UTXISEL1=0, U2STAbits.UTXISEL0=0;
//#endif
	//bit 14 UTXINV: IrDAr Encoder Transmit Polarity Inversion bit
	//If IREN = 0:
	//1 = UxTX Idle `0'
	//0 = UxTX Idle `1'
	//If IREN = 1:
	//1 = UxTX Idle `1'
	//0 = UxTX Idle `0'
	U2STAbits.UTXINV=0;
	//bit 12 Unimplemented: Read as `0'
	//bit 11 UTXBRK: Transmit Break bit
	//1 = Send Sync Break on next transmission - Start bit, followed by twelve `0' bits, followed by Stop bit;	cleared by hardware upon completion
	//0 = Sync Break transmission disabled or completed
	U2STAbits.UTXBRK=0;
	//bit 10 UTXEN: Transmit Enable bit(1)
	//1 = Transmit enabled, UxTX pin controlled by UARTx
	//0 = Transmit disabled, any pending transmission is aborted and buffer is reset. UxTX pin controlled by the PORT register.
#if defined(U2TX2RP)
	U2STAbits.UTXEN=1;
#else
	U2STAbits.UTXEN=0;
#endif
#if defined(U2RX2RP)
	//U2STAbits.URXEN=1;
#else
	//U2STAbits.URXEN=0;
#endif
	//bit 9 UTXBF: Transmit Buffer Full Status bit (read-only)
	//1 = Transmit buffer is full
	//0 = Transmit buffer is not full, at least one more character can be written
	//bit 8 TRMT: Transmit Shift Register Empty bit (read-only)
	//1 = Transmit Shift Register is empty and transmit buffer is empty (the last transmission has completed)
	//0 = Transmit Shift Register is not empty, a transmission is in progress or queued
//#if defined(UxRX2RP)
	IFS1bits.U2RXIF = 0;						//clear the flag
	IEC1bits.U2RXIE = 0;						//disable the interrupt

	//bit 7-6 URXISEL1:URXISEL0: Receive Interrupt Mode Selection bits
	//11 = Interrupt is set on RSR transfer, making the receive buffer full (i.e., has 4 data characters)
	//10 = Interrupt is set on RSR transfer, making the receive buffer 3/4 full (i.e., has 3 data characters)
	//0x = Interrupt is set when any character is received and transferred from the RSR to the receive buffer. Receive buffer has one or more characters.
	U2STAbits.URXISEL1 = 0, U2STAbits.URXISEL0 = 0;
//#endif
	//bit 5 ADDEN: Address Character Detect bit (bit 8 of received data = 1)
	//1 = Address Detect mode enabled. If 9-bit mode is not selected, this does not take effect.
	//0 = Address Detect mode disabled
	//bit 4 RIDLE: Receiver Idle bit (read-only)
	//1 = Receiver is Idle
	//0 = Receiver is active
	//bit 3 PERR: Parity Error Status bit (read-only)
	//1 = Parity error has been detected for the current character (character at the top of the receive FIFO)
	//0 = Parity error has not been detected
	//bit 2 FERR: Framing Error Status bit (read-only)
	//1 = Framing error has been detected for the current character (character at the top of the receive FIFO)
	//0 = Framing error has not been detected
	//bit 1 OERR: Receive Buffer Overrun Error Status bit (clear/read-only)
	//1 = Receive buffer has overflowed
	//0 = Receive buffer has not overflowed (clearing a previously set OERR bit (1 ? 0 transition) will reset the receiver buffer and the RSR to the empty state)
	//bit 0 URXDA: Receive Buffer Data Available bit (read-only)
	//1 = Receive buffer has data; at least one more character can be read
	//0 = Receive buffer is empty
	//REGISTER 17-2: U1STAbits: UARTx STATUS AND CONTROL REGISTER (CONTINUED)
	//Note 1: If UARTEN = 1, the peripheral inputs and outputs must be configured to an available RPn pin. See
	//Section 10.4 "Peripheral Pin Select" for more information.

}

void uart2Puts(char *str) {
#if defined(UART2_TXISR)
	//interrupt transmission
	if (*str) {								//if the string isn't empty to begin with
		//uart2Wait();						//for compatability with polling transmission
		//U1TXREG = 0;						//clear the buffer
		//_U1TX_BUSY  = 1;					//transmission in progress
		str2cb(&U2TXBuf, str);			//_U2TX_ptr=str;						//point to the string to be transmitted
		//U1STAbits.UTXEN = 1;				//enable transmission - always enabled
		//tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
		IFS1bits.U2TXIF = 0;				//UxTXIF = 0;							//clear the flag
		IEC1bits.U2TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
		U2TXREG = cbRead(&U2TXBuf);		//U2TXREG = *_U2TX_ptr++;
	}
#else
	//polling implementation
	while(*str) {
		uart2Putch(*str++);	//send the ch and advance the pointer
	}
#endif	//UART2_TXISR
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//void uart2Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart2Puts(ln);
//	//USARTWriteString("\r\n");
//	uart2Puts((char *)"\r\n");
//}

//uint8_t uart2Getch(void) {
//	//while(!RCIF); RCIF=0;		//Wait for a byte
//   //USART_WAIT(U1STAbits.TRMT);		//wait for the prior transmission to end
//
//	return U2RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart2Available(void) {
//	return U2STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart2Busy(void) {
//	return U2STAbits.UTXBF;
//}

//print to uart2
void u2Print(char *str, int32_t dat) {
	/*static*/ char uRAM[uRAM_SIZE];		//transmission buffer, 40-1 char max

	//uart2Wait();						//wait for uart to free up

	strcpy(uRAM, str);					//copy to uarm
	uPrint(uRAM, dat);					//print to uBuffer
	uart2Puts(uRAM);					//send a message on uart1
}

//end Serial

//tmr1
//global variables
static void (* _tmr1_isrptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler by default

//interrupt service routine
void _ISR_PSV _T1Interrupt(void) {
	IFS0bits.T1IF=0;							//clear tmr1 interrupt flag
#if defined(SYSTICK_TMR1)
	systick_ovf+=tmr1GetPR();					//PR1 + 1ul;	//0x10000ul;							//increment overflow count: 16-bit timer
#else	//systick on tmr2
	//do nothing
#endif
	_tmr1_isrptr();								//execute user tmr1 isr
}

//initialize the timer1 (16bit)
void tmr1Init(uint8_t ps) {
	_tmr1_isrptr=empty_handler;					//point to default handler

	PMD1bits.T1MD = 0;							//enable power to tmr
	//tmrInit(TIM1, ps);							//reset timer
	T1CONbits.TON = 0;							//turn off rtc1
	T1CONbits.TCS = 0;							//use internal clock = Fosc
	//T1CONbits.T32 = 0;							//0->16 bit timer, 1->32bit timer
	T1CONbits.TCKPS=ps & TMR_PSMASK;				//set prescaler to 1:1
	T1CONbits.TGATE = 0;							//rtc1 gate disabled
	PR1 = -1;									//set the preriod

	IFS0bits.T1IF = 0;							//reset the flag
	IEC0bits.T1IE = 0;							//rtc1 interrupt off

	T1CONbits.TON = 1;							//turn on rtc1

	//configure timer input pin (TxCK)
#if defined(T1CK2RP)
	T1CK2RP();									//configure the input pin
	T1CONbits.TCS = 1;							//1->use TxCK as input, 0->se internal clock = Fosc
#endif
}

//activate the isr handler
void tmr1AttachISR(void (*isrptr)(void)) {
	_tmr1_isrptr=isrptr;						//activate the isr handler
	IPC0bits.T1IP = TxIP_DEFAULT;
	//IPC0bits.T1IS = TxIS_DEFAULT;
	IFS0bits.T1IF = 0;							//reset the flag
	IEC0bits.T1IE = 1;							//rtc1 interrupt on
}

//tmr2
//global variables
static void (* _tmr2_isrptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler by default

//interrupt service routine
void _ISR_PSV _T2Interrupt(void) {
	IFS0bits.T2IF=0;							//clear tmr1 interrupt flag
#if defined(SYSTICK_TMR1)
	//do nothing
#else	//systick on tmr2
	systick_ovf+=tmr2GetPR();					//PR2 + 1ul;	//0x10000ul;							//increment overflow count: 16-bit timer
#endif
	_tmr2_isrptr();								//execute user tmr2 isr
}

//initialize the timer2 (16bit)
void tmr2Init(uint8_t ps) {
	_tmr2_isrptr=empty_handler;					//point to default handler

	PMD1bits.T2MD = 0;							//enable power to tmr
	//tmrInit(TIM2, ps);						//reset timer
	T2CONbits.TON = 0;							//turn off rtc1
	T2CONbits.TCS = 0;							//use internal clock = Fosc
	T2CONbits.T32 = 0;							//0->16 bit timer, 1->32bit timer
	T2CONbits.TCKPS=ps & TMR_PSMASK;			//set prescaler to 1:1
	T2CONbits.TGATE = 0;						//rtc1 gate disabled
	PR2 = -1;									//set the preriod

	IFS0bits.T2IF = 0;							//reset the flag
	IEC0bits.T2IE = 0;							//rtc1 interrupt off

	T2CONbits.TON = 1;							//turn on rtc1

	//configure timer input pin (TxCK)
#if defined(T2CK2RP)
	T2CK2RP();									//configure the input pin
	T2CONbits.TCS = 1;							//1->use TxCK as input, 0->se internal clock = Fosc
#endif
}

//activate the isr handler
void tmr2AttachISR(void (*isrptr)(void)) {
	_tmr2_isrptr=isrptr;						//activate the isr handler
	IPC1bits.T2IP = TxIP_DEFAULT;
	//IPC2bits.T2IS = TxIS_DEFAULT;
	IFS0bits.T2IF = 0;							//reset the flag
	IEC0bits.T2IE = 1;							//rtc1 interrupt on
}

//tmr3
//global variables
static void (* _tmr3_isrptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler by default

//interrupt service routine
void _ISR_PSV _T3Interrupt(void) {
	IFS0bits.T3IF=0;							//clear tmr1 interrupt flag
	_tmr3_isrptr();								//execute user tmr1 isr
}

//initialize the timer3 (16bit)
void tmr3Init(uint8_t ps) {
	_tmr3_isrptr=empty_handler;					//point to default handler

	PMD1bits.T3MD = 0;							//enable power to tmr
	//tmrInit(TIM3, ps);							//reset timer
	T3CONbits.TON = 0;							//turn off rtc1
	T3CONbits.TCS = 0;							//use internal clock = Fosc
	//T3CONbits.T32 = 0;							//0->16 bit timer, 1->32bit timer
	T3CONbits.TCKPS=ps & TMR_PSMASK;				//set prescaler to 1:1
	T3CONbits.TGATE = 0;							//rtc1 gate disabled
	PR3 = -1;									//set the preriod

	IFS0bits.T3IF = 0;							//reset the flag
	IEC0bits.T3IE = 0;							//rtc1 interrupt off

	T3CONbits.TON = 1;							//turn on rtc1

	//configure timer input pin (TxCK)
#if defined(T3CK2RP)
	T3CK2RP();									//configure the input pin
	T3CONbits.TCS = 1;							//1->use TxCK as input, 0->se internal clock = Fosc
#endif
}

//activate the isr handler
void tmr3AttachISR(void (*isrptr)(void)) {
	_tmr3_isrptr=isrptr;						//activate the isr handler
	IPC2bits.T3IP = TxIP_DEFAULT;
	//IPC2bits.T3IS = TxIS_DEFAULT;
	IFS0bits.T3IF = 0;							//reset the flag
	IEC0bits.T3IE = 1;							//rtc1 interrupt on
}

//tmr4
//global variables
static void (* _tmr4_isrptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler by default

//interrupt service routine
void _ISR_PSV _T4Interrupt(void) {
	IFS1bits.T4IF=0;							//clear tmr1 interrupt flag
	_tmr4_isrptr();								//execute user tmr1 isr
}

//initialize the timer4 (16bit)
void tmr4Init(uint8_t ps) {
	_tmr4_isrptr=empty_handler;					//point to default handler

	PMD1bits.T4MD = 0;							//enable power to tmr
	//tmrInit(TIM4, ps);							//reset timer
	T4CONbits.TON = 0;							//turn off rtc1
	T4CONbits.TCS = 0;							//use internal clock = Fosc
	T4CONbits.T32 = 0;							//0->16 bit timer, 1->32bit timer
	T4CONbits.TCKPS=ps & TMR_PSMASK;				//set prescaler to 1:1
	T4CONbits.TGATE = 0;							//rtc1 gate disabled
	PR4 = -1;									//set the preriod

	IFS1bits.T4IF = 0;							//reset the flag
	IEC1bits.T4IE = 0;							//rtc1 interrupt off

	T4CONbits.TON = 1;							//turn on rtc1


	//configure timer input pin (TxCK)
#if defined(T4CK2RP)
	T4CK2RP();									//configure the input pin
	T4CONbits.TCS = 1;							//1->use TxCK as input, 0->se internal clock = Fosc
#endif
}

//activate the isr handler
void tmr4AttachISR(void (*isrptr)(void)) {
	_tmr4_isrptr=isrptr;						//activate the isr handler
	IPC6bits.T4IP = TxIP_DEFAULT;
	//IPC6bits.T4IS = TxIS_DEFAULT;
	IFS1bits.T4IF = 0;							//reset the flag
	IEC1bits.T4IE = 1;							//rtc1 interrupt on
}

//tmr5
//global variables
static void (* _tmr5_isrptr)(void)=empty_handler;				//tmr1_ptr pointing to empty_handler by default

//interrupt service routine
void _ISR_PSV _T5Interrupt(void) {
	IFS1bits.T5IF=0;							//clear tmr1 interrupt flag
	_tmr5_isrptr();								//execute user tmr1 isr
}

//initialize the timer5 (16bit)
void tmr5Init(uint8_t ps) {
	_tmr5_isrptr=empty_handler;					//point to default handler

	PMD1bits.T5MD = 0;							//enable power to tmr
	//tmrInit(TIM5, ps);							//reset timer
	T5CONbits.TON = 0;							//turn off rtc1
	T5CONbits.TCS = 0;							//use internal clock = Fosc
	//T5CONbits.T32 = 0;							//0->16 bit timer, 1->32bit timer
	T5CONbits.TCKPS=ps & TMR_PSMASK;				//set prescaler to 1:1
	T5CONbits.TGATE = 0;							//rtc1 gate disabled
	PR5 = -1;									//set the priod

	IFS1bits.T5IF = 0;							//reset the flag
	IEC1bits.T5IE = 0;							//rtc1 interrupt off

	T5CONbits.TON = 1;							//turn on rtc1

	//configure timer input pin (TxCK)
#if defined(T5CK2RP)
	T5CK2RP();									//configure the input pin
	T5CONbits.TCS = 1;							//1->use TxCK as input, 0->se internal clock = Fosc
#endif
}

//activate the isr handler
void tmr5AttachISR(void (*isrptr)(void)) {
	_tmr5_isrptr=isrptr;						//activate the isr handler
	IPC7bits.T5IP = TxIP_DEFAULT;
	//IPC7bits.T5IS = TxIS_DEFAULT;
	IFS1bits.T5IF = 0;							//reset the flag
	IEC1bits.T5IE = 1;							//rtc1 interrupt on
}

//set up 32-bit timer
//using tmr2 (lsw) and tmr3 (msw)
void tmr23Init(uint8_t ps) {
	//period = period - 1;
	tmr2Init(ps/*, 1+period*/);
	tmr3Init(ps/*, 1+(period >>16)*/);
	T2CONbits.T32=1;					//1->as 32-bit timer

	TMR2 = TMR3 = 0;					//reset the timer
}

//read 32-bit timer2 and 3
uint32_t tmr23Get(void) {
	uint16_t msw, lsw;

	do {
		msw = TMR3;					//read the mws
		lsw = TMR2;					//read the lsw
	} while (msw ^ TMR2);

	return ((uint32_t) msw << 16) | lsw;
}

//#define tmr23AttachISR(isr)				tmr3AttachISR(isr)

//using tmr4 (lsw) and tmr5 (msw)
void tmr45Init(uint8_t ps) {
	//period = period - 1;
	tmr4Init(ps);						//tmr4Init(ps, 1+period);
	tmr5Init(ps);						//tmr5Init(ps, 1+(period>>16));
	T4CONbits.T32=1;					//1->as 32-bit timer

	TMR4 = TMR5 = 0;					//reset the timer
}

//read 32-bit timer4 and 5
uint32_t tmr45Get(void) {
	uint16_t msw, lsw;

	do {
		msw = TMR5;					//read the mws
		lsw = TMR4;					//read the lsw
	} while (msw ^ TMR5);

	return ((uint32_t) msw << 16) | lsw;
}

//#define tmr45AttachISR(isr)				tmr5AttachISR(isr)
//end Timer

//define pwm functions
//time base is Timer2, defined in mcu_init()

//pwm1/oc1
//reset pwm
void pwm1Init(void) {
	//power up the pwm module
	PMD2bits.OC1MD = 0;							//0->turn on the peripheral, 1->turn off the peripheral

#if defined(PWM12RP)
	//assign the output pins
	PWM12RP();
#endif

	//tris pin presumed to have been set to output

#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC1CON1 = 0x0000;
	OC1CON2 = 0x0000; 	OC1CON2bits.SYNCSEL = 0x1f;
	OC1CON1bits.OCM = 0x06;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm
	OC1CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC1RS = 0; OC1RS =-1;					//reset the duty cycle registers
	//OC1CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#else
	//for GA002 chips
	//OCxCON1 register settings
	//reset the registers
	OC1CON = 0x0000;
	//OC1CON2 = 0x0000;
	OC1CONbits.OCM = 0x06;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled
	OC1CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC1R = OC1RS = 0;						//reset the duty cycle registers
	//OC1CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#endif
}

//pwm2/oc2
//reset pwm
void pwm2Init(void) {
	//power up the pwm module
	PMD2bits.OC2MD = 0;						//0->turn on the peripheral, 1->turn off the peripheral

#if defined(PWM22RP)
	//assign the output pins
	PWM22RP();
#endif

	//tris pin presumed to have been set to output

#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/

	//OCxCON1 register settings
	//reset the registers
	OC2CON1 = 0x0000;
	OC2CON2 = 0x0000; 	OC2CON2bits.SYNCSEL = 0x1f;
	OC2CON1bits.OCM = 0x06;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm
	OC2CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC2R = 0; OC2RS =-1;					//reset the duty cycle registers
	//OC2CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC2CON = 0x0000;
	//OC2CON2 = 0x0000;
	OC2CONbits.OCM = 0x06;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled
	OC2CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC2R = OC2RS = 0;						//reset the duty cycle registers
	//OC2CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#endif
}


//pwm3/oc3
//reset pwm
void pwm3Init(void) {
	//power up the pwm module
	PMD2bits.OC3MD = 0;						//0->turn on the peripheral, 1->turn off the peripheral

#if defined(PWM32RP)
	//assign the output pins
	PWM32RP();
#endif

	//tris pin presumed to have been set to output

#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC3CON1 = 0x0000;
	OC3CON2 = 0x0000; 	OC3CON2bits.SYNCSEL = 0x1f;
	OC3CON1bits.OCM = 0x06;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm
	OC3CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC3R = 0; OC3RS =-1;					//reset the duty cycle registers
	//OC2CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC3CON = 0x0000;
	//OC3CON2 = 0x0000;
	OC3CONbits.OCM = 0x06;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled
	OC3CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC3R = OC3RS = 0;						//reset the duty cycle registers
	//OC3CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#endif
}


//pwm4/oc4
//reset pwm
void pwm4Init(void) {
	//power up the pwm module
	PMD2bits.OC4MD = 0;						//0->turn on the peripheral, 1->turn off the peripheral

#if defined(PWM42RP)
	//assign the output pins
	PWM42RP();
#endif

	//tris pin presumed to have been set to output
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/

	//OCxCON1 register settings
	//reset the registers
	OC4CON1 = 0x0000;
	OC4CON2 = 0x0000; 	OC4CON2bits.SYNCSEL = 0x1f;
	OC4CON1bits.OCM = 0x06;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm
	OC4CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC4R = 0; OC4RS =-1;						//reset the duty cycle registers
	//OC2CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC4CON = 0x0000;
	//OC4CON2 = 0x0000;
	OC4CONbits.OCM = 0x06;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled
	OC4CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC4R = OC4RS = 0;						//reset the duty cycle registers
	//OC4CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#endif
}


//pwm5/oc5
//reset pwm
void pwm5Init(void) {
	//power up the pwm module
	PMD2bits.OC5MD = 0;						//0->turn on the peripheral, 1->turn off the peripheral

#if defined(PWM52RP)
	//assign the output pins
	PWM52RP();
#endif

	//tris pin presumed to have been set to output
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC5CON1 = 0x0000;
	OC5CON2 = 0x0000; 	OC5CON2bits.SYNCSEL = 0x1f;
	OC5CON1bits.OCM = 0x06;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm
	OC5CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC5R = 0; OC5RS =-1;					//reset the duty cycle registers
	//OC5CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC5CON = 0x0000;
	//OC5CON2 = 0x0000;
	OC5CONbits.OCM = 0x06;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled
	OC5CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	OC5R = OC5RS = 0;						//reset the duty cycle registers
	//OC5CON1bits.ON= 1;					//1->turn on oc, 0->turn off oc
#endif
}
//end pwm/oc

//adc module
//rest the adc
//automatic sampling (ASAM=1), manual conversion
void adcInit(void) {
	PMD1bits.ADC1MD = 0;					//enable power to adc

	//reset the adc control registers
	AD1CON1 = 0;
	AD1CON2 = 0;
	AD1CON3 = 0;

	AD1CON1bits.SSRC = 7;					//0->samp ends sampling and starts conversion. 7=auto mode
	AD1CON2bits.VCFG = 0;					//0..7. adc reference: 0->AVdd-AVss,1=Vref+-AVss, 2=AVdd-Vref-, 3=Vref+ - Vref-
	AD1CON2bits.ALTS = 0;					//0->always use mux A inputs. 1->alternate between mux a and mux b inputs
	AD1CON3bits.SAMC = 31;					//0..31. 0->0 Tad (not recommended), 1->1 Tad, ... 31->32 Tad
	AD1CON3bits.ADCS = 2;					//0..63. 0->Tcy, 1-> 1Tcy, 63->64 Tcy
	AD1CSSL = 0;							//scanning disabled
#if defined(__PIC24GA11x__)
	AD1PCFGHbits.PCFGH |= 0b10;				//1->band gap enabled, 0->band gap disabled
#else
	AD1PCFGbits.PCFG15=1;					//1->band gap enabled, 0->band gap disabled
#endif
	AD1CON1bits.ADON = 1;					//1->enable adc
}

//read the adc
//single ended only.
uint16_t analogRead(uint16_t adc_ch) {
	uint16_t tmp;

	tmp=AD1PCFG;							//save current port configuration setting
	//set up adc port configuration bits
	//for the positive channel (mux a only)
	AD1CON1bits.DONE=0;
	adc_ch = adc_ch & 0x0f;					//adc_ch limited to 16 channels
#if 1
	AD1PCFG &=~(1<<adc_ch);				//configure the port to be analog
	AD1CHS = adc_ch;						//select the channel
#else
	switch (adc_ch) {
	case ADC_AN0:
		AD1PCFG &=~(1<< 0);
		AD1CHS =0x0000;
		break;		//AD1PCFG: 1->digital GPIO, 0->analog input
	case ADC_AN1:
		AD1PCFG &=~(1<< 1);
		AD1CHS =0x0001;
		break;
	case ADC_AN2:
		AD1PCFG &=~(1<< 2);
		AD1CHS =0x0002;
		break;
	case ADC_AN3:
		AD1PCFG &=~(1<< 3);
		AD1CHS =0x0003;
		break;
	case ADC_AN4:
		AD1PCFG &=~(1<< 4);
		AD1CHS =0x0004;
		break;
	case ADC_AN5:
		AD1PCFG &=~(1<< 5);
		AD1CHS =0x0005;
		break;
	case ADC_AN6:
		AD1PCFG &=~(1<< 6);
		AD1CHS =0x0006;
		break;									//not implemented on 28pin devices. do not use
	case ADC_AN7:
		AD1PCFG &=~(1<< 7);
		AD1CHS =0x0007;
		break;									//not implemented on 28pin devices. do not use
	case ADC_AN8:
		AD1PCFG &=~(1<< 8);
		AD1CHS =0x0008;
		break;									//not implemented on 28pin devices. do not use
	case ADC_AN9:
		AD1PCFG &=~(1<< 9);
		AD1CHS =0x0008;
		break;
	case ADC_AN10:
		AD1PCFG &=~(1<<10);
		AD1CHS =0x000a;
		break;
	case ADC_AN11:
		AD1PCFG &=~(1<<11);
		AD1CHS =0x000b;
		break;
	case ADC_AN12:
		AD1PCFG &=~(1<<12);
		AD1CHS =0x000c;
		break;									//not impelemned on 28pin devices. do not use
	case ADC_VCORE:
		AD1PCFG &=~(1<<13);
		AD1CHS =0x000d;
		break;
	case ADC_VBG_2:
		AD1PCFG &=~(1<<14);
		AD1CHS =0x000e;
		break;
	case ADC_VBG:
		AD1PCFG &=~(1<<15);
		AD1CHS =0x000f;
		break;									//AD1PCFG = ~adc_ch;					//mux b: not used; mux a: negative is Vref-,
	//case ADC_CTMU:		AD1PCFG &=~(0<<0); AD1CHS = 0x001f; break;						//reserved for ctmu
	default:
		break;									//do nothing
	}
#endif
	AD1CON1bits.SAMP = 1;						//start the adc
	//insert delays if necessary
	delayTks(ADC_DLY);
	while (!AD1CON1bits.DONE) continue;		//wait for adc to finish
	AD1PCFG = tmp;								//restore ad1pcfg setting
	return ADC1BUF0;							//return the adc results
}
//end ADC

//arand
//analog random
//generate 4-bit random numbers
uint8_t arand4(void) {
	uint8_t tmp=arand1();

	//tmp = (tmp << 1) | arand1();
	tmp = (tmp << 1) | arand1();
	tmp = (tmp << 1) | arand1();
	tmp = (tmp << 1) | arand1();
	return tmp;
}

//generate 8-bit random number
uint8_t arand8(void) {
	return (arand4() << 4) | arand4();
}

//return 16-bit random number
uint16_t arand16(void) {
	return ((uint16_t) arand8() << 8) | arand8();
}


//return 32-bit random number
uint32_t arand32(void) {
	return ((uint32_t) arand16() << 16) | arand16();
}
//end analog random
//end arand

//output compare
//oc1
uint16_t _oc1pr=0xffff;							//oc isr period
void (*_oc1_isrptr)(void)=empty_handler;		//tmr1_ptr pointing to empty_handler by default
//OC ISR
void _ISR_PSV _OC1Interrupt(void) {			//for PIC24
	//clear the flag
	IFS0bits.OC1IF = 0;							//clear the flag
	OC1RS += _oc1pr;							//update to the next match point
	_oc1_isrptr();								//run user handler
}

void oc1Init(uint16_t pr) {
	_oc1_isrptr=empty_handler;
	_oc1pr = pr;								//reset the pr

	//power up the pwm module
	PMD2bits.OC1MD = 0;							//0->turn on the peripheral, 1->turn off the peripheral

	//assign the output pins
#if defined(PWM12RP)
	PWM12RP();
#endif

	//tris pin presumed to have been set to output
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC1CON1 = 0x0000;
	OC1CON2 = 0x0000;
	OC1CON1bits.OCM = 0x03;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm, 0b011->continous pulse
	OC1CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC1R = OC1RS = TMR2 + _oc1pr;			//reset the duty cycle registers

	IFS0bits.OC1IF = 0;						//0->clear the flag;
	IEC0bits.OC1IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC0bits.OC1IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC1CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC1CON = 0x0000;
	//OC5CON2 = 0x0000;
	OC1CONbits.OCM = 0x03;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled, 0b011->compare toggles ocx
	OC1CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC1R = OC1RS = TMR2 + _oc1pr;			//reset the duty cycle registers

	IFS0bits.OC1IF = 0;						//0->clear the flag;
	IEC0bits.OC1IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC0bits.OC1IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC1CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#endif
}

//activate user isr
void oc1AttachISR(void (*isrptr)(void)) {
	_oc1_isrptr=isrptr;						//activate the isr handler
	OC1RS = TMR2 + _oc1pr;					//update to the next match point
	IFS0bits.OC1IF = 0;						//0->clear the flag;
	IEC0bits.OC1IE = 1;						//0->disable the interrupt, 1->enable the interrupt
}

//oc2
uint16_t _oc2pr=0xffff;							//oc isr period
void (*_oc2_isrptr)(void)=empty_handler;		//tmr1_ptr pointing to empty_handler by default
//OC ISR
void _ISR_PSV _OC2Interrupt(void) {				//for PIC24
	//clear the flag
	IFS0bits.OC2IF = 0;							//clear the flag
	OC2R += _oc2pr;								//update to the next match point
	_oc2_isrptr();								//run user handler
}

void oc2Init(uint16_t pr) {
	_oc2_isrptr=empty_handler;
	_oc2pr = pr;								//reset the pr

	//power up the pwm module
	PMD2bits.OC2MD = 0;							//0->turn on the peripheral, 1->turn off the peripheral

	//assign the output pins
#if defined(PWM22RP)
	PWM22RP();
#endif

	//tris pin presumed to have been set to output
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC2CON1 = 0x0000;
	OC2CON2 = 0x0000;
	OC2CON1bits.OCM = 0x03;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm, 0b011->continous pulse
	OC2CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC2R = OC2RS = TMR2 + _oc2pr;			//reset the duty cycle registers

	IFS0bits.OC2IF = 0;						//0->clear the flag;
	IEC0bits.OC2IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC1bits.OC2IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC2CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC2CON = 0x0000;
	//OC5CON2 = 0x0000;
	OC2CONbits.OCM = 0x03;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled, 0b011->compare toggles ocx
	OC2CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC2R = OC2RS = TMR2 + _oc2pr;			//reset the duty cycle registers

	IFS0bits.OC2IF = 0;						//0->clear the flag;
	IEC0bits.OC2IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC1bits.OC2IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC2CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#endif
}

//activate user isr
void oc2AttachISR(void (*isrptr)(void)) {
	_oc2_isrptr=isrptr;						//activate the isr handler
	OC2RS = TMR2 + _oc2pr;					//update to the next match point
	IFS0bits.OC2IF = 0;						//0->clear the flag;
	IEC0bits.OC2IE = 1;						//0->disable the interrupt, 1->enable the interrupt
}

//oc3
uint16_t _oc3pr=0xffff;							//oc isr period
void (*_oc3_isrptr)(void)=empty_handler;		//tmr1_ptr pointing to empty_handler by default
//OC ISR
void _ISR_PSV _OC3Interrupt(void) {				//for PIC24
	//clear the flag
	IFS1bits.OC3IF = 0;							//clear the flag
	OC3RS += _oc3pr;								//update to the next match point
	_oc3_isrptr();								//run user handler
}

void oc3Init(uint16_t pr) {
	_oc3_isrptr=empty_handler;
	_oc3pr = pr;								//reset the pr

	//power up the pwm module
	PMD2bits.OC3MD = 0;							//0->turn on the peripheral, 1->turn off the peripheral

	//assign the output pins
#if defined(PWM32RP)
	PWM32RP();
#endif

	//tris pin presumed to have been set to output
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC3CON1 = 0x0000;
	OC3CON2 = 0x0000;
	OC3CON1bits.OCM = 0x03;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm, 0b011->continous pulse
	OC3CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC3R = OC3RS = TMR2 + _oc3pr;			//reset the duty cycle registers

	IFS1bits.OC3IF = 0;						//0->clear the flag;
	IEC1bits.OC3IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC6bits.OC3IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC3CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC3CON = 0x0000;
	//OC3CON2 = 0x0000;
	OC3CONbits.OCM = 0x03;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled, 0b011->compare toggles ocx
	OC3CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC3R = OC3RS = TMR2 + _oc3pr;			//reset the duty cycle registers

	IFS1bits.OC3IF = 0;						//0->clear the flag;
	IEC1bits.OC3IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC6bits.OC3IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC3CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#endif
}

//activate user isr
void oc3AttachISR(void (*isrptr)(void)) {
	_oc3_isrptr=isrptr;						//activate the isr handler
	OC3RS = TMR2 + _oc3pr;					//update to the next match point
	IFS1bits.OC3IF = 0;						//0->clear the flag;
	IEC1bits.OC3IE = 1;						//0->disable the interrupt, 1->enable the interrupt
}

//oc4
uint16_t _oc4pr=0xffff;							//oc isr period
void (*_oc4_isrptr)(void)=empty_handler;		//tmr1_ptr pointing to empty_handler by default
//OC ISR
void _ISR_PSV _OC4Interrupt(void) {				//for PIC24
	//clear the flag
	IFS1bits.OC4IF = 0;							//clear the flag
	OC4R += _oc4pr;								//update to the next match point
	_oc4_isrptr();								//run user handler
}

void oc4Init(uint16_t pr) {
	_oc4_isrptr=empty_handler;
	_oc4pr = pr;								//reset the pr

	//power up the pwm module
	PMD2bits.OC4MD = 0;							//0->turn on the peripheral, 1->turn off the peripheral

	//assign the output pins
#if defined(PWM42RP)
	PWM42RP();
#endif

	//tris pin presumed to have been set to output
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC4CON1 = 0x0000;
	OC4CON2 = 0x0000;
	OC4CON1bits.OCM = 0x03;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm, 0b011->continous pulse
	OC4CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC4R = OC4RS = TMR2 + _oc4pr;			//reset the duty cycle registers

	IFS1bits.OC4IF = 0;						//0->clear the flag;
	IEC1bits.OC4IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC6bits.OC4IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC4CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC4CON = 0x0000;
	//OC4CON2 = 0x0000;
	OC4CONbits.OCM = 0x03;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled, 0b011->compare toggles ocx
	OC4CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC4R = OC4RS = TMR2 + _oc4pr;			//reset the duty cycle registers

	IFS1bits.OC4IF = 0;						//0->clear the flag;
	IEC1bits.OC4IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC6bits.OC4IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC1CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#endif
}

//activate user isr
void oc4AttachISR(void (*isrptr)(void)) {
	_oc4_isrptr=isrptr;						//activate the isr handler
	OC4RS = TMR2 + _oc4pr;					//update to the next match point
	IFS1bits.OC4IF = 0;						//0->clear the flag;
	IEC1bits.OC4IE = 1;						//0->disable the interrupt, 1->enable the interrupt
}

//oc5
uint16_t _oc5pr=0xffff;							//oc isr period
void (*_oc5_isrptr)(void)=empty_handler;		//tmr1_ptr pointing to empty_handler by default
//OC ISR
void _ISR_PSV _OC5Interrupt(void) {			//for PIC24
	//clear the flag
	IFS2bits.OC5IF = 0;							//clear the flag
	OC5RS += _oc5pr;							//update to the next match point
	_oc5_isrptr();								//run user handler
}

void oc5Init(uint16_t pr) {
	_oc5_isrptr=empty_handler;
	_oc5pr = pr;								//reset the pr

	//power up the pwm module
	PMD2bits.OC5MD = 0;							//0->turn on the peripheral, 1->turn off the peripheral

	//assign the output pins
#if defined(PWM52RP)
	PWM52RP();
#endif

	//tris pin presumed to have been set to output
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	//OCxCON1 register settings
	//reset the registers
	OC5CON1 = 0x0000;
	OC5CON2 = 0x0000;
	OC5CON1bits.OCM = 0x03;					//0b110 -> edge aligned pwm, 0b111->center aligned pwm, 0b011->continous pulse
	OC5CON1bits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC5R = OC5RS = TMR2 + _oc5pr;			//reset the duty cycle registers

	IFS2bits.OC5IF = 0;						//0->clear the flag;
	IEC2bits.OC5IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC10bits.OC5IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC5CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#else
	//for ga002 devices
	//OCxCON1 register settings
	//reset the registers
	OC5CON = 0x0000;
	//OC5CON2 = 0x0000;
	OC5CONbits.OCM = 0x03;					//0b110 -> pwm on OCx, fault pin disabled, 0b111->pwm on OCx, fault pin enabled, 0b011->compare toggles ocx
	OC5CONbits.OCTSEL = 0;					//0->timebase = timer2, 1->timebase = timer3
	//OC5R = OC5RS = TMR2 + _oc5pr;			//reset the duty cycle registers

	IFS2bits.OC5IF = 0;						//0->clear the flag;
	IEC2bits.OC5IE = 0;						//0->disable the interrupt, 1->enable the interrupt
	IPC10bits.OC5IP = OCxIP_DEFAULT;			//clear the interrupt priority

	//OC1CON1bits.ON= 1;						//1->turn on oc, 0->turn off oc
#endif
}

//activate user isr
void oc5AttachISR(void (*isrptr)(void)) {
	_oc5_isrptr=isrptr;						//activate the isr handler
	OC5RS = TMR2 + _oc5pr;					//update to the next match point
	IFS2bits.OC5IF = 0;						//0->clear the flag;
	IEC2bits.OC5IE = 1;						//0->disable the interrupt, 1->enable the interrupt
}
//end output compare

//input capture
static void (*_ic1_isrptr)(void)=empty_handler;	//function pointer pointing to empty_handler by default
//volatile uint16_t IC1DAT=0;						//buffer

//input capture ISR
void _ISR_PSV _IC1Interrupt(void) {				//for PIC24
	//clear the flag
	//IC1DAT = IC1BUF;							//read the captured value
	IFS0bits.IC1IF = 0;							//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic1_isrptr();								//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic1Init(void) {
	_ic1_isrptr = empty_handler;				//reset user handler

#if defined(IC12RP)
	IC12RP();									//assign pin to IC
#endif
	PMD2bits.IC1MD = 0;							//0->enable power to input capture
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	IC1CON1 = 0;						//reset to default value
	IC1CON2 = 0;						//reset to default value
	IC1CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC1CON1bits.ICBNE) IC1BUF;	//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC1CON1bits.ON = 1;				//1->enable the module, 0->disable the module
#else
	//for ga002 devices
	IC1CON = 0;							//reset to default value
	//IC1CON2 = 0;						//reset to default value
	IC1CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC1CONbits.ICBNE) IC1BUF;	//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC1CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
	//input capture running now
}

//activate user ptr
void ic1AttachISR(void (*isrptr)(void)) {
	_ic1_isrptr = isrptr;				//install user ptr
	//IC1BUF;								//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

static void (*_ic2_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
//volatile uint16_t IC2DAT=0;				//buffer

//input capture ISR
void _ISR_PSV _IC2Interrupt(void) {		//for PIC24
	//clear the flag
	//IC2DAT = IC2BUF;					//read the captured value
	IFS0bits.IC2IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic2_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic2Init(void) {
	_ic2_isrptr = empty_handler;		//reset user handler

#if defined(IC22RP)
	IC22RP();							//assign pin to IC
#endif
	PMD2bits.IC2MD = 0;					//0->enable power to input capture
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	IC2CON1 = 0;						//reset to default value
	IC2CON2 = 0;						//reset to default value
	IC2CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC2CON1bits.ICBNE) IC2BUF;	//read the buffer to clear the flag
	IFS0bits.IC2IF   = 0;				//0->clear the flag
	IEC0bits.IC2IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC2CON1bits.ON = 1;				//1->enable the module, 0->disable the module
#else
	//for ga002 devices
	IC2CON = 0;							//reset to default value
	//IC2CON2 = 0;						//reset to default value
	IC2CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC2CONbits.ICBNE) IC2BUF;	//read the buffer to clear the flag
	IFS0bits.IC2IF   = 0;				//0->clear the flag
	IEC0bits.IC2IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC2CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic2AttachISR(void (*isrptr)(void)) {
	_ic2_isrptr = isrptr;				//install user ptr
	//IC2BUF;								//read the buffer to clear the flag
	IFS0bits.IC2IF   = 0;				//0->clear the flag
	IEC0bits.IC2IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

static void (*_ic3_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
//volatile uint16_t IC3DAT=0;				//buffer

//input capture ISR
void _ISR_PSV _IC3Interrupt(void) {		//for PIC24
	//clear the flag
	//IC3DAT = IC3BUF;					//read the captured value
	IFS2bits.IC3IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic3_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic3Init(void) {
	_ic3_isrptr = empty_handler;		//reset user handler

#if defined(IC32RP)
	IC32RP();							//assign pin to IC
#endif
	PMD2bits.IC3MD = 0;					//0->enable power to input capture
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	IC3CON1 = 0;						//reset to default value
	IC3CON2 = 0;						//reset to default value
	IC3CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC3CON1bits.ICBNE) IC3BUF;	//read the buffer to clear the flag
	IFS2bits.IC3IF   = 0;				//0->clear the flag
	IEC2bits.IC3IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC3CON1bits.ON = 1;				//1->enable the module, 0->disable the module
	//input capture running now
#else
	//for ga002 devices
	IC3CON = 0;							//reset to default value
	//IC3CON2 = 0;						//reset to default value
	IC3CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC3CONbits.ICBNE) IC3BUF;	//read the buffer to clear the flag
	IFS2bits.IC3IF   = 0;				//0->clear the flag
	IEC2bits.IC3IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC3CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic3AttachISR(void (*isrptr)(void)) {
	_ic3_isrptr = isrptr;				//install user ptr
	//IC3BUF;								//read the buffer to clear the flag
	IFS2bits.IC3IF   = 0;				//0->clear the flag
	IEC2bits.IC3IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

static void (*_ic4_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
//volatile uint16_t IC4DAT=0;				//buffer

//input capture ISR
void _ISR_PSV _IC4Interrupt(void) {		//for PIC24
	//clear the flag
	//IC4DAT = IC4BUF;					//read the captured value
	IFS2bits.IC4IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic4_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic4Init(void) {
	_ic4_isrptr = empty_handler;		//reset user handler

#if defined(IC42RP)
	IC42RP();							//assign pin to IC
#endif
	PMD2bits.IC4MD = 0;					//0->enable power to input capture
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	IC4CON1 = 0;						//reset to default value
	IC4CON2 = 0;						//reset to default value
	IC4CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC4CON1bits.ICBNE) IC4BUF;	//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC4CON1bits.ON = 1;				//1->enable the module, 0->disable the module
	//input capture running now
#else
	//for ga002 devices
	IC4CON = 0;							//reset to default value
	//IC4CON2 = 0;						//reset to default value
	IC4CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC4CONbits.ICBNE) IC4BUF;	//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC4CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic4AttachISR(void (*isrptr)(void)) {
	_ic4_isrptr = isrptr;				//install user ptr
	//IC4BUF;								//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

static void (*_ic5_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
//volatile uint16_t IC5DAT=0;				//buffer

//input capture ISR
void _ISR_PSV _IC5Interrupt(void) {		//for PIC24
	//clear the flag
	//IC5DAT = IC5BUF;					//read the captured value
	IFS2bits.IC5IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic5_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic5Init(void) {
	_ic5_isrptr = empty_handler;		//reset user handler

#if defined(IC52RP)
	IC52RP();							//assign pin to IC
#endif
	PMD2bits.IC5MD = 0;					//0->enable power to input capture
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	IC5CON1 = 0;						//reset to default value
	IC5CON2 = 0;						//reset to default value
	IC5CON1  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC5CON1bits.ICBNE) IC5BUF;	//read the buffer to clear the flag
	IFS2bits.IC5IF   = 0;				//0->clear the flag
	IEC2bits.IC5IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC5CON1bits.ON = 1;				//1->enable the module, 0->disable the module
	//input capture running now
#else
	//for ga002 devices
	IC5CON = 0;							//reset to default value
	//IC5CON2 = 0;						//reset to default value
	IC5CON  = 	(0<<15) |				//1->enable the module, 0->disable the module
				(0<<13) |				//0->operates in idle, 1->don't operate in idle
				(1<<9) |				//1-.capture rising edge first (only used for ICM110)
				(0<<8) |				//1->32-bit mode, 0->16-bit mode
				(1<<7) |				//1->timer2 as timebase, 0->timer3 as timebase
				(0<<5) |				//0->interrupt on every capture event, 1->on every second capture event, 2->on every 3rd event, 3->on every 4th event
				(0<<4) |				//0->ICx no overflow, 1->ICx overflow
				(0<<3) |				//0->buffer is empty, 1->buffer is not empty
				(3<<0) |				//0->ICx disabled, 1->every edge, 2->every falling edge, 3->every rising edge, ...
				0x00;

	while (IC5CONbits.ICBNE) IC5BUF;	//read the buffer to clear the flag
	IFS2bits.IC5IF   = 0;				//0->clear the flag
	IEC2bits.IC5IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC5CONbits.ON = 1;				//1->enable the module, 0->disable the module
#endif
}

//activate user ptr
void ic5AttachISR(void (*isrptr)(void)) {
	_ic5_isrptr = isrptr;				//install user ptr
	//IC5BUF;								//read the buffer to clear the flag
	IFS2bits.IC5IF   = 0;				//0->clear the flag
	IEC2bits.IC5IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//end input capture

//extint
//extint0
void (* _int0_isrptr) (void)=empty_handler;

void _ISR_PSV _INT0Interrupt(void) {
	IFS0bits.INT0IF = 0;				//clera the flag
	_int0_isrptr();						//run the isr
}

void int0Init(void) {
	//INT02RP();						//map int0_pin - int0 cannot be remapped
	_int0_isrptr = empty_handler;		//initialize int isr ptr
	IFS0bits.INT0IF = 0;				//clear int0 flag
	IEC0bits.INT0IE = 0;				//1->enable int0 interrupt, 0->disable the interrupt
	//INTCONbits.INT0EP = 1;			//1=triggered on the falling edge. 0 = rising edge
}

void int0AttachISR(void (*isrptr) (void)) {
	_int0_isrptr = isrptr;
	IFS0bits.INT0IF = 0;				//clear int0 flag
	IEC0bits.INT0IE = 1;				//1->enable int0 interrupt, 0->disable the interrupt
}

//extint1
void (* _int1_isrptr) (void)=empty_handler;

void _ISR_PSV _INT1Interrupt(void) {
	IFS1bits.INT1IF = 0;				//clera the flag
	_int1_isrptr();						//run the isr
}

void int1Init(void) {
#if defined(INT12RP)
	INT12RP();							//map int1_pin
#endif
	_int1_isrptr = empty_handler;		//initialize int isr ptr
	IFS1bits.INT1IF = 0;				//clear int0 flag
	IEC1bits.INT1IE = 0;				//1->enable int0 interrupt, 0->disable the interrupt
	//INTCONbits.INT1EP = 1;			//1=triggered on the falling edge. 0 = rising edge
}

void int1AttachISR(void (*isrptr) (void)) {
	_int1_isrptr = isrptr;
	IFS1bits.INT1IF = 0;				//clear int0 flag
	IEC1bits.INT1IE = 1;				//1->enable int0 interrupt, 0->disable the interrupt
}

//extint2
void (* _int2_isrptr) (void)=empty_handler;

void _ISR_PSV _INT2Interrupt(void) {
	IFS1bits.INT2IF = 0;				//clera the flag
	_int2_isrptr();						//run the isr
}

void int2Init(void) {
#if defined(INT22RP)
	INT22RP();							//map int2_pin
#endif
	_int2_isrptr = empty_handler;		//initialize int isr ptr
	IFS1bits.INT2IF = 0;				//clear int0 flag
	IEC1bits.INT2IE = 0;				//1->enable int0 interrupt, 0->disable the interrupt
	//INTCONbits.INT2EP = 1;			//1=triggered on the falling edge. 0 = rising edge
}

void int2AttachISR(void (*isrptr) (void)) {
	_int2_isrptr = isrptr;
	IFS1bits.INT2IF = 0;				//clear int0 flag
	IEC1bits.INT2IE = 1;				//1->enable int0 interrupt, 0->disable the interrupt
}
//end extint

//spi
//rest spi1
void spi1Init(uint16_t br) {
	PMD1bits.SPI1MD = 0;				//0->enable the module

	//map the pins
#if defined(SCK1RP)
	SCK1RP();
#endif
#if defined(SDO1RP)
	SDO1RP();
#endif
#if defined(SDI1RP)
	SDI1RP();
#endif

	//initialize the spi module
	//master mode, PBCLK as clock, 8-bit data, enhanced buffer mode
	SPI1CON1 = SPI1CON2 = 0; 			//reset the spi module
	SPI1CON1bits.MSTEN = 1;				//1->master mode, 0->slave mode
	SPI1CON1bits.PPRE = br;				//set the baudrate generator (primary prescaler)
	SPI1CON1bits.SPRE = 0;				//set the secondary prescaler
	SPI1STATbits.SPIROV=0;				//clear rov flag
	//SPI1BUF;							//perform a read to clear the flag
	SPI1CON2bits.SPIBEN= 1;				//1->enable enhanced buffer mode, 0->disable enhanced buffer mode
	//need to deal with secondary as well
	SPI1BUF;							//read the buffer to reset the flag
	IFS0bits.SPI1IF = 0;				//0->reset the flag
	IEC0bits.SPI1IE = 0;				//0->disable the interrupt, 1->enable the interrupt
	IPC2bits.SPI1IP = SPIIP_DEFAULT;	//default interrupt priority

	SPI1STATbits.SPIEN = 1;				//1->enable the module, 0->disable the module
}

//rest spi2
void spi2Init(uint16_t br) {
	PMD1bits.SPI2MD = 0;				//0->enable the module

	//map the pins
#if defined(SCK2RP)
	SCK2RP();
#endif
#if defined(SDO2RP)
	SDO2RP();
#endif
#if defined(SDI2RP)
	SDI2RP();
#endif


	//initialize the spi module
	//master mode, PBCLK as clock, 8-bit data, enhanced buffer mode
	SPI2CON1 = SPI2CON2 = 0; 			//reset the spi module
	SPI2CON1bits.MSTEN = 1;				//1->master mode, 0->slave mode
	SPI2CON1bits.PPRE = br;				//set the baudrate generator
	SPI2CON1bits.SPRE = 0;				//set the secondary prescaler
	SPI1STATbits.SPIROV=0;				//clear rov flag
	//SPI1BUF;							//perform a read to clear the flag
	SPI1CON2bits.SPIBEN= 1;				//1->enable enhanced buffer mode, 0->disable enhanced buffer mode
	//need to deal with 2nd ary as well
	SPI2BUF;							//read the buffer to reset the flag
	IFS2bits.SPI2IF = 0;				//0->reset the flag
	IEC2bits.SPI2IE = 0;				//0->disable the interrupt, 1->enable the interrupt
	IPC8bits.SPI2IP = SPIIP_DEFAULT;	//default interrupt priority

	SPI2STATbits.SPIEN = 1;				//1->enable the module, 0->disable the module
}

//send data via spi
//void spi2Write(uint8_t dat) {
//	while (spi2Busy()) continue;		//tx buffer is full
//	SPI2BUF = dat;						//load the data
//}
//end spi

//i2c
//I2C1
//wait for I2C
#define I2C1Wait()		do {while (I2C1CON & 0x1f); while (I2C1STATbits.TRSTAT);} while (0)		//wait for I2C1

//#define F_I2C1			100000ul	//I2C frequency
//initialize the I2C
void I2C1Init(uint32_t bps) {
	PMD1bits.I2C1MD = 0;				//0->enable the module, 1->disable the module
	I2C1CON = 0;						//reset I2C
	I2C1BRG = F_PHB / 2 / bps - 1 - (F_PHB / 2 / 10000000ul);	//TPGOB = 130ns, minimum of 4
	if (I2C1BRG < 0x04) I2C1BRG = 0x04;	//values 0..3 prohibited
	I2C1CONbits.I2CEN = 1;					//1->turn on the I2C, 0->turn off the I2C
}

//send a start condition
void I2C1Start(void) {
	I2C1Wait();
	I2C1CONbits.SEN = 1;
	while (I2C1CONbits.SEN == 1) continue;
}

//send a stop condition
void I2C1Stop(void) {
	I2C1Wait();
	I2C1CONbits.PEN = 1;
	while (I2C1CONbits.PEN == 1) continue;
}

//send a restart condition
void I2C1Restart(void) {
	I2C1Wait();
	I2C1CONbits.RSEN = 1;
	while (I2C1CONbits.RSEN == 1) continue;
}

//send I2C
unsigned char I2C1Write(unsigned char dat) {
	I2C1TRN = dat; 					 			// Send slave address with Read/Write bit cleared
	//while (I2C1STATbits.TRSTAT == 1) continue;	// Wait until transmit buffer is empty
	while (I2C1STATbits.TBF == 1) continue;		// Wait until transmit buffer is empty
	//I2C1Wait();								//wait for I2C bus to idle
	while (I2C1STATbits.ACKSTAT == 1) continue;	//wait for the ack signal
	return I2C1STATbits.ACKSTAT; 				// Wait until ACK is received
}

//read I2C
unsigned char I2C1Read(unsigned char ack) {
	I2C1CONbits.RCEN = 1;			   		// Receive enable
	while (I2C1CONbits.RCEN == 1) continue;		// Wait until RCEN is cleared (automatic)
	I2C1STATbits.I2COV = 0;						//clear the flag
	I2C1CONbits.ACKDT = ack;					//send ack bits
	I2C1CONbits.ACKEN = 1;
	while (I2C1CONbits.ACKEN == 1) continue;
	return I2C1RCV;								// Retrieve value from I2C1RCV
}
//write from a buffer
uint8_t I2C1Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite) {
	I2C1Start();							//send start condition
	I2C1Write(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	I2C1Write(RegAddr);					//send register addr
	while (NumByteToWrite) {
		I2C1Write(*pBuffer);				//send data
		pBuffer++;							//increment buffer pointer
		NumByteToWrite--;					//decrement counter
	}
	I2C1Stop();							//send stop condition
	return 0;								//indicating success
}

//read to a buffer
uint8_t I2C1Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead) {
	I2C1Start();							//send start condition
	I2C1Write(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	I2C1Write(RegAddr);					//send register addr
	I2C1Start();							//send restart
	I2C1Write(DeviceAddr | I2C_CMD_READ);	//send device addr, for read operations
	while (NumByteToRead) {
		if (NumByteToRead==1) {
			*pBuffer=I2C1Read(I2C_NOACK);
			I2C1Stop();							//send the stop condition
			break;
		}
		*pBuffer=I2C1Read(I2C_ACK);		//read the data
		pBuffer++;							//increment buffer
		NumByteToRead--;					//decrement count
	}
	return 0;
}

//end I2C1

//I2C1
//wait for I2C
#define I2C2Wait()		do {while (I2C2CON & 0x1f); while (I2C2STATbits.TRSTAT);} while (0)		//wait for I2C1

//#define F_I2C1			100000ul	//I2C frequency
//initialize the I2C
void I2C2Init(uint32_t bps) {
	PMD3bits.I2C2MD = 0;				//0->enable the module, 1->disable the module
	I2C2CON = 0;						//reset I2C
	I2C2BRG = F_PHB / 2 / bps - 1 - (F_PHB / 2 / 10000000ul);	//TPGOB = 130ns, minimum of 4
	if (I2C2BRG < 0x04) I2C2BRG = 0x04;	//values 0..3 prohibited
	I2C2CONbits.I2CEN = 1;					//1->turn on the I2C, 0->turn off the I2C
}

//send a start condition
void I2C2Start(void) {
	I2C2Wait();
	I2C2CONbits.SEN = 1;
	while (I2C2CONbits.SEN == 1) continue;
}

//send a stop condition
void I2C2Stop(void) {
	I2C2Wait();
	I2C2CONbits.PEN = 1;
	while (I2C2CONbits.PEN == 1) continue;
}

//send a restart condition
void I2C2Restart(void) {
	I2C2Wait();
	I2C2CONbits.RSEN = 1;
	while (I2C2CONbits.RSEN == 1) continue;
}

//send I2C
unsigned char I2C2Write(unsigned char dat) {
	I2C2TRN = dat; 					 			// Send slave address with Read/Write bit cleared
	//while (I2C2STATbits.TRSTAT == 1) continue;	// Wait until transmit buffer is empty
	while (I2C2STATbits.TBF == 1) continue;		// Wait until transmit buffer is empty
	//I2C2Wait();								//wait for I2C bus to idle
	while (I2C2STATbits.ACKSTAT == 1) continue;	//wait for the ack signal
	return I2C2STATbits.ACKSTAT; 				// Wait until ACK is received
}

//read I2C
unsigned char I2C2Read(unsigned char ack) {
	I2C2CONbits.RCEN = 1;			   		// Receive enable
	while (I2C2CONbits.RCEN == 1) continue;		// Wait until RCEN is cleared (automatic)
	I2C2STATbits.I2COV = 0;						//clear the flag
	I2C2CONbits.ACKDT = ack;					//send ack bits
	I2C2CONbits.ACKEN = 1;
	while (I2C2CONbits.ACKEN == 1) continue;
	return I2C2RCV;								// Retrieve value from I2C1RCV
}
//write from a buffer
uint8_t I2C2Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite) {
	I2C2Start();							//send start condition
	I2C2Write(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	I2C2Write(RegAddr);					//send register addr
	while (NumByteToWrite) {
		I2C2Write(*pBuffer);				//send data
		pBuffer++;							//increment buffer pointer
		NumByteToWrite--;					//decrement counter
	}
	I2C2Stop();							//send stop condition
	return 0;								//indicating success
}

//read to a buffer
uint8_t I2C2Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead) {
	I2C2Start();							//send start condition
	I2C2Write(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	I2C2Write(RegAddr);					//send register addr
	I2C2Start();							//send restart
	I2C2Write(DeviceAddr | I2C_CMD_READ);	//send device addr, for read operations
	while (NumByteToRead) {
		if (NumByteToRead==1) {
			*pBuffer=I2C2Read(I2C_NOACK);
			I2C2Stop();							//send the stop condition
			break;
		}
		*pBuffer=I2C2Read(I2C_ACK);		//read the data
		pBuffer++;							//increment buffer
		NumByteToRead--;					//decrement count
	}
	return 0;
}

//end I2C2

//software i2c
#define sI2C_HIGH(pin)				do {						pinMode(pin, INPUT);  sI2C_DLY();} while (0)	//let pin float to high
#define sI2C_LOW(pin)				do {digitalWrite(pin, LOW); pinMode(pin, OUTPUT); sI2C_DLY();} while (0)	//pull pin low
#define sI2C_GET(pin)				digitalRead(pin)			//read a pin
#define sI2C_DLY()					delayTks(F_CPU / F_sI2C / 2)								//software I2C delay for half of the period to achieve F_sI2C

//initialize i2c
void sI2CInit(void) {
	//pins idle high / as input
	sI2C_HIGH(sI2CSDAPIN); sI2C_HIGH(sI2CSCLPIN);				//clear the bus (idles high)
}


//-----------------START Condition-----------------------
void sI2CStart(void) {
	sI2C_HIGH(sI2CSDAPIN);						//let sda high
	sI2C_HIGH(sI2CSCLPIN);						//let scl high
	sI2C_LOW(sI2CSDAPIN);						//pull i2c_sda low
	sI2C_LOW(sI2CSCLPIN);						//pull i2c_scl low
}

//------------------STOP Condition--------------------------
void sI2CStop(void) {
	sI2C_LOW(sI2CSCLPIN);						//let scl float high
	sI2C_LOW(sI2CSDAPIN);
	sI2C_HIGH(sI2CSCLPIN);						//let scl float high
	sI2C_HIGH(sI2CSDAPIN);						//let sda  high
}

//------------------restart condition---------------------

//-------------------I2C Write---------------------------
uint8_t sI2CWrite(uint8_t dat) {
	unsigned char i;

	sI2C_HIGH(sI2CSDAPIN);						//let sda float
	i=0x80;
	do {
		sI2C_LOW(sI2CSCLPIN);					//clear i2c_scl
	  	if(dat & i)
			{sI2C_HIGH(sI2CSDAPIN);}			//set i2c_sda
		else
			{sI2C_LOW(sI2CSDAPIN);}				//clear i2c_sda
		sI2C_HIGH(sI2CSCLPIN);					//set i2c_scl
	  	i = i >> 1;								//shift out the highest bit
	} while (i);
	sI2C_LOW(sI2CSCLPIN);						//clear i2c_scl

	sI2C_HIGH(sI2CSDAPIN);						//float sda, let the slave control it
	sI2C_HIGH(sI2CSCLPIN);
	i=0;
	while (sI2C_GET(sI2CSDAPIN)&&(i<I2C_ACK_ERROR))
		i++;									//wait for ack from the slave (ack = sda pulled to low by the slave
	sI2C_LOW(sI2CSCLPIN);
	if (i<I2C_ACK_ERROR) return I2C_ACK;		//no trouble
	else return I2C_NOACK;						//trouble! ack timed out
}

//-----------------------i2c read------------------------------
//to be consistent with i2c protocol, use negative logic
//ack = 0 -> send ack
//ack = 1 -> no ack
uint8_t sI2CRead(uint8_t ack) {
	unsigned char i, data_t=0;

	sI2C_HIGH(sI2CSDAPIN);						//let sda float
	i=0x80;
	do {
		sI2C_LOW(sI2CSCLPIN);					//clear i2c_scl
		data_t <<=1;							//left shift the data
		i = i >> 1;
		//i2c_delay(0); i2c_delay(0);i2c_delay(0);i2c_delay(0);
		sI2C_HIGH(sI2CSCLPIN);					//let scl float to high
		if (sI2C_GET(sI2CSDAPIN)) data_t |= 0x01;	//set the last bit high
		else data_t |= 0x00;
		//i2c_delay(0);
	} while (i);
	sI2C_LOW(sI2CSCLPIN);						//pull scl low
	if (ack==I2C_ACK)
		{sI2C_LOW(sI2CSDAPIN);}					//send ack
	else
		{sI2C_HIGH(sI2CSDAPIN);}				//send no-ack
	sI2C_HIGH(sI2CSCLPIN);						//send ack/no-ack
	sI2C_LOW(sI2CSCLPIN);
	return data_t;
}

//write from a buffer
uint8_t sI2CWrites(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite) {
	sI2CStart();							//send start condition
	sI2CWrite(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	sI2CWrite(RegAddr);					//send register addr
	while (NumByteToWrite) {
		sI2CWrite(*pBuffer);				//send data
		pBuffer++;							//increment buffer pointer
		NumByteToWrite--;					//decrement counter
	}
	sI2CStop();							//send stop condition
	return 0;								//indicating success
}

//read to a buffer
uint8_t sI2CReads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead) {
	sI2CStart();							//send start condition
	sI2CWrite(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	sI2CWrite(RegAddr);					//send register addr
	sI2CStart();							//send restart
	sI2CWrite(DeviceAddr | I2C_CMD_READ);	//send device addr, for read operations
	while (NumByteToRead) {
		if (NumByteToRead==1) {
			*pBuffer=sI2CRead(I2C_NOACK);
			sI2CStop();							//send the stop condition
			break;
		}
		*pBuffer=sI2CRead(I2C_ACK);		//read the data
		pBuffer++;							//increment buffer
		NumByteToRead--;					//decrement count
	}
	return 0;
}

//end software i2c

//rtcc
//initialize the rtcc
//clock source choosen in config bits: RTCOSC (SOSC and LPRC)
void RTCInit(void) {
	PMD3bits.RTCCMD = 0;						//0->enable power to rtcc
	//enable sosc
	di();
	__builtin_write_OSCCONL(OSCCON | (1<<1));	//1->enable sosc, 0->disable sosc
	ei();
	RTCC_WREN();								//allows write to rtc registers
	RCFGCALbits.RTCEN=1;						//start the rtc
	RTCC_WRDIS();
}

//read from rtcc
//mask: 0b00->min.sec, 0b01->weekday.hour, 0b10->month.day, 0b11->..year
uint16_t RTCRead(uint16_t mask) {
	uint16_t tmp;
	//RTCC_WREN();								//allows write to rtc registers
	//RCFGCAL &= RTCC_MASK;						//mask off all bits not related to pointers
	//RCFGCAL |= mask;							//point to min/sec
	RCFGCALbits.RTCPTR=mask;
	tmp = RTCVAL;								//return the lower byte
	//RTCC_WRDIS();
	return tmp;
}

//write to rtcc
void RTCWrite(uint16_t mask, uint16_t byte_t) {
	RTCC_WREN();								//allows write to rtc registers
	//RCFGCAL &= RTCC_MASK;						//mask off all bits not related to pointers
	//RCFGCAL |= mask;							//point to min/sec
	RCFGCALbits.RTCPTR=mask;
	RTCVAL = byte_t;							//return the lower byte
	RTCC_WRDIS();
}

//write to rtcc calibration register
//-512 .. +508 RTC pulses every minute
//+/- 260ppm adjustments, 2ppm / step
int8_t RTCSetCal(int8_t cal) {
	RTCC_WREN();								//allows write to rtc registers
	RCFGCALbits.CAL=cal;
	RTCC_WRDIS();
	return cal;
}

//read from rtcc calibration register
//uint8_t RTCGetCal(void) {
//	return RCFGCALbits.CAL;
//}

//convert rtcc to time_t
time_t RTC2time(time_t *t) {
	struct tm tm;
	uint16_t year, mondat, wkhour, minsec;
	uint8_t tmp;

	//read the rtcc
	RCFGCALbits.RTCPTR=3;			//start from reading year, decreaments after each read
	year  =RTCVAL;					//year since 1/1/2000
	mondat=RTCVAL;					//month (0..11) and date (1..31)
	wkhour=RTCVAL;					//weekday (0..6) and hour (0..23)
	minsec=RTCVAL;					//minute (0..59) and second (0..59)

	tmp = minsec;	tm.tm_sec = BCD2DEC(tmp);
	tmp = minsec>>8;tm.tm_min = BCD2DEC(tmp);
	tmp = wkhour;	tm.tm_hour= BCD2DEC(tmp);
	tmp = mondat; 	tm.tm_mday= BCD2DEC(tmp);
	tmp = mondat>>8;tm.tm_mon = BCD2DEC(tmp)-1;			//month = 0..11
	tmp = year;     tm.tm_year= BCD2DEC(tmp)+2000-1900;	//dspic33 RTCC starts at 1/1/2000, posix year relative to 1/1/1970
	if (t==NULL) return mktime(&tm); 						//just return seconds since epoch time if pointer is NULL
	return *t=mktime(&tm);									//change pointed value + return seconds since epoch time
}

//turn time (=time_t) to RTCC
time_t time2RTC(time_t t) {
	struct tm *tmptr;
	uint16_t year, mondat, wkhour, minsec;
	//uint8_t tmp;

	t=(t<946684800ul)?946684800ul:t;					//minimum time is 1/1/2000 for the hardware rtc
	tmptr=gmtime(&t);
	minsec = (DEC2BCD(tmptr->tm_min) << 8) | DEC2BCD(tmptr->tm_sec);
	wkhour =                                  DEC2BCD(tmptr->tm_hour);
	mondat = (DEC2BCD(tmptr->tm_mon+1)<<8) | DEC2BCD(tmptr->tm_mday);
	year   =                                  DEC2BCD(tmptr->tm_year+1900-2000);	//posix starts at 1/1/1900 and dspic33 RTCC starts at 1/1/2000
	//set rtcc
	RTCC_WREN();							//enable write to rtcc
	//write to the rtcc
	RCFGCALbits.RTCPTR=3;					//start from reading year, decreaments after each read
	RTCVAL = year;							//year since 1/1/2000
	RTCVAL = mondat;						//month (0..11) and date(1..31)
	RTCVAL = wkhour;						//weekday (0..6) and hour (0..23)
	RTCVAL = minsec;						//minute (0..59) and second (0..59)
	RTCC_WRDIS();							//disable write to rtcc
	return t;
}

//end rtcc

//software rtc
volatile sRTC_TypeDef sRTC={-1, 0, 0, 0};		//software RTC

//initialize software counter
void sRTCInit(void) {					//calibration from -128ppm to +128ppm, if sRTC_RATE = 1M
	//sRTC.tick_rate=sRTC_RATE;
	sRTC.time=-1;						//reset counter: -1=uninitiated timer
	sRTC.tick=0;						//reset the tick counter
	sRTC.cal=0;							//initialize calibration
	sRTC.halfsec=0;						//0->1st half sec, 1->2nd half sec
}

//initialize the calibration
void sRTCSetCal(int16_t cal) {
	sRTC.cal=cal;						//not implemented
}

//increment sRTC time - called sRTC_CALLRATE per second
void sRTCISR(void) {
	uint32_t tks=ticks();				//timestamp
	if (tks - sRTC.tick >= F_CPU) {	//if enough time has passed
		sRTC.tick += F_CPU;				//update tick
		sRTC.time += 1;					//advance time
	}
	sRTC.halfsec=(tks - sRTC.tick < F_CPU / 2)?0:1;	//half sec
}

//read sRTC second counter
time_t sRTC2time(time_t *t) {
	if (t==NULL) return sRTC.time;
	return *t=sRTC.time;
}

//set sRTC second counter - used for initialization
//returns -1 if uninitialized
time_t time2sRTC(time_t t) {
	return sRTC.time=t;
}

//read rtc tick
uint32_t sRTCTick(void) {
	return sRTC.tick;
}

//return half sec
//0: first half of a sec
//1: 2nd half of a sec
uint8_t sRTCHalfsec(void) {
	return sRTC.halfsec;
}

//end software rtc

//cnint
void (* _cn_isrptr) (void)=empty_handler;

void _ISR_PSV _CNInterrupt(void) {
	IFS1bits.CNIF = 0; 							//clear the flag
	_cn_isrptr();								//run the isr
}

//initialize change notification
void cnInit(uint32_t pins) {
	_cn_isrptr=empty_handler;					//reset the isr

	//enable power - always enabled

	IFS1bits.CNIF = 0;							//clear the flag
	IEC1bits.CNIE = 1;							//1->enable the interrupt, 0->disable the interrupt

	//set up cnie
	CNEN1 = pins;
	CNPU1 = pins;
	pins = pins >> 16;
	CNEN2 = pins;
	CNPU2 = pins;

	IEC1bits.CNIE = 1;							//1->enable the interrupt, 0->disable the interrupt
}

//attach user isr
void cnAttachISR(void (*isrptr) (void)) {
	_cn_isrptr = isrptr;						//point the isrptr
	IFS1bits.CNIF= 0;							//0->clear the flag
	IEC1bits.CNIE= 1;							//0->disable the interrupt
}

//end cnint

//crc, 16-bit and 32-bit
//initialize crc engine: little endian, no interrupt
//weight in xor, and initial value in init
void CRCInit(uint8_t len, uint32_t poly) {
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__) | \
			defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
			defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
			defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
	PMD3bits.CRCMD = 0;							//0->enable the model, 1->disable the model

	//configure the crc engine
	CRCCON1 = CRCCON2 = 0;						//reset the configuration word
	CRCCON1bits.LENDIAN=0;						//0->data shifting LSB first (little endian), 1->data shifting MSB first (big endian)
	CRCCON1bits.CRCISEL=0;						//0->CRCIF set on shift completion; 1->CRCIF set on buffer empty
	//CRCCON1bits.CRCGO  =1;					//1->start crc shift, 0->crc shifter turned off

	CRCCON2bits.PLEN = len-1;	//0..31: length of CRC. 0x07->8bit, 0x0f->16 bit, 0x1f->32 bit
	CRCCON2bits.DWIDTH = CRCCON2bits.PLEN;		//set data width to plen

	//CRCXORH = CRCXORL = 0;					//crc xor registers
	//CRCXORH = xor >> 16; CRCXORL = xor;		//configure the xor words
	CRCXOR = poly;

	//CRCWDATH= init >> 16; CRCWDATL = init;
	//CRCWDAT = init;

	IFS4bits.CRCIF = 0;							//0->clear the flag, 1->set the flag
	IPC16bits.CRCIP= CRCIP_DEFAULT;				//set the interrupt priority
	//IPC16bits.CRCIS= CRCIS_DEFAULT;			//set the interrupt subpriority
	IEC4bits.CRCIE = 0;							//0->disable the interrupt, 1->enable the interrupt

	CRCCON1bits.CRCEN = 1;						//1->enable the model, 0->disable the model
#else	//ga00x chips
#if defined(__PIC24GA00x__)
	PMD3bits.CRCPMD = 0;							//0->enable the model, 1->disable the model
#else	//ga11x
	PMD3bits.CRCMD = 0;							//0->enable the model, 1->disable the model
#endif
	//configure the crc engine
	CRCCON = 0;									//reset the configuration word
	//CRCCONbits.LENDIAN=0;						//0->data shifting LSB first (little endian), 1->data shifting MSB first (big endian)
	//CRCCONbits.CRCISEL=0;						//0->CRCIF set on shift completion; 1->CRCIF set on buffer empty
	//CRCCON1bits.CRCGO  =1;					//1->start crc shift, 0->crc shifter turned off

	CRCCONbits.PLEN = len-1;	//0..31: length of CRC. 0x07->8bit, 0x0f->16 bit, 0x1f->32 bit
	//CRCCONbits.DWIDTH = CRCCON2bits.PLEN;		//set data width to plen

	//CRCXORH = CRCXORL = 0;					//crc xor registers
	//CRCXORH = xor >> 16; CRCXORL = xor;		//configure the xor words
	CRCXOR = poly;

	//CRCWDATH= init >> 16; CRCWDATL = init;
	//CRCWDAT = init;

	IFS4bits.CRCIF = 0;							//0->clear the flag, 1->set the flag
	IPC16bits.CRCIP= CRCIP_DEFAULT;				//set the interrupt priority
	//IPC16bits.CRCIS= CRCIS_DEFAULT;			//set the interrupt subpriority
	IEC4bits.CRCIE = 0;							//0->disable the interrupt, 1->enable the interrupt

	//CRCCONbits.CRCEN = 1;						//1->enable the model, 0->disable the model
#endif	//ga102
}

//calculate crc
//length must be multiples of 2
uint16_t CRC16(char *msg, uint16_t length, uint16_t init_val) {
	uint16_t tmp;
#if defined(__PIC24GA10x__)
	/*#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
			defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)*/
	CRCWDAT = init_val;							//load the initial word
	CRCCON1bits.CRCGO = 1;						//CRCGo(); //while (CRCCON1bits.CRCMPT==0) continue;	//wait for crc to complete

	while (length) {
		//tmp = *(uint16_t *)msg++;				//load the data
		//tmp = ((uint16_t) (*msg++) << 8) | (*msg++);
		tmp = *msg++;
		tmp = tmp << 8;			//form the data
		tmp|= *msg++;
		while (CRCCON1bits.CRCFUL==1) continue;	//wait for buffer to have at least 1 space
		CRCDAT = tmp;
		length-=2;
	}

	while (CRCCON1bits.CRCFUL==1) continue;		//wait until CRC is not full
	CRCDAT = 0;									//shift out the last two bytes
	while (CRCCON1bits.CRCMPT==0) continue;
	NOP4();										//wait for the shift to complete. 1 NOP() is enough
	//CRCCON1bits.CRCGO=0;						//why?
	//while (CRCCON1bits.CRCGO == 1) continue;

#else
	CRCWDAT = init_val;							//load the initial word
	CRCCONbits.CRCGO = 1;						//CRCGo(); //while (CRCCON1bits.CRCMPT==0) continue;	//wait for crc to complete

	while (length) {
		//tmp = *(uint16_t *)msg++;				//load the data
		//tmp = ((uint16_t) (*msg++) << 8) | (*msg++);
		tmp = *msg++;
		tmp = tmp << 8;			//form the data
		tmp|= *msg++;
		while (CRCCONbits.CRCFUL==1) continue;	//wait for buffer to have at least 1 space
		CRCDAT = tmp;
		length-=2;
	}

	while (CRCCONbits.CRCFUL==1) continue;		//wait until CRC is not full
	CRCDAT = 0;									//shift out the last two bytes
	while (CRCCONbits.CRCMPT==0) continue;
	NOP4();										//wait for the shift to complete. 1 NOP() is enough
	//CRCCON1bits.CRCGO=0;						//why?
	//while (CRCCON1bits.CRCGO == 1) continue;

#endif

	return CRCWDAT;
}

//comparator voltage reference
void CVrefInit(void) {
	//no PMD bits?

	CVRCON = 0;									//reset value
	CVRCONbits.CVRR = 1;						//1->0..0.625 in 24 steps. 0->0.25..0.719 in 32 steps
	//output disabled
	//
	CVRCONbits.CVREN = 1;						//enable the module
}
//end comparator voltage reference

//comparator
#if defined(__PIC24GA10x__) | defined(__PIC24GB00x__) | defined(__PIC24GA11x__) | defined(__PIC24GB11x__)
/*#if 	defined(__PIC24FJ64GA102__) | defined(__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined(__PIC24FJ32GA104__) | \
	 	defined(__PIC24FJ64GB002__) | defined(__PIC24FJ64GB004__) | \
		defined(__PIC24FJ48GB002__) | defined(__PIC24FJ48GB004__) | \
		defined(__PIC24FJ32GB002__) | defined(__PIC24FJ32GB004__)*/
//initialize comparator
void CM1Init(void) {
	PMD3bits.CMPMD = 0;							//1->disable the module, 0->enable the model

	CM1CON = 0;									//reset value
	CM1CONbits.CEN = 1;							//1->enable the module, 0->disable the module
}

void CM2Init(void) {
	PMD3bits.CMPMD = 0;							//1->disable the module, 0->enable the model

	CM2CON = 0;									//reset value
	CM2CONbits.CEN = 1;							//1->enable the module, 0->disable the module
}

void CM3Init(void) {
	PMD3bits.CMPMD = 0;							//1->disable the module, 0->enable the model

	CM3CON = 0;									//reset value
	CM3CONbits.CEN = 1;							//1->enable the module, 0->disable the module
}
#else		//ga002 devices
//initialize comparator
void CM1Init(void) {
	PMD3bits.CMPMD = 0;							//1->disable the module, 0->enable the model

	CMCON = CMCON & 0b0010101010101100;			//reset value
	CMCONbits.C1EN = 1;							//1->enable the module, 0->disable the module
}

void CM2Init(void) {
	PMD3bits.CMPMD = 0;							//1->disable the module, 0->enable the model

	CMCON = CMCON &~0b0010101010101100;			//reset value
	CMCONbits.C2EN = 1;							//1->enable the module, 0->disable the module
}
#endif

//end comparator

//circular buffer
//global defines
#define cBUFF_SIZE_MASK 	(cBUFF_SIZE-1U)		//mask

//global variables
//reset the cbuffer
void cbInit(CB_TypeDef *cbuffer) {
	cbuffer->writeIndex = cbuffer->readIndex = -1;
}

//returns true if cbuffer is empty
char cbEmpty(CB_TypeDef *cbuffer) {
	return (cbuffer->writeIndex & cBUFF_SIZE_MASK) == (cbuffer->readIndex & cBUFF_SIZE_MASK);
}

//returns true if cbuffer is full;
char cbFull(CB_TypeDef *cbuffer) {
	return ((cbuffer->writeIndex + 1) & cBUFF_SIZE_MASK) == (cbuffer->readIndex & cBUFF_SIZE_MASK);
}

//write to the buffer - needs to test if the buffer is full before writing to it
cbuffer_t cbWrite(CB_TypeDef *cbuffer, cbuffer_t dat) {
	cbuffer->buffer[(++cbuffer->writeIndex) & cBUFF_SIZE_MASK] = dat;
	return dat;
}

//read from the buffer - needs to test if the buffer is empty before reading from it
cbuffer_t cbRead(CB_TypeDef *cbuffer) {
	return cbuffer->buffer[(++cbuffer->readIndex) & cBUFF_SIZE_MASK];
}

//write string to CB
void str2cb(CB_TypeDef *cb, char *str) {
	while (!cbFull(cb) && (*str)) cbWrite(cb, *str++);
}

//write CB to string
void cb2str(char *str, CB_TypeDef *cb) {
	while (!cbEmpty(cb)) *str++=cbRead(cb);
}

//end circular buffer
