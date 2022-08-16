// https://www.acmicpc.net/problem/5525
// 5525번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int solve(const string &s, int N, int S)
{
    int cnt = 0;
    int ans = 0;
    int cur;

    for (cur = 0; cur < S; ++cur)
    {
        if (s[cur] == 'I')
        {
            while (s[cur + 1] == 'O' && s[cur + 2] == 'I')
            {
                cur += 2;
                cnt++;
                if (cnt == N)
                {
                    ans++;
                    cnt--;
                }
            }
        }

        cnt = 0;
    }

    return ans;
}

signed main()
{
    fastio;
    int N, S;
    string s_str;

    cin >> N >> S;
    cin >> s_str;
    cout << solve(s_str, N, S);
    return 0;
}