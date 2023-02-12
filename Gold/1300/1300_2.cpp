#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int solve(int n, int k) {
    int ans = 0;
    int left = 1;
    int right = k;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int below_cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            below_cnt += min(n, mid / j);
        }
        if (below_cnt >= k) // 더 작은 수 탐색.
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1; // 더 큰 수 탐색.
        }
    }
    
    return ans;
}

signed main() {
    fastio;
    int N, K;
    cin >> N >> K;
    cout << solve(N, K);
    return 0;
}
