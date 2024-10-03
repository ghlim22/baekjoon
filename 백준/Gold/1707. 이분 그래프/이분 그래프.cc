#include <cstdio>
#include <stack>
#include <vector>

int main(void) {
  int k;
  int e;
  int v;

  scanf("%d", &k);
  while (k--) {
    scanf("%d %d", &v, &e);

    std::stack<int> stk;
    std::vector<int> color(v + 1, 0);
    std::vector<bool> visited(v, false);
    std::vector< std::vector<int> > graph(v + 1);

    while (e--) {
      int a, b;
      scanf("%d %d", &a, &b);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    /* DFS */
    bool possible = true;

    for (int i = 0; i < v; ++i)
      stk.push(i);

    while (!stk.empty()) {
      const int top = stk.top();
      stk.pop();
      if (visited[top])
        continue;

      visited[top] = true;
      for (int adj : graph[top]) {
        if (!visited[adj]) {
          color[adj] = color[top] ^ 1;
          stk.push(adj);
        } else if (color[adj] == color[top]) {
          possible = false;
          goto PRINT;
        }
      }
    }

  PRINT:
    printf("%s\n", possible ? "YES" : "NO");
  }

  return 0;
}