#include <stdio.h>
#include <vector>
using namespace std;

int main(void)
{
    int input, len = 0;
    int nums[5] = {-1, -1, -1, -1, -1};
    vector<int> v(5);
    fill(v.begin(), v.end(), -1);
    bool isPalindrome = true;

    while (true)
    {
        scanf("%d", &input);
        if (input == 0)
        {
            return 0;
        }

        for (int i = 0; input != 0; ++i)
        {
            v[i] = input % 10;
            input /= 10;
        }

        for (int i = 0; i < 5; ++i)
        {
            if (v[i] != -1)
            {
                len++;
            }
        }

        for (int i = 0; i <= len / 2; ++i)
        {
            if (i == len / 2)
            {
                break;
            }

            if (v[i] != v[len - 1 - i])
            {
                isPalindrome = false;
                break;
            }
        }

        if (!isPalindrome)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }

        len = 0;
        isPalindrome = true;
        fill(v.begin(), v.end(), -1);
    }
}