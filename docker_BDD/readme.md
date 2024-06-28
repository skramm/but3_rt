# Conteneurisation d'un SGBD avec Docker

S. Kramm - 2024

Cette page détaille l'utilisation d'un serveur MySql (ou MariaDB, voir plus bas) de façon conteneurisée avec Docker.

Pour des détails, voir aussi: https://hub.docker.com/_/mysql


## Utilisation de MySql 5.7

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

Ceci va créer le conteneur, qu'on peut voir avec la commande:
```
$ docker ps
CONTAINER ID   IMAGE        COMMAND                  CREATED          STATUS          PORTS                 NAMES
6863de356300   mysql:5.7   "docker-entrypoint.s…"   1 minute ago   Up 1 minutes   3306/tcp, 33060/tcp   monserveur
```

On peut maintenant accéder à ce serveur via le nom d'hôte (`monserveur` ici), soit via une appli (php, Python-Flask, ...), soit via le client CLI.

On peut lancer ce dernier dans le shell de l'hote (s'il est installé) avec cette commande:
```
$ mysql -u root --port=3306 -h 127.0.0.1 -p'secret'
```
ou
```
$ mysql -u root --port=3306 --protocol=TCP -p'secret'
```

Ceci ouvre un shell "sql", dans lequel on peut taper des commandes SQL ou des commandes de gestion.
Pour quitter, taper `exit;`.


### Stockage séparé

En lancant le serveur de cette façon, les données sont stockées dans le conteneur!
Conséquence: toutes les données qu'on pourrait y stocker sont perdues à l'arret du conteneur.
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


## Utilisation de MySql 8

**Note1**: pour une raison que personne ne comprends vraiment (et qui a fait sourire la communauté), MySql est passé directement de version 5 à version 8...

**Note2**: Sous Debian et dérivés (Ubuntu, ...) l'installation de MySql installe en fait le fork MariaDB, mais c'est quasi transparent à l'usage.

**Note3**: Les procédures d'authentification ont été renforcées dans cette version, ce qui amène des détails supplémentaires à gérer.


** TODO **







