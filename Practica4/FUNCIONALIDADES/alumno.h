#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <string>

using namespace std;

class Alumno{
private:
string Nombre_;
string Apellidos_;
string DNI_;
string Direccion_;
int Telefono_;
string Email_;
int Curso_;
string Fecha_;
int Equipo_;
int Lider_;


public:
Alumno(string DNI, string Nombre, string Apellidos, string Direccion, int Telefono, string Email, int Curso, string Fecha, int Equipo, int Lider);

inline string getDNI()const{return DNI_;};
inline string getNombre()const{return Nombre_;};
inline string getApellidos()const{return Apellidos_;};
inline string getDireccion()const{return Direccion_;};
inline int getTelefono()const{return Telefono_;};
inline string getEmail()const{return Email_;};
inline int getCurso()const{return Curso_;};
inline string getFecha()const{return Fecha_;};
inline int getEquipo()const{return Equipo_;};
inline int getLider()const{return Lider_;};

inline void setDNI(string aux){DNI_=aux;};
inline void setNombre(string aux){Nombre_=aux;};
inline void setApellidos(string aux){Apellidos_=aux;};
inline void setDireccion(string aux){Direccion_=aux;};
inline void setTelefono(int aux){Telefono_=aux;};
inline void setEmail(string aux){Email_=aux;};
inline void setCurso(int aux){Curso_=aux;};
inline void setFecha(string aux){Fecha_=aux;};
inline void setEquipo(int aux){Equipo_=aux;};
inline void setLider(int aux){Lider_=aux;};

};

#endif
