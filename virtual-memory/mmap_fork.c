#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(void)
{
    pid_t pid;
    int fd;
    char *buf1, *buf2;
    size_t pagesize;

    pagesize = getpagesize();

    buf1 = mmap(NULL, pagesize, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    buf2 = mmap(NULL, pagesize, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    memset(buf1, 0, pagesize);
    memset(buf2, 0, pagesize);
    memcpy(buf1, "before fork", sizeof("before fork"));
    memcpy(buf2, "before fork", sizeof("before fork"));

    pid = fork();

    if (pid == 0) {
	// child
	sleep(1);
	printf("child - buf1: %s\n", buf1);
	printf("child - buf2: %s\n", buf2);
	exit(0);
    } else if (pid > 0) {
	//parent
	memcpy(buf1, "parent", sizeof("parent"));
	printf("parent - buf1: %s\n", buf1);
	memcpy(buf2, "parent", sizeof("parent"));
	printf("parent - buf2: %s\n", buf2);
	wait(NULL);
    } else {
	// error
	exit(1);
    }

}