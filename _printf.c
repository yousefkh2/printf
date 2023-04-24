#include "main.h"

/**
 * _printf - print formatted string
 *
 * @format: formatted text
 * Return: (int)
 */

int _printf(const char *format, ...)
{
	int pcnt = 0;
	va_list op;
	char next;

	va_start(op, format);
	if (!is_directive(format))
	{
		_puterror("Invalid directive\n");
		exit(-1);
	}
	while (*format)
	{
		next = *(format + 1);
		if (*format != '%')
		{
			pcnt += _putchar(*format);
		} else if (next == '%')
		{
			pcnt += _putchar(*format);
			format++;
		} else if (next == 's')
		{
			pcnt += _putstr(va_arg(op, char *));
			format++;
		} else if (next == 'c')
		{
			pcnt += _putchar((char)va_arg(op, int));
			format++;
		} else if (next == 'd' || next == 'i')
		{
			pcnt += _putnumber(va_arg(op, int));
			format++;
		}

		format++;
	}
	va_end(op);
	return (pcnt);
}
