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