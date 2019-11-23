#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]){
	int i,status,tamanio_args,bg;
	pid_t pid1;

    //Calculando el espacio de los argumentos del ejecutable
    // y viendo si se ejecuta en segundo plano
    if((strcmp(argv[argc-1],"bg") == 0)){
        tamanio_args = argc - 1;
        bg = 1;
    }
    else{
        tamanio_args = argc;
        bg = 0;
    }
    
    //Una vez que se ha calculado los argumentos que necesitamos
    //declaramos la variable
    char *argv_exec[tamanio_args];
    
    //Introduccion de todos los argumentos del otro ejecutable
    for (i=1; i < tamanio_args-1; i++){
        argv_exec[i-1] = argv[i];
    }
    
    //IMPORTANTE: se debe introducir al final de los argumentos un "NULL" para que se ejecute correctamente
    argv_exec[tamanio_args-1] = NULL;
    
    //Si bg == 0 sera false, si es bg == 1 ejecutara lo que hay en el if 
    if(bg){
        if ((pid1=fork())==0) {
			printf("Soy el hijo %d que va a ejecutar el proceso %s en segundo plano\n\n",getpid(), argv[1]);
			execv(argv[1],argv_exec);
		}
		else if (pid1==-1){
			perror("Error al crear la hebra hijo\n");
			exit(-1);
		}
		else{
            int status;
            if( waitpid(pid1, &status, 0) < 0 ) {
                perror("wait");
                exit(254);
            }
            if(WIFEXITED(status)) {
                printf("Proceso %d devolvio %d\n", pid1, WEXITSTATUS(status));
                exit(WEXITSTATUS(status));
            }
        }
    }
    else{
        execv(argv[1],argv_exec);
    }
}  
