/*

	(C)Algebro.

  A partir del ejercicio 10 (Funcion Suma)
	modificado para dar el resultado por referencia.

*/

#include <iostream>

using namespace std;



void Sumar(double a, double b, double& resultado){
	resultado = a+b;
}



int main(){


	double variableA;
	double variableB;
	double resultado;

	cout << "Introducir valor para Variable A (real): ";
	cin >> variableA;

	cout << "Introducir valor para Variable B (real): ";
	cin >> variableB;

	Sumar(variableA,variableB, resultado);


	cout << "La suma de A=" << variableA << " y B=" << variableB
		<< " es " << resultado << endl;


	return 0;
}

/*
		En detalle
		---------------

		Como resultado es una referencia, al modificarla
		se ve alterado su valor desde la funcion main.


*/
