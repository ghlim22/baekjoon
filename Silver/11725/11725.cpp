// https://www.acmicpc.net/problem/11725
// 11725번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_SIZE (100000)
#define vi vector<int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N;
int parent[MAX_SIZE + 1];
vector<int> trees[MAX_SIZE + 1];

void solve()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int front = q.front();
        for (int i = 0; i < trees[front].size(); ++i)
        {
            int temp = trees[front][i];
            if (parent[temp] == 0)
            {
                q.push(temp);
                parent[temp] = front;
            }
        }
        q.pop();
    }
}

signed main()
{
    fastio;

    cin >> N;
    for (int i = 1; i <= N - 1; ++i)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        trees[temp1].push_back(temp2);
        trees[temp2].push_back(temp1);
    }
    solve();
    for (int i = 2; i <= N; ++i)
    {
        cout << parent[i] << "\n";
    }

    return 0;
}