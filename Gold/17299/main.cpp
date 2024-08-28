#include <iostream>
#include <stack>

#define SIZE (1000001)

int occur[SIZE];

int main(void)
{
    std::stack<int> left;
    std::stack<int> right;
    std::stack<int> output;
    int n;
    int elem;

    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    while (n--) {
        std::cin >> elem;
        occur[elem] += 1;
        left.push(elem);
    }

    while (!left.empty()) {
        elem = left.top();
        left.pop();
        while (!right.empty() && occur[elem] >= occur[right.top()]) {
            right.pop();
        }
        if (right.empty()) {
            output.push(-1);
        } else {
            output.push(right.top());
        }
        right.push(elem);
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
