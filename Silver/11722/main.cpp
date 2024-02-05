#include <cstdio>
#define MAX_SIZE (1000)
int dp[MAX_SIZE];
int input[MAX_SIZE];
int main(void)
{
    int len = 1;
    int size;

    std::scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        std::scanf("%d", &input[i]);
    }
    for (int i = 0; i < size; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (input[i] < input[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                len = len < dp[i] ? dp[i] : len;
            }
        }
    }
    std::printf("%d\n", len);
    return 0;
}