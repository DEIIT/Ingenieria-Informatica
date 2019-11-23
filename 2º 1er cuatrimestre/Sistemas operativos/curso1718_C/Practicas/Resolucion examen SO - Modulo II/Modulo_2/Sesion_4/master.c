#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main (int argc, char* argv[])
{
	//CREAMOS UN PROCESO HIJO QUE COMPILE EL PROGRAMA EXCLAVO
	int id;
	if( (id = fork()) == -1 ){
		perror("Error en fork()");
		exit(EXIT_FAILURE);
	}
	else if (!id){
    //COMPILAMOS EL ESCLAVO
		if (execlp("gcc","gcc","slave.c","-o","slave","-lm",NULL) == -1){
			perror("Error en execlp()");
			exit (EXIT_FAILURE);
		}
	}
	//ESPERAMOS AL HIJO, ASI NOS ASEGURAMOS QUE EL ARCHIVO EJECUTABLE SE HA CREADO
	int status_2;
	if( waitpid(id, &status_2, 0) < 0){
        perror("wait");
    }
    
	//EL NUMERO DE HIJOS COMO ARGUMENTO
	if (argc != 4){
		printf("USO: %s <cota_inf> <cota_sup> <num_esclavos>\n", argv[0] );
		exit(EXIT_FAILURE);
	}

	//EL NUMERO DE HIJOS COMO ARGUMENTO
	int NUM_SLAVES = strtol(argv[3],NULL,10); //NUMERO DE HIJOS QUE TENDRA EL PROCESO PARA REPARTIR CALCULOS EQUITATIVAMENTE
	int *fd[NUM_SLAVES];
	int *FD;
	int cota_inf = strtol(argv[1],NULL,10);
	int cota_sup = strtol(argv[2],NULL,10);
	int acumulador;
	const int incremento = ((cota_sup - cota_inf)/NUM_SLAVES);
	int hijo = 0;
	int pid;

	if (cota_inf > cota_sup || cota_sup < 0){
		printf("%s\n", "Error cota_inf no puede ser mayor que cota_sup o negativa\n" );
		exit(EXIT_FAILURE);
	}

	//EL REDIMENSIONADO EN FUNCION DE NUM_SLAVES
	for (int i = 0; i < NUM_SLAVES; i++){
		fd[i] = malloc( NUM_SLAVES * sizeof(int));
		pipe (fd[i]);
	}


	for (int i = 0, acumulador = cota_inf; i < NUM_SLAVES && !hijo ; i++ , acumulador += incremento){
		if ( (pid = fork()) == -1 ){
			perror("Error en fork()");
			exit(EXIT_FAILURE);
		}

		if (!pid){
			if(i == 0)//si el primer proceso 
				cota_inf = acumulador;
			else
				cota_inf = acumulador + 1;
			
			cota_sup = acumulador + incremento;

			FD = fd[i];

			hijo = 1; //el hijo sale del bucle en la siguiente iteraciOn
		}
	}


	if (!pid){ //cOdigo ejecutado por los hijos
		close(FD[0]); //cerramos el descriptor de lectura en el cauce
		close(STDOUT_FILENO);

		//Establecemos la salida estAndar del proceso al descriptor de escritura del cauce
		dup2(FD[1],STDOUT_FILENO);



		char cota_sup_toString[256];
		char cota_inf_toString[256];

		sprintf(cota_sup_toString,"%i", cota_sup);
		sprintf(cota_inf_toString, "%i", cota_inf);

		if ( execl("./slave","./slave",cota_inf_toString,cota_sup_toString,NULL) == -1 ){
			perror("Error en execl");
			exit(EXIT_FAILURE);
		}
	}
	else{//cOdigo ejecutado por el padre
		for (int i = 0; i < NUM_SLAVES; i++)
			close(fd[i][1]); //cerramos el descriptor de escritura para el padre
		const int BYTES = 500;

		char buffer[BYTES]; //leeremos un mAximo de 500 BYTES
		int *status;



		while (1){

			for (int i = 0; i < NUM_SLAVES; i++){
				
				for (int i = 0; i < BYTES; i++)
					buffer[i] = 0;//limpiamos el buffer.


				if ( read(fd[i][0],buffer,BYTES) == -1){
					perror("Error en read()");
					exit(EXIT_FAILURE);
				}

				printf("%s\n",buffer);
			}

			if ( wait(status) == -1)
					return 0;
		}
	}



	return 0;
}
