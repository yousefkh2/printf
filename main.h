#ifndef PRINTF
#define PRINTF

#define VALID_SPECIFIER {'%', 'c', 's', 'i', 'd'}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int _strlen(const char *s);
int is_char_in_array(char spec, char s[]);
int is_directive(const char *s);
int _putchar(char c);
int _putstr(char *s);
int _putnumber(int n);
int _puterror(char *s);

#endif
