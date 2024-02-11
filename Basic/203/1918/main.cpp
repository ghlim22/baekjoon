#include <cctype>
#include <cstddef>
#include <iostream>
#include <stack>
#include <string>

int precedence(char c) {
    switch (c) {
        case '*':
        case '/':
            return 1;
        case '+':
        case '-':
            return 2;
    }
    return 3;
}

bool should_insert(std::stack<char> &stk, char cur) {
    return (!stk.empty() && precedence(stk.top()) <= precedence(cur));
}

int main(void)
{
    std::string res = "";
    std::string input;
    std::stack<char> op;

    std::cin >> input;
    size_t size = input.size();
    for (int i = 0 ; i < size; ++i) {
        if (std::isalpha(input[i])) {
            res += input[i];
        } else if (input[i] == ')') {
            while (!op.empty() && op.top() != '(') {
                res += op.top();
                op.pop();
            }
            if (!op.empty()) {
                op.pop();
            }
        } else if (input[i] == '(') {
            op.push('(');
        } else {
            while (should_insert(op, input[i])) {
                res += op.top();
                op.pop();
            }
            op.push(input[i]);
        }
    }
    while (!op.empty()) {
        res += op.top();
        op.pop();
    }
    std::cout << res << std::endl;
    return 0;
}