
arg_c *handle_struct(const char *s, int n)
{
	arg_c *arr;
	int cnt = 0;

	arr = malloc(n * sizeof(arr) * sizeof(arg_c));
	if (arr == NULL)
		return (NULL);

	while (*s)
	{
		printf("current char is %c\n", *s);
		if (*s == '%' && *(s + 1))
		{
			switch (*(s + 1))
			{
			case 'c':
				arr[cnt].specifier = 'c';
				cnt++;
				break;
			case 's':
				arr[cnt].specifier = 's';
				cnt++;
				break;
			}

		}
		s++;
	}
	return (arr);
}



int handle_cnt(const char *s)
{
	int cnt = 0;
	char spec[] = VALID_SPECIFIER;

	while (*s && *(s + 1))
	{
		if (*s == '%' && is_valid_specifier(*(s + 1), spec))
		{
			cnt++;
		}
		s++;
	}
	return (cnt);
}


void print_struct(arg_c *ptr, int n)
{
	int i = 0;

	while(i < n)
	{
		printf("specifier type is:");
		printf("%c\n", ptr[i].specifier);
		i++;
	}
	printf("End here\n");
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

	while(*s && *(s + 1))
	{
		if (*s == '%')
			i++;
		s++;
	}
	return (i);
}

/** is_valid_specifier - check if char after % is valid
 *
 * s: pointer to string
 * Return: (int) 1 if it is valid else 0
 */
