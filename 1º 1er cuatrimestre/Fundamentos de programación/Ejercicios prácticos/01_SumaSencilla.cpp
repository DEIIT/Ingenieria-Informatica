/*

	(C)Algebro.

	Programa simple que muestra una primera toma de contacto
	con unas variables y un calculo muy sencillo.
*/

#include <iostream>		//Nos permite utilizar 'cout' y 'cin', para salida y entrada de datos (respectivamente)

using namespace std;	//Define el espacio de nombres std.


int main(){				//Función principal de uso obligatorio. Nuestro programa comenzará ejecutándose por aquí.


	int variableA = 5;	//VariableA es un entero (int) con valor 5.
	int variableB = 3;	//VariableB es un entero (int) con valor 3.
	int resultado;

	resultado = variableA + variableB;		//Resultado (int) almacena el resultado de sumar ambas variables.


	cout << "La suma de A=" << variableA << " y B=" << variableB
		<< " es " << resultado << endl;


	return 0;			//Con un 0 indicamos al sistema que se ha ejecutado nuestro programa correctamente.
}


/*
		En detalle
		---------------

		Las variables nos permiten almacenar y modificar datos durante la ejecuccion
		de nuestro programa.

		A la hora de mostrar un mensaje con cout  separamos las diferentes partes
		(variables, cadenas de texto, constantes, etcétera) con el operador <<


*/
