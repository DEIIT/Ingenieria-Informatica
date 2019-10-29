#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<dirent.h>


int main(int argc, char **argv){
    
    DIR *directorio;
	unsigned int permisos;
	char *pathname;
	struct stat atributos;
	struct dirent *directorio_actual;
	char cadena[512];
	char cadena2[512];
	int err;

    //Comprobamos que el numero de argumentos sea el correcto
	if(argc==3)
	{
		pathname=argv[1];
		directorio=opendir(pathname);
		permisos=strtol(argv[2],NULL,8);
	}
	//Si no lo es, se para la ejecucion y se muestra como ejecutar
	else
	{
		printf("%s <pathname> <permisos> \n", argv[0]);
		exit(-1);
	}
    
    //Leemos el directorio puesto como argumento
	readdir(directorio);
	
    //Entramos en el bucle leyendo lo que hay dentro del directorio
	while((directorio_actual=readdir(directorio))!=NULL)
	{
        //Imprimimos en la variable "cadena" la direccion del archivo actual
		sprintf(cadena, "%s/%s" ,pathname,directorio_actual->d_name);
		
        //Comprobamos si podemos obtener los atributos del directorio contenido en "cadena"
		if(stat(cadena,&atributos) < 0)
		{
			printf("\nError fallo al acceder a los permisos");
			perror("\nError en lstat");
			exit(-1);
		}
		//Comprobamos si es un archivo regular
		if(S_ISREG(atributos.st_mode))
		{
            //Imprimimos en "cadena2" el nombre del archivo regular
			sprintf(cadena2,"%s", directorio_actual->d_name);

            //Imprimimos el nombre y los atributos de proteccion del archivo
			printf("%s: %o ", cadena2, atributos.st_mode);
            
            //Cambiamos los permisos del directorio contenido en "cadena"
            //(que es en realidad la direccion absoluta de "cadena2")
			chmod(cadena,permisos);
			
            //Si hay error en cambiarlos se muestra...
			if(chmod(cadena,permisos) < 0) 
			{
				printf("Error: %s\n",strerror(errno));
			}
			//...Si no mostramos los nuevos cambios hechos
			else
			{
				stat(cadena,&atributos);
				printf("%o \n",atributos.st_mode);
			
			}
		}

	}
	closedir(directorio);
	return 0;
}
