/*

	(C)Algebro.

	Utilizando de un struct para definir las coordenadas (X,Y) de cualquier punto,
	y de un struct Circulo, determinar si un punto arbitrario pertenece
	al circulo (previamente introducido) o no.


*/

#include <iostream>
#include <math.h>

using namespace std;

struct Coordenada{
	double x,y;
};

struct Circulo{
	Coordenada centro;
	double radio;
};

double Cuadrado(double x){
	return x*x;
}

int main(){


	Coordenada punto;
	Circulo circulo;

	cout << "Introducir centro del circulo : ";
	cout << "\nCoordenada X : ";
	cin >> circulo.centro.x;
	cout << "Coordenada Y : ";
	cin >> circulo.centro.y;
	cout << "Introducir radio del circulo : ";
	cin >> circulo.radio;

	cout << "Introducir coordenadas del punto : ";
	cout << "\nCoordenada X : ";
	cin >> punto.x;
	cout << "Coordenada Y : ";
	cin >> punto.y;

	double distancia_central = sqrt(Cuadrado(circulo.centro.x - punto.x) + Cuadrado(circulo.centro.y - punto.y) );

	if(distancia_central < circulo.radio)
		cout << "\nEl punto " << punto.x << "," << punto.y << " pertenece al circulo.\n";
	else if(distancia_central > circulo.radio)
		cout << "\nNo pertenece el circulo.\n";
	else
		cout << "\nSe encuentra en la propia circunferencia.\n";




	return 0;
}

/*
		En detalle
		---------------

		Se dice que un punto pertenece a un circulo (se encuentra en su área)
		si la distancia de dicho punto al centro es menor que el radio.

		Podriamos haber evitado el uso de raices, si comparamos
		el cuadrado de la distancia (simplemente borramos la llamada a sqrt)
		con el cuadrado del radio...
		De manera que quedaría:

		Cuadrado(circulo.centro.x - punto.x) + Cuadrado(circulo.centro.y - punto.y)
		comparado con
		Cuadrado(circulo.radio)


*/
