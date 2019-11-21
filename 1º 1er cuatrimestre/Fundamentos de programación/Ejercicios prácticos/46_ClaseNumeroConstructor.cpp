/*

	(C)Algebro.

  Definicion e implementacion de la clase Numero.

	Atributo privado.
	Metodos Get y Set.
	Constructor por defecto y con un parametro.

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
};


int main(){

	Numero a;					//Se ha llamado al constructor por defecto (sin parámetros)

	tipo aux;

	cout << "Introducir un valor : ";
	cin >> aux;

	Numero b(aux);		//Se ha llamado al constructor con un parámetro.


	cout << "Valor defecto : " << a.Get()
		<< "\nValor por parametro : " << b.Get() << endl ;

	return 0;
}

/*
		En detalle
		---------------


*/
