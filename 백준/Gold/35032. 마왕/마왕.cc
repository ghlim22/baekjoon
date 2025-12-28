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


typedef long long ll;
typedef std::pair<int, int> pii_t;
typedef std::pair<long long, long long> pll_t;


struct magic {
	int index;
	ll x;
	ll y;
	ll r;
};

int main(void) {
  fastio;
  int n;
  std::cin >> n;

  std::vector<magic> magics;
  for (int i = 0; i < n; ++i) {
	long long x, y, r;
	std::cin >> x >> y >> r;
	magics.push_back({i + 1, x, y, r});
  }

  // R이 넓이를 결정하므로, R기준 내림차순 정렬.
  std::sort(magics.begin(), magics.end(), [](const auto &a, const auto &b) {
	return a.r > b.r;
  });

  ll sum = 0;
  std::vector<magic> selected;
  for (const auto &m : magics) {
	bool overlapped = false;
	for (const auto &s : selected) {
		if (std::abs(m.x - s.x) >= m.r + s.r || std::abs(m.y - s.y) >= m.r + s.r)
			continue;
		overlapped = true;
		break;
	}
	if (!overlapped) {
		selected.push_back(m);
		sum += 4 * m.r * m.r;
	}	
  }

  std::cout << selected.size() << '\n';
  for (const auto &s : selected)
  	std::cout << s.index << '\n';

  return 0;
}
