// <https://www.acmicpc.net/problem/2579>
// 2579번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

static int stairs[300];
static int dp[300];

void solve() {
	
}

signed main() {
	fastio;

	int	stairs_cnt = 0;
	ll	ans = 0;

	cin >> stairs_cnt;
	for (int i = 0; i < stairs_cnt; ++i)
		cin >> stairs[i];
	dp[0] = stairs[0];
	dp[1] = dp[0] + stairs[1];
	dp[2] = dp[0] + stairs[2];	

}