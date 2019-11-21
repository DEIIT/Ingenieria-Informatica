/*

	(C)Algebro.

  Suponiendo que nuestro salario anual aumenta
	un porcentaje p (tanto por uno) respecto al año anterior.
	Calculo del salario en 1, 2 y 3 anos.

	Formula:  Salario en ano a  ->  (salario)*(1+p)^a
*/

#include <iostream>

using namespace std;


int main(){


	double salario;
	double porcentaje;

	cout << "Introducir el salario inicial: ";
	cin >> salario;
	cout << "Introducir el porcentaje incremento anual: ";
	cin >> porcentaje;

	double ano1 = salario*(1+porcentaje);
	double ano2 = ano1 * (1+porcentaje);
	double ano3 = ano2 * (1+porcentaje);

	double total = salario+ano1+ano2+ano3;

	cout << "Salario inicial : " << salario << endl
		<< "Salario tras 12 meses : " << ano1 << endl
		<< "Salario tras 24 meses : " << ano2 << endl
		<< "Salario tras 36 meses : " << ano3 << endl
		<< "Total recibido durante los primeros 48 meses : " << total << endl
		<< "Media recibida anualmente : " << total/4 << endl;


	return 0;
}

/*
		En detalle
		---------------

		Si tuvieramos una funcion potencia, que nos permitiese
		calcular de forma sencilla  a^b, dispondriamos de un metodo
		rapido de calcular el salario para cualquier a.

		De la misma forma, algun comportamiento ciclico (en bucle)
		que pudiera realizar el producto de (1+porcentaje) respecto
		al valor anterior tambien nos seria de utilidad, además,
		para calcular el salario total recibido (sumatoria) durante
		los a anos que desemos calcular.


*/
