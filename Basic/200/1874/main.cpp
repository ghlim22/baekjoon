#include <iostream>
#include <queue>
#include <stack>
int main(void)
{
    int n;
    int num;
    int cur = 1;
    std::stack<int> s;
    std::queue<char> q;

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> num;
        while (cur <= num) {
            s.push(cur);
            q.push('+');
            ++cur;
        }
        if (!s.empty() && s.top() == num) {
            s.pop();
            q.push('-');
        }
    }
    if (s.empty()) {
        while (!q.empty()) {
            std::cout << q.front() << "\n";
            q.pop();
        }
    } else {
        std::cout << "NO\n";
    }
    return 0;
}