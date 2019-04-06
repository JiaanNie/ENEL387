#include "EnableGPIOx.h"
void EnableGPIOx(char ports[]) {
	int stringLength = strlen(ports);
	for (int i = 0; i < stringLength; i++) {
		switch (ports[i]) {
		case 'A':
		case 'a':
			RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
			break;
		case 'B':
		case 'b':
			RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
			break;
		case 'C':
		case 'c':
			RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
			break;
		case 'D':
		case 'd':
			RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
			break;
		case 'E':
		case 'e':
			RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
			break;
		default:
			break;
		}
	}
}
