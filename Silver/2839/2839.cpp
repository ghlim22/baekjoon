// https://www.acmicpc.net/problem/2839
// 2839번

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

int solve()
{
    int cnt = 5000;
    for (int i = 0; i * 5 <= N; ++i)
    {
        int temp_cnt = 0;
        int temp_sum = N;
        if ((N - i * 5) % 3 == 0)
        {
            temp_cnt += i;
            temp_sum -= i * 5;
            temp_cnt += temp_sum / 3;
            if (temp_cnt != 0 && temp_cnt < cnt)
            {
                cnt = temp_cnt;
            }
        }
    }

    return (cnt == 5000 ? -1 : cnt);
}

signed main()
{
    fastio;
    cin >> N;
    cout << solve();
    return 0;
}