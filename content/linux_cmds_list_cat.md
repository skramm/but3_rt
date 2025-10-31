# Linux Shell: liste de commandes par catégorie

<a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

<a name='top'></a>

Catégories:  
* 1 - [Général](#cat4)
* 2 - [Édition/visualisation fichiers](#cat14)
* 3 - [Disque & stockage](#cat2)
* 4 - [Manipulation fichiers](#cat11)
* 5 - [Manipulation dossiers](#cat15)
* 6 - [Réseau](#cat3)
* 7 - [Fichiers & permissions](#cat5)
* 8 - [Système & _Hardware_](#cat1)
* 9 - [Dev](#cat6)
* 10 - [Traitement données texte](#cat8)
* 11 - [Gestion utilisateurs](#cat9)
* 12 - [Installation logiciels](#cat10)
* 13 - [Divers](#cat7)
* 14 - [Gestion des jobs & process](#cat12)
* 15 - [controle des scripts](#cat16)
* 16 - [Gestion Kernel](#cat13)

Total: 187 commandes

**Statut**: 
- _builtin_: commande intégrée au Shell
- _installed_: programme installé et disponible dans l'OS local (VM Github)
- NI (_Not Installed_): programme non installé


## 1 - catégorie: Général
<a name='cat4'></a>

13 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+alias'>alias</a> | composition de commandes | [unalias](linux_cmds_list_alpha.md#u) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+help'>help</a> | liste commandes "_builtin_" et aide | [man](linux_cmds_list_alpha.md#m) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+history'>history</a> | historique des commandes |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+locate'>locate</a> | localise un programme dans le système | [which](linux_cmds_list_alpha.md#w) | NI |
| <a href='https://www.google.fr/search?q=linux+lsb_release'>lsb_release</a> | version distribution | [uname](linux_cmds_list_alpha.md#u) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+man'>man</a> | manuel | [help](linux_cmds_list_alpha.md#h) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+pwd'>pwd</a> | _print working directory_ |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+unalias'>unalias</a> | suppression d'un alias | [alias](linux_cmds_list_alpha.md#a) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+uname'>uname</a> | version noyau | [lsb_release](linux_cmds_list_alpha.md#l) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+wc'>wc</a> | _word count_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+whatis'>whatis</a> | que fait cette commande? |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+who'>who</a> | qui est loggé? |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+whoami'>whoami</a> | qui suis-je? |  | _installed_ |

## 2 - catégorie: Édition/visualisation fichiers
<a name='cat14'></a>

13 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+bat'>bat</a> | cat en mieux | [cat,tail](linux_cmds_list_alpha.md#c) | NI |
| <a href='https://www.google.fr/search?q=linux+cat'>cat</a> | affiche et/ou concatene un/des fichiers |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+file'>file</a> | nature d'un fichier |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+head'>head</a> | premières lignes texte | [tail](linux_cmds_list_alpha.md#t) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+less'>less</a> | filtre d'affichage | [more](linux_cmds_list_alpha.md#m) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+more'>more</a> | filtre d'affichage | [less](linux_cmds_list_alpha.md#l) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+nano'>nano</a> | éditeur console basique |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+od'>od</a> | visualisation en hexa ou octal | [xxd](linux_cmds_list_alpha.md#x) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+stat'>stat</a> | détails complets sur un fichier |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tac'>tac</a> | affiche ordre inversé | [cat](linux_cmds_list_alpha.md#c) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tail'>tail</a> | dernières lignes texte | [head](linux_cmds_list_alpha.md#h) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+touch'>touch</a> | création ou MAJ date d'un fichier |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+xxd'>xxd</a> | visualisation en hexa | [od](linux_cmds_list_alpha.md#o) | _installed_ |

## 3 - catégorie: Disque & stockage
<a name='cat2'></a>

4 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+dd'>dd</a> | utilitaire de copie bas niveau |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+df'>df</a> | _disk free_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+du'>du</a> | _disk usage_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+fdisk'>fdisk</a> |  |  | _installed_ |

## 4 - catégorie: Manipulation fichiers
<a name='cat11'></a>

6 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+cmp'>cmp</a> | comparaison de fichiers | [diff](linux_cmds_list_alpha.md#d) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+cp'>cp</a> | copie fichier(s) | [mv](linux_cmds_list_alpha.md#m) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+diff'>diff</a> | différences entre 2 fichiers, ligne par ligne | [cmp](linux_cmds_list_alpha.md#c) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ln'>ln</a> | création de lien, symbolique ou _hardlink_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+mv'>mv</a> | déplacement/renommage | [cp](linux_cmds_list_alpha.md#c) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+rm'>rm</a> | suppression fichier | [rmdir](linux_cmds_list_alpha.md#r) | _installed_ |

## 5 - catégorie: Manipulation dossiers
<a name='cat15'></a>

7 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+cd'>cd</a> | _Change Directory_ | [pushd](linux_cmds_list_alpha.md#p) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+ls'>ls</a> | _list directory content_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+mkdir'>mkdir</a> | _make directory_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+popd'>popd</a> | récupération dossier courant | [pushd](linux_cmds_list_alpha.md#p) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+pushd'>pushd</a> | chgt dossier courant avec sauvegarde | [popd](linux_cmds_list_alpha.md#p) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+rmdir'>rmdir</a> | supression dossier | [rm](linux_cmds_list_alpha.md#r) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tree'>tree</a> | affiche l'arborescence d'un dossier | [ls](linux_cmds_list_alpha.md#l) | _installed_ |

## 6 - catégorie: Réseau
<a name='cat3'></a>

22 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+curl'>curl</a> | client multiprotocoles (wget en mieux) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+dig'>dig</a> | requete DNS |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ftp'>ftp</a> | transfert de fichiers |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+hostname'>hostname</a> | nom de la machine |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ip'>ip</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+nc'>nc</a> | alias pour netcat | [netcat](linux_cmds_list_alpha.md#n) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+netcat'>netcat</a> | utilitaire TCP/UDP | [nc](linux_cmds_list_alpha.md#n) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+netstat'>netstat</a> | infos/reseau, routage, etc. |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+nmap'>nmap</a> | exploration réseau |  | NI |
| <a href='https://www.google.fr/search?q=linux+nmcli'>nmcli</a> | pilote CLI des connexions réseau |  | NI |
| <a href='https://www.google.fr/search?q=linux+nslookup (_deprecated_)'>nslookup (_deprecated_)</a> | outil DNS | [dig](linux_cmds_list_alpha.md#d) | NI |
| <a href='https://www.google.fr/search?q=linux+ping'>ping</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+rsync'>rsync</a> | transfert de fichier (bas niveau) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ssh'>ssh</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ssh-add'>ssh-add</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ssh-copy-id'>ssh-copy-id</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ssh-keygen'>ssh-keygen</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tcpdump'>tcpdump</a> | capture trames réseau (Wireshark en CLI) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+traceroute'>traceroute</a> |  |  | NI |
| <a href='https://www.google.fr/search?q=linux+ufw'>ufw</a> |  pilote CLI de Firewall  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+wget'>wget</a> | client http CLI | [curl](linux_cmds_list_alpha.md#c) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+whois'>whois</a> | infos/domaine |  | NI |

## 7 - catégorie: Fichiers & permissions
<a name='cat5'></a>

10 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+chage'>chage</a> | _change user password expiry information_ | [passwd](linux_cmds_list_alpha.md#p) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+chgrp'>chgrp</a> | chgt groupe propriétaire fichier |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+chmod'>chmod</a> | chgt permissions fichier |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+chown'>chown</a> | chgt propriétaire fichier |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+find'>find</a> | _search for files, folders,_ ... |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+sort'>sort</a> | tri de texte |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tar'>tar</a> | utilitaire archivage | [zip](linux_cmds_list_alpha.md#z) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+umask'>umask</a> | permissions par défaut | [chmod](linux_cmds_list_alpha.md#c) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+unzip'>unzip</a> | décompression zip | [zip](linux_cmds_list_alpha.md#z) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+zip'>zip</a> | compression zip | [unzip](linux_cmds_list_alpha.md#u) | _installed_ |

## 8 - catégorie: Système & _Hardware_
<a name='cat1'></a>

17 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+free'>free</a> | état RAM utilisée/libre | [vmstat](linux_cmds_list_alpha.md#v) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+halt'>halt</a> |  | [shutdown,reboot](linux_cmds_list_alpha.md#s) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+lsblk'>lsblk</a> | liste périphs stockage "bloc" |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+lscpu'>lscpu</a> | détails sur archi CPU |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+lsdev'>lsdev</a> | infos générales sur _hardware_ |  | NI |
| <a href='https://www.google.fr/search?q=linux+lshw'>lshw</a> | _list hardware_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+lsof'>lsof</a> | _list open files_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+lspci'>lspci</a> | _list all PCI devices_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+lstopo'>lstopo</a> |  |  | NI |
| <a href='https://www.google.fr/search?q=linux+lsusb'>lsusb</a> | liste périphs USB |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+reboot'>reboot</a> |  | [shutdown,halt](linux_cmds_list_alpha.md#s) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+sensors'>sensors</a> | données capteurs (température, tension, etc.) |  | NI |
| <a href='https://www.google.fr/search?q=linux+shutdown'>shutdown</a> |  | [reboot,halt](linux_cmds_list_alpha.md#r) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ss'>ss</a> | _list sockets_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+su'>su</a> | changement temp. d'utilisateur | [sudo](linux_cmds_list_alpha.md#s) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+sudo'>sudo</a> | exécution d'une commande admin | [su](linux_cmds_list_alpha.md#s) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+vmstat'>vmstat</a> | état mémoire virtualle | [free](linux_cmds_list_alpha.md#f) | _installed_ |

## 9 - catégorie: Dev
<a name='cat6'></a>

7 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+cloc'>cloc</a> | _Count Lines Of Code_ | [wc](linux_cmds_list_alpha.md#w) | NI |
| <a href='https://www.google.fr/search?q=linux+g++'>g++</a> | compilation C++ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+gcc'>gcc</a> | compilation C |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+gdb'>gdb</a> | déboggage pas à pas |  | NI |
| <a href='https://www.google.fr/search?q=linux+git'>git</a> | **LE** gestionnaire de versions de fichiers source |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+make'>make</a> | compilation |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+strings'>strings</a> | extraction de chaines dans des binaires |  | _installed_ |

## 10 - catégorie: Traitement données texte
<a name='cat8'></a>

11 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+awk'>awk</a> | _pattern scanning and processing language_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+cut'>cut</a> | suppression de texte dans des lignes |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+grep'>grep</a> | recherche de chaîne | [ripgrep](linux_cmds_list_alpha.md#r) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+jo'>jo</a> | génération de JSON | [jq](linux_cmds_list_alpha.md#j) | NI |
| <a href='https://www.google.fr/search?q=linux+jq'>jq</a> | traitement de chaines JSON | [jo](linux_cmds_list_alpha.md#j) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+paste'>paste</a> | fusion de lignes de texte de plusieurs fichiers |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ripgrep'>ripgrep</a> | (rg) grep récursif | [grep](linux_cmds_list_alpha.md#g) | NI |
| <a href='https://www.google.fr/search?q=linux+sed'>sed</a> |  _Stream EDitor_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+split'>split</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tr'>tr</a> | _translate or delete characters_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+uniq'>uniq</a> | suppression lignes identiques |  | _installed_ |

## 11 - catégorie: Gestion utilisateurs
<a name='cat9'></a>

9 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+addgroup'>addgroup</a> | création groupe d'utilisateurs | [adduser](linux_cmds_list_alpha.md#a) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+adduser'>adduser</a> | création utilisateur |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+groupadd'>groupadd</a> | création groupe (bas niveau!) | [addgroup](linux_cmds_list_alpha.md#a) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+groups'>groups</a> | affiche les groupes existants | [id](linux_cmds_list_alpha.md#i) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+id'>id</a> | affiche les infos sur un utilisateur |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+passwd'>passwd</a> | changement pwd | [chage](linux_cmds_list_alpha.md#c) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+useradd'>useradd</a> | création utilisateur (bas niveau!) | [adduser](linux_cmds_list_alpha.md#a) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+userdel'>userdel</a> | suppression compte |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+usermod'>usermod</a> | modification compte utilisateur |  | _installed_ |

## 12 - catégorie: Installation logiciels
<a name='cat10'></a>

8 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+apt'>apt</a> | gestion paquets Debian |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+apt-get'>apt-get</a> | gestion paquets Debian (bas niveau) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+dpkg'>dpkg</a> | utilitaire paquets Debian (.deb) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+npm'>npm</a> | gestionnaire de paquets Javascript |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+pip'>pip</a> | gestionnaire de paquets Python (2 ou 3) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+pip3'>pip3</a> | gestionnaire de paquets Python3 |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+rpm'>rpm</a> | gestion paquets Fedora |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+yum'>yum</a> | gestion paquets RedHat |  | NI |

## 13 - catégorie: Divers
<a name='cat7'></a>

27 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+clear'>clear</a> | effacement terminal |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+convert'>convert</a> | conversion format d'image |  | NI |
| <a href='https://www.google.fr/search?q=linux+cron'>cron</a> | planification de tâches |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+date'>date</a> | affiche date & heure |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+env'>env</a> | liste var. environnement |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+eval'>eval</a> | exécute la commande passée en argument |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+fc-list'>fc-list</a> | _list available fonts_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+fmt'>fmt</a> | text formatter |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+hey'>hey</a> | _HTTP load generator_ |  | NI |
| <a href='https://www.google.fr/search?q=linux+last'>last</a> | historique des logins & boots |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+md5sum'>md5sum</a> | calcul de hash MD5 |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+nano'>nano</a> | éditeur "console" |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+pango-view'>pango-view</a> | _convert text to image_ |  | NI |
| <a href='https://www.google.fr/search?q=linux+screen'>screen</a> | multiplexeur de terminal | [tmux](linux_cmds_list_alpha.md#t) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+seq'>seq</a> | _print a sequence of numbers_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+set'>set</a> | paramétrage du shell |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+sleep'>sleep</a> | attente |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tee'>tee</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+time'>time</a> | chronométrage de tâche |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+tmux'>tmux</a> | multiplexeur de terminal | [screen](linux_cmds_list_alpha.md#s) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+tty'>tty</a> | indique le terminal courant (`/dev/pts/XX`) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+type'>type</a> | indique si une commande est interne (_builtin_) ou externe |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+uptime'>uptime</a> | durée fonctionnement système |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+watch'>watch</a> | exécution périodique d'une commande |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+which'>which</a> | localisation (chemin) d'un programme | [locate](linux_cmds_list_alpha.md#l) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+xargs'>xargs</a> |  |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+yes'>yes</a> | _output a string repeatedly until killed_ |  | _installed_ |

## 14 - catégorie: Gestion des jobs & process
<a name='cat12'></a>

12 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+bg'>bg</a> | passage d'un _job_ en arrière plan (_BackGround_) | [fg](linux_cmds_list_alpha.md#f) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+fg'>fg</a> | passage d'un _job_ au premier plan (_ForeGround_) | [bg](linux_cmds_list_alpha.md#b) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+htop'>htop</a> | top en mieux | [top](linux_cmds_list_alpha.md#t) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+jobs'>jobs</a> | affichage des _jobs_ lancés |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+kill'>kill</a> | stoppe un process par PID (envoi d'un signal POSIX) | [pkill](linux_cmds_list_alpha.md#p) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+killall'>killall</a> | stoppe tous les process par nom |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+pidof'>pidof</a> |  donne le PID d'un process | [ps](linux_cmds_list_alpha.md#p) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+pkill'>pkill</a> | stoppe un process par nom | [kill](linux_cmds_list_alpha.md#k) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+ps'>ps</a> | snapshot des process | [top,pstree](linux_cmds_list_alpha.md#t) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+pstree'>pstree</a> | arborescence des process | [ps](linux_cmds_list_alpha.md#p) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+top'>top</a> | _dashboard_ système & process | [htop](linux_cmds_list_alpha.md#h) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+trap'>trap</a> | interception de signal POSIX |  | _builtin_ |

## 15 - catégorie: controle des scripts
<a name='cat16'></a>

11 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+case'>case</a> |  |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+echo'>echo</a> | affichage de texte/variable | [printf](linux_cmds_list_alpha.md#p) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+exit'>exit</a> |  |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+for'>for</a> |  |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+function'>function</a> |  |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+if'>if</a> |  |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+printf'>printf</a> | affichage de texte/variable formatté | [echo](linux_cmds_list_alpha.md#e) | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+read'>read</a> | saisie ligne (clavier ou fichier) |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+return'>return</a> |  |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+source'>source</a> |  |  | _builtin_ |
| <a href='https://www.google.fr/search?q=linux+while'>while</a> |  |  | _builtin_ |

## 16 - catégorie: Gestion Kernel
<a name='cat13'></a>

10 commandes - <a href='#top'>Haut de page</a>- <a href='linux_cmds_list_alpha.md'>Liste alphabétique</a>

| Nom | Description | Voir aussi | Statut |
|-----|-----|-----|-----|
| <a href='https://www.google.fr/search?q=linux+depmod'>depmod</a> | _generates modules.dep and map files_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+dmesg'>dmesg</a> | affichage logs kernel (buffer circulaire) |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+insmod'>insmod</a> | _insert a module into the kernel_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+journalctl'>journalctl</a> | outil d'accès aux logs systemd | [systemctl](linux_cmds_list_alpha.md#s) | _installed_ |
| <a href='https://www.google.fr/search?q=linux+logger'>logger</a> | écriture dans un log système |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+lsmod'>lsmod</a> | _show the status of modules in the kernel_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+modinfo'>modinfo</a> | _show information about a module_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+modprobe'>modprobe</a> | _add and remove modules from the kernel_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+rmmod'>rmmod</a> | _remove a module from the kernel_ |  | _installed_ |
| <a href='https://www.google.fr/search?q=linux+systemctl'>systemctl</a> | gestion des services (CLI/systemd) |  | _installed_ |


_MAJ: 2025-10-31T19:21:22+0000_,
_OS: Ubuntu - 24.04.3 LTS (Noble Numbat)_
