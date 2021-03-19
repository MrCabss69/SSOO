//este programa debe imprimir por salida estándar, todo lo que reciba por la entrada estandar usando un buffer de 1024b

int main(void){
	char buffer[1024];
	int cnt;
	while((cnt = read(0,buffer,1024)) >0){ // se lee de la entrada estandar (0) 
		write(1,buffer,cnt); // se saca el buffer por la salida estandar (1)
	}
	return 0;
}