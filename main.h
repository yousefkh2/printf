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
int int_len(long int n);

int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_int(va_list ap);
int print_decimal(va_list ap);

unsigned int num_bytes(unsigned long int n, int base);
char get_rem_as_char(int [], char [], int rem, int size);
char *int_to(unsigned long int n, int base);

int print_binary(va_list ap);
int print_unsigned_int(va_list ap);
int print_octal(va_list ap);
int print_hex(va_list ap);
int print_HEX(va_list ap);
int print_reverse(va_list ap);
int print_special(va_list ap);
int print_address(va_list ap);

char get_13rot(char c);
int print_13rot(va_list);

#endif /* MAIN_H */
