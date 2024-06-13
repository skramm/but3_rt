#!/usr/bin/env python3
# test3.py

import jinja2
from jinja2 import Environment

import json

# Chargement (et affichage) des données JSON depuis un fichier
with open("persons.json") as json_file:
    liste = json.load(json_file)
print(liste)

print("RENDU HTML:")
def render_jinja_html(template_loc,file_name,**context):
    return jinja2.Environment(
        loader=jinja2.FileSystemLoader(template_loc),
        lstrip_blocks = True,trim_blocks = True 
    ).get_template(file_name).render(context)

res=render_jinja_html( 'templates/', 'test3.html', person_list=liste )
print(res)



