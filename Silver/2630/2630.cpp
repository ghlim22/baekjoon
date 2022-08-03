// https://www.acmicpc.net/problem/2630
// 2630번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, cnt_W = 0, cnt_B = 0;
int paper[128][128];

bool isSame(int n, int start_row, int start_col)
{
    int first = paper[start_row][start_col];
    for (int i = start_row; i < start_row + n; ++i)
    {
        for (int j = start_col; j < start_col + n; ++j)
        {
            if (first != paper[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int n, int start_row, int start_col)
{
    if (n == 1)
    {
        if (paper[start_row][start_col])
        {
            cnt_B++;
        }
        else
        {
            cnt_W++;
        }

        return;
    }

    if (isSame(n, start_row, start_col))
    {
        if (paper[start_row][start_col])
        {
            cnt_B++;
        }
        else
        {
            cnt_W++;
        }

        return;
    }
    else
    {
        solve(n / 2, start_row, start_col);
        solve(n / 2, start_row, start_col + n / 2);
        solve(n / 2, start_row + n / 2, start_col);
        solve(n / 2, start_row + n / 2, start_col + n / 2);
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> paper[i][j];
        }
    }
    solve(N, 0, 0);
    cout << cnt_W << "\n"
         << cnt_B;
    return 0;
}