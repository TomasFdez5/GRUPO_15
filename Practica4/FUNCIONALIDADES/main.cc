#include "alumno.h"
#include "agenda.h"
#include "profesor.h"

#include <string>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <iostream>

using namespace std;


int main(){
	int opcion=0;
	int aux=0;
	int orden=0;
	int correcto=0;

	string cadena,vacio;
	string apellido1,apellido2,apellidos;
	string nombrefichero;

	string DNI,  Nombre,  Apellidos,  Direccion,  Email, Fecha;
	int Telefono=0, Curso=0,Equipo=0;
	int Lider;
	Alumno a(DNI, Nombre, Apellidos, Direccion,Telefono,Email,Curso,Fecha,Equipo=0,Lider=0);
	Agenda agend;

	char id[20];
	char password[20];
	int rol=0;

	cout<<"registrarse(1) o logearse(2)"<<endl;
		cin>>opcion;

		cout<<"Introduzca su ID : "<<endl;
			cin>>id;
			cout<<"Introduzca su contraseña : "<<endl;
			cin>>password;
			cout<<"Introduzca su rol : coordinador (1) o profesor (0)"<<endl;
			cin>>rol;
			Profesor profesor(id,password,rol);

		if(opcion==1){
			profesor.Registrarse(profesor);

		}
		if(opcion==2){
			if(profesor.Logearse(profesor)==0){
					cout<<"El usuario no se encuentra registrado."<<endl;
					cout<<"¿Desea registrarse? SI (1)  NO (0)"<<endl;
					cin>>aux;
					if(aux==1){
						cout<<" Vuelva a introduzca su ID : "<<endl;
						cin>>id;
						cout<<" Vuelva a introduzca su contraseña : "<<endl;
						cin>>password;
						cout<<" Vuelva a introduzca su rol : coordinador (1) o profesor (0)"<<endl;
						cin>>rol;
						if(rol!=1&&rol!=0){rol=0;}
						Profesor profesor(id,password,rol);
						profesor.Registrarse(profesor);

					}
					if(aux==0){
						cout<<"Saliendo..."<<endl;
						return 0;
					}
		}
			if(profesor.Logearse(profesor)==-1){
					cout<<"Role seleccionado no te pertenece."<<endl;
					return -1;
			}

		}



	if(profesor.getRole()==1){
		do{
		//getchar();
		cout<<"______________________________________________"<<endl;
		cout<<"Elija una opción:"<<endl;

		cout<<"1. Añadir un alumno."<<endl;

		cout<<"2. Buscar un alumno."<<endl;

		cout<<"3. Mostrar un alumno."<<endl;

		cout<<"4. Mostrar el listado completo de alumnos."<<endl;

		cout<<"5. Borrar un alumno."<<endl;

		cout<<"6. Modificar un alumno."<<endl;

		cout<<"7. Cargar"<<endl;

		cout<<"8. Guardar"<<endl;

		cout<<"9. Cargar copia de seguridad"<<endl;

		cout<<"10. Guardar en copia de seguridad"<<endl;

		cout<<"11. Salir del programa "<<endl;

		cout<<"______________________________________________"<<endl;

		cout<<"Elija una opcion :"<<endl;
		cin>>opcion;
		getchar();

		switch(opcion){
			case 1:
			cout<<"Introduzca el DNI del alumno a buscar."<<endl;

			getline(cin,cadena);
			if(cadena==vacio){
				cout<<"No se ha introducido ningun DNI. ERROR!!!!"<<endl;
				break;
			}
			if(agend.buscar(cadena)==1){
				cout<<"El alumno existe en la agenda."<<endl;
			}else{
				cout<<"El alumno no existe en la agenda."<<endl;
			}
	break;

		  break;

			case 2:


			break;
			case 3:
			cout<<"______________________________________________"<<endl;
			cout<<"Introduzca el DNI del alumno a mostrar."<<endl;
			getline(cin,cadena);
			if(cadena==vacio){
				cout<<"No se ha introducido ningun DNI. ERROR!!!!"<<endl;
				break;
			}

			agend.mostrar(cadena);

			cout<<"______________________________________________\n"<<endl;
			break;

			case 4:

			break;

			case 5:


				break;
			case 6:
			cout<<"______________________________________________"<<endl;
			cout<<"Introduzca el DNI del alumno a modificar."<<endl;
			getline(cin,cadena);
			if(cadena==vacio){
				cout<<"No se ha introducido ningun DNI. ERROR!!!!"<<endl;
				break;
			}
			agend.modificar(cadena);

			cout<<"______________________________________________\n"<<endl;

			break;

			case 7:

			break;

			case 8:


			break;

			case 9:

			break;

			case 10:


			break;

		}

	}while((opcion<11)&&(opcion>0));
	}
	else{
		if(profesor.getRole()==0){
			do{
				//getchar();
				cout<<"______________________________________________"<<endl;
				cout<<"Elija una opción:"<<endl;

				cout<<"1. Añadir un alumno."<<endl;

				cout<<"2. Buscar un alumno."<<endl;

				cout<<"3. Mostrar un alumno."<<endl;

				cout<<"4. Mostrar el listado completo de alumnos."<<endl;

				cout<<"5. Borrar un alumno."<<endl;

				cout<<"6. Modificar un alumno."<<endl;

				cout<<"7. Cargar"<<endl;

				cout<<"8. Guardar"<<endl;

				cout<<"9. Salir del programa "<<endl;

				cout<<"______________________________________________"<<endl;

				cout<<"Elija una opcion :"<<endl;
				cin>>opcion;
				getchar();

				switch(opcion){
					case 1:

						break;

					case 2:


						break;
					case 3:

						break;

					case 4:

					break;

					case 5:


					break;
					case 6:

					break;

					case 7:

					break;

					case 8:


					break;

				}

			}while((opcion<9)&&(opcion>0));

		}


		}

	return 0;


}
