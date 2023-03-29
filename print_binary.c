#include "main.h"
#include <stdlib.h>

/**
 *print_binary - prints binary
 *@num: int num
 *@sum: sum of bytes written
 */
void print_binary(int num, int *sum)
{
	int i, n;
	int *a;

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
