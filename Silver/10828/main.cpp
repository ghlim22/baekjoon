// https://www.acmicpc.net/problem/main
// main번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve()
{
}

signed main()
{
    fastio;

    int n, output;
    string str;
    stack<int> stk;

    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "push")
        {
            int temp;
            cin >> temp;
            stk.push(temp);
            continue;
        }
        else if (str == "pop")
        {
            if (stk.empty())
            {
                output = -1;
            }
            else
            {
                output = stk.top();
                stk.pop();
            }
        }
        else if (str == "size")
        {
            output = stk.size();
        }
        else if (str == "empty")
        {
            if (stk.empty())
            {
                output = 1;
            }
            else
            {
                output = 0;
            }
        }
        else if (str == "top")
        {
            if (stk.empty())
            {
                output = -1;
            }
            else
            {
                output = stk.top();
            }
        }
        cout << output << "\n";
    }

    return 0;
}