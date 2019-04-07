#include "PWM_Config.h"
void PWM_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN | RCC_APB2ENR_AFIOEN;
  // Write a 0xB ( 1011b ) into the configuration and mode bits for PA8 (AFIO)
  GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0 ;
  GPIOA->CRH &= ~GPIO_CRH_CNF8_0 ;
	
	TIM1->CR1 |= TIM_CR1_CEN;
	TIM1->CR2 |= TIM_CR2_OIS1;
	TIM1->EGR |= TIM_EGR_UG;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE| TIM_CCMR1_OC1FE ;
	TIM1->CCER |= TIM_CCER_CC1E;
	TIM1->PSC = 12999;
	TIM1->CCR1 = 0;
	TIM1->ARR = 39;
	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI;
	TIM1->CR1 |= TIM_CR1_CEN;


	
}

void PWM2_Init(void){
	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0 ;
	GPIOA->CRH &= ~GPIO_CRH_CNF9_0 ;
	TIM1->CR1|= TIM_CR1_CEN;
	TIM1->CR2 |= TIM_CR2_OIS2;
	TIM1->EGR |= TIM_EGR_UG;
	TIM1->CCMR1 |=TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2|TIM_CCMR1_OC1PE| TIM_CCMR1_OC2FE ;
	TIM1->CCER |= TIM_CCER_CC2E;
	TIM1->PSC = 12999;
	TIM1->CCR2 = 0;
	TIM1->ARR = 39;
	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI;
	TIM1->CR1 |= TIM_CR1_CEN;


	
}


void Update_PA8_PWM(uint32_t  rotation){
	TIM1->CCR1 = rotation;
	Delay(40000);
	TIM1->EGR |= TIM_EGR_UG;
}
void Update_PA9_PWM(uint32_t rotation){
	TIM1->CCR2 = rotation;
	Delay(40000);
	TIM1->EGR |= TIM_EGR_UG;
}



void PWM_Update(uint32_t percentage_duty_cycle,  char  sign){
	
	uint32_t currentPeriod = TIM1->CCR1;
	uint32_t newPeriod;
	if(sign == '+'){
		// increase pwm
		if (currentPeriod < 10 && currentPeriod > 0){
			newPeriod = currentPeriod + percentage_duty_cycle;
			TIM1->CCR1 =  newPeriod;
		}
		else{
			TIM1->CCR1 =  5;
		}
		
	}
	else{
		// decrease pwm
		if (currentPeriod < 10 && currentPeriod > 0){
			newPeriod = currentPeriod - percentage_duty_cycle;
			TIM1->CCR1 =  newPeriod;
		}
		else{
			TIM1->CCR1 =  5;
		}
	}
	Delay(40000);
	TIM1->EGR |= TIM_EGR_UG;
}
