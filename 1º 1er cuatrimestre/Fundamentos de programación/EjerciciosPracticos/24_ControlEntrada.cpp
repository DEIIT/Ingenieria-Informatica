/*

	(C)Algebro.

	Realizacion de un control de entrada  de manera
	que forcemos al usuario a introducir un valor
	entre un rango concreto.

*/

#include <iostream>

using namespace std;




int main(){

	const int LIMIT_INF = 0;
	const int LIMIT_SUP = 20;
	int entrada;

	do{
		cout << "\nIntroducir un valor entre " << LIMIT_INF << " y " << LIMIT_SUP << " : ";
		cin >> entrada;
	}while(entrada < LIMIT_INF || entrada > LIMIT_SUP); 	//condicion para mantener el bucle.


	cout << "Introducido " << entrada << endl;


	return 0;
}

/*
		En detalle
		---------------

		Con un bucle do-while forzamos que haya al menos una ejecuccion,
		y si es necesario, que se ejecute un numero mayor de veces.


*/
