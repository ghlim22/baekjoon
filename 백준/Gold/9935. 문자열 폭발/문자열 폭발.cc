#include <deque>
#include <iostream>
#include <utility>

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

void solve(const std::string &line, const std::string &bomb) {
  std::deque<char> d;

  const int LEN = line.size();
  for (int i = 0; i < LEN; ++i) {
    d.push_back(line[i]);
    if (d.size() >= bomb.size()) {
      for (int j = 0; j < bomb.size(); ++j) {
        if (d[d.size() - j - 1] != bomb[bomb.size() - j - 1]) {
          goto PASS;
        }
      }
      for (int j = 0; j < bomb.size(); ++j) {
        d.pop_back();
      }
    }
  PASS:;
  }

  if (d.empty()) {
    std::cout << "FRULA" << std::endl;
  } else {
    while (!d.empty()) {
      std::cout << d.front();
      d.pop_front();
    }
    std::cout << std::endl;
  }
}

int main(void) {
  fastio;

  std::string line;
  std::string bomb;

  std::cin >> line;
  std::cin >> bomb;

  solve(line, bomb);

  return 0;
}