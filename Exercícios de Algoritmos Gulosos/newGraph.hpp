#include <vector>
#include <stdio.h>

using namespace std;

typedef struct Graph
{
    vector<vector<int>> vec;
} Graph;

Graph createMatrixGraph(int vert, int vec[]);
Graph createListGraph(int vert, int vec[]);
void printMatrixGraph(int vert, Graph graph);
void printListGraph(int vert, Graph graph);