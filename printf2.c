#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 *print_xhex - prints hex in lowercase
 *@valist: valist
 */
void print_xhex(va_list valist, int *sum)
{
    long decimalNumber = va_arg(valist, long);
    long int remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];

    quotient = decimalNumber;
    while (quotient != 0)
    {
        temp = quotient % 16;
        // To convert integer into character
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 87;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }
    for (j = i - 1; j > 0; j--)
        *sum += write(1, &hexadecimalNumber[j], 1);
}

/**
 *print_Xhex - prints hex in uppercase
 *@valist: valist
 */
void print_Xhex(va_list valist, int *sum)
{
    long decimalNumber = va_arg(valist, long);
    long int remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];

    quotient = decimalNumber;
    while (quotient != 0)
    {
        temp = quotient % 16;
        // To convert integer into character
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }
    for (j = i - 1; j > 0; j--)
        *sum += write(1, &hexadecimalNumber[j], 1);
}

/**
 *print_hex - prints hex
 *@valist: valist
 */
void print_hex(long decimalNumber, int *sum)
{
    long int remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[3];

    quotient = decimalNumber;
    while (quotient != 0)
    {
        temp = quotient % 16;
        // To convert integer into character
        if (temp < 10)
            temp = temp + 48;
        else
        {
            temp = temp + 55;
        }
        hexadecimalNumber[i++] = temp;
        hexadecimalNumber[i++] = 48;

        quotient = quotient / 16;
    }
    for (j = i - 1; j > 0; j--)
        *sum += write(1, &hexadecimalNumber[j], 1);
}

void print_octal(int num, int *sum)
{
    char octal_str[32] = "";
    int index = 0;

    // Convert the integer to an octal string
    do
    {
        octal_str[index++] = (num % 8) + '0';
        num /= 8;
    } while (num > 0);

    // Reverse the string
    int length = strlen(octal_str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = octal_str[i];
        octal_str[i] = octal_str[length - i - 1];
        octal_str[length - i - 1] = temp;
    }

    // Print the string
    char *str = octal_str;
    while (*str != '\0')
    {
        *sum += _putchar(*str);
        str++;
    }
}

void print_number(unsigned int n, int *sum)
{
    unsigned int num = n;
    char tmp;

    if (n < 0)
    {
        *sum += write(1, "-", 1);
        num = -num;
    }
    if (num > 9)
    {

        print_number(num / 10, sum);
    }

    tmp = num % 10 + '0';
    *sum += write(1, &tmp, 1);
}

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
                char *str = va_arg(valist, char *);
                char buffer[1024];

                strcpy(buffer, str);

                // Get the length of the buffer
                int buffer_length = strlen(buffer);

                write(1, str, buffer_length);
                break;
            case 'S':
                char *string = va_arg(valist, char *);
                while (*string != '\0')
                {
                    if (*string <= 32 || *str >= 127)
                    {
                        write(1, "\\x", 2);
                        print_hex(*string, sum);
                    }
                    else
                    {
                        *sum += _putchar(*string);
                    }
                    string++;
                }
                break;
            case 'd':
            case 'i':
            case 'u':
                print_number(va_arg(valist, int), sum);
                break;
            case '%':
                *sum += _putchar('%');
                break;
            case 'b':
                int num = va_arg(valist, int), i, n;
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
                break;

            case 'o':
                int val = va_arg(valist, int);
                print_octal(val, sum);
                break;

            case 'x':
                print_xhex(valist, sum);
                break;

            case 'X':
                print_Xhex(valist, sum);
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

int main()
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
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("%S\n", "Best\nSchool");
    // _printf("Address:[%p]\n", addr);
    // printf("Address:[%p]\n", addr);
    // len = _printf("Percent:[%%]\n");
    // len2 = printf("Percent:[%%]\n");
    // _printf("Len:[%d]\n", len);
    // printf("Len:[%d]\n", len2);
    // _printf("Unknown:[%r]\n");
    // printf("Unknown:[%r]\n");

    return 0;
}