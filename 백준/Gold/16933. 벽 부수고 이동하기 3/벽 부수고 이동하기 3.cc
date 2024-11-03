#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>

#define MAX (1000)
#define DAY (0)
#define NIGHT (1)

struct info {
  int y;
  int x;
  int cost;
  int broken_wall;
  int time;
};

int N;
int M;
int K;
int INPUT[MAX][MAX];
int W[MAX][MAX];

const int DY[4] = {0, 0, -1, 1};
const int DX[4] = {-1, 1, 0, 0};

void input(void) {
  std::cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    std::string line;
    std::cin >> line;
    for (int j = 0; j < M; ++j) {
      INPUT[i][j] = line[j] - '0';
    }
  }
}

int solve(void) {
  std::fill(&W[0][0], &W[0][0] + MAX * MAX, INT_MAX);

  int answer = INT_MAX;
  std::queue<info> q;
  info origin = {.y = 0, .x = 0, .cost = 1, .broken_wall = 0, .time = DAY};
  W[0][0] = 0;
  q.push(origin);

  while (!q.empty()) {
    info cur = q.front();
    q.pop();

    if (cur.y == N - 1 && cur.x == M - 1) {
      return cur.cost;
    }

    for (int i = 0; i < 4; ++i) {
      info n = {.y = cur.y + DY[i],
                .x = cur.x + DX[i],
                .cost = cur.cost + 1,
                .broken_wall =
                    cur.broken_wall +
                    ((cur.time == DAY && INPUT[n.y][n.x] == 1) ? 1 : 0),
                .time = cur.time ^ 1};

      if (!(n.y >= 0 && n.y < N && n.x >= 0 && n.x < M))
        continue;

      if (W[n.y][n.x] <= n.broken_wall)
        continue;

      if (INPUT[n.y][n.x] == 1) {
        if (cur.broken_wall >= K)
          continue;
        if (cur.time == NIGHT) {
          /* 이동하지 않고 낮을 기다린다. */
          n.y = cur.y;
          n.x = cur.x;
        }
      }

      W[n.y][n.x] = n.broken_wall;
      q.push(n);
    }
  }

  return -1;
}

int main(void) {
  input();
  std::cout << solve();
  return 0;
}
