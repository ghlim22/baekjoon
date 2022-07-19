// https://www.acmicpc.net/problem/1780
// 1780번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int minus_one_cnt = 0;
int one_cnt = 0;
int zero_cnt = 0;
int N;
int arr[2187][2187];
bool is_same_num(int start_row, int start_col, int size);

void solve(int start_row, int start_col, int size)
{
    // base case: 종이가 모두 같은 숫자로 구성되어 있다면 cnt++.
    if (is_same_num(start_row, start_col, size))
    {
        switch (arr[start_row][start_col])
        {
        case -1:
            minus_one_cnt++;
            return;
        case 0:
            zero_cnt++;
            return;
        case 1:
            one_cnt++;
            return;
        default:
            return;
        }
    }

    // 아니라면 종이를 9등분해 재귀적으로 해결.
    for (int i = start_row; i < start_row + size; i += size / 3)
    {
        for (int j = start_col; j < start_col + size; j += size / 3)
        {
            solve(i, j, size / 3);
        }
    }
}

bool is_same_num(int start_row, int start_col, int size)
{
    int base = arr[start_row][start_col];
    for (int i = start_row; i < start_row + size; ++i)
    {
        for (int j = start_col; j < start_col + size; ++j)
        {
            if (arr[i][j] != base)
            {
                return false;
            }
        }
    }
    return true;
}

signed main()
{
    fastio;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    solve(0, 0, N);

    cout << minus_one_cnt << "\n";
    cout << zero_cnt << "\n";
    cout << one_cnt << "\n";

    return 0;
}