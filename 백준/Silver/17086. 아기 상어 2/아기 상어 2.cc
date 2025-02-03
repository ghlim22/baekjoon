#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

const int d4y[4] = {0, -1, 1, 0};
const int d4x[4] = {-1, 0, 0, 1};
const int d8y[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int d8x[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

int N;
int M;
int input[50][50];
int map[50][50];

std::queue<pii_t> sharks;

void get_input() {
  fastio;
  std::cin >> N >> M;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      std::cin >> input[y][x];
      if (input[y][x]) {
        sharks.push(std::make_pair(y, x));
      }
    }
  }
}

int solve() {
  while (!sharks.empty()) {
    std::queue<pii_t> q;
    q.push(sharks.front());

    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;

      for (int i = 0; i < 8; ++i) {
        int dy = y + d8y[i];
        int dx = x + d8x[i];
        if (!(dy >= 0 && dy < N && dx >= 0 && dx < M))
          continue;
        if (input[dy][dx] == 1)
          continue;
        if (map[dy][dx] != 0 && map[dy][dx] <= map[y][x] + 1)
          continue;
        map[dy][dx] = map[y][x] + 1;
        q.push(std::make_pair(dy, dx));
      }

      q.pop();
    }

    sharks.pop();
  }

  int answer = 0;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      answer = std::max(answer, map[y][x]);
    }
  }

  return answer;
}

int main(void) {
  get_input();
  std::cout << solve() << std::endl;

  return 0;
}