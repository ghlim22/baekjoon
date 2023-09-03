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
        for (int i = 1; i <= n; ++i)
            std::cin >> arr[i];
        cache[1] = arr[1];
        for (int i = 2; i <= n; ++i)
            cache[i] = std::max(0, cache[i - 1]) + arr[i];
        int max = cache[1];
        for (int i = 2; i <= n; ++i)
            max = std::max(max, cache[i]);
        std::cout << max << std::endl;
    }
    return 0;
}
