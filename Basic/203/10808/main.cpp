#include <cstddef>
#include <iostream>
#include <string>
int cnt[26];
int main(void)
{
    std::string str;

    std::cin >> str;
    size_t size = str.size();
    for (int i = 0; i < size; ++i) {
        ++cnt[str[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        std::cout << cnt[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}