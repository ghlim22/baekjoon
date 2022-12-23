// <https://www.acmicpc.net/problem/1001>
// 1001번 

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
	int a, b;

	cin >> a >> b;
	ll res = a - b;
	cout << res;
}

signed main() {
	fastio;
	solve();
}