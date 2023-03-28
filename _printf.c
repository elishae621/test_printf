#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...)
{
    va_list valist;
    int *sum;
    sum = malloc(sizeof(int));
    *sum = 0;

    va_start(valist, format);

    while (format != NULL && *format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
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
                print_number(va_arg(valist, int), sum);
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
                print_octal(va_arg(valist, int), sum);
                break;

            case 'x':
                print_hex_smallcase(va_arg(valist, long), sum);
                break;

            case 'X':
                print_hex_uppercase(va_arg(valist, long), sum);
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
        else
        {
            *sum += _putchar(*format);
        }
        format++;
    }
    return (*sum);
}
