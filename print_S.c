#include "main.h"

/**
 *print_octal - prints octal
 *@num: int num
 *sum: int sum
 */
void print_S(char *string, int *sum)
{
    while (*string != '\0')
    {
        if (*string <= 32 || *string >= 127)
        {
            _putstring("\\x");
            print_hex(*string, sum);
        }
        else
        {
            *sum += _putchar(*string);
        }
        string++;
    }
}
