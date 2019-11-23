#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

const int SIGCOUNT = 64; //Numero de seniales en el SO.
int * contador;//vector de enteros dinamico destinado a contar el numero de veces que es envida una senial

//Manejador de seniales
static void handler (int nSignal)
{
	if( 0 < nSignal && nSignal <= SIGCOUNT){
		contador[nSignal-1]++;
		printf("Se ha mandado la senial numero %i, %i veces.\n", nSignal, contador[nSignal-1] );
	}
}



int main (int argc, char* argv[])
{
	contador = (int *)malloc(sizeof(int)*SIGCOUNT);
	struct sigaction action; 



	for (int i = 0; i < SIGCOUNT; i++)
		contador[i] = 0;
 
	
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	
	for (int i = 1; i <= SIGCOUNT; i++) //Establecemos las seniales
		if ( (sigaction(i, &action, NULL) ) == -1 )
			printf("No puedo manejar la senial %i\n", i);

	while (1){}/*BUCLE INFINITO*/
}