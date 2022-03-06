#include <stdio.h>

#include "add.h"

#define STR1 "Hello, SO!\n"
#define A 3
#define B (A + 2)

#define KB 1024
#define MB (1024*KB)

char *str2 = "Hello, SO2!\n";

int main()
{
	int prod = 0;
	int c = 3;
	int d = c + 2;

	printf("%s", STR1);
	printf("%s", str2);

	printf("A = %d\n", A);
	printf("B = %d\n", B);
	printf("c = %d\n", c);
	printf("d = %d\n", d);

	prod = mul(A, B);
	printf("A * B = %d\n", prod);
	prod = mul(c, d);
	printf("c * d = %d\n", prod);

	return 0;
}
