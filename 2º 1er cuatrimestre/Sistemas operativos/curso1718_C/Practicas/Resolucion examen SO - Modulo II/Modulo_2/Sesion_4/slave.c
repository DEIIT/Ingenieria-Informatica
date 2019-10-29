#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>




int main (int argc, char* argv[])
{
	if(argc != 3){
		printf( "USO:%s <cota_inf> <cota_sup>\n", argv[0] );
		exit(EXIT_FAILURE);
	}


	long int cota_inf = strtol( argv[1], NULL, 10 );
	long int cota_sup = strtol( argv[2], NULL, 10 );
	int divisible;


	

	if (cota_inf > cota_sup){
		printf("Error cota_sup no puede ser menor que cota_sup\n");
		exit (EXIT_FAILURE);
	}

	printf("Los numeros primos comprendidos entre [%li,%li] son :\n", cota_inf, cota_sup );

	for (long int i = cota_inf; i <= cota_sup; i++){
		divisible = 0;
		
		for (double k = 2; k <= sqrt( (double)i ) && !divisible; k++)
			if (!(i % (long int)k ))
				divisible = 1;

		if (!divisible && i != 1 && i != 0)
			printf("%li ", i);
	}


	return 0;
}
