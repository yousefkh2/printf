#include "main.h"

/**
 * int_len - return length of integer
 *
 * @n: number to get its lenght
 * Return: (int) length of integer
 */

int int_len(long int n)
{
	int len = 0;

	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * int_to_str - convert number to string
 *
 * @n: number to convert
 * Return: pointer to converted number as array
 */

char *int_to_str(int n)
{
	int len = int_len(n);
	int i = 0;
	int rem;
	int is_neg = 0;
	char *str;

	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		is_neg = 1;
		str[0] = '-';
	}
	for (; i < len; i++)
	{
		if (is_neg && (i == len - 1))
			break;

		rem = n % 10;
		n /= 10;
		str[len - i - 1] = abs(rem) + '0';
	}
	str[len] = '\0';
	return (str);
}

/**
 * get_13rot - move char by 13
 *
 * @c: char to move
 * Return: new char after be moved
 */

char get_13rot(char c)
{
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		return (c);

	if (c <= 90 && (c + 13) > 90)
		return (c - 13);
	else if (c < 90)
		return (c + 13);
	else if (c <= 122 && (c + 13) > 122)
		return (c - 13);
	else
		return (c + 13);
}
