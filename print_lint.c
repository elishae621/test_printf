#include "main.h"

/**
 *helper_print_lint - helper_print_lint
 *@n: int n
 *@sum: sum of bytes written
 */
void helper_print_lint(long int n, int *sum)
{
	long int num = n;
	char tmp;

	if (num > 9)
	{

		helper_print_lint(num / 10, sum);
	}

	tmp = num % 10 + '0';
	*sum += _putchar(tmp);
}

/**
 *print_lint - print_lint
 *@n: int n
 *@sum: sum of bytes written
 *@flag: flag
 */
void print_lint(long int n, int *sum, char *flag)
{
	long int num = n;
	char tmp;

	if (n < 0)
	{
		*sum += _putchar('-');
		num = -num;
	}
	else
	{
		if (_found_in(flag, '+'))
			*sum += _putchar('+');
		if (_found_in(flag, ' '))
			*sum += _putchar(' ');
		if (_found_in(flag, '0'))
			*sum += _putchar('0');
	}
	if (num > 9)
	{

		helper_print_lint(num / 10, sum);
	}

	tmp = num % 10 + '0';
	*sum += _putchar(tmp);
}
