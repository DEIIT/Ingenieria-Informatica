/*

	(C)Algebro.

  Utilizando un struct para almacenar el maximo y el minimo,
	encontrarlos dado una secuencia de numeros.
*/

#include <iostream>

using namespace std;

struct Tope{
	double max, min;
};

int main(){


	Tope topes;
	double num;


	cout << "Introducir numeros reales (0 para finalizar) : ";
	cin >> num;
	topes.min = topes.max = num;

	while(num != 0){
		if(num > topes.max)
			topes.max = num;
		else if(num < topes.min)
			topes.min = num;

		cin >> num;
	}


	cout << "\nEl minimo es " << topes.min
		<< "\nEl maximo es " << topes.max << endl;


	return 0;
}

/*
		En detalle
		---------------




*/
