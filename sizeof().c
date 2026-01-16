#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("int: %ld\n", sizeof(int));
	printf("long int: %ld\n", sizeof(long int));
	printf("long long: %ld\n", sizeof(long long));
	printf("double: %ld\n", sizeof(double));
	printf("float: %ld\n", sizeof(float));
	printf("char: %ld\n", sizeof(char));
	printf("char*: %ld - todos los punteros son de ese tamaño\n", sizeof(char*));
}
