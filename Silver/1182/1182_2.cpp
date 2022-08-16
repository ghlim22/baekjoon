// https://www.acmicpc.net/problem/1182_2
// 1182_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
int N, S;
int ans = 0;
int arr[20];

void solve(int sum, int idx, int cnt)
{
    // 종료 조건.
    if (idx == N)
    {
        // sum == S라면 답 하나 추가.
        // 부분수열의 크기는 양수.
        if (sum == S && cnt > 0)
        {
            ans++;
        }
        return;
    }

    solve(sum + arr[idx], idx + 1, cnt + 1); // add current element.
    solve(sum, idx + 1, cnt);                // not add current element.
}

signed main()
{
    fastio;
    cin >> N >> S;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    solve(0, 0, 0);
    cout << ans;
    return 0;
}