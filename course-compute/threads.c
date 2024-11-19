#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N	8

struct targs {
	int id;
	int var;
};

void *routine(void *args)
{
	int count;
	struct targs *targs = (struct targs *)args;

	printf("Thread %d && var = %d\n", targs->id, targs->var);

	while(1)
		count++;

	return NULL;
}

int main(void)
{

	pthread_t threads[N];
	struct targs thread_args[N];
	int i, rc;

        fprintf(stderr, "Before creating a thread\n");
    	getchar();

	for (i = 0; i < N; i++) {
		thread_args[i].id = i;
		thread_args[i].var = i * i;
		rc = pthread_create(&threads[i], NULL, routine, &thread_args[i]);
    		fprintf(stderr, "After creating thread no %d\n", i);
    		getchar();
		if (rc != 0) {
			perror("Create");
			exit(1);
		}
	}

    	fprintf(stderr, "Before waiting the threads\n");
    	getchar();

	for (i = 0; i < N; i++) {
		rc = pthread_join(threads[i], NULL);
		if (rc != 0) {
			perror("Join");
			exit(1);
		}
	}


	return 0;
}
