#include <algorithm>
#include <codecvt>
#include <iostream>
#include <queue>
#include <vector>

#define MAX (100000)

typedef std::vector<int> vi;

std::vector<vi> graph(MAX + 1);
std::vector<int> order(MAX + 1);
std::vector<bool> visited(MAX + 1);
std::queue<int> route;
int n;

bool compare(const int &a, const int &b) { return order[a] < order[b]; }

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  /* 주어진 탐색 경로와 각 정점의 등장 순서를 저장한다. */
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    route.push(a);
    order[a] = i;
  }
}

void solve() {
  if (route.front() != 1) {
    std::cout << 0;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    std::sort(graph[i].begin(), graph[i].end(), compare);
  }

  std::queue<int> q;
  q.push(1);
  visited[1] = true;
  route.pop();
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();

    for (int adj : graph[cur]) {
      if (visited[adj])
        continue;
      if (adj != route.front())
        goto PRINT;
      visited[adj] = true;
      q.push(adj);
      route.pop();
    }
  }

PRINT:
  if (q.empty())
    std::cout << 1;
  else
    std::cout << 0;
}

int main(void) {
  input();
  solve();
  return 0;
}