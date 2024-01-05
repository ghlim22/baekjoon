#include <iostream>

int main(void)
{
    bool flag = true;
    std::string s;

    std::cin >> s;
    for (int i = 0; i < s.length() / 2; ++i)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "1\n";
    else
        std::cout << "0\n";
    return 0;
}
