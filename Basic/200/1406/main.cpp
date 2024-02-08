#include <assert.h>
#include <deque>
#include <iostream>
#include <string>
int main(void)
{
    int n;
    int cur;
    std::string str;
    std::deque<char> left;
    std::deque<char> right;

    std::cin >> str;
    std::cin >> n;
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        left.push_back(str[i]);
    }
    while (n--) {
        char cmd, ch;

        std::cin >> cmd;
        switch (cmd) {
            case 'P':
                std::cin >> ch;
                left.push_back(ch);
                break;
            case 'L':
                if (left.size() > 0) {
                    right.push_back(left.back());
                    left.pop_back();
                }
                break;
            case 'D':
                if (right.size() > 0) {
                    left.push_back(right.back());
                    right.pop_back();
                }
                break;
            case 'B':
                if (left.size() > 0) {
                    left.pop_back();
                }
                break;
            default:
                assert(false);
                break;
        } 
    }
    while (!left.empty()) {
        std::cout << left.front();
        left.pop_front();
    }
    while (!right.empty()) {
        std::cout << right.back();
        right.pop_back();
    }
    std::cout << std::endl;
    return 0;
}