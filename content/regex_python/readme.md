# Utilisation d'expressions régulières ("Regex" en Python)

Package python à utiliser: `re`

https://docs.python.org/3/library/re.html

Autre page à consulter:  
https://www.w3schools.com/python/python_regex.asp

Exemple de mise en oeuvre:

```
regex=".{3,5}"
print( "regex=", regex )

while True:
	s=input( "chaine à tester: ")
	res=re.fullmatch( regex, s )
	if res == None:
		print( "pas de match" )
	else:
		print( "match:", res.group() )
```

Voir fichier [test_regex_1.py](test_regex_1.py)
