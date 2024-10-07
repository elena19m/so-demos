#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
	int fd1 = open("file", O_CREAT | O_RDWR | O_TRUNC, 0644);
	int fd2 = open("file", O_CREAT | O_RDWR | O_TRUNC, 0644);
	int fd3 = dup(fd1);

	write(fd1, "1\n", 2);
	write(fd2, "2\n", 2);
	write(fd3, "3\n", 2);

	close(fd1);
	close(fd2);
	close(fd3);
}
