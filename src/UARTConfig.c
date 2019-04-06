#include "UARTConfig.h"

void UART_Init(void){
	// enable AFIO 
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	
	
	// need to config to AFIO input and output
	// config PB 10 for sending data
	// this will set PB10 with the mode 11 which is  output mode max speed at 50 MHz from page 110 
	GPIOB->CRH |= GPIO_CRH_MODE10;
	
	//this will SET PB10 with config 00  at pin 10 without change other pins
	GPIOB->CRH |= GPIO_CRH_CNF10_1;
	GPIOB->CRH &= (~GPIO_CRH_CNF10_0);
	
	// config PB 11 for recieving data
	GPIOB->CRH &= (~GPIO_CRH_MODE11);
	GPIOB->CRH |= GPIO_CRH_MODE11_0;
	GPIOB->CRH &= (~GPIO_CRH_MODE11_1);
	
	USART3->CR1 |= USART_CR1_UE;
	USART3->BRR = 0x9C4;
	USART3->CR1 |= USART_CR1_TE | USART_CR1_RE;
}


void UART2_Init(void){
	// enable AFIO 
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	
	
	// need to config to AFIO input and output
	// config PA 2 for sending data
	// this will set PA 2 with the mode 11 which is  output mode max speed at 50 MHz from page 110 
	GPIOA->CRL |= GPIO_CRL_MODE2;
	
	//this will SET PA 2 with config 00  at pin 10 without change other pins
	GPIOA->CRL |= GPIO_CRL_CNF2_1;
	GPIOA->CRL &= (~GPIO_CRL_CNF2_0);
	
	// config PA 3 for recieving data
	GPIOA->CRL &= (~GPIO_CRL_MODE3);
	GPIOA->CRL |= GPIO_CRL_MODE3_0;
	GPIOA->CRL &= (~GPIO_CRL_MODE3_1);
	
	USART2->CR1 |= USART_CR1_UE;
	USART2->BRR = 0x9C4;
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;
}

void UART2_SendData(char byte){
	USART2->DR = byte;

}
char  UART2_ReceiveData(void){
	char data = USART2->DR;
	return data;
}

void UART_SendData(char byte){
	USART3->DR = byte;

}
char  UART_ReceiveData(void){
	char data = USART3->DR;
	return data;
}
