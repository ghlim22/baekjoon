#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX (20)

typedef std::pair<int, int> pii_t;

struct pos {
  int y1;
  int x1;
  int y2;
  int x2;
};

char BOARD[MAX][MAX];
int WIDTH;
int HEIGHT;
pos init;
const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  init.y1 = -1;

  std::cin >> HEIGHT >> WIDTH;
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      std::cin >> BOARD[i][j];
      if (BOARD[i][j] == 'o') {
        if (init.y1 == -1) {
          init.y1 = i;
          init.x1 = j;
        } else {
          init.y2 = i;
          init.x2 = j;
        }
      }
    }
  }
}

bool is_in_range(int y, int x) {
  if (!(y >= 0 && y < HEIGHT))
    return false;
  if (!(x >= 0 && x < WIDTH))
    return false;
  return true;
}

int bfs() {
  int cost = 0;
  std::queue<pos> q;
  q.push(init);

  while (!q.empty() && cost <= 10) {
    int qsize = q.size();
    while (qsize--) {
      pos p = q.front();
      q.pop();

      if (is_in_range(p.y1, p.x1) ^ is_in_range(p.y2, p.x2))
        return cost;

      if (!is_in_range(p.y1, p.x1) && !is_in_range(p.y2, p.x2))
        continue;

      for (int i = 0; i < 4; ++i) {
        pos np = {.y1 = p.y1 + DY[i],
                  .x1 = p.x1 + DX[i],
                  .y2 = p.y2 + DY[i],
                  .x2 = p.x2 + DX[i]};

        if (is_in_range(np.y1, np.x1) &&
            BOARD[np.y1][np.x1] == '#') /* Wall */ {
          np.y1 = p.y1;
          np.x1 = p.x1;
        }

        if (is_in_range(np.y2, np.x2) &&
            BOARD[np.y2][np.x2] == '#') /* Wall */ {
          np.y2 = p.y2;
          np.x2 = p.x2;
        }

        if (np.y1 == p.y1 && np.x1 == p.x1 && np.y2 == p.y2 && np.x2 == p.x2)
          continue;

        q.push(np);
      }
    }
    cost++;
  }

  return -1;
}

void solve() {
    std::cout << bfs();
}

int main() {
  input();
  solve();
  return 0;
}