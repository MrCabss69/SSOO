#include <pthread.h>
#include <stdio.h>


#define MAX_THREADS 10

struct sumandos {
	int sum1;
	int sum2;
};

void *func(void *p) {
	struct sumandos *par = (struct sumandos *)p;
	int suma;
	suma = (*par).sum1 + (*par).sum2;
	// Equivale a  suma = par->sum1 + par->sum2;

	printf("La suma es igual a %d \n", suma);
	pthread_exit(NULL);
}

int main(void) {
	int j;
	pthread_attr_t attr;
	pthread_t thid[MAX_THREADS];
	struct sumandos sum[MAX_THREADS];

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	for(j = 0; j < MAX_THREADS; j++){
		sum[j].sum1=j;
		sum[j].sum2=j+1;
		pthread_create(&thid[j], &attr, &func, &sum[j]);
	}

	for(j = 0; j < MAX_THREADS; j++)
		pthread_join(thid[j], NULL);

	pthread_attr_destroy (&attr);

	return 0;
}


