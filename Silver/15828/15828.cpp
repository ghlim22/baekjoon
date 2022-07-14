// https://www.acmicpc.net/problem/15828
// 15828번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

queue<int> que;
bool duplicated[1000001];

void solve()
{
}

signed main()
{
    fastio;
    solve();

    int temp, size, cnt = 0;
    cin >> size;

    while (1)
    {
        cin >> temp;
        if (temp == -1)
        {
            break;
        }
        else if (temp == 0)
        { 
            que.pop();
            cnt--;
        }
        else
        {
            if (cnt < size)
            {
                que.push(temp);
                cnt++;
            }
        }
    }

    if (que.empty())
    {
        cout << "empty";
    }
    else
    {
        while (!que.empty())
        {
            cout << que.front() << "\n";
            que.pop();
        }
    }

    return 0;
}