#include <pthread.h>
#include <stdio.h>

#define MAX_THREADS 10
#define TAM_CADENA 50

void *func(void *p) {
	char *par = (char *)p;
	printf("Thread %d. Cadena: %s \n", (int) pthread_self(), par);
	pthread_exit(NULL);
}

int main(void) {
	int j;
	pthread_attr_t attr;
	pthread_t thid[MAX_THREADS];
	char cadenas[MAX_THREADS][TAM_CADENA];

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	for(j = 0; j < MAX_THREADS; j++){
		sprintf(cadenas[j],"Valor: %d",j);
		pthread_create(&thid[j], &attr, &func, &cadenas[j]);
	}

	for(j = 0; j < MAX_THREADS; j++)
		pthread_join(thid[j], NULL);

	pthread_attr_destroy (&attr);
	return 0;
}


