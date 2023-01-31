// https://www.acmicpc.net/problem/11399_2
// 11399_2번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
	
}

signed main() {
	fastio;

	int cnt = 0;
	int ans = 0;

	cin >> cnt;
	int arr[cnt];
	int dp[cnt];
	for (int i = 0; i < cnt; ++i)
		cin >> arr[i];
	sort(arr, arr + cnt);
	dp[0] = arr[0];
	ans += dp[0];
	for (int i = 1; i < cnt; ++i){
		dp[i] = dp[i - 1] + arr[i];
		ans += dp[i];
	}
	cout << ans;
	return (0);
}