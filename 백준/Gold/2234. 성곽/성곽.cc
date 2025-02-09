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

typedef std::pair<int, int> pii_t;

struct coord {
  coord() : _y(0), _x(0) {}
  coord(int y, int x) : _y(y), _x(x) {}
  bool operator==(const coord &other) {
    return _y == other._y && _x == other._x;
  }
  bool operator!=(const coord &other) {
    return !(_y == other._y && _x == other._x);
  }
  int _y;
  int _x;
};

const int d4y[4] = {0, -1, 0, 1};
const int d4x[4] = {-1, 0, 1, 0};
const int d8y[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int d8x[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

int M;
int N;
int map[50][50];
int visited[50][50];
std::vector<int> rooms;

bool in_range(int y, int x) { return (y >= 0 && y < M && x >= 0 && x < N); }

bool in_range(const coord &c) { return in_range(c._y, c._x); }

void input(void) {
  fastio;
  std::cin >> N >> M;
  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x)
      std::cin >> map[y][x];
  }
}

int bfs(int sy, int sx) {
  int size = 0;
  std::queue<coord> q;

  visited[sy][sx] = rooms.size();
  q.push(coord(sy, sx));
  while (!q.empty()) {
    coord current = q.front();
    size++;

    for (int i = 0; i < 4; ++i) {
      if (map[current._y][current._x] &
          (1 << i)) // Check if there's a wall in that direction
        continue;

      coord adj(current._y + d4y[i], current._x + d4x[i]);
      if (!in_range(adj))
        continue;
      if (visited[adj._y][adj._x] != -1)
        continue;

      visited[adj._y][adj._x] = rooms.size();
      q.push(adj);
    }

    q.pop();
  }

  return size;
}

int main(void) {
  input();

  int max_room_size = 0;
  std::memset(visited, -1, sizeof(visited));
  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x) {
      if (visited[y][x] != -1)
        continue;
      rooms.push_back(bfs(y, x));
      if (rooms.back() > max_room_size)
        max_room_size = rooms.back();
    }
  }

  int max_possible_size = 0;
  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x) {
      int current_room = visited[y][x];
      if (current_room == -1)
        continue;

      for (int i = 0; i < 4; ++i) {
        if (!(map[y][x] &
              (1 << i))) // Check if there's a wall in that direction
          continue;

        int ay = y + d4y[i];
        int ax = x + d4x[i];
        if (!in_range(ay, ax))
          continue;

        int adjacent_room = visited[ay][ax];
        if (adjacent_room == -1 || current_room == adjacent_room)
          continue;

        int possible_size = rooms[current_room] + rooms[adjacent_room];
        if (max_possible_size < possible_size)
          max_possible_size = possible_size;
      }
    }
  }

  std::cout << rooms.size() << '\n'
            << max_room_size << '\n'
            << max_possible_size << '\n';

  return 0;
}
