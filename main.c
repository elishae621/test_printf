#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - check code
 * Return: On success 1.
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%i]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Binary: [%b]\n", 98);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%#x, %#X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%#x, %#X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("%S\n", "Best\nSchool");
	_printf("%R\n", "Encrypted string");
	_printf("%r\n", "A long string");
	_printf("Positive:[%+i]\n", 762534);
	printf("Positive:[%+d]\n", 762534);
	_printf("Positive:[% i]\n", 762534);
	printf("Positive:[% d]\n", 762534);
	_printf("Positive:[%0i]\n", 762534);
	printf("Positive:[%0d]\n", 762534);
	_printf("Positive:[%#i]\n", 762534);
	printf("Positive:[%f]\n", 762534.3);
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);

	return (0);
}
