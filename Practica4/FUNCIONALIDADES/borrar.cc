int Agenda::borrar(string dni){
	list<Alumno>::iterator a1;

	if(agenda_.empty()){
		return -1;
	}
	for(a1=agenda_.begin(); a1!=agenda_.end();a1++){
		if(dni==a1->getDNI()){
			agenda_.erase(a1);
			return 1;
		}
	}
	return 2;
}

int Agenda::borrar1(string apellidos){
	list<Alumno>::iterator a1;

	if(agenda_.empty()){
		return -1;
	}
	for(a1=agenda_.begin(); a1!=agenda_.end();a1++){
		if(apellidos==a1->getApellidos()){
			agenda_.erase(a1);
			return 1;
		}
	}
	return 2;
}