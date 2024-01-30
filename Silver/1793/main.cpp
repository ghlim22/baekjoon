#include <cstring>
#include <iostream>
#define MAX_SIZE (250)
int dp[MAX_SIZE + 1][2000];

void add(int *res, const int *a, const int *b)
{
    int i;
    int s;
    int carry;

    res[0] = (a[0] + 2 * b[0]) % 10;
    carry = (a[0] + 2 * b[0]) / 10;
    for (i = 1; i < 100 && (a[i] != -1 || b[i] != -1); ++i) {
        int x = a[i] != -1 ? a[i] : 0;
        int y = b[i] != -1 ? b[i] * 2 : 0;
        s = (carry + x + y) % 10;
        carry = (carry + x + y) / 10;
        res[i] = s;
    }
    if (carry > 0) {
        res[i] = carry;
    }
}

void print(int *num)
{
    int i;

    for (i = 0; num[i] != -1; ++i) {
        ;
    }
    while (--i >= 0) {
        std::cout << num[i];
    }
    std::cout << std::endl;
}

int main(void)
{
    int n;

    std::memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 3;
    for (int i = 3; i <= MAX_SIZE; ++i) {
        add(dp[i], dp[i - 1], dp[i - 2]);
    }
    while (true) {
        std::cin >> n;
        if (std::cin.eof()) {
            break;
        }
        print(dp[n]);
    }

    return 0;
}