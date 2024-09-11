#include <iostream>
#include <stack>
int main(void)
{
    int n, b;
    char digits[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::stack<char> stk;

    std::cin >> n >> b;
    do {
        stk.push(digits[n % b]);
        n /= b;
    } while (n > 0);
    while (!stk.empty()) {
        std::cout << stk.top();
        stk.pop();
    }
    std::cout << std::endl;
    return 0;
}