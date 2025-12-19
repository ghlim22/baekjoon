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

typedef std::pair<int, int> pii_t;

int n, m, s, p;
std::vector<int> atm;
std::vector<std::vector<int>> g;
std::vector<std::vector<int>> gt;
std::vector<bool> visited;
std::vector<int> restaurant;
std::stack<int> stk;

std::vector<int> sccAmount;
std::vector<int> sccIndex;
std::vector<std::vector<int>> sccGraph;
std::vector<int> sccCache;

void dfs1(int node) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	for (int adj : g[node]) {
		dfs1(adj);
	}
	stk.push(node);
}

int dfs2(int node, int sccCurrentIndex) {
	if (visited[node]) {
		return 0;
	}
	int retval = atm[node];
	visited[node] = true;
	sccIndex[node] = sccCurrentIndex;
	for (int adj : gt[node]) {
		if (visited[adj] && sccIndex[adj] != sccCurrentIndex) {
			if (std::find(sccGraph[sccIndex[adj]].begin(), sccGraph[sccIndex[adj]].end(), sccCurrentIndex) == sccGraph[sccIndex[adj]].end()) {
				sccGraph[sccIndex[adj]].push_back(sccCurrentIndex);
				continue;
			}
		}
		retval += dfs2(adj, sccCurrentIndex);
	}
	return retval;
}

void dfs3(int sccNode) {
	sccCache[sccNode] = std::max(sccCache[sccNode], sccAmount[sccNode]);
	for (int adj : sccGraph[sccNode]) {
		if (sccCache[adj] < sccCache[sccNode] + sccAmount[adj]) {
			sccCache[adj] = sccCache[sccNode] + sccAmount[adj];
			dfs3(adj);
		}
	}
}

int main(void) {
  fastio;

  std::cin >> n >> m;
  atm = std::vector<int>(n+1);
  g = std::vector<std::vector<int>>(n+1);
  gt = std::vector<std::vector<int>>(n+1);
  visited = std::vector<bool>(n + 1);

  for (int i = 0; i < m; ++i) {
	int x, y;
	std::cin >> x >> y;
	g[x].push_back(y);
	gt[y].push_back(x);
  }
  for (int i = 0; i < n; ++i) {
	std::cin >> atm[i + 1];
  }
  std::cin >> s >> p;
  for (int i = 0; i < p; ++i) {
	int r;
	std::cin >> r;
	restaurant.push_back(r);
  }

  for (int i = 1; i <= n; ++i) {
	dfs1(i);
  }

  std::fill(visited.begin(), visited.end(), false);
  sccIndex = std::vector<int>(n + 1, -1);
  while (!stk.empty()) {
	int node = stk.top();
	stk.pop();
	if (!visited[node]) {
		int sccCurrentIndex = sccAmount.size();
		int amount = dfs2(node, sccCurrentIndex);
		sccAmount.push_back(amount);
		sccGraph.push_back(std::vector<int>());
	}
  }

  sccCache = std::vector<int>(sccAmount.size());
  dfs3(sccIndex[s]);

  int retval = 0;
  for (int r : restaurant) {
	retval = std::max(retval, sccCache[sccIndex[r]]);
  }
  std::cout << retval << std::endl;

  return 0;
}
