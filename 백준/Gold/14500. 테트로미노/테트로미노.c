#include <stdio.h>
#define MAX (500)

int board[MAX][MAX];
int visited[MAX][MAX];

const int DY[4] = {-1, 0, 0, 1};
const int DX[4] = {0, 1, -1, 0};

int ans = 0;
int n;
int m;

int max(int a, int b)
{
  if (a > b) {
    return a;
  }
  return b;
}

void find(int y, int x, int sum, int dep) {
  if (dep == 4) {
    ans = max(ans, sum);
    return;
  }

  visited[y][x] = 1;


  /* ㅏ 모양 테트로미노 */
  if (dep == 2) {
    int largest = 0;
    int second = 0;

    for (int i = 0; i < 4; ++i) {
      const int ny = y + DY[i];
      const int nx = x + DX[i];

      if (!(ny >= 0 && ny < n)) {
        continue;
      }
      if (!(nx >= 0 && nx < m)) {
        continue;
      }
      if (visited[ny][nx]) {
        continue;
      }

      if (board[ny][nx] > largest) {
        second = largest;
        largest = board[ny][nx];
      } else if (board[ny][nx] > second) {
        second = board[ny][nx];
      }
    }

    if (largest > 0 && second > 0) {
      ans = max(ans, sum + largest + second);
    }
  }

  /* ㅡ ㅁ ㄴ ㄱㄴ */
  for (int i = 0; i < 4; ++i) {
    const int ny = y + DY[i];
    const int nx = x + DX[i];

    if (!(ny >= 0 && ny < n)) {
      continue;
    }
    if (!(nx >= 0 && nx < m)) {
      continue;
    }
    if (visited[ny][nx]) {
      continue;
    }
    find(ny, nx, sum + board[ny][nx], dep + 1);
  }

  visited[y][x] = 0;
}

int main(void) {

  /* Input */
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &board[i][j]);
    }
  }

  /* Solve */
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      find(i, j, board[i][j], 1);
    }
  }

  printf("%d\n", ans);

  return 0;
}
