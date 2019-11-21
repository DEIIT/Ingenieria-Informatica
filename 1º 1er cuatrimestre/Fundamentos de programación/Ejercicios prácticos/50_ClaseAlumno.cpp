/*

	(C)Algebro.

  Definicion e implementacion de la clase Alumno.

	Atributos privados.
	Metodos acceso y modificacion.
	Constructores.
	Metodo Equal.


*/

#include <iostream>

using namespace std;

enum Pelo {platino, ocre, rosado, obsidiana, celeste};
enum Curso {primero=1, segundo, tercero, cuarto};

class Alumno{
	private:
		int id;
		int edad;
		Pelo pelo;
		Curso curso;
		int cred_superados;


	public:

		Alumno(){
			id=-1;
			edad=18;
			pelo = rosado;
			curso = primero;
			cred_superados = 0;
		}

		Alumno(int al_id, int al_edad, Pelo al_pelo, Curso al_curso, int cred=0){
			id = al_id;
			edad = al_edad;
			pelo = al_pelo;
			curso = al_curso;
			cred_superados = cred;
		}

		void AjusteID(int nuevo_id){
			id = nuevo_id;
		}

		void Cumpleanos(){
			edad+=1;
		}

		void Tinte(Pelo color){
			pelo = color;
		}

		void CambioCurso(Curso curs){
			curso = curs;
		}

		void Incrementa_Creditos(int aprobados){
			cred_superados += aprobados;
		}

		void Reset_Creditos(){
			cred_superados = 0;
		}

		int Get_ID()const{
			return id;
		}

		int Get_Edad()const{
			return edad;
		}

		Pelo Get_Pelo()const{
			return pelo;
		}

		Curso Get_Curso()const{
			return curso;
		}

		int Get_Creditos()const{
			return cred_superados;
		}

		bool Misma_Edad(const Alumno& otro)const{
			return edad == otro.Get_Edad();
		}

		bool Misma_ID(const Alumno& otro)const{
			return id == otro.Get_ID();
		}

		bool Mismo_Curso(const Alumno& otro)const{
			return curso == otro.Get_Curso();
		}

		bool Mismo_Pelo(const Alumno& otro)const{
			return pelo == otro.Get_Pelo();
		}

		bool Mismos_Creditos(const Alumno& otro)const{
			return cred_superados == otro.Get_Creditos();
		}

		bool Equal(const Alumno& otro)const{
			return Misma_Edad(otro) && Misma_ID(otro) &&
				Mismo_Curso(otro) && Mismo_Pelo(otro) && Mismos_Creditos(otro);
		}

};


int main(){

	Alumno A;
	Alumno B(10,19,celeste,segundo);

	cout << "A == B : " << (A.Equal(B)? "Si" : "No")<< endl;
	A.AjusteID(10);
	A.Tinte(celeste);
	A.Incrementa_Creditos(60);
	A.CambioCurso(segundo);
	A.Cumpleanos();

	cout << "A == B : " << (A.Equal(B)? "Si" : "No")<< endl;

	A.Reset_Creditos();

	cout << "A == B : " << (A.Equal(B)? "Si" : "No")<< endl;

	return 0;
}

/*
		En detalle
		---------------


*/
