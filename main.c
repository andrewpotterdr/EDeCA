#include <stdio.h>
#include "sort.h"
#define MAX 100001

void printVector(int size, int vec[size]);

void main(int argc, char** argv)
{
    FILE *file;
    int number, i, size, option;
    int v[MAX];

    file = fopen(argv[1], "r");
    if(!file) perror("File not found.\n");
    fscanf(file, "%d", &size);
    for(i = 0; i<size; i++)
    {
        fscanf(file, "%d", &number);
        v[i] = number;
    }
    fclose(file);
    printf("Choose the sorting method:\n1 - Selection Sort\n2 - Insertion Sort\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
            printVector(size, selectionSort(v, size));
        break;
        case 2:
            printVector(size, insertionSort(v, size));
        break;
    }
}

void printVector(int size, int vec[size])
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d\n", vec[i]);
    }
}