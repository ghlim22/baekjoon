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

    deque<int> dq;
    deque<int>::iterator iter;

    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "push_front")
        {
            int temp;
            cin >> temp;
            dq.push_front(temp);
            continue;
        }
        else if (str == "push_back")
        {
            int temp;
            cin >> temp;
            dq.push_back(temp);
            continue;
        }
        else if (str == "pop_front")
        {
            if (dq.empty())
            {
                output = -1;
            }
            else
            {
                output = dq.front();
                dq.pop_front();
            }
        }
        else if (str == "pop_back")
        {
            if (dq.empty())
            {
                output = -1;
            }
            else
            {
                output = dq.back();
                dq.pop_back();
            }
        }
        else if (str == "size")
        {
            output = dq.size();
        }
        else if (str == "empty")
        {
            if (dq.empty())
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
            if (dq.empty())
            {
                output = -1;
            }
            else
            {
                output = dq.front();
            }
        }
        else if (str == "back")
        {
            if (dq.empty())
            {
                output = -1;
            }
            else
            {
                output = dq.back();
            }
        }
        cout << output << "\n";
    }

    return 0;
}