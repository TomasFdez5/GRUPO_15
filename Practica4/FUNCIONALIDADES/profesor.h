//profesor.h
//Declaracion de la clase profesor

#ifndef PROFESOR_H
#define PROFESOR_H

#include "alumno.h"
#include "agenda.h"

#include <string>
#include <list>
using namespace std;


struct registro
{
	char ID[20];
	char password[20];
	int rol;
};

class Profesor{
	private:
		char id_[20];
		char password_[20];
		int role_;

	public:
		Profesor(char* id,char* password, int rol);
		int Registrarse(Profesor aux);
		int Logearse(Profesor aux);
		list<class Alumno> Cargar_copia();
		int Guardar_copia(Agenda Aux);
		 list<class Alumno> Cargar_fichero(string nombre);
		int Guardar_fichero(string nombre,Agenda Aux);
		inline int getRole()const{return role_;};




};



#endif
