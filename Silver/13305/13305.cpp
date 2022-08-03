// https://www.acmicpc.net/problem/13305
// 13305번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int city_cnt;
ll roads[100000];  // n 개
ll prices[100000]; // n - 1개
ll sum = 0;

void solve()
{
    int cur = 0;
    int i;
    while (cur < city_cnt)
    {
        ll distance = 0;
        for (i = cur + 1; i < city_cnt; ++i)
        {
            distance += roads[i - 1];
            if (i == city_cnt - 1 || prices[cur] > prices[i]) // 현재 도시보다 기름이 저렴한 도시를 발견 or 마지막 도시에 도착.
            {
                sum += prices[cur] * distance;
                cur = i;
                break;
            }
        }
        if (cur == city_cnt - 1)
        {
            break;
        }
    }
}

signed main()
{
    fastio;
    cin >> city_cnt;
    for (int i = 0; i < city_cnt - 1; ++i)
    {
        cin >> roads[i];
    }
    for (int i = 0; i < city_cnt; ++i)
    {
        cin >> prices[i];
    }
    solve();
    cout << sum;
    return 0;
}