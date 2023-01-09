#include <stdio.h>

static void mergesort(int *arr, int low, int high, int *tmp)
{
    if (low >= high)
        return ;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid, tmp);
    mergesort(arr, mid + 1, high, tmp);
    int i = low;
    int j = mid + 1;
    int k = low;
    for (;k <= high; ++k)
    {
        if (j > high)
            tmp[k] = arr[i++];
        else if (i > mid)
            tmp[k] = arr[j++];
        else if (arr[i] <= arr[j])
            tmp[k] = arr[i++];
        else
            tmp[k] = arr[j++];
    }
    for (i = low; i <= high; ++i)
        arr[i] = tmp[i];
}

int main(void)
{
    int N;

    scanf("%d", &N);
    int arr[N], tmp[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    mergesort(arr, 0, N - 1, tmp);
    for (int i = 0; i < N; ++i)
        printf("%d\n", arr[i]);
    return (0);
}