
INFILES  :=$(wildcard *.gantt)
OUTFILES_1 :=$(patsubst %.gantt,out/%.png,$(INFILES))
OUTFILES_2 :=$(patsubst %.gantt,out/%.svg,$(INFILES))


all1: $(OUTFILES_1)

all2: $(OUTFILES_2)  

show:
	@echo "OUTFILES_1=$(OUTFILES_1)"

# for some reason, the recipe
#	plantuml -output out $<
# does not behave as expected
	
out/%.png: %.gantt
	plantuml $<
	@mv *.png out/
	
out/%.svg: %.gantt
	plantuml -tsvg $<
	@mv *.svg out/

mkd:
	mkdir -p out
	
	
	
	
