#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct sumandos {
	int sum1;
	int sum2;
};

int sumatotal;

void *sumar(void *p) {
	struct sumandos *par = (struct sumandos *)p;

	sumatotal =  (*par).sum1 + (*par).sum2;

	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	int j;
	pthread_attr_t attr;
	pthread_t miHilo;
	struct sumandos sum;

	if (argc !=3){
		fprintf(stderr,"Error. Uso: ./9_hiloSumadorSal val1 val2\n");
		return 1;
	}

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	sum.sum1 = atoi(argv[1]);
	sum.sum2 = atoi(argv[2]);
	
	pthread_create(&miHilo, &attr, &sumar,&sum);

	pthread_join(miHilo,NULL);

	printf("La suma es: %d\n",sumatotal);

	pthread_attr_destroy (&attr);
	return 0;
}


