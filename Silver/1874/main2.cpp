#include <iostream>
#include <queue>
#include <stack>
int main(void)
{
    std::stack<int> stk;
    std::queue<char> q;
    int num;
    int n;
    int cur = 1;

    std::cin >> n;
    while (std::cin >> num) {
        // if (!stk.empty() && num > stk.top() && num < cur) {
        //     std::cout << "NO" << std::endl;
        //     exit(0);
        // }
        // while (stk.empty() || num > stk.top()) {
        //     stk.push(cur);
        //     q.push('+');
        //     cur++;
        // }
        // while (!stk.empty()) {
        //     q.push('-');
        //     if (stk.top() == num) {
        //         stk.pop();
        //         break;
        //     }
        //     stk.pop();
        // }

        while (num <= cur && (stk.empty() || num > stk.top())) {
            stk.push(cur);
            q.push('+');
            cur++;
        }
        if (stk.empty() || stk.top() < num) {
            std::cout << "NO" << std::endl;
            exit(0);
        }
        while (!stk.empty()) {
            q.push('-');
            if (stk.top() == num) {
                stk.pop();
                break;
            }
            stk.pop();
        }
    }

    while (!q.empty()) {
        std::cout << q.front() << std::endl;
        q.pop();
    }

    return 0;
}