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
    size_t pagesize;
    long pid;
    int fd;
    int ret;
    char *buf;

    pagesize = getpagesize();
    pid = getpid();

    fd = open("private.c", O_RDONLY);
    if (fd < 0) {
	perror("open");
	exit(1);
    }

    printf("pid = %ld\n", pid);
    fprintf(stderr, "Before mmap\n");
    getchar();

    buf = mmap(NULL, pagesize, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
	perror("mmap");
	exit(1);
    }

    fprintf(stderr, "After mmap\n");
    getchar();

    
    printf("buf = %p\n", buf);

    fprintf(stderr, "Before printing one byte from the memory page\n");
    getchar();

    fprintf(stderr, "buf[0] = %c\n", buf[0]);

    fprintf(stderr, "Before editing the memory page\n");
    getchar();

    buf[0]='a';

    fprintf(stderr, "After editing the memory page\n");
    getchar();
}
