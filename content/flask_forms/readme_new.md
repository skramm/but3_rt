# Introduction au framework Flask

Ce document donne quelques indications pour la mise en oeuvre rapide de Flask pour des projets.
Il ne couvre pas de coté "lancement", qui peut être fait sur la machine hôte, ou dans un conteneur Docker.

Dans la suite, on supposera une installation en local, et accessible sur le port 5000.

Pour quelque chose de plus complet, voir le [tuto officiel](https://flask.palletsprojects.com/en/stable/quickstart/), dont beaucoup d'éléments ici sont tirés.

## Hello World et autres routes

```
from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"
```
L'exécution de ce code va lancer un serveur web, qui va répondre sur la racine avec le code HTMl "Hello, World!".

On peut ajouter des "routes" (qu'on appelle aussi "endpoint") et qui vont définir l'action à effectuer lors de la connection en HTTP sur celle-ci.
Par exemple, on peut ajouter ceci:

```
@app.route("/hello2")
def hello2():
    return "Hello again!"
```

On aura maintenant sur notre serveur deux "endpoint", l'un sur la racine (`localhost:5000` si on est en local), l'autre sur `hello2`
(`localhost:5000/hello2`).

Mais ces points de connection sont en fait **dynamiques**:
on peut utiliser une chaine quelconque comme route, comme ceci: 

```
@app.route('/user/<username>')
def show_name(username):
    return f"Hello {username}!"
```
La connection sur `localhost:5000/user/abcd` va afficher `Hello abcd!`.

Cette technique utilisée telle-quelle pose cependant un problème de sécurité:
il n'y a pas de validation de la saisie utilisateur, et il est donc possible à un utilisateur d'injecter du code exécutable Javascript dans la route.
Il est **impératif** de proteger le code via un "échapemment" de la chaine récupérée via le navigateur.
Il faut d'abord ajouter un "import:
```
from markupsafe import escape
```
Et la bonne approche du code précédent sera:
```
@app.route('/user/<username>')
def hello(username):
    return f"Hello, {escape(username)}!"
```

## Actions HTTP

Les requetes HTTP les plus courantes des navigateurs sont `GET` et `POST`.
On peut proposer une action différente selon la requete.
Il faudra d'abord ajouter un import:

```
from flask import request
```
Puis, ajouter la route suivante, qui va appeler deux fonctions différentes selon la méthode HTTP:
```
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        return do_the_login()
    else:
        return show_the_login_form()
```


## Utilisation de formulaires 

Il faut distinguer
- le formulaire lui-même;
- le "endpoint" qui sera appelé une fois le formulaire complété par l'utilisateur (appui sur bouton, ou sur "Entrée").

### 1 - Formulaire HTML

Le formulaire reste en général classique.
Il peut être sur une page dédiée, ou être intégré sur une page existante
(mais qui doit être dans le sous-dossier `templates`).

Le formulaire va ressembler à ceci:
```
<form method='post' action='/newuser'>
<label for="name">Entrer une chaine:</label>
<br>
<input type="text" id="ch1" name="ch1">
</form>
```

Le point important ici est le "endpoint" a appeler lors de la validation, ici `/newuser`, et qui doit exister dans le code Python/Flask.

### 2 - Code Python

Il faut importer des sous-packages de Flask:
```
from flask import Flask, request, render_template
```

Si le formulaire est sur une page distincte (ici `form.html`), il faut prévoir un point d'entrée:
```
@app.route("/monFormulaire",methods = ['POST', 'GET'])
def monForm():
	return render_template("form.html")
```

Ensuite, il faut prévoir la fonction a exécuter lors de la validation du formulaire:
```
@app.route('/newuser',methods = ['POST', 'GET'])
def newuser():
	if request.method == 'POST':
		res = request.form.get( "ch1" )
		return res.text()
```
Le nom de la fonction est libre, mais le endpoint doit correspondre à celui indiqué dans le formulaire.
De plus, le champ à récupérer est donné par l'argument passé à la fonction "get()" et doit donc correspondre à son nom dans le formulaire (ici `ch1`).

On récupère dans `res.text()` la chaine de caractères issue du formulaire, qu'on peut ensuite traiter en fonction des besoins.


