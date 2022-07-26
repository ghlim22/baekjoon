// https://www.acmicpc.net/problem/9663
// 9663번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_N (15)

using namespace std;

static const int INF = 0x3f3f3f3f;

bool check_col[MAX_N];
bool check_dia[MAX_N * 2 - 1];
bool check_reverse_dia[MAX_N * 2 - 1];

int N, ans = 0;

void solve(int row_idx)
{
    if (row_idx == N)
    {
        ans++;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        int dia = row_idx + i;
        int reverse_dia = row_idx - i + N - 1;
        if (!check_col[i] && !check_dia[dia] && !check_reverse_dia[reverse_dia])
        {
            check_col[i] = true;
            check_dia[dia] = true;
            check_reverse_dia[reverse_dia] = true;

            solve(row_idx + 1);

            check_col[i] = false;
            check_dia[dia] = false;
            check_reverse_dia[reverse_dia] = false;
        }
    }
}

signed main()
{
    fastio;
    cin >> N;
    solve(0);
    cout << ans;
    return 0;
}