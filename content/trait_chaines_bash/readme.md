# Traitement de chaines de caractères en Bash

(présentés sous forme d'exemple concret)

Note: ici, on omet les guillemets pas souci de clarté mais il faudra les ajouter si la chaine à traiter contient des espaces.


On déclare une variable qui contient une chaine:
```
$ var=ABCDEF
```

## Longueur de la chaine

Ceci:
```
$ echo taille=${#var}
```
va afficher
```
taille=6
```


## Extraction d'une sous-chaine

Pour avoir la fin d'une chaine à partir d'une certaine position:
```
${var:position}
```

Pour avoir une partie d'une longueur définie:
```
${var:position:longueur} 
```


### Exemples

Ceci:
```
$ echo s1=${var:3}
```

affiche:
```
"s1=DEF"
```

Ceci:
```
$ echo "s2=${var:2:3}"
```
affiche
```
s2=CDE
```



## Recherche et remplacement:

Remplacement de la 1ère occurence de `pattern`:
```
${string/pattern/replacement}
```

Remplacement **toutes** les occurences de `pattern`
```
${string//pattern/replacement}:
```
 
 Exemples:
 
```
$ f=a,b,c
$ echo "${f/,/;}"  # affiche "a;b,c"
$ echo "${f//,/;}"  # affiche "a;b;c"
```


