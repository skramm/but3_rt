# Conteneurisation d'un SGBD avec Docker

S. Kramm - 2024

Cette page détaille l'utilisation d'un serveur MySql (ou MariaDB, voir plus bas) de façon conteneurisée avec Docker.

Pour des détails, voir aussi: https://hub.docker.com/_/mysql


## 1 - Utilisation de MySql 5.7

L'utilisation de cette version est la plus simple, mais cette version est en fin de vie, il n'y a plus de mises à jour depuis octobre 2023.

**Etapes**

Il faut d'abord créer un réseau virtuel:
```
$ docker network create mynetwork
```

On peut ensuite lancer un serveur MySql dans un conteneur, connecté à ce réseau:
```
$ docker run \
	--name monserveur \
	--network=mynetwork \
	--rm
	-e MYSQL_ROOT_PASSWORD=secretpw \
	-d \
	-p 3306:3306
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
Il faudra relancer le conteneur sans cette option, attendre son arret, puis examiner le problème avec `$ docker logs monserveur`.

Si le conteneur démarre, on peut y accéder à ce serveur via le nom d'hôte (`monserveur` ici), soit via une appli (php, Python-Flask, ...), soit via le client CLI.

On peut lancer ce dernier dans le shell de l'hote (s'il est installé) avec cette commande:
```
$ mysql -u root --port=3306 -h 127.0.0.1 -p'secretpw'
```
ou
```
$ mysql -u root --port=3306 --protocol=TCP -p'secretpw'
```

Ceci ouvre un shell "sql", dans lequel on peut taper des commandes SQL ou des commandes de gestion.
La doc donnant ces commandes est ici: https://dev.mysql.com/doc/refman/8.4/en/mysql.html

Pour quitter, taper `exit;`.

On peut aussi utiliser ce client CLI pour automatiser des actions sur ce serveur, en lui "passant" un fichier contenant des commandes SQL
(création d'une BDD, création d'une table dans une BDD, rempissage d'une table, etc.):
```
$ mysql -u root --port=3306 -h 127.0.0.1 -p'secretpw' < fichier.sql
```

### Stockage séparé

En lancant le serveur de cette façon, les données sont stockées dans le conteneur.
Conséquence: toutes les données qu'on pourrait y stocker sont perdues à l'arret du conteneur!

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
	-p 3306:3306
	mysql:5.7
```

## 2 - Utilisation de MySql 8

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

Sous Linux/Ubuntu, le client MySql étant déjà issu de MariaDB, la connexion depuis l'hote se fait comme ci-dessus (en faidant attention au n° de port).





