#include <stdio.h>
#include <signal.h>
#include <unistd.h> 
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>



int main (int argc, char * argv[])
{
	sigset_t mask1;


	sigfillset(&mask1);
	sigdelset(&mask1, SIGUSR1);

	printf("Lanzado el proceso con PID %i\nUsar la senial SIGUSR1 para que el proceso continue su ejecucion\n", getpid() );
	if ( (sigsuspend(&mask1) ) == -1){
		perror("error en sigsuspend");
		exit(EXIT_FAILURE);
	}

	
	return 0;
}