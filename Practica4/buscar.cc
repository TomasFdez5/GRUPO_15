void Agenda::buscar(string dni){
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(dni==a1->getDNI()){
			mostrar((*a1));
			imprimir((*a1));
		}
	}
	
}
void Agenda::buscar1(string apellidos){
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(apellidos==a1->getApellidos()){
			mostrar((*a1));
			imprimir((*a1));
		}
	}
}

void Agenda::buscar2(int equipo){
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(equipo==a1->getEquipo()){
			mostrar((*a1));
			imprimir((*a1));
		}
	}
}