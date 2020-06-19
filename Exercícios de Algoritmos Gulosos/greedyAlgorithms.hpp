#include <climits>
#include <stdio.h>
#include "newGraph.hpp"
#include <algorithm>

using namespace std;

typedef pair<int, int> iPair;

typedef struct GraphA
{
    int V,E;
    vector<pair<int, iPair>> edges;

    GraphA(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }
    int kruskal();
} GraphA;

typedef struct DisjointSets
{
    int *parent, *rank;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        for(int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if(u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if(rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
        
        if(rank[x] == rank[y])
        {
            rank[y]++;
        }
    }
} DisjointSets;

int minDistance(int vert, int dist[], bool sptSet[]);
//void dijkstra(int vert, int src, Graph graph);
void dijkstra(int vert, int src, int dest, int** graph);
void printDijkstra(int vert, int src, int dist[], int dest);
//void prim(int vert, Graph graph);
void prim(int vert, int** graph);
//void printPrim(int vert, int parent[], Graph graph);
void printPrim(int vert, int parent[], int** graph);