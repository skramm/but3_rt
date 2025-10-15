# Installation de Docker (Debian)

La procédure décrite ici est prévue pour une Debian 11 ou 12 et a été testée en 2025

**Préalable**: implique que l'utilisateur courant aie les droits "admin" (sudo)


1. Installer Docker avec le gestionnaire de paquet de l'OS:

`$ sudo apt install docker docker.io`


2. Vérifier la version installée et la noter:

`$ sudo docker version`

3. En l'état, l'utilisation du client CLI Docker implique les droits "admin" et donc l'usage de "sudo" pour chaque commande, ce qui est un ennuyeux.  
Pour éviter ceci, il **faut** ajouter au groupe d'utilisateur "docker" (qui a normalement été crée lors de l'install de docker) le "user" actuel:

`$ sudo usermod -aG docker $USER`

4. Les assignations d'utilisateurs aux groupes ne se font que lors du "boot", il faut donc rebooter:

`$ sudo /usr/sbin/shutdown -r now`  
ou  
`$ sudo reboot`

5. Relogger vous en "user" et vérifier que vous pouvez utiliser Docker sans être "root" avec:

`$ docker run hello-world`

Vous pouvez aussi voir avec la commande `$ id` que vous êtes bien dans le groupe "docker".


