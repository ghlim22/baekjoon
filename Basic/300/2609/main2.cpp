#include <algorithm>
#include <cstdlib>
#include <iostream>

int CountFactors(int n, int f)
{
    int count = 0;
    for (long i = f; i <= n; i *= f)
        count += n / i;
    
    return count;
}

int main()
{
    int n;
    int m;

    std::cin >> n >> m;

    int two = CountFactors(n, 2);
    int five = CountFactors(n, 5);

    two -= CountFactors(n - m, 2);
    five -= CountFactors(n - m, 5);

    two -= CountFactors(m, 2);
    five -= CountFactors(m, 5);

    std::cout << std::min(two, five);
    
    return 0;
}
