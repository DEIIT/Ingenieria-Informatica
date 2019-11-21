/*

	(C)Algebro.

	A partir del ejercicio 02 (Suma Sencilla Entrada) haciendo uso
	de un struct ParNumerico para almacenar ambos numeros

*/

#include <iostream>

using namespace std;


struct ParNumero{
	int variableA;
	int variableB;
};

int main(){


	ParNumero par;		//Creacion de una variable de tipo ParNumero

	cout << "Introducir valor para Variable A : ";
	cin >> par.variableA;

	cout << "Introducir valor para Variable B: ";
	cin >> par.variableB;


	cout << "La suma de A=" << par.variableA << " y B=" << par.variableB
		<< " es " << par.variableA+par.variableB << endl;


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
