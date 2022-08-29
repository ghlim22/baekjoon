// https://www.acmicpc.net/problem/b
// b번

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
int current_phone = 0;
int total_battery_usage = 0;
int prev_battery_usage = 0;

void solve(int new_phone)
{
    if (total_battery_usage >= 100)
    {
        current_phone = 0;
        total_battery_usage = 0;
        prev_battery_usage = 0;
    }
    if (current_phone == 0)
    {
        current_phone = new_phone;
        total_battery_usage += 2;
        prev_battery_usage = 2;
        return;
    }
    if (current_phone != new_phone)
    {
        current_phone = new_phone;
        total_battery_usage += 2;
        prev_battery_usage = 2;
    }
    else
    {
        total_battery_usage += prev_battery_usage * 2;
        prev_battery_usage *= 2;
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int phone;
        cin >> phone;
        solve(phone);
    }
    if (total_battery_usage >= 100)
    {
        cout << 0;
    }
    else
    {
        cout << total_battery_usage;
    }

    return 0;
}