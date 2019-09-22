/*

	(C)Algebro.

	Introducir numeros en un vector, y avisar cuando
	se introduzca algun dato repetido (no necesariamente consecutivo)

*/

#include <iostream>

using namespace std;




int main(){

	const int TAMANIO = 50;
	int datos[TAMANIO];

	int numero;
	int introducidos=0;
	bool encontrado;

	cout << "Introducir numero (0 para finalizar): ";
	cin >> numero; 	//lectura adelantada

	while(numero!=0 && introducidos<TAMANIO){

		encontrado = false;
		for(int i=0; i<TAMANIO && i<introducidos && !encontrado; i++)
					encontrado = numero == datos[i];
		if(encontrado)
			cout << numero << " repetido.";


		datos[introducidos] = numero;
		introducidos += 1;

		cout << "\nIntroducir numero (0 para finalizar): ";
		cin >> numero;
	}



	return 0;
}

/*
		En detalle
		-----------------------




*/
