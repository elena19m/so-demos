#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 10
//#define N 500000

int main(void)
{
	char *p;
	int i;

	for (i = 0; i < N; i++) { 
		p = malloc(10);
		//printf("[for] p = %p\n", p);
		//free(p);
	}
	
	p =  malloc(1 * 130 * 1024);
	//printf("[outside for] p = %p\n", p);
	free(p);

	//malloc_stats();

	return 0;
}
