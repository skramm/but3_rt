# redis client cheatsheet

## 1 - Commandes généralistes

| Commande |   |
|----|-----|
| PING | PONG (test) |
| DBSIZE | Nombre de clés stockées |
|    | Effacement de toute la BDD courante |
|  | Effacement de toutes les BDD |
|  | Test de l'existence d'une clé |
|  | Suppression d'une clé |
|  |  |


## 2 - Gestion de valeurs de type "string" (texte ou numérique)

| Commande |   |
|----|-----|
| SET | Donne une valeur à une clé |
|  | Récupère la valeur d'une clé |
|  | Incrémente un compteur (+1) |
|  | Incrémente un compteur d'une valeur spécifiée |
|  |  |
|  |  |


## 3 - Gestion de listes

| Commande |   |
|----|-----|
|  | Nb d'éléments dans la liste |
| LPUSH | Ajout d'élements par la gauche |
|  | Ajout d'élements par la droite |
|  | Dépilement d'une valeur par la gauche |
|  | Dépilement d'une valeur par la droite |
|  | Lecture d'un élément par son index |
|  | Lecture de plusieurs éléments par leurs index |
|  |  |
|  |  |

## 3 - Gestion de Hash (collection de paires clé-valeur)

| Commande |   |
|----|-----|
| HLEN | Nb d'éléments |
| HGET | Accès à une valeur |
|    | Incrémentation valeur numérique |
|  | Ajout paire clé/valeur |
|  | Renvoie la liste des clés |
|  | Renvoie une des valeurs |
|  |  |
|  |  |





