#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

/* self := operators.top() */
bool has_precedence(char self, char other)
{
    if (self == '*' || self == '/') {
        return true;
    } else {
        return (other == '+' || other == '-');
    }
}

int main(void)
{
    std::string line;
    std::vector<char> postfix;
    std::stack<char> operators;

    std::getline(std::cin, line);

    for (int i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (isalpha(c)) {
            postfix.push_back(c);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && operators.top() != '(' &&
                   has_precedence(operators.top(), c)) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    for (int i = 0; i < postfix.size(); ++i) {
        std::cout << postfix[i];
    }

    return 0;
}
