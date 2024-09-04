#include <iostream>
#include <vector>

#define N (1000000)

std::vector<int> spf(N + 1);
std::vector<int> primes;

void linearSieve()
{
	for (int i = 2; i <= N; ++i) {
		if (spf[i] == 0) {
			spf[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			long comp = (long)p * i;
			if (comp > N) 
				break;
			spf[comp] = p;
			if (i % p == 0)
				break;
		}
	}
}

int main(void)
{
	int m, n;
	std::cin >> m >> n;
	linearSieve();
	for (int i = 0; i < primes.size() && primes[i] <= n; ++i) {
		if (primes[i] < m) {
			continue;
		}
		for (int j = i; j < primes.size() && primes[j] <= n; ++j) {
			std::cout << primes[j] << '\n';
		}
		break;
	}
	return 0;
}
