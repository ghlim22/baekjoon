#include <iostream>

int CountTrailingZeros(int n)
{
    int zeros = 0;

    for (int i = 5; i <= n; i *= 5)
        zeros += n / i;

    return zeros;
}

int main()
{
    int n;

    std::cin >> n;
    std::cout << CountTrailingZeros(n);

    return 0;
}
