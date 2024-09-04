#include <cstddef>
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

bool solve(int n)
{
	for (int p : primes) {
		if (p > n / 2) {
			break;
		}
		if (spf[n - p] == n - p) {
			std::cout << n << " = " << p << " + " << n - p << '\n';
			return true;
		}
	}
	return false;
}

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;

	linearSieve();

	while (true) {
		std::cin >> n;

		if (n == 0) {
			break;
		}

		if (!solve(n)) {
			std::cout << "Goldbach's conjecture is wrong.\n";
		}	
	}


	return 0;
}
