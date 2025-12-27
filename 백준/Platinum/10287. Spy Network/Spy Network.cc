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

const int d4y[4] = {0, -1, 1, 0};
const int d4x[4] = {-1, 0, 0, 1};
const int d8y[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int d8x[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

void dfs1(int current, std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::stack<int> &stk) {
	if (visited[current]) {
		return;
	}
	visited[current] = true;
	for (int next : graph[current]) {
		dfs1(next, graph, visited, stk);
	}
	stk.push(current);
}

void dfs2(int current, std::vector<std::vector<int>> &graphT, std::vector<int> &scc, std::vector<int> &sccIndex, std::vector<std::vector<int>> &sccGraph, int curSccNo) {
	sccIndex[current] = curSccNo;
	scc.push_back(current);
	for (int next : graphT[current]) {
		if (sccIndex[next] == -1) {
			dfs2(next, graphT, scc, sccIndex, sccGraph, curSccNo);
		} else if (sccIndex[next] != curSccNo && std::find(sccGraph[sccIndex[next]].begin(), sccGraph[sccIndex[next]].end(), curSccNo) == sccGraph[sccIndex[next]].end()) {
			sccGraph[sccIndex[next]].push_back(curSccNo);
		}
	}
}

long gcd(long x, long y) {
	if (y > x) {
		std::swap(x, y);
	}
	while (y) {
		long tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main(void) {
  fastio;

  int t;
  std::cin >> t;
  while (t--) {
	long n, m, l;
	std::cin >> n >> m >> l;

	std::vector<std::vector<int>> graph(n + 1);
	std::vector<std::vector<int>> graphT(n + 1);
	std::vector<long> report(n + 1);
	std::vector<bool> visited(n + 1);
	std::stack<int> stk;

	while (m--) {
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		graphT[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> report[i];
		dfs1(i, graph, visited, stk);
	}
	
	std::vector<std::vector<int>> sccs;
	std::vector<int> sccIndex(n + 1, -1);
	std::vector<long> sccReport;
	std::vector<std::vector<int>> sccGraph;

	while (stk.size()) {
		int current = stk.top();
		stk.pop();
		if (sccIndex[current] == -1) {
			std::vector<int> scc;
			sccGraph.push_back(std::vector<int>());
			dfs2(current, graphT, scc, sccIndex, sccGraph, sccs.size());
			sccs.push_back(scc);
		}
	}

	for (auto &scc : sccs) {
		long finalReport = 0;
		for (long i : scc) {
			finalReport = gcd(report[i], finalReport);
		}
		sccReport.push_back(finalReport);
	}

	long answer = 0;
	for (int i = 0; i < sccGraph.size(); ++i) {
		for (int j : sccGraph[i]) {
			sccReport[j] = gcd(sccReport[j], sccReport[i]);
		}
		if (l == sccReport[i]) {
			answer += sccs[i].size();
		}
	}
	std::cout << answer << '\n';
  }

  return 0;
}