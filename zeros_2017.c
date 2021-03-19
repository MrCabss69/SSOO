
//codificar en C un programa que crea un archivo que contenga exactamente 23502 bytes nulos.
char buf[23502];
int main(int argc, char * argv[]){
	int file = creat("ZEROS",0666);
	int w = write(file,buf,sizeof(buf));
	return 0;
}