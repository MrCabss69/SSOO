#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	pid_t pid;
	int estado;

	if (argc<2){
		printf("Error. Uso: %s ejec [par]\n", argv[0]);
		return 1;
	}

	pid = fork();
	if (pid < 0 ){
		perror("fork()");
		return 1;
	}
	if (pid == 0) {
		// Proceso hijo
		execvp(argv[1], &argv[1]);
		perror("exec()");
		return 1;
	}
	else {
		// Proceso padre
		wait(&estado);
                if (WIFEXITED(estado))
                        printf("El hijo ha finalizado correctamente con el valor: %d\n",WEXITSTATUS(estado));
                else if (WIFSIGNALED(estado))
                        printf("El hijo ha muerto por la recepción de una señal con el valor: %d\n", WTERMSIG(estado));
        }

	return 0;

}
