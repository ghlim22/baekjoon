#include <stdio.h>

#define LEN 500

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};
int R, C;
char map[LEN][LEN];

int main(void) {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j)
      scanf(" %c", &map[i][j]);
  }

  int fail_flag = 0;
  for (int y = 0; y < R; ++y) {
    for (int x = 0; x < C; ++x) {
      if (map[y][x] == 'S') {
        for (int i = 0; i < 4; ++i) {
          int ny = y + DY[i];
          int nx = x + DX[i];
          if (!(ny >= 0 && ny < R && nx >= 0 && nx < C))
            continue;
          if (map[ny][nx] == 'W') {
            fail_flag = 1;
            goto PRINT;
          }
          if (map[ny][nx] == '.') {
            map[ny][nx] = 'D';
          }
        }
      }
    }
  }

PRINT:
  if (fail_flag) {
    printf("%d\n", 0);
  } else {
    printf("%d\n", 1);
    for (int y = 0; y < R; ++y) {
      for (int x = 0; x < C; ++x) {
        printf("%c", map[y][x]);
      }
      printf("\n");
    }
  }

  return 0;
}
