# EXTRACCIÓN DE REQUISITOS DEL USUARIO:

## **Actores de la aplicación:**
1. Profesor
2. Alumnos

## **Datos que almacena la aplicación:**
* DNI 
* Nombre 
* Apellidos 
* Teléfono 
* Email  
* Dirección
* Curso más alto matriculado 
* Fecha de nacimiento 
* Equipo al que pertenece
* Líder (booleano)
* ID
* Contraseña

## **Requisitos funcionales:**

1. Insertar datos del usuario
2. Buscar un usuario mediante DNI, apellido o equipo al que pertenece
3. Modificar un usuario (previamente buscar el usuario)
4. Borrar usuario (previamente buscar el usuario)
5. Mostrar un usuario o varios usuarios, por orden (previamente buscar el usuario)
6. Guardado automático y manual
7. Cargar la copia de seguridad
8. Mostar el listado completo de alumnos
## **Requisitos NO funcionales:**
    
1. Lenguaje de programación C++
2. Compatible con GNU/linux
3. Fácil de entender y visualmente agradable
4. Copias de seguridad en ficheros binarios
  Con colorines
5. Formato de fichero HTML
6. Clase máxima de 150 alumnos
  Solo un líder por grupo
7. Orden alfabéticamente por apellido o nombre, de manera numérica del DNI sin importar letra o curso más alto en el que está matriculado, y todo lo anterior de manera ascendente o descendente

## **Prioridades de los requisitos funcionales:**

* nivel 1: Insertar usuario
* nivel 2: Buscar un usuario
* nivel 3: Mostrar, modificar y borrar un usuario
* nivel 4: Guardar y cargar
