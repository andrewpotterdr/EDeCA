all: main

main: main.o newGraph.o greedyAlgorithms.o
	g++ -o main main.cpp newGraph.o greedyAlgorithms.o

main.o: main.cpp
	g++ -c main.cpp

greedyAlgorithms.o: greedyAlgorithms.cpp greedyAlgorithms.hpp
	g++ -c greedyAlgorithms.cpp

newGraph.o: newGraph.cpp newGraph.hpp
	g++ -c newGraph.cpp

clean:
	rm -rf *.o
