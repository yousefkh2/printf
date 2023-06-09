#include "main.h"

/**
 * get_print_func - handle print function
 * @c: flag to handle print func
 *
 * Return: pointer to appropriate print function
 */
int (*get_print_func(char c))(va_list)
{
	int (*print_functions1[])(va_list) = {
		print_char, print_string, print_percent,
		print_int, print_int, print_binary
	};
	int (*print_functions2[])(va_list) = {
		print_unsigned_int, print_octal, print_hex, print_HEX,
		print_reverse, print_special, print_address, print_13rot
	};
	char print_chars1[] = {'c', 's', '%', 'd', 'i', 'b'};
	char print_chars2[] = {'u', 'o', 'x', 'X', 'r', 'S', 'p', 'R'};
	int i = 0;

	while (i < 6)
	{
		if (c == print_chars1[i])
		{
			return (print_functions1[i]);
		}
		i++;
	}

	i = 0;
	while (i < 8)
	{
		if (c == print_chars2[i])
		{
			return (print_functions2[i]);
		}
		i++;
	}

	return (NULL);
}

/**
 * _printf - print formatted string
 * @format: formatted text
 *
 * Return: (int)
 */
int _printf(const char *format, ...)
{
	int pcnt = 0;
	va_list op;
	int (*print_func)(va_list);

	va_start(op, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(format + 1))
				break;
			print_func = get_print_func(*(format + 1));
			if (print_func)
				pcnt += print_func(op);
			else
				pcnt += write(1, format, 2);
			format++;
		}
		else
		{
			pcnt += write(1, format, 1);
		}
		format++;
	}
	va_end(op);
	return (pcnt);
}
