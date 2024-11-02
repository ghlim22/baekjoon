#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#define MAX (1000)

struct info {
  int r;
  int c;
  int wall;
  int dist;
};

struct cost {
  int dist;
  int wall;
};

int g_height;
int g_width;
int g_k;
int g_board[MAX][MAX];
int g_visited[MAX][MAX][11];
cost g_cost[MAX][MAX];
const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

int solve(void) {
  std::queue<info> q;
  info origin = {.r = 0, .c = 0, .wall = g_k, .dist = 1};
  g_visited[origin.r][origin.c][origin.wall] = 1;
  q.push(origin);

  while (q.empty() == false) {
    info cur = q.front();
    q.pop();

    if (cur.r == g_height - 1 && cur.c == g_width - 1) {
      return cur.dist;
    }

    for (int i = 0; i < 4; i++) {
      int nr = cur.r + DY[i];
      int nc = cur.c + DX[i];
      int nw = cur.wall;
      int nd = cur.dist + 1;

      if (!(nr >= 0 && nr < g_height && nc >= 0 && nc < g_width)) {
        continue;
      }
      if (g_board[nr][nc] == 1) {
        if (nw > 0)
          nw--;
        else
          continue;
      }
      if (g_visited[nr][nc][nw] != 0) {
        continue;
      }

      bool flag = false;
      for (int j = nw; j <= 10; j++) {
        int dist = g_visited[nr][nc][j];
        if (dist != 0 && dist < nd) {
          flag = true;
          break;
        }
      }
      if (flag)
        continue;

      info nxt = {.r = nr, .c = nc, .wall = nw, .dist = nd};
      g_visited[nr][nc][nw] = nd;
      q.push(nxt);
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