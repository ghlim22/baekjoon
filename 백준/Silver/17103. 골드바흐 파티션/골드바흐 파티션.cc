#include <iostream>
#include <queue>
#include <vector>

#define MAX (1000000)

void findPrimes(const int n, std::vector<int> &spf, std::vector<int> &primes)
{
	for (int i = 2; i <= n; ++i) {
		if (spf[i] == 0) {
			spf[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			long comp = (long)p * i;
			if (comp > n) {
				break;
			}
			spf[comp] = p;
			if (i % p == 0) {
				break;
			}
		}
	}
}

int partition(const int n, std::vector<int> &spf, std::vector<int> &primes)
{
	int count = 0;

	for (int p : primes) {
		if (p > n / 2) {
			break;
		}
		const int counterpart = n - p;
		if (spf[counterpart] == counterpart) { /* See if the counterpart of p is a prime number. */
			++count;
		}
	}

	return count;
}

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int t;
	int n;
	std::vector<int> spf(MAX + 1, 0);
	std::vector<int> primes;

	findPrimes(MAX, spf, primes);

	std::cin >> t;

	while (t--) {
		std::cin >> n;
		std::cout << partition(n, spf, primes) << '\n';
	}

	return 0;
}
