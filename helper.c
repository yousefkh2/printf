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
