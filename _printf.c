#include "main.h"

int (*get_print_func(char c))(va_list)
{
    int (*print_functions[])(va_list) = {
        print_char, print_string, print_percent,
        print_int, print_decimal
    };
    char print_chars[] = {'c', 's', '%', 'd', 'i'};
    int i;

    for (i = 0; i < 5; i++)
    {
        if (c == print_chars[i])
        {
            return print_functions[i];
        }
    }
    return NULL;
}

int _printf(const char *format, ...)
{
    va_list ap;
    int count = 0;
    int (*print_func)(va_list);

    va_start(ap, format);
    for (; *format != '\0'; format++)
    {
        if (*format == '%')
        {
            format++;
            print_func = get_print_func(*format);
            if (print_func)
            {
                count += print_func(ap);
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
    }
    va_end(ap);
    return count;
}

