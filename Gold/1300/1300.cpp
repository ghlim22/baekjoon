// https://www.acmicpc.net/problem/1300
// 1300번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, k, result = 0;
void solve(int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 1; i <= N; ++i)
        {
            cnt += min(mid / i, N);
        }

        if (cnt >= k)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << result;
}

signed main()
{
    fastio;
    cin >> N >> k;
    solve(1, k);
    return 0;
}