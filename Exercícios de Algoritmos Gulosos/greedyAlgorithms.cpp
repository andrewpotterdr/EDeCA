#include "greedyAlgorithms.hpp"

// KRUSKAL vv

int GraphA::kruskal()
{
    int mstWeight = 0;

    sort(edges.begin(), edges.end());

    DisjointSets ds(V);

    vector<pair<int, iPair>>::iterator it;
    for(it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int setU = ds.find(u);
        int setV = ds.find(v);

        if(setU != setV)
        {
            mstWeight += it->first;

            ds.merge(setU, setV);
        }
    }
    return mstWeight;
}

// DIJKSTRA vv

int minDistance(int vert, int dist[], bool sptSet[])
{
    int min = INT_MAX, minIndex;

    for(int i = 0; i < vert; i++)
    {
        if(sptSet[i] == false && dist[i] <= min)
        {
            min = dist[i], minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int vert, int src, int dest, int** graph)
{
    int dist[vert];
    bool sptSet[vert];
    for(int i = 0; i < vert; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for(int i = 0; i < vert; i++)
    {
        int u = minDistance(vert, dist, sptSet);
        sptSet[u] = true;
        for(int j = 0; j < vert; j++)
        {
            if(!sptSet[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printDijkstra(vert, src, dist, dest);
}

void printDijkstra(int vert, int src, int dist[], int dest)
{
    printf("Minimum path from %d to %d: %d\n", src, dest, dist[dest]);
}

// PRIM vv

void prim(int vert, int** graph)
{
    int parent[vert], key[vert];
    bool mstSet[vert];

    for(int i = 0; i < vert; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < vert - 1; i++)
    {
        int u = minDistance(vert, key, mstSet);
        mstSet[u] = true;

        for(int j = 0; j < vert; j++)
        {
            if(graph[u][j] && mstSet[j] == false && graph[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printPrim(vert, parent, graph);
}

void printPrim(int vert, int parent[], int** graph)
{
    int sum = 0;
    for(int i = 1;i < vert; i++)
    {
        sum += graph[i][parent[i]];
    }
    printf("Prim MST: %d\n", sum);
}