#include "main.h"

void print_number(int n, int *sum)
{
    int num = n;
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
