#include <iostream>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

int main(void) {
  fastio;

  int n, k;
  std::cin >> n >> k;

  int answer = 0;
  int j = 0;
  for (int i = 1; i <= n; ++i) {
	if (n % i == 0) {
		j++;
		if (j == k) {
			answer=i;
			break;
		}
	}
  }
  std::cout << answer;

  return 0;
}