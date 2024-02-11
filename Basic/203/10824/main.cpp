#include <iostream>
long concat(long x, long y)
{
    int len = 0;
    long y_tmp = y;
    while (y_tmp >= 1) {
        y_tmp /= 10;
        ++len;
    }
    while (len--) {
        x *= 10;
    }
    return x + y;
}
int main(void)
{
    long a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cout << concat(a, b) + concat(c, d) << std::endl;
    return 0;
}