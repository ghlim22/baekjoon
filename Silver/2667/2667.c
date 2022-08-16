#include <stdio.h>

#define MAX_SIZE (25)

int house[MAX_SIZE][MAX_SIZE];
int N;
int complex_num;
int complex_cnt[500];

int compare(const void *first, const void *second)
{
    int *p = (int *)first;
    int *q = (int *)second;
    if (*p > *q)
    {
        return 1;
    }
    else if (*p < *q)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void solve(int i, int j)
{
    house[i][j] = 0;            // 이번 집을 방문 처리해준다.
    complex_cnt[complex_num]++; // 집을 방문할 때마다 이번 단지의 집 수를 추가해준다.

    if (i > 0 && house[i - 1][j]) // up
    {
        solve(i - 1, j);
    }
    if (i < N - 1 && house[i + 1][j]) // down
    {
        solve(i + 1, j);
    }
    if (j > 0 && house[i][j - 1]) // left
    {
        solve(i, j - 1);
    }
    if (j < N - 1 && house[i][j + 1]) // right
    {
        solve(i, j + 1);
    }
}

int main(void)
{
    scanf("%1d", &N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%1d", &house[i][j]);
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (house[i][j]) // 집을 찾으면 solve를 실행해 연결된 집을 모두 방문처리한다.
            {
                solve(i, j);
                complex_num++; // 단지 번호 추가.
            }
        }
    }

    qsort(complex_cnt, complex_num, sizeof(int), compare);
    printf("%d\n", complex_num);
    for (int i = 0; i < complex_num; ++i)
    {
        printf("%d\n", complex_cnt[i]);
    }

    return 0;
}