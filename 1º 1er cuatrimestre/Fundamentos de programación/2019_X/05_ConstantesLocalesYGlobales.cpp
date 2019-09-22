/*

	(C)Algebro.

  Realizacion de un cálculo sencillo utilizando  variables y constantes,
	de uso local y de uso global.
*/

#include <iostream>

using namespace std;


const float PI = 3.1415;		//const indica que una vez asignado un valor NO se puede modificar.

int main(){

	const float altura = 2.0;

	float radio;
	float area;
	float volumen;

	cout << "Introducir radio de la circunferencia base de un cilindro: ";
	cin >> radio;

	area = 2 * PI * radio * (radio + altura);
	volumen = PI * radio * radio * altura;


	cout << "Radio : " << radio << "  Altura : " << altura << endl
				<< "Area Cilindro : " << area << "  Volumen Cilindro : " << volumen << endl;


	return 0;
}

/*
		En detalle
		---------------

		Las constantes son utiles ya que nos permiten definir un valor valido con la
		certeza de que jamas se va a modificar, de tal manera que aporta robustez
		al programa (si la constante esta correctamente definida)

		Las constantes definidas dentro de la funcion main (locales), solo se podran usar en esta.

		Las constates globales son mas comunes, y son accesibles desde fuera de la funcion main,
		y compartidas por otras funciones. No las usaremos hasta ejercicios posteriores donde
		tengamos diferentes funciones, además de la función main.

*/
