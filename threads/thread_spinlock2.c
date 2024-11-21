#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N	8
#define ROUNDS	1000000
//#define ROUNDS	1

pthread_spinlock_t spinlock;
int pshared = PTHREAD_PROCESS_SHARED;

int count;
__thread int count_t;

struct targs {
	int id;
	int var;
};

void *routine(void *args)
{
	int i;
	struct targs *targs = (struct targs *)args;

	pthread_spin_lock(&spinlock);
	for (i = 0; i < ROUNDS; i++) {
		count = count  + targs->var;
	}
	pthread_spin_unlock(&spinlock);
	printf("Thread %d: count = %d\n", targs->id, count);

	return NULL;
}

int main(void)
{

	pthread_t threads[N];
	struct targs thread_args[N];
	int i, rc;
	
	rc = pthread_spin_init(&spinlock, pshared);
	if (rc != 0) {
		perror("Spinlock init");
		exit(1);
	}

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

	return 0;
}
