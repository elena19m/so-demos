#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N	8
#define ROUNDS	1000000

int count;
__thread int count_t;

struct targs {
	int id;
	int var;
};

void *routine(void *args)
{
	int i;
	int local_count = 0;
	static int static_count;
	struct targs *targs = (struct targs *)args;

	for (i = 0; i < ROUNDS; i++) {
		count = count  + targs->var;
		count_t = count_t + targs->var;
		local_count = local_count + targs->var;
		static_count =  static_count + targs->var;
	}
	printf("Thread %d: count = %d\n", targs->id, count);
	printf("Thread %d: count_t = %d\n", targs->id, count_t);
	printf("Thread %d: local_count = %d\n", targs->id, local_count);
	printf("Thread %d: static_count = %d\n", targs->id, static_count);

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

	printf("Main: count = %d\n", count);
	printf("Main: count_t = %d\n", count_t);

	return 0;
}
