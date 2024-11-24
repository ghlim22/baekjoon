#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>

#define LEFT 0
#define UP 1
#define DOWN 2
#define RIGHT 3

struct pos {
  int y;
  int x;
};

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};
int N, M;
char B[30][30];
bool V[30][30];
int ANSWER;

bool check(const pos &p, int d) {
  int ny = p.y + DY[d];
  int nx = p.x + DX[d];
  if (!(ny >= 0 && ny < N))
    return false;
  if (!(nx >= 0 && nx < M))
    return false;
  if (V[ny][nx])
    return false;
  if (B[ny][nx] == '*')
    return false;
  return true;
}

void search(const pos &p, int d, int cost, int remainder) {
  V[p.y][p.x] = true;
  remainder--;

  if (remainder == 0) {
    ANSWER = std::min(ANSWER, cost);
    V[p.y][p.x] = false;
    return;
  }

  if (d != -1 && check(p, d)) {
    search(pos{.y = p.y + DY[d], .x = p.x + DX[d]}, d, cost, remainder);
  } else {
    for (int i = 0; i < 4; ++i) {
      if (i == d)
        continue;
      if (!check(p, i))
        continue;
      search(pos{.y = p.y + DY[i], .x = p.x + DX[i]}, i, cost + 1, remainder);
    }
  }

  V[p.y][p.x] = false;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  for (int t = 1; (std::cin >> N >> M); ++t) {
    std::queue<pos> q;

    for (int i = 0; i < N; ++i) {
      std::string line;
      std::cin >> line;
      for (int j = 0; j < M; ++j) {
        B[i][j] = line[j];
        if (B[i][j] == '.') {
          q.push(pos{.y = i, .x = j});
        }
      }
    }

    ANSWER = INT_MAX;
    int remainder = q.size();
    while (!q.empty()) {
      search(pos{.y = q.front().y, .x = q.front().x}, -1, 0, remainder);
      q.pop();
    }
    if (ANSWER == INT_MAX) {
      ANSWER = -1;
    }
    std::cout << "Case " << t << ": " << ANSWER << "\n";
  }

  return 0;
}