all: main.o nodes.o library.o
	gcc -o program main.o nodes.o library.o
main.o: main.c nodes.h library.h
	gcc -g -c main.c
nodes.o: nodes.c nodes.h
	gcc -g -c nodes.c
library.o: library.c library.h
	gcc -g -c library.c
run:
	./program
clean:
	rm -rf program main.o nodes.o library.o
