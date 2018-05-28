CXXFLAGS = -std=c++98
target = main
rm_prefix = $(subst test-in,,$1)

test: in_0 $(target)
	make --no-print-directory $(addprefix test-,$(shell ls in**))

test-in%:
#	./$(target) < in$(call rm_prefix,$@)
	./$(target) < in$(call rm_prefix,$@) | diff - out$(call rm_prefix,$@)

in_0 : test.txt
	csplit -z $< /^#/ {*}
	sed -i -e '/^#/d;/^$$/d' xx*
	for x in $$(seq 0 $$(expr $$(ls xx** | wc -l ) / 2 - 1)); do\
	  mv $$(printf "xx%02d" $$(expr $$x \* 2 )) in_$${x} ;\
	  mv $$(printf "xx%02d" $$(expr $$x \* 2 + 1 )) out_$${x} ;\
	done

clean:
	rm -f in* out*
	rm -f main
