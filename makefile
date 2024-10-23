all: program

program: main.o Cezar.o
	gcc main.o Cezar.o -o program -lm

main.o: main.c
	gcc -Wall -g -c main.c

Cezar.o: Cezar.c
	gcc -Wall -g -c Cezar.c

clean:
	rm -f *.o program
