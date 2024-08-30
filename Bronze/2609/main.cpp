#include <iostream>
#include <utility>

int FindGCD(int a, int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(void)
{
    int a;
    int b;

    std::cin >> a >> b;

    if (a < b) {
        std::swap(a, b);
    }

    int gcd = FindGCD(a, b);
    int lcm = a / gcd * b;

    std::cout << gcd << '\n' << lcm;

    return 0;
}