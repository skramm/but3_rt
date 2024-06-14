
INFILES  :=$(wildcard *.gantt)
OUTFILES :=$(patsubst %.gantt,%.png,$(INFILES))


all: $(OUTFILES) 

%.png: %.gantt
	plantuml $<
	
	
