// https://www.acmicpc.net/problem/9251
// 9251번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX (1000)

using namespace std;

static const int INF = 0x3f3f3f3f;

int dp[MAX + 1][MAX + 1];
char str1[MAX + 1];
char str2[MAX + 1];

void solve(int str1_len, int str2_len)
{
    for (int i = 1; i <= str1_len; ++i)
    {
        for (int j = 1; j <= str2_len; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

signed main()
{
    fastio;
    cin >> str1 >> str2;
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    solve(str1_len, str2_len);

    /*
        for (int i = 0; i <= str1_len; ++i)
        {
            for (int j = 0; j <= str2_len; ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        */

    cout << dp[str1_len][str2_len];
    return 0;
}