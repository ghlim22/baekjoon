// https://www.acmicpc.net/problem/c
// c번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int P, N;
int arr[1000];
int cnt = 0;

void solve()
{
    sort(arr, arr + N);
    for (int i = 0; i < N; ++i)
    {
        if (P >= 200)
        {
            break;
        }
        P += arr[i];
        cnt++;
    }
    cout << cnt;
}

signed main()
{
    fastio;
    cin >> P >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    solve();

    return 0;
}