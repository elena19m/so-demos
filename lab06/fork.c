#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
    pid_t pid;

    printf("Here we are - ");

    pid = fork();

    if (pid == 0) {
	// child
	printf("child\n");
	exit(0);
    } else if (pid > 0) {
	//parent
	printf("parent\n");
	wait(NULL);
    } else {
	// error
	exit(1);
    }

}