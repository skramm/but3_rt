#!/usr/bin/python3
import re
# Reference:
# https://docs.python.org/3/library/re.html

# 3 à 5 caractères quelconques
regex=".{3,5}"
print( "regex=", regex )

while True:
	s=input( "chaine à tester: ")
	res=re.fullmatch( regex, s )
	if res == None:
		print( "pas de match" )
	else:
		print( "match:", res.group() )

# https://www.w3schools.com/python/python_regex.asp#matchobject

