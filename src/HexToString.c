#include "HexToString.h"
char ParseHexToASCII(uint8_t value){
	char result;
	if(value < 0x0a){
		result = value + 0x30; 
		// if value is between 0 to 9 we add 0x30 so it is the ASCII repersentation of '0' to '9' 
	}
	else{
		result = value + 0x37;
		// if value is between 0xA to 0xF we add 0x37 so it is the ASCII repersentation of 'A' to 'F'
	}
	return result;
	
}

// convert a 4 bit hex value to it ASCII repersentation
char* ConvertHexToString(uint32_t value){
	static char resultString[10] = "0x";
	int appendingPosition = 2;
	int shiftBits = 4;
	int numberOfShift = 7;
	uint8_t mask = 0xf;
	char ASCII;
	while(numberOfShift >=0){
		int currentShiftBits = shiftBits * numberOfShift;
		uint8_t currentByte = value >> currentShiftBits;
		currentByte&=mask;
		ASCII = ParseHexToASCII(currentByte);
		resultString[appendingPosition] = ASCII;
		appendingPosition +=1;
		numberOfShift -=1;
	}
	return resultString;
}
// limitation of this fuction is that currently only able convert String that is 10 character long 
//not as dynamic as i wanted to be at the moment
