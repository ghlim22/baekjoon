#include <cassert>
#include <cctype>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <sys/types.h>
int input[26];
void func(std::stack<double> &stk, char op)
{
    double a = stk.top();
    stk.pop();
    double b = stk.top();
    stk.pop();
    switch (op) {
    case '+':
        stk.push(b + a);
        break;
    case '-':
        stk.push(b - a);
        break;
    case '*':
        stk.push(b * a);
        break;
    case '/':
        stk.push(b / a);
        break;
    default:
        assert(false);
        break;
    }
}
int main(void)
{
    std::stack<double> stk;
    std::string expr;
    int n;

    std::cin >> n;
    std::cin >> expr;
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }

    size_t len = expr.length();
    for (int i = 0; i < len; ++i) {
        if (isalpha(expr[i])) {
            stk.push(input[expr[i] - 'A']);
        } else {
            func(stk, expr[i]);
        }
    }
    std::cout << std::fixed << std::setprecision(2) << stk.top() << std::endl;

    return 0;
}