#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//#define DIV0
//#define SEGFAULT
//#define CHLD

static void handler(int signum) {
	if (signum == SIGFPE) {
		printf("Sad division by 0. Bye!\n");
		exit(1);
	}
	if (signum ==  SIGSEGV) {
		printf("Segmentation fault. Bye!\n");
		exit(1);
	}
	if (signum == SIGCHLD) {
		printf("Hey, look, a child!\n");
	}
}


int main(void) {
  
#ifdef DIV0
	int a, b, c;
#endif

#ifdef SEGFAULT
	char *p;
#endif

#ifdef CHLD
	pid_t pid;
	int status;
#endif

	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));

	sa.sa_handler = handler;
	sigaction(SIGFPE, &sa, NULL);
	sigaction(SIGSEGV, &sa, NULL);
	sigaction(SIGCHLD, &sa, NULL);

#ifdef DIV0
	a = 7;
	b = 0;
	c = a/b;
#endif

#ifdef SEGFAULT
	p = NULL;
	p[0] = '1';
#endif

#ifdef CHLD	
	pid = fork();
	if (pid == 0) {
		// do something
		sleep(1);
	} else {
		waitpid(pid, &status, 0);
	}
#endif

}
