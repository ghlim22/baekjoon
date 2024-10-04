#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#define MAX (50)

typedef std::pair<int, int> pii_t;

const int DY[4] = {
    -1,
    0,
    0,
    1,
};
const int DX[4] = {
    0,
    -1,
    1,
    0,
};
char board[MAX][MAX];
bool visited[MAX][MAX];
int width;
int height;
int sy;
int sx;
char sc;

void dfs(int dep, int y, int x) {
  visited[y][x] = true;
  for (int i = 0; i < 4; ++i) {
    int ny = y + DY[i];
    int nx = x + DX[i];
    if (!(ny >= 0 && ny < height))
      continue;
    if (!(nx >= 0 && nx < width))
      continue;
    if (board[ny][nx] != sc)
      continue;
    if (visited[ny][nx]) {
      if (dep >= 3 && ny == sy && nx == sx) {
        printf("Yes");
        exit(0);
      }
      continue;
    }
    dfs(dep + 1, ny, nx);
  }
  visited[y][x] = false;
}

int main(void) {

  scanf("%d %d", &height, &width);
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j)
      scanf(" %c", &board[i][j]);
  }

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      memset(visited, 0, sizeof(visited));
      sy = i;
      sx = j;
      sc = board[i][j];
      dfs(0, sy, sx);
    }
  }

  printf("No");

  return 0;
}