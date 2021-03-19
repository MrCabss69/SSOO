//ejercicio 1 marzo 2018
//Implementar en C el método incrementa_archivo que abre el archivo dado como argumento y redirige la entrada y salida estándar a dicho archivo
int main(int argc, char * argv[]){
	int fich;
	fich = open(argv[1], O_RDRW|O_CREAT,0666);
	switch(fich){
		case -1:
			printf("Error, no se pudo abrir el archivo de redirección");
			perror("open"); // se imprime error por la salida stderr 
			exit(1);
			break;
		default:
			printf("Se abrió correctamente el fichero de redirección!");
			dup2(fich,0); // redirección de entrada estandar(0) al fichero(fich)
			dup2(fich,1); // redirección de salida estandar(0) al fichero(fich)
			break;
	}
	// A través de descriptores estándar sumar 5 al entero contenido en la posición de memoria 3Gigabytes del archvo
#define POS(3UL*(1<<30))
	int offset = lseek(0, POS, SEEK_SET); // lseek redirecciona el puntero de lectura ( descriptor_archivo, n_bytes , se coloca en n_bytes con seek_set)
	if(offset = -1){
		fprint("Ha habido un error de posicionamiento de puntero");
		perror("lseek1");
	}
	int v = 0;
	int cnt = read(0,&val,sizeof(int)); //  read() trata de leer hasta 'count' bytes del fichero al que apunta fd(en este caso el fichero al q hemos redirigido la entrada estandar 0) y lo guarda en la direccion de memoria en la que está almacenado val
	if( cnt = -1){
		fprint("Ha habido un error de lectura");
		perror("read");
		int offset = lseek(1,-cnt,SEEK_CUR);
		// off_t lseek(int fildes, off_t offset, int whence);
		// con la opción SEEK_CUR: El número de bytes indicado en offset se suma a la dirección actual y el puntero se coloca en la dirección resultante.
	}
	if( offset = -1 ){
		fprint("Ha habido un error de resposicionamiento del cursor");
		perror("lseek2");
		v = v + 5;
		cnt = write( 1, &val , sizeof(int));
	}
	if( cnt == 1){
		perror("write")
	}
	return 0;

}