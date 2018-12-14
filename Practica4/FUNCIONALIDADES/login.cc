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
