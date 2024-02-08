#include <iostream>
#include <stack>
#include <string>
int main(void)
{
    int tc;
    std::string str;

    std::cin >> tc;
    while (tc--) {
        std::stack<char> s;
        bool flag = false;
        std::cin >> str;
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            if (str[i] == '(') {
                s.push(1);
            } else if (s.empty()) {
                flag = true;
                break;
            } else {
                s.pop();
            }
        }
        if (!s.empty() || flag) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}