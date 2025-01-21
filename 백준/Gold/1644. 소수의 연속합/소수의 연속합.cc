#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int N;
  std::cin >> N;

  std::vector<int> spf(N + 1, 0);
  std::vector<int> primes;

  // Linear sieve
  for (int i = 2; i <= N; ++i) {
    if (spf[i] == 0) {
      primes.push_back(i);
    }
    for (int j : primes) {
      if (i * j > N)
        break;
      spf[i * j] = j;
      if (i % j == 0)
        break;
    }
  }

  if (N == 1) {
	std::cout << 0 << std::endl;
	return 0;
  }

  // Two pointers
  int cnt = 0;
  int sum = primes[0]; // sum = primes[i] + primes[i + 1] + primes[i + 2] + ... + primes[j]
  for (int i = 0, j = 0; i <= j && j < primes.size();) {
    if (sum >= N) {
      if (sum == N)
        cnt++;
      sum -= primes[i++];

    } else {
      sum += primes[++j];
    }
  }
  std::cout << cnt << std::endl;

  return 0;
}