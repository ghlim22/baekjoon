#include <stdio.h>
#include <string.h>

int get_distance(int a, int b, char (*arr)[5]);
int get_answer(char (*arr)[5], int n);

int main(void)
{
    int t;
    int n;
    char arr[32][5];

    scanf("%d", &t);
    while (t--)
    {
        memset(arr, 0, sizeof(char) * 32 * 5);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", arr[i % 32]);
        }
        if (n > 32) /* There's 16 kinds of MBTI. So there must be a MBTI type
        which entered more than or equal to 3 times.*/
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", get_answer(arr, n));
    }

    return 0;
}

int get_distance(int a, int b, char (*arr)[5])
{
    int dist = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (arr[a][i] != arr[b][i])
        {
            ++dist;
        }
    }

    return dist;
}

int get_answer(char (*arr)[5], int n)
{
    int ans = 100;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (i == j || j == k || k == i)
                {
                    continue;
                }
                int tmp = get_distance(i, j, arr) + get_distance(j, k, arr) 
                + get_distance(k, i, arr);
                ans = ans <= tmp ? ans : tmp;
            }
        }
    }
    
    return ans;
}
