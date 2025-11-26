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


## 4 - "Parsing" de fichier texte

On a souvent besoin de récuperer le contenu d'un fichier généré par une autre commande et de le traiter "ligne par ligne", pour en extraire les infos dont on a besoin.

### 4.1 - Cas simple
Exemple:
Soit un fichier ` f1.txt` contenant ceci:
```
:1234
:5678
:90
```

On souhaite récupérer les nombres, mais **sans** le 1er caractère.

Le script suivant extrait les nombres dans un deuxième fichier `f2.txt`:

```
while read VAR
do
	echo "${VAR:1}">f2.txt
done<f1.txt
```

### 4.2 - Fichier contenant des champs

La commande `read` dispose d'options permettant de s'adapter à d'autres situations,
voir `$ help read`.

En particulier dans le cas de lecture d'un fichier d'entrée `f1.txt` contenant des champs séparés par des espaces:
```
a63 Paul
b56 Joe
f87 Bill
```
L'option `-a` (_array_) va placer les différents champs dans les élements d'un tableau, qu'on peut ensuite récupérer par leur indice:
```
while read -a VAR
do
	echo "${VAR[1]}">f2.txt # on récupère le 2è champ de texte
done<f1.txt
```
Ceci va générer le fichier `f2.txt`, contenant:
```
Paul
Joe
Bill
```

Dans certain cas, on a besoin de savoir **combien** de champs ont été lus
(et donc placés dans le tableau Bash `VAR`).
On accède à cette information avec:
```
nbelem=${#VAR[@]}
```

Pour avoir l'intégralité des éléments du tableau:
```
$ echo "${VAR[@]}"
```

Il est possible de spécifier un autre séparateur de champ que celui par défaut (SPC) en le précisant dans la variable d'environnement `IFS`
(_Internal Field Separator_):
```
IFS=","; while read -r VAR
...
```




