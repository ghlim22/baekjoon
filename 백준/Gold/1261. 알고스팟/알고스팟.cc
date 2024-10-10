#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

#define MAX (100)

typedef std::pair<int, int> pii_t;

int width;
int height;
int map[MAX][MAX];
int visited[MAX][MAX];
const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

void input() {
  scanf("%d %d", &width, &height);
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      scanf("%1d", &map[i][j]);
    }
  }
}

void solve() {
  memset(visited, -1, sizeof(visited));

  std::queue<pii_t> q;
  q.push(std::make_pair(0, 0));
  visited[0][0] = 0;
  while (!q.empty()) {
    const int y = q.front().first;
    const int x = q.front().second;
    q.pop();
    if (y == height - 1 && x == width - 1) {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      const int ny = y + DY[i];
      const int nx = x + DX[i];
      if (!(ny >= 0 && ny < height)) {
        continue;
      }
      if (!(nx >= 0 && nx < width)) {
        continue;
      }
      /* 인접한 위치를 아직 방문 하지 않았거나, 기존 비용보다 더 적은 비용으로
       * 방문할 수 있으면 새로 방문한다. */
      const int cost = visited[y][x] + (map[ny][nx] == 1);
      if (visited[ny][nx] == -1 || visited[ny][nx] > cost) {
        visited[ny][nx] = cost;
        q.push(std::make_pair(ny, nx));
      }
    }
  }

  printf("%d\n", visited[height - 1][width - 1]);
}

int main(void) {
  input();
  solve();
  return 0;
}