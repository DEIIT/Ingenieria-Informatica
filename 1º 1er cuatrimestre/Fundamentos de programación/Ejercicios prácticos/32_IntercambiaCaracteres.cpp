/*

	(C)Algebro.

	Dada una frase intercambia un caracter por otro.

	Frase ejemplo: Antonio, coma panes que estan muy ricos.
	Caracter a cambiar: a   Caracter sustituto: e


*/

#include <iostream>

using namespace std;




int main(){

	const int TAMANIO = 50;
	char datos[TAMANIO];

	int introducidos=0;
	char car, sust;

	cout << "Introducir una frase : ";
	car = cin.get();
	while(introducidos < TAMANIO-1 && car != '\n'){
		datos[introducidos] = car;
		introducidos += 1;

		car = cin.get();
	}
	datos[introducidos] = '\0'; 	//Terminador de la cadena.

	cout << "\nCaracter a buscar : ";
	cin >> car;
	cout << "\nCaracter sustituto : ";
	cin >> sust;

	for(int i=0;i<introducidos;i++)
		if(datos[i]==car)
			datos[i]=sust;

	cout << "Frase final : " << datos << ".\n";

	return 0;
}

/*
		En detalle
		-----------------------


		Normalmente las cadenas de caracteres se finalizan con un caracter de control
		'\0' que indica el fin de la cadena para facilitar el procesamietno de cadenas
		de forma que la cadena "Hola" realmente es "Hola\0".

*/
