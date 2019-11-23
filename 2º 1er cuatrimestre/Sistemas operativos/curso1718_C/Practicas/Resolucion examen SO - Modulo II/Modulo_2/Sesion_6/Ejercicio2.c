#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (int argc,const char* argv[])
{
	if (argc < 3){
		printf("USO: %s <Orden de linux> <REDIRECCIONAMIENTO> <Nombre de Archvivo>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	int n_paramder = 0; //numero de parametros del array paramsder
	int n_paramizq = 0; //numero de parametros del array paramsizq
	char **paramsder; //Orden linux y sus parametros de la parte derecha del cauce
	char **paramsizq; //Orden linux y sus parametros de la parte izquierda del cauce
	int parder = 0;
	int *fd;//DESCRIPTORES PARA EL CAUCE SIN NOMBRE
	pid_t pid;


	

	//Reserva de memoria y ajustes iniciales...
	fd = (int*) malloc (2 * sizeof(int));
	paramsder = (char**) malloc (argc * sizeof(char*));
	paramsizq = (char**)malloc (argc * sizeof(char*));

	for (int i = 1; i < argc; i++){//Empezamos en 1 porque argv[0] es el nombre del ejecutable... 
		if( parder){
			paramsder[n_paramder] = (char*)malloc (strlen(argv[i]) * sizeof(char));
			strcpy(paramsder[n_paramder],argv[i]);
			n_paramder++;
		}
		else{
			if(argv[i][0] == '|')
				parder = 1;
			else{
				paramsizq[n_paramizq] = (char*)malloc (strlen(argv[i]) * sizeof(char));
				strcpy(paramsizq[n_paramizq],argv[i]);
				n_paramizq++;
			}
		}
	}


	//ABRIMOs CAUCE

	if (pipe(fd) == -1){
		perror ("Error en pipe");
		exit(EXIT_FAILURE);
	}


	if ( (pid = fork()) == -1 ){
		perror("Error en fork");
		exit(EXIT_FAILURE);
	}


	if (pid == 0){//hijo
		close(fd[1]); //Cerramos el cauce para escritura

		if (fcntl(fd[0],F_DUPFD,0) == -1){ //redireccionamos la entrada estandar con el cauce para lectura
			perror("Error en fcntl");
			exit(EXIT_FAILURE);
		}

		if (execvp(paramsder[0],paramsder) == -1){
			perror("Error en execvp");
			exit(EXIT_FAILURE);
		}

	}
	else{
		close(fd[0]); //Cerramos el cauce para lectura

		if(fcntl(fd[1],F_DUPFD,1) == -1){//redireccionamos la salida estandar con el cauce para escritura
			perror("Error en fcntl");
			exit(EXIT_FAILURE);
		}

		if(execvp(paramsizq[0],paramsizq) == -1){
			perror("Error en execvp");
			exit(EXIT_FAILURE);
		}
	}


	//LIBERAMOS MEMORIA:
	for (int i = 0; i < n_paramder; i++)
		free(paramsder[i]);
	for (int i = 0; i < n_paramizq; i++)
		free(paramsizq[i]);
	free(paramsizq);
	free(paramsder);
	free(fd);


	return 0;
}