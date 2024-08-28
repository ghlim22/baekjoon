#include <cstddef>
#include <iostream>
#include <stack>

int main(void)
{
    int total = 0;
    int sticks = 0;
    std::string line;

    std::cin >> line;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == '(') {
            if (line[i + 1] == ')') {
                ++i;
                total += sticks;
            } else {
                ++sticks;
            }
        } else {
            ++total;
            --sticks;
        }
    }

    std::cout << total;

    return 0;
}
