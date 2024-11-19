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
	printf("child exits\n");
	exit(0);
    } else if (pid > 0) {
	//parent
	printf("parent doesn't care\n");
	sleep(5);
	printf("parent cares... eventually\n");
	wait(NULL);

	sleep(30);
    } else {
	// error
	exit(1);
    }

}
