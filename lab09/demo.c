/* do not use UNICODE */
#undef _UNICODE
#undef UNICODE

#include <windows.h>
#include <stdio.h>

#include "../utils/utils.h"

#define NO_THREADS 2

int count = 0;
int ROUNDS = 100000;

HANDLE mutex1, mutex2;

/* function executed by the threads */
DWORD WINAPI ThreadFunc1(LPVOID lpParameter)
{
	int i;

	printf("thread %d starting\n", lpParameter);

	for (i = 0; i < ROUNDS; i++) {
		WaitForSingleObject(mutex1, INFINITE);
		WaitForSingleObject(mutex2, INFINITE);
		count++;
		ReleaseMutex(mutex2);
		ReleaseMutex(mutex1);
	}

	return 0;
}

/* function executed by the threads */
DWORD WINAPI ThreadFunc2(LPVOID lpParameter)
{
	int i;

	printf("thread %d starting\n", lpParameter);

	for (i = 0; i < ROUNDS; i++) {
		WaitForSingleObject(mutex1, INFINITE);
		WaitForSingleObject(mutex2, INFINITE);
		count++;
		ReleaseMutex(mutex2);
		ReleaseMutex(mutex1);
	}

	return 0;
}

DWORD main(VOID)
{
	DWORD IdThread, dwReturn;
	HANDLE hThread[NO_THREADS];
	int i;

	setbuf(stdout, NULL);

	mutex1 = CreateMutex(NULL, FALSE, NULL);
	mutex2 = CreateMutex(NULL, FALSE, NULL);

	/* create threads */
	hThread[0] = CreateThread(
			NULL, /* default security attributes */
			0,    /* default stack size */
			(LPTHREAD_START_ROUTINE) ThreadFunc1,
			(LPVOID) 1, /* no thread parameter */
			0,          /* immediately run the thread */
			&IdThread); /* thread id */
	// DIE(hThread[0] == NULL, "CreateThread 1");

	hThread[1] = CreateThread(
			NULL, /* default security attributes */
			0,    /* default stack size */
			(LPTHREAD_START_ROUTINE) ThreadFunc2,
			(LPVOID) 2, /* no thread parameter */
			0,          /* immediately run the thread */
			&IdThread); /* thread id */
	//DIE(hThread[1] == NULL, "CreateThread 2");

	
	/* wait for threads completion */
	for (i = 0; i < NO_THREADS; i++) {
		dwReturn = WaitForSingleObject(hThread[i], INFINITE);
		//DIE(dwReturn == WAIT_FAILED, "WaitForSingleObject");
	}

	CloseHandle(mutex1);
	CloseHandle(mutex2);

	return 0;
}
