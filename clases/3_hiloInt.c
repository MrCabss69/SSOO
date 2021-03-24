#include <pthread.h>
#include <stdio.h>

void *func(void *p) {
	int *par = (int *) p;
	printf("Thread %d. Valor: %d \n", (int) pthread_self(),*par);
	pthread_exit(NULL);
}

int main(void) {
	int valor=15;
	pthread_attr_t attr;
	pthread_t miHilo;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_create(&miHilo, &attr, &func, &valor);

	pthread_join(miHilo, NULL);

	pthread_attr_destroy (&attr);
	return 0;
}


