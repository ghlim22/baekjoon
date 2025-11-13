#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

std::vector<int> energy;
std::vector<std::vector<pii_t>> graph;
std::vector<int> answer;
std::vector<std::vector<pii_t>> reachable;

void dfs(int prev, int current) {
	answer[current] = current;
	reachable[current].push_back({current, energy[current]});
	for (auto [child, distance] : graph[current]) {
		if (child == prev) {
			continue;
		}
		dfs(current, child);
		for (auto [descendant, remainder] : reachable[child]) {
			if (remainder == distance) {
				answer[descendant] = current;
			} else if (remainder > distance) {
				answer[descendant] = current;
				reachable[current].push_back({descendant, remainder - distance});
			}
		}
	}
}

int main(void) {
  fastio;

  int n;
  std::cin >> n;

  energy = std::vector<int>(n + 1);
  graph = std::vector<std::vector<pii_t>>(n + 1);
  answer = std::vector<int>(n + 1);
  reachable = std::vector<std::vector<pii_t>>(n + 1);

  for (int i = 1; i <= n; ++i) {
	std::cin >> energy[i];
  }

  for (int i = 0; i < n - 1; ++i) {
	int a, b, c;
	std::cin >> a >> b >> c;
	graph[a].push_back({b, c});
	graph[b].push_back({a, c});
  }

  dfs(0, 1);
  for (int i = 1; i <= n; ++i) {
	std::cout << answer[i] << '\n';
  }

  return 0;
}