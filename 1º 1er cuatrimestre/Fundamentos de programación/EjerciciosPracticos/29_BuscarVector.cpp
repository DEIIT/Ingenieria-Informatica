/*

	(C)Algebro.

	A partir de un vector de enteros preinicializado (Ver ejercicio 15 o 23)
	buscar un valor concreto en el.


*/

#include <iostream>

using namespace std;




int main(){

	int datos[] = {7,3,9,11,15,23,19,6,13,2,9,20};
	const int TAMANIO = 12;

	int numero;
	bool encontrado=false;
	cout << "Numero a buscar : ";
	cin >> numero;

	for(int i=0; i<TAMANIO && !encontrado; i++)
				encontrado = numero == datos[i];

	if(encontrado)
		cout << "\nEncontrado.\n";
	else
		cout << "\nNo encontrado.\n";



	return 0;
}

/*
		En detalle
		-----------------------




*/
