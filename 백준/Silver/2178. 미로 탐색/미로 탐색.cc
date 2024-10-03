#include <cstdio>
#include <queue>
#include <utility>

#define MAX (100)

typedef std::pair<int, int> pii_t;

int cost[MAX + 1][MAX + 1];
int map[MAX + 1][MAX + 1];
const int DX[4] = {-1, 0, 0, 1};
const int DY[4] = {0, -1, 1, 0};

int main(void) {
  int n, m;
  std::scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      scanf("%1d", &map[i][j]);
  }

  std::queue<pii_t> q;
  q.push(std::make_pair(1, 1));
  cost[1][1] = 1;
  while (!q.empty()) {
    pii_t front = q.front();
    q.pop();
    int updated_cost = cost[front.first][front.second] + 1;
    for (int i = 0; i < 4; ++i) {
      int ny = front.first + DY[i];
      int nx = front.second + DX[i];
      if (!(ny >= 1 && ny <= n))
        continue;
      if (!(nx >= 0 && nx <= m))
        continue;
      if (map[ny][nx] == 0)
        continue;
      if (cost[ny][nx] != 0)
        continue;
      cost[ny][nx] = updated_cost;
      q.push(std::make_pair(ny, nx));
    }
  }

  printf("%d\n", cost[n][m]);

  return 0;
}