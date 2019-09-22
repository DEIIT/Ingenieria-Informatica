/*

	(C)Algebro.

  A partir del ejercicio 11 (Cuadrado Cubo)
	actualizado para
	si el numero introducido es mayor que cero, calcular su cuadrado,
	si el numero introducido es menor que cero, calcular su Cubo
	si el numero introducido es cero, escribir "Es cero."

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

	if(variableX > 0)
		cout  << variableX << " al cuadrado es " << Cuadrado(variableX) << endl;
	else if(variableX < 0)
		cout << variableX << " al cubo es " << Cubo(variableX) << endl;
	else
		cout << "Es cero." << endl;


	return 0;
}

/*
		En detalle
		---------------

		



*/
