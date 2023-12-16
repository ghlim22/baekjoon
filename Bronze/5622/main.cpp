#include <iostream>
#include <string>

int main(void)
{
    int rot_sum = 0;
    std::string input;

    std::cin >> input;
    size_t len = input.length();
    for (int i = 0; i < len; ++i)
    {
        if (input[i] < 'D')
            rot_sum += 3;
        else if (input[i] < 'G')
            rot_sum += 4;
        else if (input[i] < 'J')
            rot_sum += 5;
        else if (input[i] < 'M')
            rot_sum += 6;
        else if (input[i] < 'P')
            rot_sum += 7;
        else if (input[i] < 'T')
            rot_sum += 8;
        else if (input[i] < 'W')
            rot_sum += 9;
        else
            rot_sum += 10;
    }

    std::cout << rot_sum << std::endl;

    return 0;
}