#include <iostream>
#define MAX_SIZE (30)

long dp[MAX_SIZE + 1];

int main(void)
{
    int n;

    std::cin >> n;
    if (n % 2 != 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = i - 4; j >= 0; --j) {
            dp[i] += dp[j] * 2;
        }
    }
    std::cout << dp[n] << std::endl;

    return 0;
}