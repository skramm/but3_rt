mkdir -p out
set -x
for a in *.gantt
do
	java -jar /usr/local/bin/plantuml.jar -tsvg -output out/ $a
	java -jar /usr/local/bin/plantuml.jar -output out/ $a	
done

	
	
	
