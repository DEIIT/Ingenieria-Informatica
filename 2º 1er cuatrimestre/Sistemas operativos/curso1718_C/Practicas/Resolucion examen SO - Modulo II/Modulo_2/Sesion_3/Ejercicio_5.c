#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc, char *argv[]) {
    
	const int NUM_HIJOS = 5;
	int i, status_par,status_impar;
	pid_t pid[NUM_HIJOS];
    pid_t pid_inicial = getpid();
    
    
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
	
// Esperando por los hijos pares (0,2,4) que son el orden impar (1,3,5)

	for (i = 0;i<NUM_HIJOS;i+=2) {
		if (waitpid(pid[i],&status_impar,0) > 0) {                  
	    		printf("Acaba de finalizar mi hijo con PID:%d de orden:%d\n\n",pid[i], pid[i] - pid_inicial);
	    		printf("Solo me quedan %d hijos vivos\n\n",NUM_HIJOS - (i+1));
        }
    }
	
// Esperando por los hijos impares (1,3) que son el orden par (2,4)

	for (i = 1;i<NUM_HIJOS;i+=2) {
		if (waitpid(pid[i],&status_par,0) > 0) {                  
	    		printf("Acaba de finalizar mi hijo con PID:%d de orden:%d\n\n",pid[i], pid[i] - pid_inicial);
	    		printf("Solo me quedan %d hijos vivos\n\n",NUM_HIJOS - (i+1));
                if((NUM_HIJOS - (i+1)) == 0){
                    printf("Finalizando mi ejecucion porque no me quedan hijos vivos\n");
                    printf("--------------------------------\n");
                }
        }
    }
	



} 
