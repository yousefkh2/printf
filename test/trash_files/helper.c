#include <string.h>
#include "main.h"

/**
 * _strlen - calulate string length
 * @s:string pointer to calculate its length
 * Return: string length as int
 */

int _strlen(char *s)
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
 * percent_sign_count - count number of percentage sign in string
 *
 * s: string to sparse
 * Return: (int) number of percentage signs
 */

int percent_sign_count(char *s)
{
	int i = 0;

	while(*s)
	{
		if (*s == '%')
			i++;
		s++;
	}
	return (i);
}
  
 
