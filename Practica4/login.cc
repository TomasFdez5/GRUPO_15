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

int log_in(struct registro aux ){
 	struct registro read;
 	ifstream Profesores("Profesores.bin", ios::binary);
 	Profesores.seekg(0, ios::beg);
 	if(Profesores.is_open()){
 		while(!Profesores.eof()){
			Profesores.read((char*)&read,sizeof(registro));
 			cout<<read.ID<<endl;
 			cout<<read.password<<endl;
 			Profesores.seekg(sizeof(registro),ios::cur);	
 		}
	}
 			Profesores.close();
}
