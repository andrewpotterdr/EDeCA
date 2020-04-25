all: main

main: main.o sort.o
	gcc -o main main.c sort.o

main.o: main.c
	gcc -c main.c

sort.o: sort.c sort.h
	gcc -c sort.c

clean:
	rm -rf *.o