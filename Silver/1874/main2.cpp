#include <iostream>
#include <stack>
#include <vector>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(false);

    int n;
    int cur = 1;
    std::stack<int> stk;
    std::vector<char> output;

    std::cin >> n;
    while (n--) {
        int input;
        std::cin >> input;
        while (input >= cur) {
            stk.push(cur++);
            output.push_back('+');
        }
        if (!stk.empty() && stk.top() == input) {
            stk.pop();
            output.push_back('-');
        }
    }

    if (stk.empty()) {
        for (int i = 0; i < output.size(); ++i) {
            std::cout << output[i] << "\n";
        }
    } else {
        std::cout << "NO" << "\n";
    }

    return 0;
}
