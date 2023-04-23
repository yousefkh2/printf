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
 * is_char_in_array - check if char in given array
 *
 * @spec: char to check
 * @s: array of char
 * Return: (int) 1 if char in array else 0
 */

int is_char_in_array(char spec, char s[])
{

	if (!spec)
		return (0);

	while (*s)
	{
		if (spec == *s)
			return (1);
		s++;
	}
	return (0);
}

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

char get_rem_as_char(c_rem *arr, int rem, int size)
{
	int i = 0;

	while (i < size)
	{
		if (arr[i].rem == rem)
			return (arr[i].rep);
		i++;
	}
	return (0);
}

/**
 * int_to_binary - convert integer to binary
 *
 * @n: integer to convert
 * Return: (int) represent converted integer
 */

char * int_to(unsigned int n, int base)
{
	unsigned int res = 0;
	unsigned int n_bytes = num_bytes(n, base);
	char *rep_ptr;

	c_rem arr_rem[16] =
		{{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
		 {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
		 {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'},
		 {15, 'F'}};

	rep_ptr = malloc(n_bytes + 1);
	if (rep_ptr == NULL)
		return (NULL);

	while (n)
	{
		rep_ptr[n_bytes - 1] = get_rem_as_char(arr_rem, n % base, 16);
		n = n / base;
		n_bytes--;
	}
	return (rep_ptr);
}
