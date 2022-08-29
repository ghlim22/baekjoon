// https://www.acmicpc.net/problem/11724_2
// 11724_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_NUM (1000)

using namespace std;

static const int INF = 0x3f3f3f3f;

bool arr[MAX_NUM + 1][MAX_NUM + 1];
bool vis[MAX_NUM + 1];

void dfs(int n, int start)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i] && arr[start][i])
        {
            vis[i] = true;
            dfs(n, i);
        }
    }
}

int solve(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(n, i);
            ans++;
        }
    }
    return ans;
}

signed main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        arr[node1][node2] = true;
        arr[node2][node1] = true;
    }
    cout << solve(n);
    return 0;
}