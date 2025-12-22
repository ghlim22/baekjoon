#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

void dfs1(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::stack<int> &stk, int node) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	for (int next : graph[node]) {
		dfs1(graph, visited, stk, next);
	}
	stk.push(node);	
}

int dfs2(std::vector<std::vector<int>> &graphT, std::vector<bool> &visited, int node, std::vector<int> &sccIndex, std::vector<std::vector<int>> &sccGraph, int scc) {
	visited[node] = true;
	sccIndex[node] = scc;
	int sccSize = 1;
	for (int adj : graphT[node]) {
		if (!visited[adj]) {
			sccSize += dfs2(graphT, visited, adj, sccIndex, sccGraph, scc);
		} else if (scc != sccIndex[adj]) {
			int adjScc = sccIndex[adj];
			if (std::find(sccGraph[adjScc].begin(), sccGraph[adjScc].end(), scc) == sccGraph[adjScc].end()) {
				sccGraph[adjScc].push_back(scc);
			}
		}
	}
	return sccSize;
}

int main(void) {
  fastio;

  int n, m, s, t;
  std::cin >> n >> m >> s >> t;

  std::vector<std::vector<int>> graph(n + 1);
  std::vector<std::vector<int>> graphT(n + 1);

  while (m--) {
	int a, b;
	std::cin >> a >> b;
	graph[a].push_back(b);
	graphT[b].push_back(a);
  }

  std::vector<bool> visited(n + 1);
  std::stack<int> stk;
  for (int i = 1; i <= n; ++i) {
	dfs1(graph, visited, stk, i);
  }

  std::fill(visited.begin(), visited.end(), false);
  std::vector<std::vector<int>> sccGraph;
  std::vector<int> sccIndex(n + 1);
  std::vector<int> sccSize;
  int scc = 0;

  while (!stk.empty()) {
	int node = stk.top();
	stk.pop();
	if (!visited[node]) {
		int size = dfs2(graphT, visited, node, sccIndex, sccGraph, scc);
		sccGraph.push_back(std::vector<int>());
		sccSize.push_back(size);
		scc++;
	}
  }
  
  std::vector<int> cache(scc);
  std::queue<int> q;
  std::vector<bool> inQueue(scc);
  q.push(sccIndex[s]);
  inQueue[sccIndex[s]] = true;
  cache[sccIndex[s]] = sccSize[sccIndex[s]];
  while (!q.empty()) {
	int curScc = q.front();
	q.pop();
	inQueue[curScc] = false;

	if (curScc == sccIndex[t]) {
		continue;
	}

	for (int nextScc : sccGraph[curScc]) {
		if (cache[nextScc] < cache[curScc] + sccSize[nextScc]) {
			cache[nextScc] = cache[curScc] + sccSize[nextScc];
			if (!inQueue[nextScc]) {
				inQueue[nextScc] = true;
				q.push(nextScc);
			}
		}
	}
  }

  std::cout << cache[sccIndex[t]] << std::endl;

  return 0;
}