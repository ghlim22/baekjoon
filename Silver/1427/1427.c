#include <stdio.h>

int main(void)
{
    int arr[10] = {0, };
    int n;

    scanf("%d", &n);
    do
    {
        arr[n % 10]++;
        n /= 10;
    } while (n);
    for (int i = 9; i >= 0; --i)
    {
        for (int j = 0; j < arr[i]; ++j)
            printf("%d", i);
    }
    return (0);
}