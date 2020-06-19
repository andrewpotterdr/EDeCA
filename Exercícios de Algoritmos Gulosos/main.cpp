#include <stdio.h>
#include "greedyAlgorithms.hpp"

int main(int argc, char** argv)
{
    FILE *file;
    int vert;

    file = fopen(argv[1], "r");
    if(!file) perror("File not found.\n");
    fscanf(file, "%d", &vert);
    int m[vert][vert];
    int** graph = new int*[vert];
    for(int i = 0; i < vert; i++)
    {
        graph[i] = new int[vert];
    }

    for(int i = 0; i < vert; i++)
    {
        for(int j = i; j < vert; j++)
        {
            if(i==j)
            {
               graph[i][j] = 0;
            }
            else
            {
                fscanf(file, "%d", &graph[i][j]);
                graph[j][i] = graph[i][j];
            }
        }
    }

    fclose(file);

    GraphA grapho(vert, (vert*vert) - vert);
    for(int i = 0; i < vert; i++)
    {
        for(int j = 0; j < vert; j++)
        {
            if(graph[i][j] > 0)
            {
                grapho.addEdge(i, j, graph[i][j]);
            }
        }
    }

    printf("Kruskal MST: %d\n", grapho.kruskal());
    prim(vert, graph);
    dijkstra(vert, 0, vert-1, graph);
}