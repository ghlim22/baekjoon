#include <cctype>
#include <cstddef>
#include <cstring>
#include <iostream>
int main(void)
{
    char str[101];
    std::cin.getline(str, 101);
    size_t len = std::strlen(str);
    for (int i = 0; i < len; ++i) {
        if (std::isalpha(str[i])) {
            int tmp = str[i] + 13;
            if (std::islower(str[i]) && tmp > 'z') {
                str[i] = tmp - 'z' + 'a' - 1;
            } else if (std::isupper(str[i]) && tmp > 'Z') {
                str[i] = tmp - 'Z' + 'A' - 1;
            } else {
                str[i] = tmp;
            }
        }
    }
    std::cout << str << std::endl;

    return 0;
}