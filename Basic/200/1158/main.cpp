#include <deque>
#include <iostream>

int main(void)
{
    int n;
    int k;
    std::deque<int> dq;

    std::cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        dq.push_back(i);
    }
    std::cout << "<";
    for (int i = 1; !dq.empty(); ++i) {
        if (i % k == 0) {
            std::cout << dq.front();
            if (dq.size() > 1) {
                std::cout << ", ";
            }
        } else {
            dq.push_back(dq.front());
        }
        dq.pop_front();
    }
    std::cout << ">\n";
    return 0;
}