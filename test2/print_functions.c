#include "main.h"
#include <unistd.h>

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
 * print_percent - prints a percent sign
 * Return: number of characters printed
 */
int print_percent(void)
{
    write(1, "%", 1);
    return (1);
}

/**
 * print_int - prints an integer
 * @ap: argument pointer
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
    int n = va_arg(ap, int);
    int count = 0, temp;
    char c;
    int i;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        n = -n;
    }

    temp = n;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }

    while (count > 0)
    {
        temp = n;
        for (i = 0; i < count - 1; i++)
            temp /= 10;
        c = (temp % 10) + '0';
        write(1, &c, 1);
        count--;
    }

    return (count);
}

