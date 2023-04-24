#include "main.h"

/**
 * is_directive - check if string has valid directive
 *
 * @s: string to check
 * Return: (int) 1 if directive is valid else 0
 */

int is_directive(const char *s)
{
	int is_dir = 1;
	char spec[] = VALID_SPECIFIER;

	while (*s)
	{
		if (*s == '%' && *(s + 1) == '%')
		{
			s++;
		} else if (*s == '%' && !is_char_in_array(*(s + 1), spec))
		{

			is_dir = 0;
			break;
		}
		s++;
	}

	return (is_dir);
}

/**
 * _putchar - print char to stdout
 *
 * @c: char to print
 * Return: Always (1)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - print string to stdout
 *
 * @s: string to print
 * Return:(int) number of char in string
 */

int _putstr(char *s)
{
	int cnt = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		cnt++;
	}
	return (cnt);
}

/**
 * _putnumber - print number ot stdout
 *
 * @n: number to print
 * Return: (int) number of printed numbers
 */

int _putnumber(int n)
{
	int i = n;
	int res;
	int den = 1;
	int cnt = 0;

	if (n < 0)
	{
		n = -n;
		i = n;
		cnt += _putchar('-');
	}
	while (i > 9)
	{
		den *= 10;
		i /= 10;
	}
	while (den >= 1)
	{
		res = n / den;
		n -= res * den;
		den /= 10;
		cnt += _putchar(res + '0');
	}
	return (cnt);
}

/**
 * _puterror - print string to stderr
 *
 * @s: string to print
 * Return:(int) number of char in string
 */

int _puterror(char *s)
{
	return (write(2, s, _strlen(s)));
}
