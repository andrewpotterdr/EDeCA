#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct number
{
    long long value;
    struct number * next;
} number;

void printVector(int size, long long vec[size])
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%lld\n", vec[i]);
    }
    printf("\n");
}

long long * selectionSort(long long v[], int size, double *t)
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

long long * insertionSort(long long v[], int size, double *t)
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

void merge(long long v[], int start, int middle, int end)
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

void mergeSort(long long v[], int start, int end)
{
    if(start < end)
    {
        int middle = floor((start + end)/2);
        mergeSort(v,start,middle);
        mergeSort(v,middle+1,end);
        merge(v,start,middle,end);
    }
}

int partition(long long v[], int start, int end)
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

void quickSort(long long v[], int start, int end)
{
    if(start < end)
    {
        int pivot = partition(v, start, end);
        quickSort(v, start, pivot-1);
        quickSort(v, pivot+1, end);
    }
}

long long biggerNum(long long v[], int size)
{
    int i;
    long long bigger = 0;
    for(i = 0; i < size; i++)
    {
        if(v[i] > bigger)
        {
            bigger = v[i];
        }
    }
    return bigger;
}

void posify(long long v[], int size)
{
    int i;
    long long smallest = 0;
    for(i = 0; i < size; i++)
    {
        if(v[i] < smallest)
        {
            smallest = v[i];
        }
    }
    if(smallest < 0)
    {
        for(i = 0; i < size; i++)
        {
            v[i] += (smallest*-1);
        }
    }
}

void countingSort(long long v[], int size)
{
    posify(v, size);
    long long bigger = biggerNum(v, size);
    int aux[bigger], i, j;
    for(i = 0; i <= bigger; i++)
    {
        aux[i] = 0;
    }
    for(i = 0; i < size; i++)
    {
        aux[v[i]]++;
    }
    for(i = 0, j = 0; j < size;)
    {
        if(aux[i] > 0)
        {
            v[j] = i;
            j++;
            aux[i]--;
        }
        else
        {
            i++;
        }       
    }
}

void push(number * head, long long value)
{
    number *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = (number *) malloc(sizeof(number));
    current->next->value = value;
    current->next->next = NULL;
}

long long pop(number * head)
{
    long long value;
    number *trash, *next = NULL;
    trash = head->next;
    if(trash == NULL)
    {
        return -1;
    }
    next = trash->next;
    value = trash->value;
    free(trash);
    head->next = next;

    return value;
}

void radixSort(long long v[], int size)
{
    posify(v, size);
    long long bigger = biggerNum(v, size);
    int i, j, k, digits = 1, m;
    while(bigger/10 != 0)
    {
        digits++;
        bigger /= 10;
    }
    number numbers[10], *ptr;
    for(i = 0; i < 10; i++)
    {
        ptr = &numbers[i];
        ptr->value = -1;
        ptr->next = NULL;
    }
    for(i = 0, m=1; i < digits; i++, m*=10)
    {
        for(j = 0; j < size; j++)
        {
            char str[15], str2[2];
            sprintf(str, "%lld", (v[j]/m));
            str2[0] = str[strlen(str) - 1];
            str2[1] = '\0';
            switch(atoi(str2))
            {
                case 0:
                    ptr = &numbers[0];
                break;
                case 1:
                    ptr = &numbers[1];
                break;
                case 2:
                    ptr = &numbers[2];
                break;
                case 3:
                    ptr = &numbers[3];
                break;
                case 4:
                    ptr = &numbers[4];
                break;
                case 5:
                    ptr = &numbers[5];
                break;
                case 6:
                    ptr = &numbers[6];
                break;
                case 7:
                    ptr = &numbers[7];
                break;
                case 8:
                    ptr = &numbers[8];
                break;
                case 9:
                    ptr = &numbers[9];
                break;
            }
            push(ptr, v[j]);
        }
        long long retvalue = 0;
        for(j = 0, k = 0; j < size;)
        {
            retvalue = pop(&numbers[k]);
            if(retvalue != -1)
            {
                v[j] = retvalue;
                j++;
            }
            else
            {
                k++;
            }
        }
    }
}