// https://www.acmicpc.net/problem/1074
// 1074번

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
ll r, c;
ll ans = 0;

void solve(int n, int row, int col)
{
    if (n == 0)
    {
        return;
    }

    ll size = 1 << n;
    ll half = size / 2;
    ll row_idx = row / half;
    ll col_idx = col / half;

    if (row_idx == 0 && col_idx == 0)
    {
        ans += half * half * 0;
        solve(n - 1, row % half, col % half);
    }
    else if (row_idx == 0 && col_idx == 1)
    {
        ans += half * half * 1;
        solve(n - 1, row % half, col % half);
    }
    else if (row_idx == 1 && col_idx == 0)
    {
        ans += half * half * 2;
        solve(n - 1, row % half, col % half);
    }
    else
    {
        ans += half * half * 3;
        solve(n - 1, row % half, col % half);
    }
}

signed main()
{
    fastio;
    cin >> N >> r >> c;
    solve(N, r, c);
    cout << ans;
    return 0;
}