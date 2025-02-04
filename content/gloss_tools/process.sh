# lecture du fichier CSD et génération du markdown

# 1 - lecture des catégories
declare -A catego
IFS=";";while read -a tab
do
#	echo ${tab[@]}
	catego[${tab[0]}]=${tab[1]}
done < cat.csv

echo "Catégories:"
for key in "${!catego[@]}"
do
	echo "key=$key";
	echo "=> ${key} ${catego[${key}]}"
done


# 2 - lecture fichier et construction fichiers .md

IFS=";";while read -a tab
do
	echo ${tab[@]}
done < gloss2.csv

echo "Lignes"
for value in "${tab[*]}"; do echo "$value"; done


