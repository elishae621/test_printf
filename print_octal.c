#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 *print_octal - prints octal
 *@n: int num
 *@sum: int sum
 *@flag: flag
 */
void print_octal(unsigned int n, int *sum, char *flag)
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
		if (_found_in(flag, '#'))
			*sum += _putchar('0');
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
