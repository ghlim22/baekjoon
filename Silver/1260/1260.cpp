// https://www.acmicpc.net/problem/1260
// 1260번

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

bool nodes[MAX_SIZE][MAX_SIZE];
bool vis[MAX_SIZE];
bool vis_q[MAX_SIZE];

queue<int> print_que;

int N, M, V;

void print(void)
{
    while (!print_que.empty())
    {
        cout << print_que.front() << ((print_que.size() == 1) ? "\n" : " ");
        print_que.pop();
    }
}

void dfs_solve(int node)
{
    if (!vis[node - 1])
    {
        // cout << node << " ";
        print_que.push(node);
        vis[node - 1] = true;
    }
    for (int i = 0; i < N; ++i)
    {
        if (!vis[i] && nodes[node - 1][i])
        {
            // cout << i + 1 << " ";
            print_que.push(i + 1);
            vis[i] = true;
            dfs_solve(i + 1);
        }
    }
}

void bfs_solve(int node)
{
    queue<int> q;
    q.push(node - 1);
    vis_q[node - 1] = true;
    while (!q.empty())
    {
        int front = q.front();
        for (int i = 0; i < N; ++i)
        {
            if (!vis_q[i] && nodes[front][i])
            {
                vis_q[i] = true;
                q.push(i);
            }
        }
        // cout << q.front() + 1 << " ";
        print_que.push(q.front() + 1);
        q.pop();
    }
}

signed main()
{
    fastio;
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        nodes[node1 - 1][node2 - 1] = true;
        nodes[node2 - 1][node1 - 1] = true;
    }

    // dfs
    dfs_solve(V);
    print();
    // bfs
    bfs_solve(V);
    print();

    return 0;
}