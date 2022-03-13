#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char shorts[] = "This\n";

void ocreate(void)
{
	int rc, fd;

	fd = open("test.out", O_RDWR | O_CREAT, 0644);
	rc = write(fd, "SO Rulz!!!\n", 11);

	close(fd);

}

void rewrite(void)
{
	int rc, fd;

	fd = open("test.out", O_RDWR | O_CREAT | O_TRUNC, 0644);
	rc = write(fd, shorts, sizeof(shorts));

	close(fd);
}

int main(void)
{
	ocreate();
	rewrite();

	return 0;
}
