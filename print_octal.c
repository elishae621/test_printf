#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 *print_octal - prints octal
 *@num: int num
 *sum: int sum
 */
void print_octal(unsigned int n, int *sum)
{
    char buffer[1024];
    unsigned int num = n;
    unsigned long int i = 0;

    if (num == 0)
    {
        buffer[i++] = '0';
    }
    else
    {
        while (num != 0 && i < sizeof(buffer))
        {
            buffer[i++] = (num % 8) + '0';
            num /= 8;
        }
    }

    while (i > 0 && *sum < INT_MAX)
    {
        *sum += _putchar(buffer[--i]);
    }
}
