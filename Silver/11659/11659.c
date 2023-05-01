#include <stdio.h>
#define MAX_SIZE (100000)

int main(void)
{
    int arr[MAX_SIZE + 1] = {
        0,
    };
    int N, M, i, j;

    scanf("%d %d", &N, &M);
    for (int k = 1; k <= N; ++k)
    {
        int input;
        scanf("%d", &input);
        arr[k] = arr[k - 1] + input;
    }

    while (M--)
    {
        scanf("%d %d", &i, &j);
        printf("%d\n", arr[j] - arr[i - 1]);
    }

    return (0);
}