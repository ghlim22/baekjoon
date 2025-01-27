#include <cstdio>
#include <queue>

typedef std::pair<int, int> pii_t;

int visited[1000001];
int F, S, G, U, D;

int bfs(int cur) {
  std::queue<pii_t> q;

  visited[cur] = true;
  q.push(std::make_pair(cur, 0));
  while (!q.empty()) {
    int floor = q.front().first;
    int cost = q.front().second;
    q.pop();
    if (floor == G) {
      return cost;
    }
    int down = floor - D;
    if (down >= 1 && !visited[down]) {
      visited[down] = true;
      q.push(std::make_pair(down, cost + 1));
    }
    int up = floor + U;
    if (up <= F && !visited[up]) {
      visited[up] = true;
      q.push(std::make_pair(up, cost + 1));
    }
  }
  return -1;
}

int main(void) {
  std::scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
  int ret = bfs(S);
  if (ret == -1) {
    std::printf("use the stairs\n");
  } else {
    std::printf("%d\n", ret);
  }
  return 0;
}