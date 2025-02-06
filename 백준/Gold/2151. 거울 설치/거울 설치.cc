#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

#define NONE (-1)

enum DIRECTION {
  NORTH,
  SOUTH,
  WEST,
  EAST,
};

typedef std::pair<int, int> pii_t;

struct coord {
  int y;
  int x;
  DIRECTION dir;
};

const int d4y[4] = {-1, 1, 0, 0};
const int d4x[4] = {0, 0, -1, 1};
const int d8y[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int d8x[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

int N;
char map[50][50];
int v[50][50][4];
std::vector<coord> doors;

void input() {
  fastio;
  std::cin >> N;
  for (int y = 0; y < N; ++y) {
    std::string line;
    std::cin >> line;
    for (int x = 0; x < N; ++x) {
      map[y][x] = line[x];
      if (map[y][x] == '#') {
        coord c = {.y = y, .x = x, .dir = NORTH};
        doors.push_back(c);
      }
    }
  }
}

int solve() {
  // Init
  std::memset(v, NONE, sizeof(v));
  std::queue<coord> q;
  for (int i = 0; i < 4; ++i) {
    coord n = {.y = doors[0].y, .x = doors[0].x, .dir = (enum DIRECTION)i};
    v[n.y][n.x][n.dir] = 0;
    q.push(n);
  }

  int answer = INT_MAX;
  while (!q.empty()) {
    coord c = q.front();
    q.pop();

    if (c.y == doors[1].y && c.x == doors[1].x) {
      answer = std::min(answer, v[c.y][c.x][c.dir]);
      continue;
    }

    // put a mirror
    if (map[c.y][c.x] == '!') {
      enum DIRECTION mirror[2];
      switch (c.dir) {
      case NORTH:
      case SOUTH:
        mirror[0] = WEST;
        mirror[1] = EAST;
        break;
      case EAST:
      case WEST:
        mirror[0] = NORTH;
        mirror[1] = SOUTH;
        break;
      default:
        break;
      }

      for (int i = 0; i < 2; ++i) {
        coord n = c;
        n.dir = mirror[i];
        if (v[n.y][n.x][n.dir] != -1 &&
            v[n.y][n.x][n.dir] <= v[c.y][c.x][c.dir] + 1)
          continue;
        v[n.y][n.x][n.dir] = v[c.y][c.x][c.dir] + 1;
        q.push(n);
      }
    }

    // go straight
    do {
      coord n = c;
      n.y += d4y[n.dir];
      n.x += d4x[n.dir];

      if (!(n.y >= 0 && n.y < N && n.x >= 0 && n.x < N))
        break;
      if (v[n.y][n.x][n.dir] != -1 && v[n.y][n.x][n.dir] <= v[c.y][c.x][c.dir])
        break;
      if (map[n.y][n.x] == '*')
        break;

      v[n.y][n.x][n.dir] = v[c.y][c.x][c.dir];
      q.push(n);
    } while (false);
  }

  return answer;
}

int main(void) {
  input();
  std::cout << solve() << std::endl;

  return 0;
}