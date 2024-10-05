#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define MAX (3000)

typedef std::vector<int> vi;
typedef std::pair<int, int> pii;

std::vector<vi> graph(MAX + 1);
bool visited[MAX + 1];
bool loop[MAX + 1];
int prev[MAX + 1];
int distance[MAX + 1];
int n;

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

/* DFS */
void find_cycle() {
  std::stack<int> stk; /* node # */

  stk.push(1);
  prev[1] = -1;
  while (!stk.empty()) {
    int cur = stk.top();
    stk.pop();
    if (visited[cur])
      continue;
    visited[cur] = true;
    for (int adj : graph[cur]) {
      if (adj == prev[cur])
        continue;
      if (visited[adj]) { /* Found a cycle */
		loop[adj] = true;
        do {
          loop[cur] = true;
          cur = prev[cur];
        } while (cur != adj);

        return;
      }
      prev[adj] = cur;
      stk.push(adj);
    }
  }
}

void calculate_distance() {
  memset(visited, 0, sizeof(visited));
  for (int i = 1; i <= n; ++i) {
    if (visited[i])
      continue;
    if (!loop[i])
      continue;

    std::queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int adj : graph[cur]) {
        if (loop[adj])
          continue;
        if (visited[adj])
          continue;
        visited[adj] = true;
        distance[adj] = distance[cur] + 1;
        q.push(adj);
      }
    }
  }
}

void solve() {
  find_cycle();
  calculate_distance();
  for (int i = 1; i <= n; ++i) {
    std::cout << distance[i];
    if (i < n)
      std::cout << ' ';
  }
}

int main(void) {
  input();
  solve();
  return 0;
}
