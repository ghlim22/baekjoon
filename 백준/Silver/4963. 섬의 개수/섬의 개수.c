#include <stdio.h>

#define MAX (50)

int width;
int height;
int map[MAX][MAX];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x) {
  map[y][x] = 0;
  for (int i = 0; i < 8; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (!(ny >= 0 && ny < height)) {
      continue;
    }
    if (!(nx >= 0 && nx < width)) {
      continue;
    }
    if (map[ny][nx]) {
      dfs(ny, nx);
    }
  }
}

int main(void) {
  while (1) {
    scanf("%d %d", &width, &height);

    if (width == 0 && height == 0) {
      break;
    }

    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        scanf("%d", &map[i][j]);
      }
    }

    int island_cnt = 0;
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        if (map[y][x]) {
          ++island_cnt;
          dfs(y, x);
        }
      }
    }

    printf("%d\n", island_cnt);
  }

  return 0;
}