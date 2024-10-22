#include <algorithm>
#include <iostream>

#define MAX (20)

int WIDTH;
int HEIGHT;
int MAX_DEPTH = 0;
char BOARD[MAX][MAX];
bool VISITED_CHAR[26];
const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> HEIGHT >> WIDTH;
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      std::cin >> BOARD[i][j];
    }
  }
}

void dfs(int y, int x, int depth) {

  MAX_DEPTH = std::max(depth, MAX_DEPTH);

  VISITED_CHAR[BOARD[y][x] - 'A'] = true;
  for (int i = 0; i < 4; ++i) {
    int ny = y + DY[i];
    int nx = x + DX[i];
    if (!(ny >= 0 && ny < HEIGHT))
      continue;
    if (!(nx >= 0 && nx < WIDTH))
      continue;
    if (VISITED_CHAR[BOARD[ny][nx] - 'A'])
      continue;
    dfs(ny, nx, depth + 1);
  }
  VISITED_CHAR[BOARD[y][x] - 'A'] = false;
}

void solve() {
  dfs(0, 0, 1);
  std::cout << MAX_DEPTH;
}

int main(void) {
  input();
  solve();
  return 0;
}