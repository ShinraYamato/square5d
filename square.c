/**
 * @file square.c
 * @author Pierre Buffo @ShinraYamato
 * @brief A simple program testing if the square from a given values is composed of at least 5 differents digits
 * @version 0.1
 * @date 2022-08-15
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define HELPTEXT "Usage: square NUMBER \n NUMER: must be between -65535 and 65535\n"
#define DIFFCHARNUMBER 5

/*
 * Function:  countUniqueChar 
 * --------------------
 * count unique digits (0-9) in a string
 *
 * number: source number
 *
 * returns: number of unique char
 */
uint8_t countUniqueChar(char *number){
	uint8_t ASCIIChars[10] = {0}; //0-9
	uint8_t uniqueChars = 0;
	for (uint8_t i = 0; i < strlen(number); i++){
		ASCIIChars[number[i]-48] += 1; //0 has position 48 in ASCII table
	}
	for (uint8_t i = 0; i < 10; i++){
		if (ASCIIChars[i])
			uniqueChars++;
	}
	return uniqueChars;
}

int main(int argc, char *argv[]) {
	//check if there's an argument
	if (argc < 2){
		printf(HELPTEXT);
		return -1;
	}
	
	//check if arg is a valid number 
	int number = atoi(argv[1]);
	if (!number){
		printf(HELPTEXT);
		return -1;
	}
	
	//check for a potential overflow after square operation
	uint32_t square = number * number;
	if (abs(number) != (int) sqrt(square)) {
		printf(HELPTEXT);
		return -1;
	}
	char squareString[10] = {0}; //4,294,967,295 max value in uint32_t
	sprintf(squareString, "%u", square);
	
	//check for 5 different digits
	uint8_t uniqueChars = countUniqueChar(squareString);
	if (uniqueChars >= DIFFCHARNUMBER)
		printf("OK !\n");
	else
		printf("FAIL !\n");
	printf("DETAILS: Source number : %d - Square : %u - Unique chars: %u\n", number, square, uniqueChars);
	return 0;
}