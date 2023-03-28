#include "main.h"

void print_unsigned_number(unsigned int n, int *sum)
{
    unsigned int num = n;
    char tmp;

    if (n < 0)
    {
        *sum += _putchar('-');
        num = -num;
    }
    if (num > 9)
    {

        print_number(num / 10, sum);
    }

    tmp = num % 10 + '0';
    *sum += _putchar(tmp);
}
