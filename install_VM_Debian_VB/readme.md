# TITRE

## Procédure


1. Créer une nouvelle MV dans VirtualBox de type "Debian 64bits", et la nommer {\btt debian11}.
Lui assigner 4096~MB de RAM et un disque de 32~GB.
Laisser les autres options à leur valeur par défaut.

**NE PAS LUI ASSIGNER d'ISO !**


2. Télécharger l'ISO amd64 de la version 11 de Debian
(codename "Bullseye"):<br>
https://www.debian.org/releases/bullseye/debian-installer/

Le fichier à télécharger doit s'appeler:
`debian-11.8.0-amd64-netinst.iso`

3. Une fois la machine créée, la sélectionner dans VirtualBox et dans ses paramètres, dans la section "Storage", cliquer sur l'icone de disque optique et aller sélectionner l'ISO que vous venez de télécharger:

![img_vb](img/VB_iso.png)



4. Démarrer la MV et installer l'OS en suivant les différents écrans.

**Bien lire le texte affiché**, et répondre de façon adéquate.
Si rien n'est précisé ci-dessous, laisser la valeur par défaut.


	- au démarrage de la procédure d'install, choisir l'install **non-graphique**!!;
	- laisser la langue en anglais mais bien indiquer dans les étapes après le clavier français;
	- donner "root" comme mdp admin et créer un utilisateur `user` avec le mdp: `user`;
	- laisser les options par défaut pour le partitionnement du disque (tous les fichiers dans la même partition);
	- lors de la sélection du miroir pour les paquets, bien choisir la France;
	- lors de la sélection des logiciels à installer, **décocher** les bureaux mais laisser les utilitaires (voir ci-dessous).

![selection_soft](img/debian_soft_select_2)


%\begin{enumerate}
\item {\bf
**ATTENTION**:
lors de l'install de `grub`, bien valider l'installation sur le disque, mais à l'écran suivant {\bf ne pas} laisser le choix par défaut (install manuelle) mais sélectionner l'install automatique sur le disque!
%\end{enumerate}

\item Une fois l'OS installé, se logger en "root", et après un {\btt apt update/apt upgrade}, installer le bureau "xfce4" et l'utilitaire "sudo": \\
\fbox{\btt \# apt install xfce4 sudo}

\item Ajouter l'utilisateur courant au groupe des sudoers avec:
\fbox{\btt \# /sbin/usermod -aG sudo user}

\item Rebooter avec 
\fbox{\btt \# /usr/sbin/shutdown -r now}
et se relogger en "user".

%\item Via le terminal "xterm", passer "root" avec \fbox{\btt \$ su} et installer les paquets {\btt mousepad} (editeur texte graphique léger), {\btt firefox-esr}, {\btt sudo}, {\btt xfce4-terminal} (beaucoup plus convivial que "xterm", le terminal par défaut), et {\btt unzip}: \\
%\fbox{\btt \$ apt install firefox-esr sudo xfce4-terminal mousepad unzip}


\item Via le terminal "xterm", installer les paquets {\btt mousepad} (editeur texte graphique léger), {\btt firefox-esr}, {\btt sudo}, {\btt xfce4-terminal} (beaucoup plus convivial que "xterm", le terminal par défaut), et {\btt unzip}: \\
\fbox{\btt \$ sudo apt install firefox-esr sudo xfce4-terminal mousepad unzip}

\item Redémarrer la machine, puis une fois le bureau actif, se logger en "user".
Via le menu \\
"Applications$\rightarrow$Settings$\rightarrow$Display", régler la définition d'écran sur 1280x960.

\item Installer ensuite Docker avec le gestionnaire de paquet de l'OS \\
\fbox{\btt \$ sudo apt install docker docker.io}

%\item Se connecter depuis la MV sur
%\url{https://docs.docker.com/engine/install/debian/} \\
%et suivre la procédure recommandée pour installer Docker (en restant connecté en root).


%\item Quitter le mode "root" avec \fbox{\btt \$ exit}, vérifier que vous êtes bien {\btt user} avec
%\fbox{\btt \$ whoami}, et donner la version installée avec 
\item Donner la version installée avec 
\fbox{\btt \$ sudo docker version}:
\answerbox{4cm}


%\paragraph{Post-install}

\item En l'état, l'utilisation du client CLI Docker implique les droits "admin" et donc l'usage de {\btt sudo} pour chaque commande, ce qui est un peu ennuyeux.
Pour éviter ceci, il faut ajouter au groupe d'utilisateur docker (qui a normalement été crée lors de l'install de docker) le "user" actuel:
%\begin{Verbatim}[frame=single,fontseries=b]
%$ sudo groupadd docker

\fbox{\btt \$ sudo usermod -aG docker \$USER}
%\end{Verbatim}

\item Les assignations d'utilisateurs aux groupes ne se font que lors du "boot", il faut donc rebooter:\\
\fbox{\btt \$ sudo /usr/sbin/shutdown -r now}


\item Vérifier que vous pouvez utiliser Docker sans être "root" avec:

\fbox{\btt \$ docker run hello-world}

