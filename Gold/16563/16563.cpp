// <https://www.acmicpc.net/problem/16563>
// 16563번 

#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX (5000000)
using namespace std;

static int spf[MAX + 1];
static int primes[MAX + 1];
static int pn_cnt = 0;

static void linear_sieve(void)
{
	for (int i = 2; i <= MAX; ++i)
	{
		if (spf[i] == 0)
		{
			primes[pn_cnt++] = i;
			spf[i] = i;
		}
		for (int j = 0; i * primes[j] <= MAX; ++j)
		{
			spf[i * primes[j]] = primes[j];
			if (i % primes[j] == 0)
				break ;
		}
	}
}

signed main() {
	fastio;
	
	int cnt = 0;

	linear_sieve();
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int input;

		cin >> input;
		while (input > 1)
		{
			cout << spf[input] << ' ';
			input /= spf[input];
		}
		cout << '\n';
	}

	return (0);
}