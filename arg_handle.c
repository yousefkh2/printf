#include "main.h"

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
 * print_char - print char to stdout
 *
 * @ap: va_list to handle argument
 * Return: Always (1)
 */

int print_char(va_list ap)
{
	char c = va_arg(ap, int);
	return (write(1, &c, 1));
}

/**
 * _putstr - print string to stdout
 *
 * @ap: va_list to handle argument
 * Return:(int) number of char in string
 */

int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	int cnt = 0;

	if (str == NULL)
		return (write(1, "(null)",6));
	while (*str)
	{
		cnt += write(1, str, 1);
		str++;
	}
	return (cnt);
}

/**
 * _putnumber - print number ot stdout
 *
 * @ap: va_list to handle argument
 * Return: (int) number of printed numbers
 */

int print_number(va_list ap)
{
	int n = va_arg(ap, int);
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
 * _putpercent - print % to stdout
 *
 * @ap: va_list to handle argumet
 * Retrun: (int) number of printed numbers (1)
 */

int print_percent(va_list ap)
{
	char c = '%';

	UNUSED(ap);
	return (write(1, &c, 1));
}
