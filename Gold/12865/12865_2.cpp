// https://www.acmicpc.net/problem/12865_2
// 12865_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_WEIGHT (100000)
#define MAX_NUM (100)

using namespace std;

static const int INF = 0x3f3f3f3f;

int dp[MAX_NUM + 1][MAX_WEIGHT + 1];
int weight[MAX_NUM + 1];
int values[MAX_NUM + 1];

int N, K;

void solve()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= K; ++j)
        {
            if (j >= weight[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + values[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

signed main()
{
    fastio;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> weight[i] >> values[i];
    }
    solve();
    cout << dp[N][K];
    return 0;
}