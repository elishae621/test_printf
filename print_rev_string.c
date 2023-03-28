#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *print_reverse_string - reverses the content of an string of integers
 *@str: pointer integer
 *@sum: sum printed
 */
void print_reverse_string(char *str, int *sum)
{
    int i, j, t, len;
    len = strlen(str);
    for (i = 0, j = (len - 1); i < j; i++, j--)
    {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    *sum += _putstring(str);
}
