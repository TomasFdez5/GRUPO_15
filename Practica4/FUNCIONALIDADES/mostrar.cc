void Agenda::mostrar(string cadena){
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(a1->getDNI()==cadena&&buscar((cadena))==1){
			string cadena=(*a1).getDNI()+".md";
			ofstream ficherosalida(cadena.c_str());
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
			imprimir(*a1);
			ficherosalida.close();
		}
	}

}