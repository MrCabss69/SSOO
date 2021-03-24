#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define MAX_THREADS 10

struct param {
	char msg[50];
	int num;
};

void *func(void *p) {
	struct param *par = (struct param*) p;
	printf("Thread. Msg: %s. Num: %d \n", par->msg, par->num);
	pthread_exit(NULL);
}

int main(void) {
	int j;
	struct param pars[MAX_THREADS];
	pthread_attr_t attr;
	pthread_t thid[MAX_THREADS];

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	for(j = 0; j < MAX_THREADS; j++){
		strcpy(pars[j].msg,"Hola");
		pars[j].num=j;
		pthread_create(&thid[j], &attr, &func,&pars[j] );
	}

	for(j = 0; j < MAX_THREADS; j++)
		pthread_join(thid[j], NULL);

	pthread_attr_destroy (&attr);

	return 0;
}


