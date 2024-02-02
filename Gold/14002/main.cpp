#include <algorithm>
#include <cstdio>
#include <stack>
#define MAX_SIZE (1000)

int num[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];
int prev[MAX_SIZE + 1];
int size;

int lowerbound(int key, int len)
{
    int left = 0;
    int right = len;

    while (left < right) {
    }

    return (right);
}

int main(void)
{
    int max_len = 1;
    int last_idx = 1;

    std::scanf("%d", &size);
    for (int i = 1; i <= size; ++i) {
        std::scanf("%d", &num[i]);
    }

    std::fill(dp, dp + MAX_SIZE + 1, 1);
    for (int i = 1; i < size; ++i) {
        for (int j = i + 1; j <= size; ++j) {
            if (num[i] < num[j] && dp[i] + 1 > dp[j]) {
                dp[j] = dp[i] + 1;
                prev[j] = i;
                if (max_len < dp[j]) {
                    max_len = dp[j];
                    last_idx = j;
                }
            }
        }        
    }

    std::printf("%d\n", max_len);
    std::stack<int> s;
    s.push(num[last_idx]);
    for (int i = last_idx; prev[i] != 0; i = prev[i]) {
        s.push(num[prev[i]]);
    }
    while (!s.empty()) {
        std::printf("%d ", s.top());
        s.pop();
    }
    std::printf("\n");

    return (0);    
}
