//profesor.h
//Declaracion de la clase profesor

#ifndef PROFESOR_H
#define PROFESOR_H

#include "alumno.h"
#include "agenda.h"

#include <string>
#include <list>
using namespace std;

struct registroAlumno{
	char nombre[20];
	char apellidos[40];
	char dni[9];
	char direccion[50];
	int telefono;
	char email[20];
	int curso;
	char fecha[10];
	int equipo;
	int lider;
};
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
		int Cargar_fichero(string nombre,Agenda aux);
		int Guardar_fichero(string nombre,Agenda Aux);
		inline int getRole()const{return role_;};




};



#endif
