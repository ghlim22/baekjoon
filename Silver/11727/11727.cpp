// https://www.acmicpc.net/problem/11727
// 11727번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MOD (10007)

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, ans = 0;
int arr[1000];

void solve()
{
    for (int i = 2; i < N; ++i)
    {
        arr[i] = arr[i - 1] % MOD + arr[i - 2] * 2 % MOD;
    }
}

signed main()
{
    fastio;
    cin >> N;
    arr[0] = 1;
    arr[1] = 3;
    solve();
    cout << arr[N - 1] % MOD;
    return 0;
}