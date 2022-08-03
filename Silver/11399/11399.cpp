// https://www.acmicpc.net/problem/11399
// 11399번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, arr[1000];

ll solve()
{
    ll sum = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            sum += arr[j];
        }
    }

    return sum;
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << solve();
    return 0;
}