#include <cstring>
#include <deque>
#include <iostream>
#include <queue>

#define MAX (8)

struct pos {
  int y;
  int x;
};

bool VISITED[MAX][MAX];
char BOARD[MAX][MAX];
std::deque<pos> WALLS;

const int DY[8] = {0, -1, 1, 0, -1, -1, 1, 1};
const int DX[8] = {-1, 0, 0, 1, -1, 1, -1, 1};

void input(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  for (int i = 0; i < MAX; ++i) {
    for (int j = 0; j < MAX; ++j) {
      std::cin >> BOARD[i][j];
      if (BOARD[i][j] == '#')
        WALLS.push_front(pos{.y = i, .x = j});
    }
  }
}

int solve(void) {
  std::queue<pos> q;

  q.push(pos{.y = MAX - 1, .x = 0});

  for (int time = 0; !q.empty(); ++time) {
    int qsize = q.size();
    while (qsize--) {
      pos cur = q.front();
      q.pop();

      if (BOARD[cur.y][cur.x] == '#')
        continue;

      if (cur.y == 0 && cur.x == MAX - 1)
        return 1;

      bool wall = false;
      bool moved = false;
      for (int i = 0; i < 8; ++i) {
        pos n = {.y = cur.y + DY[i], .x = cur.x + DX[i]};

        if (!(n.y >= 0 && n.y < MAX && n.x >= 0 && n.x < MAX))
          continue;
        if (VISITED[n.y][n.x]) {
          continue;
        }
        if (BOARD[n.y][n.x] == '#') {
          wall = true;
          continue;
        }

        moved = true;
        VISITED[n.y][n.x] = true;
        q.push(n);
      }

    //   if (!moved) {
    //     memset(VISITED, 0, sizeof(VISITED));
    //     for (int i = 0; i < 8; ++i) {
    //       pos n = {.y = cur.y + DY[i], .x = cur.x + DX[i]};

    //       if (!(n.y >= 0 && n.y < MAX && n.x >= 0 && n.x < MAX))
    //         continue;
    //       if (VISITED[n.y][n.x]) {
    //         continue;
    //       }
    //       if (BOARD[n.y][n.x] == '#') {
    //         continue;
    //       }

    //       VISITED[n.y][n.x] = true;
    //       q.push(n);
    //     }
    //   }

      if (wall)
        q.push(cur);
    }

    int wsize = WALLS.size();
    while (wsize--) {
      pos cur = WALLS.front();
      WALLS.pop_front();

      BOARD[cur.y][cur.x] = '.';

      pos n = {.y = cur.y + 1, .x = cur.x};
      if (n.y >= MAX)
        continue;

      BOARD[n.y][n.x] = '#';
      VISITED[n.y][n.x] = false;
      WALLS.push_back(n);
    }
  }

  return 0;
}

int main(void) {
  input();
  std::cout << solve();
  return 0;
}