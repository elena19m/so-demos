#include <stdio.h>
#include <stdlib.h>

char arr[] = "Ana are mere";
//char *arr;
//char arr[] = {'A', 'n', 'a', ...}'

char *p = arr;
const char *p2 = arr;
char *const p3 = arr;
const char *const p4 = arr; 

int main() {

	p[0] = 'A';
	p = malloc(10);

	//p2[0] = 'A';
	p2 = malloc(10);

	p3[0] = 'A';
	//p3 = malloc(10);

	//p4[0] = 'A';
	//p4 = malloc(10);
}
