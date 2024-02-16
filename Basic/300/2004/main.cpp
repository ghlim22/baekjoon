#include <iostream>
typedef unsigned long long ull_t;

// n!을 소인수 분해 했을 때, f를 몇 계승 가지고 있는지 센다.
// f는 소수.
ull_t countFactors(int n, int f)
{
    ull_t res = 0;
    for (ull_t i = f; i <= n; i *= f) {
        res += n / i;
    }
    return res;
}

int main(void)
{
    int n, m;

    std::cin >> n >> m;

    ull_t countTwo =
        countFactors(n, 2) - countFactors(n - m, 2) - countFactors(m, 2);

    ull_t countFive =
        countFactors(n, 5) - countFactors(n - m, 5) - countFactors(m, 5);

    if (countTwo < countFive) {
        std::cout << countTwo;
    } else {
        std::cout << countFive;
    }
    std::cout << std::endl;

    return 0;
}