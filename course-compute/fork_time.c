#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N	10000

int main(void)
{
    int i;
    pid_t pid;

    for (i = 0 ; i < N; i++) {
	    pid = fork();

	    if (pid == 0) {
		// child
		printf("Process %d\n", i);
		exit(0);
	    } else if (pid > 0) {
		//parent
		printf("parent\n");
	    } else {
		// error
		exit(1);
	    }
     }

}
