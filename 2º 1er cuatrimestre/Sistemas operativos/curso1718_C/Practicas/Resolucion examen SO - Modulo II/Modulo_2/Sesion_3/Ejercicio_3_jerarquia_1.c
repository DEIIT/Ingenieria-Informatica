#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_PROC 20

void main(int argc, char *argv[]){
	int i,status;
	pid_t pid1, pid2;

	// Jerarquia de procesos tipo 1
	// Cada hijo genera a su vez otro hijo

	printf("PID inicial: %d \n",getpid());
    
    printf("--------------------------------\n");

	for (i=0;i<NUM_PROC;i++){
		if ((pid1 = fork()) == 0){
			printf("\nHijo de %d y PID es %d \n",getppid(),getpid());
		}
		else if (pid1 < 0) {
			printf("\nNo se pudo crear el hijo.\n");
			return;			
		} 
		/*
         * La funcion waitpid suspende la ejecucion del proceso en curso hasta que
         * un  hijo especificado por el argumento pid ha terminado, o hasta que se
         * produce una senial cuya accion es finalizar el proceso actual o llamar a
         * la funcion manejadora de la senial
         */ 
		else if (pid2=waitpid(pid1,&status,0) >0) {
			break;
		}

	}
	
} 
