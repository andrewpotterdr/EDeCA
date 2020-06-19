all: main

main: main.o knapsack.o
	g++ -o main main.cpp knapsack.o

main.o: main.cpp
	g++ -c main.cpp

sort.o: knapsack.cpp knapsack.hpp
	g++ -c knapsack.cpp

clean:
	rm -rf *.o