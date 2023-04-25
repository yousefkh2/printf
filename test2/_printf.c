#include "main.h"
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string with zero or more directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int count = 0, i;

    va_start(ap, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
            continue;
        }

        i++;
        switch (format[i])
        {
        case 'c':
            count += print_char(ap);
            break;
        case 's':
            count += print_string(ap);
            break;
        case '%':
            count += print_percent();
            break;
        case 'd':
        case 'i':
            count += print_int(ap);
            break;
        default:
            write(1, &format[i - 1], 1);
            write(1, &format[i], 1);
            count += 2;
        }
    }

    va_end(ap);

    return (count);
}

