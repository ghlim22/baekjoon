// <https://www.acmicpc.net/problem/15711>
// 15711번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static unsigned ll fast_power(int base, int exp, int mod)
{
	unsigned ll res = 1;

	while (exp)
	{
		if (exp & 1)
			res = ((res % mod) * (base % mod)) % mod;
		base = ((base % mod) * (base % mod)) % mod;
		exp >>= 1;
	}
	return (res);
}

static bool is_prime(unsigned ll n, unsigned ll a)
{
	if (n < 2)
		return (false);
	if (n == 2)
		return (true);
	if (n % a == 0 || n % 2 == 0)
		return (false);
	unsigned ll k = n - 1;
	while (true)
	{
		unsigned ll tmp = fast_power(a, k, n);
		if (tmp == n - 1) // a^(k) mod n = -1 mod n
			return (true);
		if (k & 1)
			return (tmp == n - 1 || tmp == 1);
		k >>= 1;
	}
}



signed main() {
	fastio;
	cout << is_prime(108, 2);
	cout << is_prime(108, 7);
	cout << is_prime(108, 61);
	return (0);
}