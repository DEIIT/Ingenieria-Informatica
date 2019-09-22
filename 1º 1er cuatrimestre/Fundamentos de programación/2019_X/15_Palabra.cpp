/*

	(C)Algebro.


	Haciendo uso de un Array con valores iniciales prefijados,
	modificar sus elementos para cambiar el resultado.

*/

#include <iostream>

using namespace std;


int main(){


	char palabra[] = {'c','a','s','a'};		//No se indica el tamanio ya que esta implicito en la inicializacion
	int indice;

	cout << "Introducir la posicion a modificar (comienza en 0) : ";
	cin >> indice;

	cout << "Introducir la nueva letra en la posicion " << indice << " : ";
	cin >> palabra[indice];


	cout << "Palabra resultante : " << palabra << endl;		//las cadenas de caracteres pueden mostrarse directamente.


	return 0;
}

/*
		En detalle
		---------------

		Si inicializamos el vector en su creacion (asignar unos valores iniciales)
		no se requiere de especificar el numero de elementos, ya que es
		implicito a la declaracion.

		Normalmente las cadenas de caracteres se finalizan con un caracter de control
		'\0' que indica el fin de la cadena para facilitar el procesamietno de cadenas
		de forma que la cadena "Hola" realmente es "Hola\0".

*/
