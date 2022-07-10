// https://www.acmicpc.net/problem/1431
// 1431번

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

// static const int INF = 0x3f3f3f3f;

int GetSumOfDigits(const string &s1)
{
    int sum = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        if (s1[i] >= '0' && s1[i] <= '9')
        {
            sum += (int)(s1[i] - '0');
        }
    }

    return sum;
}

bool compare_serial(const string &s1, const string &s2)
{
    if (s1.length() != s2.length())
    {
        return s1.length() < s2.length();
    }

    if (GetSumOfDigits(s1) != GetSumOfDigits(s2))
    {
        return GetSumOfDigits(s1) < GetSumOfDigits(s2);
    }

    return s1 < s2;
}

void solve(int count)
{
    string arr[count];

    for (int i = 0; i < count; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + count, compare_serial);

    for (int i = 0; i < count; ++i)
    {
        cout << arr[i] << '\n';
    }
}

signed main()
{
    int count;
    fastio;
    cin >> count;
    solve(count);

    return 0;
}