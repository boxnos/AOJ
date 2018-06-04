CXXFLAGS = -std=c++98 -Wall -Wextra -g
target = main
rm_prefix = $(subst test-in,,$1)
make = make --no-print-directory

test: in_0 $(target)
	 $(make) $(addprefix test-,$(shell ls in**))

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
	rm -f gmon.out

debug: in_0 $(target)
	$(make) $(addprefix debug-,$(shell ls in**))

debug-in%:
	gdb ./$(target)

profile:
	$(make) -B test CXXFLAGS="$(CXXFLAGS) -pg"
	gprof ./$(target) gmon.out | less
	$(make) clean
