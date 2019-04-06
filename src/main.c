#include "Robot.h"
void processCommand(int command);

int main(void){
	configureSystemClock();
	EnableGPIOx("abcd");
	ConfigLCDPins();
	LCDInit();
	UART2_Init();
	ClearLCDLine(1);
	WriteToLCD(1, "DiscordBot: ");
	PWM_Init();
	PWM2_Init();
	ClearLCDLine(2);
	char sdata = '0';
	char data2;
	char message[16];
	int command;
	int i  = 0;
	char temp[2];
	for (int i =0; i < 16; i++){
		message[i] = '\0';
	}
	while(1){
		uint32_t isReadySend = (USART2->SR &USART_SR_TXE) >>7;
		uint32_t isReadyReceive = (USART2->SR & USART_SR_RXNE) >> 5;
		if(isReadyReceive == 1){
			data2 = UART2_ReceiveData();
			if(i  == 0){
				// that mean this is a predefine command
				command = data2 - '0';
				i++;
			}
			else {
				message[i-1] = data2;
				temp[0] = data2;
				i++;
				WriteToLCD(2, message);
				if (data2 == '!'){
					i = 0;
					for (int i =0; i < 16; i++){
						message[i] = '\0';
					}
					
					
				}
			}
		}
	}
}

void processCommand(int command){
	switch (command){
		case 1:
			// move up
			break;
		case 2:
			// move down
			break;
		case 3:
			// move left
			break;
		case 4:
			// move right
			break;
	
	
	}


}
