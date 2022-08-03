// https://www.acmicpc.net/problem/1074_2
// 1074_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, r, c, cnt = 0;

void solve(int n, int row, int col)
{
    if (n == 0)
    {
        return;
    }

    int size = pow(2, n);
    int half = size / 2;

    // 1 ~ 4 사분면 구분.
    if (row < half && col < half) // 1
    {
        ;
    }
    else if (row < half && col >= half) // 2
    {
        cnt += 1 * half * half;
    }
    else if (row >= half && col < half) // 3
    {
        cnt += 2 * half * half;
    }
    else // 4
    {
        cnt += 3 * half * half;
    }

    solve(n - 1, row % half, col % half); // 4등분 후 재귀 호출.
}

signed main()
{
    fastio;
    cin >> N >> r >> c;
    solve(N, r, c);
    cout << cnt;
    return 0;
}