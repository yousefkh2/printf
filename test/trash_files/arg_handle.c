#include "main.h"

arg_c **handle(const char *s, int n)
{
	arg_c **arr;
	int i = 0;
	int cnt = 0;

	arr = malloc(n * sizeof(arr));
	if (arr == NULL)
		return (NULL);

	while (i < n)
	{
		arr[i] = malloc(sizeof(arg_c));
		if (arr[i] == NULL)
		{
			free(arr);
			return (NULL);
		}
		i++;
	}

	while (*s)
	{
		printf("current char is %c\n", *s);
		if (*s == '%' && *(s + 1))
		{
			switch (*(s + 1))
			{
			case 'c':
				arr[cnt]->specifier = 'c';
				cnt++;
				break;
			case 's':
				arr[cnt]->specifier = 's';
				cnt++;
				break;
			}

		}
		s++;
	}
	return (arr);
}
