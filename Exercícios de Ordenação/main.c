#include <stdio.h>
#include "sort.h"
#define MAX 100001

void main(int argc, char** argv)
{
    FILE *file;
    int number, i, size, option;
    long long v[MAX];
    double executionTime = 0;

    file = fopen(argv[1], "r");
    if(!file) perror("File not found.\n");
    fscanf(file, "%d", &size);
    for(i = 0; i<size; i++)
    {
        fscanf(file, "%d", &number);
        v[i] = number;
    }
    fclose(file);
    printf("Choose the sorting method:\n1 - Selection Sort\n2 - Insertion Sort\n3 - Merge Sort\n4 - Quick Sort\n5 - Counting Sort\n6 - Radix Sort\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
            printVector(size, selectionSort(v, size, &executionTime));
            printf("Execution time for a %d size entry with Selection Sort: %lf seconds.", size, executionTime);
        break;
        case 2:
            printVector(size, insertionSort(v, size, &executionTime));
            printf("Execution time for a %d size entry with Insertion Sort: %lf seconds.", size, executionTime);
        break;
        case 3:
            mergeSort(v, 0, size-1);
            printVector(size, v);
        break;
        case 4:
            quickSort(v, 0, size-1);
            printVector(size, v);
        break;
        case 5:
            countingSort(v, size);
            printVector(size, v);
        break;
        case 6:
            radixSort(v, size);
            printVector(size, v);
        break;
    }
}