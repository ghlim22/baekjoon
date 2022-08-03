// https://www.acmicpc.net/problem/15652
// 15652번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, M;
int arr[8];

void solve(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << arr[i] << (i == M - 1 ? "\n" : " ");
        }
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (depth > 0 && i < arr[depth - 1])
        {
            continue;
        }
        arr[depth] = i;
        solve(depth + 1);
    }
}

signed main()
{
    fastio;
    cin >> N >> M;
    solve(0);
    return 0;
}