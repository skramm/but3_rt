# Génération de liste de command Linux

- S. Kramm - 2024-2025  
- https://github.com/skramm/but3_rt/

Le fichier [`linux_commands.yml`](../../.github/workflows/linux_commands.yml)
réalise (CI) la génération des deux fichiers
- [`linux_cmds_list_alpha.md`](../linux_cmds_list_alpha.md)
- [`linux_cmds_list_cat.md`](../linux_cmds_list_cat.md)

A partir de deux fichiers source:
- [`linux_cat.csv`](linux_cat.csv): contient les catégories (arbitraires)
- [`linux_commands.csv`](linux_commands.csv): contient les commandes et leur catégorie


Deux étapes:

1 - Exécution du script [`get_type.sh`](get_type.sh)  
Ce dernier va déterminer pour chaque commande si elle est de type "builtin" ou installée sous forme de programme (ou script), ou pas disponible sur la VM sur laquelle la CI s'exécute.
Il produit en sortie un fichier `out.csv`
2 - Compilation et exécution du programme C++ [`linux_gen.cpp`](linux_gen.cpp), en prenant en entrée le fichier `out.csv`.

