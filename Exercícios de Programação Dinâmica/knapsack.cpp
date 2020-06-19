#include "knapsack.hpp"

int knapsack(int size, int m, int p[], int v[])
{
    vector<vector<pair<int, int>>> prod;
    prod.resize(m+1);

    for(int i = 0; i <= m; i++)
    {
        prod[i].resize(size+1);
        for(int j = size-1; j >= 0; j--)
        {
            if(p[j+1] <= i)
            {
                if((v[j+1] + prod[i - p[j+1]][j+1].first) > prod[i][j+1].first)
                {
                    prod[i][j].first = v[j+1] + prod[i - p[j+1]][j+1].first;
                    prod[i][j].second = 1;
                }
                else
                {
                    prod[i][j] = prod[i][j+1];
                    prod[i][j].second = 0;
                }
            }
        }
    }
    
    for(int i = 0; i <= m; i++)
    {
        printf("%2d\t", i);
        for(int j = 0; j <= size; j++)
        {
            printf("%3d - %d\t", prod[i][j].first, prod[i][j].second);
        }
        puts("");
    }
    for(int i = 0, y = m; i < size; i++)
    {
        while(prod[y][i].second == 0 && y == m)
        {
            printf("x%d = %d, ", i+1, 0);
            i++;
        }
        if(y >= p[i+1] && prod[y][i].second == 1)
        {
            printf("x%d = %d, ", i+1, 1);
            y -= p[i+1];
        }
        else
        {
            printf("x%d = %d, ", i+1, 0);
        }
    }
    puts("");
    return prod[m][0].first;
}