/*

	(C)Algebro.

  Dado un entero para la longitud base,
	'dibujar' media piramide y su reflejo.

	por ejemplo, para longitud 3:
	1    1
	12  21
	123321
*/

#include <iostream>

using namespace std;


int main(){


	int longitud;
	cout << "Longitud base (maximo 9) : ";
	cin >> longitud;

	for(int i=1;i<=longitud;i++){
		for(int j=1;j<=i; j++){		// Piramide izquierda (creciente)
			cout << j;
		}
		for(int h=0;h<2*(longitud-i);h++){  // Espaciado
			cout << ' ';
		}
		for(int j=i;j>=1; j--){		//Piramide derecha (decreciente)
			cout << j;
		}

		cout << endl;
	}



	return 0;
}

/*
		En detalle
		---------------

		Si la longitud es mayor que 9, entonces el espaciado no concuerda,
		ya que los numeros de dos cifras son un numero, pero dos digitos.
		Eso significa que el bucle coloca un espacio en la posicion correspondiente
		a estos numeros, pero solo un espacio por cada uno, cuando se requieren dos.

		El calculo de 2*(longitud-i) viene asociado a que (longitud-i) son los numeros
		restantes para acabar la piramide; necesitamos el doble de estos, ya que
		la base asciende y luego desciende en el reflejo.d

*/
