#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
int _strlen(const char *s);
int _putchar(char c);
char *int_to_str(int n);
int int_len(int n);

int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_int(va_list ap);
int print_decimal(va_list ap);

unsigned int num_bytes(unsigned int n, int base);
char get_rem_as_char(int [], char [], int rem, int size);
char *int_to(unsigned int n, int base);

int print_binary(va_list ap);
int print_unsigned(va_list ap);
int print_octal(va_list ap);
int print_hex(va_list ap);
int print_HEX(va_list ap);

#endif /* MAIN_H */
