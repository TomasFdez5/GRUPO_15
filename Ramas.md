## 0.4 Ramas 
### Ramas o *branches*
>Es la forma para separar la línea actual de desarrollo con respecto a la principal. Normalmente representan versiones del software que posteriormente son integradas a la línea principal.

![Introducción a Ramas](https://ibb.co/cUx9sU)

### Comandos Ramas I
##### Ver listado de ramas:
~~~
git branch
~~~
##### Crear una rama:
~~~
git branch *nombre_rama*
~~~
##### Cambiarnos a una rama:
~~~
git checkout *nombre_rama*
~~~
##### Cambiar una rama y moverse en un paso:
~~~
git checkout -b *nombre_rama*
~~~
##### Comparar ramas:
~~~
git diff *nombre_rama*..*nombre_rama*
~~~

### Comandos Ramas II
##### Ver ramas idénticas a la actual:
~~~
git branch --merged
~~~

##### Renombrar ramas:
~~~
git branch -m *nombre_antiguo*..*nombre_nuevo*
~~~

##### Eliminar ramas:
~~~
git branch -d *nombre_ramas*
git branch -D *nombre_ramas*
~~~

##### Integrar ramas a la actual:
~~~
git merge *nombre_rama*
~~~

##### Resolver conflictos (se suele hacer manualmente):
~~~
git merge --abort
~~~



