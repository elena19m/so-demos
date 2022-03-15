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
	if (fd < 0) {
		perror("Error while opening file");
		exit(-1);
	}

	rc = write(fd, "SO Rulz!!!\n", 11);
	if (rc < 0) {
		perror("Error while reading file");
		exit(-1);
	}

	close(fd);

}

void rewrite(void)
{
	int rc, fd;

	fd = open("test.out", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("Error while opening file");
		exit(-1);
	}

	rc = write(fd, shorts, sizeof(shorts));
	if (rc < 0) {
		perror("Error while writing file");
		exit(-1);
	}

	close(fd);
}

int main(void)
{
	ocreate();
	rewrite();

	return 0;
}
