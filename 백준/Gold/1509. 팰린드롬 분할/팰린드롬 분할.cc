#include <algorithm>
#include <iostream>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

int d[2501];

int main(void) {
  fastio;

  std::string s;
  std::cin >> s;

  int N = s.size();
  s = " " + s;

  std::fill(d + 1, d + N + 1, 3000);

  for (int i = 1; i <= N; ++i) {
	// 짝수 길이 palindrome
	for (int j = 0; i - j >= 1 && i + j <= N; ++j) {
		if (s[i - j] != s[i + j]) {
			break;
		}
		d[i + j] = std::min(d[i + j], d[i - j - 1] + 1);
	}

	// 홀수 길이 palindrome
	for (int j = 0; i - j >= 1 && i + j + 1 <= N; ++j) {
		if (s[i - j] != s[i + j + 1]) {
			break;
		}
		d[i + j + 1] = std::min(d[i + j + 1], d[i - j - 1] + 1);
	}
  }

  std::cout << d[N] << std::endl;

  return 0;
}