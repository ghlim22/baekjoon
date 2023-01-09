#include <stdio.h>

static int numbers[1000000];

static int part(int low, int high)
{
    int pivot = numbers[low];
    while (low < high)
    {
        while (low < high && numbers[high] >= pivot)
            high--;
        if (high == low)
            break;
        numbers[low++] = numbers[high];
        while (low < high && numbers[low] <= pivot)
            low++;
        if (high == low)
            break;
        numbers[high--] = numbers[low];  
    }
    if (low == high)
        numbers[low] = pivot;
    return (low);
}

static void quicksort(int low, int high)
{
    if (low >= high)
        return ;
    int p = part(low, high);
    quicksort(low, p - 1);
    quicksort(p + 1, high);
}

int main(void)
{
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &numbers[i]);
    quicksort(0, N - 1);
    for (int i = 0; i < N; ++i)
        printf("%d\n", numbers[i]);
    return (0);
}