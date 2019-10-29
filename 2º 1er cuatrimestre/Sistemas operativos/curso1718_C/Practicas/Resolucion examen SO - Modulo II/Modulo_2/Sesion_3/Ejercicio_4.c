#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc, char *argv[]) {
    
	const int NUM_HIJOS = 5;
	int i,status;
	pid_t pid[NUM_HIJOS];
    
    printf("--------------------------------\n");

	for (i=0; i<NUM_HIJOS;i++){
		if ((pid[i]=fork())==0) {
			printf("Soy el hijo %d \n\n",getpid());
			break;
		}
		else if (pid[i]<0){
			perror("Error al crear la hebra hijo\n");
			exit(-1);
		}
	}

	for (i = 0;i<NUM_HIJOS;i++) {
		if (waitpid(pid[i],&status,0) > 0) {                  
	    		printf("Acaba de finalizar mi hijo con PID:%d\n\n",pid[i]);
	    		printf("Solo me quedan %d hijos vivos\n\n",NUM_HIJOS - (i+1));
                if((NUM_HIJOS - (i+1)) == 0){
                    printf("Finalizando mi ejecucion porque no me quedan hijos vivos\n");
                    printf("--------------------------------\n");
                }
    		}
	}


} 
