# Demo Jinja

[Jinja](https://jinja.palletsprojects.com/) est un **moteur de template** Python, destiné au web dynamique.
Il permet de spécifier dans une page HTML des "templates" (gabarits) qui seront remplacés à l'exécution par d'autres chaines de caractères.

Le code ici fait une démonstration de l'utilisation des templates Jinja **en dehors** de l'utilisation de Flask:
la génération du HTML se fait directement dans la console.
Cette démo est "dockerisée", et utilise une image [Alpine](https://fr.wikipedia.org/wiki/Alpine_Linux), qui est extrèmement légère.

Prérequis:
* une machine (VM) Debian ou équivalent (Ubuntu, ...)
* une install Docker fonctionnelle (testé avec 24.0.5), utilisable sans "sudo"

Pour faire tourner les démos, cloner ce dépot (ou faire un `git pull` si vous l'avez dejà cloné), puis:
```
$ cd but3_rt/content/demo_jinja
$ ./build.sh # crée une image Docker
$ ./run.sh  # lance le Docker et démarre un shell (sh, pas de bash dans l'image Alpine) avec tout déjà installé
```

Ceci doit ouvrir un shell dans le conteneur, dans un dossier `/srv`.
On peut ensuite taper le nom d'une des démos pour l'exécuter (voir la liste avec `$ ls -l *.py`).

Le conteneur a un lien statique avec le dossier dans la machine hote
(concept docker de "bind mount"),
donc vous pouvez modifier le code et tester sans avoir besoin de "rebuilder" le conteneur.

**ATTENTION**: si vous voulez expérimenter avec le code, mieux vaut faire une copie de tout le dossier ailleurs
(dans lequel vous pourrez virer le dossier `.git`).
En effet, si vous faites des modifs, lorsque vous voudrez synchroniser le dossier avec mes modifs à moi (via un `git pull`),
il y aura des conflits.


Pour les machines Windows, il faudra (à confirmer?):
* renommer les scripts `.sh` en `.bat`;
* vérifier que le programme `docker` est dans le path;
* au besoin les éditer en mettant toute la commande sur la même ligne (Le shell Windows ne reconnait pas le `\` qui permet de spécifier une commande s'étalant sur plusieurs lignes);
* les lancer sans le `./` en tête.

Chacune des demos ci-dessous va afficher le code produit dans la console.
Si vous voulez voir le rendu dans un navigateur, vous pouver ajouter une redirection:
```
$ ./testX.py > testX.html
```
Ceci va générer dans le dossier courant
(rappel: qui est partagé entre l'hote et le conteneur)
le fichier `testX.html` que vous pouvez ensuite sur l'hote ouvrir dans un navigateur.


## 1 - demo Jinja 1

Lancer (depuis le shell du conteneur) [test1.py](test1.py):
```
$ ./test1.py
```
ce qui va provoquer l'affichage de 3 pages HTML dans la console.

La boucle est ici dans le code Python, donc on appelle 3 fois la fonction de rendering, qui va donc générer 3 pages
(ici, on se contente de les afficher dans la console, mais avec Flask elle seront disponibles via le serveur).
```
************** FRUIT= apple
<html>
    <head>
        <title>Variable apple</title>
    </head>
    <body>
        <h3>Hello apple</h3>
    </body>
</html>
************** FRUIT= banana
<html>
    <head>
        <title>Variable banana</title>
    </head>
    <body>
        <h3>Hello banana</h3>
    </body>
</html>
************** FRUIT= cherry
<html>
    <head>
        <title>Variable cherry</title>
    </head>
    <body>
        <h3>Hello cherry</h3>
    </body>
</html>
```
Voir le fichier Python ainsi que le template pour comprendre comment ça marche.

## 2 - demo Jinja 2

Lancer [test2.py](test2.py):
```
$ ./test2.py
```

Ceci va générer une unique page avec un tableau avec un nombre de lignes dynamique, pas de boucle dans le code Python.
Dans cette démo, la "boucle" est dans le "template" [test2.html](templates/test2.html).
```
<html>
    <head>
        <title>For Example</title>
    </head>
    <body>
        <h2>Demo tableau</h2>
        <table>
        <tr><th>En tete</th></tr>
        
          <tr><td> apple </td></tr>  
        
          <tr><td> banana </td></tr>  
        
          <tr><td> cherry </td></tr>  
        
        </table>
    </body>
</html>
```

## 3 - demo Jinja 3

D'après [zetcode.com/python/jinja/](https://zetcode.com/python/jinja/)

Cette démo montre comment on peut avoir des tests (if/else) dans le template HTML,
comment on charge un fichier contenant un tableau JSON, 
et comment on peut passer une liste composée de paires JSON:

Lancer [test3.py](demo_jinja/test3.py):
```
$ ./test3.py
```
Voir le template [test3.html](templates/test3.html).
```
<html>
<body>
<h2>Demo tableau 2 colonnes</h2>
<table>
<tr><th>Num</th><th></th></tr>
<tr><td> Andrej </td><td>
34
</td></tr>
<tr><td> Mark </td><td>
MINOR</td></tr>
<tr><td> Thomas </td><td>
44
</td></tr>
<tr><td> Lucy </td><td>
MINOR</td></tr>
<tr><td> Robert </td><td>
23
</td></tr>
<tr><td> Dragomir </td><td>
54
</td></tr>
</table>
</body>
</html>
```



## Historique

### 2024/02
Passage à une image "python3/alpine" au lien de Debian:11

voir fichiers Dockerfile2 vs. Dockerfile

intéret: on passe d'une image de 587 MB à une image de 63 MB !!


