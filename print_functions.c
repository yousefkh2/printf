#include "main.h"

int print_char(va_list ap)
{
    char c = (char)va_arg(ap, int);
    return write(1, &c, 1);
}

int print_string(va_list ap)
{
    char *str = va_arg(ap, char *);
    int count = 0;
    for (; *str != '\0'; str++)
    {
        write(1, str, 1);
        count++;
    }
    return count;
}

int print_percent(va_list ap)
{
    (void)ap;
    char c = '%';
    return write(1, &c, 1);
}

int print_int(va_list ap)
{
    int n = va_arg(ap, int);
    int count = 0;
    char buffer[12];
    char *ptr = &buffer[11];
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
    }

    *ptr = '\0';

    do
    {
        ptr--;
        *ptr = (num % 10) + '0';
        num /= 10;
        count++;
    } while (num > 0);

    write(1, ptr, &buffer[11] - ptr);

    return count;
}

int print_decimal(va_list ap)
{
    return print_int(ap); // since both %d and %i are for signed integers
}

