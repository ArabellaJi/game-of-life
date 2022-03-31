test:	project1
	./project1

project1.o: 	project1.h
project1:		project1.o
	g++ -o $@ $^
