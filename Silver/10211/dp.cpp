#include <algorithm>
#include <climits>
#include <iostream>
static int arr[1001];
static int cache[1001];
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
        cache[1] = arr[1];
        for (int i = 2; i <= n; ++i)
            cache[i] = std::max(0, cache[i - 1]) + arr[i];
        ans = INT_MIN;
        for (int i = 1; i <= n; ++i)
            ans = std::max(ans, cache[i]);
        std::cout << ans << std::endl;
    }
    return 0;
}
