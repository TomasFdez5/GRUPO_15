# Tutorial de Git y Github
## 0. Git
## 0.1. Introducción
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

#### Ventajas
###### Git
* Habilidad de deshacer cambios.
* Historial y documentación de cambios.
* Múltiples versiones de código.
* Habilidad de resolver conflictos entre versiones de distintos programadores.
* Copias independientes.

###### GitHub
* Documentación de requerimientos.
* Ver el avance del desarrollo.

## 0.2. Instalación y configuración
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

## **0.3. Uso básico**
#### Los tres estados de Git

<a href="https://ibb.co/ePuRbp"><img src="https://thumb.ibb.co/ePuRbp/4.png" alt="4" border="0"></a>

### Comandos básicos I
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


### Comandos básicos II
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

### Comandos básicos III
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

### Comandos básicos IV
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

### Comandos básicos V
##### Deshacer múltiples cambios en el repositorio:
~~~
git reset --soft <id_commit>
git reset --mixed <id_commit>
git reset --hard <id_commit>
~~~

##### Listar archivos que git no controla:
~~~
git clean -n
~~~

##### Eliminar archivos que en el respositorio:
~~~
.gitignore
~~~

### Comandos básicos VI
##### Listar el contenido del repositorio de git:
~~~
git ls-tree master
git ls-tree master^^^
git ls-tree master"3
~~~

##### Log en una línea:
~~~
git log --oneline
~~~

##### Log con los tres últimos commits en una línea:
~~~
git log --oneline -3
~~~

### Comandos básicos VII
##### Examinar el contenido de un commit:
~~~
git show <id>
~~~

##### Comparar un commit con el actual:
~~~
git diff <id> nombre_archivo
~~~

##### Comparar dos commits:
~~~
git diff id..id nombre_archivo
~~~
## 0.4 Ramas 
### Ramas o *branches*
>Es la forma para separar la línea actual de desarrollo con respecto a la principal. Normalmente representan versiones del software que posteriormente son integradas a la línea principal.

<a href="https://imgbb.com/"><img src="https://image.ibb.co/dBvXU9/1.png" alt="1" border="0"></a>

### Comandos Ramas I

##### Ver listado de ramas:
~~~
git branch
~~~
##### Crear una rama:
~~~
git branch nombre_rama
~~~
##### Cambiarnos a una rama:
~~~
git checkout nombre_rama
~~~
##### Cambiar una rama y moverse en un paso:
~~~
git checkout -b nombre_rama
~~~
##### Comparar ramas:
~~~
git diff nombre_rama..nombre_rama
~~~

### Comandos Ramas II

##### Ver ramas idénticas a la actual:
~~~
git branch --merged
~~~

##### Renombrar ramas:
~~~
git branch -m nombre_antiguo..nombre_nuevo
~~~

##### Eliminar ramas:
~~~
git branch -d nombre_ramas
git branch -D nombre_ramas
~~~

##### Integrar ramas a la actual:
~~~
git merge nombre_rama
~~~

##### Resolver conflictos (se suele hacer manualmente):
~~~
git merge --abort
~~~




### Comandos Ramas III

##### Almacenar cambios temporales:
~~~
git stash save "Mensaje"
~~~
##### Listar cambios:
~~~
git stash list
~~~
##### Ver contenido de un cambio temporal:
~~~
git stash show -p nombre_stash
~~~
##### Eliminar un cambio temporal: 
~~~
git stash drop nombre_stash
~~~
##### Aplicar cambio del stash:
~~~
git stash apply nombre_stash
git stash pop nombre_stash
~~~


## 0.5 GitHub 
### GitHub no es Git

<a href="https://imgbb.com/"><img src="https://image.ibb.co/gpT8K9/2.png" alt="2" border="0"></a>
### Comandos Github I
##### Añadir repositorio remoto:
~~~
git remote add origin url
~~~
##### Ver repositorios remotos:
~~~
git remote -v
~~~
##### Eliminar repositorio remoto:
~~~
git remote rm origin:
~~~
##### Añadir cambios del repositorio local remoto:
~~~
git push -u origin master
~~~
##### Añadir cambios de repositorio remoto al local
~~~
git pull
~~~
### Comandos GitHub II
##### Ver *branches* remotos:
~~~
git branch -r
~~~
##### Ver todos los *branches*:
~~~
git branch -a
~~~
##### Clonar un repositorio remoto:
~~~~
git clone url
~~~~
**Dar seguimiento a *branches* remotos**

* LOCAL --> REMOTO
1. Cambios en el repositorio local
2. Commit de los cambios 
3. Añadir cambios a repositorio remoto:

~~~
git push
~~~

* REMOTO --> LOCAL
    * Sincronización y unión:
    ~~~
    git fetch origin 
    git merge origin/master
    ~~~
    * En un solo paso
    ~~~
    git pull
    ~~~ 
**operación con *branches* remotos**

* Creación:
    1. Crear branch local
    2. Hacer cambios en dicho branch
    3. Hacer  commit
    4. Copiar el branch al repositorio remoto:

~~~
git push -u origin branch_remoto
~~~

* Copia:
~~~
git checkout -b local remoto
~~~

* Eliminación
~~~
git push origin --delete branch_remoto
~~~
