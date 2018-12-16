#include "agenda.h"
#include "alumno.h"
#include <fstream>


using namespace std;
/*
Modulo ordenacion
*/
bool nombreASC(Alumno a,Alumno b){return a.getNombre()<b.getNombre();}
bool nombreDESC(Alumno a,Alumno b){return a.getNombre()>b.getNombre();}
bool apellidoASC(Alumno a,Alumno b){return a.getApellidos()<b.getApellidos();}
bool apellidoDESC(Alumno a,Alumno b){return a.getApellidos()>b.getApellidos();}
bool dniASC(Alumno a,Alumno b){return a.getDNI()<b.getDNI();}
bool dniDESC(Alumno a,Alumno b){return a.getDNI()>b.getDNI();}
bool equipoASC(Alumno a,Alumno b){return a.getEquipo()<b.getEquipo();}
bool equipoDESC(Alumno a,Alumno b){return a.getEquipo()>b.getEquipo();}


Agenda::Agenda(){}

int Agenda::comprobarlider(int team){
	list<Alumno>::iterator a1;
	list<Alumno>::iterator b2;
	int encontrado=0;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(a1->getEquipo()==team){
			for(b2=agenda_.begin();b2!=agenda_.end();b2++){
				if(b2->getLider()==1){
					encontrado=1;
				}
			}
		}
	}
	return encontrado;
}


int Agenda::insertar(Alumno alumno){
	int contador=0;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(alumno.getDNI()==a1->getDNI()){
			cout<<"El identificador del alumno (DNI) ya existe en la lista."<<endl;
			return -1;
		}
		if(alumno.getEmail()==a1->getEmail()){
			cout<<"El correo del alumno ya existe en la lista."<<endl;
			return -1;
		}
		if(alumno.getEquipo()==a1->getEquipo()){
			contador++;
		}
	}
	if(contador<3){
		agenda_.push_back(alumno);
		cout<<"Alumno introducido con exito!"<<endl;
		return 1;
	}
	else{
		cout<<"Equipo completo"<<endl;
		return -1;
	}
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
//Funcion que se encarga de imprimir los datos por pantalla
void Agenda::imprimir(Alumno alumno){
	cout<<"NOMBRE :	"<<alumno.getNombre() <<endl;
	cout<<"APELLIDOS : "<< alumno.getApellidos()<<endl;
	cout<<"DNI : "<<alumno.getDNI() <<endl;
	cout<<"DIRECCION : "<<alumno.getDireccion() <<endl;
	cout<<"TELEFONO : "<<alumno.getTelefono() <<endl;
	cout<<"EMAIL : "<<alumno.getEmail() <<endl;
	cout<<"CURSO : "<<alumno.getCurso() <<endl;
	cout<<"FECHA : "<< alumno.getFecha()<<endl;
	cout<<"EQUIPO : "<<alumno.getEquipo() <<endl;
	if(alumno.getLider()==1){
		cout<<"LIDER : SI"<<endl;
	}
	else{
		cout<<"LIDER : NO"<<endl;
	}
}

void Agenda::mostrar(string cadena){
	int iter=1;
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
			cout<<"\tAlumno "<<iter<<" : "<<endl;
			cout<<"|==========================|"<<endl;
			imprimir(*a1);
			cout<<"|==========================|"<<endl;
			ficherosalida.close();
		}
		iter++;
	}

}
void Agenda::mostrar1(string cadena){
	int iter=1;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(a1->getApellidos()==cadena&&buscar1((cadena))==1){
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
			cout<<"\tAlumno "<<iter<<" : "<<endl;
			cout<<"|==========================|"<<endl;
			imprimir(*a1);
			cout<<"|==========================|"<<endl;
			ficherosalida.close();
		}
	}

}

void Agenda::mostrar2(int equipo){
	int iter=1;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(a1->getEquipo()==equipo&&buscar2((equipo))==1){
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
			cout<<"\tAlumno "<<iter<<" : "<<endl;
			cout<<"|==========================|"<<endl;
			imprimir(*a1);
			cout<<"|==========================|"<<endl;
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
	if(seleccion==4&&orden==1){agenda_.sort(equipoASC);}
	if(seleccion==4&&orden==2){agenda_.sort(equipoDESC);}

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
		cout<<"Error! Lista vacia, no se puede borrar."<<endl;
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
			cout<<"9. Telefono"<<endl;
			cout<<"10. Condición de lider"<<endl;
			cout<<"11. Salir"<<endl;
			cout<<"____________________________________________"<<endl;
			cin>>n;
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
					cout<<"Nuevo telefono"<<endl;
					cin>>aux;
					a1->setTelefono(aux);
					break;

					case 10:
					cout<<"Introduzca 0 si no es lider"<<endl;
					cout<<"Introduzca 1 si es lider"<<endl;
					list<Alumno>::iterator a2;
					for(a2=agenda_.begin();a2!=agenda_.end();a2++){
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
						cout<<"El equipo "<<a1->getEquipo()<<" sin lider"<<endl;

					}
					a1->setLider(aux);
					break;
				};
			
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
			cout<<"9. Telefono"<<endl;
			cout<<"10. Condición de lider"<<endl;
			cout<<"11. Salir"<<endl;
			cout<<"____________________________________________"<<endl;
			cin>>n;
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
					cout<<"Nuevo telefono"<<endl;
					cin>>aux;
					a1->setTelefono(aux);
					break;

					case 10:
					cout<<"Introduzca 0 si no es lider"<<endl;
					cout<<"Introduzca 1 si es lider"<<endl;
					list<Alumno>::iterator a2;
					for(a2=agenda_.begin();a2!=agenda_.end();a2++){
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
						cout<<"El equipo "<<a1->getEquipo()<<" sin lider"<<endl;

					}
					a1->setLider(aux);
					break;

				};
			
		}
	}
	if(find==0){
		cout<<"Error no existe el alumno"<<endl;
	}
}

void Agenda::setAgenda(list<Alumno> aux){
	agenda_.clear();
	list<Alumno>::iterator a1;
	for(a1=aux.begin();a1!=aux.end();a1++){
		agenda_.push_back((*a1));
	}
}
