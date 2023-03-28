#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 *print_binary - prints octal
 *@num: int num
 *sum: int sum
 */
void print_binary(va_list valist, int *sum)
{
    int num = 0, i, n;
    int *a;

    num = va_arg(valist, int);
    a = malloc(20 * sizeof(int));

    for (i = 0; num >= 0; i++)
    {
        if (num == 0)
        {
            *(a + i) = num;
            break;
        }
        n = num % 2;
        num /= 2;
        n += '0';
        *(a + i) = n;
    }
    while (i >= 0)
    {
        *sum += _putchar(*(a + i));
        i--;
    }
}
