#include <stdio.h>
#include <time.h>

int * selectionSort(int v[], int size, double *t)
{
    clock_t tempo;
    tempo = clock();
    int i, j, smallestIndex, temp;
    for(i = 0; i < size-1; i++)
    {
        smallestIndex = i;
        for(j = i+1; j < size; j++)
        {
            if(v[j] < v[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        if(i != smallestIndex)
        {
            temp = v[i];
            v[i] = v[smallestIndex];
            v[smallestIndex] = temp;
        }
    }
    tempo = clock() - tempo;
    *t = *t + tempo / (double)CLOCKS_PER_SEC;
    return v;
}

int * insertionSort(int v[], int size, double *t)
{
    clock_t tempo;
    tempo = clock();
    int i, j, temp;
    for(i = 0; i < size-1; i++)
    {
        for(j = i+1; j > 0; j--)
        {
            if(v[j] < v[j-1])
            {
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }
    }
    tempo = clock() - tempo;
    *t = *t + tempo / (double)CLOCKS_PER_SEC;
    return v;
}