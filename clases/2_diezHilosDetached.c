#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_THREADS 10

void *func(void *p) {
	printf("Thread %d \n", (int) pthread_self());
	pthread_exit(NULL);
}

int main(void) {
	int j;
	pthread_attr_t attr;
	pthread_t thid[MAX_THREADS];
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	for(j = 0; j < MAX_THREADS; j++)
		pthread_create(&thid[j], &attr, &func, NULL);


	sleep(5);

	pthread_attr_destroy (&attr);
	return 0;
}


