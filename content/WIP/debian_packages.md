# Gestion des paquets Debian

!!!!!!!!!!WIP!!!!!!!!!!!

Le système de paquets utilisé par Debian et les distributions dérivées (Ubuntu, Mint, ...) permet d'homogénéiser la gestion des programmes installés.

A noter qu'il existe dans cet ecosystème d'autres systèmes, voir [ci-dessous](#autres).

D'autres distributions utilisent d'autres systèmes: Fedora => rpm, RedHat => yum

Beaucoup de détails ici:
https://www.debian.org/doc/manuals/debian-faq/pkgtools.fr.html

## 1 - Paquet Debian

A debian package is a Unix ar archive that includes two tar archives: one containing the control information and another with the program data to be installed.

## 2 - `dpkg`

Outil de gestion des paquets de *bas* niveau.

Cet outil sert à manipuler des fichiers "package" Debian, d'extension `.deb`.
Ces fichiers, au contenu très normalisés, contiennent tout le nécessaire pour installer un logiciel.

Installer une application à partir de son fichier .deb: 
```
$ sudo dpkg -i fichier.deb
```

Lister les paquets installés sur la machine:
```
$ dpkg -l
```

Lister le contenu d'un fichier .deb, ce qui affiche aussi l'emplacement cible de chaque fichier: 
```
$ sudo dpkg -c fichier.deb
```


## 3 - `apt`

__Advanced Package Tool__, outil de gestion des paquets de **haut niveau**.



### Différence entre les deux outils

Historiquement, il existait plusieurs programmes dédiés à la gestion des paquets, qui commencaient tous par `apt-...`.

Depuis, le binaire `apt` regroupe toutes les fonctionnalités, c'est une _surcouche_ aux différents binaires `apt-...`.

Parfois le nom du paquet est différent du nom du programme que l'on cherche à installer, et un paquet peut contenir plusieurs programmes.
On peut faire une recherche avec:
```
$ apt search <nom-du-prog>
```

Installer une application à partir de son nom:
```
$ sudo apt install <nom-du-prog>
```

Obtenir des détails sur un paquet (qu'il soit installé ou pas):
```
$ apt show <nom-paquet>
```


Supprimer une application à partir de son nom:
```
$ sudo apt remove <nom-du-prog>
```
ou
```
$ sudo apt purge <nom-du-prog>
```

Cette dernière commande va également supprimer tous les fichiers de configuration associés.

## 4 - Différence entre `apt` et `dpkg`

source: https://www.geeksforgeeks.org/linux-unix/difference-between-apt-and-dpkg-in-ubuntu/

| Feature | apt | dpkg |
|-----|---|----|
| Purpose | High-level package management tool | Low-level package management tool |
| Functionality | Can manage package installation, upgrades, dependency resolution, and repository management | Installs, uninstalls, and manages individual Debian packages |
| Dependency Handling | Automatically resolves and installs package dependencies | Does not handle dependencies; requires manual installation of dependencies |
| Source | Fetches packages from online repositories (via the internet) | Installs packages from local .deb files |
| Repository Management | Can manage multiple repositories, add/remove repositories easily | No repository management; operates on local .deb packages only |
| Cache Management | Maintains a local cache of available packages from repositories (apt-cache) | No cache management for package listings |
| Ease of Use | User-friendly, with simplified syntax and higher abstraction for managing packages  | Requires more manual intervention, particularly for dependencies |
| Automatic Updates | Supports automatic updates and upgrades with simple commands (apt upgrade)  | No built-in support for automatic updates  |
| Interaction Level | Typically used by end-users for package management | Typically used by system administrators or for specific package operations  |
| Log Files | | /var/log/apt/ | /var/log/dpkg.log  |
| Uninstalling Packages | Automatically handles dependency removal (apt autoremove) | Does not manage dependencies during uninstallation |


## 5 - Autres systèmes de gestion de paquets
<a name="autres"></a>

Au niveau OS:
* snap
* flatpak
* AppImage

Pour des comparatifs, voir:



Au niveau environnement de dev:
* Python gère l'installation de paquets via l'outil
[`pip`](https://fr.wikipedia.org/wiki/Pip_(gestionnaire_de_paquets))
* Node.js, basé sur Javascript, gère l'installation de paquets avec les outils
[`npm`](https://fr.wikipedia.org/wiki/Npm)
ou
[`yarn`](https://fr.wikipedia.org/wiki/Yarn)


