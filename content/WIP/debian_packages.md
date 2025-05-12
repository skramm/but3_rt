# Gestion des paquets Debian

!!!!!!!!!!WIP!!!!!!!!!!!

Le système de paquets utilisé par Debian et les distributions dérivées (Ubuntu, Mint, ...) permet d'homogénéiser la gestion des programmes installés.

A noter qu'il existe dans cet ecosystème d'autres systèmes, voir [ci-dessous](#autres).

D'autres distributions utilisent d'autres systèmes: Fedora => rpm, RedHat => yum

Beaucoup de détails ici:
https://www.debian.org/doc/manuals/debian-faq/pkgtools.fr.html

## `dpkg`


## `apt` et `apt-xxx`

Historiquement, il existait plusieurs programmes dédiés à la gestion des paquets, qui commencaient tous par `apt-...`.

Depuis, le binaire `apt` regroupe toutes les fonctionnalités.


Parfois le nom du paquet est différent du nom du programme que l'on cherche à installer, et un paquet peut contenir plusieurs programmes.
On peut faire une recherche avec:
```
$ apt search <nom-du-prog>
```





## Autres systèmes de gestion de paquets
<a name="autres"></a>

Au niveau OS:
* snap
* flatpak

Au niveau environnement de dev:
* Python gère l'installation de paquets via l'outil
[`pip`](https://fr.wikipedia.org/wiki/Pip_(gestionnaire_de_paquets))
* Node.js, basé sur Javascript, gère l'installation de paquets avec les outils
[`npm`](https://fr.wikipedia.org/wiki/Npm)
ou
[`yarn`](https://fr.wikipedia.org/wiki/Yarn)


