// https://www.acmicpc.net/problem/11047
// 11047번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, K, cnt = 0;
int coins[10];

void solve()
{
    while (K > 0)
    {
        cnt += K / coins[N - 1];
        K %= coins[N - 1];
        N--;
    }
}

signed main()
{
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }
    solve();
    cout << cnt;
    return 0;
}