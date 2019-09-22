/*

	(C)Algebro.

	Calculo de la media de una secuencia de numeros introducidos
	por consola.

*/

#include <iostream>

using namespace std;




int main(){


 	double numero;
	int introducidos=0;
	double media;

	cout << "Introducir numero (0 para finalizar): ";
	cin >> numero; 	//lectura adelantada

	while(numero!=0){

		media+=numero;
		introducidos += 1;

		cout << "\nIntroducir numero (0 para finalizar): ";
		cin >> numero;
	}

	if(introducidos>0)
		cout << "Media : " << media/introducidos << endl;
	else
		cout << "Ningún numero introducido.";

	return 0;
}

/*
		En detalle
		-----------------------

		La lectura adelantada nos permite realizar 0 ejecucciones.
		Si el primer dato es el terminador (el que sea),
		el programa debe funcionar correctamente.

		De la misma manera, el terminador no debe
		considerarse como un dato valido (salvo excepciones...)
		De manera que la cadena  1,2,3,0. contiene tres datos válidos,
		y por tanto la media debe ser 2, y no 1.5.



*/
