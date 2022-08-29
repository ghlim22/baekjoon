// https://www.acmicpc.net/problem/e
// e번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N;
bool vis[500001];
vector<int> tree[500001];
int characters[500001];
string ans = "";
deque<int> dq;

void solve(int cur)
{
    bool is_last = true;
    if (!vis[cur])
    {
        vis[cur] = true;
        dq.push_back(cur);
        vis[cur] = true;
    }

    for (int i = 1; i <= tree[cur].size(); ++i)
    {
        is_last = false;
        if (!vis[tree[cur][i]])
        {
            solve(tree[cur][i]);
        }
    }

    if (is_last)
    {
        /*
        string str = "";
        for (int i = 0; i < dq.size(); ++i)
        {
            str.push_back(dq[i]);
        }
        if (ans == "")
        {
            ans = str;
        }
        else if (ans < str)
        {
            ans = str;
        }
        */
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> characters[i];
    }
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solve(1);
    cout << ans;

    return 0;
}