#include <iostream>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

std::vector<int> spf(10001);
std::vector<int> primes;

int main(void) {
  fastio;
  int m, n;
  std::cin >> m >> n;

  for (int i = 2; i <= n; ++i) {
	if (spf[i] == 0) {
		spf[i] = i;
		primes.push_back(i);
	}
	for (int p : primes) {
		int x = p * i;
		if (x > n) {
			break;
		}
		spf[x] = p;
		if (i % p == 0) {
			break;
		}
	}
  }

  int sum = 0;
  int min = 10001;
  for (int p : primes) {
	if (p > n) break;
	if (p >= m) {
		min = (p < min) ? p : min;
		sum += p;
	}
  }

  if (sum == 0) {
	std::cout << "-1";
  } else {
	std::cout << sum << '\n' << min;
  }

  return 0;
}