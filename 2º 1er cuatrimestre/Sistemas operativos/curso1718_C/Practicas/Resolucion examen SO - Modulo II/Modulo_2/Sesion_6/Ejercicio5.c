#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <dirent.h>


/**
 * @brief Metodo para ajustar una ruta
 * @details si en @e rutaizq proporcionamos el string "Escritorio" y
 * en @e rutader proporcionamos "Jose" la salida de la funcion es el ajuste
 * de una ruta de la siquiente manera: "./Escritorio/Jose/"
 * Cabe la posibilidad de que el metodo genere rutas "././ruta" o "././ruta1/./ruta2" pero siguen siendo rutas validas
 * para el sistema
 */

char *AjustarRuta(const char * rutaizq, const char * rutader)
{
	char *final_pathName;
	int tam = strlen(rutaizq) + strlen (rutader) + 10;


	final_pathName = (char*)malloc (tam * sizeof(char));

	strcpy(final_pathName,"./");
	strcat(final_pathName,rutaizq);

	if( rutaizq[strlen(rutaizq) - 1] != '/' )
		strcat(final_pathName,"/");

	strcat(final_pathName,rutader);


	return final_pathName;
}


/**
* @brief Metodo para copiar un archivo en una ruta dada
* @param fd  Es el descriptor del archivo
* @param fd_name  es el nombre del archivo
* @param dir_destino  es ruta destino a donde se quiera copiar el archivo
* @pre @e fd debe de ser el descriptor del archivo que tiene mo como nombre fd_name
* y debe de estar ya ABIERTO, fd_name ES EL NOMBRE DEL ARCHIVO UNICAMENTE, no debe pasarse con el nombre
* una ruta de directorios... EL directorio con nombre dir_destino debe existir y ser una ruta valida del sistema
*/

void copiarArchivo(int * fd,const char * fd_name,const char *dir_destino)
{
	char *map;
	char *final_pathName;
	struct stat info_fd;
	int fd_dup;


	if (fstat( *fd, &info_fd ) == -1){
		perror("Error en fstat");
		exit(EXIT_FAILURE);
	}


	final_pathName = AjustarRuta(dir_destino,fd_name);

	fd_dup = open(final_pathName,O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
	if (fd_dup == -1){
		printf("Error al crear el Archivo %s en la ruta %s\n",fd_name,dir_destino );
		exit(EXIT_FAILURE);
	}

	if (info_fd.st_size != 0){ //SI EL FICHERO ESTA VACIO NO HACEMOS MAP NI WRITE
		map = (char *) mmap (NULL, info_fd.st_size, PROT_READ, MAP_SHARED, *fd, 0);

		if (map == MAP_FAILED){
			printf("Fallo en el mapeo del fichero %s\n",fd_name );
			exit(EXIT_FAILURE);
		}

		if( write( fd_dup, map,info_fd.st_size )  == -1){
			printf("Error al escribir en el fichero %s\n",final_pathName );
			exit( EXIT_FAILURE );
		}
	}
}


/**
 * @brief Metodo para copiar un directorio y su contenido
 *
 * @param dir_acopiar ruta del directorio que se copiara
 * @param dir_destino ruta del directorio donde se hara la copia.
 */

void copiarDirectorio(const char * dir_acopiar,const char *dir_destino)
{
	struct dirent ** listaficheros;
	int n_ficheros;
	int fd;
	struct stat info_fd;
	char *final_pathName;
	char *nombrefdAjustado;
	mode_t permisos = 0777;
	int es_directorio;




	n_ficheros = scandir( dir_acopiar, &listaficheros, NULL, alphasort );//escaneamos el directorio

	if( n_ficheros == -1 ){
		printf("Error al escanear el direcorio %s\n", dir_acopiar );
		exit(EXIT_FAILURE);
	}



	//CREAMOS UN DIRECTORIO CON EL NOMBRE DEL DIRECTORIO QUE ESTAMOS ESCANEADO EN LA RUTA dir_destino
	if (mkdir(dir_destino, permisos) == -1){
		printf("Error al crear el directorio %s\n",dir_destino );
		exit(EXIT_FAILURE);
	}




	for (int i = 2; i < n_ficheros; i++){ //Empezamos en 2 para evitar procesar lo directorios "." y ".."

		nombrefdAjustado = AjustarRuta( dir_acopiar, listaficheros[i]->d_name );

		printf("copiando: %s\n", nombrefdAjustado );

		fd = open( nombrefdAjustado, O_RDONLY );

		if (fd == -1){
			printf("Error al abrir el fichero %s\n",listaficheros[i]->d_name );
			exit( EXIT_FAILURE );
		}

		if ( fstat( fd, &info_fd ) == -1){
			printf("Error al obtener la informacion del fichero %s\n", listaficheros[i]->d_name );
			exit( EXIT_FAILURE );
		}


		es_directorio = ( S_ISDIR( info_fd.st_mode ) ) ? 1 : 0;//Compramos si es un directorio


		if ( es_directorio ){
			final_pathName = AjustarRuta(dir_destino,listaficheros[i]->d_name);
			copiarDirectorio( nombrefdAjustado, final_pathName );
		}
		else
			copiarArchivo (&fd, listaficheros[i]->d_name,dir_destino);
	}
}




int main (int argc, char * const argv[])
{
	if (argc != 3){
		printf("USO: %s <Archivo o direcorio a copiar> <Ruta destino donde se copiara>\n",argv[0] );
		return 1;
	}

	int fd;
	char *pathAcopiar = argv[1]; //nombre del archivo o direcotorio a copiar
	char *pathDestino = argv[2]; //nombre del directorio donde se copiara
	struct stat info_fd;
	int es_directorio;




	fd = open( pathAcopiar, O_RDONLY );
	if (fd == -1){//abrimos el archivo o directorio a copiar
		perror( "Error en open al abrir el descriptor de archivo a copiar" );
		exit( EXIT_FAILURE );
	}

	if ( fstat( fd, &info_fd ) == -1){
		perror( "Error al obtener informacion sobre el descriptor de archivo a copiar" );
		exit( EXIT_FAILURE );
	}

	es_directorio = ( S_ISDIR( info_fd.st_mode ) ) ? 1 : 0;//Compramos si es un directorio;


	if ( es_directorio )
		copiarDirectorio( pathAcopiar, AjustarRuta(pathDestino,pathAcopiar) );
	else{
		if ( strrchr(pathAcopiar,'/') != NULL )//Por si el archivo nos lo pasan con una ruta...
			pathAcopiar = strrchr(pathAcopiar,'/') + 1; //OBTENEMOS EL NOMBRE DEL ARCHIVO SIN LA RUTA..., EL +1 DENOTA QUE EL PUNTERO AVANCE UNA POSICION

		copiarArchivo ( &fd, pathAcopiar,pathDestino);
	}


	return 0;
}
