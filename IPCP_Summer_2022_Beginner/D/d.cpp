// https://www.acmicpc.net/problem/d
// d번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

enum skill
{
    L,
    S
};

int N;
int ans = 0;
int skill_count[2];

void solve()
{
}

signed main()
{
    fastio;
    cin >> N;
    bool error = false;
    for (int i = 0; i < N; ++i)
    {
        char ch;
        cin >> ch;
        switch (ch)
        {
        case 'L':
            skill_count[L]++;
            break;
        case 'S':
            skill_count[S]++;
            break;
        case 'R':
            if (skill_count[L] == 0)
            {
                error = true;
                break;
            }
            skill_count[L]--;
            ans++;
            break;
        case 'K':
            if (skill_count[S] == 0)
            {
                error = true;
                break;
            }
            skill_count[S]--;
            ans++;
            break;
        default:
            ans++;
            break;
        }
        if (error)
        {
            break;
        }
    }
    cout << ans;
    return 0;
}