#include <iostream>
#include <queue>

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);
    
    int n;
    int k;
    std::queue<int> q;
    std::queue<int> output;

    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 0; i < k - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        output.push(q.front());
        q.pop();
    }
    
    std::cout << '<';
    while (!output.empty()) {
        std::cout << output.front();
        output.pop();
        if (!output.empty()) {
            std::cout << ", ";
        }
    }
    std::cout << '>';

    return 0;
}
