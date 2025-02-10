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

int N;
int M;
int map[50][50];
int cost[50][50][10];
std::vector<coord> virus;

void input(void) {
  fastio;
  std::cin >> N >> M;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      std::cin >> map[y][x];
      if (map[y][x] == 2) {
        virus.push_back(coord(y, x));
      }
    }
  }
}

void bfs(int no) {
  std::queue<coord> q;

  cost[virus[no]._y][virus[no]._x][no] = 0;
  q.push(virus[no]);
  while (!q.empty()) {
    const coord &current = q.front();

    for (int i = 0; i < 4; ++i) {
      coord adj(current._y + d4y[i], current._x + d4x[i]);
      if (!adj.inRange(N, N))
        continue;
      if (map[adj._y][adj._x] == 1)
        continue;
	  if (cost[adj._y][adj._x][no] != -1)
		continue;
      q.push(adj);
      cost[adj._y][adj._x][no] = cost[current._y][current._x][no] + 1;
    }

    q.pop();
  }
}

int select(int cursor, int count, int set) {
  if (count == M) {
    int minimum_time = -1; // Minimum time to reach all blank spaces
    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < N; ++x) {
        if (map[y][x] == 1)
          continue;
        int current_time = INT_MAX;
        for (int i = 0; i < virus.size(); ++i) {
          if (!(set & (1 << i)))
            continue;
          if (cost[y][x][i] == -1)
            continue;
          current_time = std::min(current_time, cost[y][x][i]);
        }
        // If there's a blank space that virus cannot reach 
        if (current_time == INT_MAX)
          return INT_MAX;
        minimum_time = std::max(minimum_time, current_time);
      }
    }
    return minimum_time;
  }
  if (virus.size() - cursor < M - count) {
    return INT_MAX;
  }
  if (cursor == virus.size()) {
    return INT_MAX;
  }
  return std::min(select(cursor + 1, count + 1, set | (1 << cursor)),
                  select(cursor + 1, count, set));
}

int solve(void) {
  std::memset(cost, -1, sizeof(cost));

  for (int i = 0; i < virus.size(); ++i) {
    bfs(i);
  }

    int ret = select(0, 0, 0);
    if (ret == INT_MAX) {
      return -1;
    }
    return ret;
}

int main(void) {
  input();
  std::cout << solve();

  return 0;
}