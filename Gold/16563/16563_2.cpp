// https://www.acmicpc.net/problem/16563_2
// 16563_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_SIZE (5000000)
#define MAX_PRIME_CNT (78498)

using namespace std;

static const int INF = 0x3f3f3f3f;
static int max_num = 0;
static int primes[MAX_SIZE + 1];
static int spf[MAX_SIZE + 1];
static int prime_cnt = 0;

static void sieve(int max)
{
	for (int i = 2; i <= max; ++i)
	{
		// not visited. we know i is a prime number.
		if (spf[i] == 0)
		{
			spf[i] = i;
			primes[prime_cnt++] = i;
		}
		for (int j = 0; i * primes[j] <= max; ++j)
		{
			spf[i * primes[j]] = primes[j];
			if (i % primes[j] == 0)
				break ;
		}
	}
}

signed main() {
	fastio;

	int num_cnt = 0;

	sieve(MAX_SIZE);

	cin >> num_cnt;
	for (int i = 0; i < num_cnt; ++i){
		int num;

		cin >> num;
		while (num > 1)
		{
			cout << spf[num] << ' ';
			num /= spf[num];
		}
		cout << '\n';
	}
	
	return (0);
}