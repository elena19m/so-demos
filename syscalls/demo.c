#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PRINTFDEMO	1
#define PRINTFDEMO2	1
#define WRITEDEMO	1

int main(void)
{

#if PRINTFDEMO2
	printf("%s: %d\n", "SO counter", 3);
#endif

#if PRINTFDEMO
	printf("SO...2\n");
	printf("E");
	printf("F");
	printf("G");
	printf("H");
#endif

#if WRITEDEMO
	write(1, "SO...1\n", 7);
	write(1, "A", 1);
	write(1, "B", 1);
	write(1, "C", 1);
	write(1, "D", 1);
#endif

}
