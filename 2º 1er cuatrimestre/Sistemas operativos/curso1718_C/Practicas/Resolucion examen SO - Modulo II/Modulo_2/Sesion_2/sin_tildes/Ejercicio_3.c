#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<dirent.h>

int archivos_x_other_group = 0;
int sumatoria_bytes = 0;


void funcion_lectura(char *pathname);


int main(int argc, char **argv){
    
    char cwd[1024];
    char *pathname;
    int err;

    //Comprobamos que el numero de argumentos sea 2...
    //...Si lo es cogemos ese directorio para trabajar
	if(argc==2){
		pathname=argv[1];
	}
	//...Si no cogemos el directorio actual para trabajar
    else{
        getcwd(cwd, sizeof(cwd));
        pathname=cwd;
    }
    
    printf("\nLos i-nodos son:\n");

    funcion_lectura(pathname);
    
    printf("\nExisten %d archivos regulares con permisos de ejecucion para Grupo y Otros\n", archivos_x_other_group);
    
	
    printf("\nEl tamanio total ocupado por dichos archivos es %d bytes\n",
           sumatoria_bytes);
    
	return 0;
}

void funcion_lectura(char *pathname){
    DIR *directorio;
	struct stat atributos;
	struct dirent *directorio_actual;
    int longitud = strlen(pathname)+1;
    
    
    
    //Asignamos el directorio
    directorio=opendir(pathname);
    
    //Leemos el directorio puesto
	readdir(directorio);
	
    //Entramos en el bucle leyendo lo que hay dentro del directorio
	while((directorio_actual=readdir(directorio))!=NULL)
	{
        int total_utilizados = longitud+strlen(directorio_actual->d_name);
        char cadena[total_utilizados];
        //Imprimimos en la variable "cadena" la direccion del archivo actual
		sprintf(cadena, "%s/%s" ,pathname,directorio_actual->d_name);
		
        //Comprobamos si podemos obtener los atributos del directorio contenido en "cadena"
		if(stat(cadena,&atributos) < 0)
		{
			printf("\nError fallo al acceder a los permisos\n");
			perror("\nError en lstat");
            
		}
		// Tambien se puede usar strcmp((&cadena[longitud]), ".") != 0;
		else if(strcmp((&directorio_actual->d_name[0]), ".") != 0){
            //Si es un archivo regular...
            if(S_ISREG(atributos.st_mode)){
                //...imprime su i-nodo
                printf("%s: %o \n", cadena, atributos.st_ino);
                //Suma los bytes a la variable global
                sumatoria_bytes+=atributos.st_size;
                
                //Comprueba si tiene permisos de ejecucion para "Otros"
                if(atributos.st_mode & S_IXOTH){
                    //Comprueba si tiene permisos de ejecucion para "Grupo"
                    if(atributos.st_mode & S_IXGRP){
                        //Suma a la variable global uno
                        archivos_x_other_group++;
                    }
                
                }
            }
            //...si no lo es y no tiene un punto delante del nombre del nodo
            else if(S_ISDIR(atributos.st_mode)){
                //... y ademas es un directorio
                {
                //Llamar de nuevo a la funcion pasando el directorio
                    funcion_lectura(cadena);
                }
            }
        }
        
    }
    //Se cierra el directorio
    closedir(directorio);
    
}
