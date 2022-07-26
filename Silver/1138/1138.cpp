// https://www.acmicpc.net/problem/1138
// 1138번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
int ans[10];
int N;

void solve()
{
}

signed main()
{
    fastio;
    solve();

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int left, j;
        cin >> left;

        for (int k = 0; k < N; ++k)
        {
            if (ans[k] == 0)
            {
                if (left == 0)
                {
                    ans[k] = i;
                    break;
                }
                else
                {
                    left--;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << ans[i];
        if (i == N - 1)
        {
            ;
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}