/*

	(C)Algebro.

  Suponemos un cine que calcula el precio de su entrada segun la edad.
	De 0 a 2 anios, la entrada es gratuita.
	De 3 a 9 anios, la entrada vale 1 euro, mas 0.1 por anio de edad.
	De 10 a 15 anios, la entrada vale 2 euros, mas 0.05 por anio de edad.
	De 16 a 25 anios, la entrada vale 4 euros.
	De 26 a 59 anios, la entrada vale 0.2 por anio de edad.
	A partir de 59, la entrada vale 1.5 euros.

*/

#include <iostream>

using namespace std;




int main(){


	int edad;
	double precio=0;

	cout << "Introducir edad : ";
	cin >> edad;

	if(edad > 15){
		if(edad > 59) 			//>59
			precio = 1.5;
		else if(edad > 25)	//26-59
			precio = 0.2*edad;
		else								//16-25
			precio = 4;
	}else{
		if(edad > 9)				//10-15
			precio = 2 + 0.05*edad;
		else if(edad > 2)		//3-9
			precio = 1 + 0.1*edad;
	}

	if(precio > 0)
		cout << "El precio es de " << precio << " euros." << endl;
	else
		cout << "La entrada es gratuita para " << edad << " anios.";

	return 0;
}

/*
		En detalle
		---------------





*/
