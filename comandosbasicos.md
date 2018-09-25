#Tutorial de Git y Github
## 0. Git
### 0.1. Introducción
* Código efímero.
* Necesidad de mantener todas las versiones del código fuente.
* Problemas en organizaciones para mantener el código actualizado.
* Coherencia de versiones.
* Conocimiento del cambio que ha provocado que el sistema no funcione.
* Fallos en el disco duro que suponen riesgo de información desactualiazada.

#### **Git**
Sistema para el control distribuido de versiones de código. Fundamentalmente permite:

* Dar seguimiento a los cambios realizados sobre un archivos
* Almacenar una copia de los cambios.

#### **GitHub**
Sitio web dónde podemos subir una copia de nuestro repositorio Git.

##### Ventajas
###### Git
* Habilidad de deshacer cambios.
* Historial y documentación de cambios.
* Múltiples versiones de código.
* Habilidad de resolver conflictos entre versiones de distintos programadores.
* Copias independientes.

###### GitHub
* Documentación de requerimientos.
* Ver el avance del desarrollo.

### 0.2. Instalación y configuración
#### **Instalación**
* Para instalar Git: [https://git-scm.com/](https://git-scm.com/)  
* En el curso se utilizará Git a través de líneas de comandos. 
* Para eclipse existen _plugins_ integrados: [https://www.eclipse.org/egit/](https://www.eclipse.org/egit/)

### Configuración básica
##### Nombre del administrador:
~~~
git config --global user.name "Sergio Lucena Téllez"
~~~

##### Correo electrónico:
~~~
git config --global user.email i72lutes@uco.es
~~~

##### Editor de texto:
~~~
git config --global core.editor "gedit"
~~~

##### Color de la interfaz:
~~~
git config --global color.ui true
~~~

##### Listado de la configuración:
~~~
git config --list
~~~ 

### **0.3. Uso básico**
#### Los tres estados de Git

#### Comandos básicos I
##### Iniciar repositorio en un directorio:
~~~
git init
~~~

##### Agregar cambios al area de _staging_:
~~~
git add
~~~

##### Validar cambios en el repositorio:
~~~
git commit -m "Mensaje"
~~~

##### Hacer los dos pasos anteriores en uno:
~~~
git commit -am "Mensaje"
~~~

##### Historial de commits:
~~~
git log
~~~


#### Comandos básicos II
##### Ayuda del listado anterior:
~~~
git help log
~~~

##### Listar los 5 commits más recientes:
~~~
git log -n 5
~~~

##### Listar los commits desde una fecha:
~~~
git log --since=2018-09-18
~~~

##### Ver cambios en el directorio:
~~~
git status
~~~

#### Comandos básicos III
##### Ver diferencia entre ficheros en el directorio y el repositorio de git:
~~~
git diff
~~~

##### Ver diferencia entre ficheros en el _staging_ y el repositorio:
~~~
git diff --staged
~~~

##### Eliminar archivos:
~~~
git rm archivo
git commit -m "Mensaje"
~~~

##### Mover o renombrar archivos:
~~~
git mv antiguo nuevo
git commit -m "Mensaje"
~~~

#### Comandos básicos IV
##### Deshacer cambios con git:
~~~
git checkout -- nombre_fichero
~~~

##### Retirar archivos del _staging_:
~~~
git reset HEAD nombre_fichero
~~~

##### Complementar último commit:
~~~
git commit --amend -m "Mensaje"
~~~

##### Recuperar version de un fichero de commit antiguo:
~~~
git checkout <id_commit> -- nombre_archivo
~~~

##### Revertir un commit
~~~
git revert <id_commit>
~~~
