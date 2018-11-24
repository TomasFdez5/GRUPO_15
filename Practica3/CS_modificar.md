## Modificar alumn@

**ID** : 003

**Breve descripción:** Se modifican los datos de un alumn@.

**Actores principales:** Profesor.

**Actores secundarios:** Alumno.

#### Precondiciones:
1. Haber introducido previamente al alumn@.

#### Flujo principal:
1. Buscamos el alumno por DNI o apellidos para comprobar que existe.
2. Se modifcan los datos deseados.
3. El sistema recoge los datos introducidos por teclado.

#### Postcondiciones:
1. Se sobreescriben los datos en el fichero.

#### Flujos alternativos:
1. a Si no existe el alumno, se advierte al profesor.
2. a Si el formato de los datos no es el correcto, los datos no se modificaran.
2. b Si quitamos el líder de un grupo, se advertirá de ello al profesor.
