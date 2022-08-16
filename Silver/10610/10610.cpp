// https://www.acmicpc.net/problem/10610
// 10610번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

bool isMulitpleOf3(const string &str)
{
    int len = str.length();
    int sum = 0;

    for (int i = 0; i < len; ++i)
    {
        sum += str[i] - '0';
    }

    if (sum % 3 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(string &str)
{
    if (isMulitpleOf3(str))
    {
        sort(str.begin(), str.end(), greater<int>());
        if (str[str.length() - 1] == '0')
        {
            cout << str;
            return;
        }
    }
    cout << -1;
}

signed main()
{
    fastio;
    string input;

    cin >> input;

    solve(input);

    return 0;
}