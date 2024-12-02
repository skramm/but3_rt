#!/usr/bin/env python3
# test2.py
import jinja2

# sans Flask, on ne peut pas appeler directement la fonction render_template().
#(voir tuto https://www.geeksforgeeks.org/templating-with-jinja2-in-flask/ )

# Il faut donc ruser et définir une fonction annexe,
# d'après https://stackoverflow.com/a/33944561/193789


def render_jinja_html(template_loc,file_name,**context):
    return jinja2.Environment(
        loader=jinja2.FileSystemLoader(template_loc)
    ).get_template(file_name).render(context)
    
    
fruits = ["apple", "banana", "cherry"]
res=render_jinja_html( 'templates/', 'test2.html', liste_fruits=fruits )
print(res)



