#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *print_reverse_string - reverses the content of an string of integers
 *@str: pointer integer
 *@sum: sum printed
 */
void print_reverse_string(char *str, int *sum)
{
    char *nstr;
    int lengthOfArray = 0;
    int i = 0;

    nstr = malloc(sizeof(str));

    strcpy(nstr, str);

    while (str[i] != '\0')
    {
        lengthOfArray++;
        i++;
    }

    for (i = 0; i < lengthOfArray / 2; i++)
    {
        char temp = *(nstr + i);
        *(nstr + i) = *(nstr + (lengthOfArray - i - 1));
        *(nstr + (lengthOfArray - i - 1)) = temp;
    }
    *sum += _putstring(nstr);
}
