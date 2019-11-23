#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int leidos, i = 1;
	int filein,fileout;
	char buffer[81];

	if (argc==2)
	{
		filein=open(argv[1], O_RDONLY);
	}
	else
	{
		filein=STDIN_FILENO;
	}
	
	fileout=open("archivo_salida", O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR);
	
	if (fileout < 0)
	{
		printf("El fichero de salida no se pudo abrir correctamente\n");
		exit(-1);
	}
     
	while((leidos=read(filein,buffer,80))>0)
	{
            //Inicializacion de la escritura 
            //de bloque despues de cada iteracion al bucle
            char bloque_cons[12] = "//Bloque ";
            
            //Almacenamiento de la variable 'i'
            char numero[2];
            
            //Conversion de 'i' a char
            sprintf(numero, "%d", i);
            
            //Concatenar el numero de 'i'
            strcat(bloque_cons, numero);
            
            //Concatenar el salto de linea en el bloque
            strcat(bloque_cons, "\n");
            
            //Se escribe la cadena 'bloque_cons' desde 0 a 'sizeof(bloque_cons)-1'
            //para evitar escribir el caracter nulo
            write(fileout, bloque_cons, sizeof(bloque_cons)-1);
            
            //Concatenar el salto de linea en buffer
            strcat(buffer, "\n");
            
            //Se escriben los 80 bytes (81 con el salto de linea)
            write(fileout, buffer, leidos);
            
            //Incrementamos el iterador
            i++;
    }

	close(filein);
	close(fileout);
	return 0;
}
