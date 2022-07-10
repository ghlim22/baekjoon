#include <iostream>
using namespace std;

int GetDigitsSum(int n);

int main(void)
{
    int n, m;
    bool isExist = false;

    cin >> n;

    for (int i = 1; i < n; ++i)
    {
        if (i + GetDigitsSum(i) == n)
        {
            m = i;
            isExist = true;
            break;
        }
    }

    if (isExist)
    {
        cout << m << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }

    return 0;
}

int GetDigitsSum(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}