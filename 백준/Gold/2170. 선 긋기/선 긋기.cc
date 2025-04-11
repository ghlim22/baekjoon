#include <algorithm>
#include <iostream>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

pii_t lines[1000000];

int main() {
  fastio;
  int n;

  std::cin >> n;
  for (int i = 0; i < n; ++i)
    std::cin >> lines[i].first >> lines[i].second;

  std::sort(lines, lines + n);

  int sum = 0;
  int start = lines[0].first;
  int end = lines[0].second;
  for (int i = 1; i < n; ++i) {
    if (lines[i].second <= end)
      continue;
    if (lines[i].first > end) {
      sum += (end - start);
      start = lines[i].first;
      end = lines[i].second;
    } else {
      end = lines[i].second;
    }
  }
  sum += (end - start);

  std::cout << sum << '\n';

  return 0;
}