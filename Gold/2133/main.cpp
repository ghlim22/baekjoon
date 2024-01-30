#include <iostream>
#define MAX_SIZE (30)

long dp[MAX_SIZE + 1];

int main(void)
{
    int n;

    std::cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    if (n % 2 == 1) {
        std::cout << 0 << std::endl;
    } else {
        for (int i = 4; i <= n; ++i) {
            dp[i] = dp[i - 2] * dp[2];
            for (int j = i - 4; j >= 0; j -= 2) {
                dp[i] += 2 * dp[j];
            }
        }
        std::cout << dp[n] << std::endl;
    }
}