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

void log_up(struct registro aux){

	ofstream Profesores("Profesores.bin", ios::binary);
	Profesores.seekp(0, ios::end);
	Profesores.write((char*)&aux, sizeof(registro));
	Profesores.close();
 }

