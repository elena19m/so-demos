#include <stdio.h>

char buf[] = "C is love";
char buf2[] = "Sleepy";
const char *cp1 = buf;
char *const cp2 = buf;
const char *const cp3 = buf;

int main() {

	// const char *cp1
	// we cannot modify the memory region cp1 points to
	// we can modify the address cp1 saves
	// cp1[0] = 'D';
	cp1 = buf2;

	// char *const cp2
	// we can modify the memory region cp2 point to
	// we cannot modify the address cp2 saves
	cp2[0] = 'D';
	// cp2 = buf2;

	// const char *const cp3
	// we cannot modify the memory region cp2 point to
	// we cannot modify the address cp2 saves
	// cp3[0] = 'D';
	// cp3 = buf2;

  return 0;
}
