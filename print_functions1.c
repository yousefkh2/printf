#include "main.h"

/**
 * print_char - prints a character
 * @ap: argument pointer
 *
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
 *
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
 * @ap: va_list to handle argument
 *
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
 *
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
	int n = va_arg(ap, int);
	int len = int_len(n);

	write(1, int_to_str(n), len);
	return (len);
}

/**
 * print_binary - print number in binary
 * @ap: list of arguments
 *
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

