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
    unsigned long long func = (unsigned long long) main;
    unsigned long long page = func & (1-0xfff);
    long pid;
    int ret;

    pagesize = getpagesize();
    pid = getpid();

    printf("main = 0x%llx\n", func);
    printf("page = 0x%llx\n", page);
    printf("pid = %ld\n", pid);

    fprintf(stderr, "Before mprotect\n");
    getchar();
    ret = mprotect((void *)page, pagesize, PROT_READ | PROT_WRITE | PROT_EXEC);

    if(ret < 0)
	perror("mprotect");

    fprintf(stderr, "After mprotect\n");
    getchar();


    fprintf(stderr, "Before editing the .text zone\n");
    getchar();

    ((char *)page)[0]='a';

    fprintf(stderr, "After editing the .text zone\n");
    getchar();
}
