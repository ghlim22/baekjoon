#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

void dfs1(int node, std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::stack<int> &stk) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	for (int next : graph[node]) {
		if (!visited[next]) {
			dfs1(next, graph, visited, stk);
		}
	}
	stk.push(node);
}

void dfs2(int node, std::vector<std::vector<int>> &graphT, std::vector<bool> &visited, std::vector<int> &scc, std::vector<int> &sccIndex, std::vector<std::vector<int>> &sccGraph, int sccNum) {
	if (visited[node]) {
		return;
	}

	visited[node] = true;
	scc.push_back(node);
	sccIndex[node] = sccNum;
	for (int next : graphT[node]) {
		if (!visited[next]) {
			dfs2(next, graphT, visited, scc, sccIndex, sccGraph, sccNum);
		} else if (sccIndex[next] != sccIndex[node]) {
			sccGraph[sccIndex[next]][sccIndex[node]] = 1;
		}
	}
}

int main(void) {
  fastio;

  int t;
  std::cin >> t;
  while (t--) {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> graph(n);
	std::vector<std::vector<int>> graphT(n);
	for (int i = 0; i < n; ++i) {
		std::string l;
		std::cin >> l;
		for (int j = 0; j < n; ++j) {
			if (l[j] == '1') {
				graph[i].push_back(j);
				graphT[j].push_back(i);
			}
		}
	}

	std::vector<bool> visited(n);
	std::stack<int> stk;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs1(i, graph, visited, stk);
		}
	}

	std::vector<std::vector<int>> sccs;
	std::vector<int> sccIndex(n);
	std::vector<std::vector<int>> sccGraph;
	std::fill(visited.begin(), visited.end(), false);
	while (stk.size()) {
		int node = stk.top();
		stk.pop();

		if (!visited[node]) {
			int sccNum = sccs.size();
			std::vector<int> scc;
			dfs2(node, graphT, visited, scc, sccIndex, sccGraph, sccNum);
			sccs.push_back(scc);	
			sccGraph.push_back(std::vector<int>(n));
		}
	}

	// 각 scc의 내부에 있는 도시들끼리 연결
	std::vector<pii_t> edges;
	for (auto &v : sccs) {
		if (v.size() == 1) {
			continue;
		}
		for (int i = 0; i < v.size() - 1; ++i) {
			edges.push_back({v[i], v[i + 1]});
		}
		edges.push_back({v[v.size() - 1], v[0]});
	}

	// 불필요한 SCC간 도로(외부 간선)을 제거한다.
	// 플로이드-워셜 알고리즘 응용.
	for (int k = 0; k < sccGraph.size(); ++k) {
		for (int i = 0; i < sccGraph.size(); ++i) {
			for (int j = 0; j < sccGraph.size(); ++j) {
				if (i == j || j == k || i == k) {
					continue;
				}
				if (sccGraph[i][k] && sccGraph[k][j] && sccGraph[i][j]) {
					sccGraph[i][j] = 0;
				}
			}
		}
	}

	// 외부 도로 추가
	for (int i = 0; i < sccGraph.size(); ++i) {
		for (int j = 0; j < sccGraph.size(); ++j) {
			if (sccGraph[i][j])
				edges.push_back({sccs[i].front(), sccs[j].front()});
		}
	}

	// 도로 출력.
	std::cout << edges.size() << '\n';
	for (auto &[p1, p2] : edges) {
		std::cout << p1 + 1 << ' ' << p2 + 1 << '\n';
	}
	std::cout << '\n';
  }

  return 0;
}