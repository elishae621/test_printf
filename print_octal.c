#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 *print_octal - prints octal
 *@num: int num
 *sum: int sum
 */
void print_octal(int num, int *sum)
{
    char *octal_str;
    int index = 0, i, length;

    octal_str = malloc(sizeof(char) * 32);

    // Convert the integer to an octal string
    do
    {
        octal_str[index++] = (num % 8) + '0';
        num /= 8;
    } while (num > 0);

    // Reverse the string
    length = strlen(octal_str);
    for (i = 0; i < length / 2; i++)
    {
        char temp = octal_str[i];
        octal_str[i] = octal_str[length - i - 1];
        octal_str[length - i - 1] = temp;
    }

    *sum += _putstring(octal_str);
}
