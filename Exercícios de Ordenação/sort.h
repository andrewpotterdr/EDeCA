typedef struct number
{
    long long value;
    struct number * next;
} number;

long long * selectionSort(long long v[], int size, double *t);
long long * insertionSort(long long v[], int size, double *t);
void mergeSort(long long v[], int start, int end);
void merge(long long v[], int start, int middle, int end);
void printVector(int size, long long vec[size]);
int partition(long long v[], int start, int end);
void quickSort(long long v[], int start, int end);
void posify(long long v[], int size);
long long biggerNum(long long v[], int size);
void countingSort(long long v[], int size);
void push(number * head, long long value);
long long pop(number ** head);
void radixSort(long long v[], int size);
int left(int i);
int right(int i);
void maxHeapify(long long v[], int heapSize, int i);
void buildMaxHeap(long long v[], int heapSize);
void heapSort(long long v[], int heapSize);