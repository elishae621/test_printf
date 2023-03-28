#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _putstring(char *s);
void print_hex_smallcase(va_list valist, int *sum);
void print_hex_uppercase(va_list valist, int *sum);
void print_hex(long decimalNumber, int *sum);
void print_number(int n, int *sum);
void print_octal(int num, int *sum);
void print_binary(va_list valist, int *sum);
void print_S(char *string, int *sum);
void print_rot13(char *str, int *sum);

#endif /* MAIN_H */
