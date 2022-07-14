// https://www.acmicpc.net/problem/5464
// 5464번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int parking[101];
int prices[101];
int weights[2001];
queue<int> waiting;

void solve()
{
}

signed main()
{
    fastio;
    solve();

    int n, m, cnt = 0, sum = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> prices[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < 2 * m; ++i)
    {
        int car;
        cin >> car;

        if (car < 0)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (-car == parking[j])
                {
                    parking[j] = 0;
                    cnt--;
                    break;
                }
            }
        }
        else
        {
            if (cnt < n)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (parking[j] == 0)
                    {
                        parking[j] = car;
                        sum += prices[j] * weights[car];
                        cnt++;
                        break;
                    }
                }
            }
            else
            {
                waiting.push(car);
            }
        }

        while (cnt < n && !waiting.empty())
        {
            int temp = waiting.front();
            for (int j = 1; j <= n; ++j)
            {
                if (parking[j] == 0)
                {
                    parking[j] = temp;
                    waiting.pop();
                    sum += prices[j] * weights[temp];
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << sum;

    return 0;
}