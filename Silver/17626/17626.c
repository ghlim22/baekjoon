#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <memory.h>
#define MAX_SIZE (50000)
#define MIN(x, y) ((x) <= (y) ? (x) : (y))

static int dp[MAX_SIZE + 5];

int main(void)
{
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j <= n; ++j)
        {
            if (j * j > i)
                break;
            dp[i] = MIN(dp[i], dp[i - j * j] + 1);
        }
    }
    printf("%d\n", dp[n]);
    return (0);
}
