/*

	(C)Algebro.

  Definicion e implementacion de la clase Numero.

	Atributo público.

*/

#include <iostream>

using namespace std;

typedef int tipo;		//nos permite cambiar el tipo de forma uniforme.

class Numero{
	public:
		tipo numero;
};


int main(){

	Numero a;
	a.numero = 3;

	cout << "Introducir un valor : ";
	cin >> a.numero;

	cout << "Valor : " << a.numero << endl ;

	return 0;
}

/*
		En detalle
		---------------


*/
