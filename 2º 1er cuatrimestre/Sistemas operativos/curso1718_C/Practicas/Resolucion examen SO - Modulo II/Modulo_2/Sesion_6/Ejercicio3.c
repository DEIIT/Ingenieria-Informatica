#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main (int argc, const char *argv[])
{
	struct flock cerrojo;
	int fd;

	if( (fd = open("test.txt",O_CREAT|O_TRUNC|O_WRONLY,S_IRWXU)) == -1){
		perror("Error en open");
		exit(EXIT_FAILURE);
	}


	cerrojo.l_type = F_WRLCK;
	cerrojo.l_whence = SEEK_SET;
	cerrojo.l_start = 0;
	cerrojo.l_len = 0;

	fork();

	if (fcntl(fd,F_SETLK,&cerrojo) == -1){ //FORZAMOS EL INTERBLOQUEO PARA VER SI EL KERNEL ES CAPAZ DE DETECTARLO
		perror("Error en fcntl");
		exit(EXIT_FAILURE);
	}

	sleep(3);



	return 0;
}
