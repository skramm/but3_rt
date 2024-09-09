# Installation de VM Debian 11 sous VirtualBox

Note 1: suppose une install VirtualBox version 6 ou 7

Note 2: le 1er caractère des commandes ci-dessous (`#` ou `$`) indique respectivement si vous etes loggé en "root" (`#`)  ou en utilisateur standard (`$`).
Ceci a une importance, vérifiez!

## Procédure

1. Créer une nouvelle VM dans VirtualBox de type "Debian 64bits", et la nommer `debian11`.
Lui assigner 4096 MB de RAM et un disque de 32 GB.
Laisser les autres options à leur valeur par défaut.

**NE PAS LUI ASSIGNER d'ISO !**


2. Télécharger l'ISO amd64 de la version 11 de Debian
(codename "Bullseye") pour l'architecture `amd64`, en version **netinst** (ISO de taille minimale, et installation du reste via le réseau):<br>
https://www.debian.org/releases/bullseye/debian-installer/

Le fichier à télécharger doit s'appeler:
`debian-11.X.Y-amd64-netinst.iso`
<br>
(avec "X.Y" un numéro de version)

3. Une fois la machine créée, la sélectionner dans VirtualBox et dans ses paramètres, dans la section "Storage", cliquer sur l'icone de disque optique et aller sélectionner l'ISO que vous venez de télécharger:

![img_vb](img/VB_iso.jpg)



4. Démarrer la MV et installer l'OS en suivant les différents écrans.

**Bien lire le texte affiché**, et répondre de façon adéquate.
Si rien n'est précisé ci-dessous, laisser la valeur par défaut.


  - au démarrage de la procédure d'install, choisir l'install **non-graphique**!!;
  - laisser la langue en anglais mais bien indiquer dans les étapes après le clavier français;
  - donner "root" comme mdp admin et créer un utilisateur `user` avec le mdp: `user`;
  - laisser les options par défaut pour le partitionnement du disque (tous les fichiers dans la même partition);
  - lors de la sélection du miroir pour les paquets, bien choisir la France, puis laisser le choix par défaut;
  - lors de la sélection des logiciels à installer, **décocher** (avec la touche SPC) les bureaux mais laisser les utilitaires (voir ci-dessous).

![selection_soft](img/debian_soft_select_2.png)


**ATTENTION**:
lors de l'install de `grub`, bien valider son installation sur le disque, mais à l'écran suivant **ne pas** laisser le choix par défaut (install "manuelle") mais sélectionner l'install automatique sur le disque!

5. Une fois l'OS installé, se logger en "root", et après un `apt update/apt upgrade`, installer le bureau "xfce4" et l'utilitaire "sudo":

`# apt install xfce4 sudo`

6. Ajouter l'utilisateur courant au groupe des sudoers avec:
```
# /sbin/usermod -aG sudo user
```

7. Rebooter avec:
```
# /usr/sbin/shutdown -r now
```

8. Se logger en "user" puis, via le terminal "xterm", installer les paquets suivant:

`$ sudo apt install firefox-esr xfce4-terminal mousepad unzip`

9. Redémarrer la machine, puis une fois le bureau actif, se logger en "user".
Ouvrir un terminal et taper:
```
$ xrandr --size 1280x960
```

## Procédure pour install Docker (si demandé)

Se logger en "user", puis:

1. Installer Docker avec le gestionnaire de paquet de l'OS:

`$ sudo apt install docker docker.io`


2. Vérifier la version installée et la noter:

`$ sudo docker version`

3. En l'état, l'utilisation du client CLI Docker implique les droits "admin" et donc l'usage de "sudo" pour chaque commande, ce qui est un peu ennuyeux.
<br>
Pour éviter ceci, il faut ajouter au groupe d'utilisateur "docker" (qui a normalement été crée lors de l'install de docker) le "user" actuel:

`$ sudo usermod -aG docker $USER`

4. Les assignations d'utilisateurs aux groupes ne se font que lors du "boot", il faut donc rebooter:

`$ sudo /usr/sbin/shutdown -r now`

5. Relogger vous en "user" et vérifier que vous pouvez utiliser Docker sans être "root" avec:

`$ docker run hello-world`

Vous pouvez aussi voir avec la commande `$ id` que vous êtes bien dans le groupe "docker".


