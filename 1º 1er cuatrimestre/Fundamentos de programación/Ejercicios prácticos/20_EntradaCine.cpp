/*

	(C)Algebro.

  Suponemos un cine que calcula el precio de su entrada segun la edad.
	De 0 a 2 anios, la entrada es gratuita.
	De 3 a 22 anios, la entrada vale 0.2 euros por anio.
	De 23 a 64 anios, la entrada vale 0.25 euros por anio.
	De 65 en adelante, la entrada es gratuita.

*/

#include <iostream>

using namespace std;




int main(){


	int edad;

	cout << "Introducir edad : ";
	cin >> edad;

	if(edad > 64 || edad < 3)
		cout << "La entrada es gratuita" << endl;
	else if(edad > 22)
		cout << "El precio es de " << edad*0.25<< " euros." << endl;
	else
		cout << "El precio es de " << edad*0.2 << " euros." << endl;


	return 0;
}

/*
		En detalle
		---------------

		Las condiciones logicas (contenidas dentro de la comprobacion if)
		nos permiten comprobar casos booleanos (true o false),
		lo cual tambien da pie a usar sentencias o cadenas de las mismas,
		por ejemplo
		A OR B, ó  A AND B.  (A || B ,   A && B)
		en nuestro caso A es 'edad>64' y B es 'edad<3',
		que pueden ser sustituidas por true ó false, dependiendo del valor de 'edad';
		pero además, podemos hacer estructuras mas complejas,
		A OR (B AND C)    (A || (B && C))



*/
