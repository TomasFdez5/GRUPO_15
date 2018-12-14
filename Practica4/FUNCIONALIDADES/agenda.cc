#include "agenda.h"
#include "alumno.h"
#include <fstream>


using namespace std;


/*
Modulo ordenacion
*/
bool nombreASC(Alumno a,Alumno b){return a.getNombre()>b.getNombre();}
bool nombreDESC(Alumno a,Alumno b){return a.getNombre()<b.getNombre();}
bool apellidoASC(Alumno a,Alumno b){return a.getApellidos()>b.getApellidos();}
bool apellidoDESC(Alumno a,Alumno b){return a.getApellidos()<b.getApellidos();}
bool dniASC(Alumno a,Alumno b){return a.getDNI()>b.getDNI();}
bool dniDESC(Alumno a,Alumno b){return a.getDNI()<b.getDNI();}
bool equipoASC(Alumno a,Alumno b){return a.getEquipo()>b.getEquipo();}
bool equipoDESC(Alumno a,Alumno b){return a.getEquipo()<b.getEquipo();}


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



void Agenda::mostrar(string cadena){
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(a1->getDNI()==cadena&&buscar((cadena))==1){
			string cadena=(*a1).getDNI()+".md";
			ofstream ficherosalida(cadena.c_str());
			ficherosalida<<"** DNI : "<<(*a1).getDNI()<<endl;
			ficherosalida<<"** Nombre : "<<(*a1).getNombre()<<endl;
			ficherosalida<<"** Apellidos : "<<(*a1).getApellidos()<<endl;
			ficherosalida<<"** Direccion : "<<(*a1).getDireccion()<<endl;
			ficherosalida<<"** Telefono : "<<(*a1).getTelefono()<<endl;
			ficherosalida<<"** Email : "<<(*a1).getEmail()<<endl;
			ficherosalida<<"** Curso : "<<(*a1).getCurso()<<endl;
			ficherosalida<<"** Fecha de nacimiento : "<<(*a1).getFecha()<<endl;
			ficherosalida<<"** Equipo : "<<(*a1).getEquipo()<<endl;
			if((*a1).getLider()==1){
				ficherosalida<<"** Lider : SI "<<endl;
			}
			else{
				ficherosalida<<"** Lider : NO "<<endl;
			}
			imprimir(*a1);
			ficherosalida.close();
		}
	}

}


int Agenda::mostrar_todos(int seleccion,int orden){
	ofstream ficherosalida("agenda.md");
	list<Alumno>::iterator a1;
	int i = 1;
	if(agenda_.empty()){
		ficherosalida.close();
		return 0;
	}
	if(seleccion==1&&orden==1){agenda_.sort(nombreASC);}
	if(seleccion==1&&orden==2){agenda_.sort(nombreDESC);}
	if(seleccion==2&&orden==1){agenda_.sort(apellidoASC);}
	if(seleccion==2&&orden==2){agenda_.sort(apellidoDESC);}
	if(seleccion==3&&orden==1){agenda_.sort(dniASC);}
	if(seleccion==3&&orden==2){agenda_.sort(dniDESC);}
	if(seleccion==2&&orden==1){agenda_.sort(equipoASC);}
	if(seleccion==2&&orden==2){agenda_.sort(equipoDESC);}

	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		ficherosalida<<"### Alumno "<<i<<endl;
		ficherosalida<<"** DNI : "<<(*a1).getDNI()<<endl;
		ficherosalida<<"** Nombre : "<<(*a1).getNombre()<<endl;
		ficherosalida<<"** Apellidos : "<<(*a1).getApellidos()<<endl;
		ficherosalida<<"** Direccion : "<<(*a1).getDireccion()<<endl;
		ficherosalida<<"** Telefono : "<<(*a1).getTelefono()<<endl;
		ficherosalida<<"** Email : "<<(*a1).getEmail()<<endl;
		ficherosalida<<"** Curso : "<<(*a1).getCurso()<<endl;
		ficherosalida<<"** Fecha de nacimiento : "<<(*a1).getFecha()<<endl;
		ficherosalida<<"** Equipo : "<<(*a1).getEquipo()<<endl;
		if((*a1).getLider()==1){
			ficherosalida<<"** Lider : SI "<<endl;
		}
		else{
			ficherosalida<<"** Lider : NO "<<endl;
		}
		i++;
	}
	ficherosalida.close();
	return 1;
}
