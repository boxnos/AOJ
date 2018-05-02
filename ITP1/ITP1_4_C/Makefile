target = main
remove_prefix = $(subst test-,,$1)

test: xx00 $(target)
	make --no-print-directory test-xx{00..$(shell expr $(words $(wildcard xx*)) / 2)..2}

test-xx%:
	./$(target) < $(call remove_prefix,$@) | diff - $(shell ruby -e 'puts "$(call remove_prefix,$@)".succ')

xx00 : test.txt
	csplit -z $< /^#/ {*}
	sed -i -e '/^#/d;/^$$/d' xx*

clean:
	rm -f xx*
	rm -f main
