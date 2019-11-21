/*

	(C)Algebro.

	A partir del ejercicio 33 (Suma Sencilla Entrada Struct) vamos
	a realizar una copia del struct para modificarla como
	si se tratase de una variable normal.

*/

#include <iostream>

using namespace std;


struct ParNumero{
	int variableA;
	int variableB;
};

int main(){


	ParNumero par, copia;

	cout << "Introducir valor para Variable A : ";
	cin >> par.variableA;

	cout << "Introducir valor para Variable B : ";
	cin >> par.variableB;


	copia = par;		// Copia atributo a atributo.
	copia.variableA += par.variableB;
	copia.variableB *= par.variableA;

	cout << "La suma de A=" << par.variableA << " y B=" << par.variableB
		<< " es " << copia.variableA << endl
		<< "El producto de A=" << par.variableA << " y B=" << par.variableB
		<< " es " << copia.variableB << endl;


	return 0;
}

/*
		En detalle
		---------------

		El acceso de una variable struct siempre tiene la misma forma:

		nombre_variable_struct.nombre_atributo;

		Los atributos de cualquier struct pueden ser modificados y consultados
		con total libertad, pero depende siempre de la variable que los engloba.

*/
