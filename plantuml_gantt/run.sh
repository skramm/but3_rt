
set -x
for a in *.gantt
do
	java -jar /usr/local/bin/plantuml.jar $a
#	plantuml -tsvg $<
done

	
	
	
