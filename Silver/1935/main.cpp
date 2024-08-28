#include <cassert>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>

int operands[26];

int main(void)
{
    std::stack<double> stk;
    std::string line;
    int n;
    int operand;

    std::cin >> n;
    std::cin.ignore();
    std::getline(std::cin, line);
    for (int i = 0; i < n; ++i) {
        std::cin >> operand;
        operands[i] = operand;
    }

    for (int i = 0; i < line.size(); ++i) {
        if (isalpha(line[i])) {
            stk.push(static_cast<double>(operands[line[i] - 'A']));
        } else {
            double res;
            double right = stk.top();
            stk.pop();
            double left = stk.top();
            stk.pop();

            switch (line[i]) {
            case '+':
                res = left + right;
                break;

            case '-':
                res = left - right;
                break;

            case '*':
                res = left * right;
                break;

            case '/':
                res = left / right;
                break;

            default:
                assert(false);
            }

            stk.push(res);
        }
    }

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << stk.top();

    return 0;
}
