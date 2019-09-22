/*

	(C)Algebro.

	Utilizando un struct para contabilizar el numero de apariciones
	de una caracter cualquiera, contar cuantas veces se repite dicho caracter.

*/

#include <iostream>

using namespace std;


struct Aparicion{
	char vocal;
	int aparicion=0;
};

int main(){


	Aparicion apariciones[5];
	apariciones[0].vocal = 'a';
	apariciones[1].vocal = 'e';
	apariciones[2].vocal = 'i';
	apariciones[3].vocal = 'o';
	apariciones[4].vocal = 'u';

	char car;

	cout << "Introducir una frase : ";
	car = cin.get();
	while(car != '\n'){
		/*
			Forma simple, más intuitiva.

		if(car == 'a')
			apariciones[0].aparicion++;
		else if(car == 'e')
			apariciones[1].aparicion++;
		else if(car == 'i')
			apariciones[2].aparicion++;
		else if(car == 'o')
			apariciones[3].aparicion++;
		else if(car == 'u')
			apariciones[4].aparicion++;
		*/

		/*
			Forma compacta, haciendo uso de la inicializacion del struct
		*/

		for(int i=0;i<5;i++)
			if(car == apariciones[i].vocal)
				apariciones[i].aparicion++;

		car = cin.get();
	}


	for(int i=0;i<5;i++)
		cout << "Caracter " << apariciones[i].vocal << " aparece " << apariciones[i].aparicion << endl;


	return 0;
}

/*
		En detalle
		---------------



*/
