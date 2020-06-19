#include "newGraph.hpp"

Graph createMatrixGraph(int vert, int vec[])
{
    int counter = 0;
    Graph matrixGraph;
    matrixGraph.vec.resize(vert);
    for(int i = 0; i < vert; i++)
    {
        matrixGraph.vec[i].resize(vert);
        for(int j = i; j < vert; j++)
        {
            if(i==j)
            {
                matrixGraph.vec[i][j] = 0;
            }
            else
            {
                matrixGraph.vec[i][j] = vec[counter];
                matrixGraph.vec[j][i] = vec[counter];
                counter ++;
            }
        }
    }
    return matrixGraph;
}

Graph createListGraph(int vert, int vec[])
{
    int counter = 0;
    Graph listGraph;
    listGraph.vec.resize(vert);
    for(int i = 0; i < vert; i++)
    {
        listGraph.vec[i].resize(vert);
        for(int j = i; j < vert; j++)
        {
            if(i != j)
            {
                if(vec[counter] > 0)
                {
                    listGraph.vec[i][j] = j + 1;
                    listGraph.vec[j][i] = i + 1;
                }
                counter++;
            }
        }
    }
    return listGraph;
}

void printMatrixGraph(int vert, Graph graph)
{
    for(int i = 0; i < vert; i++)
    {
        for(int j = 0; j < vert; j++)
        {
            printf("%5d ", graph.vec[i][j]);
        }
        puts("");
    }
}

void printListGraph(int vert, Graph graph)
{
    for(int i = 0; i < vert; i++)
    {
        printf("%4d -> ", i + 1);
        for(int j = 0; j < graph.vec[i].size(); j++)
        {
            if(j != 0)
            {
                printf(" -> %4d", graph.vec[i][j]);
            }
            else
            {
                printf("%4d", graph.vec[i][j]);
            }
        }
        puts("");
    }
}