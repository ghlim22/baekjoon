#include <stdio.h>
#include <limits.h>
#define MAX_SIZE (100)
#define INF (100000)
#define MIN(x, y) ((x) < (y) ? (x) : (y))

static void input(void);
static void floyd(void);
static void print(void);

int N;
int arr[MAX_SIZE][MAX_SIZE];

int main(void)
{
    input();
    floyd();
    print();

    return (0);
}

static void input(void)
{
    int i, j;

    scanf("%d", &N);
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            scanf("%d", &arr[i][j]);
            if (!arr[i][j])
                arr[i][j] = INF;
        }
    }
}

static void floyd(void)
{
    int i, j, k;

    for (k = 0; k < N; ++k)
    {
        for (i = 0; i < N; ++i)
        {
            for (j = 0; j < N; ++j)
            {
                arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

static void print(void)
{
    int i, j;

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            if (arr[i][j] == INF)
                printf("0");
            else
                printf("1");

            if (j < N - 1)
                printf(" ");
        }
        if (i != N - 1)
            printf("\n");
    }
}