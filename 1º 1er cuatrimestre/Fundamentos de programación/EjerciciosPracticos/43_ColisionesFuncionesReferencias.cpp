/*

	(C)Algebro.

	Modificacion del ejercicio 40 (Colisiones Funciones) haciendo
	uso del paso por referencia.

	Añadida la funcion Lee_Circulo.

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


void Lee_Coordenada(Coordenada& punto){
	cout << "\nCoordenada X : ";
	cin >> punto.x;
	cout << "Coordenada Y : ";
	cin >> punto.y;
}

void Lee_Circulo(Circulo& circulo){
	cout << "Introducir centro del circulo : ";
	Lee_Coordenada(circulo.centro);
	cout << "Introducir radio del circulo : ";
	cin >> circulo.radio;
}

double Area(const Circulo& circulo){
	return PI*Cuadrado(circulo.radio);
}

double Distancia(const Coordenada& coor1,const Coordenada& coor2){
	return sqrt(Cuadrado(coor1.x - coor2.x) + Cuadrado(coor1.y - coor2.y) );
}

int main(){


	Coordenada punto;
	Circulo circulo;

	Lee_Circulo(circulo);

	cout << "Introducir coordenadas del punto : ";
	Lee_Coordenada(punto);


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

		Podemos hacer uso de la palabra clave 'const' para indicar
		que, aunque hagamos paso por referencia (y por lo tanto no creamos una copia)
		no queremos modificar la variable original.
		Lo que conseguimos es ahorrar que se realice una copia.


*/
