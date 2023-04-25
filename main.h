#ifndef PRINTF
#define PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
int _strlen(const char *s);
int _putchar(char c);
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int print_number(va_list ap);


#endif
