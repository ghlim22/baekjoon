#include <algorithm>
#include <cmath>
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

typedef std::pair<int, long> pii_t;

std::vector<int> energy;
std::vector<std::vector<pii_t>> graph;
pii_t t[18][100001];
int log2_limit;
int n;

void dfs(int prev, int current) {
	for (const auto &[adj, distance] : graph[current]) {
		if (adj != prev) {
			t[0][adj].first = current;
			t[0][adj].second = distance;
			dfs(current, adj);
		}
	}
}

void buildTable() {
	t[0][1].first = 1;
	t[0][1].second = 0;
	for (int k = 1; k <= log2_limit; ++k) {
		for (int i = 1; i <= n; ++i) {
			const auto &[midNode, midCost] = t[k - 1][i];
			int to = t[k-1][midNode].first;
			int distance = midCost + t[k-1][midNode].second;
			t[k][i].first = to; // i에서 2^(i-1) 이동 -> j + j에서 2^(i-1)번 이동 ==> i에서 2^i번 이동
			t[k][i].second = distance;
		}
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		int node = i;
		for (int k = log2_limit; k >= 0 && node != 1 && energy[i] > 0; --k) {
			const auto &[next, distance] = t[k][node];
			if (distance <= energy[i]) {
				energy[i] -= distance;
				node = next;
			}
		}
		std::cout << node << '\n';
	}
}

int main(void) {
  fastio;

  std::cin >> n;

  log2_limit = std::ceil(std::log2(n));
  energy = std::vector<int>(n + 1);
  graph = std::vector<std::vector<pii_t>>(n + 1);
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
  buildTable();
  solve();

  return 0;
}