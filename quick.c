#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void generateRandomArray(int arr[], int n);
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
void generateRandomArray(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}
int main()
{
    int n_values[] = {5000, 10000, 15000, 20000};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);
    clock_t start, end;
    double time_taken[num_values];
    for (int i = 0; i < num_values; i++)
    {
        int n = n_values[i];
        int *arr = (int*)malloc(n * sizeof(int));
        generateRandomArray(arr, n);
        start = clock();
        quickSort(arr, 0, n - 1);end = clock();
        time_taken[i] = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arr);
    }
    printf("n\tTime Taken (s)\n");
    for (int i = 0; i < num_values; i++)
    {
        printf("%d\t%f\n", n_values[i], time_taken[i]);
    }
    return 0;
}