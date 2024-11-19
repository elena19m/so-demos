#include <stdio.h>
#include <stdlib.h>
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
    pid = fork();

    if (pid == 0) {
	// child
	printf("child will sleep for now\n");
	sleep(100);
	exit(0);
    } else if (pid > 0) {
	//parent
	printf("parent exists\n");
    } else {
	// error
	exit(1);
    }

}
