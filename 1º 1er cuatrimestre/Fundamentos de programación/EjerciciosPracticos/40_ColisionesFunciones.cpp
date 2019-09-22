/*

	(C)Algebro.

	Modificacion del ejercicio 39 (Colisiones) con la aparicion
	de funciones que nos permitan operar con nuestros structs.


*/

#include <iostream>
#include <math.h>

using namespace std;

static const double PI = 3.14159265358979;

double Cuadrado(double x){
	return x*x;
}

struct Coordenada{
	double x,y;
};

struct Circulo{
	Coordenada centro;
	double radio;
};


Coordenada Lee_Coordenada(){
	Coordenada punto;
	cout << "\nCoordenada X : ";
	cin >> punto.x;
	cout << "Coordenada Y : ";
	cin >> punto.y;
	return punto;
}

double Area(Circulo circulo){
	return PI*Cuadrado(circulo.radio);
}

double Distancia(Coordenada coor1, Coordenada coor2){
	return sqrt(Cuadrado(coor1.x - coor2.x) + Cuadrado(coor1.y - coor2.y) );
}

int main(){


	Coordenada punto;
	Circulo circulo;

	cout << "Introducir centro del circulo : ";
	circulo.centro = Lee_Coordenada();
	cout << "Introducir radio del circulo : ";
	cin >> circulo.radio;

	cout << "Introducir coordenadas del punto : ";
	punto = Lee_Coordenada();


	cout << "\nArea del circulo : " << Area(circulo);

	double distancia_central = Distancia(punto, circulo.centro);

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


*/
