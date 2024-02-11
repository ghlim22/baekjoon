#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
int main(void)
{
    while (true) {
        std::string str;
        std::getline(std::cin, str);
        if (std::cin.fail()) {
            break;
        }
        int lower = 0;
        int upper = 0;
        int num = 0;
        int ws = 0;
        size_t size = str.length();
        for (int i = 0; i < size; ++i) {
            if (std::islower(str[i])) {
                ++lower;
            } else if (std::isupper(str[i])) {
                ++upper;
            } else if (std::isdigit(str[i])) {
                ++num;
            } else {
                ++ws;
            }
        }
        std::cout << lower << ' ' << upper << ' ' << num << ' ' << ws
                  << std::endl;
    }
    return 0;
}