## Registrar un profesor

**ID** : 010

**Breve descripción:** El profesor añade su ID y su contraseña a la credencial para acceder al sistema.

**Actores principales:** Persona no identificada.

**Actores secundarios:** Ninguno.

#### Precondiciones:
1. El ID y la contraseña no existan en las credenciales del sistema.

#### Flujo principal:
1. El caso de uso comienza cuando el profesor quiere inscribirse al sistema.
2. Introduce su ID y su contraseña.
3. Se comprueba que la ID no exista.

#### Postcondiciones:
1. Se añade el profesor a la credencial.
2. Se comunica el registro con éxito.

#### Flujos alternativos:
3. Si existe la ID, se manda un mensaje de error.
