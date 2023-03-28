#include "main.h"
/**
 *print_hex - prints hex
 *@decimalNumber: decimalNumber
 *@sum: sum of bytes written
 */
void print_hex(long decimalNumber, int *sum)
{
	long int quotient;
	int i = 1, j, temp;
	char hexadecimalNumber[3];

	quotient = decimalNumber;
	while (quotient != 0)
	{
		temp = quotient % 16;
		// To convert integer into character
		if (temp < 10)
			temp = temp + 48;
		else
		{
			temp = temp + 55;
		}
		hexadecimalNumber[i++] = temp;
		hexadecimalNumber[i++] = 48;

		quotient = quotient / 16;
	}
	for (j = i - 1; j > 0; j--)
		*sum += _putchar(hexadecimalNumber[j]);
}
