#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;
struct registro
{
	string ID;
	string password;
};

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

