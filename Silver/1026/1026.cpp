// https://www.acmicpc.net/problem/1026
// 1026번

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
int arr_a[50];
int arr_b[50];
ll sum = 0;

bool descend_cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    for (int i = 0; i < N; ++i)
    {
        sum += arr_a[i] * arr_b[i];
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr_a[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> arr_b[i];
    }
    sort(arr_a, arr_a + N, descend_cmp);
    sort(arr_b, arr_b + N);

    solve();
    cout << sum;
    return 0;
}