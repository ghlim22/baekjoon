#include <iostream>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

long comb[53][53];

int main(void) {
  fastio;

  for (int i = 0; i <= 52; ++i) {
	comb[i][0] = 1;
  }
  for (int i = 1; i <= 52; ++i) {
	for (int j = 1; j <= i; ++j) {
		comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
	}
  }

  const long modulus = 10007;
  int N;
  std::cin >> N;

  long retval = 0;
  for (int i = 1; i <= N / 4; ++i) {
	long setsize = comb[13][i] * comb[52 - 4 * i][N - 4 * i];
	if (i & 1) {
		retval = (retval + setsize % modulus) % modulus;
	} else {
		retval = ((retval - setsize) % modulus + modulus) % modulus;
	}
  }
  std::cout << retval;

  return 0;
}