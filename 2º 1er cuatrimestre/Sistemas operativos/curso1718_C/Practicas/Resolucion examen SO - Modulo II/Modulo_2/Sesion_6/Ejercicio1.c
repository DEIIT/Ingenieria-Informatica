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

	int n_param = 0; //numero de parametros
	char redir; //tipo de redireccionamiento
	char **params; //Orden linux y sus parametros
	char *path; //path del que leer|escribir
	int pth = 0;//bool
	int fd;
	pid_t pid;





	params = (char**) malloc (argc * sizeof(char*));

	for (int i = 1; i < argc; i++){//Empezamos en 1 porque argv[0] es el nombre del ejecutable...
		if( (argv[i][0] != '<') && (argv[i][0] != '>') && (!pth)){
			params[n_param] = (char*)malloc (strlen(argv[i]) * sizeof(char));
			strcpy(params[n_param],argv[i]);
			n_param++;
		}
		else{
			if (pth){
				path = (char*)malloc (strlen(argv[i]) * sizeof(char));
				strcpy(path,argv[i]);
			}
			else{
				redir = (argv[i][0] == '<') ? '<' : '>';
				pth = 1;
			}

		}
	}

	if ( (pid = fork()) == -1 ){
		perror("Error en fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0){ //Hijo
		if (redir == '<'){
			params[n_param] = path;
			n_param++;

			if((fd = open(path,O_RDONLY)) == -1){//Abrimos el archivo "path" en modo lectura
				perror("Error en open");
				exit(EXIT_FAILURE);
			}

			close(0);//CERRAMOS LA ENTRADA ESTANDAR

			if(fcntl(fd,F_DUPFD,0) == -1){//Redireccionamos la entrada estandar con el descriptor abierto
				perror("Error al redireccionar la entrada estandar con fcntl");
				exit(EXIT_FAILURE);
			}

			if(execvp(params[0],params) == -1){
				perror("Error en execvp");
				exit(EXIT_FAILURE);
			}
		}

		else{

			if ( (fd = open(path,O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU|O_CLOEXEC)) == -1){
				perror("Error en open");
				exit(EXIT_FAILURE);
			}

			close(1); //CERRAMOS LA SALIDA ESTANDAR

			if(fcntl(fd,F_DUPFD,1) == -1){//Redireccionamos la salida estandar con el descriptor abierto
				perror("Error al redireccionar la salida estandar con fcntl");
				exit(EXIT_FAILURE);

			}

			if(execvp(params[0],params) == -1){
				perror("Error en execv");
				exit(EXIT_FAILURE);
			}

		}
	}

	//LIBERAMOS MEMORIA:
	for (int i = 0; i < n_param; i++)
		free(params[i]);
	free(params);
	free(path);


	return 0;
}
