#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define EMPTY -1
#define OBSTACLE -2
#define STARTING -3

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

struct coord {
  coord() : _y(0), _x(0) {}
  coord(int y, int x) : _y(y), _x(x) {}
  bool operator==(const coord &other) {
    return _y == other._y && _x == other._x;
  }
  bool operator!=(const coord &other) {
    return !(_y == other._y && _x == other._x);
  }
  bool inRange(int w, int h) {
    return (_y >= 0 && _y < h && _x >= 0 && _x < w);
  }
  int _y;
  int _x;
};

typedef std::pair<int, int> pii_t;

const int d4y[4] = {0, -1, 1, 0};
const int d4x[4] = {-1, 0, 0, 1};
const int d8y[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int d8x[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

int W;
int H;
int dd[10][10];  // distances between dirty sections
int ds[10];      // distances between starting point and dirty sections
int map[20][20]; // -1: empty, -2: obstacles, -3: starting point, 0-: dirties
bool v[20][20];
std::vector<coord> dirties;
coord st;

bool input() {
  std::cin >> W >> H;
  if (W == 0 && H == 0) {
    return false;
  }

  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      char c;
      std::cin >> c;

      if (c == '*') {
        map[y][x] = dirties.size();
        dirties.emplace_back(y, x);
      } else if (c == 'o') {
        st._y = y;
        st._x = x;
        map[y][x] = STARTING;
      } else if (c == 'x') {
        map[y][x] = OBSTACLE;
      } else {
        map[y][x] = EMPTY;
      }
    }
  }

  return true;
}

bool bfs(int no) {
  std::queue<coord> q;
  q.push(dirties[no]);
  v[q.back()._y][q.back()._x] = true;

  for (int cost = 0; !q.empty(); ++cost) {
    int len = q.size();
    while (len--) {
      coord c = q.front();
      q.pop();

      int m = map[c._y][c._x];
      if (m >= 0) {
        dd[no][m] = cost;
      } else if (m == STARTING) {
        ds[no] = cost;
      }

      for (int i = 0; i < 4; ++i) {
        coord adj(c._y + d4y[i], c._x + d4x[i]);
        if (!adj.inRange(W, H))
          continue;
        if (map[adj._y][adj._x] == OBSTACLE)
          continue;
        if (v[adj._y][adj._x])
          continue;
        q.push(adj);
        v[q.back()._y][q.back()._x] = true;
      }
    }
  }

  if (ds[no] == -1)
    return false;
  for (int i = 0; i < dirties.size(); ++i) {
    if (dd[no][i] == -1)
      return false;
  }

  return true;
}

int solve() {
  for (int i = 0; i < dirties.size(); ++i) {
    std::memset(v, 0, sizeof(v));
    if (!bfs(i)) {
      return -1;
    }
  }

  int answer = INT_MAX;
  std::vector<int> p;
  for (int i = 0; i < dirties.size(); ++i) {
    p.push_back(i);
  }

  do {
    int cost = ds[p[0]];
    int cur = p[0];
    for (int i = 1; i < p.size(); ++i) {
      cost += dd[cur][p[i]];
      cur = p[i];
    }
    answer = std::min(answer, cost);
  } while (std::next_permutation(p.begin(), p.end()));

  return answer;
}

int main(void) {
  fastio;
  while (true) {
    std::memset(dd, -1, sizeof(dd));
    std::memset(ds, -1, sizeof(ds));
    dirties.clear();
    if (!input()) {
      break;
    }
    std::cout << solve() << std::endl;
  }

  return 0;
}