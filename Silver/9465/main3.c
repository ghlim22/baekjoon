#include <stdio.h>

#define MAX_SIZE (100000)
#define max(a, b) ((a) >= (b) ? (a) : (b))

int dp[2][MAX_SIZE];
int num[2][MAX_SIZE];

void input(int n);
void solve(int n);

int main(void)
{
    int n;
    int t;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
		input(n);
		solve(n);
    }
    return 0;
}

void input(int n)
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &num[i][j]);
        }
    }
}

void solve(int n)
{
    dp[0][0] = num[0][0];
    dp[1][0] = num[1][0];
    dp[0][1] = dp[1][0] + num[0][1];
    dp[1][1] = dp[0][0] + num[1][1];

    for (int c = 2; c < n; ++c) {
        for (int r = 0; r < 2; ++r) {
            dp[r][c] = num[r][c] + max(dp[r ^ 1][c - 1], max(dp[0][c - 2], dp[1][c - 2]));
        }
    }

	printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));
}