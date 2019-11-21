/*

	(C)Algebro.

	Programa simple que muestra un mensaje por pantalla.
*/

#include <iostream>		//Nos permite utilizar 'cout' y 'cin', para salida y entrada de datos (respectivamente)


using namespace std;	//Define el espacio de nombres std.



int main(){				//Función principal de uso obligatorio. Nuestro programa comenzará ejecutándose por aquí.


	cout << "Hello World!!!" << endl;	//Indicamos que queremos mostrar el mensaje  "Hello World!!!" y además, un salto de línea.


	return 0;			//Con un 0 indicamos al sistema que se ha ejecutado nuestro programa correctamente.
}



/*
		En detalle
		---------------

		cout  nos sirve para sacar por consola (mostrar en pantalla) mensajes que queramos
		que el usuario lea (aunque de forma externa al programa podría redireccionarse)

		endl  indica que queremos que se efectúe un salto de línea, generalmente
		para dar mayor legitibilidad a los mensajes que mostramos.


*/
