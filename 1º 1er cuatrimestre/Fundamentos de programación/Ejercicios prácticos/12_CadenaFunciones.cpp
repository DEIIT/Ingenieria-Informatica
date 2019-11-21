/*

	(C)Algebro.

  Haciendo uso de Cadena de funciones,
	para las funciones Doble y Cuadrado,
	se va a demostrar la desigualdad de

	2(x^2) !=  (2x)^2

*/

#include <iostream>

using namespace std;


//Definicion de la funcion Cuadrado, que recibe un numero real
//y devuelve el cuadrado de dicho numero
double Cuadrado(double a){
	return a*a;
}

//Definicion de la funcion Doble, que recibe un numero real
//y devuelve el producto de 2 y el valor recibido.
double Doble(double a){
	return 2*a;
}


int main(){


	double variableX;

	cout << "Introducir valor para X : ";
	cin >> variableX;

	cout << "Calculando primero la potencia : " << Doble(Cuadrado(variableX)) << endl
		<< "Calculando primero el producto : " <<  Cuadrado(Doble(variableX)) << endl;


	return 0;
}

/*
		En detalle
		---------------




*/
