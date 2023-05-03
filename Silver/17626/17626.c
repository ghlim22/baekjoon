#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <memory.h>
#define MAX_SIZE (50500)
#define MIN(x, y) ((x) <= (y) ? (x) : (y))

static unsigned int dp[MAX_SIZE + 1];

int main(void)
{
    int n, limit, min_cost;

    scanf("%d", &n);

    memset(dp, 0xFF, sizeof(dp));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    limit = (int)sqrt(n) + 1;

    for (int i = 2; i <= limit; ++i)
        dp[i * i] = 1;
    if (dp[n] == 1)
    {
        printf("%d\n", dp[n]);
        return (0);
    }

    for (int i = 3; i <= n; ++i)
    {
        if (dp[i] == 1)
            continue;
        dp[i] = dp[i - 1] + 1;
        limit = i / 2;
        for (int j = 2; j <= limit; ++j)
        {
            dp[i] = MIN(dp[i], dp[i - j] + dp[j]);
        }
    }

    printf("%d\n", dp[n]);
    return (0);
}
