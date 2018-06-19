CXXFLAGS = -std=c++11 -O2 -Wall -Wextra
target = main
rm_prefix = $(subst test-in,,$1)
make = make --no-print-directory

test: in_0 $(target)
	 $(make) $(addprefix test-,$(shell ls in**))

test-in%:
#	./$(target) < in$(call rm_prefix,$@)
	time ./$(target) < in$(call rm_prefix,$@) | diff - out$(call rm_prefix,$@)  -u | tr ':' '-'; exit $${PIPESTATUS[1]}
#	./$(target) < in$(call rm_prefix,$@) | ruby -e 'e=0;f=ARGV.map {|n|n=="-" ? STDIN : open(n)};while l=f[0].gets;m=f[1].gets;if(l.to_f-m.to_f).abs>=0.0001;puts"< #{l}> #{m}";e=1;end;end;exit e' - out$(call rm_prefix,$@)

in_0 : test.txt
	ruby -ne'BEGIN{b=[]};if$$_=~/^#/;b<<"";elsif$$_!~/^$$/;b[-1]<<$$_;end;END{b.each.with_index{|f,i|File.write("#{i.odd? ? "out":"in"}_#{i/2}",f)}}'<$<

clean:
	rm -f $(target) in* out* gmon.out

debug: in_0 $(target)
	$(make) -B $(target) $(addprefix debug-,$(shell ls in**)) CXXFLAGS="$(CXXFLAGS) -g"

debug-in%:
	gdb ./$(target)

profile:
	$(make) -B test CXXFLAGS="$(CXXFLAGS) -pg"
	gprof ./$(target) gmon.out | less
	$(make) clean
