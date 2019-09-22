/*

	(C)Algebro.

	Dado un numero por consola, contar un determinado numero de veces,
	desde 0 hasta otro numero indicado por consola.

	Por ejemplo:  "Contar hasta 10, 4 veces..."

*/

#include <iostream>

using namespace std;


int main(){


	int tope, rep;
	cout << "Introducir tope : ";
	cin >> tope;
	cout << "Introducir repeticiones : ";
	cin >> rep;

	for(int repetidor=0; repetidor<rep; repetidor++){
		for(int contador=0; contador<tope; contador++){
			cout << contador << " ";
		}
		cout << endl;
	}




	return 0;
}

/*
		En detalle
		---------------

		Si lo comparamos con el ejercicio 22 (Contar),
		vemos que la diferencia es que indicamos un
		numero de veces que se va a repetir la cuenta.

*/
