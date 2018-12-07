void modificar(string dni){
	int find=0;
	int n;
	int aux;
	string aux_t;
	int existe=0;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(dni==a1->getDNI()){
			find=1;
			cout<<"¿que campo quiere modificar?"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<"1. Nombre"<<endl;
			cout<<"2. Apellidos"<<endl;
			cout<<"3. DNI"<<endl;
			cout<<"4. Direccion"<<endl;
			cout<<"5. Email"<<endl;
			cout<<"6. Curso"<<endl;
			cout<<"7. Fecha"<<endl;
			cout<<"8. equipo"<<endl;
			cout<<"9. condición de lider"<<endl;
			cout<<"10. salir"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cin>>n;
			while(n>0 && n<10){
				switch(n){
					case 1:
						cout<<"Nuevo nombre"<<endl;
						getline(cin, aux_t);
						a1->setNombre(aux_t);
					break;
					case 2:
						cout<<"Nuevos apellidos"<<endl;
						getline(cin, aux_t);
						a1->setApellidos(aux_t);	
					break;
					case 3:
						cout<<"Nuevo DNI"<<endl;
						getline(cin, aux_t);
						a1->setDNI(aux_t);	
					break;
					case 4:
						cout<<"Nueva direccion"<<endl;
						getline(cin, aux_t);
						a1->setDireccion(aux_t);	
					break;	
					case 5:
						cout<<"Nuevo email"<<endl;
						getline(cin, aux_t);
						a1->setEmail(aux_t);	
					break;	
					case 6:
						cout<<"Nuevo curso"<<endl;
						cin>>aux;
						a1->setCurso(aux);	
					break;
					case 7:
						cout<<"Nueva fecha"<<endl;
						getline(cin, aux_t);
						a1->setFecha(aux_t);
					break;
					case 8:
						cout<<"Nuevo equipo"<<endl;
						cin>>aux;
						a1->setEquipo(aux);
					break;
					case 9:
					cout<<"introduzca 0 si no es lider"<<endl;
					cout<<"introduzaca 1 si es lider"<<endl;
					list<Alumno>::iterator a2;
					for(a2=agenda_.begin();a2!=agenda_.end();a1++){
						if(a1->getEquipo()==a2->getEquipo()){
							if(a2->getLider==1){
								existe==1;
							}
						}
					}
					cin>aux;
					if(existe==1 && aux==1){
						cout<<"error ya hay un lider"<<endl;
						break;
					}
					if(a1->getLider==1 && aux==0){
						cout<<"Advertencia: Se ha borrado al lider"<<endl;

					}
					a1->setLider(aux);
					break;
				};
			}
		}
	}	
	if(find==0){
		cout<<"error no existe el alumno"<<endl;
	}
}
void modificar1(string apellidos){
	int find=0;
	int n;
	int aux;
	string aux_t;
	int existe=0;
	list<Alumno>::iterator a1;
	for(a1=agenda_.begin();a1!=agenda_.end();a1++){
		if(apellidos==a1->getApellidos()){
			find=1;
			cout<<"¿que campo quiere modificar?"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<"1. Nombre"<<endl;
			cout<<"2. Apellidos"<<endl;
			cout<<"3. DNI"<<endl;
			cout<<"4. Direccion"<<endl;
			cout<<"5. Email"<<endl;
			cout<<"6. Curso"<<endl;
			cout<<"7. Fecha"<<endl;
			cout<<"8. equipo"<<endl;
			cout<<"9. condición de lider"<<endl;
			cout<<"10. salir"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cin>>n;
			while(n>0 && n<10){
				switch(n){
					case 1:
						cout<<"Nuevo nombre"<<endl;
						getline(cin, aux_t);
						a1->setNombre(aux_t);
					break;
					case 2:
						cout<<"Nuevos apellidos"<<endl;
						getline(cin, aux_t);
						a1->setApellidos(aux_t);	
					break;
					case 3:
						cout<<"Nuevo DNI"<<endl;
						getline(cin, aux_t);
						a1->setDNI(aux_t);	
					break;
					case 4:
						cout<<"Nueva direccion"<<endl;
						getline(cin, aux_t);
						a1->setDireccion(aux_t);	
					break;	
					case 5:
						cout<<"Nuevo email"<<endl;
						getline(cin, aux_t);
						a1->setEmail(aux_t);	
					break;	
					case 6:
						cout<<"Nuevo curso"<<endl;
						cin>>aux;
						a1->setCurso(aux);	
					break;
					case 7:
						cout<<"Nueva fecha"<<endl;
						getline(cin, aux_t);
						a1->setFecha(aux_t);
					break;
					case 8:
						cout<<"Nuevo equipo"<<endl;
						cin>>aux;
						a1->setEquipo(aux);
					break;
					case 9:
					cout<<"introduzca 0 si no es lider"<<endl;
					cout<<"introduzaca 1 si es lider"<<endl;
					list<Alumno>::iterator a2;
					for(a2=agenda_.begin();a2!=agenda_.end();a1++){
						if(a1->getEquipo()==a2->getEquipo()){
							if(a2->getLider==1){
								existe==1;
							}
						}
					}
					cin>aux;
					if(existe==1 && aux==1){
						cout<<"error ya hay un lider"<<endl;
						break;
					}
					if(a1->getLider==1 && aux==0){
						cout<<"Advertencia: Se ha borrado al lider"<<endl;

					}
					a1->setLider(aux);
					break;
				};
			}
		}
	}	
	if(find==0){
		cout<<"error no existe el alumno"<<endl;
	}
}