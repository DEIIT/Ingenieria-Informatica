/*

	(C)Algebro.

  Dado un numero por consola, contar desde 0 hasta este ese numero (no incluido).
	Realizado con un bucle for y con un bucle while.

*/

#include <iostream>

using namespace std;




int main(){


	int tope;
	cout << "Introducir tope : ";
	cin >> tope;

	for(int contador=0; contador<tope; contador++)
		cout << contador << " ";
	cout << endl;


	int contador=0;
	while(contador < tope){
		cout << contador << " ";
		contador++;
	}
	cout << endl;


	return 0;
}

/*
		En detalle
		---------------

		Ambos bucles hacen exactamente lo mismo:

		Inicializacion  (contador=0)
		Comprobacion (contador < tope  ?? )
		Actualizacion (contador++);
		*Volver a Comprobacion.



*/
