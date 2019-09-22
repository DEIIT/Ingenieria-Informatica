/*

	(C)Algebro.

  Dado un entero para la longitud base,
	'dibujar' media piramide.

	por ejemplo, para longitud 3:
	1
	12
	123
*/

#include <iostream>

using namespace std;


int main(){


	int longitud;
	cout << "Longitud base : ";
	cin >> longitud;

	for(int i=1;i<=longitud;i++){
		for(int j=1;j<=i; j++){		//Hay que tener en cuenta que comenzamos en 1.
			cout << j;
		}
		cout << endl;
	}



	return 0;
}

/*
		En detalle
		---------------

		Al tener los dos bucles anidados, nos permite recorrer
		fila a fila y columna a columna para ir "pintando"
		los numeros que queramos.
		El primer for (englobante) indica las filas,
		podriamos haber usado de [0,longitud) en lugar de [1,longitud]
		pero de esta manera es mas sencilla la condicion del segundo bucle.

		El segundo for recorre desde el 1 hasta llegar al tamanio i de esa fila.
		Si estamos en la primera fila, i valdra 1, y asi sucesivamente,
		de esta manera vamos haciendo filas con un mayor numero de columnas.


*/
