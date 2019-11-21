/*

	(C)Algebro.

  A partir del ejercicio 03 (SumaReales)
	vamos a implementar una funcion Suma,
	para realizar dicho calculo.

*/

#include <iostream>

using namespace std;


//Definicion de la funcion Suma, que recibe dos numeros reales y devuelve
//el resultado de dicha suma.
double Sumar(double a, double b){
	return a+b;
}



int main(){


	double variableA;
	double variableB;
	double resultado;

	cout << "Introducir valor para Variable A (real): ";
	cin >> variableA;

	cout << "Introducir valor para Variable B (real): ";
	cin >> variableB;

	resultado = Sumar(variableA,variableB);


	cout << "La suma de A=" << variableA << " y B=" << variableB
		<< " es " << resultado << endl;


	return 0;
}

/*
		En detalle
		---------------

		Las funciones tiene una estructura fija

		TIPO_DATO_DEVUELTO		NOMBRE_FUNCION	(TIPO_PARAMETRO1 NOMBRE_PARAMETRO1, TIPO_PARAMETRO2 NOMBRE_PARAMETRO2, ...){

			...OPERACIONES_REQUERIDAS...

			return  VALOR_DEVUELTO
		}



*/
