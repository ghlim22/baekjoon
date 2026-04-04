#include <iostream>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)
  
const long modulus = 1000000003;
long cache[1001][500];

int main(void) {
  fastio;
  int n, k;
  std::cin >> n >> k;

  if (k > (n + 1) / 2) {
    std::cout << 0 << '\n';
    return 0;
  }


  cache[0][0] = 1;
  cache[1][0] = 1;
  cache[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    cache[i][0] = 1;
    for (int j = 1; j <= k; ++j) {
      cache[i][j] += cache[i - 1][j] + cache[i - 2][j - 1];
      cache[i][j] %= modulus;
    } 
  }


  if (n <= 2) {
    std::cout << cache[n][k] << '\n';
  } else {
    long answer = cache[n-3][k-1] + cache[n-1][k];
    answer %= modulus;
    std::cout << answer << '\n';
  }


  return 0;
}
