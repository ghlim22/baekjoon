#include <climits>
#include <cstring>
#include <iostream>
#include <queue>

struct shark {
  int y;
  int x;
  int count;
  int size;
  int time;
};

struct coord {
  int y;
  int x;
};

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int n;
int map[20][20];
int dist[20][20];

bool solve(shark *s) {
  std::memset(dist, -1, sizeof(dist));
  coord start = {.y = s->y, .x = s->x};
  std::queue<coord> q;
  q.push(start);
  dist[start.y][start.x] = 0;

  // bfs
  while (!q.empty()) {
    coord cur = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];
      if (!(ny >= 0 && ny < n && nx >= 0 && nx < n))
        continue;
      if (dist[ny][nx] != -1)
        continue;
      if (map[ny][nx] > s->size)
        continue;
      dist[ny][nx] = 1 + dist[cur.y][cur.x];
      q.push(coord{.y = ny, .x = nx});
    }
  }

  // eat a fish
  // find the nearest fish from upperleft to lowerright
  coord fish;
  int min_dist = INT_MAX;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (map[y][x] == 0)
        continue;
	  if (map[y][x] == s->size)
		continue;
      if (dist[y][x] == -1)
        continue;
      if (dist[y][x] >= min_dist)
        continue;
      min_dist = dist[y][x];
      fish.y = y;
      fish.x = x;
    }
  }

  if (min_dist == INT_MAX)
    return false;

  s->count++;
  if (s->count == s->size) {
    s->count = 0;
    s->size++;
  }
  s->time += min_dist;
  s->y = fish.y;
  s->x = fish.x;
  map[fish.y][fish.x] = 0;

  return true;
}

int main() {
  shark s = {.y = 0, .x = 0, .count = 0, .size = 2, .time = 0};
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 9) {
        map[i][j] = 0;
        s.y = i;
        s.x = j;
      }
    }
  }

  while (solve(&s))
    ;

  std::cout << s.time << std::endl;

  return 0;
}