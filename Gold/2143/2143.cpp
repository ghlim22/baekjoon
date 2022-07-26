// https://www.acmicpc.net/problem/2143
// 2143번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

ll T, n, m, ans = 0;
int a[1000];
int b[1000];

void solve()
{
}

signed main()
{
    fastio;
    solve();

    cin >> T;

    // 배열 A 저장.
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // 배열 B 저장.
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    // 배열 A의 부분합을 <부분합, 등장횟수>맵에 넣어준다.
    map<ll, ll> a_map;
    for (int i = 0; i < n; ++i)
    {
        ll sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += a[j];
            a_map[sum]++;
        }
    }
    // 배열 B의 부분합을 구하면서 T - (B의 부분합)이 맵 A에 존재한다면 답에 더해준다.
    for (int i = 0; i < m; ++i)
    {
        ll sum = 0;
        for (int j = i; j < m; ++j)
        {
            sum += b[j];
            if (a_map[T - sum])
            {
                ans += a_map[T - sum];
            }
        }
    }

    cout << ans;

    return 0;
}