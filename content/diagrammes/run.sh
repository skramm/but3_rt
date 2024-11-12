# -E, --no-separation
#             Prevents the separation of common edges of shapes.

#-o, --overwrite
#              If  the filename of the destination image already exists, an al‐
#              ternative name is chosen.  If the overwrite option is  selected,
#              the image file is instead overwriten.

for fn in *.dit
do

	ditaa -E -o -b EEFFFF $fn
done	
