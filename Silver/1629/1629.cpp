// https://www.acmicpc.net/problem/1629
// 1629번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
int a, b, c;

ll solve(int a, int x)
{
    if (x == 0)
    {
        return 1;
    }

    ll temp = solve(a, x / 2);
    temp = temp * temp % c;

    if (x % 2)
    {
        temp *= a;
    }

    return temp % c;
}

signed main()
{
    fastio;
    cin >> a >> b >> c;
    cout << solve(a, b);
    return 0;
}