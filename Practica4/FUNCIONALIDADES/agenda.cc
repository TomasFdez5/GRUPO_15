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


int Agenda::borrar(string dni){
	list<Alumno>::iterator a1;

	if(agenda_.empty()){
		return -1;
	}
	for(a1=agenda_.begin(); a1!=agenda_.end();a1++){
		if(dni==a1->getDNI()){
			agenda_.erase(a1);
			return 1;
		}
	}
	return 2;
}

int Agenda::borrar1(string apellidos){
	list<Alumno>::iterator a1;

	if(agenda_.empty()){
		return -1;
	}
	for(a1=agenda_.begin(); a1!=agenda_.end();a1++){
		if(apellidos==a1->getApellidos()){
			agenda_.erase(a1);
			return 1;
		}
	}
	return 2;
}


void Agenda::modificar(string dni){
	int find=0;
	int n;
	int aux;
	string aux_t;
	int existe=0;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(dni==a1->getDNI()){
			find=1;
			cout<<"¿Que campo quiere modificar?"<<endl;
			cout<<"____________________________________________"<<endl;
			cout<<"1. Nombre"<<endl;
			cout<<"2. Apellidos"<<endl;
			cout<<"3. DNI"<<endl;
			cout<<"4. Direccion"<<endl;
			cout<<"5. Email"<<endl;
			cout<<"6. Curso"<<endl;
			cout<<"7. Fecha"<<endl;
			cout<<"8. Equipo"<<endl;
			cout<<"9. Condición de lider"<<endl;
			cout<<"10. Salir"<<endl;
			cout<<"____________________________________________"<<endl;
			cin>>n;
			//while(n>0 && n<10){
					getchar();
				switch(n){
					case 1:
						cout<<"Nuevo nombre"<<endl;
						getline(cin, aux_t);
						a1->setNombre(aux_t);
					break;
					case 2:
						cout<<"Nuevos apellidos"<<endl;
						getline(cin, aux_t);
						a1->setApellidos(aux_t);
					break;
					case 3:
						cout<<"Nuevo DNI"<<endl;
						getline(cin, aux_t);
						a1->setDNI(aux_t);
					break;
					case 4:
						cout<<"Nueva direccion"<<endl;
						getline(cin, aux_t);
						a1->setDireccion(aux_t);
					break;
					case 5:
						cout<<"Nuevo email"<<endl;
						getline(cin, aux_t);
						a1->setEmail(aux_t);
					break;
					case 6:
						cout<<"Nuevo curso"<<endl;
						cin>>aux;
						a1->setCurso(aux);
					break;
					case 7:
						cout<<"Nueva fecha"<<endl;
						getline(cin, aux_t);
						a1->setFecha(aux_t);
					break;
					case 8:
						cout<<"Nuevo equipo"<<endl;
						cin>>aux;
						a1->setEquipo(aux);
					break;
					case 9:
					cout<<"Introduzca 0 si no es lider"<<endl;
					cout<<"Introduzca 1 si es lider"<<endl;
					list<Alumno>::iterator a2;
					for(a2=agenda_.begin();a2!=agenda_.end();a1++){
						if(a1->getEquipo()==a2->getEquipo()){
							if(a2->getLider()==1){
								existe=1;
							}
						}
					}
					cin>>aux;
					if(existe==1 && aux==1){
						cout<<"Error ya hay un lider"<<endl;
						break;
					}
					if(a1->getLider()==1 && aux==0){
						cout<<"Advertencia: Se ha borrado al lider"<<endl;

					}
					a1->setLider(aux);
					break;
				};
			//}
		}
	}
	if(find==0){
		cout<<"Error no existe el alumno"<<endl;
	}
}
void Agenda::modificar1(string apellidos){
	int find=0;
	int n;
	int aux;
	string aux_t;
	int existe=0;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(apellidos==a1->getApellidos()){
			find=1;
			cout<<"¿Que campo quiere modificar?"<<endl;
			cout<<"____________________________________________"<<endl;
			cout<<"1. Nombre"<<endl;
			cout<<"2. Apellidos"<<endl;
			cout<<"3. DNI"<<endl;
			cout<<"4. Direccion"<<endl;
			cout<<"5. Email"<<endl;
			cout<<"6. Curso"<<endl;
			cout<<"7. Fecha"<<endl;
			cout<<"8. Equipo"<<endl;
			cout<<"9. Condición de lider"<<endl;
			cout<<"10. Salir"<<endl;
			cout<<"____________________________________________"<<endl;
			cin>>n;
			//while(n>0 && n<10){
				switch(n){
					case 1:
						cout<<"Nuevo nombre"<<endl;
						getline(cin, aux_t);
						a1->setNombre(aux_t);
					break;
					case 2:
						cout<<"Nuevos apellidos"<<endl;
						getline(cin, aux_t);
						a1->setApellidos(aux_t);
					break;
					case 3:
						cout<<"Nuevo DNI"<<endl;
						getline(cin, aux_t);
						a1->setDNI(aux_t);
					break;
					case 4:
						cout<<"Nueva direccion"<<endl;
						getline(cin, aux_t);
						a1->setDireccion(aux_t);
					break;
					case 5:
						cout<<"Nuevo email"<<endl;
						getline(cin, aux_t);
						a1->setEmail(aux_t);
					break;
					case 6:
						cout<<"Nuevo curso"<<endl;
						cin>>aux;
						a1->setCurso(aux);
					break;
					case 7:
						cout<<"Nueva fecha"<<endl;
						getline(cin, aux_t);
						a1->setFecha(aux_t);
					break;
					case 8:
						cout<<"Nuevo equipo"<<endl;
						cin>>aux;
						a1->setEquipo(aux);
					break;
					case 9:
					cout<<"Introduzca 0 si no es lider"<<endl;
					cout<<"Introduzaca 1 si es lider"<<endl;
					list<Alumno>::iterator a2;
					for(a2=agenda_.begin();a2!=agenda_.end();a1++){
						if(a1->getEquipo()==a2->getEquipo()){
							if(a2->getLider()==1){
								existe=1;
							}
						}
					}
					cin>>aux;
					if(existe==1 && aux==1){
						cout<<"Error ya hay un lider"<<endl;
						break;
					}
					if(a1->getLider()==1 && aux==0){
						cout<<"Advertencia: Se ha borrado al lider"<<endl;

					}
					a1->setLider(aux);
					break;
				};
			//}
		}
	}
	if(find==0){
		cout<<"Error no existe el alumno"<<endl;
	}
}
