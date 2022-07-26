// https://www.acmicpc.net/problem/1654
// 1654번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve()
{
}

ll N, K;
ll arr[10000];

ll get_cable_cnt(ll len)
{
    if (len == 0)
    {
        len = 1;
    }
    ll cnt = 0;
    for (int i = 0; i < K; ++i)
    {
        cnt += arr[i] / len;
    }
    return cnt;
}

signed main()
{
    fastio;
    solve();

    cin >> K >> N;
    for (int i = 0; i < K; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + K);

    ll max_len = arr[K - 1];
    ll min_len = 1;
    ll ans = 0;
    ll cnt = N;
    while (min_len <= max_len)
    {
        ll mid = (min_len + max_len) / 2;
        ll temp = get_cable_cnt(mid);

        if (temp >= cnt)
        {
            ans = mid;
            min_len = mid + 1;
        }
        else if (temp < cnt)
        {
            max_len = mid - 1;
        }
    }

    cout << ans;

    return 0;
}