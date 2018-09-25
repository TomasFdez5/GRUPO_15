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
git stash pop nomnre_stash
~~~


## 0.5 GitHub 
### GitHub no es Git

<a href="https://imgbb.com/"><img src="https://image.ibb.co/gpT8K9/2.png" alt="2" border="0"></a>
