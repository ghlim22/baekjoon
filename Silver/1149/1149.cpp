// https://www.acmicpc.net/problem/1149
// 1149번

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
int red[1000], blue[1000], green[1000];
int red_sum[1000], blue_sum[1000], green_sum[1000];

int select_red_sum(int n);
int select_green_sum(int n);
int select_blue_sum(int n);

int select_red_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (red_sum[n - 1])
    {
        return red_sum[n - 1];
    }
    red_sum[n - 1] = red[n - 1] + min(select_blue_sum(n - 1), select_green_sum(n - 1));
    return red_sum[n - 1];
}

int select_green_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (green_sum[n - 1])
    {
        return green_sum[n - 1];
    }
    green_sum[n - 1] = green[n - 1] + min(select_red_sum(n - 1), select_blue_sum(n - 1));
    return green_sum[n - 1];
}

int select_blue_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (blue_sum[n - 1])
    {
        return blue_sum[n - 1];
    }
    blue_sum[n - 1] = blue[n - 1] + min(select_red_sum(n - 1), select_green_sum(n - 1));
    return blue_sum[n - 1];
}

void solve()
{
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> red[i] >> blue[i] >> green[i];
    }
    int red = select_red_sum(N);
    int green = select_green_sum(N);
    int blue = select_blue_sum(N);

    int ans = min(red, green);
    ans = min(ans, blue);

    cout << ans;

    return 0;
}