#!/usr/bin/python3

import csv

f_cat="linux_cat.csv"
f_cmd="linux_commands.csv"

with open(f_cat, mode='r', newline='\n', encoding='utf-8') as f1:
	cat_reader = csv.DictReader(f1, delimiter=";")
	print( "categories=",list(cat_reader) )
#	print( "nb of categories=",len(categ) )
	for row in cat_reader:
		# Each row is already a dictionary with column names as keys
		print("row:", row)
		# Example: Access specific fields using column names
		print("fields:", row['cat_ID'], row['cat_name'])


