/*

	(C)Algebro.


	Realizacion de una suma, almacenando las Variables
	en un Array de tamanio 2.

*/

#include <iostream>

using namespace std;


int main(){


	double variables[2];		//Indicamos el tipo, que es un array (vector), y su tamanio.
	double resultado;

	cout << "Introducir valor para Variable A : ";
	cin >> variables[0];		//primera posicion

	cout << "Introducir valor para Variable B: ";
	cin >> variables[1];	//segunda posicion

	resultado = variables[0] + variables[1];


	cout << "La suma de A=" << variables[0] << " y B=" << variables[1]
		<< " es " << resultado << endl;


	return 0;
}

/*
		En detalle
		---------------

		Para declarar un Array (vector), usamos la siguiente sintaxis

		TIPO_DATOS	NOMBRE_VECTOR  [ TAMANIO ]


		Un array es un tipo de dato estrucutado que almacena un conjunto
		de datos del mismo tipo denominados elementos.
		Para acceder a las posiciones de dicho vector, usamos un valor entero positivo
		denominado indice, que indica la posicion del elemento dentro del vector;
		por ejemplo,

		char vector[10];
		int indice = 3;
		vector[indice] = 'A';

		produce un array con 10 casillas de tipo caracter (char),
		y accede al elemento 4º (posicion 3) para fijar su valor a 'A'.

*/
