#include <stdio.h>
#include <stdlib.h>

static int N;
static int K;

static void my_mergesort(int *arr, int low, int high, int *tmp)
{
    if (low >= high)
        return ;
    int mid = (low + high) / 2;
    my_mergesort(arr, low, mid, tmp);
    my_mergesort(arr, mid + 1, high, tmp);
    if (K > N / (high - low + 1))
        return ;
    int i = low;
    int j = mid + 1;
    int k = low;
    for (;k <= high; ++k)
    {
        if (j > high)
            tmp[k] = arr[i++];
        else if (i > mid)
            tmp[k] = arr[j++];
        else if (arr[i] < arr[j])
            tmp[k] = arr[i++];
        else
            tmp[k] = arr[j++];
    }
    for (i = low; i <= high; ++i)
        arr[i] = tmp[i];
}
int main(void)
{
    scanf("%d", &N);
    int arr[N];
    int tmp[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &K);
    my_mergesort(arr, 0, N - 1, tmp);
    for (int i = 0; i < N; ++i)
    {
        printf("%d", arr[i]);
        if (i != N - 1)
            printf(" ");
    }
    return (0);
}