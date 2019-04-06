#define LCD_CM_ENA 0x00210002
#define LCD_CM_DIS 0x00230000
#define LCD_DM_ENA 0x00200003
#define LCD_DM_DIS 0x00220001
#define LCD_LN1 	 0x80  // line 1 in the lcd first character
#define LCD_LN2		 0xC0 // line 2 in the lcd first character
#define WAIT_50_MS ((uint32_t)90000)
#define WAIT_5_MS  ((uint32_t)9000)
#include "stm32f10x.h"
#include "Delay.h"
//configure data bus pin from DB0 to DB 7 as output pins
void ConfigLCDPins(void);
void LCDInit(void);
void CMD2LCD(uint8_t data);
void DAT2LCD(uint8_t data);
void WriteToLCD(int lineNumber, char inputString[]);
void ClearLCDLine(int lineNumeber);
