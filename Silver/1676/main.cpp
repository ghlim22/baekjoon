#include <cstring>
#include <iostream>
#define SIZE (500)
int cache[SIZE + 1];
int CountFactors(int n, int f)
{
    if (cache[n] != -1)
        return cache[n];
    if (n % f == 0)
        return CountFactors(n / f, f) + 1;
    return 0;
}
int CountTrailingZeros(int n)
{
    memset(cache, -1, sizeof(cache));

    int zeros = 0;
    for (int i = 5; i <= n; ++i)
        zeros += CountFactors(i, 5);
    return zeros;
}

int main()
{
    int n;

    std::cin >> n;
    std::cout << CountTrailingZeros(n);
    return 0;
}
