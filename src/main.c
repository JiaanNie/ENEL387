#include "Robot.h"

int main(void){
	//Robot_init();
	configureSystemClock();
	EnableGPIOx("abcd");
	ConfigLCDPins();
	LCDInit();
	UART_Init();
	ClearLCDLine(1);
	WriteToLCD(1, "DiscordBot: ");
	PWM_Init();
	PWM2_Init();
	ClearLCDLine(2);
	char sdata = '0';
	char data;
	char data2;
	char rdata[10];
	int i  = 0;
	WriteToLCD(2, "wilson");
	while(1){
		uint32_t isReadySend = (USART3->SR &USART_SR_TXE) >>7;
		uint32_t isReadyReceive = (USART3->SR & USART_SR_RXNE) >> 5;
		if (isReadySend == 1){
			UART_SendData(sdata);
			sdata += 1;
		}
		if(isReadyReceive == 1){
			data2 = UART_ReceiveData();
			rdata[i] = data2;
			WriteToLCD(2, rdata);
			i++;
		}
	}
}
