#include "heuristicas.hpp"

int main(int argc, char** argv)
{
    FILE *file;
    int vert;
    int inicio = atoi(argv[2]);
    int times = atoi(argv[3]);

    file = fopen(argv[1], "r");
    if(!file) perror("File not found.\n");
    fscanf(file, "%d", &vert);

    int** m = (int**)malloc(vert * sizeof(int*));
    pair<int*,int> l;
    l.first = (int*)malloc((vert+1) * sizeof(int));
    l.second = INT_MAX;

    for(int i = 0; i < vert; i++)
    {
        m[i] = (int*)malloc(vert * sizeof(int));
    }

    for(int i = 0; i < vert; i++)
    {
        for(int j = i; j < vert; j++)
        {
            if(i==j)
            {
               m[i][j] = 0;
            }
            else
            {
                fscanf(file, "%d", &m[i][j]);
                m[j][i] = m[i][j];
            }
        }
    }
    fclose(file);
    for(int i = 0; i < vert; i++)
    {
        for(int j = 0; j < vert; j++)
        {
            if(j == 0)
            {
                printf("%4d", m[i][j]);
            }
            else
            {
                printf(" %4d", m[i][j]);
            }
        }
        puts("");
    }

    printf("MELHOR CAMINHO: %d\n", multiStart(vert, l, m, inicio, times));

    /*pair<int,int>* tips = (pair<int,int>*)malloc(vert * sizeof(pair<int,int>));
    for(int i = 0; i < vert; i++)
    {
        tips[i].first = i;
        tips[i].second = m[0][i];
    }

    quickSort(tips, 0, vert-1);

    for(int i = 0; i < vert; i++)
    {
        printf("%d ", tips[i].first);
    }
    puts("");
    for(int i = 0; i < vert; i++)
    {
        printf("%d ", tips[i].second);
    }*/
}