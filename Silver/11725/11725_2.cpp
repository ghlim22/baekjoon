// https://www.acmicpc.net/problem/11725_2
// 11725_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_SIZE (100000)

using namespace std;

static const int INF = 0x3f3f3f3f;

int parent[MAX_SIZE + 1];
int N;
vector<int> tree[MAX_SIZE + 1];

void solve()
{
    queue<int> que;
    que.push(1);
    while (!que.empty())
    {
        int front = que.front();
        for (int i = 0; i < tree[front].size(); ++i)
        {
            int node = tree[front][i];
            if (parent[node] == 0)
            {
                parent[node] = front;
                que.push(node);
            }
        }
        que.pop();
    }

    for (int i = 2; i <= N; ++i)
    {
        cout << parent[i] << '\n';
    }
}

signed main()
{
    fastio;

    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solve();

    return 0;
}