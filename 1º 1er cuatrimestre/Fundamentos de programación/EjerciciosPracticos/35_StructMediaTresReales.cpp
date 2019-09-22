/*

	(C)Algebro.

  Actualizacion del ejercicio 16 (Vector Media Tres Reales)
	haciendo uso de un struct en lugar de un array.
*/

#include <iostream>

using namespace std;

struct Triada{
	double A,B,C;
};

int main(){


	Triada numeros;
	double media;

	cout << "Introducir tres numeros reales : ";
	cin >> numeros.A;
	cin >> numeros.B;
	cin >> numeros.C;


	media =  (numeros.A+numeros.B+numeros.C)/3;


	cout << "\nLa media es " << media << endl;


	return 0;
}

/*
		En detalle
		---------------




*/
