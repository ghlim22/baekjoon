// https://www.acmicpc.net/problem/2667
// 2667번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_SIZE (25)

using namespace std;

static const int INF = 0x3f3f3f3f;

int house[MAX_SIZE][MAX_SIZE];
int N;
int complex_num;
int counts[500];

void solve(int i, int j)
{
    if (house[i][j])
    {
        house[i][j] = 0;       // 이번 집을 방문 처리해준다.
        counts[complex_num]++; // 집을 방문할 때마다 이번 단지의 집 수를 추가해준다.
        if (i > 0 && house[i - 1][j])
        {
            solve(i - 1, j);
        }
        if (i < N - 1 && house[i + 1][j])
        {
            solve(i + 1, j);
        }
        if (j > 0 && house[i][j - 1])
        {
            solve(i, j - 1);
        }
        if (j < N - 1 && house[i][j + 1])
        {
            solve(i, j + 1);
        }
    }
}

signed main()
{
    fastio;

    cin >> N;
    string line;
    for (int i = 0; i < N; ++i)
    {
        cin >> line;
        for (int j = 0; j < N; ++j)
        {
            if (line[j] == '1')
            {
                house[i][j] = 1;
            }
            else
            {
                house[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (house[i][j]) // 집을 찾으면 dfs로 연결된 집 모두 방문 처리.
            {
                solve(i, j);
                complex_num++; // dfs가 한 번 완료되면 단지 번호 추가.
            }
        }
    }

    sort(counts, counts + complex_num);
    cout << complex_num << "\n";
    for (int i = 0; i < complex_num; ++i)
    {
        cout << counts[i] << "\n";
    }

    return 0;
}