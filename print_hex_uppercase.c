#include "main.h"

/**
 *print_hex_uppercase - prints hex in uppercase
 *@decimalNumber: decimalNumber
 *@sum: sum of bytes written
 *@flag: flag
 */
void print_hex_uppercase(long decimalNumber, int *sum, char *flag)
{
	long int quotient;
	int i = 1, j, temp;
	char hexadecimalNumber[100];

	quotient = decimalNumber;
	while (quotient != 0)
	{
		temp = quotient % 16;
		// To convert integer into character
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexadecimalNumber[i++] = temp;
		quotient = quotient / 16;
	}
	if (decimalNumber != 0 && _found_in(flag, '#'))
		*sum += _putstring("0X");
	for (j = i - 1; j > 0; j--)
		*sum += _putchar(hexadecimalNumber[j]);
}
