#include <stdio.h>
#include <stdlib.h>

char a = 'A';
int b;

char *c = "Memory Management Unit";

const char d = 'D';

static const char e = 'E';

int count = 0;

void inc() {
	static int i = 0;
	static int j = 1;
	int k = 0;

#if BONUS
	const char h[] = "Hello, world";
#endif

	fprintf(stdout, "%s: Call number = %d\n", __func__, count++);
	i++;
	j++;
	k++;

	fprintf(stdout, "%s: i = %d\n", __func__, i);
	fprintf(stdout, "%s: j = %d\n", __func__, j);
	fprintf(stdout, "%s: k = %d\n", __func__, k);

#if BONUS
	fprintf(stdout, "%s: h = %s\n", __func__, h);
	*(char *)h += 1;
	fprintf(stdout, "%s: h = %s\n", __func__, h);
#endif
}

int add(int a, int b) {
	int res;

	res = a + b;

	return res;
}

int main() {
	static char f = 'F';
	char g = 'G';
	int *buf;

	inc();
	inc();
	inc();

	fprintf(stdout, "%s: a = %c\n", __func__, a);
	fprintf(stdout, "%s: b = %d\n", __func__, b);
	fprintf(stdout, "%s: c = %s\n", __func__, c);
	fprintf(stdout, "%s: d = %c\n", __func__, d);
	fprintf(stdout, "%s: e = %c\n", __func__, e);
	fprintf(stdout, "%s: f = %c\n", __func__, f);
	fprintf(stdout, "%s: g = %c\n", __func__, g);

	buf = malloc(10 * sizeof(int));

	fprintf(stdout, "%s: buf[100] = %d\n", __func__, buf[100]);

	return 0;
}
