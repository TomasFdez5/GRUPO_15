#include "agenda.h"
#include "alumno.h"
#include <fstream>


using namespace std;


Agenda::Agenda(){}

void Agenda::insertar(Alumno alumno){
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(alumno.getDNI()==a1->getDNI()){
			cout<<"El identificador del alumno (DNI) ya existe en la lista."<<endl;
			break;
		}
		if(alumno.getEmail()==a1->getEmail()){
			cout<<"El identificador del alumno (DNI) ya existe en la lista."<<endl;
			break;
		}
	}
	agenda_.push_back(alumno);
}


int Agenda::buscar(string dni){
	list<Alumno>::iterator a1;
	int encontrado=0;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(dni==a1->getDNI()){
			encontrado=1;
		}
	}

	return encontrado;
}
int Agenda::buscar1(string apellidos){
	int encontrado=0;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(apellidos==a1->getApellidos()){
			encontrado=1;
		}
	}

	return encontrado;
}

int Agenda::buscar2(int equipo){
	list<Alumno>::iterator a1;
	int encontrado=0;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(equipo==a1->getEquipo()){
			encontrado=1;

		}
	}

	return encontrado;
}