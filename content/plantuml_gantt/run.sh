mkdir -p out
set -x
for a in *.gantt
do
	java -jar /usr/local/bin/plantuml.jar -tsvg -output out2/ $a
	java -jar /usr/local/bin/plantuml.jar -output out2/ $a	
done

	
	
	
