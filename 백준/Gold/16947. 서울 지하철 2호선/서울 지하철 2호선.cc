#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define MAX (3000)

typedef std::vector<int> vi;
typedef std::pair<int, int> pii;

bool visited[MAX + 1];
bool loop_tmp[MAX + 1];
bool loop[MAX + 1];
int dist[MAX + 1];
std::vector<vi> graph(MAX + 1);
bool found_cycle = false;
int n;

void find_cycle(int start, int prev, int cur) {
  visited[cur] = true;
  loop_tmp[cur] = true;
  for (int adj : graph[cur]) {
    if (adj == prev) {
      continue;
    }
    if (adj == start) {
      /* Save the loop */
      found_cycle = true;
      memmove(loop, loop_tmp, sizeof(loop));
      return;
    }
    if (visited[adj]) {
      continue;
    }
    find_cycle(start, cur, adj);
  }
  loop_tmp[cur] = false;
}

void bfs(int start) {
  memset(visited, 0, sizeof(visited));

  std::queue<pii> q;
  q.push(std::make_pair(start, 0));
  while (!q.empty()) {
    pii front = q.front();
    visited[front.first] = true;
    q.pop();
    if (loop[front.first]) {
      dist[start] = front.second;
      return;
    }
    for (int adj : graph[front.first]) {
      if (visited[adj])
        continue;
      q.push(std::make_pair(adj, front.second + 1));
    }
  }
}

int main(void) {
  /* INPUT */
  std::cin.tie(NULL)->sync_with_stdio(false);

  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  /* Find a cycle */
  for (int i = 1; i <= n && !found_cycle; ++i) {
    memset(visited, 0, sizeof(visited));
    memset(loop_tmp, 0, sizeof(loop_tmp));
    find_cycle(i, i, i);
  }

  /* Calculate distances */
  for (int i = 1; i <= n; ++i) {
    if (loop[i])
      continue;
    bfs(i);
  }

  /* PRINT */
  for (int i = 1; i <= n; ++i) {
    std::cout << dist[i];
    if (i < n)
      std::cout << ' ';
  }

  return 0;
}
