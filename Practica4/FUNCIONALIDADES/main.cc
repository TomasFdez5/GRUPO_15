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
				cout<<"______________________________________________"<<endl;
				cout<<"Introduzca los datos del jugador. Los marcados con * son campos obligatorios!"<<endl;
				cout<<"Introduzca su DNI* :"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{
					a.setDNI(cadena);
				}

				cout<<"Introduzca su nombre* :"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{
					a.setNombre(cadena);
				}

				cout<<"Introduzca su primer apellido* :"<<endl;
				getline(cin,apellido1);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{

					cout<<"Introduzca su segundo apellido* :"<<endl;
					getline(cin,apellido2);
					if(cadena==vacio){
						cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
						break;
					}else{

						apellidos=apellido1+" "+apellido2;
						a.setApellidos(apellidos);
					}
				}

				cout<<"Introduzca su direccion* :"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{

					a.setDireccion(cadena);
				}

				cout<<"Introduzca su Telefono* :"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{
					aux=atoi(cadena.c_str());
					a.setTelefono(aux);
				}

				cout<<"Introduzca su Email* :"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{

					a.setEmail(cadena);
				}

				cout<<"Introduzca su Curso* :"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{
					aux=atoi(cadena.c_str());
					a.setCurso(aux);
				}

				cout<<"Introduzca su Fecha* :"<<endl;
				cout<<"dd/mm/aaaa"<<endl;
				getline(cin,cadena);
				if(cadena==vacio){
					cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
					break;
				}else{

					a.setFecha(cadena);
				}

				cout<<"Introduzca su Equipo :"<<endl;
				getline(cin,cadena);
				aux=atoi(cadena.c_str());
				a.setEquipo(aux);

				cout<<"Introduzca si es Lider de su grupo :"<<endl;
				cout<<"true o false"<<endl;
				getline(cin,cadena);

				if(cadena=="true"){
					if(agend.comprobarlider(aux)){
						cout<<"En el equipo ya existe lider, estableciendo false..."<<endl;
						a.setLider(false);
					}else{
						a.setLider(true);
					}

				}else{
					if(cadena=="false"){
						a.setLider(false);
					}
					else{
						if(cadena!=vacio){
							cout<<"No se ha introducido de forma correcta."<<endl;
							cout<<"Lider = true, NO lider = false"<<endl;
						}
					}
				}
				agend.insertar(a);

				cout<<"Jugador introducido con exito!"<<endl;
				cout<<"______________________________________________\n"<<endl;

			break;


			case 2:
				cout<<"______________________________________________"<<endl;
				cout<<"Introduzca el criterio de busqueda : "<<endl;
				cout<<"Mediante su DNI	1\nMediante su apellido 2\nMediante el equipo al que pertenece	3"<<endl;
				cin>>opcion;
				if(opcion<1&&opcion>3){
					cout<<"Opción incorrecta! Cancelando..."<<endl;
					break;
				}
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
						case 2:
								cout<<"Introduzca el apellido del alumno a buscar."<<endl;
								getline(cin,cadena);
								if(cadena==vacio){
									cout<<"No se ha introducido ningun apellido. ERROR!!!!"<<endl;
									break;
								}
								if(agend.buscar1(cadena)==1){
									cout<<"El alumno existe en la agenda."<<endl;
								}else{
									cout<<"El alumno no existe en la agenda."<<endl;
								}
						break;

						case 3:
								cout<<"Introduzca el equipo al que pertenece el alumno a buscar."<<endl;

								cin>>aux;
								if(cadena==vacio){
									cout<<"No se ha introducido ningun equipo. ERROR!!!!"<<endl;
									break;
								}
								if(agend.buscar2(aux)==1){
									cout<<"El alumno existe en la agenda."<<endl;
								}else{
									cout<<"El alumno no existe en la agenda."<<endl;
								}
						break;
					};
					cout<<"______________________________________________\n"<<endl;



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
			cout<<"______________________________________________"<<endl;
			correcto=0;
			while(correcto==0){
					cout<<"Introduzca el criterio de ordenación deseado : "<<endl;
					cout<<"Alfabeticamente por nombre 1\n Alfabeticamente por apellido 2\n Numericamente por DNI 3\n Curso más alto matriculado 4."<<endl;
					cin>>aux;
					cout<<"Introduzca el método de ordenacion : "<<endl;
					cout<<"Ascendente 1\n Descendente 2"<<endl;
					cin>>orden;
					correcto=1;
					if((aux<1||aux>4)&&(orden<1||orden>2)){correcto=1;}
			}
			if(agend.mostrar_todos(aux,orden)==1){
				cout<<"Generando fichero markdown con el listado de alumnos...."<<endl;
			}

			cout<<"______________________________________________\n"<<endl;

			break;

			case 5:
			cout<<"______________________________________________"<<endl;
			cout<<"Introduzca el DNI del alumno a borrar."<<endl;
			getline(cin,cadena);
			if(cadena==vacio){
				cout<<"No se ha introducido ningun DNI. ERROR!!!!"<<endl;
				break;
			}
			agend.borrar(cadena);

			cout<<"______________________________________________\n"<<endl;

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
						cout<<"______________________________________________"<<endl;
						cout<<"Introduzca los datos del jugador. Los marcados con * son campos obligatorios!"<<endl;
						cout<<"Introduzca su DNI* :"<<endl;
						getline(cin,cadena);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{
							a.setDNI(cadena);
						}

						cout<<"Introduzca su nombre* :"<<endl;
						getline(cin,cadena);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{
							a.setNombre(cadena);
						}

						cout<<"Introduzca su primer apellido* :"<<endl;
						getline(cin,apellido1);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{

							cout<<"Introduzca su segundo apellido* :"<<endl;
							getline(cin,apellido2);
							if(cadena==vacio){
								cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
								break;
							}else{

								apellidos=apellido1+" "+apellido2;
								a.setApellidos(apellidos);
							}
						}

						cout<<"Introduzca su direccion* :"<<endl;
						getline(cin,cadena);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{

							a.setDireccion(cadena);
						}

						cout<<"Introduzca su Telefono* :"<<endl;
						getline(cin,cadena);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{
							aux=atoi(cadena.c_str());
							a.setTelefono(aux);
						}

						cout<<"Introduzca su Email* :"<<endl;
						getline(cin,cadena);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{

							a.setEmail(cadena);
						}

						cout<<"Introduzca su Curso* :"<<endl;
						getline(cin,cadena);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{
							aux=atoi(cadena.c_str());
							a.setCurso(aux);
						}

						cout<<"Introduzca su Fecha* :"<<endl;
						cout<<"dd/mm/aaaa"<<endl;
						getline(cin,cadena);
						if(cadena==vacio){
							cout<<"No se ha introducido el campo obligatorio. ERROR!!!!"<<endl;
							break;
						}else{

							a.setFecha(cadena);
						}

						cout<<"Introduzca su Equipo :"<<endl;
						getline(cin,cadena);
						aux=atoi(cadena.c_str());
						a.setEquipo(aux);

						cout<<"Introduzca si es Lider de su grupo :"<<endl;
						cout<<"true o false"<<endl;
						getline(cin,cadena);

						if(cadena=="true"){
							if(agend.comprobarlider(aux)){
								cout<<"En el equipo ya existe lider, estableciendo false..."<<endl;
								a.setLider(false);
							}else{
								a.setLider(true);
							}

						}else{
							if(cadena=="false"){
								a.setLider(false);
							}
							else{
								if(cadena!=vacio){
									cout<<"No se ha introducido de forma correcta."<<endl;
									cout<<"Lider = true, NO lider = false"<<endl;
								}
							}
						}
						agend.insertar(a);

						cout<<"Jugador introducido con exito!"<<endl;
						cout<<"______________________________________________\n"<<endl;

					break;


					case 2:
						cout<<"______________________________________________"<<endl;
						cout<<"Introduzca el criterio de busqueda : "<<endl;
						cout<<"Mediante su DNI	1\nMediante su apellido 2\nMediante el equipo al que pertenece	3"<<endl;
						cin>>opcion;
						if(opcion<1&&opcion>3){
							cout<<"Opción incorrecta! Cancelando..."<<endl;
							break;
						}
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
								case 2:
										cout<<"Introduzca el apellido del alumno a buscar."<<endl;
										getline(cin,cadena);
										if(cadena==vacio){
											cout<<"No se ha introducido ningun apellido. ERROR!!!!"<<endl;
											break;
										}
										if(agend.buscar1(cadena)==1){
											cout<<"El alumno existe en la agenda."<<endl;
										}else{
											cout<<"El alumno no existe en la agenda."<<endl;
										}
								break;

								case 3:
										cout<<"Introduzca el equipo al que pertenece el alumno a buscar."<<endl;

										cin>>aux;
										if(cadena==vacio){
											cout<<"No se ha introducido ningun equipo. ERROR!!!!"<<endl;
											break;
										}
										if(agend.buscar2(aux)==1){
											cout<<"El alumno existe en la agenda."<<endl;
										}else{
											cout<<"El alumno no existe en la agenda."<<endl;
										}
								break;
							};
							cout<<"______________________________________________\n"<<endl;



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
					cout<<"______________________________________________"<<endl;
					correcto=0;
					while(correcto==0){
							cout<<"Introduzca el criterio de ordenación deseado : "<<endl;
							cout<<"Alfabeticamente por nombre 1\n Alfabeticamente por apellido 2\n Numericamente por DNI 3\n Curso más alto matriculado 4."<<endl;
							cin>>aux;
							cout<<"Introduzca el método de ordenacion : "<<endl;
							cout<<"Ascendente 1\n Descendente 2"<<endl;
							cin>>orden;
							correcto=1;
							if((aux<1||aux>4)&&(orden<1||orden>2)){correcto=1;}
					}
					if(agend.mostrar_todos(aux,orden)==1){
						cout<<"Generando fichero markdown con el listado de alumnos...."<<endl;
					}

					cout<<"______________________________________________\n"<<endl;

					break;

					case 5:
					cout<<"______________________________________________"<<endl;
					cout<<"Introduzca el DNI del alumno a borrar."<<endl;
					getline(cin,cadena);
					if(cadena==vacio){
						cout<<"No se ha introducido ningun DNI. ERROR!!!!"<<endl;
						break;
					}
					agend.borrar(cadena);

					cout<<"______________________________________________\n"<<endl;

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

				}

			}while((opcion<9)&&(opcion>0));

		}


		}

	return 0;


}
