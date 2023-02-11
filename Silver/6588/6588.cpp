// <https://www.acmicpc.net/problem/6588>
// 6588번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX (1000000)

using namespace std;

static int spf[MAX + 1];
static int primes[MAX + 1];
static int prime_cnt = 0;

static void linear_sieve(void)
{
	for (int i = 2; i <= MAX; ++i)
	{
		if (spf[i] == 0)
		{
			spf[i] = i;
			primes[prime_cnt++] = i;
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
	linear_sieve();
	while (true)
	{
		int num = 0;

		cin >> num;
		if (num == 0)
			break ;
		for (int i = 3; i <= num / 2; i += 2)
		{
			if (spf[i] == i && spf[num - i] == num - i)
			{
				cout << num << " = " << i << " + " << num - i << '\n';
				break ;
			}
		}
	}

	return (0);
}
