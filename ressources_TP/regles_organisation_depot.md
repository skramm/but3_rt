# BUT RT - SAÉ:
# Règles pour les dépots Git

- S. Kramm, rédaction initiale: 2025/04

## Introduction

Dans certaines activités, il vous sera demandé de placer votre production sur un dépot Git,
hébergé sur un site de développement collaboratif, type Github ou Gitlab.
L'enseignant pourra ainsi avoir accès à tout votre travail, à des fins d'évaluation ou de discussion sur le projet.
Afin de ne pas perdre de temps et d'adopter des bonnes pratiques professionnelles, ci-dessous quelques règles à respecter.

Attention: le respect de ces règles pourra être un des éléments d'évaluation !

## Règles

### 1 - Nom du dépot

Si l'enseignant vous demander de placer un travail dans un dossier nommé `ABCD`
sur un dépot (Github/Gitlab) nommé `XYZ`, respecter cette consigne!
En effet, via des scripts, l'enseignant peut vouloir cloner l'ensemble des travaux des étudiants et le script ira donc cloner le dépot
`https://gitXXXX.com/NOM-ETUDIANT/XYZ`
dans lequel il va aller chercher le contenu du dossier `ABCD`.

Si le clonage échoue ou si le dossier n'existe pas... vous serez pénalisé.

### 2 - Travail d'équipe

S'il s'agit d'un travail en équipe, ne **pas** démultiplier le travail demandé sur le dépot de chaque étudiant.
En général, placer le travail sur le dépot du chef de projet.


### 3 - Accès au dépot:

Les dépot Git sur les plateformes collaboratives peuvent être crées en "public" ou "privé", cette dernière option permettant de limiter l'accès aux seules personnes autorisées.
Il est possible de modifier ce réglage à tout moment, et dans les deux sens.

Le cas le plus simple est de placer le dépot en public, mais dans certains cas, on peut vouloir souhaiter que d'autres étudiants ne "pillent" pas votre travail.
Ceci peut donc vous amener à placer votre travail en privé.
Dans ce cas, il faudra penser à donner un accès à l'enseignant, voyez celà avec lui.

### 4 - Formats des fichiers

La règle pour les dépot Git est de ne pas y placer des fichiers "générés", mais uniquement du fichier source (scripts Shell, code Python, etc.), en "texte brut".
Pour de la rédaction de documentation, rapports, etc, le format à privilégier est le **Markdown**.  
(voir https://www.google.com/search?q=markdown+cheatsheet)  
Pour la documentation, il est néamoins possible d'inclure dans le .md des images (copies d'écran ou graphiques), qui devront donc être hébergées sur le dépot.

**Attention** néanmoins à limiter leur taille:
ne **PAS** placer des copie d'écran complètes de 4000x3000 pixels pesant 3MB!!!
Découper la zone pertinente avec un outil de traitement d'images et redimensionner à quelques centaines de pixels de large.  
Enfin, une conversion en JPEG permet souvent de gagner en poids, surtout pour des copies d'écran ou des photos.


### 5 - Fichier `readme.md`

Ce fichier `readme.md` est le premier document que l'on consulte.
Il doit permettre de comprendre le contenu du dépot, et donner les indications sur comment utiliser le travail.

En particulier, si le travail demandé comprend une partie "démo", il est essentiel que ce fichier donne les indication sur comment faire fonctionner cette démo, avec toutes les étapes nécessaires

### 6 - Identification / datation

Tous les documents doivent être **datés** (a minima par mois/année) et leurs auteurs doivent être clairement identifiés.
Dans les cas d'un travail en équipe, il faut les **noms** des personnes de l'équipe, et ce sur tous les différents fichiers.

### 7 - Organisation du dépot

Il est essentiel de **documenter** cette organisation:
prévoir dans le readme une partie indiquant la nature des différents fichiers & dossiers et ce qui s'y trouve.

De même, ne pas surcharger la racine avec de trop nombreux fichiers:
penser à les organiser en différents sous-dossiers.




