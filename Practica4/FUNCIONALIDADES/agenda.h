//persona.h
//Declaracion de la clase persona

#ifndef AGENDA_H
#define AGENDA_H

#include "alumno.h"

#include <string>

#include <list>
using namespace std;

class Agenda{
	private:
		list<class Alumno> agenda_;
	public:

		Agenda();

		void insertar(Alumno alumno);

		int buscar(string dni);
		int buscar1(string apellidos);
		int buscar2(int equipo);

		void modificar(string dni);
		void modificar1(string apellidos);

		int borrar(string dni);
		int borrar1(string apellidos);

		void mostrar(string cadena);
		int mostrar_todos(int seleccion,int orden);

		//Funciones auxiliares
		void imprimir(Alumno alumno);
		int comprobarlider(int team);

		inline list<class Alumno> getAgenda(){return agenda_;};
		void setAgenda(list<class Alumno>);



};



#endif
