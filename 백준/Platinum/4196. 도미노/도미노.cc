#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

void dfs1(int node, std::stack<int> &stk, std::vector<std::vector<int>> &g, std::vector<bool> &v) {
	v[node] = true;
	for (int adj : g[node]) {
		if (!v[adj]) {
			dfs1(adj, stk, g, v);
		}
	}
	stk.push(node);
}

void dfs2(int node, std::vector<std::vector<int>> &g, std::vector<bool> &v) {
	v[node] = true;
	for (int adj : g[node]) {
		if (!v[adj]) {
			dfs2(adj, g, v);
		}
	}
}

int main(void) {
  fastio;

  int t, n, m, x, y;
  std::cin >> t;
  while (t--) {
	std::cin >> n >> m;
	std::vector<std::vector<int>> graph(n + 1);
	while (m--) {
		std::cin >> x >> y;
		graph[x].push_back(y);
	}

	std::vector<bool> v(n + 1);
	std::stack<int> stk;
	for (int i = 1; i <= n; ++i) {
		if (!v[i]) {
			dfs1(i, stk, graph, v);
		}
	}

	int answer = 0;
	std::fill(v.begin(), v.end(), false);
	while (!stk.empty()) {
		int node = stk.top();
		stk.pop();
		if (!v[node]) {
			answer++;
			dfs2(node, graph, v);
		}
	}

	std::cout << answer << '\n';
  }

  return 0;
}