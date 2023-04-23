#ifndef PRINTF
#define PRINTF

#define VALID_SPECIFIER {'%', 'c', 's', 'i', 'd'}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

typedef struct convert_reminder
{
	int rem;
	char rep;
} c_rem;

int _printf(const char *format, ...);
int _strlen(const char *s);
int is_char_in_array(char spec, char s[]);
int is_directive(const char *s);
int _putchar(char c);
int _putstr(char *s);
int _putnumber(int n);
int _puterror(char *s);
char * int_to(unsigned int n, int base);
unsigned int num_bytes(unsigned int n, int base);
char get_rem_as_char(c_rem *arr, int rem, int size);


#endif
