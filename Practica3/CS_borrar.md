## Borrar un alumn@

**ID** : 004

**Breve descripción:** Borrar del sistema la información de un alumn@.

**Actores principales:** Profesor.

**Actores secundarios:** Alumno.

#### Precondiciones:
1. Que exista el/la alumn@ que deseamos borrar.

#### Flujo principal:
1. El caso de uso comienza cuando el profesor quiere eliminar los datos un alumno.
2. Buscamos que exista el alumn@ a eliminar.
3. Eliminamos todos los datos pertenecientes al alumn@ del fichero. 

#### Postcondiciones:
1. El fichero se modifica.
2. El alumn@ ya no existe en el fichero.
3. Si se elimina a un líder de equipo, se esperará la confirmación del profesor.

#### Flujos alternativos:
2. a Si no no existe el alumn@, se advertirá de ello.
3. a Si se elimna de forma incorrecta, el archivo no se modifica.



 
