#include <algorithm>
#include <iostream>
#include <utility>
#include <stack>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

std::vector<int> g[20001];
std::vector<int> gT[20001];
std::vector<bool> v(20001);
std::vector<int> scc(20001);

void dfs(int node, std::stack<int> &searched) {
	v[node] = true;
	for (int adj : g[node]) {
		if (!v[adj]) {
			dfs(adj, searched);
		}
	}
	searched.push(node);
}

void dfs2(int node, int sccIndex) {
	v[node] = true;
	scc[node] = sccIndex;
	for (int adj : gT[node]) {
		if (!v[adj]) {
			dfs2(adj, sccIndex);
		}
	}
}

int main(void) {
  fastio;

  int n, m;
  std::cin >> n >> m;
  
  while (m--) {
	int x, y;
	std::cin >> x >> y;
	
	g[-x + n].push_back(y + n);
	g[-y + n].push_back(x + n);

	gT[y + n].push_back(-x + n);
	gT[x + n].push_back(-y + n);
  }

  std::stack<int> searched;
  for (int i = 0; i <= 2 * n; ++i) {
	if (!v[i]) {
		dfs(i, searched);
	}
  }

  std::fill(v.begin(), v.end(), false);
  int sccIndex = 0;
  while (!searched.empty()) {
	int node = searched.top();
	searched.pop();
	if (!v[node]) {
		dfs2(node, sccIndex);
		sccIndex++;
	}
  }

  bool answer = true;
  for (int i = 0; i < n; ++i) {
	if (scc[i] == scc[2 * n - i]) {
		answer = false;
		break;
	}
  }
  std::cout << answer;

  return 0;
}