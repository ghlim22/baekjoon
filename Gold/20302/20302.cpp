// https://www.acmicpc.net/problem/20302
// 20302번 

#include <iostream>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INTEGER_PROMPT ("mint chocolate")
#define RATIONAL_PROMPT ("toothpaste")

using namespace std;

static long long get_gcd(long long a, long long b)
{
	if (b == 0)
		return (a);
	return (get_gcd(b, a % b));
}

static void init_prime_table(void)
{
	for (int i = 2; i <= 100000; ++i)
	{
		if (!visited[i])
		{
			primes[i] = true;
			for (int j = i * i; j < 100000; j += i)
				visited[j] = true;
		}
	}
}

static void factorize(int n, int *table)
{

}

signed main() {
	fastio;

	return (0);
}