#include <iostream>
int get_gcd(int a, int b)
{
    if (a < b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    if (b == 0) {
        return a;
    }
    return get_gcd(b, a % b);
}
int main(void)
{
    int a, b;
    int gcd;
    int lcm;
    std::cin >> a >> b;
    gcd = get_gcd(a, b);
    lcm = a / gcd * b;
    std::cout << gcd << std::endl;
    std::cout << lcm << std::endl;
    return 0;
}