//BUENO VARGAS, GUILLERMO
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main (int argc, char* argv[])
{
	int *pcut[2];
	int *FD;
	int fileout;

	char *lista=getenv("PATH");

	//LANZAMOS EL HIJO PARA CREAR LISTABUSQUEDA
	int id;
	if( (id = fork()) == -1 ){
		perror("Error en fork()");
		exit(EXIT_FAILURE);
	}
	else if (!id){
		int leidos = strlen(lista);
		fileout=open("listabusqueda", O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR);
		if (fileout < 0)
		{
			printf("El fichero de salida no se pudo abrir correctamente\n");
			exit(-1);
		}
		write(fileout, lista, leidos);
		close(fileout);
	}

	//ESPERAMOS AL HIJO, ASI NOS ASEGURAMOS QUE EL ARCHIVO LISTABUSQUEDA SE HA CREADO
	int status_2;
	if( waitpid(id, &status_2, 0) < 0){
        	perror("wait");
 	}


	//EL REDIMENSIONADO
	for (int i = 0; i < 2; i++){
		pcut[i] = malloc( 2 * sizeof(int));
		pipe (pcut[i]);
	}
	
	FD = pcut[0];


	//LANZAMOS EL SEGUNDO HIJO PARA QUE EJECUTE CUT
	int id_2;
	if( (id_2 = fork()) == -1 ){
		perror("Error en fork()");
		exit(EXIT_FAILURE);
	}
	else if (!id_2){
		close(FD[0]); //cerramos el descriptor de lectura en el cauce
		close(STDOUT_FILENO);

		//Establecemos la salida estAndar del proceso al descriptor de escritura del cauce
		dup2(FD[1],STDOUT_FILENO);

		if (execlp("cut","cut","-d:","-f",argv[2],"-z","listabusqueda",NULL) == -1){
			perror("Error en execlp()");
			exit (EXIT_FAILURE);
		}
		
	}

	else{
		close(FD[1]);
		char rutadir[PATH_MAX];
		int status;

		if ( read(FD[0],rutadir,PATH_MAX) == -1){
			perror("Error en read()");
			exit(EXIT_FAILURE);
		}

		//CONCATENAMOS LA CADENA
		strcat(rutadir,"/");
		strcat(rutadir,argv[1]);


		struct stat atributos;


		if(stat(rutadir,&atributos) >= 0){
			printf("\nDirectorio encontrado: %ld bytes, %u id_usuario_propietario, %u id_grupo_propietario \n", atributos.st_size, atributos.st_uid, atributos.st_gid);
		}


		int id_3;

		if( waitpid(id_3, &status_2, 0) < 0 ) {
		        perror("wait");
		        exit(254);
            	}

		//Si ls devuelve 0 indica que no esta en el directorio
		if(WIFEXITED(status_2) == 0){
		        printf("Proceso %d devolvio %d\n", id_2, WEXITSTATUS(status));
		}


		if( waitpid(id_2, &status, 0) < 0 ) {
		        perror("wait");
		        exit(254);
            	}

		if(WIFEXITED(status)){
		        printf("Proceso %d devolvio %d\n", id_2, WEXITSTATUS(status));
		}

	}


	return 0;
}
