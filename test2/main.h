#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
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

