#include "main.h"

/**
 * print_reverse - print string in reverse order
 *
 * @ap: list of arguments
 * Return: number of printed chars
 */

int print_reverse(va_list ap)
{
	char *str = va_arg(ap, char *);

	int i;
	int len = _strlen(str);
	int cnt = 0;

	for (i = len - 1 ; i >= 0; i--)
	{
		cnt += _putchar(str[i]);
	}
	return (cnt);
}

/**
 * print_address - print address of argument
 *
 * @ap: list of arguments
 * Return: number of printed chars
 */

int print_address(va_list ap)
{
	void *ptr = va_arg(ap, void *);
	unsigned long int n = (unsigned long int) ptr;
	char *str_num;
	int cnt = 0;
	int i = 0;


	if (ptr == NULL)
	{
		cnt += write(1, "(nil)", 5);
		return (cnt);
	}

	str_num = int_to(n, 16);
	cnt += write(1, "0x", 2);
	while (*(str_num + i))
	{
		str_num[i] = tolower(str_num[i]);
		i++;
	}
	cnt += write(1, str_num, _strlen(str_num));

	return (cnt);
}
