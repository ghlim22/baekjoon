// https://www.acmicpc.net/problem/12865
// 12865번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

typedef struct
{
    int weight;
    int value;
    int index;
} Stuff;

Stuff arr[100];
bool vis[100];
int N, K;
int weight[100];
int value[100];
int ans = 0;
int dp[100001];

void solve_dp()
{
    int res = 0;
    for (int i = 1; i <= K; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                if (j != k && weight[j] + weight[k] <= i)
                {
                    if (dp[weight[j]] > 0 && dp[weight[k]] > 0)
                    {
                        dp[i] = max(dp[i], dp[weight[j]] + dp[weight[k]]);
                    }
                    else
                    {
                        dp[i] = max(dp[i], arr[j].value + arr[k].value);
                    }
                }
            }
        }
    }
}

void solve(int value_sum, int weight_sum, int idx)
{
    if (idx == N)
    {
        if (weight_sum <= K)
        {
            ans = max(ans, value_sum);
        }
        return;
    }

    solve(value_sum, weight_sum, idx + 1);
    solve(value_sum + value[idx], weight_sum + weight[idx], idx + 1);
}

bool cmp(const Stuff &a, const Stuff &b)
{
    if (a.weight == b.weight)
    {
        return a.value > b.value;
    }
    return a.weight > b.weight;
}

signed main()
{
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> weight[i] >> value[i];
    }
    solve(0, 0, 0);
    cout << ans;

    return 0;
}