# program = python3 
# target = main.py
program = ./
target = main
rm_prefix = $(subst test-in,,$1)

test: in_0 $(target)
	make --no-print-directory $(addprefix test-,$(shell ls in**))

test-in%:
#	time ./$(target) < in$(call rm_prefix,$@)
	$(program)$(target) < in$(call rm_prefix,$@) | diff - out$(call rm_prefix,$@)

in_0 : test.txt
	csplit -z $< /^\>/ {*}
	sed -i -e '/^>/d' xx*
#	sed -i -e '/^#/d;/^$$/d' xx*
	for x in $$(seq 0 $$(expr $$(ls xx** | wc -l ) / 2 - 1)); do\
	  mv $$(printf "xx%02d" $$(expr $$x \* 2 )) in_$${x} ;\
	  mv $$(printf "xx%02d" $$(expr $$x \* 2 + 1 )) out_$${x} ;\
	done

clean:
	rm -f in* out*
	rm -f main
