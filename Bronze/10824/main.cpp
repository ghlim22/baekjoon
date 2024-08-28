#include <iostream>
#include <vector>

void solve(const std::vector<int> &lhs, const std::vector<int> &rhs);

long concat(long left, long right)
{
    long tmp = right;
    long len = 0;

    do {
        tmp /= 10;
        ++len;
    } while (tmp > 0);

    while (len--) {
        left *= 10;
    }

    return left + right;
}

int main(void)
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << concat(a, b) + concat(c, d);
    return 0;
}
