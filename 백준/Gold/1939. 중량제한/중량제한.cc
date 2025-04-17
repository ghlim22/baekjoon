#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> pii_t;
typedef std::vector<std::vector<pii_t>> BridgeInfo;

bool VISITED[100001];

bool bfs(const BridgeInfo &v, int orig, int dest, int limit) {
  std::memset(VISITED, 0, sizeof(VISITED));

  std::queue<int> q;
  q.push(orig);
  VISITED[orig] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == dest) {
      return true;
    }

    for (auto p : v[cur]) {
      if (VISITED[p.first])
        continue;
      if (p.second < limit)
        continue;
      VISITED[p.first] = true;
      q.push(p.first);
    }
  }

  return false;
}

int main() {
  int n, m, orig, dest;
  int lo = 1;
  int hi = 1;

  std::cin >> n >> m;

  BridgeInfo bridges(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    bridges[a].push_back({b, c});
    bridges[b].push_back({a, c});
    hi = std::max(hi, c);
  }
  std::cin >> orig >> dest;

  int answer = 0;
  while (lo <= hi) {
    int mid = (hi - lo) / 2 + lo;
    if (bfs(bridges, orig, dest, mid)) {
      answer = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  std::cout << answer;

  return 0;
}