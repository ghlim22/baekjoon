// https://www.acmicpc.net/problem/1182
// 1182번

#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int arr[21];
int N, S, ans;

void solve(int idx, int sum) // idx: 현재 원소의 index, sum: 이전까지 원소들의 합.
{
    if (idx == N)
    {
        return;
    }

    if (sum + arr[idx] == S)
    {
        ans++;
    }

    solve(idx + 1, sum + arr[idx]); // 현재 원소를 더하는 경우.
    solve(idx + 1, sum);            // 현재 원소를 더하지 않는 경우.
}

signed main()
{
    fastio;
    cin >> N >> S;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    solve(0, 0);
    cout << ans;

    return 0;
}