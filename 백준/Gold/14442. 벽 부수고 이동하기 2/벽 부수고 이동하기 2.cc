#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>

#define MAX (1000)

struct info {
  int r;
  int c;
  int broken_walls;
  int distance;
};

int g_height;
int g_width;
int g_k;
int g_board[MAX][MAX];
int g_broken_walls[MAX][MAX]; /* 부순 벽의 개수를 저장한다. */
const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

int solve(void) {
  std::queue<info> q;
  info origin = {.r = 0, .c = 0, .broken_walls = 0, .distance = 1};

  std::fill(&g_broken_walls[0][0], &g_broken_walls[0][0] + MAX * MAX, INT_MAX);

  g_broken_walls[0][0] = 0;
  q.push(origin);

  while (q.empty() == false) {
    info cur = q.front();
    q.pop();

    if (cur.r == g_height - 1 && cur.c == g_width - 1) {
      return cur.distance;
    }

    for (int i = 0; i < 4; ++i) {
      int nr = cur.r + DY[i];
      int nc = cur.c + DX[i];
      int nw = cur.broken_walls;
      int nd = cur.distance + 1;

      if (!(nr >= 0 && nr < g_height && nc >= 0 && nc < g_width)) {
        continue;
      }

      if (g_board[nr][nc] == 1) {
        if (nw < g_k)
          ++nw;
        else
          continue;
      }

      /* 새로운 경로는 기존 경로보다 항상 이동 거리가 같거나 더 길다.
        이 상황에서 새로운 경로의 부순 벽의 개수가 기존 경로의 부순 벽의 개수
        이상이라면 새로운 경로를 폐기한다. 새로운 경로가 기존 경로보다 유리할 수
        없기 때문이다.*/
      if (g_broken_walls[nr][nc] <= nw) {
        continue;
      }

      info next = {.r = nr, .c = nc, .broken_walls = nw, .distance = nd};
      g_broken_walls[nr][nc] = nw;
      q.push(next);
    }
  }

  return -1;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> g_height >> g_width >> g_k;

  for (int i = 0; i < g_height; i++) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < g_width; j++) {
      g_board[i][j] = s[j] - '0';
    }
  }

  std::cout << solve();

  return 0;
}