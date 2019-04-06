#include "Robot.h"

void Robot_init(void){
	configureSystemClock();
	EnableGPIOx("abcd");
	ConfigLCDPins();
	LCDInit();
	UART_Init();
	ClearLCDLine(1);
	WriteToLCD(1, "DiscordBot: ");
	PWM_Init();
	PWM2_Init();
}

void Move_forward(void){
	//2ms that mean  4
	int rotation = 4;
	Update_PA8_PWM(rotation);
	Update_PA9_PWM(2);
	Delay(30000000);

}

void Move_back(void){
	//1ms that mean  2
	int rotation = 2;
	Update_PA8_PWM(rotation);
	Update_PA9_PWM(4);
	Delay(30000000);
}	
void Move_left(void){


}
void Move_right(void){


}
void Stop(void){
	//1.5ms that mean 3 
	int rotation = 3;
	Update_PA8_PWM(rotation);
	Update_PA9_PWM(rotation);
	Delay(30000000);
	// this delay is about 5 to 6 second

}
void Robot_routine(void){
	

}
