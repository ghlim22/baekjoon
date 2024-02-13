#include <iostream>
int main(void)
{
    long res = 1;
    int n;

    std::cin >> n;
    while (n > 0) {
        res *= n;
        --n;
    }
    std::cout << res << std::endl;
    return 0;
}