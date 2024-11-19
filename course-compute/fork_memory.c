#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PAGE_SIZE getpagesize()

int main(void)
{
    pid_t pid;
    char *buf1, *buf2;
 
    printf("Test - \n");
    //fprintf(stdout, ...);
    buf1 = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    buf2 = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);

    strcpy(buf1, "Much private, such wow");
    strcpy(buf2, "Much shared, such wow");

    pid = fork();

    if (pid == 0) {
	// child
	sleep(2);
	printf("child\n");
	printf("[child] buf1 = %s\n", buf1);
	printf("[child] buf2 = %s\n", buf2);
	exit(0);
    } else if (pid > 0) {
	//parent
	printf("parent\n");
    	strcpy(buf1, "Parent");
    	strcpy(buf2, "Parent");
	printf("[parent] buf1 = %s\n", buf1);
	printf("[parent] buf2 = %s\n", buf2);
	//wait(NULL);
    } else {
	// error
	exit(1);
    }

}
