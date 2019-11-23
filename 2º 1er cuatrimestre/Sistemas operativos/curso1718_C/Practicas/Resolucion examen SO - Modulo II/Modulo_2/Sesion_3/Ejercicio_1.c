#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


void comprobacion_par(int valor){
    if(valor%2 == 0) printf("\nEl hijo ha comprobado que este valor es par\n");
    else printf("\nEl hijo ha comprobado que este valor es impar\n");
}


void comprobacion_4(int valor){
    if(valor%4 == 0) printf("\nEl padre ha comprobado que este valor es divisible entre 4\n");
    else printf("\nEl padre ha comprobado que este valor no es divisible entre 4\n");
}


int main (int argc, char** argv){
    
    if(argc==2){
        //Se crea una nueva hebra hijo que se ejecuta aqui
        pid_t pid = fork();
        
        int numero = atoi(argv[1]);
        //Si el numero es 0, significa que es el hijo
        if(pid == 0)
            comprobacion_par(numero);
        else
            comprobacion_4(numero);
        
    }
    else
        printf("\nMal numero de argumentos: %s <numero entero positivo>\n", argv[0]);
    
    return 0;
    
}
