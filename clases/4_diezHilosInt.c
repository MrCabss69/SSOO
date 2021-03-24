#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 10

void * print_id(void *p){
	int *pos = (int *) p;
	printf("Id: %d; pos:%d \n", (int) pthread_self(),*pos);
	pthread_exit(NULL);
}

int main(void){

	int i;
	int pos[NUM_THREADS];
	pthread_t thid[NUM_THREADS];
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	for (i=0; i<NUM_THREADS; i++) {
		pos[i]=i;
		pthread_create(&thid[i],&attr,&print_id,&pos[i]);
	}

	for (i=0; i<NUM_THREADS; i++) 
		pthread_join(thid[i],NULL);

	pthread_attr_destroy (&attr);

	return 0;
}
