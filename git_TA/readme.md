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


