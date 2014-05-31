ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

test:
	clicoder all

a.out: main.cpp
	g++ $^
binary: a.out
	./a.out < in.txt > out.txt

Main.class: Main.java
	javac $^
class: Main.class
	java Main < in.txt > out.txt

build: a.out
execute: binary
