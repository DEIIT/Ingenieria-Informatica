/*

	(C)Algebro.

	A partir de un vector de enteros preinicializado (Ver ejercicio 15)
	recorrerlo para mostrar los datos que contiene.

	Recorrido similar al ejercicio 22 (Contar).

*/

#include <iostream>

using namespace std;




int main(){

	int palabra[] = {1,3,5,7,9,11}; //No se indica el tamanio ya que esta implicito en la inicializacion
	const int TAMANIO = 6;


	for(int contador=0; contador<TAMANIO; contador++)
		cout << palabra[contador] << " ";
	cout << endl;


	int contador=0;
	while(contador < TAMANIO){
		cout << palabra[contador] << " ";
		contador++;
	}
	cout << endl;


	return 0;
}

/*
		En detalle
		-----------------------

		Tenemos una constante para controlar el tamanio
		del vector, de manera que si cambiamos el vector
		y actualizamos dicho contados, no haya que modificar
		el codigo en ningun otro punto del codigo.
		

		(Igual que en el ejercicio 22)
		Ambos bucles hacen exactamente lo mismo:

		Inicializacion  (contador=0)
		Comprobacion (contador < tope  ?? )
		Actualizacion (contador++);
		*Volver a Comprobacion.



*/
