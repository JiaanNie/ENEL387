#include "IntToString.h"

char ParseIntToASCII(int digit){
	return digit + '0';
}
char* ConvertIntToString(int value){
	static char resultString[10] = "";
	int appendingPosition = 0;
	char ASCII;
	int numberOfConversion = 0;
	if(value < 10){
		numberOfConversion = 1;
	}
	else if(value < 100){
		numberOfConversion = 2;
	}
	else{
		numberOfConversion = 3;  
	}
	while(numberOfConversion > 0){
		int placeholder = value;
		int divisor;
		int modulo = 1;
		for(int i = 0; i < numberOfConversion; i++){
			modulo = modulo * 10;
		}
		divisor =  modulo /10;
		placeholder = (placeholder % modulo) / divisor;
		ASCII = ParseIntToASCII(placeholder);
		resultString[appendingPosition] = ASCII;
		appendingPosition+= 1;
		numberOfConversion -=1;
	}
	return resultString;
}
