#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int in(char *arr, int len, const char *target)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (strncmp(&arr[i], target, strlen(target)) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int _printf(const char *format, ...)
{
    va_list valist;
    int *sum, width = 0, precision = 0;
    char *flags, specifier;
    char flag;

    flags = malloc(sizeof(char) * 6);

    flags = "-+ #0";

    sum = malloc(sizeof(int));
    *sum = 0;

    va_start(valist, format);

    while (format != NULL && *format != '\0')
    {
        if (*format == '%')
        {
            format++;
            // %[flags][width][.precision][length]specifier
            if (in(flags, 5, format))
            {
                flag = *format;
            }
            else if (isdigit(*format))
            {
                width = *format;
            }
            else if (*format == '.')
            {
                format++;
                precision = *format;
            }
            else
            {
                specifier = *format;
            }
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
            printf("flag: %c", flag);
            printf("precision: %d", precision);
            printf("width: %d", width);
            printf("specifier: %c", specifier);
        }
        else
        {
            *sum += _putchar(*format);
        }
        format++;
    }
    return (*sum);
}
