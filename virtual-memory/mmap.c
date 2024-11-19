#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WRITEDEMO

int main(void)
{
    char *buf1, *buf2;
    size_t pagesize;
    char a;

    pagesize = getpagesize();

    fprintf(stderr, "Before mmap SHARED\n");
    getchar();
    buf1 = mmap(NULL, 7 * pagesize, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    fprintf(stderr, "Before mmap PRIVATE\n");
    getchar();
    buf2 = mmap(NULL, 7 * pagesize, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    fprintf(stderr, "After mmap PRIVATE\n");
    getchar();

#ifdef WRITEDEMO
    fprintf(stderr, "Before reading from mmap SHARED\n");
    getchar();

    a = buf1[0];

    fprintf(stderr, "Before reading from mmap PRIVATE\n");
    getchar();

    a = buf2[0];

    fprintf(stderr, "Before writing the first byte of buf1\n");
    getchar();

    buf1[0] = 'A';

    fprintf(stderr, "Before writing the last byte of buf1\n");
    getchar();

    buf1[7* pagesize - 1] = 'A';

    fprintf(stderr, "Before writing the first byte of buf2\n");
    getchar();

    buf2[0] = 'A';

    fprintf(stderr, "After writing in buf2\n");
    getchar();
#endif

}
