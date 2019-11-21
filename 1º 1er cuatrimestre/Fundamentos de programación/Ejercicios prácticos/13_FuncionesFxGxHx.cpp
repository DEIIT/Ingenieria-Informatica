/*

	(C)Algebro.

	Actualizacion del ejercicio 09 (CalculoFxGxHx)
	aplicando cadena de funciones para simplificarlo.

  Dada tres funciones matemáticas f(x),g(x) y h(x) calcular el valor obtenido
	para una x indicada por consola de h(x)

	Funciones:
		f(x) = x^2 + 2*x - 3
		g(x) = f(x+1) - f(x-1)
		h(x) = (g(x) + g(-x))/2

*/

#include <iostream>

using namespace std;

double  Calcula_F(double val_x){
	return val_x * val_x + 2*val_x - 3;
}

double  Calcula_G(double val_x){
	return Calcula_F(val_x+1) - Calcula_F(val_x-1);
}

double  Calcula_H(double val_x){
	return (Calcula_G(val_x) + Calcula_G(-val_x))/2;
}


int main(){


	double valor_x;

	cout << "Introducir el valor de x: ";
	cin >> valor_x;

	cout << "Valor de h(" << valor_x << ") = " << Calcula_H(valor_x) << endl;


	return 0;
}

/*
		En detalle
		---------------




*/
