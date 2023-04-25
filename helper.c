#include "main.h"

/**
 * _strlen - calulate string length
 * @s:string pointer to calculate its length
 * Return: string length as int
 */

int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * num_bytes - number of bytes required to store converted number
 *
 * @n: number to convert
 * @base: destination base of converted number
 * Return: (unsigned int) number of bytes
 */

unsigned int num_bytes(unsigned int n, int base)
{
	unsigned int num = 0;

	while (n)
	{
		n /= base;
		num++;
	}
	return (num);
}

/**
 * get_rem_as_char - get associated char for division based on number base
 *
 * @arr_rem: actual integer remainder
 * @assoc: respective char remainder according to number base
 * @rem: division remainder
 * @size: array size
 * Return: char for given remainder
 */

char get_rem_as_char(int arr_rem[], char assoc[], int rem,  int size)
{
	int i = 0;

	while (i < size)
	{
		if (arr_rem[i] == rem)
			return (assoc[i]);
		i++;
	}
	return (0);
}

/**
 * int_to - convert integer to given base
 *
 * @n: integer to convert
 * @base: required base to convert
 * Return: (int) represent converted integer
 */

char *int_to(unsigned int n, int base)
{

	unsigned int n_bytes = num_bytes(n, base);
	char *rep_ptr;
	int remainder[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			     15};
	char associate_sym[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
				  '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	rep_ptr = malloc(n_bytes + 1);
	if (rep_ptr == NULL)
		return (NULL);

	rep_ptr[n_bytes] = '\0';

	while (n)
	{

		rep_ptr[n_bytes - 1] = get_rem_as_char(remainder, associate_sym,
						       n % base, 16);
		n = n / base;
		n_bytes--;
	}
	return (rep_ptr);
}


/**
 * _putchar - print char to stdout
 *
 * @c: char to print
 * Return: Always (1)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
