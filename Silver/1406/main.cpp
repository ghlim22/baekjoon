#include <cassert>
#include <deque>
#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int m;
    std::string init;
    std::deque<char> left;
    std::deque<char> right;

    std::cin >> init;
    for (int i = 0; i < init.size(); ++i) {
        left.push_back(init[i]);
    }

    std::cin >> m;
    while (m--) {
        char cmd;
        std::cin >> cmd;
        switch (cmd) {
        case 'L':
            if (!left.empty()) {
                right.push_front(left.back());
                left.pop_back();
            }
            break;

        case 'D':
            if (!right.empty()) {
                left.push_back(right.front());
                right.pop_front();
            }
            break;

        case 'B':
            if (!left.empty()) {
                left.pop_back();
            }
            break;

        case 'P':
            char c;
            std::cin >> c;
            left.push_back(c);
            break;

        default:
            assert(false);
        }
    }

    while (!left.empty()) {
        std::cout << left.front();
        left.pop_front();
    }
    while (!right.empty()) {
        std::cout << right.front();
        right.pop_front();
    }

    return 0;
}
