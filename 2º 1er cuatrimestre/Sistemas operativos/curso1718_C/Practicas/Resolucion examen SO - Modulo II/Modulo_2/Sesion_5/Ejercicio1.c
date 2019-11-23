/*
 reciboSignal.c
 Trabajo con llamadas al sistema del Subsistema de Procesos conforme a POSIX 2.10
 Utilizacion de la llamada sigaction para cambiar el comportamiento del proceso       
 frente a la recepcion de una senial.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
static void sig_USR_hdlr(int sigNum) 
  {

    if(sigNum == SIGUSR1)
    printf("\nRecibida la senial SIGUSR1\n\n");
    else if(sigNum == SIGUSR2)
    printf("\nRecibida la senial SIGUSR2\n\n"); 
   }

// CREO UN MANEJADOR DE SEniALES, "static" denota que la funcion solo es visible en el archivo donde se define

int main(int argc, char *argv[])
   {
    struct sigaction sig_USR_nact;
    if(setvbuf(stdout,NULL,_IONBF,0)) //DESACTIVAMOS EL BUFFERING PARA LA SALIDA ESTADAR DEL PROCESO
       {
    perror("\nError en setvbuf");
       }

//Inicializar la estructura sig_USR_na para especificar la nueva accion para la senial.

sig_USR_nact.sa_handler= sig_USR_hdlr; 



//'sigemptyset' inicia el conjunto de seniales dado al conjunto vacio. 

sigemptyset (&sig_USR_nact.sa_mask);
sig_USR_nact.sa_flags = 0;

//Establecer mi manejador particular de senial para SIGUSR1
if( sigaction(SIGUSR1,&sig_USR_nact,NULL) <0) 
    {
perror("\nError al intentar establecer el manejador de senial para SIGUSR1");
exit(-1);
    }
//Establecer mi manejador particular de senial para SIGUSR2
if( sigaction(SIGUSR2,&sig_USR_nact,NULL) <0) 
 {
perror("\nError al intentar establecer el manejador de senial para SIGUSR2");
exit(-1);
    }
for(;;)
   {
   }
}

/*###############################################################################*/
/*
 envioSignal.c
 Trabajo con llamadas al sistema del Subsistema de Procesos conforme a POSIX 2.10
 Utilizacion de la llamada kill para enviar una senial:
 0: SIGTERM
 1: SIGUSR1
 2: SIGUSR2
  a un proceso cuyo identificador de proceso es PID.
 SINTAXIS: envioSignal [012] <PID> 
*/


#include <sys/types.h> //POSIX Standard: 2.6 Primitive System Data Types 
// <sys/types.h>
#include <limits.h> //Incluye <bits/posix1_lim.h> POSIX Standard: 2.9.2 //Minimum    //Values Added to <limits.h> y <bits/posix2_lim.h>
#include <unistd.h> //POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
int main(int argc, char *argv[])
 {
          long int pid;
          int signal;
          if(argc<3) {
          printf("\nSintaxis de ejecucion: envioSignal [012] <PID>\n\n");
          exit(-1);
           }
         pid= strtol(argv[2],NULL,10);
         if(pid == LONG_MIN || pid == LONG_MAX) 
           {
         if(pid == LONG_MIN)
         printf("\nError por desbordamiento inferior LONG_MIN %d",pid);
         else
            printf("\nError por desbordamiento superior LONG_MAX %d",pid);
            perror("\nError en strtol");
            exit(-1);
           }
        signal=atoi(argv[1]);
        switch(signal) {
            case 0: //SIGTERM
            kill(pid,SIGTERM); break;
            case 1: //SIGUSR1
            kill(pid,SIGUSR1); break;
            case 2: //SIGUSR2
            kill(pid,SIGUSR2); break;
            default : // not in [012]
            printf("\n No puedo enviar ese tipo de senial"); 
              }
}

/**envioSignal envia una senial (solo envia las seniales "SIGTERM", "SIGUSR1", "SIGUSR2") a un proceso que se le pasa como argumento
  reciboSignal es un programa en un bucle infinito que tiene programadas un manejador de seniales,
  este programa maneja las seniales que envia el programa anteriormente descrito... (el manejador de seniales, lo unico que hace es mostrar
  pantallazos por la salida estandar del proceso...)
*/
