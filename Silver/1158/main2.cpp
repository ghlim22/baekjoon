#include <iostream>
#include <queue>

int main(void)
{
    int n = 0;
    int k = 0;
    std::queue<int> q;
    std::queue<int> output;

    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    for (int i = 1; !q.empty(); ++i) {
        int m = q.front();
        q.pop();
        if (i == k) {
            i = 0;
            output.push(m);
        } else {
            q.push(m);
        }
    }

    std::cout << '<';
    while (!output.empty()) {
        std::cout << output.front();
        output.pop();
        if (!output.empty()) {
            std::cout << ", ";
        }
    }
    std::cout << ">" << std::endl;

    return 0;
}
