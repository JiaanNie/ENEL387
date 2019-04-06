#include "LCD_Config.h"
void ConfigLCDPins(void){
	GPIOC->CRL &= 	~GPIO_CRL_CNF0 & 
					~GPIO_CRL_CNF1 &
					~GPIO_CRL_CNF2 &
					~GPIO_CRL_CNF3 &
					~GPIO_CRL_CNF4 &
					~GPIO_CRL_CNF5 &
					~GPIO_CRL_CNF6 &
					~GPIO_CRL_CNF7;
	
	GPIOC->CRL |=    GPIO_CRL_MODE0 |
					 GPIO_CRL_MODE1 | 
					 GPIO_CRL_MODE2 |
					 GPIO_CRL_MODE3 |
					 GPIO_CRL_MODE4 |
					 GPIO_CRL_MODE5 |
					 GPIO_CRL_MODE6 |
					 GPIO_CRL_MODE7;

	//configure port B pin 0 1 5 as output pin
	GPIOB ->CRL &=  ~GPIO_CRL_CNF0 &
					~GPIO_CRL_CNF1 &
					~GPIO_CRL_CNF5;
								
	GPIOB->CRL |=	GPIO_CRL_MODE0 |
					GPIO_CRL_MODE1 | 
					GPIO_CRL_MODE5;	
}
void LCDInit(void){
	// the following steps is to use to wake up the LCD tell it
	// to get ready to read and write and transmit data
	Delay(WAIT_50_MS);
	CMD2LCD(0x38);
	Delay(WAIT_5_MS);
	CMD2LCD(0x38);
	Delay(WAIT_5_MS);
	CMD2LCD(0x38);
	Delay(WAIT_5_MS);
	CMD2LCD(0x38);
	Delay(WAIT_5_MS);
	CMD2LCD(0x0F);
	Delay(WAIT_5_MS);
	CMD2LCD(0x01);
	Delay(WAIT_5_MS);
	CMD2LCD(0x06);
	Delay(WAIT_5_MS);	
	// need to learn how to find out what 90000 equal in time (ms)
	// look at page 46 to follow the steps
}

void CMD2LCD(uint8_t data){
	GPIOB->BSRR = LCD_CM_ENA;
	GPIOC->ODR &=0xff00;
	GPIOC->ODR |= data;
	Delay(8000);
	GPIOB ->BSRR = LCD_CM_DIS;
	Delay(80000);
}
//send command to lcd

void DAT2LCD(uint8_t data){
	GPIOB->BSRR = LCD_DM_ENA;
	GPIOC->ODR &=0xff00;
	GPIOC->ODR |= data;
	Delay(WAIT_5_MS);
	GPIOB ->BSRR = LCD_DM_DIS;
	Delay(WAIT_50_MS);
}
//send data so LCD can display it on the screen
void WriteToLCD(int lineNumber, char inputString[]){
	
	uint8_t position;
	uint8_t command;
	if(lineNumber ==2){
		position = LCD_LN2;
		command = LCD_LN2;
	}
	else{
		position = LCD_LN1;
		command = LCD_LN1;
	}
	int i = 0;
	CMD2LCD(command);
	Delay(WAIT_5_MS);	
	while(inputString[i] != '\0'){
		DAT2LCD(inputString[i]);
		i+=1;
		position +=0x1;
	}
}
// when function call users requires which line on the lcd should the program write to and what is the string

void ClearLCDLine(int lineNumeber){
	char emptyLine[] = "                ";
	if(lineNumeber ==2){
		WriteToLCD(2, emptyLine);
		CMD2LCD(LCD_LN2);
	}
	else{
		WriteToLCD(1, emptyLine);
		CMD2LCD(LCD_LN1);
	}
}
