// https://www.acmicpc.net/problem/15649_2
// 15649_2번

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
bool used[9];
int arr[8];

void solve(int len, int arr[])
{
    if (len == M)
    {
        // 수열 출력.
        for (int i = 0; i < M; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= N; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            arr[len] = i;
            solve(len + 1, arr);
            used[i] = false;
        }
    }
}

signed main()
{
    fastio;
    cin >> N >> M;
    solve(0, arr);

    return 0;
}