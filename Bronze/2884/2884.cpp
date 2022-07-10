#include <iostream>
using namespace std;

int main(void)
{
    int hour, min, total_min;

    cin >> hour >> min;

    min -= 45;
    if (min < 0)
    {
        min += 60;
        hour--;
        if (hour < 0)
        {
            hour = 23;
        }
    }

    cout << hour << " " << min << '\n';

    return 0;
}