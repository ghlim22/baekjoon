#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX (20)

typedef std::pair<int, int> pii_t;

struct point {
  int y;
  int x;
};

typedef std::pair<point, point> pair_point_t;

int BOARD[MAX][MAX];
int WIDTH;
int HEIGHT;
const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

std::vector<point> COINS;

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> HEIGHT >> WIDTH;
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      char c;
      std::cin >> c;
      if (c == '#')
        BOARD[i][j] = 1;
      else if (c == 'o') {
        point tmp = {.y = i, .x = j};
        COINS.push_back(tmp);
      }
    }
  }
}

bool is_in_range(const point &p) {
  if (!(p.y >= 0 && p.y < HEIGHT))
    return false;
  if (!(p.x >= 0 && p.x < WIDTH))
    return false;
  return true;
}

bool is_wall(const point &p) { return BOARD[p.y][p.x]; }

int bfs() {

  int cost = 0;
  std::queue<pair_point_t> q;
  q.push(std::make_pair(COINS[0], COINS[1]));

  while (!q.empty() && cost <= 10) {
    const int size = q.size();
    for (int i = 0; i < size; ++i) {
      pair_point_t f = q.front();
      point one = f.first;
      point two = f.second;
      q.pop();

      if (is_in_range(one) ^ is_in_range(two))
        return cost;

      if (!is_in_range(one) && !is_in_range(two))
        continue;

      for (int j = 0; j < 4; ++j) {
        point next_one = {.y = one.y + DY[j], .x = one.x + DX[j]};
        point next_two = {.y = two.y + DY[j], .x = two.x + DX[j]};

        if (is_in_range(next_one) && is_wall(next_one))
          next_one = one;
        if (is_in_range(next_two) && is_wall(next_two))
          next_two = two;
        if (one.x == next_one.x && one.y == next_one.y && two.x == next_two.x &&
            two.y == next_two.y)
          continue;

        pair_point_t next = std::make_pair(next_one, next_two);
        q.push(next);
      }
    }
    cost++;
  }

  return -1;
}

void solve() { std::cout << bfs(); }

int main() {
  input();
  solve();
  return 0;
}