#include <algorithm>
#include <climits>
#include <iostream>
static int arr[1001];
static int sum[1001];
int main(void)
{
    int t;
    int n;
    int tmp;
    int ans;

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
            std::cin >> arr[i + 1];
        sum[0] = 0;
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + arr[i];
        ans = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
                ans = std::max(ans, sum[i] - sum[j]);
        }
        std::cout << ans << std::endl;   
    }
    return 0;
}
