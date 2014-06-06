test:
	clicoder all

a.out: main.cxx
	g++ $^ -std=c++11
binary: a.out
	./a.out < in.txt > out.txt

Main.class: Main.java
	javac $^
class: Main.class
	java Main < in.txt > out.txt

ruby:
	ruby main.rb < in.txt > out.txt

build: a.out
execute: binary
