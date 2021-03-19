//ejercicio 1 del año 2018
//mandato: anular fich pos tam
// escribir el programa anular fich pos tam, el cual emite por la salida estandar parte del contenido actual del archivo fich consistente en tam (bytes) a partir de la posición pos del archivo
// luego reescribe esa parte del archivo con bytes nulos
// usar int atoi(char*str);
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
int main(int arg, char*argv[]){
	//se abre el archivo 
	int fd_fich = open(argv[1],O_RDWR);
	if( fd_fich = -1 ){
		perror("open");
		exit(1);
	}
	int pos = atoi(argv[2]);
	int tam = atoi(argv[3]);
	int cnt;
	int ret;
	char buffer[tam];

	//lseek puntero en pos 
	int ret = lseek(fd_fich,pos,SEEK_SET);
	cnt = read(fd_fich,buffer,tam);
	ret = write(1,buffer,cnt);
	
	//se imprime por salida estandar
	ret = lseek(fd,-cnt,SEEK_CUR);
	for (int i = 0; i < cnt; ++){
		buffer[i]= '\0'; // se sobrescribe el buffer con bytes nulos
	}
	ret = write(fd,buf,cnt);
	close(fd);

	return 0;
	
}