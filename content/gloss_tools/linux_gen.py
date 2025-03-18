#!/usr/bin/python3

import csv

f_cat="linux_cat.csv"
f_cmd="linux_commands.csv"
mydict = {}
dict.fromkeys([1])

with open(f_cat) as csvfile:
	reader = csv.reader(csvfile, delimiter=";")
	for row in reader:
		print(row)
		mydict[row[0]]=row[1];

print( "type=",type(mydict) )

for i in range(len(mydict)):
	print( "res: ", mydict[i] )
#	print( "i=", i )
		
#	for dct_cat in map(dict, reader):
#		print( "idx=",dct_cat['cat_ID'], "string=", dct_cat['cat_name'] )

'''
with open(f_cmd) as csvfile:
	reader = csv.DictReader(csvfile, delimiter=";")
	for dct_cmd in map(dict, reader):
		print( "idx=",dct_cmd['cat_ID'], "string=", dct_cmd['cat_name'] )
'''

