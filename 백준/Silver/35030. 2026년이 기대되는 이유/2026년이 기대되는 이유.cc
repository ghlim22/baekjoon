#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

#define MAX (100001)

typedef std::pair<int, int> pii_t;

bool isSpecial(int num, std::vector<int> &spf) {
	if (spf[num + 1] != num + 1) {
		return false;
	}

	for (int i = 100000; i >= 10; i /= 10) {
		int j = num / i;
		if (j == 0) continue;
		int k = num % i;
		int l = j * k + 1;
		if (spf[l] != l) return false;
	}

	return true;
}

int main(void) {
  fastio;

  std::vector<int> primes;
  std::vector<int> spf(MAX + 1);
  spf[0] = 0;
  spf[1] = 0;
  for (int i = 2; i <= MAX; ++i) {
	if (spf[i] == 0) {
		spf[i] = i;
		primes.push_back(i);
	}
	for (int p : primes) {
		int x = p * i;
		if (x > MAX) break;
		spf[x] = p;
		if (i % p == 0) break;
	}
  }

  int sum = 0;
  std::vector<pii_t> cache;
  for (int p : primes) {
	if (isSpecial(p - 1, spf)) {
		sum++;
		cache.push_back({p - 1, sum});
	}
  }

  int t;
  std::cin >> t;
  while (t--) {
	int n;
	std::cin >> n;
	pii_t tmp = {n, MAX};
	auto it = std::upper_bound(cache.begin(), cache.end(), tmp);
	std::cout << (*--it).second << '\n';
  }

  return 0;
}