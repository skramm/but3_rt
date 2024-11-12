# demo of a md5 collision
# source: Marc Stevens
# https://twitter.com/realhashbreaker/status/1770161965006008570

# Ces deux chaines semblent identiques, mais il y a une tout petite différence
# (de 1 bit, en fait)
# pouvez-vous la voir?

str1='TEXTCOLLBYfGiJUETHQ4hAcKSMd5zYpgqf1YRDhkmxHkhPWptrkoyz28wnI9V0aHeAuaKnak'
str2='TEXTCOLLBYfGiJUETHQ4hEcKSMd5zYpgqf1YRDhkmxHkhPWptrkoyz28wnI9V0aHeAuaKnak'

echo $str1
echo $str2

echo -n $str1 | md5sum
echo -n $str2 | md5sum


# note: -n: no newline. Needed, else the newline is part of the string
