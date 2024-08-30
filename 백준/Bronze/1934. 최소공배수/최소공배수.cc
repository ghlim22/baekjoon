#include <cstdio>

int get_gcd(int a, int b)
{
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) {
        return a;
    }
    return get_gcd(b, a % b);
}

int main(void)
{
    int t, a, b;

    std::scanf("%d", &t);
    while (t--) {
        std::scanf("%d %d", &a, &b);
        int gcd = get_gcd(a, b);
        int lcm = a * b / gcd;
        std::printf("%d\n", lcm);
    }
    return 0;
}