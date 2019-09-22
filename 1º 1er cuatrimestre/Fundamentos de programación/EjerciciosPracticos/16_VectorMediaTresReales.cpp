/*

	(C)Algebro.

  Actualizacion del ejercicio 06 (Media Tres Reales)
	haciendo uso de un array.
*/

#include <iostream>

using namespace std;


int main(){


	const int TAM = 3;
	double numeros[TAM];
	double media;

	cout << "Introducir tres numeros reales : ";
	cin >> numeros[0];
	cin >> numeros[1];
	cin >> numeros[2];

	media =  (numeros[0]+numeros[1]+numeros[2])/3;


	cout << endl << "La media es " << media << endl;


	return 0;
}

/*
		En detalle
		---------------




*/
