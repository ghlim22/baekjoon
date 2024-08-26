#include <iostream>
#include <stack>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(false);
    std::stack<int> stk;
    int n;

    std::cin >> n;
    while (n--) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "push") {
            int num;
            std::cin >> num;
            stk.push(num);
        } else if (cmd == "pop") {
            if (stk.empty()) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << stk.top() << std::endl;
                stk.pop();
            }
        } else if (cmd == "size") {
            std::cout << stk.size() << std::endl;
        } else if (cmd == "empty") {
            std::cout << (stk.empty() ? 1 : 0) << std::endl;
        } else {
            if (stk.empty()) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << stk.top() << std::endl;
            }
        }
    }

    return 0;
}
