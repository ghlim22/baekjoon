// https://www.acmicpc.net/problem/a
// a번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int T;

int solve(int a, int b, int c)
{
    int x, y, z;
    int res = 0;
    for (x = 1; x <= a; ++x)
    {
        for (y = 1; y <= b; ++y)
        {
            int temp1 = x % y;
            for (z = 1; z <= c; ++z)
            {
                int temp2 = y % z;
                int temp3 = z % x;
                if (temp1 == temp2 && temp1 == temp3 && temp2 == temp3)
                {
                    res++;
                }
            }
        }
    }

    return res;
}

signed main()
{
    fastio;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << '\n';
    }

    return 0;
}