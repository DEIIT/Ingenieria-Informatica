/*

	(C)Algebro.
  
  Realizacion de un cálculo sencillo utilizando  variables y constantes.

*/

#include <iostream>

using namespace std;


int main(){


	const float PI = 3.1415;		//const indica que una vez asignado un valor NO se puede modificar.
	float radio;
	float area;
	float perimetro;

	cout << "Introducir radio de la circunferencia : ";
	cin >> radio;

	area = PI * radio * radio;
	perimetro = 2 * PI * radio;


	cout << "Radio : " << radio << "  Perimetro : " << perimetro << "  Area : " << area << endl;


	return 0;
}

/*
		En detalle
		---------------
		Los datos de tipo double al igual que los de tipo float,
    nos permiten almacenar numeros con decimales.

		Las constantes son utiles ya que nos permiten definir un valor valido con la
		certeza de que jamas se va a modificar, de tal manera que aporta robustez
		al programa (si la constante esta correctamente definida)
*/
