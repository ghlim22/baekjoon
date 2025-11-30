#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <algorithm>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

void dfs1(int node, std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::stack<int> &s) {
	visited[node] = true;
	for (int adj : graph[node]) {
		if (!visited[adj]) {
			dfs1(adj, graph, visited, s);
		}
	}
	s.push(node);
}

void dfs2(int node, std::vector<std::vector<int>> &graphT, std::vector<int> &scc, int sccIndex) {
	scc[node] = sccIndex;
	for (int adj : graphT[node]) {
		if (scc[adj] == 0) {
			dfs2(adj, graphT, scc, sccIndex);
		}
	}
}

int main(void) {
  fastio;

  for (int n, m; std::cin >> n >> m;) {
	int graphSize = 2 * n;
	std::vector<std::vector<int>> graph(graphSize + 1);
	std::vector<std::vector<int>> graphT(graphSize + 1);
	std::vector<bool> visited(graphSize + 1, false);
	while (m--) {
		int a, b;
		std::cin >> a >> b;
		a += n;
		b += n;
		int notA = 2 * n - a;
		int notB = 2 * n - b;
		graph[notA].push_back(b);
		graphT[b].push_back(notA);
		graph[notB].push_back(a);
		graphT[a].push_back(notB);
	}
	graph[n - 1].push_back(n + 1);
	graphT[n + 1].push_back(n - 1);

	std::stack<int> s;
	for (int i = 0; i <= graphSize; ++i) {
		if (!visited[i] && i != n) {
			dfs1(i, graph, visited, s);
		}
	}

	int sccIndex = 1;
	std::vector<int> scc(graphSize + 1);
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		if (scc[node] == 0) {
			dfs2(node, graphT, scc, sccIndex);
			sccIndex++;
		}
	}

	bool flag = true;
	for (int i = n + 1; i <= graphSize; ++i) {
		int j = 2 * n - i;
		if (scc[i]==scc[j]) {
			flag = false;
			break;
		}
	}

	if (flag) {
		std::cout << "yes\n";
	} else {
		std::cout << "no\n";
	}
  }

  return 0;
}