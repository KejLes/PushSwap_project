#include <stdio.h>

void *try();

int main(int argc, char **argv)
{
	for(int i = 1; argv[i]; i++)
	{
		printf("%s\n", argv[i]);
	}
	if (try())
		printf("si\n");
	else
		printf("no\n");
}

void	*try()
{
	if(1 == 2)
		return (0);
	return ((void *)1);
}
