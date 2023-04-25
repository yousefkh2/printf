#include "main.h"

/**
 * print_char - prints a character
 * @ap: argument pointer
 * Return: number of characters printed
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @ap: argument pointer
 * Return: number of characters printed
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	int i;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
		write(1, &s[i], 1);

	return (i);
}

/**
 * print_percent - print % to stdout
 *
 * @ap: va_list to handle argumet
 * Return: (int) number of printed numbers (1)
 */

int print_percent(va_list ap)
{
	char c = '%';

	UNUSED(ap);
	return (write(1, &c, 1));
}

/**
 * print_int - prints an integer
 * @ap: argument pointer
 * Return: number of characters printed
 */
int print_int(va_list ap)
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
 * print_binary - print number in binary
 *
 * @ap: list of arguments
 * Return: count of printed numbers
 */

int print_binary(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *rep_num = int_to(num, 2);

	if (!num)
		return (write(1, "0", 1));
	return (write(1, rep_num, _strlen(rep_num)));
}

/**
 * print_unsigned - print unsigned integer
 *
 * @ap: list of arguments
 * Return: count of printed numbers
 */

int print_unsigned(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);

	int i = n;
	int res;
	int den = 1;
	int cnt = 0;

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
 * print_octal - print number in octal
 *
 * @ap: list of arguments
 * Return: count of printed numbers
 */

int print_octal(va_list ap)
{
	unsigned int num = va_arg(ap, int);
	char *rep_num = int_to(num, 8);

	if (!num)
		return (write(1, "0", 1));
	return (write(1, rep_num, _strlen(rep_num)));
}

/**
 * print_hex - print number in hex format (lower)
 *
 * @ap: list of arguments
 * Return: count of printed numbers
 */

int print_hex(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *rep_num = int_to(num, 16);
	int i = 0;

	if (!num)
		return (write(1, "0", 1));
	while (*(rep_num + i))
	{
		rep_num[i] = tolower(rep_num[i]);
		i++;
	}
	return (write(1, rep_num, _strlen(rep_num)));
}

/**
 * print_HEX - print number in hex format (upper)
 *
 * @ap: list of arguments
 * Return: count of printed numbers
 */

int print_HEX(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *rep_num = int_to(num, 16);

	if (!num)
		return (write(1, "0", 1));
	return (write(1, rep_num, _strlen(rep_num)));

	return (0);
}
