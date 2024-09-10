# Génération de paire de clé SSH pour utilisation sous Github

S. Kramm - IUT Rouen - 2024/09

La procédure complète est décrite dans ce lien, les items ci-dessous en sont un résumé simplifié:

https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent

Il faut au préalable se créer un compte (gratuit) sur https://github.com.

- Une fois connecté, vous pouvez créer un dépot (gros bouton vert).
Lui donner le nom demandé dans le sujet de TP.
<br>
**Attention**: valider la case à cocher pour avoir la création automatique du fichier `README.md`.
Ce fichier texte permettra de donner des informations générales sur ce que contient ce dépot, au [format Markdown](https://fr.wikipedia.org/wiki/Markdown).

Github permet de cloner un dépot avec deux protocoles, HTTPS ou un protocole "git", s'appuyant sur le protocole SSH, et impliquant donc une authentification via une paire de clés.

Le clonage via HTTPS est le plus simple, mais a un gros inconvénient:
<br>
Pour pouvoir pousser sur le dépot, il faudra **à chaque fois** fournir un "token", qui doit préalablement être généré sur votre compte Github.

Pour éviter cette problématique, il est préférable de cloner via le protocole "git", qui s'appuie sur SSH.
Ceci implique de créer préalablement une paire de clés, l'une privée, l'autre publique, puis de configurer votre machine locale et votre compte Github pour pouvoir utiliser ces clés.
Les étapes ci-dessous décrive ce processus:

-1. Dans une console ouverte dans votre "home" de votre machine (`$ cd ~`), générer une paire de clés avec:
<br>
`$ ssh-keygen` 
<br>
Valider avec entrée en laissant toutes les questions avec les réponses par défaut.

-2. Visualiser la paire de clés générée avec:
<br>
`$ ls -l .ssh/`
<br>
Vous devez observer deux fichiers, dont le nom comprend l'algo utilisé pour la génération (rsa ou ed25519), l'un sans extension, l'autre se terminant par `.pub`.
Ce dernier contient la clé **publique**, que vous pouvez transmettre à tout le monde, l'autre contient la clé **privée**, qui ne devra pas quitter la machine.

-3. Lancer l'agent ssh local sur la machine:
`$ eval "\$(ssh-agent -s)"`

-4. Ajouter la clé privée à cet agent:
<br>
`$ ssh-add $\sim$/.ssh/id_ed25519`
<br>
(ou `$ ssh-add $\sim$/.ssh/id_rsa` si l'algo utilisé est RSA)

-5. Ouvrir le fichier contenant la clé **publique** en tapant:
<br>
`$ pluma $\sim$/.ssh/id\ed25519.pub` (ou `id\_rsa.pub`)
<br>
__Note__: si pluma n'est pas installé sur votre machine, essayer mousepad ou tout autre éditeur GUI installé sur la machine.
- Sélectionner tout le contenu (CTRL-A), le copier (CTRL-C), aller sur son profil Github (en haut à droite), sélectionner "__Settings__".
Dans le panneau qui s'ouvre à gauche, sélectionner "__SSH and GPG keys__" et copier la clé dans la zone de texte (CTRL-V).
<br>
Penser à ajouter un identifiant à cette clé, pour pouvoir reconnaitre plus tard la machine sur laquelle vous l'avez crée.
En effet, il faudra faire cette manip sur chaque nouvelle machine où vous aurez besoin de travailler sur ce dépot.

Une fois cette procédure finalisée, vous pouvez 
