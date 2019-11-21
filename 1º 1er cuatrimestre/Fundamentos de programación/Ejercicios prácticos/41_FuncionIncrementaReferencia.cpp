/*

	(C)Algebro.

  Implementacion de un funcion incrementa que recibe
	una variable entera por referencia para aumentarla en uno.

*/

#include <iostream>

using namespace std;



void Incrementa(int& valor){
	valor += 1;
}



int main(){


	int numero;

	cout << "Valor inicia de numero : ";
	cin >> numero;

	Incrementa(numero);

	cout << "\nNumero incrementado : " << numero << endl;


	return 0;
}

/*
		En detalle
		---------------

		Incrementa modifica la variable 'numero' directamente
		desde donde se llama.

		Normalmente (paso por parámetro) se recibe un valor que se almacena
		en una variable nueva local a la función, una copia del valor original.
		Si en función modificamos esa variable, la original no se modifica.
		En el paso por referencia (utilizando '&') la variable original
		sí se ve modificada.


*/
