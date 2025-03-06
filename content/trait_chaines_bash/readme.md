# Traitement de chaines de caractères en Bash

(présentés sous forme d'exemples concret)

Note: ici, on omet les guillemets par souci de clarté mais il faudra les ajouter si la chaîne à traiter contient des espaces.


On déclare une variable qui contient une chaine:
```
$ var=ABCDEF
```

## 1 - Longueur de la chaine

Ceci:
```
$ echo taille=${#var}
```
va afficher
```
taille=6
```


## 2 - Extraction d'une sous-chaine

Pour avoir la fin d'une chaine `$var` à partir d'une certaine position:
```
${var:position}
```

Pour avoir une partie d'une longueur définie:
```
${var:position:longueur} 
```

(Note: le 1er caractère est en position 0)

### Exemples

Ceci:
```
$ echo s1=${var:3}
```

affiche:
```
s1=DEF
```

Ceci:
```
$ echo s2=${var:2:3}
```
affiche
```
s2=CDE
```



## 3 - Recherche et remplacement:

Remplacement de la 1ère occurence de `pattern`:
```
${string/pattern/replacement}
```

Remplacement **toutes** les occurences de `pattern`
```
${string//pattern/replacement}:
```
 
### Exemples:

Remplacement de `,` par `;`:
```
$ var=a,b,c
$ echo "${var/,/;}"  # affiche "a;b,c"
$ echo "${var//,/;}"  # affiche "a;b;c"
```
Fonctionne aussi pour des chaînes longues:

```
$ var="bonjour Madame"
$ echo "${var/Madame/Monsieur}"  # affiche "bonjour Monsieur"
```

### Utilisation de `tr`

Pour un seul caractère, on peut aussi utiliser `tr`:
```
$ var="aaa;bbb;ccc"
$ echo $var | tr ';' ' '
```

affiche:
```
aaa bbb ccc
```

Note: cette commande permet d'autres choses bien plus élaborées
(exemple: remplacer majuscules par minuscules, etc), voir
https://en.wikipedia.org/wiki/Tr_(Unix)



