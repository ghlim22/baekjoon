#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> pii_t;

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};
int map[1000][1000];
int info[1000][1000];
bool visited[1000][1000];
int N;
int M;
std::vector<int> cc;

void bfs(int sy, int sx) {
  int size = 0;
  std::queue<pii_t> q;
  visited[sy][sx] = true;
  q.push(std::make_pair(sy, sx));
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    size++;
    info[y][x] = cc.size();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + DY[i];
      int nx = x + DX[i];
      if (!(ny >= 0 && ny < N && nx >= 0 && nx < M))
        continue;
      if (visited[ny][nx])
        continue;
      if (map[ny][nx] != 1)
        continue;
      visited[ny][nx] = true;
      q.push(std::make_pair(ny, nx));
    }
  }
  cc.push_back(size);
}

int get_size(int y, int x) {
  int size = 1;
  for (int i = 0; i < 4; ++i) {
    int ay = y + DY[i];
    int ax = x + DX[i];
    if (!(ay >= 0 && ay < N && ax >= 0 && ax < M))
      continue;
    if (map[ay][ax] != 1)
      continue;

    bool dup = false;
    for (int j = 0; j < i && !dup; ++j) {
      int py = y + DY[j];
      int px = x + DX[j];
      if (!(py >= 0 && py < N && px >= 0 && px < M))
        continue;
      if (map[py][px] != 1)
        continue;
      if (info[py][px] == info[ay][ax])
        dup = true;
    }
    if (dup)
      continue;
    size += cc[info[ay][ax]];
  }

  return size;
}

int main(void) {
  std::cin >> N >> M;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      std::cin >> map[y][x];
    }
  }

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (visited[y][x])
        continue;
      if (map[y][x] != 1)
        continue;
      bfs(y, x);
    }
  }

  //   for (int i = 0; i < cc.size(); ++i) {
  //     std::cout << cc[i] << ' ';
  //   }
  //   std::cout << std::endl;
  //   for (int y = 0; y < N; ++y) {
  //     for (int x = 0; x < M; ++x) {
  //       std::cout << info[y][x] << ' ';
  //     }
  //     std::cout << std::endl;
  //   }

  int answer = 0;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (map[y][x] != 0)
        continue;
      answer = std::max(answer, get_size(y, x));
    }
  }

  std::cout << answer << std::endl;

  return 0;
}