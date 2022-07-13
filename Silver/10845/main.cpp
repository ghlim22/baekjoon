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
    queue<int> q;

    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "push")
        {
            int temp;
            cin >> temp;
            q.push(temp);
            continue;
        }
        else if (str == "pop")
        {
            if (q.empty())
            {
                output = -1;
            }
            else
            {
                output = q.front();
                q.pop();
            }
        }
        else if (str == "size")
        {
            output = q.size();
        }
        else if (str == "empty")
        {
            if (q.empty())
            {
                output = 1;
            }
            else
            {
                output = 0;
            }
        }
        else if (str == "front")
        {
            if (q.empty())
            {
                output = -1;
            }
            else
            {
                output = q.front();
            }
        }
        else if (str == "back")
        {
            if (q.empty())
            {
                output = -1;
            }
            else
            {
                output = q.back();
            }
        }
        cout << output << "\n";
    }

    return 0;
}