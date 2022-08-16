// https://www.acmicpc.net/problem/11053
// 11053번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, ans = 1;
int arr[1000];
int dp[1000];

void solve()
{
    dp[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) // j < i, arr[j] < arr[i] 인 dp[j] 중 최댓값.
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    solve();
    cout << ans;
    return 0;
}