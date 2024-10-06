#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX (100000)

typedef std::vector<int> vi;

int N;
std::queue<int> route;
std::vector<vi> graph(MAX + 1);
int order[MAX + 1];

bool compare(const int &a, const int &b) { return order[a] > order[b]; }

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 0; i < N; ++i) {
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

  /* 각 정점을 등장 순서대로 방문하도록 정렬 */
  for (int i = 1; i <= N; ++i) {
    std::sort(graph[i].begin(), graph[i].end(), compare);
  }

  std::vector<bool> visited(N + 1, false);
  std::stack<int> stk;

  stk.push(1);
  while (!stk.empty() && !route.empty()) {
    const int top = stk.top();
    stk.pop();
    if (visited[top]) {
      continue;
    }
    visited[top] = true;
    if (top != route.front()) {
      std::cout << 0;
      return;
    }
    route.pop();
    for (int adj : graph[top]) {
      if (!visited[adj]) {
        stk.push(adj);
      }
    }
  }

  std::cout << 1;
}

int main(void) {
  input();
  solve();
  return 0;
}