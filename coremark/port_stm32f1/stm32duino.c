#include "stm32duino.h"				//stm32duino

//global defines

//global variables
//declare pins
//ALL PINS ARE MAPPED, WHETHER THEY EXIST OR NOT
//SO MAKE SURE THAT THE PINS YOU PICKED ACTUALLY EXIST FOR YOUR PACKAGE
//Pin  0.. 7 -> GPIOA
//Pin  8..15 -> GPIOB
const PIN2GPIO GPIO_PinDef[]={
#if defined(GPIOA)
	{GPIOA, 1<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOA, 1<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOA, 1<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOA, 1<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOA, 1<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOA, 1<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOA, 1<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOA, 1<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOA, 1<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOA, 1<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOA, 1<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOA, 1<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOA, 1<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOA, 1<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOA, 1<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOA, 1<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif
#if defined(GPIOB)
	{GPIOB, 1<<0},						//STM32duino Pin 16 = RP0/PB0/CHIP PIN4
	{GPIOB, 1<<1},						//STM32duino Pin 17 = RP1/PB1/CHIP PIN5
	{GPIOB, 1<<2},						//STM32duino Pin 18 = RP2/PB2/CHIP PIN6
	{GPIOB, 1<<3},						//STM32duino Pin 19 = RP3/PB3/CHIP PIN7
	{GPIOB, 1<<4},						//STM32duino Pin 20 = RP4/PB4/CHIP PIN11
	{GPIOB, 1<<5},						//STM32duino Pin 21 = RP5/PB5/CHIP PIN14
	{GPIOB, 1<<6},						//STM32duino Pin 22 = RP6/PB6/CHIP PIN15
	{GPIOB, 1<<7},						//STM32duino Pin 23 = RP7/PB7/CHIP PIN16
	{GPIOB, 1<<8},						//STM32duino Pin 24 = RP8/PB8/CHIP PIN17
	{GPIOB, 1<<9},						//STM32duino Pin 25 = RP9/PB9/CHIP PIN18
	{GPIOB, 1<<10},						//STM32duino Pin 26 = RP10/PB10/CHIP PIN21
	{GPIOB, 1<<11},						//STM32duino Pin 27 = RP11/PB11/CHIP PIN22
	{GPIOB, 1<<12},						//STM32duino Pin 28 = RP12/PB12/CHIP PIN23
	{GPIOB, 1<<13},						//STM32duino Pin 29 = RP13/PB13/CHIP PIN24
	{GPIOB, 1<<14},						//STM32duino Pin 30 = RP14/PB14/CHIP PIN25
	{GPIOB, 1<<15},						//STM32duino Pin 31 = RP15/PB15/CHIP PIN26
#endif
	
#if defined(GPIOC)
	{GPIOC, 1<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOC, 1<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOC, 1<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOC, 1<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOC, 1<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOC, 1<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOC, 1<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOC, 1<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOC, 1<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOC, 1<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOC, 1<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOC, 1<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOC, 1<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOC, 1<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOC, 1<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOC, 1<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOC

#if defined(GPIOD)						//pins 48..63
	{GPIOD, 1<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOD, 1<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOD, 1<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOD, 1<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOD, 1<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOD, 1<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOD, 1<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOD, 1<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOD, 1<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOD, 1<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOD, 1<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOD, 1<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOD, 1<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOD, 1<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOD, 1<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOD, 1<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOD

#if defined(GPIOE)						//pins 64..79
	{GPIOE, 1<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOE, 1<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOE, 1<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOE, 1<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOE, 1<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOE, 1<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOE, 1<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOE, 1<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOE, 1<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOE, 1<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOE, 1<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOE, 1<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOE, 1<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOE, 1<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOE, 1<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOE, 1<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOE

#if defined(GPIOF)						//pins 80..96
	{GPIOF, 1<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOF, 1<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOF, 1<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOF, 1<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOF, 1<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOF, 1<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOF, 1<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOF, 1<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOF, 1<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOF, 1<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOF, 1<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOF, 1<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOF, 1<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOF, 1<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOF, 1<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOF, 1<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOF

#if defined(GPIOG)						//pins 80..96
	{GPIOG, 1<<0},						//STM32duino Pin 32 = RP0/PB0/CHIP PIN4
	{GPIOG, 1<<1},						//STM32duino Pin 33 = RP1/PB1/CHIP PIN5
	{GPIOG, 1<<2},						//STM32duino Pin 34 = RP2/PB2/CHIP PIN6
	{GPIOG, 1<<3},						//STM32duino Pin 35 = RP3/PB3/CHIP PIN7
	{GPIOG, 1<<4},						//STM32duino Pin 36 = RP4/PB4/CHIP PIN11
	{GPIOG, 1<<5},						//STM32duino Pin 37 = RP5/PB5/CHIP PIN14
	{GPIOG, 1<<6},						//STM32duino Pin 38 = RP6/PB6/CHIP PIN15
	{GPIOG, 1<<7},						//STM32duino Pin 39 = RP7/PB7/CHIP PIN16
	{GPIOG, 1<<8},						//STM32duino Pin 40 = RP8/PB8/CHIP PIN17
	{GPIOG, 1<<9},						//STM32duino Pin 41 = RP9/PB9/CHIP PIN18
	{GPIOG, 1<<10},						//STM32duino Pin 42 = RP10/PB10/CHIP PIN21
	{GPIOG, 1<<11},						//STM32duino Pin 43 = RP11/PB11/CHIP PIN22
	{GPIOG, 1<<12},						//STM32duino Pin 44 = RP12/PB12/CHIP PIN23
	{GPIOG, 1<<13},						//STM32duino Pin 45 = RP13/PB13/CHIP PIN24
	{GPIOG, 1<<14},						//STM32duino Pin 46 = RP14/PB14/CHIP PIN25
	{GPIOG, 1<<15},						//STM32duino Pin 47 = RP15/PB15/CHIP PIN26
#endif	//GPIOG
};

//set up core timer
//global variables

//for time base off TIMER1 @ 1:1 prescaler
//volatile uint32_t timer1_millis = 0;
volatile uint32_t timer_ticks = 0;
//static uint16_t timer1_fract = 0;

//timer1 overflow isr
//void _ISR_PSV _T2Interrupt(void) {
//	IFS0bits.T2IF=0;					//clear tmr1 interrupt flag
//	timer_ticks+=0x10000ul;				//increment overflow count: 16-bit timer
//}

//configure gpio DDR mode (cnf1..0 + mod1..0 bits)
void GPIO_DDR(GPIO_TypeDef * gpio, uint32_t mask, uint32_t mode) {
	mode = mode & 0x0f;				//lowest 4 bits effective

	//for the lowest 8 bits
	if (mask & (1ul<< 0)) gpio->CRL = (gpio->CRL &~0x0000000ful) | (mode << (0 * 4));
	if (mask & (1ul<< 1)) gpio->CRL = (gpio->CRL &~0x000000f0ul) | (mode << (1 * 4));
	if (mask & (1ul<< 2)) gpio->CRL = (gpio->CRL &~0x00000f00ul) | (mode << (2 * 4));
	if (mask & (1ul<< 3)) gpio->CRL = (gpio->CRL &~0x0000f000ul) | (mode << (3 * 4));
	if (mask & (1ul<< 4)) gpio->CRL = (gpio->CRL &~0x000f0000ul) | (mode << (4 * 4));
	if (mask & (1ul<< 5)) gpio->CRL = (gpio->CRL &~0x00f00000ul) | (mode << (5 * 4));
	if (mask & (1ul<< 6)) gpio->CRL = (gpio->CRL &~0x0f000000ul) | (mode << (6 * 4));
	if (mask & (1ul<< 7)) gpio->CRL = (gpio->CRL &~0xf0000000ul) | (mode << (7 * 4));

	//for the highest 8 bits
	if (mask & (1ul<< 8)) gpio->CRH = (gpio->CRH &~0x0000000ful) | (mode << (0 * 4));
	if (mask & (1ul<< 9)) gpio->CRH = (gpio->CRH &~0x000000f0ul) | (mode << (1 * 4));
	if (mask & (1ul<<10)) gpio->CRH = (gpio->CRH &~0x00000f00ul) | (mode << (2 * 4));
	if (mask & (1ul<<11)) gpio->CRH = (gpio->CRH &~0x0000f000ul) | (mode << (3 * 4));
	if (mask & (1ul<<12)) gpio->CRH = (gpio->CRH &~0x000f0000ul) | (mode << (4 * 4));
	if (mask & (1ul<<13)) gpio->CRH = (gpio->CRH &~0x00f00000ul) | (mode << (5 * 4));
	if (mask & (1ul<<14)) gpio->CRH = (gpio->CRH &~0x0f000000ul) | (mode << (6 * 4));
	if (mask & (1ul<<15)) gpio->CRH = (gpio->CRH &~0xf0000000ul) | (mode << (7 * 4));

}


//reset clock to HSI
void SystemCoreClockHSI(void) {
	RCC->CR |= RCC_CR_HSION;				//turn on HSI
	//wait for HSI to be ready
	while ((RCC->CR & RCC_CR_HSIRDY) == 0) continue;	//1->HSI ready, 0->HSI not ready
	//switch the clock to HSI
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_SW) | (RCC_CFGR_SW & RCC_CFGR_SW_HSI);
#if defined(HSITRIM)
	HSITrimSet(HSITRIM);
#endif
	SystemCoreClockUpdate();				//update systemcoreclock
}

//reset clock to HSE
void SystemCoreClockHSE(void) {
	RCC->CR |= RCC_CR_HSEON;				//turn on HSE
	//wait for HSI to be ready
	while ((RCC->CR & RCC_CR_HSERDY) == 0) continue;	//1->HSE ready, 0->HSE not ready
	//switch the clock to HSE
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_SW) | (RCC_CFGR_SW & RCC_CFGR_SW_HSE);
	SystemCoreClockUpdate();				//update systemcoreclock
}

//switch to HSIxPLL
void SystemCoreClockHSIPLL(uint32_t PLLMul_x) {
	SystemCoreClockHSI();					//switch to HSI - so PLL can be disabled

	//RCC->CR |= RCC_CR_HSION;				//turn on HSI - so PLL can be disabled
	//wait for HSI to be ready
	//while ((RCC->CR & RCC_CR_HSIRDY) == 0) continue;	//1->HSI ready, 0->HSI not ready
	//HSI is ready now
	//switch the clock to HSI
	//RCC->CFGR = (RCC->CFGR &~RCC_CFGR_SW) | (RCC_CFGR_SW & RCC_CFGR_SW_HSI);

	//turn off PLL - doable only if PLL is NOT the system clock
	RCC->CR &=~RCC_CR_PLLON;				//1->pll on, 0->pll off
	//configure PLL multiplier
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_PLLMULL) | (RCC_CFGR_PLLMULL & PLLMul_x);	//set the pll multiplier
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_PLLSRC) | (RCC_CFGR_PLLSRC & RCC_CFGR_PLLSRC_HSI_Div2);		//0->HSI selected as pll source (pll input = HSI/2); 1->prediv1 as pll source
	RCC->CR |= RCC_CR_PLLON;				//1->pll on, 0->pll off
	while ((RCC->CR & RCC_CR_PLLRDY) == 0) continue;	//1->PLL ready, 0->pll not ready
	//switch the clock to PLL
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_SW) | (RCC_CFGR_SW & RCC_CFGR_SW_PLL);
	//now hsi/2pll is the clock source
	SystemCoreClockUpdate();				//update systemcoreclock
}

//switch to HSExPLL
//Predivx makes sure that PLL output frequency is less than 24Mhz
void SystemCoreClockHSEPLL(uint32_t PLLMul_x/*, uint32_t PREDIV_x*/) {
	SystemCoreClockHSI();					//switch to HSI - so PLL can be disabled

	RCC->CR |= RCC_CR_HSEON;				//turn on HSE
	//wait for HSI to be ready
	while ((RCC->CR & RCC_CR_HSERDY) == 0) continue;	//1->HSI ready, 0->HSI not ready
	//HSE is ready now
	//switch the clock to HS
	//RCC->CFGR = (RCC->CFGR &~RCC_CFGR_SW) | (RCC_CFGR_SW & RCC_CFGR_SW_HSE);

	//turn off PLL - doable only if PLL is NOT the system clock
	RCC->CR &=~RCC_CR_PLLON;				//1->pll on, 0->pll off
	//configure predivider
	//RCC->CFGR = (RCC->CFGR &~RCC_CFGR2_PREDIV1) | (RCC_CFGR2_PREDIV1 & PREDIV_x);
	//configure PLL multiplier
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_PLLMULL) | (RCC_CFGR_PLLMULL & PLLMul_x);	//set the pll multiplier
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_PLLSRC) | (RCC_CFGR_PLLSRC & (1<<16));		//0->HSI selected as pll source (pll input = HSI/2); 1->prediv1 as pll source
	RCC->CR |= RCC_CR_PLLON;				//1->pll on, 0->pll off
	while ((RCC->CR & RCC_CR_PLLRDY) == 0) continue;	//1->PLL ready, 0->pll not ready
	//switch the clock to PLL
	RCC->CFGR = (RCC->CFGR &~RCC_CFGR_SW) | (RCC_CFGR_SW & RCC_CFGR_SW_PLL);
	//now hsi/2pll is the clock source
	SystemCoreClockUpdate();				//update systemcoreclock
}

//get AHB speed
uint32_t AHBClock(void) {
	uint32_t tmp;

	SystemCoreClockUpdate();					//update systemcoreclock
	tmp = SystemCoreClock;

	switch (RCC->CFGR & RCC_CFGR_HPRE) {
		case RCC_CFGR_HPRE_DIV2:   tmp /= 2; break;
		case RCC_CFGR_HPRE_DIV4:   tmp /= 4; break;
		case RCC_CFGR_HPRE_DIV8:   tmp /= 8; break;
		case RCC_CFGR_HPRE_DIV16:  tmp /= 16; break;
		case RCC_CFGR_HPRE_DIV64:  tmp /= 64; break;
		case RCC_CFGR_HPRE_DIV128: tmp /= 128; break;
		case RCC_CFGR_HPRE_DIV256: tmp /= 256; break;
		case RCC_CFGR_HPRE_DIV512: tmp /= 512; break;
	}

	return tmp;
}

//get APB1 speed
uint32_t APB1Clock(void) {
	uint32_t tmp;

	tmp = F_AHB;								//get AHB speed

	switch (RCC->CFGR & RCC_CFGR_PPRE1) {
		case RCC_CFGR_PPRE1_DIV2:   tmp /= 2; break;
		case RCC_CFGR_PPRE1_DIV4:   tmp /= 4; break;
		case RCC_CFGR_PPRE1_DIV8:   tmp /= 8; break;
		case RCC_CFGR_PPRE1_DIV16:  tmp /= 16; break;
	}

	return tmp;
}

//get APB2 speed
uint32_t APB2Clock(void) {
	uint32_t tmp;

	tmp = F_AHB;								//get AHB speed

	switch (RCC->CFGR & RCC_CFGR_PPRE2) {
		case RCC_CFGR_PPRE2_DIV2:   tmp /= 2; break;
		case RCC_CFGR_PPRE2_DIV4:   tmp /= 4; break;
		case RCC_CFGR_PPRE2_DIV8:   tmp /= 8; break;
		case RCC_CFGR_PPRE2_DIV16:  tmp /= 16; break;
	}

	return tmp;
}

//global variables
//for time base off SysTick (24-bit counter)
volatile uint32_t systick_ovf = 1ul<<24;						//time base on Systick -> SysTick->VAL being the lowest 24-bits (SysTick is a downcounter)
static void (* _systick_isrptr)(void)=empty_handler;				//systick_ptr pointing to empty_handler by default

//systick handler - to provide time base for millis()/micros()
void SysTick_Handler(void) {
	//clear the flag
	systick_ovf += 1ul<<24;						//increment systick counter - 24bit, 1:1 prescaler
	_systick_isrptr();									//execute user handler
}

//install systick isr
//activate the isr handler
void systickAttachISR(void (*isrptr)(void)) {
	_systick_isrptr = isrptr;
}


//reset the mcu
void mcuInit(void) {
	volatile uint32_t i=100000ul; while (i--) continue;
	
	//select the clock source, or use default clock
	//SystemCoreClockHSI();						//use HSi as system coreclock
	//SystemCoreClockHSIPLL2x5();				//use hsipll
	//SystemCoreClockHSE();						//use hse
	//SystemCoreClockHSEPLL1x5();				//use hsepll

#if defined(F_HSITRIM)
	RCC->CR = (RCC->CR &~(0x1f << 3)) | ((F_HSITRIM & 0x1f) << 3);
#endif

	//enable clock to GPIO
	RCC->APB2ENR |=
#if defined(RCC_APB2ENR_IOPAEN)
			RCC_APB2ENR_IOPAEN |
#endif
#if defined(RCC_APB2ENR_IOPBEN)
			RCC_APB2ENR_IOPBEN |
#endif
#if defined(RCC_APB2ENR_IOPCEN)
			RCC_APB2ENR_IOPCEN |
#endif
#if defined(RCC_APB2ENR_IOPDEN)
			RCC_APB2ENR_IOPDEN |
#endif
#if defined(RCC_APB2ENR_IOPEEN)
			RCC_APB2ENR_IOPEEN |
#endif
#if defined(RCC_APB2ENR_IOPFEN)
			RCC_APB2ENR_IOPFEN |
#endif
#if defined(RCC_APB2ENR_IOPGEN)
			RCC_APB2ENR_IOPGEN |
#endif
			0x00;

	//update SystemCoreClock - it must be the last step before exiting mcuInit
	SystemCoreClockUpdate();
	
	//start systick / coretick
	//use systick
	//configure Systick as the time base for millis()/micros()

#if defined(USE_CORETICK)
#if defined(CoreDebug_DEMCR_TRCENA_Msk)
	//use coretick
	//configure dwt as the time base for millis()/micros()
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;		//enable debug tracer
#endif
	//ITM->LAR = 0xC5ACCE55;						//unlock access to dwt, if so equip'd
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;			//enable dwt cycle count
	DWT->CYCCNT= 0;									//reset the counter
#endif

	//configure systick
	systick_ovf = 1ul<<24;											//SysTick is a 24-bit downcounter
	//for chips where SysTick_Config() is not defined in cmsis
	SysTick->LOAD  = 	(systick_ovf-1)/*ticks*/ & SysTick_LOAD_RELOAD_Msk;      /* set reload register */
	SysTick->VAL   = 	0;                                          /* Load the SysTick Counter Value */
	SysTick->CTRL  = 	SysTick_CTRL_CLKSOURCE_Msk |
						SysTick_CTRL_TICKINT_Msk   |
						SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
	_systick_isrptr=	empty_handler;								//default handler - do nothing
	NVIC_SetPriority 	(SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Systick Interrupt */
	//NVIC_EnableIRQ(SysTick_IRQn);									//enable systick irq
	
	//alternative - for CMSIS-equip'd chips
	//SysTick_Config(SysTick_LOAD_RELOAD_Msk);			//reload all 24 bits

	//enable global interrupts
	ei();										//testing

}

//return timer clicks
//execution time = 30 ticks, no optimization
uint32_t systicks(void) {
	volatile uint32_t m;
	volatile uint32_t f;

	//do a double read
	do {
		m = systick_ovf;				//read the overflow counter
		f = SysTick->VAL;				//read the least significant 16-bits
	} while (m != systick_ovf);			//guard against overflow

	return (m - f) << 0;				//systick is a 24-bit downcounter
}

//empty interrupt handler
void empty_handler(void) {
	//do nothing here
}

//C main loop
int main(void) {

	mcuInit();						//reset the mcu
	setup();						//run the setup code
	while (1) {
		loop();						//run the default loop
	}
}


//Arduino Functions: GPIO
//set a pin mode to INPUT or OUTPUT
//no error checking on PIN
#define inline						//supress inline decalration
inline void pinMode(PIN_TypeDef pin, uint8_t mode) {
	GPIO_TypeDef *gpio=GPIO_PinDef[pin].gpio;
	uint16_t mask = GPIO_PinDef[pin].mask;
	
	//if (mode==OUTPUT) IO_OUT(gpio, mask); else IO_IN(gpio, mask);
	switch (mode) {
		case OUTPUT: 		IO_OUTPP(gpio, mask); break;
		case OUTPUT_OD: 	IO_OUTOD(gpio, mask); break;
		case INPUT: 		IO_INFL(gpio, mask); break;
		case INPUT_PU: 		IO_INPU(gpio, mask); break;
		case INPUT_PD: 		IO_INPD(gpio, mask); break;
	}
}

//set / clear a pin
inline void digitalWrite(PIN_TypeDef pin, uint8_t val) {
	GPIO_TypeDef *gpio=GPIO_PinDef[pin].gpio;
	uint16_t mask = GPIO_PinDef[pin].mask;
	
	if (val==LOW) IO_CLR(gpio, mask); else IO_SET(gpio, mask);
}

//read a pin
inline int digitalRead(PIN_TypeDef pin) {
	GPIO_TypeDef *gpio=GPIO_PinDef[pin].gpio;
	uint16_t mask = GPIO_PinDef[pin].mask;

	return (IO_GET(gpio, mask))?HIGH:LOW;
}
//end GPIO

//ticks()
//Arduino Functions: Time
//return timer ticks
	
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

//generic uart reset routine
void uartInit(USART_TypeDef *USARTx, unsigned long baudrate) {
    USARTx->CR1 &=~(1<<13);			//'0'->disable uart, '1'->enable uart
    USARTx->CR1 = 	(0<<15) |		//'0'->oversample by 16, '1'->oversample by 8
    				(0<<13) |		//'0'->disable uart, '1'->enable uart
    				(0<<12) |		//'0'->1 start bit, 8 data bit, n stop bit, '1'->1 start bit, 9 data bit, n stop bit
    				(0<<11) |		//'0'->idle line, '1'->wake by address
    				(0<<10) |		//'0'->disable parity, '1'->enable parity
    				(0<< 9) |		//'0'->even parity, '1'->odd parity
    				(0<< 8) |		//'0'->PE interrupt disabled, '1'->pe interrupt enabled
    				(0<< 7) |		//'0'->tx empty interrupt disabled, '1'-tx empty interrupt enabled
    				(0<< 6) |		//'0'->transmission completion interrupt disabled, '1'->transmission complete interrupt enabled
    				(0<< 5) |		//'0'->rx not empty interrupt disabled, '1'->rx not empty interrupt enabled
    				(0<< 4) |		//'0'->idle interrupt disabled, '1'->idle interrupt enabled
    				(1<< 3) |		//'0'->disable tx, '1'->enable tx
    				(1<< 2) |		//'0'->disable rx, '1'->enable rx
    				(0<< 1) |		//'0'->disable receiver wake-up, '1'->enable receiver wake-up
    				(0<< 0) |		//'0'->no break char is transmitted, '1'->break char will be transmitted
    				0x00;
    USARTx->CR2 = 	(0<<14) |		//'0'->LIN mode disabled, '1'->LIN mode enabled
    				(0<<12) |		//0->1 stop bit, 1->0.5 stop bit, 2->2 stop bit, 3 -> 1.5 stop bit
    				(0<<11) |		//'0'->SCLK pin disabled, '1'->SCLK pin enabled
    				(0<<10) |		//'0'->SCLK idles low, '1'->SCLK idles high
    				(0<< 9) |		//'0'->first clock transition is first data capture edge, '1'->second clock transition is the first data capture edge
    				(0<< 8) |		//'0'->clock pulse of the last data bit is not output to the sclk pin, '1'->clock pulse of the last data bit is output to the sclk pin
    				(0<< 6) |		//'0'->LIN break detection interrupt disabled, '1'->LIN break detection interrupt enabled
    				(0<< 5) |		//'0'->LIN break detection is 10-bit, '1'->LIN break detection is 11 bit
    				(0<< 0) |		//address of the uart node
    				0x00;
    USARTx->CR3 = 	(0<<11) |		//'0'->three sample bit, '1'->one sample bit
    				(0<<10) |		//'0'->CTS interrupt disabled, '1'->CTS interrupt enabled
    				(0<< 9) |		//'0'->CTS disabled, '1'->CTS enabled
    				(0<< 8) |		//'0'->RTS interrupt disabled, '1'->RTS interrupt enabled
    				(0<< 5) |		//'0'->smartcard mode disabled, '1'->smartcard mode enabled
    				(0<< 4) |		//'0'->smartcard nack disabled, '1'->smartcard nack enabled
    				(0<< 3) |		//'0'->half duplex mode not selected, '1'->half duplex mode selected
    				(0<< 2) |		//'0'->irda normal mode, '1'->irda low-power mode
    				(0<< 1) |		//'0'->irda disabled, '1'->irda enabled
    				(0<< 0) |		//'0'->error interrupt disabled, '1'->error interrupt enabled
    				0x00;
    if (F_UART / 2 / baudrate < 16) USARTx->CR1 |= (1<<15);		//brr is at least 16 if bit 15 is 0, 8 if 1
	//set the baudrate register
    USARTx->BRR = /*SystemCoreClock*/F_UART / baudrate * 2 / ((USARTx->CR1 & (1<<15))?1:2);		//per datasheet, for OVER8=0 or 1
    USARTx->DR = 0;					//reset the data register
    USARTx->SR = 0;					//reset the data register
    //enable uart1
    USARTx->CR1 |= (1<<13);			//'0'->disable uart, '1'->enable uart
}

//generic print to uart buffer
void uPrint(char *uRAM, int32_t dat) {
	uint8_t idx=20;						//buffer index
	uint8_t negFlag=0;					//flag for negative sign: 1->negative, 0->positive

	if (dat<0) {negFlag = 1; dat = -dat;}
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
	uRAM[idx--]=negFlag?'-':' ';
}


//uart1
//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart1Init(unsigned long baudrate) {
    //configure uart1
    //route clock to uart1
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

	//reset uart
	uartInit(USART1, baudrate);

    //configure the RX-PA9/TX-PA10 pins - GPIO clock assumed enabled here previously
    //IO_INFL(GPIOA, 1<<9);			//RX as floating input/AF input
    //IO_AFPP(GPIOA, 1<<10);			//TX as AFPP
#if defined(U1TX2PIN)
	U1TX2PIN();
#endif
#if defined(U1RX2PIN)
	U1RX2PIN();
#endif
}

void uart1Putch(char ch) {
	   //while (!(USART1->SR & USART_SR_TXE));    	//wait for the transmission buffer to be empty
	    while (uart1Busy()) continue;    			//wait for the transmission buffer to be empty
	    USART1->DR = ch;                        	//load the data buffer
	    //while (!(USART1->SR & (1<<6)));    		//wait for the transmission to complete
}

//put a string
void uart1Puts(char *str) {
	while (*str) uart1Putch(*str++);
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
void uart1Putline(char *ln) {
	//USARTWriteString(ln);
	uart1Puts(ln);
	//USARTWriteString("\r\n");
	uart1Puts((char *)"\r\n");
}

//get the received char
uint8_t uart1Getch(void) {
    //while (!(USART1->SR & USART_SR_RXNE));  	//wait for the receipt buffer to be empty
    return USART1->DR;                       	//save the transmission buffer
}

//test if data rx is available
uint16_t uart1Available(void) {
	//return (USART1->SR & USART_SR_TC)?true:false;
	return (USART1->SR & USART_SR_RXNE);
}

//test if uart tx is busy
uint16_t uart1Busy(void) {
    return !(USART1->SR & USART_SR_TXE);    	//return 1 if TX buffer is empty
}

//print to uart1
void u1Print(char *str, int32_t dat) {
	static char uRAM[uRAM_SIZE];				//transmission buffer, 40-1 char max
	
	strcpy(uRAM, str);							//copy to uarm
	uPrint(uRAM, dat);							//print to uBuffer
	uart1Puts(uRAM);							//send a message on uart1
}	


#if defined(USART2)
//uart2
//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart2Init(unsigned long baudrate) {
    //configure uart1
    //route clock to uart1
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	//reset uart
	uartInit(USART2, baudrate);

    //configure the RX-PA3/TX-PA2 pins - GPIO clock assumed enabled here previously
    //IO_INFL(GPIOA, 1<<3);			//RX as floating input/AF input
    //IO_AFPP(GPIOA, 1<<2);			//TX as AFPP
#if defined(U2TX2PIN)
	U2TX2PIN();
#endif
#if defined(U2RX2PIN)
	U2RX2PIN();
#endif
}

void uart2Putch(char ch) {
	   //while (!(USART2->SR & USART_SR_TXE));    	//wait for the transmission buffer to be empty
	    while (uart2Busy()) continue;    			//wait for the transmission buffer to be empty
	    USART2->DR = ch;                        	//load the data buffer
	    //while (!(USART2->SR & (1<<6)));    		//wait for the transmission to complete
}

void uart2Puts(char *str) {
	while (*str) uart2Putch(*str++);
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

void uart2Putline(char *ln) {
	//USARTWriteString(ln);
	uart2Puts(ln);
	//USARTWriteString("\r\n");
	uart2Puts((char *)"\r\n");
}

uint8_t uart2Getch(void) {
	   //while (!(USART2->SR & USART_SR_RXNE));  	//wait for the receipt buffer to be empty
	    return USART2->DR;                       	//save the transmission buffer
}

//test if data rx is available
uint16_t uart2Available(void) {
	//return (USART2->SR & USART_SR_TC)?true:false;
	return (USART2->SR & USART_SR_RXNE);
}

//test if uart tx is busy
uint16_t uart2Busy(void) {
	   return !(USART2->SR & USART_SR_TXE);    	//return 1 if TX buffer is empty
}

//print to uart2
void u2Print(char *str, int32_t dat) {
	static char uRAM[uRAM_SIZE];					//transmission buffer, 40-1 char max
	
	strcpy(uRAM, str);								//copy to uarm
	uPrint(uRAM, dat);								//print to uBuffer
	uart2Puts(uRAM);								//send a message on uart1
}	

#endif		//USART2

#if defined(RCC_APB1ENR_USART3EN)
//uart3
//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart3Init(unsigned long baudrate) {
    //configure uart1
    //route clock to uart1
    RCC->APB1ENR |= RCC_APB1ENR_USART3EN;

	//reset uart
	uartInit(USART3, baudrate);

    //configure the RX-PA3/TX-PA2 pins - GPIO clock assumed enabled here previously
    //IO_INFL(GPIOA, 1<<3);			//RX as floating input/AF input
    //IO_AFPP(GPIOA, 1<<2);			//TX as AFPP
#if defined(U3TX2PIN)
	U3TX2PIN();
#endif
#if defined(U3RX2PIN)
	U3RX2PIN();
#endif
}

void uart3Putch(char ch) {
	   //while (!(USART3->SR & USART_SR_TXE));    	//wait for the transmission buffer to be empty
	    while (uart3Busy()) continue;    			//wait for the transmission buffer to be empty
	    USART3->DR = ch;                        	//load the data buffer
	    //while (!(USART3->SR & (1<<6)));    		//wait for the transmission to complete
}

void uart3Puts(char *str) {
	while (*str) uart3Putch(*str++);
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

void uart3Putline(char *ln) {
	//USARTWriteString(ln);
	uart3Puts(ln);
	//USARTWriteString("\r\n");
	uart3Puts((char *)"\r\n");
}

uint8_t uart3Getch(void) {
	   //while (!(USART3->SR & USART_SR_RXNE));  	//wait for the receipt buffer to be empty
	    return USART3->DR;                       	//save the transmission buffer
}

//test if data rx is available
uint16_t uart3Available(void) {
	//return (USART3->SR & USART_SR_TC)?true:false;
	return (USART3->SR & USART_SR_RXNE);
}

//test if uart tx is busy
uint16_t uart3Busy(void) {
	   return !(USART3->SR & USART_SR_TXE);    	//return 1 if TX buffer is empty
}

//print to uart3
void u3Print(char *str, int32_t dat) {
	char uRAM[40];						//transmission buffer, 40-1 char max
	
	strcpy(uRAM, str);					//copy to uarm
	uPrint(uRAM, dat);					//print to uBuffer
	uart3Puts(uRAM);					//send a message on uart1
}	

#endif		//USART3


#if defined (RCC_APB1ENR_UART4EN)
//uart4
//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart4Init(unsigned long baudrate) {
    //configure uart1
    //route clock to uart1
    RCC->APB1ENR |= RCC_APB1ENR_UART4EN;

	//reset uart
	uartInit(UART4, baudrate);

    //configure the RX-PA3/TX-PA2 pins - GPIO clock assumed enabled here previously
    //IO_INFL(GPIOA, 1<<3);			//RX as floating input/AF input
    //IO_AFPP(GPIOA, 1<<2);			//TX as AFPP
#if defined(U4TX2PIN)
	U4TX2PIN();
#endif
#if defined(U4RX2PIN)
	U4RX2PIN();
#endif
}

void uart4Putch(char ch) {
	   //while (!(UART4->SR & USART_SR_TXE));    	//wait for the transmission buffer to be empty
	    while (uart4Busy()) continue;    			//wait for the transmission buffer to be empty
	    UART4->DR = ch;                        	//load the data buffer
	    //while (!(UART4->SR & (1<<6)));    		//wait for the transmission to complete
}

void uart4Puts(char *str) {
	while (*str) uart4Putch(*str++);
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

void uart4Putline(char *ln) {
	//USARTWriteString(ln);
	uart4Puts(ln);
	//USARTWriteString("\r\n");
	uart4Puts((char *)"\r\n");
}

uint8_t uart4Getch(void) {
	   //while (!(UART4->SR & USART_SR_RXNE));  	//wait for the receipt buffer to be empty
	    return UART4->DR;                       	//save the transmission buffer
}

//test if data rx is available
uint16_t uart4Available(void) {
	//return (UART4->SR & USART_SR_TC)?true:false;
	return (UART4->SR & USART_SR_RXNE);
}

//test if uart tx is busy
uint16_t uart4Busy(void) {
	   return !(UART4->SR & USART_SR_TXE);    	//return 1 if TX buffer is empty
}

//print to uart4
void u4Print(char *str, int32_t dat) {
	char uRAM[40];						//transmission buffer, 40-1 char max
	
	strcpy(uRAM, str);					//copy to uarm
	uPrint(uRAM, dat);					//print to uBuffer
	uart4Puts(uRAM);					//send a message on uart1
}	

#endif		//UART4


#if defined (RCC_APB1ENR_UART5EN)
//uart5
//initialize usart: high baudrate (brgh=1), 16-bit baudrate (brg16=1)
//baudrate=Fxtal/(4*(spbrg+1))
//spbrg=(Fxtal/4/baudrate)-1
//tx/rx pins to be assumed in gpio mode
//data bits: 	8
//parity: 		none
//stop bits: 	1
//Xon/Xoff:		none
void uart5Init(unsigned long baudrate) {
    //configure uart1
    //route clock to uart1
    RCC->APB1ENR |= RCC_APB1ENR_UART5EN;

	//reset uart
	uartInit(UART5, baudrate);

    //configure the RX-PA3/TX-PA2 pins - GPIO clock assumed enabled here previously
    //IO_INFL(GPIOA, 1<<3);			//RX as floating input/AF input
    //IO_AFPP(GPIOA, 1<<2);			//TX as AFPP
#if defined(U5TX2PIN)
	U5TX2PIN();
#endif
#if defined(U5RX2PIN)
	U5RX2PIN();
#endif
}

void uart5Putch(char ch) {
	   //while (!(UART5->SR & USART_SR_TXE));    	//wait for the transmission buffer to be empty
	    while (uart5Busy()) continue;    			//wait for the transmission buffer to be empty
	    UART5->DR = ch;                        	//load the data buffer
	    //while (!(UART5->SR & (1<<6)));    		//wait for the transmission to complete
}

void uart5Puts(char *str) {
	while (*str) uart5Putch(*str++);
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

void uart5Putline(char *ln) {
	//USARTWriteString(ln);
	uart5Puts(ln);
	//USARTWriteString("\r\n");
	uart5Puts((char *)"\r\n");
}

uint8_t uart5Getch(void) {
	   //while (!(UART5->SR & USART_SR_RXNE));  	//wait for the receipt buffer to be empty
	    return UART5->DR;                       	//save the transmission buffer
}

//test if data rx is available
uint16_t uart5Available(void) {
	//return (UART5->SR & USART_SR_TC)?true:false;
	return (UART5->SR & USART_SR_RXNE);
}

//test if uart tx is busy
uint16_t uart5Busy(void) {
	   return !(UART5->SR & USART_SR_TXE);    	//return 1 if TX buffer is empty
}

//print to uart5
void u5Print(char *str, int32_t dat) {
	char uRAM[40];						//transmission buffer, 40-1 char max
	
	strcpy(uRAM, str);					//copy to uarm
	uPrint(uRAM, dat);					//print to uBuffer
	uart5Puts(uRAM);					//send a message on uart1
}	

#endif		//USART5
//end Serial

//generic timer reset routine
void tmrInit(TIM_TypeDef *TIMx, uint16_t ps) {
	//source from internal clock -> disable slave mode
	TIMx->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	TIMx->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	TIMx->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	TIMx->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	TIMx->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIMx->CR1 = 0;						//much easier

	//clear the status register bits for capture / compare flags
	TIMx->SR &=~(TIM_SR_UIF | TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF);
	//disable the interrupt by clearing the enable bits
	TIMx->DIER &=~(TIM_DIER_UIE | TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE);

	//set the prescaler
	TIMx->PSC = ps - 1;					//set the prescaler
	TIMx->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIMx->ARR = (uint16_t) -1;						//auto reload register / period = 0; - need to change for downcounters
	TIMx->CNT = 0;						//reset the counter

	//enable the timer.
	TIMx->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//tmr1 - confirmed to exist on STM32F103
//global variables
static void (* _tim1_ovfisrptr)(void)=empty_handler;				//tim1_ptr pointing to empty_handler by default
static void (* _tim1_cc1isrptr)(void)=empty_handler;				//tim1_ptr pointing to empty_handler by default
static void (* _tim1_cc2isrptr)(void)=empty_handler;				//tim1_ptr pointing to empty_handler by default
static void (* _tim1_cc3isrptr)(void)=empty_handler;				//tim1_ptr pointing to empty_handler by default
static void (* _tim1_cc4isrptr)(void)=empty_handler;				//tim1_ptr pointing to empty_handler by default

static uint16_t _tim1_cc1=0;				//output compare registers
static uint16_t _tim1_cc2=0;
static uint16_t _tim1_cc3=0;
static uint16_t _tim1_cc4=0;

//isr for timer1 ovf
void TIM1_UP_IRQHandler(void) {
	//ovf isr
	if ((TIM1->SR & TIM_SR_UIF) && (TIM1->DIER & TIM_DIER_UIE)) {TIM1->SR &=~TIM_SR_UIF; _tim1_ovfisrptr();}
}

//isr for timer1 capture / compare
void TIM1_CC_IRQHandler(void) {
	//oc1..4 portion
	//output compare 1 flag is set, clear the flag, update the output compare register, execute user handler
	if ((TIM1->SR & TIM_SR_CC1IF) && (TIM1->DIER & TIM_DIER_CC1IE)) {TIM1->SR &=~TIM_SR_CC1IF; if (TIM1->CCER & TIM_CCER_CC1E) _tim1_cc1 = TIM1->CCR1; else TIM1->CCR1 += _tim1_cc1;_tim1_cc1isrptr();}
	if ((TIM1->SR & TIM_SR_CC2IF) && (TIM1->DIER & TIM_DIER_CC2IE)) {TIM1->SR &=~TIM_SR_CC2IF; if (TIM1->CCER & TIM_CCER_CC2E) _tim1_cc2 = TIM1->CCR2; else TIM1->CCR2 += _tim1_cc2;_tim1_cc2isrptr();}
	if ((TIM1->SR & TIM_SR_CC3IF) && (TIM1->DIER & TIM_DIER_CC3IE)) {TIM1->SR &=~TIM_SR_CC3IF; if (TIM1->CCER & TIM_CCER_CC3E) _tim1_cc3 = TIM1->CCR3; else TIM1->CCR3 += _tim1_cc3;_tim1_cc3isrptr();}
	if ((TIM1->SR & TIM_SR_CC4IF) && (TIM1->DIER & TIM_DIER_CC4IE)) {TIM1->SR &=~TIM_SR_CC4IF; if (TIM1->CCER & TIM_CCER_CC4E) _tim1_cc4 = TIM1->CCR4; else TIM1->CCR4 += _tim1_cc4;_tim1_cc4isrptr();}
}

//initialize the timer1 (16bit)
void tmr1Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	//reset timer
	tmrInit(TIM1, ps);
}

//activate the isr handler
void tmr1OVFAttachISR(void (*isrptr)(void)) {
#if defined(STM32F10X_LD_VL) || defined(STM32F10X_MD_VL) || defined(STM32F10X_HD_VL)
	NVIC_DisableIRQ(TIM1_UP_TIM16_IRQn);		//disable irq

	_tim1_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);		//enable irq
	//priorities not set -> default values used.
#else
	NVIC_DisableIRQ(TIM1_UP_IRQn);		//disable irq

	_tim1_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM1_UP_IRQn);		//enable irq
	//priorities not set -> default values used.
#endif
}

//set tim1_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr1OC1SetPR(uint16_t pr) {
	//save the period value
	_tim1_cc1 = pr - 0;
	TIM1->CCR1 = TIM1->CNT + _tim1_cc1;

	//clear the flag
	//TIM1->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM1->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr1OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set tim1_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr1OC2SetPR(uint16_t pr) {
	//save the period value
	_tim1_cc2 = pr - 0;
	TIM1->CCR2 = TIM1->CNT + _tim1_cc2;

	//clear the flag
	//TIM1->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM1->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr1OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set tim1_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr1OC3SetPR(uint16_t pr) {
	//save the period value
	_tim1_cc3 = pr - 0;
	TIM1->CCR3 = TIM1->CNT + _tim1_cc3;

	//clear the flag
	//TIM1->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM1->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr1OC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set tim1_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr1OC4SetPR(uint16_t pr) {
	//save the period value
	_tim1_cc4 = pr - 0;
	TIM1->CCR4 = TIM1->CNT + _tim1_cc4;

	//clear the flag
	//TIM1->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM1->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr1OC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic1
void tmr1IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM1->CCMR1 = (TIM1->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM1->CCMR1 = (TIM1->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM1->SR &=~TIM_SR_CC1IF; TIM1->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM1->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM1 rmp to MCO (=3)
	//TIM1->OR = (TIM1->OR &~TIM1_OR_TI1_RMP) | (((3) << 0) & TIM1_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM1->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM1CH1toPIN)
	TIM1CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr1IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr1IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM1->CCMR1 = (TIM1->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM1->CCMR1 = (TIM1->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM1->SR &=~TIM_SR_CC2IF; TIM1->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM1->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM1 rmp to MCO (=3)
	//TIM1->OR = (TIM1->OR &~TIM1_OR_TI1_RMP) | (((3) << 0) & TIM1_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM1->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM1CH2toPIN)
	TIM1CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr1IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic3
void tmr1IC3Init(uint8_t ps) {
	//set up the capture channel 1
	TIM1->CCMR2 = (TIM1->CCMR2 &~TIM_CCMR2_CC3S) | (TIM_CCMR2_CC3S_0);	//0b01->input capture
	TIM1->CCMR2 = (TIM1->CCMR2 &~TIM_CCMR2_IC3PSC) | ((ps<<TIM_CCMR2_IC3PSC_Pos) & TIM_CCMR2_IC3PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM1->SR &=~TIM_SR_CC3IF; TIM1->DIER &=~TIM_DIER_CC3IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM1->CCER |= TIM_CCER_CC3E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM1 rmp to MCO (=3)
	//TIM1->OR = (TIM1->OR &~TIM1_OR_TI1_RMP) | (((3) << 0) & TIM1_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM1->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM1CH3toPIN)
	TIM1CH3toPIN();											//configure the input capture pin
#endif	//ch3
}

//activate the isr handler
void tmr1IC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic4
void tmr1IC4Init(uint8_t ps) {
	//set up the capture channel 1
	TIM1->CCMR2 = (TIM1->CCMR2 &~TIM_CCMR2_CC4S) | (TIM_CCMR2_CC4S_0);	//0b01->input capture
	TIM1->CCMR2 = (TIM1->CCMR2 &~TIM_CCMR2_IC4PSC) | ((ps<<TIM_CCMR2_IC4PSC_Pos) & TIM_CCMR2_IC4PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM1->SR &=~TIM_SR_CC4IF; TIM1->DIER &=~TIM_DIER_CC4IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM1->CCER |= TIM_CCER_CC4E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM1 rmp to MCO (=3)
	//TIM1->OR = (TIM1->OR &~TIM1_OR_TI1_RMP) | (((3) << 0) & TIM1_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM1->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM1CH4toPIN)
	TIM1CH4toPIN();											//configure the input capture pin
#endif	//ch4
}

//activate the isr handler
void tmr1IC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_CC_IRQn);		//disable irq

	_tim1_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM1->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM1->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_CC_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//tmr2

//global variables
static void (* _tim2_ovfisrptr)(void)=empty_handler;				//TIM2_ptr pointing to empty_handler by default
static void (* _tim2_cc1isrptr)(void)=empty_handler;				//TIM2_ptr pointing to empty_handler by default
static void (* _tim2_cc2isrptr)(void)=empty_handler;				//TIM2_ptr pointing to empty_handler by default
static void (* _tim2_cc3isrptr)(void)=empty_handler;				//TIM2_ptr pointing to empty_handler by default
static void (* _tim2_cc4isrptr)(void)=empty_handler;				//TIM2_ptr pointing to empty_handler by default

static uint16_t _tim2_cc1=0;				//output compare registers
static uint16_t _tim2_cc2=0;
static uint16_t _tim2_cc3=0;
static uint16_t _tim2_cc4=0;

//isr for timer1 capture / compare
void TIM2_IRQHandler(void) {
	//oc1 portion
	//output compare 1 flag is set, clea the flag, update the output compare register, execute user handler
	if ((TIM2->SR & TIM_SR_CC1IF) && (TIM2->DIER & TIM_DIER_CC1IE)) {TIM2->SR &=~TIM_SR_CC1IF; if (TIM2->CCER & TIM_CCER_CC1E) _tim2_cc1 = TIM2->CCR1; else TIM2->CCR1 += _tim2_cc1; _tim2_cc1isrptr();}
	if ((TIM2->SR & TIM_SR_CC2IF) && (TIM2->DIER & TIM_DIER_CC2IE)) {TIM2->SR &=~TIM_SR_CC2IF; if (TIM2->CCER & TIM_CCER_CC2E) _tim2_cc2 = TIM2->CCR2; else TIM2->CCR2 += _tim2_cc2; _tim2_cc2isrptr();}
	if ((TIM2->SR & TIM_SR_CC3IF) && (TIM2->DIER & TIM_DIER_CC3IE)) {TIM2->SR &=~TIM_SR_CC3IF; if (TIM2->CCER & TIM_CCER_CC3E) _tim2_cc3 = TIM2->CCR3; else TIM2->CCR3 += _tim2_cc3; _tim2_cc3isrptr();}
	if ((TIM2->SR & TIM_SR_CC4IF) && (TIM2->DIER & TIM_DIER_CC4IE)) {TIM2->SR &=~TIM_SR_CC4IF; if (TIM2->CCER & TIM_CCER_CC4E) _tim2_cc4 = TIM2->CCR4; else TIM2->CCR4 += _tim2_cc4; _tim2_cc4isrptr();}

	//ovf portion
	if ((TIM2->SR & TIM_SR_UIF) && (TIM2->DIER & TIM_DIER_UIE)) {TIM2->SR &=~TIM_SR_UIF; _tim2_ovfisrptr();}
}

//initialize the timer1 (16bit)
void tmr2Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	//reset timer
	tmrInit(TIM2, ps);
}

//activate the isr handler
void tmr2OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);			//disable irq

	_tim2_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM2_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr2OC1SetPR(uint16_t pr) {
	//save the period value
	_tim2_cc1 = pr - 0;
	TIM2->CCR1 = TIM2->CNT + _tim2_cc1;

	//clear the flag
	//TIM2->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM2->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr2OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);			//disable irq

	_tim2_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM2_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr2OC2SetPR(uint16_t pr) {
	//save the period value
	_tim2_cc2 = pr - 0;
	TIM2->CCR2 = TIM2->CNT + _tim2_cc2;

	//clear the flag
	//TIM2->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM2->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr2OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);			//disable irq

	_tim2_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM2_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr2OC3SetPR(uint16_t pr) {
	//save the period value
	_tim2_cc3 = pr - 0;
	TIM2->CCR3 = TIM2->CNT + _tim2_cc3;

	//clear the flag
	//TIM2->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM2->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr2OC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);			//disable irq

	_tim2_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM2_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr2OC4SetPR(uint16_t pr) {
	//save the period value
	_tim2_cc4 = pr - 0;
	TIM2->CCR4 = TIM2->CNT + _tim2_cc4;

	//clear the flag
	//TIM2->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM2->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr2OC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);			//disable irq

	_tim2_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);			//enable irq
	//priorities not set -> default values used.
}


//ic1
void tmr2IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM2->CCMR1 = (TIM2->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM2->CCMR1 = (TIM2->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM2->SR &=~TIM_SR_CC1IF; TIM2->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM2->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM2 rmp to MCO (=3)
	//TIM2->OR = (TIM2->OR &~TIM2_OR_TI1_RMP) | (((3) << 0) & TIM2_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM2->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM2CH1toPIN)
	TIM2CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr2IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);		//disable irq

	_tim2_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr2IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM2->CCMR1 = (TIM2->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM2->CCMR1 = (TIM2->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM2->SR &=~TIM_SR_CC2IF; TIM2->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM2->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM2 rmp to MCO (=3)
	//TIM2->OR = (TIM2->OR &~TIM2_OR_TI1_RMP) | (((3) << 0) & TIM2_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM2->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM2CH2toPIN)
	TIM2CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr2IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);		//disable irq

	_tim2_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic3
void tmr2IC3Init(uint8_t ps) {
	//set up the capture channel 1
	TIM2->CCMR2 = (TIM2->CCMR2 &~TIM_CCMR2_CC3S) | (TIM_CCMR2_CC3S_0);	//0b01->input capture
	TIM2->CCMR2 = (TIM2->CCMR2 &~TIM_CCMR2_IC3PSC) | ((ps<<TIM_CCMR2_IC3PSC_Pos) & TIM_CCMR2_IC3PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM2->SR &=~TIM_SR_CC3IF; TIM2->DIER &=~TIM_DIER_CC3IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM2->CCER |= TIM_CCER_CC3E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM2 rmp to MCO (=3)
	//TIM2->OR = (TIM2->OR &~TIM2_OR_TI1_RMP) | (((3) << 0) & TIM2_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM2->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM2CH3toPIN)
	TIM2CH3toPIN();											//configure the input capture pin
#endif	//ch3
}

//activate the isr handler
void tmr2IC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);		//disable irq

	_tim2_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic4
void tmr2IC4Init(uint8_t ps) {
	//set up the capture channel 1
	TIM2->CCMR2 = (TIM2->CCMR2 &~TIM_CCMR2_CC4S) | (TIM_CCMR2_CC4S_0);	//0b01->input capture
	TIM2->CCMR2 = (TIM2->CCMR2 &~TIM_CCMR2_IC4PSC) | ((ps<<TIM_CCMR2_IC4PSC_Pos) & TIM_CCMR2_IC4PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM2->SR &=~TIM_SR_CC4IF; TIM2->DIER &=~TIM_DIER_CC4IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM2->CCER |= TIM_CCER_CC4E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM2 rmp to MCO (=3)
	//TIM2->OR = (TIM2->OR &~TIM2_OR_TI1_RMP) | (((3) << 0) & TIM2_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM2->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM2CH4toPIN)
	TIM2CH4toPIN();											//configure the input capture pin
#endif	//ch4
}

//activate the isr handler
void tmr2IC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM2_IRQn);		//disable irq

	_tim2_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM2->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM2->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM2_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//end tmr2

//tmr3
//global variables
static void (* _tim3_ovfisrptr)(void)=empty_handler;				//TIM3_ptr pointing to empty_handler by default
static void (* _tim3_cc1isrptr)(void)=empty_handler;				//TIM3_ptr pointing to empty_handler by default
static void (* _tim3_cc2isrptr)(void)=empty_handler;				//TIM3_ptr pointing to empty_handler by default
static void (* _tim3_cc3isrptr)(void)=empty_handler;				//TIM3_ptr pointing to empty_handler by default
static void (* _tim3_cc4isrptr)(void)=empty_handler;				//TIM3_ptr pointing to empty_handler by default

static uint16_t _tim3_cc1=0;				//output compare registers
static uint16_t _tim3_cc2=0;
static uint16_t _tim3_cc3=0;
static uint16_t _tim3_cc4=0;

//isr for timer1 capture / compare
void TIM3_IRQHandler(void) {
	//oc1 portion
	if ((TIM3->SR & TIM_SR_CC1IF) && (TIM3->DIER & TIM_DIER_CC1IE)) {TIM3->SR &=~TIM_SR_CC1IF; if (TIM2->CCER & TIM_CCER_CC1E) _tim2_cc1 = TIM2->CCR1; else TIM3->CCR1 += _tim3_cc1; _tim3_cc1isrptr();}
	if ((TIM3->SR & TIM_SR_CC2IF) && (TIM3->DIER & TIM_DIER_CC2IE)) {TIM3->SR &=~TIM_SR_CC2IF; if (TIM2->CCER & TIM_CCER_CC2E) _tim2_cc2 = TIM2->CCR2; else TIM3->CCR2 += _tim3_cc2; _tim3_cc2isrptr();}
	if ((TIM3->SR & TIM_SR_CC3IF) && (TIM3->DIER & TIM_DIER_CC3IE)) {TIM3->SR &=~TIM_SR_CC3IF; if (TIM2->CCER & TIM_CCER_CC3E) _tim2_cc3 = TIM2->CCR3; else TIM3->CCR3 += _tim3_cc3; _tim3_cc3isrptr();}
	if ((TIM3->SR & TIM_SR_CC4IF) && (TIM3->DIER & TIM_DIER_CC4IE)) {TIM3->SR &=~TIM_SR_CC4IF; if (TIM2->CCER & TIM_CCER_CC4E) _tim2_cc4 = TIM2->CCR4; else TIM3->CCR4 += _tim3_cc4; _tim3_cc4isrptr();}
	
	//isr
	if ((TIM3->SR & TIM_SR_UIF) && (TIM3->DIER & TIM_DIER_UIE)) {TIM3->SR &=~TIM_SR_UIF; _tim3_ovfisrptr();}
}

//initialize the timer1 (16bit)
void tmr3Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	//reset timer
	tmrInit(TIM3, ps);
}

//activate the isr handler
void tmr3OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);			//disable irq

	_tim3_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM3_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr3OC1SetPR(uint16_t pr) {
	//save the period value
	_tim3_cc1 = pr - 0;
	TIM3->CCR1 = TIM3->CNT + _tim3_cc1;

	//clear the flag
	//TIM3->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM3->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr3OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);			//disable irq

	_tim3_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM3_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr3OC2SetPR(uint16_t pr) {
	//save the period value
	_tim3_cc2 = pr - 0;
	TIM3->CCR2 = TIM3->CNT + _tim3_cc2;

	//clear the flag
	//TIM3->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM3->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr3OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);			//disable irq

	_tim3_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM3_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr3OC3SetPR(uint16_t pr) {
	//save the period value
	_tim3_cc3 = pr - 0;
	TIM3->CCR3 = TIM3->CNT + _tim3_cc3;

	//clear the flag
	//TIM3->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM3->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr3OC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);			//disable irq

	_tim3_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM3_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr3OC4SetPR(uint16_t pr) {
	//save the period value
	_tim3_cc4 = pr - 0;
	TIM3->CCR4 = TIM3->CNT + _tim3_cc4;

	//clear the flag
	//TIM3->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM3->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr3OC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);			//disable irq

	_tim3_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);			//enable irq
	//priorities not set -> default values used.
}


//ic1
void tmr3IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM3->CCMR1 = (TIM3->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM3->CCMR1 = (TIM3->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM3->SR &=~TIM_SR_CC1IF; TIM3->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM3->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM3 rmp to MCO (=3)
	//TIM3->OR = (TIM3->OR &~TIM3_OR_TI1_RMP) | (((3) << 0) & TIM3_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM3->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM3CH1toPIN)
	TIM3CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr3IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);		//disable irq

	_tim3_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr3IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM3->CCMR1 = (TIM3->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM3->CCMR1 = (TIM3->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM3->SR &=~TIM_SR_CC2IF; TIM3->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM3->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM3 rmp to MCO (=3)
	//TIM3->OR = (TIM3->OR &~TIM3_OR_TI1_RMP) | (((3) << 0) & TIM3_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM3->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM3CH2toPIN)
	TIM3CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr3IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);		//disable irq

	_tim3_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic3
void tmr3IC3Init(uint8_t ps) {
	//set up the capture channel 1
	TIM3->CCMR2 = (TIM3->CCMR2 &~TIM_CCMR2_CC3S) | (TIM_CCMR2_CC3S_0);	//0b01->input capture
	TIM3->CCMR2 = (TIM3->CCMR2 &~TIM_CCMR2_IC3PSC) | ((ps<<TIM_CCMR2_IC3PSC_Pos) & TIM_CCMR2_IC3PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM3->SR &=~TIM_SR_CC3IF; TIM3->DIER &=~TIM_DIER_CC3IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM3->CCER |= TIM_CCER_CC3E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM3 rmp to MCO (=3)
	//TIM3->OR = (TIM3->OR &~TIM3_OR_TI1_RMP) | (((3) << 0) & TIM3_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM3->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM3CH3toPIN)
	TIM3CH3toPIN();											//configure the input capture pin
#endif	//ch3
}

//activate the isr handler
void tmr3IC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);		//disable irq

	_tim3_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic4
void tmr3IC4Init(uint8_t ps) {
	//set up the capture channel 1
	TIM3->CCMR2 = (TIM3->CCMR2 &~TIM_CCMR2_CC4S) | (TIM_CCMR2_CC4S_0);	//0b01->input capture
	TIM3->CCMR2 = (TIM3->CCMR2 &~TIM_CCMR2_IC4PSC) | ((ps<<TIM_CCMR2_IC4PSC_Pos) & TIM_CCMR2_IC4PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM3->SR &=~TIM_SR_CC4IF; TIM3->DIER &=~TIM_DIER_CC4IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM3->CCER |= TIM_CCER_CC4E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM3 rmp to MCO (=3)
	//TIM3->OR = (TIM3->OR &~TIM3_OR_TI1_RMP) | (((3) << 0) & TIM3_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM3->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM3CH4toPIN)
	TIM3CH4toPIN();											//configure the input capture pin
#endif	//ch4
}

//activate the isr handler
void tmr3IC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM3_IRQn);		//disable irq

	_tim3_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM3->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM3->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM3_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//end tmr3

#if defined(RCC_APB1ENR_TIM4EN)
//tmr4
//global variables
static void (* _tim4_ovfisrptr)(void)=empty_handler;				//TIM4_ptr pointing to empty_handler by default
static void (* _tim4_cc1isrptr)(void)=empty_handler;				//TIM4_ptr pointing to empty_handler by default
static void (* _tim4_cc2isrptr)(void)=empty_handler;				//TIM4_ptr pointing to empty_handler by default
static void (* _tim4_cc3isrptr)(void)=empty_handler;				//TIM4_ptr pointing to empty_handler by default
static void (* _tim4_cc4isrptr)(void)=empty_handler;				//TIM4_ptr pointing to empty_handler by default

static uint16_t _tim4_cc1=0;				//output compare registers
static uint16_t _tim4_cc2=0;
static uint16_t _tim4_cc3=0;
static uint16_t _tim4_cc4=0;

//isr for timer1 capture / compare
void TIM4_IRQHandler(void) {
	//oc1..4 portion
	//if ((TIM4->DIER & TIM_DIER_CC1IE) && (TIM4->SR & TIM_SR_CC1IF)) {		//output compare 1 flag is set
	if ((TIM4->SR & TIM_SR_CC1IF) && (TIM4->DIER & TIM_DIER_CC1IE)) {TIM4->SR &=~TIM_SR_CC1IF; if (TIM4->CCER & TIM_CCER_CC1E) _tim4_cc1 = TIM4->CCR1; else TIM4->CCR1 += _tim4_cc1; _tim4_cc1isrptr();}
	if ((TIM4->SR & TIM_SR_CC2IF) && (TIM4->DIER & TIM_DIER_CC2IE)) {TIM4->SR &=~TIM_SR_CC2IF; if (TIM4->CCER & TIM_CCER_CC2E) _tim4_cc2 = TIM4->CCR2; else TIM4->CCR2 += _tim4_cc2; _tim4_cc2isrptr();}
	if ((TIM4->SR & TIM_SR_CC3IF) && (TIM4->DIER & TIM_DIER_CC3IE)) {TIM4->SR &=~TIM_SR_CC3IF; if (TIM4->CCER & TIM_CCER_CC3E) _tim4_cc3 = TIM4->CCR3; else TIM4->CCR3 += _tim4_cc3; _tim4_cc3isrptr();}
	if ((TIM4->SR & TIM_SR_CC4IF) && (TIM4->DIER & TIM_DIER_CC4IE)) {TIM4->SR &=~TIM_SR_CC4IF; if (TIM4->CCER & TIM_CCER_CC4E) _tim4_cc4 = TIM4->CCR4; else TIM4->CCR4 += _tim4_cc4; _tim4_cc4isrptr();}

	//ovf isr
	if ((TIM4->SR & TIM_SR_UIF) && (TIM4->DIER & TIM_DIER_UIE)) {TIM4->SR &=~TIM_SR_UIF; _tim4_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr4Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	//reset timer
	tmrInit(TIM4, ps);
}

//activate the isr handler
void tmr4OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);			//disable irq

	_tim4_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM4_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr4OC1SetPR(uint16_t pr) {
	//save the period value
	_tim4_cc1 = pr - 0;
	TIM4->CCR1 = TIM4->CNT + _tim4_cc1;

	//clear the flag
	//TIM4->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM4->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr4OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);			//disable irq

	_tim4_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM4_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr4OC2SetPR(uint16_t pr) {
	//save the period value
	_tim4_cc2 = pr - 0;
	TIM4->CCR2 = TIM4->CNT + _tim4_cc2;

	//clear the flag
	//TIM4->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM4->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr4OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);			//disable irq

	_tim4_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM4_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr4OC3SetPR(uint16_t pr) {
	//save the period value
	_tim4_cc3 = pr - 0;
	TIM4->CCR3 = TIM4->CNT + _tim4_cc3;

	//clear the flag
	//TIM4->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM4->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr4OC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);			//disable irq

	_tim4_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM4_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr4OC4SetPR(uint16_t pr) {
	//save the period value
	_tim4_cc4 = pr - 0;
	TIM4->CCR4 = TIM4->CNT + _tim4_cc4;

	//clear the flag
	//TIM4->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM4->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr4OC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);			//disable irq

	_tim4_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);			//enable irq
	//priorities not set -> default values used.
}


//ic1
void tmr4IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM4->CCMR1 = (TIM4->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM4->CCMR1 = (TIM4->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM4->SR &=~TIM_SR_CC1IF; TIM4->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM4->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM4 rmp to MCO (=3)
	//TIM4->OR = (TIM4->OR &~TIM4_OR_TI1_RMP) | (((3) << 0) & TIM4_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM4->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM4CH1toPIN)
	TIM4CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr4IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);		//disable irq

	_tim4_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr4IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM4->CCMR1 = (TIM4->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM4->CCMR1 = (TIM4->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM4->SR &=~TIM_SR_CC2IF; TIM4->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM4->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM4 rmp to MCO (=3)
	//TIM4->OR = (TIM4->OR &~TIM4_OR_TI1_RMP) | (((3) << 0) & TIM4_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM4->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM4CH2toPIN)
	TIM4CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr4IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);		//disable irq

	_tim4_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic3
void tmr4IC3Init(uint8_t ps) {
	//set up the capture channel 1
	TIM4->CCMR2 = (TIM4->CCMR2 &~TIM_CCMR2_CC3S) | (TIM_CCMR2_CC3S_0);	//0b01->input capture
	TIM4->CCMR2 = (TIM4->CCMR2 &~TIM_CCMR2_IC3PSC) | ((ps<<TIM_CCMR2_IC3PSC_Pos) & TIM_CCMR2_IC3PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM4->SR &=~TIM_SR_CC3IF; TIM4->DIER &=~TIM_DIER_CC3IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM4->CCER |= TIM_CCER_CC3E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM4 rmp to MCO (=3)
	//TIM4->OR = (TIM4->OR &~TIM4_OR_TI1_RMP) | (((3) << 0) & TIM4_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM4->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM4CH3toPIN)
	TIM4CH3toPIN();											//configure the input capture pin
#endif	//ch3
}

//activate the isr handler
void tmr4IC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);		//disable irq

	_tim4_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic4
void tmr4IC4Init(uint8_t ps) {
	//set up the capture channel 1
	TIM4->CCMR2 = (TIM4->CCMR2 &~TIM_CCMR2_CC4S) | (TIM_CCMR2_CC4S_0);	//0b01->input capture
	TIM4->CCMR2 = (TIM4->CCMR2 &~TIM_CCMR2_IC4PSC) | ((ps<<TIM_CCMR2_IC4PSC_Pos) & TIM_CCMR2_IC4PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM4->SR &=~TIM_SR_CC4IF; TIM4->DIER &=~TIM_DIER_CC4IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM4->CCER |= TIM_CCER_CC4E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM4 rmp to MCO (=3)
	//TIM4->OR = (TIM4->OR &~TIM4_OR_TI1_RMP) | (((3) << 0) & TIM4_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM4->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM4CH4toPIN)
	TIM4CH4toPIN();											//configure the input capture pin
#endif	//ch4
}

//activate the isr handler
void tmr4IC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM4_IRQn);		//disable irq

	_tim4_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM4->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM4->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM4_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//end tmr4
#endif	//TIM4

#if defined(RCC_APB1ENR_TIM5EN)
//tmr5
//global variables
static void (* _tim5_ovfisrptr)(void)=empty_handler;				//TIM5_ptr pointing to empty_handler by default
static void (* _tim5_cc1isrptr)(void)=empty_handler;				//TIM5_ptr pointing to empty_handler by default
static void (* _tim5_cc2isrptr)(void)=empty_handler;				//TIM5_ptr pointing to empty_handler by default
static void (* _tim5_cc3isrptr)(void)=empty_handler;				//TIM5_ptr pointing to empty_handler by default
static void (* _tim5_cc4isrptr)(void)=empty_handler;				//TIM5_ptr pointing to empty_handler by default

static uint16_t _tim5_cc1=0;				//output compare registers
static uint16_t _tim5_cc2=0;
static uint16_t _tim5_cc3=0;
static uint16_t _tim5_cc4=0;

//isr for timer1 capture / compare
void TIM5_IRQHandler(void) {
	//oc1..4 portion
	//if ((TIM5->DIER & TIM_DIER_CC1IE) && (TIM5->SR & TIM_SR_CC1IF)) {		//output compare 1 flag is set
	if ((TIM5->SR & TIM_SR_CC1IF) && (TIM5->DIER & TIM_DIER_CC1IE)) {TIM5->SR &=~TIM_SR_CC1IF; if (TIM5->CCER & TIM_CCER_CC1E) _tim5_cc1 = TIM5->CCR1; else TIM5->CCR1 += _tim5_cc1; _tim5_cc1isrptr();}
	if ((TIM5->SR & TIM_SR_CC2IF) && (TIM5->DIER & TIM_DIER_CC2IE)) {TIM5->SR &=~TIM_SR_CC2IF; if (TIM5->CCER & TIM_CCER_CC2E) _tim5_cc2 = TIM5->CCR2; else TIM5->CCR2 += _tim5_cc2; _tim5_cc2isrptr();}
	if ((TIM5->SR & TIM_SR_CC3IF) && (TIM5->DIER & TIM_DIER_CC3IE)) {TIM5->SR &=~TIM_SR_CC3IF; if (TIM5->CCER & TIM_CCER_CC3E) _tim5_cc3 = TIM5->CCR3; else TIM5->CCR3 += _tim5_cc3; _tim5_cc3isrptr();}
	if ((TIM5->SR & TIM_SR_CC4IF) && (TIM5->DIER & TIM_DIER_CC4IE)) {TIM5->SR &=~TIM_SR_CC4IF; if (TIM5->CCER & TIM_CCER_CC4E) _tim5_cc4 = TIM5->CCR4; else TIM5->CCR4 += _tim5_cc4; _tim5_cc4isrptr();}

	//ovf isr
	if ((TIM5->SR & TIM_SR_UIF) && (TIM5->DIER & TIM_DIER_UIE)) {TIM5->SR &=~TIM_SR_UIF; _tim5_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr5Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

	//reset timer
	tmrInit(TIM5, ps);
}

//activate the isr handler
void tmr5OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);			//disable irq

	_tim5_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM5_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr5OC1SetPR(uint16_t pr) {
	//save the period value
	_tim5_cc1 = pr - 0;
	TIM5->CCR1 = TIM5->CNT + _tim5_cc1;

	//clear the flag
	//TIM5->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM5->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr5OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);			//disable irq

	_tim5_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM5_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr5OC2SetPR(uint16_t pr) {
	//save the period value
	_tim5_cc2 = pr - 0;
	TIM5->CCR2 = TIM5->CNT + _tim5_cc2;

	//clear the flag
	//TIM5->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM5->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr5OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);			//disable irq

	_tim5_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM5_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr5OC3SetPR(uint16_t pr) {
	//save the period value
	_tim5_cc3 = pr - 0;
	TIM5->CCR3 = TIM5->CNT + _tim5_cc3;

	//clear the flag
	//TIM5->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM5->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr5OC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);			//disable irq

	_tim5_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM5_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr5OC4SetPR(uint16_t pr) {
	//save the period value
	_tim5_cc4 = pr - 0;
	TIM5->CCR4 = TIM5->CNT + _tim5_cc4;

	//clear the flag
	//TIM5->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM5->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr5OC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);			//disable irq

	_tim5_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);			//enable irq
	//priorities not set -> default values used.
}


//ic1
void tmr5IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM5->CCMR1 = (TIM5->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM5->CCMR1 = (TIM5->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM5->SR &=~TIM_SR_CC1IF; TIM5->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM5->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM5 rmp to MCO (=3)
	//TIM5->OR = (TIM5->OR &~TIM5_OR_TI1_RMP) | (((3) << 0) & TIM5_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM5->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM5CH1toPIN)
	TIM5CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr5IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);		//disable irq

	_tim5_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr5IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM5->CCMR1 = (TIM5->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM5->CCMR1 = (TIM5->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM5->SR &=~TIM_SR_CC2IF; TIM5->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM5->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM5 rmp to MCO (=3)
	//TIM5->OR = (TIM5->OR &~TIM5_OR_TI1_RMP) | (((3) << 0) & TIM5_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM5->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM5CH2toPIN)
	TIM5CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr5IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);		//disable irq

	_tim5_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic3
void tmr5IC3Init(uint8_t ps) {
	//set up the capture channel 1
	TIM5->CCMR2 = (TIM5->CCMR2 &~TIM_CCMR2_CC3S) | (TIM_CCMR2_CC3S_0);	//0b01->input capture
	TIM5->CCMR2 = (TIM5->CCMR2 &~TIM_CCMR2_IC3PSC) | ((ps<<TIM_CCMR2_IC3PSC_Pos) & TIM_CCMR2_IC3PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM5->SR &=~TIM_SR_CC3IF; TIM5->DIER &=~TIM_DIER_CC3IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM5->CCER |= TIM_CCER_CC3E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM5 rmp to MCO (=3)
	//TIM5->OR = (TIM5->OR &~TIM5_OR_TI1_RMP) | (((3) << 0) & TIM5_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM5->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM5CH3toPIN)
	TIM5CH3toPIN();											//configure the input capture pin
#endif	//ch3
}

//activate the isr handler
void tmr5IC3AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);		//disable irq

	_tim5_cc3isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC3IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC3IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic4
void tmr5IC4Init(uint8_t ps) {
	//set up the capture channel 1
	TIM5->CCMR2 = (TIM5->CCMR2 &~TIM_CCMR2_CC4S) | (TIM_CCMR2_CC4S_0);	//0b01->input capture
	TIM5->CCMR2 = (TIM5->CCMR2 &~TIM_CCMR2_IC4PSC) | ((ps<<TIM_CCMR2_IC4PSC_Pos) & TIM_CCMR2_IC4PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM5->SR &=~TIM_SR_CC4IF; TIM5->DIER &=~TIM_DIER_CC4IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM5->CCER |= TIM_CCER_CC4E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM5 rmp to MCO (=3)
	//TIM5->OR = (TIM5->OR &~TIM5_OR_TI1_RMP) | (((3) << 0) & TIM5_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM5->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM5CH4toPIN)
	TIM5CH4toPIN();											//configure the input capture pin
#endif	//ch4
}

//activate the isr handler
void tmr5IC4AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM5_IRQn);		//disable irq

	_tim5_cc4isrptr = isrptr;			//install user handler

	//clear the flag
	TIM5->SR &=~TIM_SR_CC4IF;			//clear the interrupt flag
	TIM5->DIER |= TIM_DIER_CC4IE;		//enable the isr

	NVIC_EnableIRQ(TIM5_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//end tmr5
#endif	//TIM5

#if defined(RCC_APB1ENR_TIM6EN)
//tmr6
//global variables
static void (* _tim6_ovfisrptr)(void)=empty_handler;				//TIM6_ptr pointing to empty_handler by default
//static void (* _tim6_oc1isrptr)(void)=empty_handler;				//TIM6_ptr pointing to empty_handler by default
//static void (* _tim6_oc2isrptr)(void)=empty_handler;				//TIM6_ptr pointing to empty_handler by default
//static void (* _tim6_oc3isrptr)(void)=empty_handler;				//TIM6_ptr pointing to empty_handler by default
//static void (* _tim6_oc4isrptr)(void)=empty_handler;				//TIM6_ptr pointing to empty_handler by default

//static uint16_t _tim6_oc1=0;				//output compare registers
//static uint16_t _tim6_oc2=0;
//static uint16_t _tim6_oc3=0;
//static uint16_t _tim6_oc4=0;

//isr for timer1 capture / compare
void TIM6_IRQHandler(void) {
	//oc1 portion
	//if (TIM6->SR & TIM_SR_CC1IF) {TIM6->SR &=~TIM_SR_CC1IF; if (TIM6->CCER & TIM_CCER_CC1E) _tim6_cc1 = TIM6->CCR1; else TIM6->CCR1 += _tim6_cc1; _tim6_cc1isrptr();}
	//if (TIM6->SR & TIM_SR_CC2IF) {TIM6->SR &=~TIM_SR_CC2IF; if (TIM6->CCER & TIM_CCER_CC2E) _tim6_cc2 = TIM6->CCR2; else TIM6->CCR2 += _tim6_cc2; _tim6_cc1isrptr();}
	//if (TIM6->SR & TIM_SR_CC3IF) {TIM6->SR &=~TIM_SR_CC3IF; if (TIM6->CCER & TIM_CCER_CC3E) _tim6_cc3 = TIM6->CCR3; else TIM6->CCR3 += _tim6_cc3; _tim6_cc1isrptr();}
	//if (TIM6->SR & TIM_SR_CC4IF) {TIM6->SR &=~TIM_SR_CC4IF; if (TIM6->CCER & TIM_CCER_CC4E) _tim6_cc4 = TIM6->CCR4; else TIM6->CCR4 += _tim6_cc4; _tim6_cc1isrptr();}
	
	//ovf isr
	if ((TIM6->SR & TIM_SR_UIF) && (TIM6->DIER & TIM_DIER_UIE)) {TIM6->SR &=~TIM_SR_UIF; _tim6_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr6Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

	//reset timer
	tmrInit(TIM6, ps);
}

//activate the isr handler
void tmr6OVFAttachISR(void (*isrptr)(void)) {
#if defined(STM32F10X_LD_VL) || defined(STM32F10X_MD_VL) || defined(STM32F10X_HD_VL)
	NVIC_DisableIRQ(TIM6_DAC_IRQn);		//disable irq

	_tim6_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM6->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM6->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM6_DAC_IRQn);		//enable irq
	//priorities not set -> default values used.
#else
	NVIC_DisableIRQ(TIM6_IRQn);		//disable irq

	_tim6_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM6->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM6->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM6_IRQn);		//enable irq
	//priorities not set -> default values used.
#endif
}

//end tmr6
#endif	//TIM6

#if defined(RCC_APB1ENR_TIM7EN)
//tmr7
//global variables
static void (* _tim7_ovfisrptr)(void)=empty_handler;				//TIM7_ptr pointing to empty_handler by default
//static void (* _tim7_oc1isrptr)(void)=empty_handler;				//TIM7_ptr pointing to empty_handler by default
//static void (* _tim7_oc2isrptr)(void)=empty_handler;				//TIM7_ptr pointing to empty_handler by default
//static void (* _tim7_oc3isrptr)(void)=empty_handler;				//TIM7_ptr pointing to empty_handler by default
//static void (* _tim7_oc4isrptr)(void)=empty_handler;				//TIM7_ptr pointing to empty_handler by default

//static uint16_t _tim7_oc1=0;				//output compare registers
//static uint16_t _tim7_oc2=0;
//static uint16_t _tim7_oc3=0;
//static uint16_t _tim7_oc4=0;

//isr for timer1 capture / compare
void TIM7_IRQHandler(void) {
	//oc1 portion
	//if (TIM7->SR & TIM_SR_CC1IF) {TIM7->SR &=~TIM_SR_CC1IF; if (TIM7->CCER & TIM_CCER_CC1E) _tim7_cc1 = TIM7->CCR1; else TIM7->CCR1 += _tim7_cc1; _tim7_cc1isrptr();}
	//if (TIM7->SR & TIM_SR_CC2IF) {TIM7->SR &=~TIM_SR_CC2IF; if (TIM7->CCER & TIM_CCER_CC2E) _tim7_cc2 = TIM7->CCR2; else TIM7->CCR2 += _tim7_cc2; _tim7_cc1isrptr();}
	//if (TIM7->SR & TIM_SR_CC3IF) {TIM7->SR &=~TIM_SR_CC3IF; if (TIM7->CCER & TIM_CCER_CC3E) _tim7_cc3 = TIM7->CCR3; else TIM7->CCR3 += _tim7_cc3; _tim7_cc1isrptr();}
	//if (TIM7->SR & TIM_SR_CC4IF) {TIM7->SR &=~TIM_SR_CC4IF; if (TIM7->CCER & TIM_CCER_CC4E) _tim7_cc4 = TIM7->CCR4; else TIM7->CCR4 += _tim7_cc4; _tim7_cc1isrptr();}
	
	//ovf isr
	if ((TIM7->SR & TIM_SR_UIF) && (TIM7->DIER & TIM_DIER_UIE)) {TIM7->SR &=~TIM_SR_UIF; _tim7_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr7Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;

	//reset timer
	tmrInit(TIM7, ps);
}

//activate the ovf isr handler
void tmr7OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM7_IRQn);		//disable irq

	_tim7_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM7->SR &=~TIM_SR_UIF;				//clear the interrupt flag
	TIM7->DIER |= TIM_DIER_UIE;			//enable the isr

	NVIC_EnableIRQ(TIM7_IRQn);		//enable irq
	//priorities not set -> default values used.
}
//end tmr7
#endif	//TIM7


#if defined(RCC_APB1ENR_TIM8EN)
//tmr8
//global variables
static void (* _tim8_ovfisrptr)(void)=empty_handler;				//TIM8_ptr pointing to empty_handler by default
//static void (* _tim8_oc1isrptr)(void)=empty_handler;				//TIM8_ptr pointing to empty_handler by default
//static void (* _tim8_oc2isrptr)(void)=empty_handler;				//TIM8_ptr pointing to empty_handler by default
//static void (* _tim8_oc3isrptr)(void)=empty_handler;				//TIM8_ptr pointing to empty_handler by default
//static void (* _tim8_oc4isrptr)(void)=empty_handler;				//TIM8_ptr pointing to empty_handler by default

//static uint16_t _tim8_oc1=0;				//output compare registers
//static uint16_t _tim8_oc2=0;
//static uint16_t _tim8_oc3=0;
//static uint16_t _tim8_oc4=0;

//isr for timer1 capture / compare
void TIM8_IRQHandler(void) {
	//oc1 portion
	//if (TIM8->SR & TIM_SR_CC1IF) {TIM8->SR &=~TIM_SR_CC1IF; if (TIM8->CCER & TIM_CCER_CC1E) _tim8_cc1 = TIM8->CCR1; else TIM8->CCR1 += _tim8_cc1; _tim8_cc1isrptr();}
	//if (TIM8->SR & TIM_SR_CC2IF) {TIM8->SR &=~TIM_SR_CC2IF; if (TIM8->CCER & TIM_CCER_CC2E) _tim8_cc2 = TIM8->CCR2; else TIM8->CCR2 += _tim8_cc2; _tim8_cc1isrptr();}
	//if (TIM8->SR & TIM_SR_CC3IF) {TIM8->SR &=~TIM_SR_CC3IF; if (TIM8->CCER & TIM_CCER_CC3E) _tim8_cc3 = TIM8->CCR3; else TIM8->CCR3 += _tim8_cc3; _tim8_cc1isrptr();}
	//if (TIM8->SR & TIM_SR_CC4IF) {TIM8->SR &=~TIM_SR_CC4IF; if (TIM8->CCER & TIM_CCER_CC4E) _tim8_cc4 = TIM8->CCR4; else TIM8->CCR4 += _tim8_cc4; _tim8_cc1isrptr();}
	
	//ovf isr
	if ((TIM8->SR & TIM_SR_UIF) && (TIM8->DIER & TIM_DIER_UIE)) {TIM8->SR &=~TIM_SR_UIF; _tim8_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr8Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM8EN;

	//reset timer
	tmrInit(TIM8, ps);
}

//activate the ovf isr handler
void tmr8OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM8_IRQn);		//disable irq

	_tim8_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM8->SR &=~TIM_SR_UIF;				//clear the interrupt flag
	TIM8->DIER |= TIM_DIER_UIE;			//enable the isr

	NVIC_EnableIRQ(TIM8_IRQn);		//enable irq
	//priorities not set -> default values used.
}
//end tmr8
#endif	//TIM8

#if defined(RCC_APB2ENR_TIM9EN)
//tmr9
//global variables
static void (* _tim9_ovfisrptr)(void)=empty_handler;				//TIM9_ptr pointing to empty_handler by default
//static void (* _tim9_oc1isrptr)(void)=empty_handler;				//TIM9_ptr pointing to empty_handler by default
//static void (* _tim9_oc2isrptr)(void)=empty_handler;				//TIM9_ptr pointing to empty_handler by default
//static void (* _tim9_oc3isrptr)(void)=empty_handler;				//TIM9_ptr pointing to empty_handler by default
//static void (* _tim9_oc4isrptr)(void)=empty_handler;				//TIM9_ptr pointing to empty_handler by default

//static uint16_t _tim9_oc1=0;				//output compare registers
//static uint16_t _tim9_oc2=0;
//static uint16_t _tim9_oc3=0;
//static uint16_t _tim9_oc4=0;

//isr for timer1 capture / compare
void TIM9_IRQHandler(void) {
	//oc1 portion
	//if (TIM9->SR & TIM_SR_CC1IF) {TIM9->SR &=~TIM_SR_CC1IF; if (TIM9->CCER & TIM_CCER_CC1E) _tim9_cc1 = TIM9->CCR1; else TIM9->CCR1 += _tim9_cc1; _tim9_cc1isrptr();}
	//if (TIM9->SR & TIM_SR_CC2IF) {TIM9->SR &=~TIM_SR_CC2IF; if (TIM9->CCER & TIM_CCER_CC2E) _tim9_cc2 = TIM9->CCR2; else TIM9->CCR2 += _tim9_cc2; _tim9_cc1isrptr();}
	//if (TIM9->SR & TIM_SR_CC3IF) {TIM9->SR &=~TIM_SR_CC3IF; if (TIM9->CCER & TIM_CCER_CC3E) _tim9_cc3 = TIM9->CCR3; else TIM9->CCR3 += _tim9_cc3; _tim9_cc1isrptr();}
	//if (TIM9->SR & TIM_SR_CC4IF) {TIM9->SR &=~TIM_SR_CC4IF; if (TIM9->CCER & TIM_CCER_CC4E) _tim9_cc4 = TIM9->CCR4; else TIM9->CCR4 += _tim9_cc4; _tim9_cc1isrptr();}
	
	//ovf isr
	if ((TIM9->SR & TIM_SR_UIF) && (TIM9->DIER & TIM_DIER_UIE)) {TIM9->SR &=~TIM_SR_UIF; _tim9_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr9Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM9EN;

	//reset timer
	tmrInit(TIM9, ps);
}

//activate the ovf isr handler
void tmr9OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM9_IRQn);		//disable irq

	_tim9_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM9->SR &=~TIM_SR_UIF;				//clear the interrupt flag
	TIM9->DIER |= TIM_DIER_UIE;			//enable the isr

	NVIC_EnableIRQ(TIM9_IRQn);		//enable irq
	//priorities not set -> default values used.
}
//end tmr9
#endif	//TIM9

#if defined(RCC_APB2ENR_TIM10EN)
//tmr10
//global variables
static void (* _tim10_ovfisrptr)(void)=empty_handler;				//TIM10_ptr pointing to empty_handler by default
//static void (* _tim10_oc1isrptr)(void)=empty_handler;				//TIM10_ptr pointing to empty_handler by default
//static void (* _tim10_oc2isrptr)(void)=empty_handler;				//TIM10_ptr pointing to empty_handler by default
//static void (* _tim10_oc3isrptr)(void)=empty_handler;				//TIM10_ptr pointing to empty_handler by default
//static void (* _tim10_oc4isrptr)(void)=empty_handler;				//TIM10_ptr pointing to empty_handler by default

//static uint16_t _tim10_oc1=0;				//output compare registers
//static uint16_t _tim10_oc2=0;
//static uint16_t _tim10_oc3=0;
//static uint16_t _tim10_oc4=0;

//isr for timer1 capture / compare
void TIM10_IRQHandler(void) {
	//oc1 portion
	//if (TIM10->SR & TIM_SR_CC1IF) {TIM10->SR &=~TIM_SR_CC1IF; if (TIM10->CCER & TIM_CCER_CC1E) _tim10_cc1 = TIM10->CCR1; else TIM10->CCR1 += _tim10_cc1; _tim10_cc1isrptr();}
	//if (TIM10->SR & TIM_SR_CC2IF) {TIM10->SR &=~TIM_SR_CC2IF; if (TIM10->CCER & TIM_CCER_CC2E) _tim10_cc2 = TIM10->CCR2; else TIM10->CCR2 += _tim10_cc2; _tim10_cc1isrptr();}
	//if (TIM10->SR & TIM_SR_CC3IF) {TIM10->SR &=~TIM_SR_CC3IF; if (TIM10->CCER & TIM_CCER_CC3E) _tim10_cc3 = TIM10->CCR3; else TIM10->CCR3 += _tim10_cc3; _tim10_cc1isrptr();}
	//if (TIM10->SR & TIM_SR_CC4IF) {TIM10->SR &=~TIM_SR_CC4IF; if (TIM10->CCER & TIM_CCER_CC4E) _tim10_cc4 = TIM10->CCR4; else TIM10->CCR4 += _tim10_cc4; _tim10_cc1isrptr();}
	
	//ovf isr
	if ((TIM10->SR & TIM_SR_UIF) && (TIM10->DIER & TIM_DIER_UIE)) {TIM10->SR &=~TIM_SR_UIF; _tim10_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr10Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM10EN;

	//reset timer
	tmrInit(TIM10, ps);
}

//activate the ovf isr handler
void tmr10OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM10_IRQn);		//disable irq

	_tim10_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM10->SR &=~TIM_SR_UIF;				//clear the interrupt flag
	TIM10->DIER |= TIM_DIER_UIE;			//enable the isr

	NVIC_EnableIRQ(TIM10_IRQn);		//enable irq
	//priorities not set -> default values used.
}
//end tmr10
#endif	//TIM10


#if defined(RCC_APB2ENR_TIM11EN)
//tmr11
//global variables
static void (* _tim11_ovfisrptr)(void)=empty_handler;				//TIM11_ptr pointing to empty_handler by default
//static void (* _tim11_oc1isrptr)(void)=empty_handler;				//TIM11_ptr pointing to empty_handler by default
//static void (* _tim11_oc2isrptr)(void)=empty_handler;				//TIM11_ptr pointing to empty_handler by default
//static void (* _tim11_oc3isrptr)(void)=empty_handler;				//TIM11_ptr pointing to empty_handler by default
//static void (* _tim11_oc4isrptr)(void)=empty_handler;				//TIM11_ptr pointing to empty_handler by default

//static uint16_t _tim11_oc1=0;				//output compare registers
//static uint16_t _tim11_oc2=0;
//static uint16_t _tim11_oc3=0;
//static uint16_t _tim11_oc4=0;

//isr for timer1 capture / compare
void TIM11_IRQHandler(void) {
	//oc1 portion
	//if (TIM11->SR & TIM_SR_CC1IF) {TIM11->SR &=~TIM_SR_CC1IF; if (TIM11->CCER & TIM_CCER_CC1E) _tim11_cc1 = TIM11->CCR1; else TIM11->CCR1 += _tim11_cc1; _tim11_cc1isrptr();}
	//if (TIM11->SR & TIM_SR_CC2IF) {TIM11->SR &=~TIM_SR_CC2IF; if (TIM11->CCER & TIM_CCER_CC2E) _tim11_cc2 = TIM11->CCR2; else TIM11->CCR2 += _tim11_cc2; _tim11_cc1isrptr();}
	//if (TIM11->SR & TIM_SR_CC3IF) {TIM11->SR &=~TIM_SR_CC3IF; if (TIM11->CCER & TIM_CCER_CC3E) _tim11_cc3 = TIM11->CCR3; else TIM11->CCR3 += _tim11_cc3; _tim11_cc1isrptr();}
	//if (TIM11->SR & TIM_SR_CC4IF) {TIM11->SR &=~TIM_SR_CC4IF; if (TIM11->CCER & TIM_CCER_CC4E) _tim11_cc4 = TIM11->CCR4; else TIM11->CCR4 += _tim11_cc4; _tim11_cc1isrptr();}
	
	//ovf isr
	if ((TIM11->SR & TIM_SR_UIF) && (TIM11->DIER & TIM_DIER_UIE)) {TIM11->SR &=~TIM_SR_UIF; _tim11_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr11Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM11EN;

	//reset timer
	tmrInit(TIM11, ps);
}

//activate the ovf isr handler
void tmr11OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM11_IRQn);		//disable irq

	_tim11_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM11->SR &=~TIM_SR_UIF;				//clear the interrupt flag
	TIM11->DIER |= TIM_DIER_UIE;			//enable the isr

	NVIC_EnableIRQ(TIM11_IRQn);		//enable irq
	//priorities not set -> default values used.
}
//end tmr11
#endif	//TIM11

#if defined(RCC_APB1ENR_TIM12EN)	//defined(TIM12)
//tmr12
//global variables
static void (* _tim12_ovfisrptr)(void)=empty_handler;				//TIM12_ptr pointing to empty_handler by default
static void (* _tim12_oc1isrptr)(void)=empty_handler;				//TIM12_ptr pointing to empty_handler by default
static void (* _tim12_oc2isrptr)(void)=empty_handler;				//TIM12_ptr pointing to empty_handler by default
//static void (* _tim12_oc3isrptr)(void)=empty_handler;				//TIM12_ptr pointing to empty_handler by default
//static void (* _tim12_oc4isrptr)(void)=empty_handler;				//TIM12_ptr pointing to empty_handler by default

static uint16_t _tim12_oc1=0;				//output compare registers
static uint16_t _tim12_oc2=0;
//static uint16_t _tim12_oc3=0;
//static uint16_t _tim12_oc4=0;

//isr for timer1 capture / compare
void TIM1_BRK_TIM12_IRQHandler(void) {
	//oc1 portion
	if (TIM12->SR & TIM_SR_CC1IF) && (TIM12->DIER & TIM_DIER_CC1IE)) {TIM12->SR &=~TIM_SR_CC1IF; if (TIM12->CCER & TIM_CCER_CC1E) _tim12_cc1 = TIM12->CCR1; else TIM12->CCR1 += _tim12_cc1; _tim12_cc1isrptr();}
	if (TIM12->SR & TIM_SR_CC2IF) && (TIM12->DIER & TIM_DIER_CC2IE)) {TIM12->SR &=~TIM_SR_CC2IF; if (TIM12->CCER & TIM_CCER_CC2E) _tim12_cc2 = TIM12->CCR2; else TIM12->CCR2 += _tim12_cc2; _tim12_cc1isrptr();}
	if (TIM12->SR & TIM_SR_CC3IF) && (TIM12->DIER & TIM_DIER_CC3IE)) {TIM12->SR &=~TIM_SR_CC3IF; if (TIM12->CCER & TIM_CCER_CC3E) _tim12_cc3 = TIM12->CCR3; else TIM12->CCR3 += _tim12_cc3; _tim12_cc1isrptr();}
	if (TIM12->SR & TIM_SR_CC4IF) && (TIM12->DIER & TIM_DIER_CC4IE)) {TIM12->SR &=~TIM_SR_CC4IF; if (TIM12->CCER & TIM_CCER_CC4E) _tim12_cc4 = TIM12->CCR4; else TIM12->CCR4 += _tim12_cc4; _tim12_cc1isrptr();}
	
	//ovf isr
	if ((TIM12->SR & TIM_SR_UIF) && (TIM12->DIER & TIM_DIER_UIE)) {TIM12->SR &=~TIM_SR_UIF; _tim12_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr12Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM12EN;

	//reset timer
	tmrInit(TIM12, ps);
}

//activate the isr handler
void tmr12OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM12_IRQn);		//disable irq

	_tim12_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM12->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM12->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM12_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set TIM12_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr12OC1SetPR(uint16_t pr) {
	//save the period value
	_tim12_oc1 = pr - 0;
	TIM12->CCR1 = _tim12_oc1;

	//clear the flag
	//TIM12->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM12->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr12OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM12_IRQn);			//disable irq

	_tim12_oc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM12->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM12->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM12_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM12_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr12OC2SetPR(uint16_t pr) {
	//save the period value
	_tim12_oc2 = pr - 0;
	TIM12->CCR2 = _tim12_oc2;

	//clear the flag
	//TIM12->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM12->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr12OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM12_IRQn);			//disable irq

	_tim12_oc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM12->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM12->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM12_IRQn);			//enable irq
	//priorities not set -> default values used.
}


//ic1
void tmr12IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM12->CCMR1 = (TIM12->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM12->CCMR1 = (TIM12->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM12->SR &=~TIM_SR_CC1IF; TIM12->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM12->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM12 rmp to MCO (=3)
	//TIM12->OR = (TIM12->OR &~TIM12_OR_TI1_RMP) | (((3) << 0) & TIM12_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM12->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM12CH1toPIN)
	TIM12CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr12IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM12_IRQn);		//disable irq

	_tim12_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM12->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM12->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM12_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr12IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM12->CCMR1 = (TIM12->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM12->CCMR1 = (TIM12->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM12->SR &=~TIM_SR_CC2IF; TIM12->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM12->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM12 rmp to MCO (=3)
	//TIM12->OR = (TIM12->OR &~TIM12_OR_TI1_RMP) | (((3) << 0) & TIM12_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM12->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM12CH2toPIN)
	TIM12CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr12IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM12_IRQn);		//disable irq

	_tim12_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM12->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM12->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM12_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//end tmr12
#endif	//TIM12

#if defined(RCC_APB1ENR_TIM13EN)	//defined(TIM13)
//tmr13
//global variables
static void (* _tim13_ovfisrptr)(void)=empty_handler;				//TIM13_ptr pointing to empty_handler by default
static void (* _tim13_oc1isrptr)(void)=empty_handler;				//TIM13_ptr pointing to empty_handler by default
static void (* _tim13_oc2isrptr)(void)=empty_handler;				//TIM13_ptr pointing to empty_handler by default
//static void (* _tim13_oc3isrptr)(void)=empty_handler;				//TIM13_ptr pointing to empty_handler by default
//static void (* _tim13_oc4isrptr)(void)=empty_handler;				//TIM13_ptr pointing to empty_handler by default

static uint16_t _tim13_oc1=0;				//output compare registers
static uint16_t _tim13_oc2=0;
//static uint16_t _tim13_oc3=0;
//static uint16_t _tim13_oc4=0;

//isr for timer1 capture / compare
void TIM1_BRK_TIM13_IRQHandler(void) {
	//oc1 portion
	if ((TIM13->SR & TIM_SR_CC1IF) && (TIM13->DIER & TIM_DIER_CC1IE)) {TIM13->SR &=~TIM_SR_CC1IF; if (TIM13->CCER & TIM_CCER_CC1E) _tim13_cc1 = TIM13->CCR1; else TIM13->CCR1 += _tim13_cc1; _tim13_cc1isrptr();}
	if ((TIM13->SR & TIM_SR_CC2IF) && (TIM13->DIER & TIM_DIER_CC2IE)) {TIM13->SR &=~TIM_SR_CC2IF; if (TIM13->CCER & TIM_CCER_CC2E) _tim13_cc2 = TIM13->CCR2; else TIM13->CCR2 += _tim13_cc2; _tim13_cc1isrptr();}
	//if ((TIM13->SR & TIM_SR_CC3IF) && (TIM13->DIER & TIM_DIER_CC3IE)) {TIM13->SR &=~TIM_SR_CC3IF; if (TIM13->CCER & TIM_CCER_CC3E) _tim13_cc3 = TIM13->CCR3; else TIM13->CCR3 += _tim13_cc3; _tim13_cc1isrptr();}
	//if ((TIM13->SR & TIM_SR_CC4IF) && (TIM13->DIER & TIM_DIER_CC4IE)) {TIM13->SR &=~TIM_SR_CC4IF; if (TIM13->CCER & TIM_CCER_CC4E) _tim13_cc4 = TIM13->CCR4; else TIM13->CCR4 += _tim13_cc4; _tim13_cc1isrptr();}
	
	//ovf isr
	if ((TIM13->SR & TIM_SR_UIF) && (TIM13->DIER & TIM_DIER_UIE)) {TIM13->SR &=~TIM_SR_UIF; _tim13_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr13Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM13EN;

	//reset timer
	tmrInit(TIM13, ps);
}

//activate the isr handler
void tmr13OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM13_IRQn);		//disable irq

	_tim13_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM13->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM13->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM13_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set TIM13_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr13OC1SetPR(uint16_t pr) {
	//save the period value
	_tim13_oc1 = pr - 0;
	TIM13->CCR1 = _tim13_oc1;

	//clear the flag
	//TIM13->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM13->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr13OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM13_IRQn);			//disable irq

	_tim13_oc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM13->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM13->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM13_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM13_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr13OC2SetPR(uint16_t pr) {
	//save the period value
	_tim13_oc2 = pr - 0;
	TIM13->CCR2 = _tim13_oc2;

	//clear the flag
	//TIM13->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM13->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr13OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM13_IRQn);			//disable irq

	_tim13_oc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM13->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM13->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM13_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//ic1
void tmr13IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM13->CCMR1 = (TIM13->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM13->CCMR1 = (TIM13->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM13->SR &=~TIM_SR_CC1IF; TIM13->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM13->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM13 rmp to MCO (=3)
	//TIM13->OR = (TIM13->OR &~TIM13_OR_TI1_RMP) | (((3) << 0) & TIM13_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM13->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM13CH1toPIN)
	TIM13CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr13IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM13_IRQn);		//disable irq

	_tim13_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM13->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM13->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM13_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr13IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM13->CCMR1 = (TIM13->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM13->CCMR1 = (TIM13->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM13->SR &=~TIM_SR_CC2IF; TIM13->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM13->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM13 rmp to MCO (=3)
	//TIM13->OR = (TIM13->OR &~TIM13_OR_TI1_RMP) | (((3) << 0) & TIM13_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM13->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM13CH2toPIN)
	TIM13CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr13IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM13_IRQn);		//disable irq

	_tim13_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM13->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM13->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM13_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//end tmr13
#endif	//TIM13

#if defined(RCC_APB1ENR_TIM14EN)	//defined(TIM14)
//tmr14
//global variables
static void (* _tim14_ovfisrptr)(void)=empty_handler;				//TIM14_ptr pointing to empty_handler by default
static void (* _tim14_oc1isrptr)(void)=empty_handler;				//TIM14_ptr pointing to empty_handler by default
static void (* _tim14_oc2isrptr)(void)=empty_handler;				//TIM14_ptr pointing to empty_handler by default
//static void (* _tim14_oc3isrptr)(void)=empty_handler;				//TIM14_ptr pointing to empty_handler by default
//static void (* _tim14_oc4isrptr)(void)=empty_handler;				//TIM14_ptr pointing to empty_handler by default

static uint16_t _tim14_oc1=0;				//output compare registers
static uint16_t _tim14_oc2=0;
//static uint16_t _tim14_oc3=0;
//static uint16_t _tim14_oc4=0;

//isr for timer1 capture / compare
void TIM1_BRK_TIM14_IRQHandler(void) {
	//oc1 portion
	if ((TIM14->SR & TIM_SR_CC1IF) && (TIM14->DIER & TIM_DIER_CC1IE)) {TIM14->SR &=~TIM_SR_CC1IF; if (TIM14->CCER & TIM_CCER_CC1E) _tim14_cc1 = TIM14->CCR1; else TIM14->CCR1 += _tim14_cc1; _tim14_cc1isrptr();}
	if ((TIM14->SR & TIM_SR_CC2IF) && (TIM14->DIER & TIM_DIER_CC2IE)) {TIM14->SR &=~TIM_SR_CC2IF; if (TIM14->CCER & TIM_CCER_CC2E) _tim14_cc2 = TIM14->CCR2; else TIM14->CCR2 += _tim14_cc2; _tim14_cc1isrptr();}
	//if ((TIM14->SR & TIM_SR_CC3IF) && (TIM14->DIER & TIM_DIER_CC3IE)) {TIM14->SR &=~TIM_SR_CC3IF; if (TIM14->CCER & TIM_CCER_CC3E) _tim14_cc3 = TIM14->CCR3; else TIM14->CCR3 += _tim14_cc3; _tim14_cc1isrptr();}
	//if ((TIM14->SR & TIM_SR_CC4IF) && (TIM14->DIER & TIM_DIER_CC4IE)) {TIM14->SR &=~TIM_SR_CC4IF; if (TIM14->CCER & TIM_CCER_CC4E) _tim14_cc4 = TIM14->CCR4; else TIM14->CCR4 += _tim14_cc4; _tim14_cc1isrptr();}
	
	//ovf isr
	if ((TIM14->SR & TIM_SR_UIF) && (TIM14->DIER & TIM_DIER_UIE))  {TIM14->SR &=~TIM_SR_UIF; _tim14_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr14Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM14EN;

	//reset timer
	tmrInit(TIM14, ps);
}

//activate the isr handler
void tmr14OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM14_IRQn);		//disable irq

	_tim14_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM14->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM14->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM14_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set TIM14_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr14OC1SetPR(uint16_t pr) {
	//save the period value
	_tim14_oc1 = pr - 0;
	TIM14->CCR1 = _tim14_oc1;

	//clear the flag
	//TIM14->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM14->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr14OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM14_IRQn);			//disable irq

	_tim14_oc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM14->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM14->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM14_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM14_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr14OC2SetPR(uint16_t pr) {
	//save the period value
	_tim14_oc2 = pr - 0;
	TIM14->CCR2 = _tim14_oc2;

	//clear the flag
	//TIM14->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM14->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr14OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM14_IRQn);			//disable irq

	_tim14_oc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM14->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM14->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM14_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//ic1
void tmr14IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM14->CCMR1 = (TIM14->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM14->CCMR1 = (TIM14->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM14->SR &=~TIM_SR_CC1IF; TIM14->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM14->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM14 rmp to MCO (=3)
	//TIM14->OR = (TIM14->OR &~TIM14_OR_TI1_RMP) | (((3) << 0) & TIM14_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM14->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM14CH1toPIN)
	TIM14CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr14IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM14_IRQn);		//disable irq

	_tim14_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM14->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM14->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM14_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr14IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM14->CCMR1 = (TIM14->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM14->CCMR1 = (TIM14->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM14->SR &=~TIM_SR_CC2IF; TIM14->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM14->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM14 rmp to MCO (=3)
	//TIM14->OR = (TIM14->OR &~TIM14_OR_TI1_RMP) | (((3) << 0) & TIM14_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM14->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM14CH2toPIN)
	TIM14CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr14IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM14_IRQn);		//disable irq

	_tim14_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM14->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM14->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM14_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//end tmr14
#endif	//TIM14

//#if defined(STM32F10X_LD_VL) || defined(STM32F10X_MD_VL) || defined(STM32F10X_HD_VL)	//only available on _VL
#if defined(RCC_APB2ENR_TIM15EN)
//tmr15
//global variables
static void (* _tim15_ovfisrptr)(void)=empty_handler;				//TIM15_ptr pointing to empty_handler by default
static void (* _tim15_cc1isrptr)(void)=empty_handler;				//TIM15_ptr pointing to empty_handler by default
static void (* _tim15_cc2isrptr)(void)=empty_handler;				//TIM15_ptr pointing to empty_handler by default
//static void (* _tim15_cc3isrptr)(void)=empty_handler;				//TIM15_ptr pointing to empty_handler by default
//static void (* _tim15_cc4isrptr)(void)=empty_handler;				//TIM15_ptr pointing to empty_handler by default

static uint16_t _tim15_cc1=0;				//output compare registers
static uint16_t _tim15_cc2=0;
//static uint16_t _tim15_cc3=0;
//static uint16_t _tim15_cc4=0;

//isr for timer1 capture / compare
void TIM1_BRK_TIM15_IRQHandler(void) {
	//oc1 portion
	if ((TIM15->SR & TIM_SR_CC1IF) && (TIM15->DIER & TIM_DIER_CC1IE)) {TIM15->SR &=~TIM_SR_CC1IF; if (TIM15->CCER & TIM_CCER_CC1E) _tim15_cc1 = TIM15->CCR1; else TIM15->CCR1 += _tim15_cc1; _tim15_cc1isrptr();}
	if ((TIM15->SR & TIM_SR_CC2IF) && (TIM15->DIER & TIM_DIER_CC2IE)) {TIM15->SR &=~TIM_SR_CC2IF; if (TIM15->CCER & TIM_CCER_CC2E) _tim15_cc2 = TIM15->CCR2; else TIM15->CCR2 += _tim15_cc2; _tim15_cc1isrptr();}
	//if ((TIM15->SR & TIM_SR_CC3IF) && (TIM15->DIER & TIM_DIER_CC3IE)) {TIM15->SR &=~TIM_SR_CC3IF; if (TIM15->CCER & TIM_CCER_CC3E) _tim15_cc3 = TIM15->CCR3; else TIM15->CCR3 += _tim15_cc3; _tim15_cc1isrptr();}
	//if ((TIM15->SR & TIM_SR_CC4IF) && (TIM15->DIER & TIM_DIER_CC4IE)) {TIM15->SR &=~TIM_SR_CC4IF; if (TIM15->CCER & TIM_CCER_CC4E) _tim15_cc4 = TIM15->CCR4; else TIM15->CCR4 += _tim15_cc4; _tim15_cc1isrptr();}
	
	//ovf isr
	if ((TIM15->SR & TIM_SR_UIF) && (TIM15->DIER & TIM_DIER_UIE)) {TIM15->SR &=~TIM_SR_UIF; _tim15_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr15Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;

	//reset timer
	tmrInit(TIM15, ps);
}

//activate the isr handler
void tmr15OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);		//disable irq

	_tim15_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM15->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM15->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set TIM15_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr15OC1SetPR(uint16_t pr) {
	//save the period value
	_tim15_cc1 = pr - 0;
	TIM15->CCR1 = _tim15_cc1;

	//clear the flag
	//TIM15->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM15->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr15OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);			//disable irq

	_tim15_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM15->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM15->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM15_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr15OC2SetPR(uint16_t pr) {
	//save the period value
	_tim15_cc2 = pr - 0;
	TIM15->CCR2 = _tim15_cc2;

	//clear the flag
	//TIM15->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM15->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr15OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);			//disable irq

	_tim15_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM15->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM15->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//ic1
void tmr15IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM15->CCMR1 = (TIM15->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM15->CCMR1 = (TIM15->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM15->SR &=~TIM_SR_CC1IF; TIM15->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM15->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM15 rmp to MCO (=3)
	//TIM15->OR = (TIM15->OR &~TIM15_OR_TI1_RMP) | (((3) << 0) & TIM15_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM15->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM15CH1toPIN)
	TIM15CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr15IC1AttachISR(void (*isrptr)(void)) {
#if defined(STM32F10X_LD_VL) || defined(STM32F10X_MD_VL) || defined(STM32F10X_HD_VL)
	NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);		//disable irq

	_tim15_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM15->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM15->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);		//enable irq
	//priorities not set -> default values used.
#else
	NVIC_DisableIRQ(TIM15_IRQn);		//disable irq

	_tim15_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM15->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM15->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM15_IRQn);		//enable irq
	//priorities not set -> default values used.
#endif
}

//ic2
void tmr15IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM15->CCMR1 = (TIM15->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM15->CCMR1 = (TIM15->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM15->SR &=~TIM_SR_CC2IF; TIM15->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM15->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM15 rmp to MCO (=3)
	//TIM15->OR = (TIM15->OR &~TIM15_OR_TI1_RMP) | (((3) << 0) & TIM15_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM15->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM15CH2toPIN)
	TIM15CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr15IC2AttachISR(void (*isrptr)(void)) {
#if defined(STM32F10X_LD_VL) || defined(STM32F10X_MD_VL) || defined(STM32F10X_HD_VL)
	NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);		//disable irq

	_tim15_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM15->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM15->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);		//enable irq
	//priorities not set -> default values used.
#else
	NVIC_DisableIRQ(TIM15_IRQn);		//disable irq

	_tim15_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM15->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM15->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM15_IRQn);		//enable irq
	//priorities not set -> default values used.
#endif
}

//end tmr15
#endif	//TIM15

//#if defined(STM32F10X_LD_VL) || defined(STM32F10X_MD_VL) || defined(STM32F10X_HD_VL)	//only available on _VL
#if defined(RCC_APB2ENR_TIM16EN)
//tmr16
//global variables
static void (* _tim16_ovfisrptr)(void)=empty_handler;				//TIM16_ptr pointing to empty_handler by default
static void (* _tim16_cc1isrptr)(void)=empty_handler;				//TIM16_ptr pointing to empty_handler by default
static void (* _tim16_cc2isrptr)(void)=empty_handler;				//TIM16_ptr pointing to empty_handler by default
//static void (* _tim16_cc3isrptr)(void)=empty_handler;				//TIM16_ptr pointing to empty_handler by default
//static void (* _tim16_cc4isrptr)(void)=empty_handler;				//TIM16_ptr pointing to empty_handler by default

static uint16_t _tim16_cc1=0;				//output compare registers
static uint16_t _tim16_cc2=0;
//static uint16_t _tim16_cc3=0;
//static uint16_t _tim16_cc4=0;

//isr for timer16 capture / compare
void TIM1_UP_TIM16_IRQHandler(void) {
	//tim1 ovf
	//ovf isr
	if ((TIM1->SR & TIM_SR_UIF) && (TIM1->DIER & TIM_DIER_UIE)) {TIM1->SR &=~TIM_SR_UIF; _tim1_ovfisrptr();}
	
	//tim16
	//oc1 portion
	if ((TIM16->SR & TIM_SR_CC1IF) && (TIM16->DIER & TIM_DIER_CC1IE)) {TIM16->SR &=~TIM_SR_CC1IF; if (TIM16->CCER & TIM_CCER_CC1E) _tim16_cc1 = TIM16->CCR1; else TIM16->CCR1 += _tim16_cc1; _tim16_cc1isrptr();}
	if ((TIM16->SR & TIM_SR_CC2IF) && (TIM16->DIER & TIM_DIER_CC2IE)) {TIM16->SR &=~TIM_SR_CC2IF; if (TIM16->CCER & TIM_CCER_CC2E) _tim16_cc2 = TIM16->CCR2; else TIM16->CCR2 += _tim16_cc2; _tim16_cc1isrptr();}
	//if ((TIM16->SR & TIM_SR_CC3IF) && (TIM16->DIER & TIM_DIER_CC3IE)) {TIM16->SR &=~TIM_SR_CC3IF; if (TIM16->CCER & TIM_CCER_CC3E) _tim16_cc3 = TIM16->CCR3; else TIM16->CCR3 += _tim16_cc3; _tim16_cc1isrptr();}
	//if ((TIM16->SR & TIM_SR_CC4IF) && (TIM16->DIER & TIM_DIER_CC4IE)) {TIM16->SR &=~TIM_SR_CC4IF; if (TIM16->CCER & TIM_CCER_CC4E) _tim16_cc4 = TIM16->CCR4; else TIM16->CCR4 += _tim16_cc4; _tim16_cc1isrptr();}
	
	//ovf isr
	if ((TIM16->SR & TIM_SR_UIF) && (TIM16->DIER & TIM_DIER_UIE)) {TIM16->SR &=~TIM_SR_UIF; _tim16_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr16Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM16EN;

	//reset timer
	tmrInit(TIM16, ps);
}


//activate the isr handler
void tmr16OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_UP_TIM16_IRQn);		//disable irq

	_tim16_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM16->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM16->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set TIM16_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr16OC1SetPR(uint16_t pr) {
	//save the period value
	_tim16_cc1 = pr - 0;
	TIM16->CCR1 = _tim16_cc1;

	//clear the flag
	//TIM16->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM16->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr16OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_UP_TIM16_IRQn);			//disable irq

	_tim16_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM16->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM16->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM16_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr16OC2SetPR(uint16_t pr) {
	//save the period value
	_tim16_cc2 = pr - 0;
	TIM16->CCR2 = _tim16_cc2;

	//clear the flag
	//TIM16->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM16->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr16OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_UP_TIM16_IRQn);			//disable irq

	_tim16_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM16->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM16->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//ic1
void tmr16IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM16->CCMR1 = (TIM16->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM16->CCMR1 = (TIM16->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM16->SR &=~TIM_SR_CC1IF; TIM16->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM16->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM16 rmp to MCO (=3)
	//TIM16->OR = (TIM16->OR &~TIM16_OR_TI1_RMP) | (((3) << 0) & TIM16_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM16->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM16CH1toPIN)
	TIM16CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr16IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_UP_TIM16_IRQn);		//disable irq

	_tim16_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM16->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM16->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr16IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM16->CCMR1 = (TIM16->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM16->CCMR1 = (TIM16->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM16->SR &=~TIM_SR_CC2IF; TIM16->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM16->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM16 rmp to MCO (=3)
	//TIM16->OR = (TIM16->OR &~TIM16_OR_TI1_RMP) | (((3) << 0) & TIM16_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM16->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM16CH2toPIN)
	TIM16CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr16IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_UP_TIM16_IRQn);		//disable irq

	_tim16_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM16->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM16->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);		//enable irq
	//priorities not set -> default values used.
}

#endif	//TIM16

//#if defined(STM32F10X_LD_VL) || defined(STM32F10X_MD_VL) || defined(STM32F10X_HD_VL)	//only available on _VL
#if defined(RCC_APB2ENR_TIM17EN)
//tmr17
//global variables
static void (* _tim17_ovfisrptr)(void)=empty_handler;				//TIM17_ptr pointing to empty_handler by default
static void (* _tim17_cc1isrptr)(void)=empty_handler;				//TIM17_ptr pointing to empty_handler by default
static void (* _tim17_cc2isrptr)(void)=empty_handler;				//TIM17_ptr pointing to empty_handler by default
//static void (* _tim17_cc3isrptr)(void)=empty_handler;				//TIM17_ptr pointing to empty_handler by default
//static void (* _tim17_cc4isrptr)(void)=empty_handler;				//TIM17_ptr pointing to empty_handler by default

static uint16_t _tim17_cc1=0;				//output compare registers
static uint16_t _tim17_cc2=0;
//static uint16_t _tim17_cc3=0;
//static uint16_t _tim17_cc4=0;

//isr for timer16 capture / compare
void TIM1_TRG_COM_TIM17_IRQHandler(void) {
	//oc1 portion
	if ((TIM17->SR & TIM_SR_CC1IF) && (TIM17->DIER & TIM_DIER_CC1IE)) {TIM17->SR &=~TIM_SR_CC1IF; if (TIM17->CCER & TIM_CCER_CC1E) _tim17_cc1 = TIM17->CCR1; else TIM17->CCR1 += _tim17_cc1; _tim17_cc1isrptr();}
	if ((TIM17->SR & TIM_SR_CC2IF) && (TIM17->DIER & TIM_DIER_CC2IE)) {TIM17->SR &=~TIM_SR_CC2IF; if (TIM17->CCER & TIM_CCER_CC2E) _tim17_cc2 = TIM17->CCR2; else TIM17->CCR2 += _tim17_cc2; _tim17_cc1isrptr();}
	//if ((TIM17->SR & TIM_SR_CC3IF) && (TIM17->DIER & TIM_DIER_CC3IE)) {TIM17->SR &=~TIM_SR_CC3IF; if (TIM17->CCER & TIM_CCER_CC3E) _tim17_cc3 = TIM17->CCR3; else TIM17->CCR3 += _tim17_cc3; _tim17_cc1isrptr();}
	//if ((TIM17->SR & TIM_SR_CC4IF) && (TIM17->DIER & TIM_DIER_CC4IE)) {TIM17->SR &=~TIM_SR_CC4IF; if (TIM17->CCER & TIM_CCER_CC4E) _tim17_cc4 = TIM17->CCR4; else TIM17->CCR4 += _tim17_cc4; _tim17_cc1isrptr();}
	
	//ovf isr
	if ((TIM17->SR & TIM_SR_UIF) && (TIM17->DIER & TIM_DIER_UIE)) {TIM17->SR &=~TIM_SR_UIF; _tim17_ovfisrptr();}
}

//initialize the timer4 (16bit)
void tmr17Init(uint16_t ps) {
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM17EN;

	//reset timer
	tmrInit(TIM17, ps);
}


//activate the isr handler
void tmr17OVFAttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_TRG_COM_TIM17_IRQn);		//disable irq

	_tim17_ovfisrptr = isrptr;			//install user handler

	//clear the flag
	TIM17->SR &=~TIM_SR_UIF;			//clear the interrupt flag
	TIM17->DIER |= TIM_DIER_UIE;		//enable the isr

	NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//set TIM17_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr17OC1SetPR(uint16_t pr) {
	//save the period value
	_tim17_cc1 = pr - 0;
	TIM17->CCR1 = _tim17_cc1;

	//clear the flag
	//TIM17->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM17->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr17OC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_TRG_COM_TIM17_IRQn);			//disable irq

	_tim17_cc1isrptr = isrptr;				//install user handler

	//clear the flag
	TIM17->SR &=~TIM_SR_CC1IF;				//clear the interrupt flag
	TIM17->DIER |= TIM_DIER_CC1IE;			//enable the isr

	NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//set TIM17_oc1 period
//pr is 16-bit. 32-bit used for compatability;
void tmr17OC2SetPR(uint16_t pr) {
	//save the period value
	_tim17_cc2 = pr - 0;
	TIM17->CCR2 = _tim17_cc2;

	//clear the flag
	//TIM17->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	//TIM17->DIER &=~TIM_DIER_CC1IE;		//disable the isr
}

//activate the isr handler
void tmr17OC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_TRG_COM_TIM17_IRQn);			//disable irq

	_tim17_cc2isrptr = isrptr;				//install user handler

	//clear the flag
	TIM17->SR &=~TIM_SR_CC2IF;				//clear the interrupt flag
	TIM17->DIER |= TIM_DIER_CC2IE;			//enable the isr

	NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);			//enable irq
	//priorities not set -> default values used.
}

//ic1
void tmr17IC1Init(uint8_t ps) {
	//set up the capture channel 1
	TIM17->CCMR1 = (TIM17->CCMR1 &~TIM_CCMR1_CC1S) | (TIM_CCMR1_CC1S_0);	//0b01->input capture
	TIM17->CCMR1 = (TIM17->CCMR1 &~TIM_CCMR1_IC1PSC) | ((ps<<TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM17->SR &=~TIM_SR_CC1IF; TIM17->DIER &=~TIM_DIER_CC1IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM17->CCER |= TIM_CCER_CC1E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM17 rmp to MCO (=3)
	//TIM17->OR = (TIM17->OR &~TIM17_OR_TI1_RMP) | (((3) << 0) & TIM17_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM17->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM17CH1toPIN)
	TIM17CH1toPIN();											//configure the input capture pin
#endif	//ch1
}

//activate the isr handler
void tmr17IC1AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_TRG_COM_TIM17_IRQn);		//disable irq

	_tim17_cc1isrptr = isrptr;			//install user handler

	//clear the flag
	TIM17->SR &=~TIM_SR_CC1IF;			//clear the interrupt flag
	TIM17->DIER |= TIM_DIER_CC1IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);		//enable irq
	//priorities not set -> default values used.
}

//ic2
void tmr17IC2Init(uint8_t ps) {
	//set up the capture channel 1
	TIM17->CCMR1 = (TIM17->CCMR1 &~TIM_CCMR1_CC2S) | (TIM_CCMR1_CC2S_0);	//0b01->input capture
	TIM17->CCMR1 = (TIM17->CCMR1 &~TIM_CCMR1_IC2PSC) | ((ps<<TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC);	//INPUT prescaler: 0->1:1
	//clear the flag and disable the interrupt
	TIM17->SR &=~TIM_SR_CC2IF; TIM17->DIER &=~TIM_DIER_CC2IE;	//CLEAR_BIT the interrupt flag and disable the interrupt
	TIM17->CCER |= TIM_CCER_CC2E;							//1->ENABLE input capture, 0->disable ic 
	//map TIM17 rmp to MCO (=3)
	//TIM17->OR = (TIM17->OR &~TIM17_OR_TI1_RMP) | (((3) << 0) & TIM17_OR_TI1_RMP);	//0->gpio, 1->rtcclk, 2->hse/32, 3->mco
	//TIM17->EGR |=TIM_EGR_UG;								//force an update

#if defined(TIM17CH2toPIN)
	TIM17CH2toPIN();											//configure the input capture pin
#endif	//ch2
}

//activate the isr handler
void tmr17IC2AttachISR(void (*isrptr)(void)) {
	NVIC_DisableIRQ(TIM1_TRG_COM_TIM17_IRQn);		//disable irq

	_tim17_cc2isrptr = isrptr;			//install user handler

	//clear the flag
	TIM17->SR &=~TIM_SR_CC2IF;			//clear the interrupt flag
	TIM17->DIER |= TIM_DIER_CC2IE;		//enable the isr

	NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);		//enable irq
	//priorities not set -> default values used.
}
#endif	//TIM17


//32bit timers by chaining them
//initialize tim231as a synchronized 32-bit timer
//tim2 as master / lsw (including prescaler) to tim1 / msw of the 32-bit timer
//tim1 as slave / msw of the 32-bit timer
void tmr21Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr2Init(ps); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM2->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim1 as slave
	tmr1Init(1); TIM1->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM1->SMCR = (TIM1->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x01 << 4) | 				//tab 82: 0b001->//slave tim1 driven by tim2
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM1->CNT = TIM2->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr21Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM1->CNT;				//read the msw
		lsw = TIM2->CNT;				//read the lsw
	} while (msw != TIM1->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr21SetPR(uint32_t pr) {
	TIM2->ARR = (pr - 1);
	TIM1->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr21GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM1->ARR;
	tmp = ((tmp << 16) | TIM2->ARR) + 1;
	return tmp;
}

//32bit timers by chaining them
//initialize tim 31 as a synchronized 32-bit timer
//tim3 as master / lsw (including prescaler) to tim1 / msw of the 32-bit timer
//tim1 as slave / msw of the 32-bit timer
void tmr31Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr3Init(ps); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	TIM3->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim1 as slave
	tmr1Init(1); TIM1->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM1->SMCR = (TIM1->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x02 << 4) | 				//tab 82: 0b010->//slave tim1 driven by tim3
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM1->CNT = TIM3->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr31Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM1->CNT;				//read the msw
		lsw = TIM3->CNT;				//read the lsw
	} while (msw != TIM1->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr31SetPR(uint32_t pr) {
	TIM3->ARR = (pr - 1);
	TIM1->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr31GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM1->ARR;
	tmp = ((tmp << 16) | TIM3->ARR) + 1;
	return tmp;
}

#if defined(RCC_APB1ENR_TIM4EN)
//32bit timers by chaining them
//initialize tim41 as a synchronized 32-bit timer
//tim4 as master / lsw (including prescaler) to tim1 / msw of the 32-bit timer
//tim1 as slave / msw of the 32-bit timer
void tmr41Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr4Init(ps); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM4->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim1 as slave
	tmr1Init(1); TIM1->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM1->SMCR = (TIM1->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x03 << 4) | 				//tab 82: 0b011->//slave tim1 driven by tim4
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM1->CNT = TIM4->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr41Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM1->CNT;				//read the msw
		lsw = TIM4->CNT;				//read the lsw
	} while (msw != TIM1->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr41SetPR(uint32_t pr) {
	TIM4->ARR = (pr - 1);
	TIM1->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr41GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM1->ARR;
	tmp = ((tmp << 16) | TIM4->ARR) + 1;
	return tmp;
}
#endif	//tmr41

#if defined(RCC_APB1ENR_TIM15EN) && defined(RCC_APB1ENR_TIM1EN)
//32bit timers by chaining them
//initialize tim151 as a synchronized 32-bit timer
//tim15 as master / lsw (including prescaler) to tim1 / msw of the 32-bit timer
//tim1 as slave / msw of the 32-bit timer
void tmr151Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr15Init(ps); TIM15->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM15->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim1 as slave
	tmr1Init(1); TIM1->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM1->SMCR = (TIM1->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x00 << 4) | 				//tab 82: 0b000->//slave tim1 driven by tim15
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM1->CNT = TIM4->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM15->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr151Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM1->CNT;				//read the msw
		lsw = TIM15->CNT;				//read the lsw
	} while (msw != TIM1->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr151SetPR(uint32_t pr) {
	TIM15->ARR = (pr - 1);
	TIM1->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr151GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM1->ARR;
	tmp = ((tmp << 16) | TIM15->ARR) + 1;
	return tmp;
}
#endif	//tim151

//32bit timers by chaining them
//initialize tim12 as a synchronized 32-bit timer
//tim1 as master / lsw (including prescaler) to tim2 / msw of the 32-bit timer
//tim2 as slave / msw of the 32-bit timer
void tmr12Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr1Init(ps); TIM1->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM1->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim3 as slave
	tmr2Init(1); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM2->SMCR = (TIM2->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x00 << 4) | 				//tab 86: 0b000->//slave tim2 driven by tim1
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM2->CNT = TIM1->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr12Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM2->CNT;				//read the msw
		lsw = TIM1->CNT;				//read the lsw
	} while (msw != TIM2->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr12SetPR(uint32_t pr) {
	TIM1->ARR = (pr - 1);
	TIM2->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr12GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM2->ARR;
	tmp = ((tmp << 16) | TIM1->ARR) + 1;
	return tmp;
}

//initialize tim32 as a synchronized 32-bit timer
//tim3 as master / lsw (including prescaler) to tim2 / msw of the 32-bit timer
//tim2 as slave / msw of the 32-bit timer
void tmr32Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr3Init(ps); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM3->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr2Init(1); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM2->SMCR = (TIM2->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x02 << 4) | 				//tab 71: 0b010->//slave tim2 driven by tim3
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM2->CNT = TIM3->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr32Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM2->CNT;				//read the msw
		lsw = TIM3->CNT;				//read the lsw
	} while (msw != TIM2->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr32SetPR(uint32_t pr) {
	TIM3->ARR = (pr - 1);
	TIM2->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr32GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM2->ARR;
	tmp = ((tmp << 16) | TIM3->ARR) + 1;
	return tmp;
}

#if defined(RCC_APB1ENR_TIM4EN)
//initialize tim42 as a synchronized 32-bit timer
//tim4 as master / lsw (including prescaler) to tim2 / msw of the 32-bit timer
//tim2 as slave / msw of the 32-bit timer
void tmr42Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr4Init(ps); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM4->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr2Init(1); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM2->SMCR = (TIM2->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x03 << 4) | 				//tab 86: 0b011->//slave tim2 driven by tim4
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM2->CNT = TIM4->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr42Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM2->CNT;				//read the msw
		lsw = TIM4->CNT;				//read the lsw
	} while (msw != TIM2->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr42SetPR(uint32_t pr) {
	TIM4->ARR = (pr - 1);
	TIM2->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr42GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM2->ARR;
	tmp = ((tmp << 16) | TIM4->ARR) + 1;
	return tmp;
}
#endif	//tmr42

#if defined(RCC_APB1ENR_TIM15EN) && defined(RCC_APB1ENR_TIM2EN)
//initialize tim42 as a synchronized 32-bit timer
//tim15 as master / lsw (including prescaler) to tim2 / msw of the 32-bit timer
//tim2 as slave / msw of the 32-bit timer
void tmr152Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr15Init(ps); TIM15->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM15->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr2Init(1); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM2->SMCR = (TIM2->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x01 << 4) | 				//tab 86: 0b001->//slave tim2 driven by tim15
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM2->CNT = TIM4->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM15->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr152Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM2->CNT;				//read the msw
		lsw = TIM15->CNT;				//read the lsw
	} while (msw != TIM2->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr152SetPR(uint32_t pr) {
	TIM15->ARR = (pr - 1);
	TIM2->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr152GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM2->ARR;
	tmp = ((tmp << 16) | TIM15->ARR) + 1;
	return tmp;
}
#endif	//tim152

//32bit timers by chaining them
//initialize tim13 as a synchronized 32-bit timer
//tim1 as master / lsw (including prescaler) to tim3 / msw of the 32-bit timer
//tim3 as slave / msw of the 32-bit timer
void tmr13Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr1Init(ps); TIM1->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM1->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim3 as slave
	tmr3Init(1); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM3->SMCR = (TIM3->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x00 << 4) | 				//tab 86: 0b000->//slave tim3 driven by tim1
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM3->CNT = TIM1->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr13Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM3->CNT;				//read the msw
		lsw = TIM1->CNT;				//read the lsw
	} while (msw != TIM3->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr13SetPR(uint32_t pr) {
	TIM1->ARR = (pr - 1);
	TIM3->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr13GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM3->ARR;
	tmp = ((tmp << 16) | TIM1->ARR) + 1;
	return tmp;
}

//32bit timers by chaining them
//initialize tim23 as a synchronized 32-bit timer
//tim2 as master / lsw (including prescaler) to tim3 / msw of the 32-bit timer
//tim3 as slave / msw of the 32-bit timer
void tmr23Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr2Init(ps); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM2->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim3 as slave
	tmr3Init(1); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM3->SMCR = (TIM3->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x01 << 4) | 				//tab 86: 0b001->//slave tim3 driven by tim2
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM3->CNT = TIM2->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr23Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM3->CNT;				//read the msw
		lsw = TIM2->CNT;				//read the lsw
	} while (msw != TIM3->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr23SetPR(uint32_t pr) {
	TIM2->ARR = (pr - 1);
	TIM3->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr23GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM3->ARR;
	tmp = ((tmp << 16) | TIM2->ARR) + 1;
	return tmp;
}

#if defined(RCC_APB1ENR_TIM15EN) && defined(RCC_APB1ENR_TIM3EN)
//32bit timers by chaining them
//initialize tim23 as a synchronized 32-bit timer
//tim15 as master / lsw (including prescaler) to tim3 / msw of the 32-bit timer
//tim3 as slave / msw of the 32-bit timer
void tmr153Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr15Init(ps); TIM15->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM15->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim3 as slave
	tmr3Init(1); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM3->SMCR = (TIM3->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x02 << 4) | 				//tab 86: 0b010->//slave tim3 driven by tim15
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM3->CNT = TIM2->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM15->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr153Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM3->CNT;				//read the msw
		lsw = TIM15->CNT;				//read the lsw
	} while (msw != TIM3->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr153SetPR(uint32_t pr) {
	TIM15->ARR = (pr - 1);
	TIM3->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr153GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM3->ARR;
	tmp = ((tmp << 16) | TIM15->ARR) + 1;
	return tmp;
}
#endif	//tim153

#if defined(RCC_APB1ENR_TIM4EN)
//32bit timers by chaining them
//initialize tim43 as a synchronized 32-bit timer
//tim4 as master / lsw (including prescaler) to tim3 / msw of the 32-bit timer
//tim3 as slave / msw of the 32-bit timer
void tmr43Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr4Init(ps); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM4->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim3 as slave
	tmr3Init(1); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM3->SMCR = (TIM3->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x03 << 4) | 				//tab 71: 0b011->//slave tim3 driven by tim4
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM4->CNT = TIM3->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr43Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM3->CNT;				//read the msw
		lsw = TIM4->CNT;				//read the lsw
	} while (msw != TIM3->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr43SetPR(uint32_t pr) {
	TIM4->ARR = (pr - 1);
	TIM3->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr43GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM3->ARR;
	tmp = ((tmp << 16) | TIM4->ARR) + 1;
	return tmp;
}
#endif	//tmr43

#if defined(RCC_APB1ENR_TIM4EN)
//32bit timers by chaining them
//initialize tim14 as a synchronized 32-bit timer
//tim1 as master / lsw (including prescaler) to tim4 / msw of the 32-bit timer
//tim4 as slave / msw of the 32-bit timer
void tmr14Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr1Init(ps); TIM1->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM1->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim4 as slave
	tmr4Init(1); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM4->SMCR = (TIM4->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x00 << 4) | 				//tab 86: 0b000->//slave tim4 driven by tim1
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM4->CNT = TIM1->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr14Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM4->CNT;				//read the msw
		lsw = TIM1->CNT;				//read the lsw
	} while (msw != TIM4->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr14SetPR(uint32_t pr) {
	TIM1->ARR = (pr - 1);
	TIM4->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr14GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM4->ARR;
	tmp = ((tmp << 16) | TIM1->ARR) + 1;
	return tmp;
}
#endif	//tmr14

#if defined(RCC_APB1ENR_TIM4EN)
//initialize tim23 as a synchronized 32-bit timer
//tim2 as master / lsw (including prescaler) to tim3 / msw of the 32-bit timer
//tim4 as slave / msw of the 32-bit timer
void tmr24Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr2Init(ps); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM2->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr4Init(1); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM4->SMCR = (TIM4->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x01 << 4) | 				//tab 86: 0b001->//slave tim4 driven by tim2
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM4->CNT = TIM2->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr24Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM4->CNT;				//read the msw
		lsw = TIM2->CNT;				//read the lsw
	} while (msw != TIM4->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr24SetPR(uint32_t pr) {
	TIM2->ARR = (pr - 1);
	TIM4->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr24GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM4->ARR;
	tmp = ((tmp << 16) | TIM2->ARR) + 1;
	return tmp;
}
#endif	//tmr24

#if defined(RCC_APB1ENR_TIM4EN)
//initialize tim34 as a synchronized 32-bit timer
//tim4 as master / lsw (including prescaler) to tim4 / msw of the 32-bit timer
//tim4 as slave / msw of the 32-bit timer
void tmr34Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr3Init(ps); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM3->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr4Init(1); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM4->SMCR = (TIM4->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x02 << 4) | 				//tab 86: 0b010->//slave tim4 driven by tim3
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM4->CNT = TIM1->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr34Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM4->CNT;				//read the msw
		lsw = TIM3->CNT;				//read the lsw
	} while (msw != TIM4->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr34SetPR(uint32_t pr) {
	TIM3->ARR = (pr - 1);
	TIM4->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr34GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM4->ARR;
	tmp = ((tmp << 16) | TIM3->ARR) + 1;
	return tmp;
}
#endif	//tmr34

#if defined(RCC_APB1ENR_TIM15EN) && defined(RCC_APB1ENR_TIM4EN)
//initialize tim34 as a synchronized 32-bit timer
//tim15 as master / lsw (including prescaler) to tim4 / msw of the 32-bit timer
//tim4 as slave / msw of the 32-bit timer
void tmr154Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr15Init(ps); TIM15->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM15->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr4Init(1); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM4->SMCR = (TIM4->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x03 << 4) | 				//tab 86: 0b011->//slave tim4 driven by tim15
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM4->CNT = TIM1->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM15->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr154Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM4->CNT;				//read the msw
		lsw = TIM15->CNT;				//read the lsw
	} while (msw != TIM4->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr154SetPR(uint32_t pr) {
	TIM15->ARR = (pr - 1);
	TIM4->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr154GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM4->ARR;
	tmp = ((tmp << 16) | TIM15->ARR) + 1;
	return tmp;
}
#endif	//tim154

#if defined(RCC_APB1ENR_TIM2EN) && defined(RCC_APB1ENR_TIM5EN)
//initialize tim34 as a synchronized 32-bit timer
//tim2 as master / lsw (including prescaler) to tim4 / msw of the 32-bit timer
//tim5 as slave / msw of the 32-bit timer
void tmr25Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr2Init(ps); TIM2->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM2->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr5Init(1); TIM5->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM5->SMCR = (TIM5->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x00 << 4) | 				//tab 86: 0b000->//slave tim5 driven by tim2
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM5->CNT = TIM3->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM5->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr25Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM5->CNT;				//read the msw
		lsw = TIM2->CNT;				//read the lsw
	} while (msw != TIM5->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr25SetPR(uint32_t pr) {
	TIM2->ARR = (pr - 1);
	TIM5->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr25GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM5->ARR;
	tmp = ((tmp << 16) | TIM2->ARR) + 1;
	return tmp;
}
//tim25
#endif	//tim2 & tim5

#if defined(RCC_APB1ENR_TIM3EN) && defined(RCC_APB1ENR_TIM5EN)
//initialize tim34 as a synchronized 32-bit timer
//tim4 as master / lsw (including prescaler) to tim4 / msw of the 32-bit timer
//tim4 as slave / msw of the 32-bit timer
void tmr35Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr3Init(ps); TIM3->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM3->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr5Init(1); TIM5->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM5->SMCR = (TIM5->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x01 << 4) | 				//tab 86: 0b001->//slave tim5 driven by tim3
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM5->CNT = TIM3->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM5->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr35Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM5->CNT;				//read the msw
		lsw = TIM3->CNT;				//read the lsw
	} while (msw != TIM5->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr35SetPR(uint32_t pr) {
	TIM3->ARR = (pr - 1);
	TIM5->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr35GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM5->ARR;
	tmp = ((tmp << 16) | TIM3->ARR) + 1;
	return tmp;
}
//tim35
#endif	//tim3 & tim5

#if defined(RCC_APB1ENR_TIM4EN) && defined(RCC_APB1ENR_TIM5EN)
//32bit timers by chaining them
//initialize tim43 as a synchronized 32-bit timer
//tim4 as master / lsw (including prescaler) to tim3 / msw of the 32-bit timer
//tim3 as slave / msw of the 32-bit timer
void tmr45Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr4Init(ps); TIM4->CR1 &=~TIM_CR1_CEN;	//configure tmr2 and stop it
	TIM4->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler

	//initialize tim3 as slave
	tmr5Init(1); TIM5->CR1 &=~TIM_CR1_CEN;	//configure tmr3 and stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM5->SMCR = (TIM5->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x02 << 4) | 				//tab 71: 0b010->//slave tim5 driven by tim4
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM4->CNT = TIM5->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM5->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr45Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM5->CNT;				//read the msw
		lsw = TIM4->CNT;				//read the lsw
	} while (msw != TIM5->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr45SetPR(uint32_t pr) {
	TIM4->ARR = (pr - 1);
	TIM5->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr45GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM5->ARR;
	tmp = ((tmp << 16) | TIM4->ARR) + 1;
	return tmp;
}
//tim45
#endif	//tim4 & tim5

#if defined(RCC_APB1ENR_TIM5EN) && defined(RCC_APB1ENR_TIM12EN)
//initialize tim34 as a synchronized 32-bit timer
//tim12 as master / lsw (including prescaler) to tim4 / msw of the 32-bit timer
//tim5 as slave / msw of the 32-bit timer
void tmr125Init(uint16_t ps) {
	//initialize tim2 as master
	//enable clock to tim2
	tmr12Init(ps); TIM12->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	TIM12->CR2 = 0x20;					//MMS = 0b010->tim2 as prescaler
	//initialize tim4 as slave
	tmr5Init(1); TIM5->CR1 &=~TIM_CR1_CEN;	//configure tim2 but stop it
	//source from trgo -> enable slave mode and trigger on trgo
	TIM5->SMCR = (TIM5->SMCR &~(TIM_SMCR_TS | TIM_SMCR_SMS | TIM_SMCR_MSM)) |
			(0x03 << 4) | 				//tab 86: 0b011->//slave tim5 driven by tim12
			(0x07 << 0) |				//0b111->external trigger on trgo
			(1 << 7) |					//1->enable slave mode
			0x00;

	TIM5->CNT = TIM3->CNT = 0;			//reset the counters

	//enable the timer, msw first
	TIM5->CR1 |= TIM_CR1_CEN;			//enable the timer
	TIM12->CR1 |= TIM_CR1_CEN;			//enable the timer
}

//read 32-bit timer value
uint32_t tmr125Get(void) {
	uint16_t msw, lsw;					//timer's high/low words

	//double read to maintain atomicity
	do {
		msw = TIM5->CNT;				//read the msw
		lsw = TIM12->CNT;				//read the lsw
	} while (msw != TIM5->CNT);			//see if overflow has taken place
	return ((uint32_t) msw << 16) | lsw;			//return 32-bit time
}

//set 32-bit timer period
uint32_t tmr125SetPR(uint32_t pr) {
	TIM12->ARR = (pr - 1);
	TIM5->ARR = (pr - 1)>> 16;
	return pr;
}

//read 32-bit timer period
uint32_t tmr125GetPR(void) {
	uint32_t tmp;
	
	tmp = TIM5->ARR;
	tmp = ((tmp << 16) | TIM12->ARR) + 1;
	return tmp;
}
#endif	//tim125

//end Timer

//for pwm
//generic initialization code
void pwmInit(TIM_TypeDef *TIMx, uint16_t TxCCP_PS) {
	//source from internal clock -> disable slave mode
	TIMx->SMCR &=~TIM_SMCR_SMS;			//clear sms->use internal clock

	//stop the timer to configure it
	//TIMx->CR1 &=~TIM_CR1_CEN;			//clear cen. 0=disable the timer, 1=enable the timer
	//TIMx->CR1 &=~TIM_CR1_CKD;			//clear CKD0..1. 0b00->1x clock; 0b01->2:1 clock, 0b10->4:1 clk; 0b11->reserved
	//TIMx->CR1 &=~TIM_CR1_DIR;			//clear DIR bit. 0=upcounter, 1=downcounter
	//TIMx->CR1 &=~TIM_CR1_OPM;			//clear opm bit. 0=periodic timer, 1=one-shot timer
	//or to simply zero the register
	//TIMx->CR1 = 0;						//much easier
	TIMx->CR1 =	(0<<8) |				//0->1:1 clock, 1->2:1 clock, 2->4:1 clock, 3->reserved
				(0<<7) |				//1->APR buffered, 0->APR not buffered
				(0<<5) |				//0->edge-aligned, 1->center-aligned mode 1, 2->center-aligned mode 2, 3->center-aligned mode 3
				(0<<4) |				//0->upcounter, 1->downcounter
				(0<<3) |				//0->continous mode, 1->one pulse mode
				(0<<2) |				//update request source
				(0<<1) |				//0->UEV enabled, 1->UEV disabled
				(0<<0) |				//0->counter disabled, 1->counter enabled
				0x00;
	TIMx->CR2 = 0;						//default value
	TIMx->SMCR= 0;						//default value

	//set the prescaler
	TIMx->PSC = TxCCP_PS - 1;					//set the prescaler
	TIMx->RCR = 0;						//repetition counter = 0 (=no repetition)
	TIMx->ARR = PWM_PR;						//auto reload register / period = 0; - need to change for downcounters
	TIMx->CNT = 0;						//reset the counter

	//clear the status register bits for capture / compare flags
	TIMx->SR &=~(TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF | TIM_SR_UIF);
	//disable the interrupt by clearing the enable bits
	TIMx->DIER &=~(TIM_DIER_CC1IE | TIM_DIER_CC2IE | TIM_DIER_CC3IE | TIM_DIER_CC4IE | TIM_DIER_UIE);

	//RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIMx_REMAP) | (AFIO_MAPR_TIMx_REMAP & TIMxREMAP);	//select the remap scheme

	TIMx->EGR = 0xff;					//force an update
	TIMx->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	//TIMx->CR1 |= TIM_CR1_CEN;			//enable the timer

}

/*
MAPR Bits 7:6 TIM1_REMAP[1:0]: TIM1 remapping
These bits are set and cleared by software. They control the mapping of TIM1 channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN) on the GPIO ports.
00: No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
01: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1)
10: not used
11: Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12)
*/
//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm1Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	//route the clock to timer
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	pwmInit(TIM1, TxCCP_PS);			//initialize the pwm
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM1_REMAP) | (AFIO_MAPR_TIM1_REMAP & TIM1REMAP);	//select the remap scheme

	//configure CCP1..4
	//configure CCP1
#if defined(TIM1CH1toPIN) || defined(TIM1CH1NtoPIN)
	TIM1->CCMR1 = 	(TIM1->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
#if defined(TIM1CH1NtoPIN)
					(1<< 2) |			//0->disable CC1N, 1->enable CC1N
#else
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
#endif	//ch1n
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM1->CCR1 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM1CH1toPIN)
	TIM1CH1toPIN();
#endif	//ch1
#if defined(TIM1CH1NtoPIN)
	TIM1CH1NtoPIN();
#endif	//ch1n
#endif	//ch1 || ch1n

	//configure CCP2
#if defined(TIM1CH2toPIN) || defined(TIM1CH2NtoPIN)
	TIM1->CCMR1 = 	(TIM1->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 4)) |
					(0<< 7) |			//0->normal polarity for CC2N, 1->inverse polarity
#if defined(TIM1CH2NtoPIN)
					(1<< 6) |			//0->disable CC2N, 1->enable CC2N
#else
					(0<< 6) |			//0->disable CC2N, 1->enable CC2N
#endif	//ch2n
					(0<< 5) |			//0->normal polarity for CC2, 1->inverse polarity
					(1<< 4) |			//1->enable CC2, 0->disable CC2
					0x00;
	TIM1->CCR2 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM1CH2toPIN)
	TIM1CH2toPIN();
#endif	//ch2
#if defined(TIM1CH2NtoPIN)
	TIM1CH2NtoPIN();
#endif	//ch2n
#endif	//ch2 || ch2n

	//configure CCP3
#if defined(TIM1CH3toPIN) || defined(TIM1CH3NtoPIN)
	TIM1->CCMR2 = 	(TIM1->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 8)) |
					(0<<11) |			//0->normal polarity for CC3N, 1->inverse polarity
#if defined(TIM1CH3N)
					(1<<10) |			//0->disable CC3N, 1->enable CC3N
#else
					(0<<10) |			//0->disable CC3N, 1->enable CC3N
#endif	//ch3n
					(0<< 9) |			//0->normal polarity for CC3, 1->inverse polarity
					(1<< 8) |			//1->enable CC3, 0->disable CC3
					0x00;
	TIM1->CCR3 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM1CH3toPIN)
	TIM1CH3toPIN();
#endif	//ch3
#if defined(TIM1CH3NtoPIN)
	TIM1CH3NtoPIN();
#endif	//ch3n
#endif	//ch3 || ch3n

	//configure CCP4
#if defined(TIM1CH4toPIN) || defined(TIM1CH4NtoPIN)
	TIM1->CCMR2 = 	(TIM1->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM1->CCER = 	(TIM1->CCER &~(0x0f << 12)) |
					(0<<15) |			//0->normal polarity for CC4N, 1->inverse polarity
#if defined(TIM1CH4NtoPIN)
					(1<<14) |			//0->disable CC4N, 1->enable CC4N
#else
					(0<<14) |			//0->disable CC4N, 1->enable CC4N
#endif	//ch4n
					(0<<13) |			//0->normal polarity for CC4, 1->inverse polarity
					(1<<12) |			//1->enable CC4, 0->disable CC4
					0x00;
	TIM1->CCR4 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM1CH4toPIN)
	TIM1CH4toPIN();
#endif	//ch4
#if defined(TIM1CH4NtoPIN)
	TIM1CH4NtoPIN();
#endif	//ch4n
#endif	//ch4 || ch4n

	//TIM1->EGR = 0xff;					//force an update
	//TIM1->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	TIM1->CR1 |= TIM_CR1_CEN;			//enable the timer

}


/*
MAPR Bits 9:8 TIM2_REMAP[1:0]: TIM2 remapping
These bits are set and cleared by software. They control the mapping of TIM2 channels 1 to 4 and external trigger (ETR) on the GPIO ports.
00: No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
01: Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
10: Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
11: Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
*/
//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm2Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	pwmInit(TIM2, TxCCP_PS);			//initialize the pwm

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM2_REMAP) | (AFIO_MAPR_TIM2_REMAP & TIM2REMAP);	//select the remap scheme
	//configure CCP1..4


	//configure CCP1
#if defined(TIM2CH1toPIN) || defined(TIM2CH1NtoPIN)
	TIM2->CCMR1 = 	(TIM2->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM2->CCER = 	(TIM2->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
#if defined(TIM2CH1NtoPIN)
					(1<< 2) |			//0->disable CC1N, 1->enable CC1N
#else
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
#endif	//ch1n					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM2->CCR1 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM2CH1toPIN)
	TIM2CH1toPIN();
#endif	//ch1
#if defined(TIM2CH1NtoPIN)
	TIM2CH1NtoPIN();
#endif	//ch1n
#endif	//ch1 || ch1n

	//configure CCP2
#if defined(TIM2CH2toPIN) || defined(TIM2CH2NtoPIN)
	TIM2->CCMR1 = 	(TIM2->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM2->CCER = 	(TIM2->CCER &~(0x0f << 4)) |
					(0<< 7) |			//0->normal polarity for CC2N, 1->inverse polarity
#if defined(TIM2CH2NtoPIN)
					(1<< 6) |			//0->disable CC2N, 1->enable CC2N
#else
					(0<< 6) |			//0->disable CC2N, 1->enable CC2N
#endif	//ch2n
					(0<< 5) |			//0->normal polarity for CC2, 1->inverse polarity
					(1<< 4) |			//1->enable CC2, 0->disable CC2
					0x00;
	TIM2->CCR2 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM2CH2toPIN)
	TIM2CH2toPIN();
#endif	//ch2
#if defined(TIM2CH2NtoPIN)
	TIM2CH2NtoPIN();
#endif	//ch2n
#endif	//ch2 || ch2n

	//configure CCP3
#if defined(TIM2CH3toPIN) || defined(TIM2CH3NtoPIN)
	TIM2->CCMR2 = 	(TIM2->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM2->CCER = 	(TIM2->CCER &~(0x0f << 8)) |
					(0<<11) |			//0->normal polarity for CC3N, 1->inverse polarity
#if defined(TIM2CH3NtoPIN)
					(1<<10) |			//0->disable CC3N, 1->enable CC3N
#else
					(0<<10) |			//0->disable CC3N, 1->enable CC3N
#endif	//ch3n
					(0<< 9) |			//0->normal polarity for CC3, 1->inverse polarity
					(1<< 8) |			//1->enable CC3, 0->disable CC3
					0x00;
	TIM2->CCR3 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM2CH3toPIN)
	TIM2CH3toPIN();
#endif	//ch3
#if defined(TIM2CH3NtoPIN)
	TIM2CH3NtoPIN();
#endif	//ch3n
#endif	//ch3 || ch3n

	//configure CCP4
#if defined(TIM2CH4toPIN) || defined(TIM2CH4NtoPIN)
	TIM2->CCMR2 = 	(TIM2->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM2->CCER = 	(TIM2->CCER &~(0x0f << 12)) |
					(0<<15) |			//0->normal polarity for CC4N, 1->inverse polarity
#if defined(TIM2CH4NtoPIN)
					(1<<14) |			//0->disable CC4N, 1->enable CC4N
#else
					(0<<14) |			//0->disable CC4N, 1->enable CC4N
#endif	//ch4n
					(0<<13) |			//0->normal polarity for CC4, 1->inverse polarity
					(1<<12) |			//1->enable CC4, 0->disable CC4
					0x00;
	TIM2->CCR4 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM2CH4toPIN)
	TIM2CH4toPIN();
#endif	//ch4
#if defined(TIM2CH4NtoPIN)
	TIM2CH4NtoPIN();
#endif	//ch4n
#endif	//ch4 || ch4n

	//TIM2->EGR = 0xff;					//force an update
	//TIM2->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	TIM2->CR1 |= TIM_CR1_CEN;			//enable the timer

}


//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm3Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	pwmInit(TIM3, TxCCP_PS);			//initialize the pwm

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM3_REMAP) | (AFIO_MAPR_TIM3_REMAP & TIM3REMAP);	//select the remap scheme
	//configure CCP1..4

	//configure CCP1
#if defined(TIM3CH1toPIN) || defined(TIM3CH1NtoPIN)
	TIM3->CCMR1 = 	(TIM3->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM3->CCR1 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM3CH1toPIN)
	TIM3CH1toPIN();
#endif	//ch1
#if defined(TIM3CH1NtoPIN)
	TIM3CH1NtoPIN();
#endif	//ch1n
#endif	//ch1 || ch1n

	//configure CCP2
#if defined(TIM3CH2toPIN) || defined(TIM3CH2NtoPIN)
	TIM3->CCMR1 = 	(TIM3->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 4)) |
					(0<< 7) |			//0->normal polarity for CC2N, 1->inverse polarity
#if defined(TIM3CH2NtoPIN)
					(1<< 6) |			//0->disable CC2N, 1->enable CC2N
#else
					(0<< 6) |			//0->disable CC2N, 1->enable CC2N
#endif	//ch2n
					(0<< 5) |			//0->normal polarity for CC2, 1->inverse polarity
					(1<< 4) |			//1->enable CC2, 0->disable CC2
					0x00;
	TIM3->CCR2 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM3CH2toPIN)
	TIM3CH2toPIN();
#endif	//ch2
#if defined(TIM3CH2NtoPIN)
	TIM3CH2NtoPIN();
#endif	//ch2n
#endif	//ch2 || ch2n

	//configure CCP3
#if defined(TIM3CH3toPIN) || defined(TIM3CH3NtoPIN)
	TIM3->CCMR2 = 	(TIM3->CCMR2 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 8)) |
					(0<<11) |			//0->normal polarity for CC3N, 1->inverse polarity
#if defined(TIM3CH3NtoPIN)
					(1<<10) |			//0->disable CC3N, 1->enable CC3N
#else
					(0<<10) |			//0->disable CC3N, 1->enable CC3N
#endif	//ch3n
					(0<< 9) |			//0->normal polarity for CC3, 1->inverse polarity
					(1<< 8) |			//1->enable CC3, 0->disable CC3
					0x00;
	TIM3->CCR3 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM3CH3toPIN)
	TIM3CH3toPIN();
#endif	//ch3
#if defined(TIM3CH3NtoPIN)
	TIM3CH3NtoPIN();
#endif	//ch3n
#endif	//ch3 || ch3n

	//configure CCP4
#if defined(TIM3CH4toPIN) || defined(TIM3CH4NtoPIN)
	TIM3->CCMR2 = 	(TIM3->CCMR2 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM3->CCER = 	(TIM3->CCER &~(0x0f << 12)) |
					(0<<15) |			//0->normal polarity for CC4N, 1->inverse polarity
#if defined(TIM3CH4NtoPIN)
					(1<<14) |			//0->disable CC4N, 1->enable CC4N
#else
					(0<<14) |			//0->disable CC4N, 1->enable CC4N
#endif	//ch4n
					(0<<13) |			//0->normal polarity for CC4, 1->inverse polarity
					(1<<12) |			//1->enable CC4, 0->disable CC4
					0x00;
	TIM3->CCR4 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM3CH4toPIN)
	TIM3CH4toPIN();
#endif	//ch4
#if defined(TIM3CH4NtoPIN)
	TIM3CH4NtoPIN();
#endif	//ch4n
#endif	//ch4 || ch4n

	//TIM3->EGR = 0xff;					//force an update
	//TIM3->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	TIM3->CR1 |= TIM_CR1_CEN;			//enable the timer

}

#if defined(RCC_APB1ENR_TIM4EN)
//set duty cycle
/*
Bits 11:10 TIM3_REMAP[1:0]: TIM3 remapping
These bits are set and cleared by software. They control the mapping of TIM3 channels 1 to 4 on the GPIO ports.
00: No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
01: Not used
10: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
11: Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
Note: TIM3_ETR on PE0 is not re-mapped.
*/
//initialize pwm to TxCCP_PS (prescaler) and TxCCP_PR (period)
void pwm4Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	pwmInit(TIM4, TxCCP_PS);			//initialize the pwm

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM4_REMAP) | (AFIO_MAPR_TIM4_REMAP & TIM4REMAP);	//select the remap scheme
	//configure CCP1..4

	//configure CCP1
#if defined(TIM4CH1toPIN) || defined(TIM4CH1NtoPIN)
	TIM4->CCMR1 = 	(TIM4->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM4->CCER = 	(TIM4->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
#if defined(TIM4CH1NtoPIN)
					(1<< 2) |			//0->disable CC1N, 1->enable CC1N
#else
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
#endif	//ch1n
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM4->CCR1 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM4CH1toPIN)
	TIM4CH1toPIN();
#endif	//ch1
#if defined(TIM4CH1NtoPIN)
	TIM4CH1NtoPIN();
#endif	//ch1n
#endif	//ch1 || ch1n

	//configure CCP2
#if defined(TIM4CH2toPIN) || defined(TIM4CH2NtoPIN)
	TIM4->CCMR1 = 	(TIM4->CCMR1 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM4->CCER = 	(TIM4->CCER &~(0x0f << 4)) |
					(0<< 7) |			//0->normal polarity for CC2N, 1->inverse polarity
#if defined(TIM4CH2NtoPIN)
					(1<< 6) |			//0->disable CC2N, 1->enable CC2N
#else
					(0<< 6) |			//0->disable CC2N, 1->enable CC2N
#endif	//ch2n
					(0<< 5) |			//0->normal polarity for CC2, 1->inverse polarity
					(1<< 4) |			//1->enable CC2, 0->disable CC2
					0x00;
	TIM4->CCR2 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM4CH2toPIN)
	TIM4CH2toPIN();
#endif	//ch2
#if defined(TIM4CH2NtoPIN)
	TIM4CH2NtoPIN();
#endif	//ch2n
#endif	//ch2 || ch2n

	//configure CCP3
#if defined(TIM4CH3toPIN) || defined(TIM4CH3NtoPIN)
	TIM4->CCMR2 = 	(TIM4->CCMR2 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM4->CCER = 	(TIM4->CCER &~(0x0f << 8)) |
					(0<<11) |			//0->normal polarity for CC3N, 1->inverse polarity
#if defined(TIM4CH3NtoPIN)
					(1<<10) |			//0->disable CC3N, 1->enable CC3N
#else
					(0<<10) |			//0->disable CC3N, 1->enable CC3N
#endif	//ch3n
					(0<< 9) |			//0->normal polarity for CC3, 1->inverse polarity
					(1<< 8) |			//1->enable CC3, 0->disable CC3
					0x00;
	TIM4->CCR3 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM4CH3toPIN)
	TIM4CH3toPIN();
#endif	//ch3
#if defined(TIM4CH3NtoPIN)
	TIM4CH3NtoPIN();
#endif	//ch3n
#endif	//ch3 | ch3n

	//configure CCP4
#if defined(TIM4CH4toPIN) || defined(TIM4CH4NtoPIN)
	TIM4->CCMR2 = 	(TIM4->CCMR2 &~0xff00) |
					(0<<15) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<12) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<11) |			//0->preload disabled, 1->preload enabled
					(0<<10) |			//0->fast disabled, 1->fast enabled
					(0<<8) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM4->CCER = 	(TIM4->CCER &~(0x0f << 12)) |
					(0<<15) |			//0->normal polarity for CC4N, 1->inverse polarity
#if defined(TIM4CH4NtoPIN)
					(1<<14) |			//0->disable CC4N, 1->enable CC4N
#else
					(0<<14) |			//0->disable CC4N, 1->enable CC4N
#endif
					(0<<13) |			//0->normal polarity for CC4, 1->inverse polarity
					(1<<12) |			//1->enable CC4, 0->disable CC4
					0x00;
	TIM4->CCR4 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM4CH4toPIN)
	TIM4CH4toPIN();
#endif	//ch4
#if defined(TIM4CH4NtoPIN)
	TIM4CH4NtoPIN();
#endif	//ch4n
#endif	//ch4 || ch4n

	//TIM4->EGR = 0xff;					//force an update
	//TIM4->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	TIM4->CR1 |= TIM_CR1_CEN;			//enable the timer
}
#endif	//RCC_APB1ENR_TIM4EN

#if defined(RCC_APB2ENR_TIM15EN)
//pwm15
void pwm15Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB2ENR_TIM15EN;

	pwmInit(TIM15, TxCCP_PS);			//initialize the pwm

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM15_REMAP) | (AFIO_MAPR_TIM15_REMAP & TIM15REMAP);	//select the remap scheme
	//configure CCP1..4

	//configure CCP1
#if defined(TIM15CH1toPIN) || defined(TIM15CH1NtoPIN)
	TIM15->CCMR1 = 	(TIM15->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM15->CCER = 	(TIM15->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
#if defined(TIM15CH1NtoPIN)
					(1<< 2) |			//0->disable CC1N, 1->enable CC1N
#else
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
#endif	//ch1n
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM15->CCR1 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM15CH1toPIN)
	TIM15CH1toPIN();
#endif	//ch1
#if defined(TIM15CH1NtoPIN)
	TIM15CH1NtoPIN();
#endif	//ch1n
#endif	//ch1 || ch1n

	//TIM15->EGR = 0xff;					//force an update
	//TIM15->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	TIM15->CR1 |= TIM_CR1_CEN;			//enable the timer
}
#endif	//tim15


#if defined(RCC_APB2ENR_TIM16EN)
//pwm16
void pwm16Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB2ENR_TIM16EN;

	pwmInit(TIM16, TxCCP_PS);			//initialize the pwm

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM16_REMAP) | (AFIO_MAPR_TIM16_REMAP & TIM16REMAP);	//select the remap scheme
	//configure CCP1..4

	//configure CCP1
#if defined(TIM16CH1toPIN) || defined(TIM16CH1NtoPIN)
	TIM16->CCMR1 = 	(TIM16->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM16->CCER = 	(TIM16->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
#if defined(TIM16CH1NtoPIN)
					(1<< 2) |			//0->disable CC1N, 1->enable CC1N
#else
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
#endif	//ch1n
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM16->CCR1 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM16CH1toPIN)
	TIM16CH1toPIN();
#endif	//ch1
#if defined(TIM16CH1NtoPIN)
	TIM16CH1NtoPIN();
#endif	//ch1n
#endif	//ch1 || ch1n

	//TIM16->EGR = 0xff;					//force an update
	//TIM16->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	TIM16->CR1 |= TIM_CR1_CEN;			//enable the timer
}
#endif	//TIM16


#if defined(RCC_APB2ENR_TIM17EN)
//pwm17
void pwm17Init(uint16_t TxCCP_PS) {
	//route the clock to timer
	RCC->APB1ENR |= RCC_APB2ENR_TIM17EN;

	pwmInit(TIM17, TxCCP_PS);			//initialize the pwm

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				//enable AFIO
	//AFIO->MAPR = (AFIO->MAPR &~AFIO_MAPR_TIM17_REMAP) | (AFIO_MAPR_TIM17_REMAP & TIM17REMAP);	//select the remap scheme
	//configure CCP1..4

	//configure CCP1
#if defined(TIM17CH1toPIN) || defined(TIM17CH1NtoPIN)
	TIM17->CCMR1 = 	(TIM17->CCMR1 &~0x00ff) |
					(0<<7) |			//0->OC1REF not affedted by ETRF, 1->OC1REF cleared by ETRF high
					(6<<4) |			//0->frozen (for time base), 1->active on match, 2->inactive on match, 3->toggle, 4->inactive, 5->active, 6->pwm mode 1, 7->pwm mode 2
					(0<<3) |			//0->preload disabled, 1->preload enabled
					(0<<2) |			//0->fast disabled, 1->fast enabled
					(0<<0) |			//0->ch1 as output, 1->ch1 as input, 2->ch1 as input, 3->ch1 as input
					0x00;
	TIM17->CCER = 	(TIM17->CCER &~(0x0f << 0)) |
					(0<< 3) |			//0->normal polarity for CC1N, 1->inverse polarity
#if defined(TIM17CH1NtoPIN)
					(1<< 2) |			//0->disable CC1N, 1->enable CC1N
#else
					(0<< 2) |			//0->disable CC1N, 1->enable CC1N
#endif	//ch1n
					(0<< 1) |			//0->normal polarity for CC1, 1->inverse polarity
					(1<< 0) |			//1->enable CC1, 0->disable CC1
					0x00;
	TIM17->CCR1 = 0;						//0% duty cycle

	//configure gpio for pwm output
#if defined(TIM17CH1toPIN)
	TIM17CH1toPIN();
#endif	//ch1
#if defined(TIM17CH1NtoPIN)
	TIM17CH1NtoPIN();
#endif	//ch1n
#endif	//ch1 || ch1n

	//TIM17->EGR = 0xff;					//force an update
	//TIM17->BDTR |= TIM_BDTR_MOE;			//enable MOE bit
	//enable the timer.
	TIM17->CR1 |= TIM_CR1_CEN;			//enable the timer
}
#endif	//TIM17

//adc module
uint32_t _adc_calibration=0;
//global variables
//static uint32_t _adc_calfactor;				//adc calibration factor
//initialize adc
void adc1Init(void) {
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;		//enable clock to ADC1
	ADC1->CR1 = (0<<23) |					//0->disable analog watchdog on regular channels
				(0<<22) |					//0->disable analog watchdog on injected channels
				(0<<13) |					//0->1 ch for discontinous conversion
				(0<<12) |					//0->discontinous mode for injected channels disabled
				(0<<11) |					//0->discontinous mode for regular channel disabled
				(0<<10) |					//0->automatic injected conversion disabled
				(0<< 9) |					//0->analog watchdog enabled on all channels
				(0<< 8) |					//0->scan mode disabled
				(0<< 7) |					//0->EOC interrupt on injected conversion disabled
				(0<< 6) |					//0->interrupt on analog watchdog disabled
				(0<< 5) |					//0->EOC interrupt on regular channels disabled
				(0<< 0) |					//ADC watchdog channels, 0..17 (16=Temperature sensor, 17 = Vrefint)
				0x00;
	ADC1->CR2 = (1<<23) |					//0->temperature/internal vref sensor disabled
				(0<<22) |					//1->start conversion on regular channel. 0->reset state. cleared by software
				(0<<21) |					//1->start conversion on injected channels. 0->reset state. cleared by s oftware
				(1<<20) |					//0->regular conversion on external event disabled
				(7<<17) |					//7->regular conversion triggered by software
				(0<<15) |					//0->injected conversion on external event disabled
				(7<<12) |					//7->injected conversion triggered by software
				(0<<11) |					//0->right aligned, 1->left aligned
				(0<< 3) |					//0->caliberatin stablized, 1->caliberatin initialized
				(0<< 2) |					//0->calibration complete, 1->initialize calibration
				(0<< 1) |					//0->single conversion mode, 1->continous conversion mode
				(1<< 0);					//1->adc1 on, 0->adc1 off
	//set adc sample time
	//0b111->239.5 cycles for all channels
	ADC1->SMPR1 = 	(ADC_SMPR << (3 * 7)) |
					(ADC_SMPR << (3 * 6)) |
					(ADC_SMPR << (3 * 5)) |
					(ADC_SMPR << (3 * 4)) |
					(ADC_SMPR << (3 * 3)) |
					(ADC_SMPR << (3 * 2)) |
					(ADC_SMPR << (3 * 1)) |
					(ADC_SMPR << (3 * 0)) |
					0x00;
	ADC1->SMPR2 = 	(ADC_SMPR << (3 * 9)) |
					(ADC_SMPR << (3 * 8)) |
					(ADC_SMPR << (3 * 7)) |
					(ADC_SMPR << (3 * 6)) |
					(ADC_SMPR << (3 * 5)) |
					(ADC_SMPR << (3 * 4)) |
					(ADC_SMPR << (3 * 3)) |
					(ADC_SMPR << (3 * 2)) |
					(ADC_SMPR << (3 * 1)) |
					(ADC_SMPR << (3 * 0)) |
					0x00;
	//set adc channel sequence
	ADC1->SQR3 = ADC1->SQR2 = ADC1->SQR1 = 0;							//0->1 conversion

	//optional: adc self-calibration
	//start caliberation
	ADC1->CR2 |= (1<<3);					//1->initialize calibration registers
	while ((ADC1->CR2) & (1<<3)) continue;	//wait for calibration to initialize
	ADC1->CR2 |= (1<<2);					//1->initialize calibration
	while ((ADC1->CR2) & (1<<2)) continue;	//wait for calibration to finish
	_adc_calibration = ADC1->DR;			//save calibration code
	//now adc is calibrated
	//ADC1->CR2 |= ADC_CR2_ADON;				//1->turn on adc, 0->turn off adc
}

//analog to digital converter on ADC1
//ain/analog input channel: ain valid values: 0..15, 16=temperature sensor, 17=Vrefint
//***user needs to be configured as floating input***
uint16_t adc1Read(uint32_t ain) {
	ADC1->SR &= ~(1<<1);					//clear the eoc flag
	//ADC1->CR1 = (ADC1->CR1 &~0x1f) | (ain & 0x1f);	//pick the adc channel
	//ADC1->CR2|= (1<<0);					//start the conversion
	ADC1->SQR3 = ain & 0x1f;				//define the first (and only) adc ch
	ADC1->CR2 |= (1<<22);					//start conversion
	while ((ADC1->SR & (1<<1)) == 0) continue;	//wait for conversion to end (EOC set at end of conversion)
	return ADC1->DR - _adc_calibration;						//return adc results
}

//end ADC

#if 0
//input capture
static void (*_ic1_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC1DAT=0;						//buffer 

//input capture ISR
void _ISR_PSV _IC1Interrupt(void) {				//for PIC32
	//clear the flag
	IC1DAT = IC1BUF;							//read the captured value
	IFS0bits.IC1IF = 0;							//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic1_isrptr();								//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic1Init(void) {
	_ic1_isrptr = empty_handler;				//reset user handler

	IC12RP();									//assign pin to IC
	PMD2bits.IC1MD = 0;							//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
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

	IC1BUF;								//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC1CON1bits.ON = 1;					//1->enable the module, 0->disable the module
#else
	//for ga002 devices
	IC1CON = 0;						//reset to default value
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

	IC1BUF;								//read the buffer to clear the flag
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
	IC1BUF;								//read the buffer to clear the flag
	IFS0bits.IC1IF   = 0;				//0->clear the flag
	IEC0bits.IC1IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic1Get(void) {
	return IC1DAT;
}
	
static void (*_ic2_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC2DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC2Interrupt(void) {		//for PIC32
	//clear the flag
	IC2DAT = IC2BUF;					//read the captured value
	IFS0bits.IC2IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic2_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic2Init(void) {
	_ic2_isrptr = empty_handler;		//reset user handler

	IC22RP();							//assign pin to IC
	PMD2bits.IC2MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
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

	IC2BUF;								//read the buffer to clear the flag
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

	IC2BUF;								//read the buffer to clear the flag
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
	IC2BUF;								//read the buffer to clear the flag
	IFS0bits.IC2IF   = 0;				//0->clear the flag
	IEC0bits.IC2IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic2Get(void) {
	return IC2DAT;
}
	
static void (*_ic3_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC3DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC3Interrupt(void) {		//for PIC32
	//clear the flag
	IC3DAT = IC3BUF;					//read the captured value
	IFS2bits.IC3IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic3_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic3Init(void) {
	_ic3_isrptr = empty_handler;		//reset user handler

	IC32RP();							//assign pin to IC
	PMD2bits.IC3MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
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

	IC3BUF;								//read the buffer to clear the flag
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

	IC3BUF;								//read the buffer to clear the flag
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
	IC3BUF;								//read the buffer to clear the flag
	IFS2bits.IC3IF   = 0;				//0->clear the flag
	IEC2bits.IC3IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic3Get(void) {
	return IC3DAT;
}
	
static void (*_ic4_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC4DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC4Interrupt(void) {		//for PIC32
	//clear the flag
	IC4DAT = IC4BUF;					//read the captured value
	IFS2bits.IC4IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic4_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic4Init(void) {
	_ic4_isrptr = empty_handler;		//reset user handler

	IC42RP();							//assign pin to IC
	PMD2bits.IC4MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
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

	IC4BUF;								//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 0;				//1->enable the interrupt, 0->disable the interrupt
	//ICxIP   = 1;						//optional
	//enable the input capture
	//IC4CON1bits.ON = 1;				//1->enable the module, 0->disable the module
	//input capture running now
#else
	//for ga002 devices
	IC4CON = 0;						//reset to default value
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

	IC4BUF;								//read the buffer to clear the flag
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
	IC4BUF;								//read the buffer to clear the flag
	IFS2bits.IC4IF   = 0;				//0->clear the flag
	IEC2bits.IC4IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic4Get(void) {
	return IC4DAT;
}
	
static void (*_ic5_isrptr)(void)=empty_handler;				//function pointer pointing to empty_handler by default
volatile uint16_t IC5DAT=0;				//buffer 

//input capture ISR
void _ISR_PSV _IC5Interrupt(void) {		//for PIC32
	//clear the flag
	IC5DAT = IC5BUF;					//read the captured value
	IFS2bits.IC5IF = 0;					//clear the flag after the buffer has been read (the interrupt flag is persistent)
	_ic5_isrptr();						//run user handler
}

//reset input capture 1
//16-bit mode, rising edge, single capture, Timer2 as timebase
//interrupt disabled
void ic5Init(void) {
	_ic5_isrptr = empty_handler;		//reset user handler

	IC52RP();							//assign pin to IC
	PMD2bits.IC5MD = 0;					//0->enable power to input capture

#if 	defined(__PIC24FJ64GA102__) | defined (__PIC24FJ64GA104__) | \
		defined(__PIC24FJ32GA102__) | defined (__PIC24FJ32GA104__)
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

	IC5BUF;								//read the buffer to clear the flag
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

	IC5BUF;								//read the buffer to clear the flag
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
	IC5BUF;								//read the buffer to clear the flag
	IFS2bits.IC5IF   = 0;				//0->clear the flag
	IEC2bits.IC5IE   = 1;				//1->enable the interrupt, 0->disable the interrupt
}

//read buffer value
uint16_t ic5Get(void) {
	return IC5DAT;
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
	INT12RP();							//map int1_pin
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
	INT22RP();							//map int2_pin
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
#endif	//0

//spi
//generic set up routing
void spiInit(SPI_TypeDef *SPIx, uint16_t br) {
	SPIx->CR1 = (br << 3) & SPI_CR1_BR;	//reset value
	SPIx->CR2 = 0;						//reset value
	SPIx->CR1|= SPI_CR1_MSTR;			//1->master, 0->slave
	SPIx->SR = 0;						//reset all flags
	//disable all itnerrupt
	SPIx->CR2 &=~SPI_CR2_TXEIE;			//0->disable tx empty interrupt
	SPIx->CR2 &=~SPI_CR2_RXNEIE;		//0->disable rx not empty  interrupt
	SPIx->CR2 &=~SPI_CR2_ERRIE;			//0->disable error interrupt
	SPIx->CR1|= SPI_CR1_SPE;			//1->enable spi, 0->disable spi
}

//rest spi1
void spi1Init(uint16_t br) {
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;	//1->enable the clock, 0->disablet he clock
	
	spiInit(SPI1, br);					//reset spi

	//configure pins
#if defined(NSS1toPIN)
	NSS1toPIN();
#endif
	
#if defined(SCK1toPIN)
	SCK1toPIN();
#endif
	
#if defined(MOSI1toPIN)
	MOSI1toPIN();
#endif
	
#if defined(MISO1toPIN)
	MISO1toPIN();
#endif
}

#if defined(RCC_APB1ENR_SPI2EN)
//rest spi2
void spi2Init(uint16_t br) {
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;	//1->enable the clock, 0->disablet he clock
	
	spiInit(SPI2, br);					//reset spi

	//configure pins
#if defined(NSS2toPIN)
	NSS2toPIN();
#endif
	
#if defined(SCK2toPIN)
	SCK2toPIN();
#endif
	
#if defined(MOSI2toPIN)
	MOSI2toPIN();
#endif
	
#if defined(MISO2toPIN)
	MISO2toPIN();
#endif
}
//end spi
#endif	//RCC_APB1ENR_SPI2EN

//i2c
//generic i2c reset routine
void i2cInit(I2C_TypeDef *I2Cx) {
	I2Cx->CR1 = 0;						//default value
	I2Cx->CR2 = (F_APB1 / 1000000ul) & I2C_CR2_FREQ;		//set the baudrate
	if (I2Cx->CR2 < 2) I2Cx->CR2 = 2;
	if (I2Cx->CR2 >36) I2Cx->CR2 =36;
	I2Cx->CR1|= I2C_CR1_PE;				//1->enable i2c, 0->disable i2c
}

//reset i2c1
void i2c1Init(void) {
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;	//1->enable the clock, 0->disable the clock
	
	i2cInit(I2C1);						//reset i2c

	//configure pins - scl and sda
#if defined(SCL1toPIN)
	SCL1toPIN();
#endif	//scl1
	
#if defined(SDA1toPIN)
	SDA1toPIN();
#endif	//sdapin
}

//send multiple bytes
int16_t i2c1Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToWrite) {  
	while (i2c1Busy()) continue;				//wait for the prior transmission to end
	
	i2c1Start();								//send a start condition
	i2c1WriteAddr(DeviceAddr | I2C_CMD_WRITE);	//write device address
	i2c1Write(RegAddr);							//WRITE_REG the register address
	//write multiple bytes
	while(NumByteToWrite--) 
		i2c1Write(*pBuffer++);					//send data
	i2c1Stop();  								//generate stop condition
	i2c1Ack();									//enable ack
	return 0;
}

//read multiple bytes
int16_t i2c1Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToRead) {  
	while (i2c1Busy()) continue;				//wait for the prior transmission to end
	
	i2c1Start();								//send a start condition
	i2c1WriteAddr(DeviceAddr | I2C_CMD_WRITE);	//write device address
	i2c1Write(RegAddr);							//WRITE_REG the register address
	
	//send the start condition again
	i2c1Start();								//send a start condition
	i2c1WriteAddr(DeviceAddr | I2C_CMD_READ);	//write device address
	I2C1->SR1; I2C1->SR2;						//clear the status
	//read multiple bytes
	while(NumByteToRead) {
		if (NumByteToRead==1) {i2c1NoAck(); i2c1Stop();}
		if (i2c1Avail()) {*pBuffer++=I2C1->DR; NumByteToRead--;}
	}
	i2c1Ack();									//enable ack
	return 0;
}

#if defined(RCC_APB1ENR_I2C2EN)
//reset i2c2
void i2c2Init(void) {
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;	//1->enable the clock, 0->disable the clock
	
	i2cInit(I2C2);						//reset i2c
	
	//configure pins - scl and sda
#if defined(SCL2toPIN)
	SCL2toPIN();
#endif	//scl2
	
#if defined(SDA2toPIN)
	SDA2toPIN();
#endif	//sda pin
}

//send multiple bytes
int16_t i2c2Writes(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToWrite) {  
	while (i2c2Busy()) continue;				//wait for the prior transmission to end
	
	i2c2Start();								//send a start condition
	i2c2WriteAddr(DeviceAddr | I2C_CMD_WRITE);	//write device address
	i2c2Write(RegAddr);							//WRITE_REG the register address
	//write multiple bytes
	while(NumByteToWrite--) 
		i2c2Write(*pBuffer++);					//send data
	i2c2Stop();  								//generate stop condition
	i2c2Ack();									//enable ack
	return 0;
}

//read multiple bytes
int16_t i2c2Reads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToRead) {  
	while (i2c2Busy()) continue;				//wait for the prior transmission to end
	
	i2c2Start();								//send a start condition
	i2c2WriteAddr(DeviceAddr | I2C_CMD_WRITE);	//write device address
	i2c2Write(RegAddr);							//WRITE_REG the register address
	
	//send the start condition again
	i2c2Start();								//send a start condition
	i2c2WriteAddr(DeviceAddr | I2C_CMD_READ);	//write device address
	I2C1->SR1; I2C1->SR2;						//clear the status
	//read multiple bytes
	while(NumByteToRead) {
		if (NumByteToRead==1) {i2c2NoAck(); i2c2Stop();}
		if (i2c2Avail()) {*pBuffer++=I2C1->DR; NumByteToRead--;}
	}
	i2c2Ack();									//enable ack
	return 0;
}
//end i2c
#endif	//RCC_APB1ENR_I2C2EN

//rtcc
//global variables
static void (* _isrptr_ovf)(void)=empty_handler;			//rtc overflow flag
static void (* _isrptr_alr)(void)=empty_handler;			//rtc alarm flag
static void (* _isrptr_sec)(void)=empty_handler;			//rtc second flag

//rtc alarm isr
void RTC_IRQHandler(void) {
	//overflow isr
	if ((RTC->CRL & RTC_CRL_OWF) && (RTC->CRH & RTC_CRH_OWIE)) {							//overflow flag is set
		_isrptr_ovf();										//execute user handler
		PWR->CR      |= PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
		RTC->CRL &=~RTC_CRL_OWF;							//clear the overflow flag
		PWR->CR      &=~PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	}

	//alarm isr - can be configured through EXTI line 17 as well
	if ((RTC->CRL & RTC_CRL_ALRF) && (RTC->CRH & RTC_CRH_ALRIE)) {							//overflow flag is set
		_isrptr_alr();										//execute user handler
		PWR->CR      |= PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
		RTC->CRL &=~RTC_CRL_ALRF;							//clear the overflow flag
		PWR->CR      &=~PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	}

	//second isr
	if ((RTC->CRL & RTC_CRL_SECF) && (RTC->CRH & RTC_CRH_SECIE)) {							//overflow flag is set
		_isrptr_sec();										//execute user handler
		PWR->CR      |= PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
		RTC->CRL &=~RTC_CRL_SECF;							//clear the overflow flag
		PWR->CR      &=~PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	}
}

//reset the rtc
//ps = prescaler
//for 32768Khz, 0x7fff for 1-second
//pr = period for alarm
//alarm isr is disabled
//rtcc_clk is clock source:
//RCC_BDCR_RTCSEL_LSI, RCC_BDCR_RTCSEL_LSE and RCC_BDCR_RTCSEL_HSE (HSE/128)
void RTCInit(uint32_t rtcc_clk, uint32_t ps) {
	_isrptr_alr = _isrptr_ovf = _isrptr_sec = empty_handler;	//set default isr_ptr value

	//enable backup domain
	RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;	// enable clock for Power interface
	PWR->CR      |= PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	//reset backup domain: BDRST bit goes through a 1->0 transition
	RCC->BDCR    |= RCC_BDCR_BDRST; RCC->BDCR    &=~RCC_BDCR_BDRST;		  //1->0: reset the backup domain
	switch (rtcc_clk) {
	case RCC_BDCR_RTCSEL_NOCLOCK:		//no clock
		//enable LSI -> only if LSI is used as a clock source
		//RCC->CSR |= RCC_CSR_LSION;							//1->turn on LSI, 0->turn off LSI
		//while ((RCC->CSR & RCC_CSR_LSIRDY) == 0) continue;	//1->LSI ready, 0->LSI not ready
		RCC->BDCR = (RCC->BDCR &~RCC_BDCR_RTCSEL_HSE) | (RCC_BDCR_RTCSEL_NOCLOCK);          // set RTC clock source(LSI/LSE/HSE), enable RTC clock
		break;
	case RCC_BDCR_RTCSEL_LSI:		//lsi
		//enable LSI -> only if LSI is used as a clock source
		RCC->CSR |= RCC_CSR_LSION;							//1->turn on LSI, 0->turn off LSI
		while ((RCC->CSR & RCC_CSR_LSIRDY) == 0) continue;	//1->LSI ready, 0->LSI not ready
		RCC->BDCR = (RCC->BDCR &~RCC_BDCR_RTCSEL_HSE) | (RCC_BDCR_RTCSEL_LSI);          // set RTC clock source(LSI/LSE/HSE), enable RTC clock
		break;
	case RCC_BDCR_RTCSEL_LSE:		//lse
		//enable LSE and wait for it to be ready
		RCC->BDCR |= RCC_BDCR_LSEON;						//1->turn on LSE, 0->turn off LSE
		while ((RCC->BDCR & RCC_BDCR_LSERDY) == 0) continue;	//1->LSE ready, 0->LSE not ready
		RCC->BDCR = (RCC->BDCR &~RCC_BDCR_RTCSEL_HSE) | (RCC_BDCR_RTCSEL_LSE);          // set RTC clock source(LSI/LSE/HSE), enable RTC clock
		//RCC->BDCR|= (3<<3);									//drive strength: 0->minimum, 3->maximum. no effect on stm32f103
		break;
	case RCC_BDCR_RTCSEL_HSE:		//hse
		//enable HSE ->
		RCC->CR |= RCC_CR_HSEON;							//1->turn on LSI, 0->turn off LSI
		while ((RCC->CR & RCC_CR_HSERDY) == 0) continue;	//1->HSE ready, 0->HSE not ready
		RCC->BDCR = (RCC->BDCR &~RCC_BDCR_RTCSEL_HSE) | (RCC_BDCR_RTCSEL_HSE);          // set RTC clock source(LSI/LSE/HSE), enable RTC clock
		break;
	}
	RCC->BDCR |= (RCC_BDCR_RTCEN);          // set RTC clock source(LSI/LSE/HSE), enable RTC clock
	//RCC->BDCR    &=~RCC_BDCR_BDRST;								  //reset the backup domain

	//configure RTC
	//unlocking sequence needed for CRL, CNT and ALR registers
	//RTC -> WPR = 0xCA; RTC -> WPR = 0x53;
	RTC->CRL &= ~RTC_CRL_RSF;                  			//Clear registers Synchronized Flag
	while((RTC->CRL & RTC_CRL_RSF) == 0) continue;      //Wait for the RSF bit in RTC_CRL to be set by hardware

	while ((RTC->CRL & RTC_CRL_RTOFF) == 0) continue;	//wait for RTOFF value to 1 -> prior operations have finished
	RTC->CRL |= RTC_CRL_CNF;							//1->set CNF to enter configuration mode, 0->exit configuration mode
	//write to one or more RTC registers
	ps = ps - 1;
	RTC->PRLH = ps >> 16; RTC->PRLL = ps;				//set up the preload register
	//RTC->ALRH = alr>> 16; RTC->ALRL = alr;			//set up the alarm
	RTC->CRL &=~(RTC_CRL_OWF | RTC_CRL_ALRF | RTC_CRL_SECF);					//clear the overflow flags
	RTC->CRH &=~(RTC_CRH_OWIE | RTC_CRH_ALRIE | RTC_CRH_SECIE);					//1->enable overflow interrupt

	//locking sequency
	RTC->CRL &=~RTC_CRL_CNF;							//1->set CNF to enter configuration mode, 0->exit configuration mode
	while ((RTC->CRL & RTC_CRL_RTOFF) == 0) continue;	//wait for RTOFF value to 1 -> prior operations have finished
	//RTC->WPR=0xff;
	//NVIC_EnableIRQ(RTC_IRQn);							//enable rtc handler

	RTC->CRL &= ~RTC_CRL_RSF;                  			//Clear registers Synchronized Flag
	while((RTC->CRL & RTC_CRL_RSF) == 0) continue;      //Wait for the RSF bit in RTC_CRL to be set by hardware
	PWR->CR      &=~PWR_CR_DBP;							// disable write access to RTC, BDC registers
}

//install rtc overflow isr
void RTCOVFAttachISRF(void (*isr_ptr)(void)) {
	NVIC_DisableIRQ(RTC_IRQn);					//disable rtc handler
	_isrptr_ovf = isr_ptr;						//install user handler
	PWR->CR      |= PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	//clear the flags
	RTC->CRL &=~RTC_CRL_OWF;					//clear the overflow flags
	RTC->CRH |= RTC_CRH_OWIE;					//1->enable overflow interrupt
	PWR->CR      &=~PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	NVIC_EnableIRQ(RTC_IRQn);					//enable rtc handler
}

//install rtc alarm isr
void RTCALRAttachISR(void (*isr_ptr)(void)) {
	NVIC_DisableIRQ(RTC_IRQn);					//disable rtc handler
	_isrptr_alr = isr_ptr;						//install user handler
	PWR->CR      |= PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	//clear the flags
	RTC->CRL &=~RTC_CRL_ALRF;					//clear the overflow flags
	RTC->CRH |= RTC_CRH_ALRIE;					//1->enable overflow interrupt
	PWR->CR      &=~PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	NVIC_EnableIRQ(RTC_IRQn);					//enable rtc handler
}

//install rtc second isr
void RTCSECAttachISR(void (*isr_ptr)(void)) {
	NVIC_DisableIRQ(RTC_IRQn);					//disable rtc handler
	_isrptr_sec = isr_ptr;						//install user handler
	PWR->CR      |= PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	//clear the flags
	RTC->CRL &=~RTC_CRL_SECF;					//clear the overflow flags
	RTC->CRH |= RTC_CRH_SECIE;					//1->enable overflow interrupt
	PWR->CR      &=~PWR_CR_DBP;								//1->enable access to RTC, BDC registers, 0->disable access
	NVIC_EnableIRQ(RTC_IRQn);					//enable rtc handler
}

//set rtc counter
uint32_t RTCSetCNT(uint32_t val) {
	PWR->CR      |= PWR_CR_DBP;							// enable write access to RTC, BDC registers
	//unlocking sequence needed for CRL, CNT and ALR registers
	while ((RTC->CRL & RTC_CRL_RTOFF) == 0) continue;	//wait for RTOFF value to 1 -> prior operations have finished
	RTC->CRL |= RTC_CRL_CNF;					//1->set CNF to enter configuration mode, 0->exit configuration mode
	//write to one or more RTC registers
	RTC->CNTH = val >> 16; RTC->CNTL = val;		//set up the counter
	//RTC->ALRH = alr>> 16; RTC->ALRL = alr;	//set up the alarm
	//locking sequency
	RTC->CRL &=~RTC_CRL_CNF;					//1->set CNF to enter configuration mode, 0->exit configuration mode
	while ((RTC->CRL & RTC_CRL_RTOFF) == 0) continue;	//wait for RTOFF value to 1 -> prior operations have finished
	PWR->CR      &=~PWR_CR_DBP;							// disable access to RTC, BDC registers
	return val;
}

//read rtc counter
uint32_t RTCGetCNT(void) {
	uint32_t tmp;
	uint16_t lsb;

	RTC->CRL &= ~RTC_CRL_RSF;                  			//Clear registers Synchronized Flag
	while((RTC->CRL & RTC_CRL_RSF) == 0) continue;      //Wait for the RSF bit in RTC_CRL to be set by hardware
	do {
		tmp = RTC->CNTH;
		lsb = RTC->CNTL;
	} while (tmp != RTC->CNTH);

	return (tmp << 16) | lsb;
}

//set rtc alarm
uint32_t RTCSetALR(uint32_t val) {
	//while ((RTC->CRL & RTC_CRL_SECF)==0) continue;		//wait for sEC to be set
	PWR->CR      |= PWR_CR_DBP;							// enable write access to RTC, BDC registers
	//unlocking sequence needed for CRL, CNT and ALR registers
	while ((RTC->CRL & RTC_CRL_RTOFF) == 0) continue;	//wait for RTOFF value to 1 -> prior operations have finished
	RTC->CRL |= RTC_CRL_CNF;					//1->set CNF to enter configuration mode, 0->exit configuration mode
	//write to one or more RTC registers
	//RTC->CNTH = val >> 16; RTC->CNTL = val;	//set up the counter
	RTC->ALRH = val >> 16; RTC->ALRL = val;		//set up the alarm
	//locking sequency
	RTC->CRL &=~RTC_CRL_CNF;					//1->set CNF to enter configuration mode, 0->exit configuration mode
	while ((RTC->CRL & RTC_CRL_RTOFF) == 0) continue;	//wait for RTOFF value to 1 -> prior operations have finished
	RTC->CRL &=~RTC_CRL_RSF; while ((RTC->CRL & RTC_CRL_RSF) == 0) continue;
	PWR->CR      &=~PWR_CR_DBP;							// disable access to RTC, BDC registers
	return val;
}

//read rtc alarm
uint32_t RTCGetALR(void) {
	uint32_t tmp;
	uint16_t lsb;

	RTC->CRL &= ~RTC_CRL_RSF;                  			//Clear registers Synchronized Flag
	while((RTC->CRL & RTC_CRL_RSF) == 0) continue;      //Wait for the RSF bit in RTC_CRL to be set by hardware
	do {
		tmp = RTC->ALRH;
		lsb = RTC->ALRL;
	} while (tmp != RTC->ALRH);

	return (tmp << 16) | lsb;
}

//read rtc
time_t RTC2time(time_t *t) {
	uint32_t tmp=RTCGetCNT();


	if (t==NULL) return (tmp==0)?((time_t) -1):tmp; 			//just return seconds since epoch time if pointer is NULL
	return *t=(tmp==0)?((time_t) -1):tmp;						//change pointed value + return seconds since epoch time
}

//initialize rtc with time_t
time_t time2RTC(time_t t) {
	t=(t<946684800ul)?946684800ul:t;					//minimum time is 1/1/2000 for the hardware rtc
	RTCSetCNT(t);
	return t;
}

//read prll and prlh
uint32_t RTCGetPRL(void) {
	RTC->CRL &=~RTC_CRL_RSF; while ((RTC->CRL & RTC_CRL_RSF) == 0) continue;	//wait for RSF to be set (RTC in sync)
	return (RTC->PRLH << 16) | RTC->PRLL;
}

//read divl and divh
uint32_t RTCGetDIV(void) {
	RTC->CRL &=~RTC_CRL_RSF; while ((RTC->CRL & RTC_CRL_RSF) == 0) continue;	//wait for RSF to be set (RTC in sync)
	return (RTC->DIVH << 16) | RTC->DIVL;
}

//returns:
//0: if 1st half second
//1: if 2nd half second
uint8_t RTCHalfsec(void) {
	return (RTCGetDIV() < RTCGetPRL() / 2)?0:1;
}

//set calibration register
void RTCSetCal(uint8_t cal) {
	//PWR->CR      |= PWR_CR_DBP;							// enable write access to RTC, BDC registers
	//unlocking sequence needed for CRL, CNT and ALR registers
	BKP->RTCCR = (BKP->RTCCR &~BKP_RTCCR_CAL) | (cal & BKP_RTCCR_CAL);
	//PWR->CR      &=~PWR_CR_DBP;							// disable access to RTC, BDC registers
}
//end rtcc

//software rtc
//global defines

//global variables

volatile sRTC_TypeDef sRTC={(uint32_t)-1, 0, 0, 0};		//software RTC

//initialize software counter
void sRTCInit(void) {					//calibration from -128ppm to +128ppm, if sRTC_RATE = 1M
	//sRTC.tick_rate=sRTC_RATE;
	sRTC.time=(uint32_t) -1;						//reset counter: -1=uninitiated timer
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

//exti
//global variables
static void (* _exti0_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti1_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti2_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti3_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti4_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti5_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti6_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti7_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti8_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti9_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti10_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti11_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti12_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti13_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti14_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default
static void (* _exti15_isrptr)(void)=empty_handler;				//exti0 isrpointer pointing to empty_handler by default

//EXTI0 ISR
void EXTI0_IRQHandler(void) {
	//clear the flag
	EXTI->PR |= (1<<0);						//1->clear the flag
	//execute user isr
	_exti0_isrptr();
}

//EXTI1 ISR
void EXTI1_IRQHandler(void) {
	//clear the flag
	EXTI->PR |= (1<<1);						//1->clear the flag
	//execute user isr
	_exti1_isrptr();
}

//EXTI2 ISR
void EXTI2_IRQHandler(void) {
	//clear the flag
	EXTI->PR |= (1<<2);						//1->clear the flag
	//execute user isr
	_exti2_isrptr();
}

//EXTI3 ISR
void EXTI3_IRQHandler(void) {
	//clear the flag
	EXTI->PR |= (1<<3);						//1->clear the flag
	//execute user isr
	_exti3_isrptr();
}

//EXTI4 ISR
void EXTI4_IRQHandler(void) {
	//clear the flag
	EXTI->PR |= (1<<4);						//1->clear the flag
	//execute user isr
	_exti4_isrptr();
}

//EXTI9-5 ISR
void EXTI9_5_IRQHandler(void) {
	//clear the flag and execute user isr
	switch (EXTI->PR) {
	case (1<<5): EXTI->PR |= (1<<5); _exti5_isrptr(); break;
	case (1<<6): EXTI->PR |= (1<<6); _exti6_isrptr(); break;
	case (1<<7): EXTI->PR |= (1<<7); _exti7_isrptr(); break;
	case (1<<8): EXTI->PR |= (1<<8); _exti8_isrptr(); break;
	case (1<<9): EXTI->PR |= (1<<9); _exti9_isrptr(); break;
	}
}

//EXTI15-10 ISR
void EXTI15_10_IRQHandler(void) {
	//clear the flag and execute user isr
	switch (EXTI->PR) {
	case (1<<10): EXTI->PR |= (1<<10); _exti10_isrptr(); break;
	case (1<<11): EXTI->PR |= (1<<11); _exti11_isrptr(); break;
	case (1<<12): EXTI->PR |= (1<<12); _exti12_isrptr(); break;
	case (1<<13): EXTI->PR |= (1<<13); _exti13_isrptr(); break;
	case (1<<14): EXTI->PR |= (1<<14); _exti14_isrptr(); break;
	case (1<<15): EXTI->PR |= (1<<15); _exti15_isrptr(); break;
	}
}

//global defines
#define EXTI_FALLING	0				//trigger on falling edge
#define EXTI_RISING		1				//trigger on rising edge
#define EXTI_BOTH		2				//trigger on falling and rising edges

//global variables
//initialize the exti
//pin: one pin only
//gpio: GPIOA..GPIOG
void extiInit(PIN_TypeDef pinx, uint8_t edge) {
	uint16_t tmp=0x00;
	GPIO_TypeDef *gpio;
	uint16_t pin;
	
	gpio = GPIO_PinDef[pinx].gpio;
	pin  = GPIO_PinDef[pinx].mask;

	//enable afio
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	//enable the clock
#if 0
	switch ((uint32_t) gpio) {
#if defined(RCC_APB2ENR_IOPAEN)
		case (uint32_t) GPIOA: RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; tmp = 0x00; break;
#endif
#if defined(RCC_APB2ENR_IOPBEN)
		case (uint32_t) GPIOB: RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; tmp = 0x01; break;
#endif
#if defined(RCC_APB2ENR_IOPCEN)
		case (uint32_t) GPIOC: RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; tmp = 0x02; break;
#endif
#if defined(RCC_APB2ENR_IOPDEN)
		case (uint32_t) GPIOD: RCC->APB2ENR |= RCC_APB2ENR_IOPDEN; tmp = 0x03; break;
#endif
#if defined(RCC_APB2ENR_IOPEEN)
		case (uint32_t) GPIOE: RCC->APB2ENR |= RCC_APB2ENR_IOPEEN; tmp = 0x04; break;
#endif
#if defined(RCC_APB2ENR_IOPFEN)
		case (uint32_t) GPIOF: RCC->APB2ENR |= RCC_APB2ENR_IOPFEN; tmp = 0x05; break;
#endif
#if defined(RCC_APB2ENR_IOPGEN)
		case (uint32_t) GPIOG: RCC->APB2ENR |= RCC_APB2ENR_IOPGEN; tmp = 0x06; break;
#endif
	}
#else
#if defined(RCC_APB2ENR_IOPAEN)
		if (gpio == GPIOA) {RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; tmp = 0x00;}
#endif
#if defined(RCC_APB2ENR_IOPBEN)
		if (gpio == GPIOB) {RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; tmp = 0x01;}
#endif
#if defined(RCC_APB2ENR_IOPCEN)
		if (gpio == GPIOC) {RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; tmp = 0x02;}
#endif
#if defined(RCC_APB2ENR_IOPDEN)
		if (gpio == GPIOD) {RCC->APB2ENR |= RCC_APB2ENR_IOPDEN; tmp = 0x03;}
#endif
#if defined(RCC_APB2ENR_IOPEEN)
		if (gpio == GPIOE) {RCC->APB2ENR |= RCC_APB2ENR_IOPEEN; tmp = 0x04;}
#endif
#if defined(RCC_APB2ENR_IOPFEN)
		if (gpio == GPIOF) {RCC->APB2ENR |= RCC_APB2ENR_IOPFEN; tmp = 0x05;}
#endif
#if defined(RCC_APB2ENR_IOPGEN)
		if (gpio == GPIOG) {RCC->APB2ENR |= RCC_APB2ENR_IOPGEN; tmp = 0x06;}
#endif	//iopgen
#endif	//0

	//configure exti edges
	//1->falling/rising edge enabled, 0->falling/rising edge disabled
	switch (edge) {
		case EXTI_FALLING: 	EXTI->FTSR |= pin; EXTI->RTSR &=~pin; break;
		case EXTI_RISING: 	EXTI->FTSR &=~pin; EXTI->RTSR |= pin; break;
		case EXTI_BOTH: 	EXTI->FTSR |= pin; EXTI->RTSR |= pin; break;
	}
	//configure the port
	switch (pin) {
		case (1<< 0): AFIO->EXTICR[0] = (AFIO->EXTICR[0] &~0x000f) | ((tmp) <<  0); break;
		case (1<< 1): AFIO->EXTICR[0] = (AFIO->EXTICR[0] &~0x00f0) | ((tmp) <<  4); break;
		case (1<< 2): AFIO->EXTICR[0] = (AFIO->EXTICR[0] &~0x0f00) | ((tmp) <<  8); break;
		case (1<< 3): AFIO->EXTICR[0] = (AFIO->EXTICR[0] &~0xf000) | ((tmp) << 12); break;
		case (1<< 4): AFIO->EXTICR[1] = (AFIO->EXTICR[1] &~0x000f) | ((tmp) <<  0); break;
		case (1<< 5): AFIO->EXTICR[1] = (AFIO->EXTICR[1] &~0x00f0) | ((tmp) <<  4); break;
		case (1<< 6): AFIO->EXTICR[1] = (AFIO->EXTICR[1] &~0x0f00) | ((tmp) <<  8); break;
		case (1<< 7): AFIO->EXTICR[1] = (AFIO->EXTICR[1] &~0xf000) | ((tmp) << 12); break;
		case (1<< 8): AFIO->EXTICR[2] = (AFIO->EXTICR[2] &~0x000f) | ((tmp) <<  0); break;
		case (1<< 9): AFIO->EXTICR[2] = (AFIO->EXTICR[2] &~0x00f0) | ((tmp) <<  4); break;
		case (1<<10): AFIO->EXTICR[2] = (AFIO->EXTICR[2] &~0x0f00) | ((tmp) <<  8); break;
		case (1<<11): AFIO->EXTICR[2] = (AFIO->EXTICR[2] &~0xf000) | ((tmp) << 12); break;
		case (1<<12): AFIO->EXTICR[3] = (AFIO->EXTICR[3] &~0x000f) | ((tmp) <<  0); break;
		case (1<<13): AFIO->EXTICR[3] = (AFIO->EXTICR[3] &~0x00f0) | ((tmp) <<  4); break;
		case (1<<14): AFIO->EXTICR[3] = (AFIO->EXTICR[3] &~0x0f00) | ((tmp) <<  8); break;
		case (1<<15): AFIO->EXTICR[3] = (AFIO->EXTICR[3] &~0xf000) | ((tmp) << 12); break;
	};
}

//install user handler
void extiAttachISR(PIN_TypeDef pinx, void (*isr_ptr)(void)) {
	//GPIO_TypeDef *gpio;
	uint16_t pin;
	
	//gpio = GPIO_PinDef[pinx].gpio;
	pin  = GPIO_PinDef[pinx].mask;
	//clear the flag
	EXTI->PR |= pin;						//1->clear the flag
	//enable the interrupt
	EXTI->IMR |= pin;							//1->enable the interrupt, 0->disable the interrupt
	EXTI->EMR |= pin;							//1->enable the event trigger, 0->disable the event trigger

	//enable nvic
	switch (pin) {
		case (1<< 0): NVIC_EnableIRQ(EXTI0_IRQn); _exti0_isrptr = isr_ptr; break;
		case (1<< 1): NVIC_EnableIRQ(EXTI1_IRQn); _exti1_isrptr = isr_ptr; break;
		case (1<< 2): NVIC_EnableIRQ(EXTI2_IRQn); _exti2_isrptr = isr_ptr; break;
		case (1<< 3): NVIC_EnableIRQ(EXTI3_IRQn); _exti3_isrptr = isr_ptr; break;
		case (1<< 4): NVIC_EnableIRQ(EXTI4_IRQn); _exti4_isrptr = isr_ptr; break;
		case (1<< 5): NVIC_EnableIRQ(EXTI9_5_IRQn); _exti5_isrptr = isr_ptr; break;
		case (1<< 6): NVIC_EnableIRQ(EXTI9_5_IRQn); _exti6_isrptr = isr_ptr; break;
		case (1<< 7): NVIC_EnableIRQ(EXTI9_5_IRQn); _exti7_isrptr = isr_ptr; break;
		case (1<< 8): NVIC_EnableIRQ(EXTI9_5_IRQn); _exti8_isrptr = isr_ptr; break;
		case (1<< 9): NVIC_EnableIRQ(EXTI9_5_IRQn); _exti9_isrptr = isr_ptr; break;
		case (1<<10): NVIC_EnableIRQ(EXTI15_10_IRQn); _exti10_isrptr = isr_ptr; break;
		case (1<<11): NVIC_EnableIRQ(EXTI15_10_IRQn); _exti11_isrptr = isr_ptr; break;
		case (1<<12): NVIC_EnableIRQ(EXTI15_10_IRQn); _exti12_isrptr = isr_ptr; break;
		case (1<<13): NVIC_EnableIRQ(EXTI15_10_IRQn); _exti13_isrptr = isr_ptr; break;
		case (1<<14): NVIC_EnableIRQ(EXTI15_10_IRQn); _exti14_isrptr = isr_ptr; break;
		case (1<<15): NVIC_EnableIRQ(EXTI15_10_IRQn); _exti15_isrptr = isr_ptr; break;
	}
}

//end exti

//analog random number - generate true random number with analog read
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
//end analog random number

//circular buffer
//global defines
#define cBUFF_SIZE_MASK 	(cBUFF_SIZE-1U)		//mask

//global variables
//reset the cbuffer
void cbInit(CB_TypeDef *cbuffer) {
	cbuffer->writeIndex = cbuffer->readIndex = (uint16_t) -1;
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

//tamper backup registers
//reset the tamper to use the backup registers
void bkpInit(void) {
	//enable the clock
	RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;			//1->enable clock to pwr, 0->disable clock to pwr
	
	//set dbp bit in pwr
	bkpUnlock();								//1->enable write assess, 0->disable write access
	//not needed on f1
	RCC->BDCR |= RCC_BDCR_RTCEN;				//enable RTC clock
	bkpLock();
}

//crc
void crcInit(void) {
	RCC->AHBENR |= RCC_AHBENR_CRCEN;			//1->enable clock, 0->disable clock
	CRC->CR |= CRC_CR_RESET;					//1->reset crc, 0->no effect
}
//end crc
