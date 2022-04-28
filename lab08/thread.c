#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N	8
#define ROUNDS	100000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int count;
__thread int count_t;

struct targ {
	int id;
	int var;
};

void *routine(void *args)
{
	int i;
	int local = 0;
	struct targs *targs = (struct targs *)args;

	for (i = 0; i < ROUNDS; i++) {
		count = count  + targs->var;
	}
	printf("Thread %d: count = %d\n", targs->id, count);

	return NULL;
}

int main(void)
{

	pthread_t threads[N];
	struct targs thread_args[N];
	int i, rc;

	for (i = 0; i < N; i++) {
		thread_args[i].id = i;
		thread_args[i].var = 1;
		rc = pthread_create(&threads[i], NULL, routine, &thread_args[i]);
		if (rc != 0) {
			perror("Create");
			exit(1);
		}
	}

	for (i = 0; i < N; i++) {
		rc = pthread_join(threads[i], NULL);
		if (rc != 0) {
			perror("Join");
			exit(1);
		}
	}

	return 0;
}
