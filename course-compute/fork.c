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

    //setvbuf(stdout, NULL, 0, 0);
    printf("Test - ");
    pid = fork();

    if (pid == 0) {
	// child
	// sleep(2);
	printf("child\n");
	exit(0);
    } else if (pid > 0) {
	// parent
	printf("parent\n");
	//wait(NULL);
    } else {
	// error
	exit(1);
    }

}
