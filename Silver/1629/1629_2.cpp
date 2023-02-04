// <https://www.acmicpc.net/problem/1629_2>
// 1629_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

ll solve(ll base, ll exp, ll mod) 
{
	ll res = 1;
	while (exp)
	{
		if (exp & 1)
		{
			res = ((res % mod) * (base % mod)) % mod;
		}
		base = ((base % mod) * (base % mod)) % mod;
		exp >>= 1;
	}	
	return (res);
}

signed main() {
	fastio;
	ll a = 0, b = 0, c = 0;

	cin >> a >> b >> c;
	cout << solve(a, b, c);
	return (0);
}