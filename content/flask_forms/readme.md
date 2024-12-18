# Utilisation de formulaires avec Flask

Il faut distinguer
- le formulaire lui-même;
- le "endpoint" qui sera appelé une fois le formulaire complété par l'utilisateur (appui sur bouton, ou sur "Entrée").

## Formulaire HTML

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

# Code Python

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
De plus, le champ à récupérer est indiquer par l'argument passé à la fonction "get()" et doit donc correspondre à son nom dans le formulaire (ici `ch1`).

On récupère dans `res.text()` la chaine de caractères issue du formulaire, qu'on peut ensuite traiter en fonction des besoins.


