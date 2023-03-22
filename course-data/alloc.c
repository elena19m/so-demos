#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define BYTES (5000 * sizeof(int))
#define PAGE_SIZE getpagesize()

int main() {
	int i, j;
	int *arr;

	getchar();

	printf("Will allocate %ld bytes\n", BYTES);
	printf("Will allocate %ld pages\n", (BYTES + PAGE_SIZE - 1)/PAGE_SIZE);

#ifndef MMAP
	arr = malloc(BYTES);
#else
	arr = mmap(NULL, BYTES, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
#endif
	printf("arr = %p\n", arr);
	printf("arr = %p\n", arr + 4096 * ((BYTES + PAGE_SIZE -1) / PAGE_SIZE));

	//arr[5121] = 0;

	getchar();

	printf("Will access arr[1500] = arr +  %ld\n", 1500 * sizeof(int));

	arr[1500] = 2;

	getchar();
	printf("Will access arr[1501]\n");

	arr[1500] = 2;

	getchar();

	printf("Will access arr[0]\n");
	arr[0] = 0;

	getchar();

	printf("Will access arr[3000]\n");
	arr[3000] = 0;

	getchar();

#ifdef OUT_OF_BOUNDS
	printf("Will access arr[5001]\n");
	arr[5001] = 0;
	getchar();

	printf("Will access arr[5121]\n");
	arr[5121] = 0;	
	getchar();
#endif

	return 0;
}
