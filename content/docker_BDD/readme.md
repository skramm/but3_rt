# Conteneurisation d'un SGBD avec Docker

S. Kramm - 2024

Cette page détaille l'utilisation d'un serveur MySql (ou MariaDB, voir plus bas) de façon conteneurisée avec Docker.

Pour des détails, voir aussi: https://hub.docker.com/_/mysql


## 1 - Utilisation de MySql 5.7

L'utilisation de cette version est la plus simple, mais cette version est en fin de vie, il n'y a plus de mises à jour depuis octobre 2023.

**Etapes**

Il faut d'abord créer un réseau virtuel, nécessaire pour pouvoir accéder à la BDD depuis un autre conteneur:
```
$ docker network create mynetwork
```

### 1.1 - Démarrage du conteneur

On peut ensuite lancer un serveur MySql dans un conteneur, connecté à ce réseau:
```
$ docker run \
	--name monserveur \
	--network=mynetwork \
	--rm
	-e MYSQL_ROOT_PASSWORD=secretpw \
	-d \
	-p 3306:3306 \
	mysql:5.7
```

Options:
- `-d`: exécution en mode "detached"
- `-p`: publication du port
- `--rm`: suppression du conteneur après son arrêt

Cette commande va créer le conteneur, qu'on peut voir avec la commande:
```
$ docker ps
CONTAINER ID   IMAGE        COMMAND                  CREATED          STATUS          PORTS                 NAMES
6863de356300   mysql:5.7   "docker-entrypoint.s…"   1 minute ago   Up 1 minutes   3306/tcp, 33060/tcp   monserveur
```

Attention, en cas de plantage au démarrage, le conteneur sera supprimé (option `---rm`) et on ne pourra par analyser le problème.
Il faudra relancer le conteneur **sans** cette option, attendre son arret, puis examiner le problème avec `$ docker logs monserveur`.

Si le conteneur démarre, on peut accéder à ce serveur via le nom d'hôte (`monserveur` ici), soit via une appli (php, Python-Flask, ...), soit via le client CLI `mysql`.

On peut lancer ce dernier dans le shell de l'hote (s'il est installé) avec cette commande:
```
$ mysql -u root --port=3306 -h 127.0.0.1 -p'secretpw'
```
ou
```
$ mysql -u root --port=3306 --protocol=TCP -p'secretpw'
```

Ceci ouvre un shell "sql" dans lequel on peut taper des commandes SQL ou des commandes de gestion.
La doc donnant ces commandes est ici: https://dev.mysql.com/doc/refman/5.7/en/mysql.html

Pour quitter, taper `exit;`

On peut aussi utiliser ce client CLI pour automatiser des actions sur ce serveur, en lui "passant" un fichier contenant des commandes SQL
(création d'une BDD, création d'une table dans une BDD, remplissage d'une table, etc.):
```
$ mysql -u root --port=3306 -h 127.0.0.1 -p'secretpw' < fichier.sql
```
Avec un fichier `fichier.sql` contenant du SQL, par exemple:
```
CREATE DATABASE databasename;
USE DATABASE databasename;
CREATE TABLE matable (
	id INT (11) AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR (25) DEFAULT NULL
);
```

### 1.2 - Stockage séparé

En lancant le serveur de cette façon, les données sont stockées dans le conteneur.
Conséquence: toutes les données qu'on pourrait y stocker sont **perdues** à l'arret du conteneur!

Pour avoir un stockage séparé, il faut indiquer un **volume** lors du lancement du serveur.
Il faut d'abord le créer:
```
$ docker volume create mesdatas
```

Puis le lancement du serveur, en associant au volume le dossier où MySql stocke ses données
(`/var/lib/mysql`):
```
$ docker run \
	--name monserveur \
	--network=mynetwork \
	--rm
	-e MYSQL_ROOT_PASSWORD=secretpw \
	-v mesdatas:/var/lib/mysql \
	-d \
	-p 3306:3306 \
	mysql:5.7
```

De façon alternative, on peu aussi réaliser un "bind-mount", qui permet de "lier" un dossier du conteneur avec un dossier de la machine hôte:
```
$ docker run \
	... autre options \
	--mount type=bind,source=$(pwd)/bdd,target=/var/lib/mysql \
	mysql:5.7
```
Avec `bdd` le dossier de l'hôte à lier avec le conteneur (et qui se trouve dans le dossier courant),
et dans lequel on retrouvera les fichiers gérés par MySql (à ne surtout pas manipuler directement!).

**Attention**: ceci n'est pas portable et est donc à éviter.

## 2 - Utilisation de MySql 8

La doc: https://dev.mysql.com/doc/refman/8.4/en/mysql.html

**Note1**: pour une raison que personne ne comprends vraiment (et qui a fait sourire la communauté), MySql est passé directement de version 5 à version 8...

**Note2**: Sous Debian et dérivés (Ubuntu, ...) l'installation de MySql installe en fait le fork
[MariaDB](https://fr.wikipedia.org/wiki/MariaDB),
mais c'est quasi transparent à l'usage.

**Note3**: Les procédures d'authentification ont été renforcées dans cette version, ce qui amène des détails supplémentaires à gérer.
En l'état, il est préférable d'utiliser MariaDB, logiciel libre et open source sous licence
[GPLv2](https://fr.wikipedia.org/wiki/Licence_publique_g%C3%A9n%C3%A9rale_GNU),
indépendant de toute entité commerciale.


## 3 - Utilisation de MariaDB

L'usage est très similaire à MySQL5.7.
Il faut cependant prévoir un volume spécifique:
```
docker volume create data_mdb

docker run \
	--name maria \
	--network=bddnet \
	-e MARIADB_ROOT_PASSWORD=secret \
	-v data_mdb:/var/lib/mysql \
	--rm
	-d \
	-p 3309:3306 \
	mariadb:11.2
```

Sous Linux/Ubuntu, le client MySql étant déjà issu de MariaDB, la connexion depuis l'hote se fait comme ci-dessus
(en faisant attention au n° de port).

## 4 - En cas d'erreur

Si votre conteneur s'arrete au bout de quelques secondes, il faut alors regarder ses **logs**:
supprimer le (`docker rm <UUID>`), enlever l'option `--rm` du script de lancement, et le relancer.

Vous pouvez maintenant acceder à ses logs avec:
```
$ docker logs <UUID>
```
(ou utiliser son nom si vous lui en avez donné un).

Si vous avez des erreurs bizarres après de multiples essais et en ayant éventuellement modifié l'image, celà est très certainement du au **volume** de stockage, qui est donc persistant et peut avoir "enregistré" des informations issues d'un lancement précédent.

Ajouter dans le script avant la commande de lancement la ligne:
 ```
$ docker volume rm data_mdb
 ```
(ou le nom que vous avez mis dans la commande "run").

### 5 - Import/export de CSV

Très souvent, on doit importer ou exporter le contenu de la base de données sous forme manipulable par un éditeur texte ou un tableur.
Le plus adapté est le format dit "CSV" (mais qui n'a pas de normalisation, les champs pouvent être séparés par `,` ou `;`, voir par le caractère TAB ou SPC).

Pour exporter, on peut le faire avec une requete SQL, en spécifiant explicitement les options.
Par exemple:
```
SELECT * INTO OUTFILE '/path/to/myfile.csv'
   FIELDS TERMINATED BY ','
   ENCLOSED BY '"'
   LINES TERMINATED BY '\n'
   FROM nom-de-la-table;
```
Pour importer c'est très similaire:
Par exemple:
```
LOAD DATA INFILE '/path/to/myfile.csv'
    INTO TABLE nom-de-la-table
    FIELDS TERMINATED BY ','
    ENCLOSED BY '"'
    LINES TERMINATED BY '\n'
    IGNORE 1 LINES;
```

A noter que `IGNORE 1 LINES` permet de laisser dans le fichier csv la première ligne qui très souvent contient la description des champ.
Elle sera donc ignorée ici lors de l'import.

**Remarque**: la localisation du fichier d'entrée doit être considérée avec soin, particulièrement si la BDD est conteneurisée.
Dans certaines situations, il faudra ajouter le mot clé `LOCAL`
(`LOAD DATA LOCAL INFILE ...`), voir les détails ici:
* https://dev.mysql.com/doc/refman/8.4/en/load-data.html
* https://mariadb.com/kb/en/load-data-infile/

**Attention**: Cette technique implique que l'ordre des colonnes dans le fichier CSV soit identique à l'ordre dans la table.
Si ça n'est pas le cas, il faudra spécifier dans la commande SQL quelle colonne va dans quel champ de la table,
voir les pages de doc ci-dessus pour la syntaxe exacte.

