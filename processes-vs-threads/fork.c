#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
    pid_t pid;

    printf("Test - \n");
    //fprintf(stdout, ...);

    pid = fork();

    if (pid == 0) {
	// child
	sleep(100);
	printf("child\n");
	exit(0);
    } else if (pid > 0) {
	//parent
	printf("parent\n");
	//wait(NULL);
    } else {
	// error
	exit(1);
    }

}
