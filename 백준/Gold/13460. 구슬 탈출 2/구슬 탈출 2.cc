#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>

#define MAX (10)

typedef std::pair<int, int> pii_t;

struct marble {
  int ry;
  int rx;
  int by;
  int bx;
  int cost;
  int dir;
} INIT;

const int DY[4] = {0, 0, -1, 1};
const int DX[4] = {-1, 1, 0, 0};

int HEIGHT;
int WIDTH;
char BOARD[MAX][MAX];
bool VISITED[MAX][MAX][MAX][MAX];

void input(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> HEIGHT >> WIDTH;
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      char c;
      std::cin >> c;
      BOARD[i][j] = c;
      if (c == 'R') {
        INIT.ry = i;
        INIT.rx = j;
        BOARD[i][j] = '.';
      } else if (c == 'B') {
        INIT.by = i;
        INIT.bx = j;
        BOARD[i][j] = '.';
      }
    }
  }
}

int bfs(void) {
  std::queue<marble> q;

  INIT.cost = 0;
  INIT.dir = -10;
  q.push(INIT);
  VISITED[INIT.ry][INIT.rx][INIT.by][INIT.bx] = true;

  while (q.empty() == false) {
    marble cur = q.front();
    q.pop();

    if (cur.cost > 10)
      break;
    if (BOARD[cur.ry][cur.rx] == 'O' && BOARD[cur.by][cur.bx] != 'O')
      return cur.cost;

    for (int i = 0; i < 4; i++) {
      if (cur.dir == i)
        continue;
      if ((cur.dir ^ i) == 1)
        continue;

      int ry = cur.ry;
      int rx = cur.rx;
      int by = cur.by;
      int bx = cur.bx;
      int rd = 0;
      int bd = 0;

      while (BOARD[ry][rx] == '.') {
        ry += DY[i];
        rx += DX[i];
        rd++;
      }
      if (BOARD[ry][rx] == '#') {
        ry -= DY[i];
        rx -= DX[i];
        rd--;
      }

      while (BOARD[by][bx] == '.') {
        by += DY[i];
        bx += DX[i];
        bd++;
      }
      if (BOARD[by][bx] == '#') {
        by -= DY[i];
        bx -= DX[i];
        bd--;
      }

      /* 두 구슬의 최종 위치가 같으면, 둘 중 더 멀리 있던 구슬을 한 칸 이전
       * 위치로 이동시킨다. */
      /* 하지만 두 구슬이 모두 구멍에 빠지는 상황이면 이동시키지 않는다. */
      /* 구멍이 빠진 것이 아닌 벽에 막혀서 움직이지 못 하게 된 상황일 때만 구슬
       * 위치를 조정한다. */
      if (ry == by && rx == bx && BOARD[ry][rx] != 'O') {
        if (rd > bd) {
          ry -= DY[i];
          rx -= DX[i];
        } else {
          by -= DY[i];
          bx -= DX[i];
        }
      }

      if (BOARD[by][bx] == 'O')
        continue;

      if (VISITED[ry][rx][by][bx])
        continue;

      VISITED[ry][rx][by][bx] = true;

      marble npos = {.ry = ry,
                     .rx = rx,
                     .by = by,
                     .bx = bx,
                     .cost = cur.cost + 1,
                     .dir = i};
      q.push(npos);
    }
  }

  return -1;
}

void solve(void) { std::cout << bfs(); }

int main(void) {
  input();
  solve();
  return 0;
}
