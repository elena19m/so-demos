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
    char *buf;
    size_t pagesize;
    int fd;
    char a;

    pagesize = getpagesize();

    fd = open("a.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
    // (u)rwx (g)rwx (o)rwx
    // 110 100 100
    // rw- r-- r--
    ftruncate(fd, pagesize);

    fprintf(stderr, "Before mmap-ing the file\n");
    getchar();
    buf = mmap(NULL, pagesize, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
    	fprintf(stderr, "Map failed\n");
	exit(42);
    }

    fprintf(stderr, "Before reading from file\n");
    getchar();
    a = buf[0];
    fprintf(stderr, "a = %c\n", a);

    fprintf(stderr, "Before writing to file\n");
    getchar();
    buf[0] = 'A';

    fprintf(stderr, "After writing to file\n");
    getchar();

}
