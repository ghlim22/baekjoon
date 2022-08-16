// https://www.acmicpc.net/problem/11724
// 11724번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_SIZE (1000)

using namespace std;

static const int INF = 0x3f3f3f3f;

int ans = 0;
int N, M;
int nodes[MAX_SIZE][MAX_SIZE];
bool vis[MAX_SIZE];

void solve(int node)
{
    int i;
    if (!vis[node])
    {
        vis[node] = true;
    }
    for (i = 0; i < N; ++i)
    {
        if (!vis[i] && nodes[node][i])
        {
            vis[i] = true;
            solve(i);
        }
    }
}

signed main()
{
    fastio;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        nodes[node1 - 1][node2 - 1] = true;
        nodes[node2 - 1][node1 - 1] = true;
    }
    for (int i = 0; i < N; ++i)
    {
        if (!vis[i])
        {
            solve(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}