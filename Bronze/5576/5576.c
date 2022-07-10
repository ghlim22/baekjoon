#include <stdio.h>

#define SIZE (10)

void quicksort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int arr[], int start, int end);
void print_array(int size, int arr[]);

int main(void)
{
    int scores_W[SIZE], scores_K[SIZE], sum_W = 0, sum_K = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        scanf("%d", &scores_W[i]);
    }

    for (int i = 0; i < SIZE; ++i)
    {
        scanf("%d", &scores_K[i]);
    }

    quicksort(scores_W, 0, SIZE - 1);
    quicksort(scores_K, 0, SIZE - 1);

    // print_array(SIZE, scores_W);
    // print_array(SIZE, scores_K);

    for (int i = 7; i < SIZE; ++i)
    {
        sum_W += scores_W[i];
    }

    for (int i = 7; i < SIZE; ++i)
    {
        sum_K += scores_K[i];
    }

    printf("%d %d", sum_W, sum_K);

    return 0;
}

void quicksort(int arr[], int start, int end)
{
    int part = partition(arr, start, end);
    if (start < part - 1)
    {
        quicksort(arr, start, part - 1);
    }
    if (part < end)
    {
        quicksort(arr, part, end);
    }
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[(start + end) / 2];

    while (start <= end)
    {
        while (arr[start] < pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }

        if (start <= end)
        {
            swap(arr, start, end);
            start++;
            end--;
        }
    }

    return start;
}

void swap(int arr[], int start, int end)
{
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

void print_array(int size, int arr[])
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}