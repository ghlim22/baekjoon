
#include <iostream>
#include <ostream>
#define MAX_SIZE (1000000)
#define MODULUS (1000000007)
#define NUM_OF_CASES (0)
#define TOTAL_UP_TO_THE_THIRD_PREDECESSOR (1)
long dp[MAX_SIZE + 1][2];
int main(void)
{
    int n;

    std::cin >> n;
    /* 각 n의 경우에, 2개 씩의 특이 케이스가 존재한다. (n = 2 제외) */
    /*
        dp[i][0]: num of cases, where n = i.
        dp[i][1]: total up to the third predecessor, where n = i. sum(dp[0][0],
       dp[i - 3][0])
    */

    dp[0][0] =
        1; /* dp[0][0] = 1 로 해두어, +2를 (+ 2 * dp[i][1]) 안에 넣어 두었다. */
    dp[1][0] = 2;
    dp[2][0] = 7; /* n = 2 일 때, 3개의 특이 케이스가 존재한다. */

    /*
    dp[1][0] = 2;
    dp[2][0] = 7;
    dp[n][0] = dp[n - 1][0] * 2 + dp[n - 2][0] * 3 + sum(dp[n - 3][0], dp[1][0])
    + 2
    앞선 계산에서 중복되는 것을 뒤에서 제외하고, 중복되지 않는 경우만
    반영하는 것이 핵심이다.
    */

    for (int i = 3; i <= n; ++i) {
        dp[i][TOTAL_UP_TO_THE_THIRD_PREDECESSOR] =
            dp[i - 3][NUM_OF_CASES] +
            dp[i - 1][TOTAL_UP_TO_THE_THIRD_PREDECESSOR];
        dp[i][NUM_OF_CASES] = dp[i - 1][NUM_OF_CASES] * 2 +
                              dp[i - 2][NUM_OF_CASES] * 3 +
                              dp[i][TOTAL_UP_TO_THE_THIRD_PREDECESSOR] * 2;
        dp[i][NUM_OF_CASES] %= MODULUS;
        dp[i][TOTAL_UP_TO_THE_THIRD_PREDECESSOR] %= MODULUS;
    }
    std::cout << dp[n][NUM_OF_CASES] % MODULUS << std::endl;

    return 0;
}