/*

	(C)Algebro.

	A partir del ejercicio 01 (Suma Sencilla) con el añadido
	de entrada de datos desde consola
*/

#include <iostream>

using namespace std;


int main(){


	int variableA;
	int variableB;
	int resultado;

	cout << "Introducir valor para Variable A : ";
	cin >> variableA;		//Lee un dato (en nuestro caso, un entero) almacenándolo en A.

	cout << "Introducir valor para Variable B: ";
	cin >> variableB;		//Lee un dato (en nuestro caso, un entero) almacenándolo en B.

	resultado = variableA + variableB;		//Resultado (int) almacena el resultado de sumar ambas variables.


	cout << "La suma de A=" << variableA << " y B=" << variableB
		<< " es " << resultado << endl;


	return 0;
}

/*
		En detalle
		---------------

		cin  nos sirve para leer por consola (introducir datos) que queramos
		que el usuario introduzca.

		Más adelante, de forma externa al programa, se podría redireccionar para
		que los datos los coja de un fichero de texto.



*/
