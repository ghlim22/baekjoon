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

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> graphT;
std::vector<bool> visited;
std::stack<int> stk;
std::vector<int> sccIndex;
std::vector<bool> sccSyncable;
int n;
int m;

void dfs1(int node) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	for (int adj : graph[node]) {
		if (visited[adj]) {
			continue;
		}
		dfs1(adj);
	}
	stk.push(node);
}

void dfs2(int node, int scc) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	sccIndex[node] = scc;
	for (int adj : graphT[node]) {
		if (!visited[adj]) {
			dfs2(adj, scc);
		} else if (sccIndex[adj] != scc) {
			sccSyncable[sccIndex[adj]] = false;
		}
	}
}

int main(void) {
  fastio;
  while (std::cin >> n >> m) {
	graph = std::vector<std::vector<int>>(n + 1);
	graphT = std::vector<std::vector<int>>(n + 1);
	visited = std::vector<bool>(n + 1);
	stk = std::stack<int>();
	while (m--) {
		int v, w;
		std::cin >> v >> w;
		graph[v].push_back(w);
		graphT[w].push_back(v);
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs1(i);
		}
	}

	int scc = 0;
	sccIndex = std::vector<int>(n + 1);
	sccSyncable = std::vector<bool>(n + 1, true);
	std::fill(visited.begin(), visited.end(), false);
	while (stk.size()) {
		int node = stk.top();
		stk.pop();
		if (!visited[node]) {
			dfs2(node, scc++);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (sccSyncable[sccIndex[i]]) {
			std::cout << i << ' ';
		}
	}
	std::cout << std::endl;
  }

  return 0;
}