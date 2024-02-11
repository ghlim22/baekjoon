#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
int main(void)
{
    std::vector<std::string> v;
    std::string input;

    std::cin >> input;
    size_t size = input.size();
    for (int i = 0; i < size; ++i) {
        v.push_back(input.substr(i));
    }
    std::sort(v.begin(), v.end());
    for (auto i : v) {
        std::cout << i << std::endl;
    }
    return 0;
}