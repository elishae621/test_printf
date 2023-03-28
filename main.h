#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
int _putstring(char *s);
void print_hex_smallcase(long decimalNumber, int *sum);
void print_hex_uppercase(long decimalNumber, int *sum);
void print_hex(long decimalNumber, int *sum);
void print_number(int n, int *sum, char flag);
void print_unsigned_number(unsigned int n, int *sum);
void print_octal(int num, int *sum);
void print_binary(int num, int *sum);
void print_S(char *string, int *sum);
void print_reverse_string(char *str, int *sum);
void print_rot13(char *str, int *sum);

#endif /* MAIN_H */
