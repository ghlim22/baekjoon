#include <cstdio>
#include <iostream>
#include <stack>
#include <utility>
#define MAX_SIZE (1000000)

typedef std::pair<int, int> pii_t;
int appr[MAX_SIZE + 1];
int ngf[MAX_SIZE + 1];
int input[MAX_SIZE + 1];

int main(void)
{
    int n;
    std::stack<int> stk;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> input[i];
        ++appr[input[i]];
    }

    for (int i = n; i >= 1; --i) {
        int cur = input[i];
        ngf[i] = -1;
        while (!stk.empty() && (stk.top() == cur || appr[stk.top()] <= appr[cur])) {
            stk.pop();
        }
        if (!stk.empty()) {
            ngf[i] = stk.top();
        }
        stk.push(cur);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << ngf[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}