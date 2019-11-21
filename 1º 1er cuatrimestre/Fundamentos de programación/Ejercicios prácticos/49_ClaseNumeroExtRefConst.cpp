/*

	(C)Algebro.

  Definicion e implementacion de la clase Numero.

	Atributo privado.
	Metodos Get y Set.
	Constructor por defecto,con un parametro y de copia.
	Metodos operacionales.
	Otros metodos.
	Metodos constantes y no constantes.

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


		Numero(const Numero& otro){
			numero = otro.Get();
		}

		void Set(tipo valor){
			numero = valor;
		}

		void Set(Numero& otro){
			numero = otro.Get();
		}

		tipo Get()const {
			return numero;
		}

		tipo Suma(tipo num){
			return numero + num;
		}

		tipo Suma(const Numero& otro)const{
			return numero + otro.Get();
		}

		tipo Producto(tipo num)const{
			return numero * num;
		}

		tipo Producto(const Numero& otro)const{
			return numero * otro.Get();
		}

		void Aniade(tipo num){
			numero += num;
		}

		void Aniade(const Numero& otro){
			numero += otro.Get();
		}

		tipo Potencia(int exp)const{
			tipo aux = 1;
			for(int i=0; i<exp;i++)
				aux *= numero;
			return aux;
		}

		bool Equal(const Numero& otro) const{
			return numero == otro.Get();
		}

};


int main(){

	tipo aux;

	cout << "Introducir un valor A : ";
	cin >> aux;

	Numero a(aux);

	cout << "Introducir un valor B : ";
	cin >> aux;

	Numero b(aux);
	Numero c(a);	//copia de A

	cout << "\nA + B : " << c.Suma(b)
		<< "\nA * B : " << c.Producto(b);


		cout << "\nA ^ 3 : " << a.Potencia(3);

		cout << "\nA == B : " << (a.Equal(b)?"Si":"No") << endl;

	return 0;
}

/*
		En detalle
		---------------

		Cuando tenemos un objeto constate (por ejemplo 'const Numero valor')
		este debe carantizar que sus atributos no se modifican,
		para ello, solo puede utilizar métodos const.
		Por ejemplo:

		tipo Get() const{
			return numero;
		}

		de esta manera garantizamos que el metodo Get NO modifica
		el estado de la instancia que lo llama.

*/
