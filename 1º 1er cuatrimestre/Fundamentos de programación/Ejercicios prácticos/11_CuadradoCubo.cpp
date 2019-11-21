/*

	(C)Algebro.

  Uso de funciones para definir
	Cuadrado(x) = x^2
	y
	Cubo(x) = x^3

*/

#include <iostream>

using namespace std;


//Definicion de la funcion Cuadrado, que recibe un numero real
//y devuelve el cuadrado de dicho numero
double Cuadrado(double a){
	return a*a;
}

//Definicion de la funcion Cubo, que recibe un numero real
//y devuelve el cubo de dicho numero
double Cubo(double a){
	//Tambien podriamos usar la funcion Cuadrado.
	return a*a*a;
}


int main(){


	double variableX;

	cout << "Introducir valor para X : ";
	cin >> variableX;

	cout << variableX << " al cuadrado es " << Cuadrado(variableX) << endl
		<< variableX << " al cubo es " << Cubo(variableX) << endl;


	return 0;
}

/*
		En detalle
		---------------

		Una opcion para implementar la funcion Cubo es utilizar
		la funcion Cuadrado.
		De manera que en lugar de hacer x*x*x,
		el valor devuelto se calculase como  Cuadrado(x)*x




*/
