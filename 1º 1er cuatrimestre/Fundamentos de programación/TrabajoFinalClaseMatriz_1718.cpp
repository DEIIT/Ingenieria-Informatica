#include <iostream>
#include <cmath>
using namespace std;

// Definiremos un tipo de dato "posicion" para poder devolver la posicion en la que se encuentre un elemento de la matriz.
struct posicion
{
	int fil;
	int col;
};

// Definiremos la clase Matriz, con ella podremos realizar fácilmente operaciones con matrices y controlar sus datos.
class Matriz
{
	// Para que solo se pueden usar desde la clase declararemos los datos miembros en el ámbito privado.
	private:
		
		// Lo declaramos de tipo "static const int" por que tendrá el mismo valor en todos los objetos.
		static const int MAX = 50;
		int dato[MAX][MAX];
		int util_fil, util_col;
		// El tamaño real de la matriz lo inicializaremos en los constructores de la clase.
	
	// En el ámbito público declararemos los constructores y los métodos que nos puedan servir en el main.
	public:
		
		// Constructores.
		// Sirven para que al declarar un objeto no tenga un estado inválido.
		
		// El primer constructor se usará por defecto e incializará el objeto.
		Matriz()
			:util_fil(0), util_col(0) {}
		
		//  El segundo constructor se usará cuando pasemos 2 parámetros, el número de filas y el número de columnas.
		//  Inicializará los valores del objeto, rellenando la matriz con ceros. Si los parámetros no son válidos usamos al primer constructor.
		Matriz(int num_fil, int num_col)				
		{
			if (num_fil > 0 && num_fil <= MAX && num_col > 0 && num_col <= MAX)	// Comprobación de que los parámetros son válidos
			{
				util_fil = num_fil;
				util_col = num_col;
				
				for (int i = 0; i < util_fil; i++)
					for (int j = 0; i < util_col; i++)
						dato[i][j] = 0;
			}
			else
				Matriz();
		}
			
			
		// Obtener datos.
		// Con estos métodos podremos obtener los datos del objeto que sean necesarios.
		
		int MaxFilas()
		{
			return MAX;
		}
		
		int MaxColumnas()
		{
			return MAX;
		}
		
		int FilasUtilizadas()
		{
			return util_fil;
		}
		
		int ColumnasUtilizadas()
		{
			return util_col;
		}
		
		int Elemento(int fila, int columna)			// Al no saber excepciones devolveremos -1 en caso de que se introduzcan parámetros erroneos.
		{
			int valor = -1;
			
			if (fila >= 0 && fila < util_fil && columna >= 0 && columna < util_col)
				valor = dato[fila][columna];
			
			return valor;
		}
		
		
		// Operaciones.
		// Estos métodos nos serviran para realizar operaciones con Matrices fácilmente.
		
		// Devolveremos la matriz vacía si no se cumple la precondición (En la suma y resta las matrices tienen que tener el mismo tamaño).
		// Si tienen el mismo tamaño sumaremos las componentes o las restaremos.
		Matriz Suma(Matriz m1)
		{
			Matriz m2;
			
			if (m1.util_fil == util_fil && m1.util_col == util_col)		
			{
				m2.util_fil = util_fil;
				m2.util_col = util_col;
				
				for (int i = 0; i < util_fil; i++)
					for (int j = 0; j < util_col; j++)
						m2.dato[i][j] = m1.dato[i][j] + dato[i][j];
			}
			
			return m2;
		}
	
		Matriz Resta(Matriz m1)
		{
			Matriz Resultado;
			
			if (m1.util_fil == util_fil && m1.util_col == util_col)
			{
				Resultado.util_fil = util_fil;
				Resultado.util_col = util_col;
				
				for (int i = 0; i < util_fil; i++)
					for (int j = 0; j < util_col; j++)
						Resultado.dato[i][j] = dato[i][j] - m1.dato[i][j];
			}
			
			return Resultado;
		}
		
		// Multiplicamos cada componente por el escalar pasado como parámetro
		Matriz Escalar(int escalar)
		{
			Matriz Resultado;
			
			Resultado.util_fil = util_fil;
			Resultado.util_col = util_col;
				
			for (int i = 0; i < util_fil; i++)
				for (int j = 0; j < util_col; j++)
					Resultado.dato[i][j] = dato[i][j] * escalar;
			
			return Resultado;
		}
		
		// La precondición es que las columnas de la matriz del objetos sean iguales a las filas de la matriz de m1.
		Matriz Producto(Matriz m1)
		{
			Matriz Resultado;
			int calculo = 0;
			
			if(util_col == m1.util_fil)
			{
				Resultado.util_fil = util_fil;
				Resultado.util_col = m1.util_col;
				
				for(int i = 0; i < Resultado.util_fil; i++)
					for(int j = 0; j < Resultado.util_col; j++)
					{
						for (int k = 0; k < util_col; k++)
							calculo += dato[i][k] * m1.dato[j][k];
						
						Resultado.dato[i][j] = calculo;
						calculo = 0;
					}
			}
			
			return Resultado;
		}
		
		Matriz Traspuesta()
		{
			Matriz tras;
			
			tras.util_col = util_fil;
			tras.util_fil = util_col;
			
			for (int i = 0; i < util_fil; i++)
				for (int j = 0; j < util_col; j++)
					tras.dato[i][j] = dato[j][i];
					
			return tras;
		}
		
		// Usamos la busqueda secuencial para buscar la posición de x en la Matriz del objeto.
		// Si no lo encontramos devolveremos -1 y -1 como posición.
		posicion BuscarElemento(int x)
		{
			posicion Buscado;
			bool encontrado = false;
			
			Buscado.col = -1;
			Buscado.fil = -1;
			
			for (int i = 0; i < util_fil && !encontrado; i++)
				for (int j = 0; i < util_col && !encontrado; j++)
					if (dato[i][j] == x)
					{
						Buscado.fil = i;
						Buscado.col = j;
						
						encontrado = true;
					}
			
			return Buscado;
		}
		
		Matriz Ordenar()
		{
			// Pasamos los datos de la matriz a un vector.
			
			int util_v = util_fil * util_col;
			int v[util_v], n = 0;
			
			for (int i = 0; i < util_fil; i++)
				for (int j = 0; j < util_col; j++)
				{
					v[n] = dato[i][j];
					
					n++;
				}
			
			// Ordenamos el vector usando el método de la burbuja.
			
			int tmp;
			bool cambio = true;
			
			for (int izq = 0; izq < util_v && cambio; izq++)
			{
				cambio = false;
				
				for (int i = util_v - 1; i > izq; i--)
					if (v[i] < v[i - 1])
					{
						cambio = true;
						
						tmp = v[i];
						v[i] = v[i - 1];
						v[i - 1] = tmp;
					}
			}
			
			// Pasamos el vector ordenado a una nueva matriz que sera la que devolvamos como resultado.
			
			Matriz Ordenada(util_fil, util_col);
			n = 0;
			
			for (int i = 0; i < util_fil; i++)
				for (int j = 0; j < util_col; j++)
				{
					Ordenada.dato[i][j] = v[n];
					
					n++;
				}
			
			return Ordenada;
		}
		
		
		// Modificar Matriz.
		// Estos métodos serviran para modificar los datos miembro del objeto.
		
		void Borrar()
		{
			util_fil = util_col = 0;
		}
		
		void ModificarElemento(int fila, int columna, int nuevo)
		{
			if (fila >= 0 && fila < util_fil && columna >= 0 && columna < util_col)
				dato[fila][columna] = nuevo;
		}
		
		void EliminarFila(int fila)
		{
			if (fila >= 0 && fila < util_fil)
			{
				for(int i = fila; i < util_fil - 1; i++)
					for(int j = 0; j < util_col; j++)
						dato[i][j] = dato[i + 1][j];
				
				util_fil --;
			}
		}
		
		void EliminarColumna(int columna)
		{
			if (columna >= 0 && columna < util_col)
			{
				for(int i = columna; i < util_col - 1; i++)
					for(int j = 0; j < util_fil; j++)
						dato[j][i] = dato[j][i + 1];
				
				util_col --;
			}
		}
};


// No es conveniente mezclar procesos y operaciones de E/S en una clase. 
// Por lo tanto definiremos dos funciones para leer y mostrar matrices.

Matriz LeerMatriz()
{
	int total_fil, total_col, valor;
	Matriz a;
	
	do
	{
	cout << "\nIntroduce el número de filas que tendrá la Matriz: ";
	cin >> total_fil;
	} while (total_fil < 0 && total_fil > a.MaxFilas());
		
	do
	{
	cout << "\nIntroduce el número de columnas que tendrá la Matriz: ";
	cin >> total_col;
	} while (total_col < 0 && total_col > a.MaxColumnas());
	
	Matriz Leer(total_fil, total_col);
	
	for(int i = 0; i < total_fil; i++)
		for(int j = 0; j < total_col; j++)
		{
			cout << "\n	Introduce el elemento [ " << i << " , " << j << " ]: ";
			cin >> valor;
			
			Leer.ModificarElemento(i, j, valor);
		}
		
	return Leer;
}

void MostrarMatriz(Matriz m1)
{
	cout << endl;
	
	for(int i = 0; i < m1.FilasUtilizadas(); i++)
	{
		for(int j = 0; j < m1.ColumnasUtilizadas(); j++)
			cout << m1.Elemento(i, j) << "	";
			
		cout << endl;
	}
}

// A PARTIR DE AQUÍ EMPIEZA UN EJEMPLO DE USO DE LA CLASE
// Usaremos varias funciones de Menu para elegir que hacer con una Matriz leída.
// Esto servira de ejemplo como aplicación práctica de la clase que hemos desarrollado.

int MenuPrincipal()
{
	int opcion;
	
	do
	{
		cout << "\n\n*******************************************";
		cout << "\n[1] Operaciones con la Matriz guardada";
		cout << "\n[2] Mostrar datos de la Matriz";
		cout << "\n[3] Modificar la Matriz";
		cout << "\n[4] Salir";
		cout << "\n*******************************************\n";
		cout << "Elige una opción: ";
		cin >> opcion;
	}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
	
	return opcion;
}

int MenuOperar()
{
	int opcion;
	
	do
	{
		cout << "\n\n*******************************************";
		cout << "\n[1] Sumar con otra Matriz";
		cout << "\n[2] Restar con otra Matriz";
		cout << "\n[3] Multiplicar Matriz por un Escalar";
		cout << "\n[4] Multiplicar Matriz por otra Matriz";
		cout << "\n[5] Buscar elemento dentro de la Matriz";
		cout << "\n[6] Ordenar Matriz de Menor a Mayor";		
		cout << "\n[7] Salir al Menú Principal";
		cout << "\n*******************************************\n";
		cout << "Elige una opción: ";
		cin >> opcion;
	}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7);
	
	return opcion;
}

int MenuMostrar()
{
	int opcion;
	
	do
	{
		cout << "\n\n*******************************************";
		cout << "\n[1] Mostrar la Matriz";
		cout << "\n[2] Mostrar el número de filas";
		cout << "\n[3] Mostrar el número de columnas";
		cout << "\n[4] Mostrar un elemento en concreto";
		cout << "\n[5] Salir al Menú Principal";
		cout << "\n*******************************************\n";
		cout << "Elige una opción: ";
		cin >> opcion;
	}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
	
	return opcion;
}

int MenuModificar()
{
	int opcion;
	
	do
	{
		cout << "\n\n*******************************************";
		cout << "\n[1] Modificar un elemento concreto";
		cout << "\n[2] Eliminar una fila";
		cout << "\n[3] Eliminar una columna";
		cout << "\n[4] Volver a leer Matriz";
		cout << "\n[5] Salir al Menú Principal";
		cout << "\n*******************************************\n";
		cout << "Elige una opción: ";
		cin >> opcion;
	}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
	
	return opcion;
}

bool Conservar()
{
	bool conservar = true;
	int opcion;
	
	do
	{
		cout << "\n\n¿Conservar el resultado?";
		cout << "\n[1] Sí";
		cout << "\n[2] No";
		cout << "\nElige una opción: ";
		cin >> opcion;
	}while(opcion != 1 && opcion != 2);
	
	if (opcion == 2)
		conservar = false;
	
	return conservar;
}

int main()
{
	Matriz m1, m2;
	posicion pos;
	int opcion_principal, opcion_operar, opcion_mostrar, opcion_modificar;
	int n, n1, n2;
	
	m1 = LeerMatriz();
	
	do
	{
		opcion_principal = MenuPrincipal();	
		
		if(opcion_principal == 1)
		{
			do
			{
				opcion_operar = MenuOperar();
			
				if(opcion_operar == 1)
				{
					m2 = LeerMatriz();
					
					m2 = m1.Suma(m2);
					
					MostrarMatriz(m2);
					
					if (Conservar())
						m1 = m2;
				}
				
				if(opcion_operar == 2)
				{
					m2 = LeerMatriz();	
					
					m2 = m1.Resta(m2);
					
					MostrarMatriz(m2);
					
					if (Conservar())
						m1 = m2;
				}
				
				if(opcion_operar == 3)
				{
					cout << "\nIntroduce el escalar: ";
					cin >> n;
					
					m2 = m1.Escalar(n);
					
					MostrarMatriz(m2);
					
					if (Conservar())
						m1 = m2;
				}
				
				if(opcion_operar == 4)
				{
					m2 = LeerMatriz();	
					
					m2 = m1.Producto(m2);
					
					MostrarMatriz(m2);
					
					if (Conservar())
						m1 = m2;
				}
				
				if(opcion_operar == 5)
				{
					cout << "\nIntroduce el elemento a buscar: ";
					cin >> n;
					
					pos = m1.BuscarElemento(n);
					
					cout << "\nEl elemento se encuentra en la posición [ " << pos.fil << " , " << pos.col << " ]";
				}
				
				if(opcion_operar == 6)
				{
					m2 = m1.Ordenar();
					
					MostrarMatriz(m2);
					
					if (Conservar())
						m1 = m2;
				}
				
			}	while(opcion_operar != 7);
		}
		
		if(opcion_principal == 2)
		{
			do
			{
				opcion_mostrar = MenuMostrar();
				
				if(opcion_mostrar == 1)
					MostrarMatriz(m1);
					
				if(opcion_mostrar == 2)
					cout << "\nEl número de filas utilizadas es " << m1.FilasUtilizadas();
					
				if(opcion_mostrar == 3)
					cout << "\nEl número de columnas utilizadas es " << m1.FilasUtilizadas();
					
				if(opcion_mostrar == 4)
				{
					cout << "\nIntroduce la fila del elemento: ";
					cin >> n1;
					
					cout << "\nIntroduce la columna del elemento : ";
					cin >> n2;
					
					cout << "\nEl elemento es " << m1.Elemento(n1, n2);
				}
				
			}	while(opcion_mostrar != 5);
		}
		
		if(opcion_principal == 3)
		{
			do
			{
				opcion_modificar = MenuModificar();
				
				if(opcion_modificar == 1)
				{
					cout << "\nIntroduce la fila del elemento: ";
					cin >> n1;
					
					cout << "\nIntroduce la columna del elemento: ";
					cin >> n2;
					
					cout << "\nIntroduce el nuevo valor: ";
					cin >> n;
					
					m1.ModificarElemento(n1, n2, n);
					
					cout << "\nEl elemento ha sido modificado";
				}
				
				if(opcion_modificar == 2)
				{
					cout << "\nIntroduce la fila que quieres eliminar: ";
					cin >> n1;
					
					n1--;
					
					m1.EliminarFila(n1);
					
					if (n1 > -1 && n1 < m1.FilasUtilizadas())
						cout << "\nLa columna ha sido eliminada";
					else
						cout << "\nLa columna seleccionada no existe";
				}
				
				if(opcion_modificar == 3)
				{
					cout << "\nIntroduce la columna que quieres eliminar: ";
					cin >> n2;
					
					n2--;
					
					m1.EliminarColumna(n2);
					
					if (n2 > -1 && n2 < m1.ColumnasUtilizadas())
						cout << "\nLa columna ha sido eliminada";
					else
						cout << "\nLa columna seleccionada no existe";
				}
				
				if(opcion_modificar == 4)
				{
					m1 = LeerMatriz();
				}
				
			}	while(opcion_modificar != 5);
		}
		
	}	while(opcion_principal != 4);
}
