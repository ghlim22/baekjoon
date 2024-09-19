#include <cstdio>
#define MAX_SIZE (1000)
int input[MAX_SIZE];
int dp[MAX_SIZE];
int dp_reversed[MAX_SIZE];
int main(void)
{
    int size;
    int len = 1;

    std::scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        std::scanf("%d", &input[i]);
    }

    dp[0] = 1;
    for (int i = 1; i < size; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (input[j] < input[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    dp_reversed[size - 1] = 1;
    for (int i = size - 2; i >= 0; --i) {
        dp_reversed[i] = 1;
        for (int j = size - 1; j > i; --j) {
            if (input[j] < input[i] && dp_reversed[j] + 1 > dp_reversed[i]) {
                dp_reversed[i] = dp_reversed[j] + 1;
            }
        }
        if (dp[i] + dp_reversed[i] > len) {
            len = dp[i] + dp_reversed[i];
        }
    }

    if (len > 1) {
        --len;
    }
    std::printf("%d\n", len);

    return (0);
}