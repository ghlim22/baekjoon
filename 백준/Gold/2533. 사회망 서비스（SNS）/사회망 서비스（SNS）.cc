#include <algorithm>
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

std::vector<std::vector<int>> graph(1000001);

pii_t f(int parent, int curr) {
	int choose = 1;
	int not_choose = 0;

	for (int adj : graph[curr]) {
		if (adj == parent) {
			continue;
		}
		auto [yes, no] = f(curr, adj);
		choose += std::min(yes, no);
		not_choose += yes;
	}

	return {choose, not_choose};
}

int main(void) {
  fastio;

  int N;
  std::cin >> N;
  for (int i = 0; i < N - 1; ++i) {
	int u, v;
	std::cin >> u >> v;
	graph[u].push_back(v);
	graph[v].push_back(u);
  }
  auto [choose, not_choose] = f(-1, 1);
  std::cout << std::min(choose, not_choose);

  return 0;
}