#include <iostream>
using namespace std;

int main(void)
{
    int count, temp, max = -1000000, min = 1000000;

    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        cin >> temp;

        if (temp > max)
        {
            max = temp;
        }

        if (temp < min)
        {
            min = temp;
        }
    }

    cout << min << ' ' << max << '\n';

    return 0;
}