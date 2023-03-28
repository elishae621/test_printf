#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 *print_oct - prints octal
 *@n: long num
 *@sum: int sum
 *@flag: flag
 */
void print_loct(unsigned long n, int *sum, char *flag)
{
	char buffer[1024];
	unsigned long num = n;
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
