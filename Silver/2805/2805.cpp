// https://www.acmicpc.net/problem/2805
// 2805번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

ll N, M;
ll trees[1000000];

ll get_total_tree(int height)
{
    ll sum = 0;
    for (int i = 0; i < N; ++i)
    {
        ll d = trees[i] - height;
        if (d >= 0)
        {
            sum += d;
        }
    }

    return sum;
}

void solve()
{
}

signed main()
{
    fastio;
    solve();

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> trees[i];
    }
    sort(trees, trees + N);

    ll min_h = 0;
    ll max_h = trees[N - 1];
    ll ans;

    while (min_h <= max_h)
    {
        ll mid = (min_h + max_h) / 2;
        if (get_total_tree(mid) >= M)
        {
            ans = mid;
            min_h = mid + 1;
        }
        else
        {
            max_h = mid - 1;
        }
    }

    cout << max_h;
    return 0;
}