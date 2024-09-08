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

    int count_two = CountFactors(n, 2);
    int count_five = CountFactors(n, 5);

    count_two -= CountFactors(n - m, 2);
    count_five -= CountFactors(n - m, 5);

    count_two -= CountFactors(m, 2);
    count_five -= CountFactors(m, 5);

    std::cout << std::min(count_two, count_five);
    
    return 0;
}
