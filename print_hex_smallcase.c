#include "main.h"

/**
 *print_hex_smallcase - prints hex in lowercase
 *@valist: valist
 */
void print_hex_smallcase(long decimalNumber, int *sum)
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
            temp = temp + 87;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }
    for (j = i - 1; j > 0; j--)
        *sum += _putchar(hexadecimalNumber[j]);
}
