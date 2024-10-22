#include <algorithm>
#include <iostream>

#define MAX (20)

int WIDTH;
int HEIGHT;
int MAX_DEPTH = 0;

int BOARD[MAX][MAX];
int CACHE[MAX][MAX];

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> HEIGHT >> WIDTH;
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      char c;
      std::cin >> c;
      BOARD[i][j] = c - 'A';
    }
  }
}

void dfs(int y, int x, int depth, int history) {
  if (CACHE[y][x] == history)
    return;

  MAX_DEPTH = std::max(depth, MAX_DEPTH);

  CACHE[y][x] = history;

  for (int i = 0; i < 4; ++i) {
    /* Check range */
    int ny = y + DY[i];
    int nx = x + DX[i];
    if (!(ny >= 0 && ny < HEIGHT))
      continue;
    if (!(nx >= 0 && nx < WIDTH))
      continue;

    if ((history & (1 << BOARD[ny][nx])) == 0)
      dfs(ny, nx, depth + 1, history | (1 << BOARD[ny][nx]));
  }
}

void solve() {
  dfs(0, 0, 1, (1 << BOARD[0][0]));
  std::cout << MAX_DEPTH;
}

int main(void) {
  input();
  solve();
  return 0;
}