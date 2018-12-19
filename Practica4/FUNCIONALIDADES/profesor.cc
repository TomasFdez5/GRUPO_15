#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "profesor.h"
#include "agenda.h"

using namespace std;


Profesor::Profesor(char* id, char* password, int rol){
	strcpy(id_,id);
	strcpy(password_,password);
	role_=rol;
}

int Profesor::Logearse(Profesor aux){
 	struct registro read;
 	ifstream Profesores("Profesores.bin",ios::in| ios::binary);

 	if(Profesores.is_open()){
 		while(!Profesores.eof()){
			Profesores.read((char*)&read,sizeof(registro));
 			if(strcmp(read.ID,aux.id_)==0){
 				if(strcmp(read.password,aux.password_)==0){
 					if((aux.role_==read.rol) && (aux.role_==1)){
 						return 2;
 					}else{
						if((aux.role_==read.rol)&& (aux.role_==0)){
							return 1;
						}else{
							if(aux.role_!=read.rol){
								return -1;
							}
						}

					}

 				}
 				else{
 					return -2;
 				}
 			}

 		}

	}
 	Profesores.close();
 	return 0;
}


int Profesor::Registrarse(Profesor aux){

	int encontrado=0;
	struct registro read;
	ifstream Profesores("Profesores.bin", ios::in|ios::binary);
	Profesores.seekg(0, ios::beg);

	if(Profesores.is_open()){

 		while(!Profesores.eof()){

			Profesores.read((char*)&read,sizeof(registro));
 			if(strcmp(read.ID,aux.id_)==0){
 				encontrado=1;
 				Profesores.close();
 				return -1;
 			}
 		}
	}
	Profesores.close();
	if(encontrado==0){
		ofstream Profesores("Profesores.bin", ios::out|ios::binary);
		Profesores.seekp(0, ios::end);
		Profesores.write((char*)&aux, sizeof(registro));
		Profesores.close();

	}
	return encontrado;
 }

 list<class Alumno> Profesor::Cargar_copia(){
 	char aux[40];
	int entero=0;
 	Alumno alumno("A","b","c","d",0000000,"XXXX@gmail.com",0,"DD/MM/AA",0,9999);
 	
 	list<class Alumno> agendaAux;
 		
 	ifstream fich("agendaCOPIA.bin", ios::in|ios::binary);
 	fich.seekg(0,ios::beg);
 		if(fich.is_open()){
 			
  			while(!fich.eof()){
 				fich.read((char*)&aux,40);
	 			alumno.setDNI(aux);
	 			
	 			fich.read((char*)&aux,40);
	 			alumno.setNombre(aux);
	 			
	 			fich.read((char*)&aux,40);
	 			alumno.setApellidos(aux); 			

	 			fich.read((char*)&aux,40);
	 			alumno.setDireccion(aux);
	 			
	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setTelefono(entero);

	 			fich.read((char*)&aux,40);
	 			alumno.setEmail(aux);

	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setCurso(entero);

	 			fich.read((char*)&aux,40);
	 			alumno.setFecha(aux);

	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setEquipo(entero);

	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setLider(entero);
	 			agendaAux.push_back(alumno);
 				

  			}
  		
  		}
 	fich.close();
 	return agendaAux;
 }

 int Profesor::Guardar_copia(Agenda Aux){
 		char aux[40];
 		int entero=0;
 		ofstream fich("agendaCOPIA.bin");
 		fich.seekp(0,ios::beg);
 		list<Alumno>::iterator a1;
 		list<Alumno> lista;
 		lista=Aux.getAgenda();

 		for(a1=lista.begin();a1!=lista.end();a1++){
 			strcpy(aux,a1->getDNI().c_str());
 			fich.write((char*)&aux,40);

 			strcpy(aux,a1->getNombre().c_str());
 			fich.write((char*)&aux,40);

 			strcpy(aux,a1->getApellidos().c_str());
 			fich.write((char*)&aux,40);

 			strcpy(aux,a1->getDireccion().c_str());
 			fich.write((char*)&aux,40);

 			entero=a1->getTelefono();
 			fich.write((char*)&entero,sizeof(int));

 			strcpy(aux,a1->getEmail().c_str());
 			fich.write((char*)&aux,40);

 			entero=a1->getCurso();
 			fich.write((char*)&entero,sizeof(int));

 			strcpy(aux,a1->getFecha().c_str());
 			fich.write((char*)&aux,40);

 			entero=a1->getEquipo();
 			fich.write((char*)&entero,sizeof(int));

 			entero=a1->getLider();
 			fich.write((char*)&entero,sizeof(int));
 		}

 		fich.close();
 		return 1;
}
 list<class Alumno> Profesor::Cargar_fichero(string nombre){
	char aux[40];
	int entero=0;
	int tam=0;
 	Alumno alumno("A","b","c","d",0000000,"XXXX@gmail.com",0,"DD/MM/AA",0,9999);
 	
 	list<class Alumno> agendaAux;
 		
 	ifstream fich(nombre.c_str(), ios::in|ios::binary);
 	fich.seekg(0,ios::beg);
 		if(fich.is_open()){
 			
 			fich.seekg(0,ios::end);
 			tam=fich.tellg();
 			fich.seekg(0,ios::beg);
 			cout<<tam/sizeof(Alumno)<<endl;

 			tam=tam/sizeof(Alumno);

  			for(int i=0;i<tam;i++){
 				fich.read((char*)&aux,40);
	 			alumno.setDNI(aux);
	 			
	 			fich.read((char*)&aux,40);
	 			alumno.setNombre(aux);
	 			
	 			fich.read((char*)&aux,40);
	 			alumno.setApellidos(aux); 			

	 			fich.read((char*)&aux,40);
	 			alumno.setDireccion(aux);
	 			
	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setTelefono(entero);

	 			fich.read((char*)&aux,40);
	 			alumno.setEmail(aux);

	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setCurso(entero);

	 			fich.read((char*)&aux,40);
	 			alumno.setFecha(aux);

	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setEquipo(entero);

	 			fich.read((char*)&entero,sizeof(int));
	 			alumno.setLider(entero);
 				

	 			agendaAux.push_back(alumno);
  			}
  		
  		}
 	fich.close();
 	
 	return agendaAux;

 }
 int Profesor::Guardar_fichero(string nombre,Agenda Aux){
 	char aux[40];
 	int entero=0;
	int respuesta=0;
	ifstream copia(nombre.c_str());
	if(copia.is_open()){
		cout<<"El fichero ya existe. ¿Desea sobreescribirlo? Si 1 No 2"<<endl;
		cin>>respuesta;
		if(respuesta<1||respuesta>2||respuesta==2){
			cout<<"No ha introducido una respuesta valida. Cancelando ..."<<endl;
			copia.close();
			return 0;
		}
		copia.close();
	}
 		ofstream fich(nombre.c_str());
 		fich.seekp(0,ios::beg);
 		list<Alumno>::iterator a1;
 		list<Alumno> lista;
 		lista=Aux.getAgenda();
 		for(a1=lista.begin();a1!=lista.end();a1++){
 			strcpy(aux,a1->getDNI().c_str());
 			fich.write((char*)&aux,40);
 			strcpy(aux,a1->getNombre().c_str());
 			fich.write((char*)&aux,40);
 			strcpy(aux,a1->getApellidos().c_str());
 			fich.write((char*)&aux,40);
 			strcpy(aux,a1->getDireccion().c_str());
 			fich.write((char*)&aux,40);
 			entero=a1->getTelefono();
 			fich.write((char*)&entero,sizeof(int));
 			strcpy(aux,a1->getEmail().c_str());
 			fich.write((char*)&aux,40);
 			entero=a1->getCurso();
 			fich.write((char*)&entero,sizeof(int));
 			strcpy(aux,a1->getFecha().c_str());
 			fich.write((char*)&aux,40);
 			entero=a1->getEquipo();
 			fich.write((char*)&entero,sizeof(int));
 			entero=a1->getLider();
 			fich.write((char*)&entero,sizeof(int));
 		}

 		fich.close();
		return 1;
 }
