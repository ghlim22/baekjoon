#include <iostream>
#include <stack>

int main(void)
{
    std::stack<int> left;
    std::stack<int> right;
    std::stack<int> output;
    int element;
    int n;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> element;
        left.push(element);
    }

    while (!left.empty()) {
        element = left.top();
        left.pop();
        while (!right.empty() && right.top() <= element) {
            right.pop();
        }
        if (right.empty()) {
            output.push(-1);
        } else {
            output.push(right.top());
        }
        right.push(element);
    }

    while (!output.empty()) {
        std::cout << output.top();
        output.pop();
        if (!output.empty()) {
            std::cout << ' ';
        }
    }

    return 0;
}
