#include <iostream>
#include <string>

#include "alumno.h"

using namespace std;


Alumno::Alumno(string DNI, string Nombre, string Apellidos, string Direccion, int Telefono, string Email, int Curso, string Fecha, int Equipo, int Lider){
	DNI_=DNI;
	Nombre_=Nombre;
	Apellidos_=Apellidos;
	Direccion_=Direccion;
	Telefono_=Telefono;
	Email_=Email;
	Curso_=Curso;
	Fecha_=Fecha;
	Equipo_=Equipo;
	Lider_=Lider;
}
