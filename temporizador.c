//escribir para C el programa temporizar con el siguiente uso:
//	temporizar segundos mandato [args..]
// la función del programa es limitar el numero de segundos al que está limitado la ejecución de mandato.
// a) el mandato indicado se pone ene ejecución en un proceso hijo con los argumentos indicados
// b) si el usuario pulsa crtl-c el mandato "mandato" debe morir, pero el proceso padre(temporaizar),no
// c) Si el proceso hijo(mandato) no finaliza antes de segundos, el padre debe indicarle que termine su ejecución mediante un envío de señal
// d) De no haber finalizado el hijo en el instante segundos+1, el padre debe matarlo.

int pid;
int senyal = SIGTERM;

void timeout(int s){
	kill(pid,senyal);
	senyal = SIGKILL;
}
void Ctrl_C(int s){
	kill(pid,SIGKILL);
}
int main(int argc, char * argv[]){
	int status;
	int seconds = atoi(argv[1]);
	stuct sigaction act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	act.sa_handler = Ctrl_C;
	sigaction(SIGINT,&act,NULL); // The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.
	// SIGINT -> se envia al proceso cuando se pulsa ctrl durante la ejecución del mismo

	//se ejecuta el mandato en un proceso hijo
	switch( pid = fork() ){
		case -1:
			perror();
			exit(1);
			break;
		case 0:
			execvp(argv[2],&argv[2]); // el mandato a ejecutar es pasado al programa como argv[2]
			break;
		default:
			//proceso padre
			// control de terminación del proceso hijo
			act.sa_handler = timeout;
			sigaction(SIGALARM,&act,NULL); 
			// SIGALARM -> se envia al proceso cuando se recibe una alarma la ejecución del mismo
			// en este caso lee la dirección de memoria del struct para setear la acción a relizar cuado se reciba dicha alarma
			alarm(seconds);
			while(pid != wait(&status)){
				continue;
			}
			
			alarm(0);
	// está pendiente el apartado e) del ejercicio. 

	}
	return 0;

 }
