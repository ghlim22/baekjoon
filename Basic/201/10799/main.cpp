#include <iostream>
#include <string>
int main(void)
{
    int sticks = 0;
    int pieces = 0;
    std::string str;

    std::cin >> str;
    ssize_t len = str.length();
    for (int i = 0; i < len; ++i) {
        if (str[i] == '(' && str[i + 1] == ')') {
            pieces += sticks;
            ++i;
        } else if (str[i] == '(') {
            ++sticks;
        } else if (str[i] == ')') {
            ++pieces;
            --sticks;
        }
    }
    std::cout << pieces << std::endl;

    return 0;
}