// https://www.acmicpc.net/problem/2609_2
// 2609_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

static int solve(int a, int b) {
	if (b == 0)
		return (a);
	return (solve(b, a % b));
}

signed main() {
	fastio;
	int a, b;
	cin >> a >> b;
	int gcd = solve(a, b);
	int lcm = a / gcd * b;
	cout << gcd << '\n' << lcm;
	return (0);
}