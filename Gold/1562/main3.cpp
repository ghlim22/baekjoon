#include <cstring>
#include <iostream>
#define MODULUS (1000000000)

long dp[10][101][1 << 2];
bool vis[10][101][1 << 2];
int n;

long solve(int digit, int len, int mask)
{
    long &ret = dp[digit][len][mask];
    if (ret > 0) {
        return 0;
    }
    if (len == n) {
        return mask == 3 ? 1 : 0;
    }
    if (digit < 9) {
        ret += solve(digit + 1, len + 1, mask | (digit + 1 == 9 ? 2 : 0));
        ret %= MODULUS;
    }
    if (digit > 0) {
        ret += solve(digit - 1, len + 1, mask | (digit - 1 == 0 ? 1 : 0));
        ret %= MODULUS;
    }
    return ret;
}

int main(void)
{
    long res = 0;

    std::cin >> n;
    for (int i = 1; i <= 9; ++i) {
        res += solve(i, 1, ((i == 9) ? 2 : 0));
        res %= MODULUS;
    }
    std::cout << res % MODULUS << std::endl;

    // for (n = 10; n <= 40; ++n) {
    //     std::memset(dp, 0, sizeof(dp));
    //     for (int i = 1; i <= 9; ++i) {
    //         res += solve(i, 1, ((i == 9) ? 2 : 0));
    //         res %= MODULUS;
    //     }
    //     std::cout << res % MODULUS << std::endl;
    // }

    return 0;
}