#include <iostream>
using namespace std;

int main(void)
{
    int count, target, ans = 0;
    int cards[100] = {0};

    cin >> count >> target;

    for (int i = 0; i < count; ++i)
    {
        cin >> cards[i];
    }

    for (int i = 0; i < count - 2; ++i)
    {
        for (int j = i + 1; j < count - 1; ++j)
        {
            for (int k = j + 1; k < count; ++k)
            {
                int temp = cards[i] + cards[j] + cards[k];
                if (ans < temp && temp <= target)
                {
                    ans = temp;
                }
            }
        }
    }

    cout << ans;

    return 0;
}