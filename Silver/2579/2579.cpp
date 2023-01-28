// <https://www.acmicpc.net/problem/2579>
// 2579번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

static int stairs[300];
static int res[300];

signed main() {
	fastio;

	int	stairs_cnt = 0;
	ll	ans = 0;

	cin >> stairs_cnt;
	for (int i = 0; i < stairs_cnt; ++i)
		cin >> stairs[i];
	
	res[0] = stairs[0];
	res[1] = stairs[0] + stairs[1];
	res[2] = max(stairs[0], stairs[1]) + stairs[2];

	for (int i = 3; i < stairs_cnt; ++i)
		res[i] = max(res[i - 2] + stairs[i], res[i - 3] + stairs[i - 1] + stairs[i]);

	cout << res[stairs_cnt - 1];

	return (0);
}