#include "main.h"

void helper_print_number(int n, int *sum)
{
    int num = n;
    char tmp;

    if (num > 9)
    {

        helper_print_number(num / 10, sum);
    }

    tmp = num % 10 + '0';
    *sum += _putchar(tmp);
}

void print_number(int n, int *sum, char flag)
{
    int num = n;
    char tmp;

    if (n < 0)
    {
        *sum += _putchar('-');
        num = -num;
    }
    else
    {
        if (flag == '+')
            *sum += _putchar('+');
    }
    if (num > 9)
    {

        helper_print_number(num / 10, sum);
    }

    tmp = num % 10 + '0';
    *sum += _putchar(tmp);
}
