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
 					return 0;
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
 	//Alumno aux("A","b","c","d",0000000,"XXXX@gmail.com",0,"DD/MM/AA",0,9999);
 	list<class Alumno> agendaAux;
 	registroAlumno alumAux;
 	cout<<"1"<<endl;
 	ifstream ficherosalida("agendaCOPIA.bin", ios::in|ios::binary);
 	ficherosalida.seekg(0,ios::beg);
 		if(ficherosalida.is_open()){
 			cout<<"2"<<endl;
  			while(!ficherosalida.eof()){
 				ficherosalida.read((char*)&alumAux,sizeof(registroAlumno));
 				Alumno aux(alumAux.dni, alumAux.nombre, alumAux.apellidos, alumAux.direccion,alumAux.telefono,alumAux.email,alumAux.curso,alumAux.fecha,alumAux.equipo,alumAux.lider);
 				agendaAux.push_back(aux);

  			}
  		cout<<"3"<<endl;
  		}
 	ficherosalida.close();
 	cout<<"4"<<endl;
 	return agendaAux;
 }

 int Profesor::Guardar_copia(Agenda Aux){

 		ofstream fich("agendaCOPIA.bin");
 
 		list<Alumno>::iterator a1;

 		for(a1=Aux.getAgenda().begin();a1!=Aux.getAgenda().end();a1++){
 			fich.write((char*)&a1,sizeof(Alumno));
 		}

 		fich.close();
		return 1;

 }
 int Profesor::Cargar_fichero(string nombre,Agenda agenda){
 	Alumno aux("A","b","c","d",0000000,"XXXX@gmail.com",0,"DD/MM/AA",0,9999);
 	list<class Alumno> agendaAux;
 	ifstream ficherosalida(nombre.c_str(), ios::in|ios::binary);
 	ficherosalida.seekg(0,ios::beg);
 		if(!ficherosalida.is_open()){
			return 0;
		}
 		if(ficherosalida.is_open()){
  			while(!ficherosalida.eof()){
 				ficherosalida.read((char*)&aux,sizeof(Alumno));
 				agendaAux.push_back(aux);

  			}
  		}
	agenda.setAgenda(agendaAux);
 	ficherosalida.close();
 	return 1;

 }
 int Profesor::Guardar_fichero(string nombre,Agenda Aux){
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
 		//fich.seekp(0, ios::beg);
 		list<Alumno>::iterator a1;

 		for(a1=Aux.getAgenda().begin();a1!=Aux.getAgenda().end();a1++){
 			fich.write((char*)&a1,sizeof(Alumno));
 		}

 		fich.close();
		return 1;
 }
