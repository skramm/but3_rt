# Utilisation de ssh (WIP!!!!!!!!)


## Génération de clés

```
$ ssh-keygen
```

On peut donner les options suivantes:
```
-t ALGO
```
Permet de spécifier quel algorithme on veut utiliser.
Il y a un par défaut mais ça peut dépendre de la distribution.

ALGO: l'un des algos ci-dessous (celui par défaut
`dsa`, `ecdsa`, `ecdsa-sk`, `ed25519`, `ed25519-sk`, `rsa`


```
-C "nom arbitraire"
```
permet de donner un nom aux clés crées.

## Utilisation de ssh-copy
_use locally available keys to authorise logins on a remote machine_
```
$ ssh-copy-id -i ansible.pub web1
```

## Ajout de clés à l'agent local

Pour que la connection à d'autre machines puisse fonctionner, il faut que la machine soit
"consciente" des clés locales.
Ceci se fait avec la commance `ssh-add`

La commande
```
$ ssh-add -l
```
va lister les identités connues localement.

Il faut qu'un process "ssh" soit lancé.
C'est la commande `ssh-agent` qu'on doit utiliser, mais il faut également que les variables d'environnement
que l'exécution de cette commande génère soit connues de votre shell.
Il faut donc la lancer via la commande Linux `eval`, qui va exécuter ses arguments:
```
$ eval $(ssh-agent$)
```

Ceci aura pour effet d'importer les variables d'environnement dans le shell courant.



