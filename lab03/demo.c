#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

// ls
void func1() {
	pid_t pid;
	int status;
	const char *argv[] = {"ls", NULL};
	printf("# ls\n");

}

// ls -a -l
void func2() {
	pid_t pid;
	int status;
	const char *argv[] = {"ls", "-a", "-l", NULL};
	printf("# ls -a -l\n");

}

// ls > out
void func3() {
	pid_t pid;
	int status;
	int fd;
	const char *argv[] = {"ls", NULL};
	printf("# ls > out\n");

}

// ls | wc -l
void func4() {
	pid_t pid, pid2;
	int status;
	int fd[2];
	const char *argv[] = {"ls", NULL};
	const char *argv2[] = {"wc", "-l", NULL};
	printf("# ls | wc -l\n");

	// ls > out
	// wc -l < out


}

int main(int argc, char **argv) {
	if (argc != 2)
		exit(1);

	if(strncmp(argv[1], "1", 1) == 0)
		func1();
	else if (strncmp(argv[1], "2", 1) == 0)
		func2();
	else if (strncmp(argv[1], "3", 1) == 0)
		func3();
	else if (strncmp(argv[1], "4", 1) == 0)
		func4();
}
