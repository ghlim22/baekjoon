#include <stdio.h>
#define MAX_CNT 50
#define MAX_VOL 1000
#define CHECK_BOUND(x, y, z) ((x) <= (y) && (y) <= (z))

static int vol[MAX_CNT + 1];
static int dp[MAX_CNT + 1][MAX_VOL + 1];

int main(void)
{
    int ans = -1;
    int n;
    int s;
    int m;

    scanf("%d %d %d", &n, &s, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &vol[i]);
    dp[0][s] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (dp[i - 1][j])
            {
                if (CHECK_BOUND(0, j - vol[i], m))
                    dp[i][j - vol[i]] = 1;
                if (CHECK_BOUND(0, j + vol[i], m))
                    dp[i][j + vol[i]] = 1;
            }
        }
    }
    for (int i = m; i >= 0; --i)
    {
        if (dp[n][i])
        {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}

