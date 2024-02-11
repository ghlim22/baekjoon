#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
int cnt[26];
int main(void)
{
    std::string str;

    std::cin >> str;
    std::memset(cnt, -1, sizeof(cnt));
    size_t size = str.size();
    for (int i = 0; i < size; ++i) {
        int idx = str[i] - 'a';
        if (cnt[idx] == -1) {
            cnt[idx] = i;
        }
    }
    for (int i = 0; i < 26; ++i) {
        std::cout << cnt[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}