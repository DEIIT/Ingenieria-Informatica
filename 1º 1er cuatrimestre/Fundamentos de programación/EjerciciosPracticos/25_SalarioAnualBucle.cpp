/*

	(C)Algebro.

  A partir del ejercicio 08 (Salario Anual)
	aplicar bucles para el calculo del salario.

	Formula:  Salario en ano a  ->  (salario)*(1+p)^a
*/

#include <iostream>

using namespace std;


int main(){


	double salario;
	double porcentaje;
	double total=0;
	int anios;

	cout << "Introducir el salario inicial: ";
	cin >> salario;
	cout << "Introducir el porcentaje incremento anual: ";
	cin >> porcentaje;
	cout << "Introducr el numero de anios : ";
	cin >> anios;

	for(int i=0;i<anios;i++){
		total += salario;
		salario *= 1+porcentaje;
		cout << "\nSalario pasados " << i+1 << " anios : " << salario;
	}

	cout << "\nSalario total recibido en " << anios << " anios : " << total << endl;



	return 0;
}

/*
		En detalle
		---------------



*/
