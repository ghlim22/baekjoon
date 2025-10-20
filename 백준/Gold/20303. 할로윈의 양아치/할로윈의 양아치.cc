#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

std::vector<int> graph[30001];
std::vector<bool> visited(30001);
std::vector<int> candy(30001);
std::vector<int> cache(3000);
int N, M, K;

pii_t bfs(int node) {
	std::queue<int> Q;
	int candies = 0;
	int children = 0;

	visited[node] = true;
	Q.push(node);
	
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		candies += candy[curr];
		children += 1;

		for (int fr : graph[curr]) {
			if (!visited[fr])  {
				visited[fr] = true;
				Q.push(fr);
			}
		}
	}
	
	return {candies, children};
}

int main(void) {
  fastio;

  std::cin >> N >> M >> K;

  for (int i = 1; i <= N; ++i) {
	std::cin >> candy[i];
  }

  for (int i = 0; i < M; ++i) {
	int a, b;
	std::cin >> a >> b;
	graph[a].push_back(b);
	graph[b].push_back(a);
  }

  std::vector<pii_t> chunk; // <candies, children>

  for (int i = 1; i <= N; ++i) {
	if (!visited[i]) {
		chunk.push_back(bfs(i));
	}
  }

  for (int i = 0; i < chunk.size(); ++i) {
	for (int j = K - 1; j > 0; --j) {
		int k = j - chunk[i].second;
		if (k < 0) break;
		cache[j] = std::max(cache[j], cache[k] + chunk[i].first);
	}
  }

  std::cout << cache[K - 1] << std::endl;

  return 0;
}