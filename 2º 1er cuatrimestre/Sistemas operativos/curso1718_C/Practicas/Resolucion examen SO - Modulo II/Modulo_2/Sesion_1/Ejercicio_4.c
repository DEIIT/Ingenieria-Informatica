#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>


#define S_ISREG2(mode) (mode & S_IFMT == S_IFREG)

int main(int argc, char*argv[]){
	struct stat atributos;
	int stat_num;

	if(argc != 2) {
		fprintf(stderr, "\nNumero argumentos incorrectos\n");
		exit(-1);
	}
	if((stat_num = stat(argv[1], &atributos)) < 0) {
		perror("ERROR");
		exit(-1);

	}
	else{
		if(S_ISREG(atributos.st_mode)){
			printf("\nEs Regular\n");
		}
		else{
			printf("\nNo es Regular\n");
		}
	}
}
