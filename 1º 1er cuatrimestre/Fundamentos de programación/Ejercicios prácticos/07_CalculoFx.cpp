/*

	(C)Algebro.

  Dada una función matemática f(x), calcular el valor obtenido
	para una x indicada por consola.

	Funcion: f(x) = x^3 - x^2 + 2*x - 1
*/

#include <iostream>

using namespace std;


int main(){


	double valor_x;
	double resultado;

	cout << "Introducir el valor de x: ";
	cin >> valor_x;

	//  Lo siguiente no muy buena opcion, ya que es poco legible y repetimos mucho un mismo calculo :
	//  		resultado = valor_x * valor_x * valor_x - valor_x * valor_x + 2 * valor_x - 1;

	double cuadrado = valor_x*valor_x;
	double cubo = cuadrado * valor_x;

	resultado = cubo - cuadrado + 2*valor_x - 1;	//Mejor opcion.

	cout << "Valor de f(" << valor_x << ") = " << resultado << endl;


	return 0;
}

/*
		En detalle
		---------------

		De la funcion f(x) = x^3 - x^2 + 2*x - 1
		observamos que hay  calculos que se repiten,
		es una buena practica localizar esas cosas.
		Además, la expresion
		resultado = valor_x * valor_x * valor_x - valor_x * valor_x + 2 * valor_x - 1;
		es muy complicada de entender a simple vista.
		Cualquier cambio a realizar (por ejemplo sustituir f(x) por   x^3 - 3*x^2 - x)
		se puede hacer lioso y propenso a errores.

		Este ejercicio nos hace darnos cuenta ademas que seria util almacenar
		el como calcular f(x) para poder ejecutarlo cuando sea necesario,
		y prescindir de tener que copiar en varios ocasiones la misma funcion.


*/
