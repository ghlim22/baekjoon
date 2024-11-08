#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

struct pos {
  int y;
  int x;
};

enum dir { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 };

const int DY[4] = {0, 1, 0, -1};
const int DX[4] = {-1, 0, 1, 0};

char MAP[100][100];
bool V[100][100][4];
int W;
int H;
std::vector<pos> END_POINTS;

bool operator==(const pos &lhs, const pos &rhs) {
  return (lhs.y == rhs.y && lhs.x == rhs.x);
}

void input(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> W >> H;
  for (int i = 0; i < H; ++i) {
    std::string line;
    std::cin >> line;
    for (int j = 0; j < W; ++j) {
      MAP[i][j] = line[j];
      if (MAP[i][j] == 'C') {
        END_POINTS.push_back(pos{.y = i, .x = j});
      }
    }
  }
}

bool check_range(const pos &p) {
  return (p.y >= 0 && p.y < H && p.x >= 0 && p.x < W);
}

int solve(void) {
  std::queue<pos> q;

  /* Setup */
  pos s = END_POINTS.front();
  for (int i = 0; i < 4; ++i) {
    V[s.y][s.x][i] = true;
    pos n = {.y = s.y + DY[i], .x = s.x + DX[i]};
    while (check_range(n)) {
      if (MAP[n.y][n.x] == '*')
        break;
      V[n.y][n.x][i] = true;
      q.push(n);
      if (MAP[n.y][n.x] == 'C') {
        return 0;
      }
      n.y += DY[i];
      n.x += DX[i];
    }
  }

  for (int cost = 0; !q.empty(); ++cost) {
    int qsize = q.size();
    while (qsize--) {
      pos cur = q.front();
      q.pop();

      if (cur == END_POINTS.back())
        return cost;

      for (int i = 0; i < 4; ++i) {
        if (!V[cur.y][cur.x][i])
          continue;

        // 직각 방향 거울 설치
        for (int j = 0; j < 4; ++j) {
          if (i == j || std::abs(i - j) == 2)
            continue;
          pos n = {.y = cur.y, .x = cur.x};
          while (check_range(n)) {
            if (MAP[n.y][n.x] == '*')
              break;
            if (V[n.y][n.x][j])
              break;
            V[n.y][n.x][j] = true;
            q.push(n);
            n.y += DY[j];
            n.x += DX[j];
          }
        }
      }
    }
  }
  return -1;
}

int main(void) {
  input();
  std::cout << solve();
  return 0;
}