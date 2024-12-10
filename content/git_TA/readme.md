# Git: Trucs & Astuces

## Raccourcis dans le shell

Au quotidien, il y a un certain nombre de commandes Git que l'on doit utiliser très souvent, la plus fréquente étant
```
$ git status
```

Afin de se faciliter la tache, il est commode d'utiliser des **alias** pour aller plus vite.
On peut ainsi ajouter dans son fichier `.bashrc` des lignes comme la suivante:
```
alias gits="git status"
```
Ceci permettra de taper à la place les 4 lettres `gits`.

On peut avec les alias enchainer les commandes en les séparant par `;`.
Par exemple, si on veut ajouter la visualisation du dépot distant, on mettra:
```
alias gits="git remote -v;git status"
```

On peut bien sur aller plus loin, par exemple en prévoyant `gitpl` pour `git pull`,
`gitps` pour `git push`, `dops` pour `docker ps -a`, etc.


## Verification des fichiers suivis

IL arrive parfois qu'on ne sache plus trop dans un dossier quels fichiers sont déja versionnés, sachant qu'il peut y en avoir qu'on ne souhaite pas versionner (et donc la commande `git add *` est à proscrire absolument!)

La commande à utiliser est alors
[git ls-tree](https://git-scm.com/docs/git-ls-tree)
qui affiche la liste des fichiers effectivement versionnés.

Son utilisation implique de préciser quelle branche (ou commit) on souhaite analyser, on peut par exemple faire:
```
$ git ls-tree -r --name-only HEAD
```

L'option `-r` va descendre dans les sous-dossiers, et `--name-only`... comme son nom l'indique.

Et un ceci pourra judicieusement donner lieu à un alias, nommé par exemple
`gitls`.



