## Insertar datos alumno 

**ID** : 001

**Breve descripción:** Introduce en el sistema la información de un alumno.

**Actores principales:** Profesor.

**Actores secundarios:** Alumno.

#### Precondiciones:
1. Buscar el alumno, por si previamente ya se ha añadido.

#### Flujo principal:
1. El caso de uso comienza cuando el profesor quiere introducir un alumno.
2. El sistema recoge los datos introducidos por teclado.

#### Postcondiciones:
1. Se escriben los datos del alumno en el fichero.

#### Flujos alternativos:         
Si el alumno ya existe en la base, se advertirá y no se permitirá la insercción.
2.a Si no se rellenan campo obligatorios, se advierte al profesor.




