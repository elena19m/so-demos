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
	char *const argv[] = {"ls", NULL};
	printf("# ls\n");

	pid = fork();
	if (pid == 0) {
		// child
		printf("Child\n");
		execvp(argv[0], argv);
		printf("Child exit\n");
		exit(0);

	} else if (pid > 0) {
		// parent
		printf("Parent\n");
		waitpid(pid, &status, 0);
	} else {
		// error
	}

}

// ls -a -l
void func2() {
	pid_t pid;
	int status;
	char * const argv[] = {"ls", "-a", "-l", NULL};
	printf("# ls -a -l\n");

	pid = fork();
	if (pid == 0) {
		// child
		printf("Child\n");
		execvp(argv[0], argv);
		printf("Child exit\n");
		exit(0);

	} else if (pid > 0) {
		// parent
		printf("Parent\n");
		waitpid(pid, &status, 0);
	} else {
		// error
	}
}

// ls > out
void func3() {
	pid_t pid;
	int status;
	int fd;
	char * const argv[] = {"ls", NULL};
	printf("# ls > out\n");


	pid = fork();
	if (pid == 0) {
		// child
		printf("Child\n");
		fd = open("out", O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execvp(argv[0], argv);

	} else if (pid > 0) {
		// parent
		printf("Parent\n");
		waitpid(pid, &status, 0);
	} else {
		// error
	}

}

// ls | wc -l
void func4() {
	pid_t pid, pid2;
	int status;
	int *fd;
	char * const argv[] = {"ls", NULL};
	char * const argv2[] = {"wc", "-l", NULL};
	printf("# ls | wc -l\n");

	// ls > out
	// wc -l < out

	fd = malloc(2 * sizeof(fd));
	pipe(fd);
	pid = fork();

	if (pid == 0) {
		// ls
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execvp(argv[0], argv);
	} else if (pid > 0) {
		// parent
		pid2 = fork();
		if (pid2 == 0) {
			// wc -l
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			execvp(argv2[0], argv2);
		} else if (pid2 > 0) {
			// parent
			close(fd[0]);
			close(fd[1]);
			free(fd);
			waitpid(pid, &status, 0);
			waitpid(pid2, &status, 0);
		}
	
	}

}

int main(int argc, char **argv) {

	printf("argv[0] = %s\n", argv[0]);
	printf("argv[1] = %s\n", argv[1]);

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
