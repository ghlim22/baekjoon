#include <climits>
#include <cstdio>
#define MAX_SIZE (100000)
int sum[MAX_SIZE + 1];

int main(void)
{
    long max = LONG_MIN;
    int num;
    int n;
    int k;

    std::scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        std::scanf("%d", &num);
        sum[i] = sum[i - 1] + num;
        if (i >= k && max < sum[i] - sum[i - k]) {
            max = sum[i] - sum[i - k];
        }
    }
    std::printf("%ld\n", max);

    return 0;
}