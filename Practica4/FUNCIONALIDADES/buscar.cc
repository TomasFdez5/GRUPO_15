int Agenda::buscar(string dni){
	list<Alumno>::iterator a1;
	int encontrado=0;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(dni==a1->getDNI()){
			encontrado=1;
		}
	}

	return encontrado;
}
int Agenda::buscar1(string apellidos){
	int encontrado=0;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(apellidos==a1->getApellidos()){
			encontrado=1;
		}
	}

	return encontrado;
}

int Agenda::buscar2(int equipo){
	list<Alumno>::iterator a1;
	int encontrado=0;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(equipo==a1->getEquipo()){
			encontrado=1;

		}
	}

	return encontrado;
}