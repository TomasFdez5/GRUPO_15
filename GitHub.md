# 0.5. GitHub
**GitHub no es Git**
<a href="https://ibb.co/cBKPcU"><img src="https://thumb.ibb.co/cBKPcU/github1.png" alt="github1" border="0"></a>
## Comandos Github I
#### Añadir repositorio remoto:
~~~
git remote add origin url
~~~
#### Ver repositorios remotos:
~~~
git remote -v
~~~
#### Eliminar repositorio remoto:
~~~
git remote rm origin:
~~~
#### Añadir cambios del repositorio local remoto:
~~~
git push -u origin master
~~~
#### Añadir cambios de repositorio remoto al local
~~~
git pull
~~~
## Comandos GitHub II
#### Ver *branches* remotos:
~~~
git branch -r
~~~
#### Ver todos los *branches*:
~~~
git branch -a
~~~
#### Clonar un repositorio remoto:
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
** operación con *branches* remotos**

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