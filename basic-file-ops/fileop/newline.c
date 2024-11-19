#include <stdio.h>

int main()
{
	char array[] = "Ana\n are \nmere\n";

	int c;
	for(c = 0; c < sizeof(array); c++) {
		fprintf(stderr, "array[%d] = %x\n", c, array[c]);
	}

	printf("strlen() = %d\n", strlen(array));
}
