#include <pthread.h>
#include <stdio.h>

struct sumandos {
	int sum1;
	int sum2;
};

void * imprimir_suma(void *p){
	struct sumandos *s = (struct sumandos *)p;
	int suma = s->sum1 + s->sum2;
	//Equivale a: int suma = (*s).sum1 + (*s).sum2;
	printf("Suma: %d\n", suma);	
	pthread_exit(NULL);
}

int main(void){

	struct sumandos sum;
	sum.sum1 = 55;
	sum.sum2 = 20;

	pthread_t miHilo;
	pthread_attr_t atributos;

	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_JOINABLE);

	pthread_create(&miHilo,&atributos,&imprimir_suma,&sum);

	pthread_join(miHilo,NULL);	
	
	pthread_attr_destroy (&atributos);
	
	return 0;
}
