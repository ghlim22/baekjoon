#include <algorithm>
#include <iostream>
int main(void)
{
    int count_two = 0;
    int count_five = 0;
    int n;

    std::cin >> n;
    for (int i = 2; i <= n; ++i) {
        int num = i;
        while (num >= 2 && num % 2 == 0) {
            num /= 2;
            ++count_two;
        }
        while (num >= 5 && num % 5 == 0) {
            num /= 5;
            ++count_five;
        }
    }
    if (count_five == 0 && count_two == 0) {
        std::cout << "0";
    } else if (count_two > count_five) {
        std::cout << count_five;
    } else {
        std::cout << count_two;
    }
    std::cout << std::endl;
    return 0;
}