# 1 - trim spaces:  awk '{$1=$1;print}'
# 2 - remove first 3 characters: cut -c 3-
# 3 - remove laste character from file sed 's/.$//'
# 4 - remplace | width ;

cat ../glossaire.md | awk '{$1=$1;print}' | cut -c 3- | sed 's/.$//' | tr '|' ';'

