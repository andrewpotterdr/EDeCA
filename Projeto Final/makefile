all: main

main: main.o heuristicas.o
	g++ -o main main.cpp heuristicas.o

main.o: main.cpp
	g++ -c main.cpp

heuristicas.o: heuristicas.cpp heuristicas.hpp
	g++ -c heuristicas.cpp

clean:
	rm -rf *.o
