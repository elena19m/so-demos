#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char shorts[] = "This\n";

void ocreate(void)
{
	int rc, fd;
	// O_CREAT
	// O_RDWR
	// O_RDONLY
	// O_WRONLY
	// O_APPEND
	// O_TRUNC
}

void rewrite(void)
{
	int rc, fd;

}

int main(void)
{
	ocreate();
//	rewrite();

	return 0;
}
