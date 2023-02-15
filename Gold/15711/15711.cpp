// <https://www.acmicpc.net/problem/15711>
// 15711번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define MAX (2000000)

using namespace std;

static int spf_arr[MAX + 1];
static int prime_nums_arr[MAX + 1];
static int prime_nums_cnt = 0;

static void linear_sieve(void)
{
	for (int i = 2; i <= MAX; ++i)
	{
		if (spf_arr[i] == 0)
		{
			spf_arr[i] = i;
			prime_nums_arr[prime_nums_cnt++] = i;
		}
		for (int j = 0; prime_nums_arr[j] * i <= MAX; ++j)
		{
			spf_arr[prime_nums_arr[j] * i] = prime_nums_arr[j];
			if (i % prime_nums_arr[j] == 0)
				break ;
		}
	}
}

signed main() {
	fastio;

	unsigned ll test_cnt, a, b, sum;

	linear_sieve();

	cin >> test_cnt;
	while (test_cnt--)
	{
		cin >> a >> b;
		sum = a + b;

		if (sum <= 3)
			cout << "NO\n";
		else if (~sum & 1)
			cout << "YES\n";
		else
		{
			sum -= 2;
			bool is_prime = true;
			if (sum <= MAX)
			{
				if (spf_arr[sum] != sum)
					is_prime = false;
			}
			else
			{
				for (int i = 0; i < prime_nums_cnt; ++i)
				{
					if (sum % prime_nums_arr[i] == 0)
					{
						is_prime = false;
						break ;
					}
				}
			}

			if (is_prime)
				cout << "YES\n";
			else
				cout << "NO\n";
		}

	}
	return (0);
}

/*

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
*/