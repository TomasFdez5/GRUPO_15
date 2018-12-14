
/*
Modulo ordenacion
*/
bool nombreASC(Alumno a,Alumno b){return a.getNombre()>b.getNombre();}
bool nombreDESC(Alumno a,Alumno b){return a.getNombre()<b.getNombre();}
bool apellidoASC(Alumno a,Alumno b){return a.getApellidos()>b.getApellidos();}
bool apellidoDESC(Alumno a,Alumno b){return a.getApellidos()<b.getApellidos();}
bool dniASC(Alumno a,Alumno b){return a.getDNI()>b.getDNI();}
bool dniDESC(Alumno a,Alumno b){return a.getDNI()<b.getDNI();}
bool equipoASC(Alumno a,Alumno b){return a.getEquipo()>b.getEquipo();}
bool equipoDESC(Alumno a,Alumno b){return a.getEquipo()<b.getEquipo();}



int Agenda::mostrar_todos(int seleccion,int orden){
	ofstream ficherosalida("agenda.md");
	list<Alumno>::iterator a1;
	int i = 1;
	if(agenda_.empty()){
		ficherosalida.close();
		return 0;
	}
	if(seleccion==1&&orden==1){agenda_.sort(nombreASC);}
	if(seleccion==1&&orden==2){agenda_.sort(nombreDESC);}
	if(seleccion==2&&orden==1){agenda_.sort(apellidoASC);}
	if(seleccion==2&&orden==2){agenda_.sort(apellidoDESC);}
	if(seleccion==3&&orden==1){agenda_.sort(dniASC);}
	if(seleccion==3&&orden==2){agenda_.sort(dniDESC);}
	if(seleccion==2&&orden==1){agenda_.sort(equipoASC);}
	if(seleccion==2&&orden==2){agenda_.sort(equipoDESC);}

	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		ficherosalida<<"### Alumno "<<i<<endl;
		ficherosalida<<"** DNI : "<<(*a1).getDNI()<<endl;
		ficherosalida<<"** Nombre : "<<(*a1).getNombre()<<endl;
		ficherosalida<<"** Apellidos : "<<(*a1).getApellidos()<<endl;
		ficherosalida<<"** Direccion : "<<(*a1).getDireccion()<<endl;
		ficherosalida<<"** Telefono : "<<(*a1).getTelefono()<<endl;
		ficherosalida<<"** Email : "<<(*a1).getEmail()<<endl;
		ficherosalida<<"** Curso : "<<(*a1).getCurso()<<endl;
		ficherosalida<<"** Fecha de nacimiento : "<<(*a1).getFecha()<<endl;
		ficherosalida<<"** Equipo : "<<(*a1).getEquipo()<<endl;
		if((*a1).getLider()==1){
			ficherosalida<<"** Lider : SI "<<endl;
		}
		else{
			ficherosalida<<"** Lider : NO "<<endl;
		}
		i++;
	}
	ficherosalida.close();
	return 1;
}