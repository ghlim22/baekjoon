#include <stdio.h>

static int gcd(int a, int b)
{
    int r;

    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return (a);
}

int main(void)
{
    int test_cnt;
    int x;
    int y;
    int M;
    int N;

    scanf("%d", &test_cnt);
    while (test_cnt--)
    {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        int limit = M * N / gcd(M, N);
        for (int year = 1; year <= limit; ++year)
        {
                }
    }
}