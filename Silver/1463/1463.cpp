// https://www.acmicpc.net/problem/1463
// 1463번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int dp[1000001];
int N;

void solve()
{
    for (int i = 2; i <= N; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
    }
}

signed main()
{
    fastio;
    cin >> N;
    dp[1] = 0;
    solve();
    cout << dp[N];
    return 0;
}