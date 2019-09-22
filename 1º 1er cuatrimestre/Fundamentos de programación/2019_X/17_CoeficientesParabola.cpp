/*

	(C)Algebro.

  Haciendo uso de un vector para almacenar los coeficientes a,b,c;
	calcular el valor de f(x) = a*x^2 + b*x + c
	para diferentes valores prefijados de X.
	Haciendo uso de una funcion CalcularF(coeficientes[3], X).
*/

#include <iostream>

using namespace std;


double Calcular_F(double coeficientes[3], double x){
	return coeficientes[0]*x*x + coeficientes[1]*x + coeficientes[2];
}


int main(){


	double valores_x[] = {-3, -1, 0, 1, 3};
	double coefs[3];

	cout << "Introducir tres coefs reales coeficientes : ";
	cin >> coefs[0];
	cin >> coefs[1];
	cin >> coefs[2];


	cout << "F(" << valores_x[0] << ") = " << Calcular_F(coefs, valores_x[0]) << endl
		<< "F(" << valores_x[1] << ") = " << Calcular_F(coefs, valores_x[1]) << endl
		<< "F(" << valores_x[2] << ") = " << Calcular_F(coefs, valores_x[2]) << endl
		<< "F(" << valores_x[3] << ") = " << Calcular_F(coefs, valores_x[3]) << endl
		<< "F(" << valores_x[4] << ") = " << Calcular_F(coefs, valores_x[4]) << endl;


	return 0;
}

/*
		En detalle
		---------------

		Observamos que se repite valores_x[indice] en varias ocasiones.
		E iguales que observamos en el ejercicio 08 (Salario Anual),
		la utilizacion de algun comportamiento ciclico que fuese variando
		dicho indice desde el 0 hasta el 4, nos reduciria el código y nos permitiria
		extenderlo cuanto deseasemos.


*/
