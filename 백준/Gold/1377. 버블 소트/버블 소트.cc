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

pii_t ARRAY[500000];

int main() {
  fastio;

  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> ARRAY[i].first;
    ARRAY[i].second = i;
  }

  std::sort(ARRAY, ARRAY + n);

  int maxSwapCount = 0;
  for (int i = 0; i < n; ++i) {
    int swapCount = ARRAY[i].second - i;
    maxSwapCount = std::max(maxSwapCount, swapCount);
  }

  std::cout << maxSwapCount + 1;

  return 0;
}