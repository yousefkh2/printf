#ifndef MAIN_H
#define MAIN_H

<<<<<<< HEAD
=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
>>>>>>> f2c4ed52e31c6f01d25c472e361c9311b272de13
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
<<<<<<< HEAD
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_int(va_list ap);
int print_decimal(va_list ap);
// int print_binary(va_list ap);
// int print_unsigned(va_list ap);
// int print_octal(va_list ap);
// int print_hex(va_list ap);
// int print_HEX(va_list ap);

#endif /* MAIN_H */
=======
int _strlen(const char *s);
int _putchar(char c);
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_number(va_list ap);

>>>>>>> f2c4ed52e31c6f01d25c472e361c9311b272de13

