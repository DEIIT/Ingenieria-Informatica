/*

	(C)Algebro.

  Definicion e implementacion de la clase Numero.

	Atributo privado.
	Metodos Get y Set.

*/

#include <iostream>

using namespace std;

typedef int tipo;		//nos permite cambiar el tipo de forma uniforme.

class Numero{

	private:

		tipo numero;

	public:

		void Set(tipo valor){
			numero = valor;
		}

		tipo Get(){
			return numero;
		}
};


int main(){

	Numero a;
	tipo aux;
	//a.numero = 3;  No podemos acceder

	cout << "Introducir un valor : ";
	cin >> aux;

	a.Set(aux);

	cout << "Valor : " << a.Get() << endl ;

	return 0;
}

/*
		En detalle
		---------------

		Entre otros, los atributos y métodos (funciones de clase)
		tienen dos visibilidades diferentes; esto significa
		el acceso que tienen desde fuera de la clase de ellos.

		Visibilidad public: Por defecto en struct, cualquiera puede utilizar
		desde fuera de la clase. (Llamar en caso de metodos, leer y modificar
		en caso de atributos)

		Visibilidad private: Por defecto en class, solamente la propia
		clase puede utilizar. (Llamar en caso de metodos, leer y modificar
		en caso de atributos)

*/
