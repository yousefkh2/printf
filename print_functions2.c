#include "main.h"

/**
 * print_unsigned_int - print unsigned integer
 * @ap: list of arguments
 *
 * Return: count of printed numbers
 */
int print_unsigned_int(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	unsigned int i = n;
	int res = 0;
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
 * @ap: list of arguments
 *
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
 * @ap: list of arguments
 *
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
 * @ap: list of arguments
 *
 * Return: count of printed numbers
 */
int print_HEX(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *rep_num = int_to(num, 16);

	if (!num)
		return (write(1, "0", 1));
	return (write(1, rep_num, _strlen(rep_num)));
}

/**
 * print_special - print string but for non printable chars print hex instead
 *
 * @ap: list of arguments
 * Return: number of printed chars
 */

int print_special(va_list ap)
{
	char *str = va_arg(ap, char *);
	char *tmp;
	int cnt = 0;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			tmp = int_to(*str, 16);
			cnt += write(1, "\\x", 2);
			if (_strlen(tmp) < 2)
				cnt += write(1, "0", 1);
			cnt += write(1, tmp, _strlen(tmp));
		} else
			cnt += write(1, str, 1);
		str++;
	}
	return (cnt);
}
