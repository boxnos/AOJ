test:
	clicoder all

a.out: main.cpp
	g++ -std=c++ $^
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
