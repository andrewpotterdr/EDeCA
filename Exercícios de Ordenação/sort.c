#include <stdio.h>
#include <time.h>
#include <math.h>

void printVector(int size, int vec[size])
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d\n", vec[i]);
    }
    printf("\n");
}

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

void merge(int v[], int start, int middle, int end)
{
    int taml = middle-start+1, tamr = end-middle;
    int l[taml], r[tamr], x, z;
    for(x = 0, z = start; x < taml; x++, z++)
    {
        l[x] = v[z];
    }

    for(x = 0, z = middle+1; x < tamr; x++, z++)
    {
        r[x] = v[z];
    }

    int i=0, j=0, k=start;
    while(i < taml && j < tamr)
    {
        if(l[i] <= r[j])
        {
            v[k] = l[i];
            i++;
        }
        else
        {
            v[k] = r[j];
            j++;
        }
        k++;
    }

    while(i < taml)
    {
        v[k] = l[i];
        i++;
        k++;
    }

    while(j < tamr)
    {
        v[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int start, int end)
{
    if(start < end)
    {
        int middle = floor((start + end)/2);
        mergeSort(v,start,middle);
        mergeSort(v,middle+1,end);
        merge(v,start,middle,end);
    }
}

int partition(int v[], int start, int end)
{
    int pivot = start, i = start, j = end, temp = 0;
    while(i < j)
    {
        while(v[i] <= v[pivot] && i <= end)
        {
            i++;
        }
        while(v[j] > v[pivot] && j >= start)
        {
            j--;
        }
        if(i < j)
        {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[j];
    v[j] = v[pivot];
    v[pivot] = temp;

    return j;
}

void quickSort(int v[], int start, int end)
{
    if(start < end)
    {
        int pivot = partition(v, start, end);
        quickSort(v, start, pivot-1);
        quickSort(v, pivot+1, end);
    }
}