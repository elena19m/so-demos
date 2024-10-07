#include <stdio.h>

void inc() {
	static int i = 0;
	static int j = 0;

	printf("i = %d\n", i++);
}

void inc2() {
	static int i = 0;

	printf("i = %d\n", i++);
}

int main()  {
	int i;

	for (i = 0; i < 20; i++)
		inc();

	return 0;
}
