/*

	(C)Algebro.

  Dada tres funciones matemáticas f(x),g(x) y h(x) calcular el valor obtenido
	para una x indicada por consola de h(x)


	Funciones:
		f(x) = x^2 + 2*x - 3
		g(x) = f(x+1) - f(x-1)
		h(x) = (g(x) + g(-x))/2

*/

#include <iostream>

using namespace std;


int main(){


	double valor_x;
	double resultado_f1g1, resultado_f2g1;
	double resultado_f1g2, resultado_f2g2;
	double resultado_g1, resultado_g2;
	double resultado_h;

	cout << "Introducir el valor de x: ";
	cin >> valor_x;

	resultado_f1g1 = ((valor_x+1)*(valor_x+1) + 2*(valor_x+1) - 3);
	resultado_f2g1 = ((valor_x-1)*(valor_x-1) + 2*(valor_x-1) - 3);
	resultado_g1 =  resultado_f1g1 - resultado_f2g1;

	resultado_f1g2 = ((-valor_x+1)*(-valor_x+1) + 2*(-valor_x+1) - 3);
	resultado_f2g2 = ((-valor_x-1)*(-valor_x-1) + 2*(-valor_x-1) - 3);
	resultado_g2 =  resultado_f1g2 - resultado_f2g2;

	resultado_h = (resultado_g1 + resultado_g2)/2;

	cout << "Valor de f(" << valor_x+1 << ") = " << resultado_f1g1 << endl;
	cout << "Valor de f(" << valor_x-1 << ") = " << resultado_f2g1 << endl;
	cout << "Valor de g(" << valor_x << ") = " << resultado_g1 << endl<<endl;

	cout << "Valor de f(" << -valor_x+1 << ") = " << resultado_f1g2 << endl;
	cout << "Valor de f(" << -valor_x-1 << ") = " << resultado_f2g2 << endl;
	cout << "Valor de g(" << -valor_x << ") = " << resultado_g2 << endl<<endl;

	cout << "Valor de h(" << valor_x << ") = " << resultado_h << endl;


	return 0;
}

/*
		En detalle
		---------------

		Este ejercicio nos hace darnos cuenta que seria muy util almacenar
		el como calcular f(x) para poder ejecutarlo cuando sea necesario,
		al igual que con g(x) y h(x);
		De esta manera podemos prescindir de tener que copiar en varios ocasiones
		la misma funcion.		(Se vera en el ejercicio 13 (FuncionesFxGxHx))

*/
