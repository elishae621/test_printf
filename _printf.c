#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void _exec_specifier(char *s, va_list valist, int *sum, char *flag)
{
	char specifier = s;

	switch (specifier)
	{
	case 'c':
		*sum += _putchar(va_arg(valist, int));
		break;
	case 's':
		*sum += _putstring(va_arg(valist, char *));
		break;
	case 'S':
		print_S(va_arg(valist, char *), sum);
		break;
	case 'd':
	case 'i':
		print_number(va_arg(valist, int), sum, flag);
		break;
	case 'u':
		print_unsigned_number(va_arg(valist, int), sum);
		break;
	case '%':
		*sum += _putchar('%');
		break;
	case 'b':
		print_binary(va_arg(valist, int), sum);
		break;
	case 'o':
		print_octal(va_arg(valist, unsigned int), sum, flag);
		break;
	case 'x':
		print_hex_smallcase(va_arg(valist, long), sum, flag);
		break;
	case 'X':
		print_hex_uppercase(va_arg(valist, long), sum, flag);
		break;
	case 'R':
		print_rot13(va_arg(valist, char *), sum);
		break;
	case 'r':
		print_reverse_string(va_arg(valist, char *), sum);
		break;
	default:
		break;
	}
}
/**
 * _printf: prints a string
 * @format: printing format
 * Return: no of bytes written
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int *sum, no_of_flags = 0;
	char *flags, specifier;
	char *flag;

	flags = malloc(sizeof(char) * 6);
	flag = malloc(sizeof(char) * 6);

	flags = "-+ #0";

	sum = malloc(sizeof(int));
	*sum = 0;

	va_start(valist, format);

	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			/* %[flags][width][.precision][length]specifier */
			if (_found_in(flags, *format))
			{
				*(flag + no_of_flags++) = *format;
				format++;
				specifier = *format;
			}
			/* if (isdigit(*format))
			 {
				 width = *format;
				 format++;
				 specifier = *format;
			 }
			 if (*format == '.')
			 {
				 format++;
				 precision = *format;
				 format++;
				 specifier = *format;
			 }*/
			specifier = *format;
			_exec_specifier(specifier, valist, sum, flag);
		}
		else
		{
			*sum += _putchar(*format);
		}
		format++;
	}
	return (*sum);
}
