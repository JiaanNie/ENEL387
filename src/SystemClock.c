#include "SystemClock.h"
void configureSystemClock(void){
	// configuare clock setting so it allow the clock to be ready enable
	// RCC-> CFGR should be 0x07050002
	RCC->CFGR =  RCC->CFGR
						| RCC_CFGR_SW_1
						| RCC_CFGR_PLLMULL3
						| RCC_CFGR_PLLSRC_PREDIV1;
	
	
	// enable the system clock doing | 0x00000080 just to ensure the bit is set not to change it
	// this line of code also just mean turning on all the clock source just for fun
	
	RCC->CR = RCC->CR 
					| RCC_CR_PLLON 
					| RCC_CR_HSEON 
					| RCC_CR_HSION 
					| RCC_CR_HSITRIM 
					|0x00000080;
	uint32_t temp =0x0; 
	
	// the while loop check if that PLLRDY bit is set, if is set that mean we are ready to
	// use the clock
	while(temp != RCC_CR_PLLRDY){
		temp = RCC-> CR & RCC_CR_PLLRDY;
	}
}
