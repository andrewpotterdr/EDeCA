#include <stdio.h>
#include <stdlib.h>
#include "knapsack.hpp"

int main(int argc, char** argv)
{
    FILE *file;
    int size, m, count;

    file = fopen(argv[1], "r");
    if(!file) perror("File not found.\n");
    fscanf(file, "%d", &size);
    fscanf(file, "%d", &m);
    int p[size+1], v[size+1];
    int res[size];
    for(int i = 0; i <= size; i++)
    {
        if(i != 0)
        {
            fscanf(file, "%d", &p[i]);
            fscanf(file, "%d", &v[i]);
        }
        else
        {
            p[i] = 0;
            v[i] = 0;
        }
    }
    fclose(file);

    int result = knapsack(size, m, p, v);
    printf("Result: %d\n", result);
}