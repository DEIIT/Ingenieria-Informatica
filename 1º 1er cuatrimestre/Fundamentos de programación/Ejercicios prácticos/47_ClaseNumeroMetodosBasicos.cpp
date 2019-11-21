/*

	(C)Algebro.

  Definicion e implementacion de la clase Numero.

	Atributo privado.
	Metodos Get y Set.
	Constructor por defecto y con un parametro.
	Metodos operacionales.

*/

#include <iostream>

using namespace std;

typedef int tipo;		//nos permite cambiar el tipo de forma uniforme.

class Numero{

	private:

		tipo numero;

	public:

		Numero(){
			numero = 0;
		}

		Numero (tipo valor){
			numero = valor;
		}

		void Set(tipo valor){
			numero = valor;
		}

		tipo Get(){
			return numero;
		}

		tipo Suma(tipo num){
			return numero + num;
		}

		tipo Producto(tipo num){
			return numero * num;
		}

		void Aniade(tipo num){
			numero += num;
		}


};


int main(){

	tipo aux;

	cout << "Introducir un valor : ";
	cin >> aux;

	Numero b(aux);

	cout << "Introducir otro valor : ";
	cin >> aux;


	cout << "\nSuma : " << b.Suma(aux)
		<< "\nProducto : " << b.Producto(aux);

	b.Aniade(1);

	cout << "\nIncrementado : " << b.Get() << endl;

	return 0;
}

/*
		En detalle
		---------------


*/
