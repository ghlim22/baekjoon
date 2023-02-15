// <https://www.acmicpc.net/problem/15711>
// 15711번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

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

static bool is_prime_small(int n)
{
	if (n < 2)
		return (false);
	if (n == 2)
		return (true);
	if (n % 2 == 0)
		return (false);
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return (false);
	}
	return (true);
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

	unsigned ll test_cnt, a, b;

	cin >> test_cnt;

	for (int i = 0; i < test_cnt; ++i)
	{
		cin >> a >> b;
		unsigned ll line = a + b;
		if (line == 2)
			cout << "NO\n";
		else if (~line & 1)
			cout << "YES\n";
		else if (is_prime(line - 2, 2) && is_prime(line - 2, 7) && is_prime(line - 2, 61))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return (0);
}