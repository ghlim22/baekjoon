// https://www.acmicpc.net/problem/14731
// 14731번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
ll factor = 1000000007;

signed main()
{
    fastio;

    ll N, C, K;
    ll sum = 0;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> C >> K;
        ll tmp = C * K % factor;
        ll base = 2;
        ll result = 1;
        ll exp = K - 1;
        while (exp)
        {
            if (exp & 1)
            {
                result = result * base % factor;
            }

            base = base * base % factor;
            exp /= 2;
        }
        sum = (sum + tmp * result) % factor;
    }

    cout << sum;

    return 0;
}