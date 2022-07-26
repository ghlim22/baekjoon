// https://www.acmicpc.net/problem/2961
// 2961번

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
ll ans = LONG_LONG_MAX;
ll arr_s[10], arr_b[10];

signed main()
{
    fastio;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr_s[i] >> arr_b[i];
    }
    // 비트마스킹...
    ll max = 1 << N;
    ll idx = 1;

    while (idx < max)
    {
        ll total_sour = 1;
        ll total_bitter = 0;

        for (int i = 0; i < N; ++i)
        {
            int temp = 1 << i;
            if (idx & temp)
            {
                total_sour *= arr_s[i];
                total_bitter += arr_b[i];
            }
        }

        ll temp = total_bitter - total_sour;
        if (ans > abs(temp))
        {
            ans = abs(temp);
        }
        idx++;
    }

    cout << ans;

    return 0;
}