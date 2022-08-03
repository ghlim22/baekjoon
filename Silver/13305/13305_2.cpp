// https://www.acmicpc.net/problem/13305_2
// 13305_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N;
ll dist[100000];
ll price[100000];
ll sum = 0;

void solve()
{
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> dist[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> price[i];
    }

    ll min_price = price[0];

    for (int i = 0; i < N - 1; ++i)
    {
        if (min_price > price[i])
        {
            min_price = price[i];
        }
        sum += min_price * dist[i];
    }

    cout << sum;

    return 0;
}