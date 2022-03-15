#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd, rc;
	char string[20];

#ifdef WRITE0
	fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		perror("Error fd");

	rc = write(fd, "", 0);
	printf("rc = %d\n", rc);
	if (rc < 0)
		perror("Error write");

	close(fd);
#endif

	fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);	
	if (fd < 0)
		perror("Error fd");

	rc = write(fd, "This", 4);
	printf("rc = %d\n", rc);
	if (rc < 0)
		perror("Error write");

	close(fd);

	fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);	
	if (fd < 0)
		perror("Error fd");

	rc = lseek(fd, 4, SEEK_END);
	if (rc < 0)
		perror("Error lseek end + 5");

	rc = write(fd, "X", 1);
	printf("rc = %d\n", rc);
	if (rc < 0)
		perror("Error write");

	rc = lseek(fd, 0, SEEK_SET);
	if (rc < 0)
		perror("Error lseek start");

	rc = read(fd, string, 5);
	printf("rc = %d\nstring[0] = %d, string[1] = %d\n", rc, string[0], string[1]);

	close(fd);

	return 0;

}
