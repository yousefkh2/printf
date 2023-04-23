#include "main.h"

void print_struct(arg_c **ptr)
{
	int i = 0;

	while(*ptr)
	{
		printf("specifier type is:");
		i++;
		printf("%c\n", ptr[i]->specifier);
	}
	printf("End here\n");
}

int main(void)
{
	char *s = "ana%cs yasser%";
	int n = percent_sign_count(s);

	arg_c **ptr = handle(s, n);

	print_struct(ptr);
}
