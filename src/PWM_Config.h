#include "stdint.h"
#include "stm32f10x.h"
#include "Delay.h"
void PWM_Init(void);
void PWM_Update(uint32_t percentage_duty_cycle, char sign);
void PWM2_Init(void);
void Update_PA8_PWM(uint32_t value);
void Update_PA9_PWM(uint32_t value);
