#include <algorithm>
#include <climits>
#include <iostream>
static int arr[1001];
static int t;
static int n;
static int tmp;
static int ans;
static int brute_force(int index, int sum);
int main(void)
{
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
            std::cin >> arr[i + 1];       
		std::cout << brute_force(1, 0) << std::endl;
    }
    return 0;
}
static int max(int a, int b, int c, int d)
{
    int max = std::max(a , b);
    max = std::max(max, c);
    return std::max(max, d);
}
static int brute_force(int index, int sum)
{
    if (index == n + 1)
        return sum;
	return max(arr[index], sum + arr[index], \
			brute_force(index + 1, sum + arr[index]), brute_force(index + 1, arr[index]));
}
