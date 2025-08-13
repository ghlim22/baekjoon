#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

bool visited[10001];
int counts[10001];
std::vector<std::vector<int> > graph(10001);

int dfs(int node) {
  visited[node] = true;
  int count = 1;
  for (int adj : graph[node]) {
 	if (!visited[adj]) {
     count += dfs(adj);
 	}
  }
  return count;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  for (int i = 0; i < M; ++i) {
 	int A, B;
 	std::cin >> A >> B;
    graph[B].push_back(A);
  }

  int maxCount = 0;
  for (int i = 1; i <= N; ++i) {
    int count = dfs(i);
    maxCount = std::max(maxCount, count);
    counts[i] = count;
    std::memset(visited, 0, sizeof(bool) * (N + 1));
  }

  for (int i = 1; i <= N; ++i) {
    if (counts[i] == maxCount) {
   	  std::cout << i << ' ';
 	}
  }
  std::cout << std::endl;

  return 0;
}