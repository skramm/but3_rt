
INFILES  :=$(wildcard *.gantt)
OUTFILES_1 :=$(patsubst %.gantt,%.png,$(INFILES))
OUTFILES_2 :=$(patsubst %.gantt,%.svg,$(INFILES))


all1: $(OUTFILES_1)

all2: $(OUTFILES_2)  

%.png: %.gantt
	plantuml $<
	
%.svg: %.gantt
	java -jar /usr/local/bin/plantuml.jar $<
#	plantuml -tsvg $<
	
	
	
