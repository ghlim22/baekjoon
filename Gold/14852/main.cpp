#include <iostream>
#define MOD_NUM (1000000007)
#define MAX_SIZE (1000000)
long dp[MAX_SIZE + 1][2];

int main(void)
{
    int n;

    std::cin >> n;
    dp[0][0] = 1;
    dp[1][0] = 2; // dp[i][0]: the number of ways where n = i.
    dp[2][0] = 7;
    for (int i = 3; i <= n; ++i) {
        dp[i][1] = dp[i - 3][0] + dp[i - 1][1]; // dp[i][1]: sum(dp[0][0] to dp[i - 3][0])
        dp[i][0] = dp[i - 1][0] * 2 + dp[i - 2][0] * 3 + dp[i][1] * 2;
        dp[i][1] %= MOD_NUM;
        dp[i][0] %= MOD_NUM;
    }
    std::cout << dp[n][0] % MOD_NUM << std::endl;

    return 0;
}