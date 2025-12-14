# Installation de paquets logiciels

## 1 - Introduction
Sous Debian et distributions dérivées (Ubuntu, Mint, ...), les applicatifs peuvent s'installer via des "paquets" au format ".deb", sous deux formes:
- soit via un "dépot" distant, que ce soit le/les dépots de la distribution, ou via des dépots tiers, dont il faut alors ajouter la localisation dans l'OS.
- soit via le téléchargement du paquet depuis le site de l'éditeur.

Plusieurs outils sont associés à ces procédures, dont les domaines d'application se chevauchent:
- l'outil de gestion des paquets `dpkg` (ainsi que d'autres outils associés), qui est dédié à la manipulation de paquets en local.
- les outils `apt`, `apt-get` et d'autres, qui permettent de télécharger automatiquement les paquets.

Il existe entre ces deux catégories d'outils des différences fondamentales, qu'il est important de bien appréhender:
- les applicatifs installés via `dpkg` ne seront pas automatiquement mis à jour avec les procédures classiques de MAJ du système.
- les applicatifs installés via `dpkg` ne gèrent pas les **dépendances** liées aux paquets.
- Avec les outils `apt-get` (ou `apt`), vous aurez la garantie que vous installez un paquet adapté à votre version de kernel, de distribution, et d'architecture matérielle.

L'outil  `dpkg` reste cependant utile dans quelque situations, notamment lorsqu'on souhaite installer un paquet téléchargé depuis un site.

A noter qu'on trouve des sources évoquant l'outil `aptitude`, qui est une surcouche en mode "graphique/terminal", qui n'est pas présenté ici mais dont l'usase n'est plus recommandé sous Debian.

## 2 - Utilisation des commandes `apt` et `apt-get`

Certaines des commandes présentées ici implique des droits "admin", ceci sera indiquée par la présence de la commande `sudo`.
S'il est absent, c'est que ce n'est pas nécessaire.

### 2.1 - Différences entre ces deux familles de commandes

L'outil originel est `apt-get`, la commande `apt` est une surcouche apportant quelque fonctionnalités supplémentaires utiles dans le cadre d'une utilisation en direct dans un terminal. 
Mais dans le cadre d'un contexte "IaC" (automatisation), cette commande ne doit pas être utilisée, on lui préfèrera les commandes `apt-get`, `apt-cache`, etc., plus stables et plus fiables.

### 2.2 - Particularités communes

La plupart des commandes admettent plusieurs noms de paquets comme argument.
Par exemple, si on souhaite installer les paquets `aaa`, `bbb` et `ccc`, on pourra faire ceci via une unique commande:

`sudo apt-get install aaa bbb ccc`
ou
`sudo apt install aaa bbb ccc`

## 3 - Manipulation courantes

### 3.1 - Mise à jour des sources de paquets  
`sudo apt-get update`
ou
`sudo apt update`

### 3.2 - Mise à jour des paquets installés sur la machine  
`sudo apt-get upgrade`
ou
`sudo apt upgrade`

### 3.3 - Recherche de paquets, parmi tous ceux référencés

`apt-cache search <XXX>`
ou
`apt search <XXX>`

Ceci va chercher dans le texte de description des paquets.
La commande `apt list <XXX>` va chercher s'il existe une paquet de ce nom dans ceux disponibles.

(A noter que le format de sortie est différent pour ces deux commandes, à essayer)

On peut avoir la liste de tous les paquets disponibles pour votre distribution avec:  
`apt-cache search . | wc -l`

Et leur nombre sera donné par:
`apt-cache search . | wc -l`  
(typiquement >100000)

### 3.4 - Installation d'un paquet

`sudo apt-get install <XXX>`
ou
`sudo apt install <XXX>`

A noter qu'on peut ajouter l'option `--reinstall` si on souhaite réinstaller le paquet dans sa version d'origine

Pour certains (gros) paquets, ces commande peuvent générer un "prompt" demandant confirmation.
Dans un contexte d'automatisation, il faut ajouter l'option `-y` pour ne pas avoir ce prompt.

### 3.5 - Description d'un paquet

`apt-cache show <XXX>`  
ou  
`apt show <XXX>`

Ceci fonctionne que le paquet soit installé sur la machine ou pas.

### 3.6 - Suppression de paquets

`sudo apt remove <XXX>`
ou
`sudo apt-get remove <XXX>`

A noter que ceci va supprimer les binaires, mais ni les fichiers de configuration, ni les données associées.
Pour effectivement tout supprimer, il faut utiliser ces commandes:

`sudo apt-get purge <XXX>`
ou
`sudo apt purge <XXX>`
ou
`sudo apt-get remove --purge <XXX>`

### 3.7 - Contenu d'un paquet
On peut avoir la liste des fichiers contenu dans un paquet avec:

`apt-file list <XXX>`

### 3.8 - Nettoyage du cache

Les paquets téléchargés sont stockés dans le dossier
`/var/cache/apt/`  
(essayer la commande `ls -lh /var/cache/apt/` pour avoir une idée de la taille occupée sur le disque)

On peut vider ce cache avec:

`sudo apt autoclean` ou `sudo apt-get autoclean`  
`sudo apt clean` ou `sudo apt-get clean`  
`sudo apt autoremove` ou `sudo apt-get autoremove`

### 3.9 - Liste des paquets installés:

`apt list --installed`

ou `dpkg --list`

Cette dernière commande tire ses informations de `/var/lib/dpkg/status`
et indique notamment si le paquet est installé (ligne commencant par `ii`)
ou s'il reste leur fichier de configuration (ligne commencant par `rc`)
(voir annexe ci-dessous).

Les deux commandes devraient aboutir au même nombre de paquets:  
`apt list --installed | wc -l`  
`dpkg --list | grep -P "^ii" | wc -l`  
(à essayer)


### 3.10 - Ajout de sources de paquets

Le fichier
`/etc/apt/sources.list`
contient la liste des dépot référencés.

voir aussi le dossier:  
`/etc/apt/sources.list.d/`

On gère les dépots tiers (ajout ou suppression) avec la commande:  
`add-apt-repository`

## 4 - ANNEXES

### 4.1 - Indications données par `dpkg -l`:

First letter → desired package state ("selection state"):

- `u` ... unknown
- `i` ... install
- `r` ... remove/deinstall
- `p` ... purge (remove including config files)
- `h` ... hold

Second letter → current package state:

- `n` ... not-installed
- `i` ... installed
- `c` ... config-files (only the config files are installed)
- `U` ... unpacked
- `F` ... half-configured (configuration failed for some reason)
- `h` ... half-installed (installation failed for some reason)
- `W` ... triggers-awaited (package is waiting for a trigger from another package)
- `t` ... triggers-pending (package has been triggered)


(d'après https://askubuntu.com/a/18807)


## 5 - Sources

- https://www.geeksforgeeks.org/linux-unix/apt-get-command-in-linux-with-examples/
- https://help.ubuntu.com/community/SoftwareManagement
- https://www.debian.org/doc/manuals/debian-handbook/sect.apt-get.en.html
- https://www.debian.org/doc/manuals/debian-faq/pkgtools.en.html


