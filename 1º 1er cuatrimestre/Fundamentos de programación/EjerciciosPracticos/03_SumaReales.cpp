/*

	(C)Algebro.

  A partir del ejercicio 02 (Suma Sencilla Entrada) modificacion que
	permite el uso de decimales (numeros racionales) cambiando el tipo de dato.
*/

#include <iostream>

using namespace std;


int main(){


	double variableA;
	double variableB;
	double resultado;

	cout << "Introducir valor para Variable A (real): ";
	cin >> variableA;		//Lee un dato de tipo REAL (con decimales)

	cout << "Introducir valor para Variable B (real): ";
	cin >> variableB;		//Lee un dato de tipo REAL (con decimales)

	resultado = variableA + variableB;		//Resultado (double) almacena el resultado de sumar ambas variables.


	cout << "La suma de A=" << variableA << " y B=" << variableB
		<< " es " << resultado << endl;


	return 0;
}

/*
		En detalle
		---------------

		Los datos de tipo double al igual que los de tipo float,
    nos permiten almacenar numeros con decimales.



*/
