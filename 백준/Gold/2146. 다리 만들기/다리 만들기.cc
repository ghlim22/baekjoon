#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#define MAX (100)

typedef std::pair<int, int> pii_t;

const int DY[4] = {-1, 0, 0, 1};
const int DX[4] = {0, -1, 1, 0};
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int N;
int answer = INT_MAX;

void input() {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> map[i][j];
    }
  }
}

void search_island(int y, int x, int num) {
  std::queue<pii_t> q;

  q.push(std::make_pair(y, x));
  visited[y][x] = true;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    map[y][x] = num;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + DY[i];
      int nx = x + DX[i];
      if (!(ny >= 0 && ny < N)) {
        continue;
      }
      if (!(nx >= 0 && nx < N)) {
        continue;
      }
      if (visited[ny][nx]) {
        continue;
      }
      if (map[ny][nx] == 0) {
        continue;
      }
      visited[ny][nx] = true;
      q.push(std::make_pair(ny, nx));
    }
  }
}

void number_islands() {
  int num = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j] == 1 && !visited[i][j]) {
        search_island(i, j, num++);
      }
    }
  }
}

void bfs(int y, int x) {
  memset(visited, 0, sizeof(visited));
  memset(dist, 0, sizeof(dist));

  std::queue<pii_t> q;

  int current_island = map[y][x];
  q.push(std::make_pair(y, x));
  visited[y][x] = true;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + DY[i];
      int nx = x + DX[i];
      if (!(ny >= 0 && ny < N)) {
        continue;
      }
      if (!(nx >= 0 && nx < N)) {
        continue;
      }
      if (visited[ny][nx]) {
        continue;
      }
      if (map[ny][nx] == current_island) {
        continue;
      }
      dist[ny][nx] = dist[y][x] + 1;
      visited[ny][nx] = true;
      if (map[ny][nx] == 0) {
        q.push(std::make_pair(ny, nx));
      } else {
        answer = std::min(answer, dist[y][x]);
        return;
      }
    }
  }
}

void find_another_island(int y, int x) {
  bool is_coast = false;
  for (int i = 0; i < 4; ++i) {
    int ny = y + DY[i];
    int nx = x + DX[i];
    if (!(ny >= 0 && ny < N)) {
      continue;
    }
    if (!(nx >= 0 && nx < N)) {
      continue;
    }
    if (map[ny][nx] == 0) {
      is_coast = true;
      break;
    }
  }

  if (is_coast) {
    bfs(y, x);
  }
}

void solve() {
  number_islands();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j] == 0) {
        continue;
      }
      find_another_island(i, j);
    }
  }
  std::cout << answer;
}

int main() {
  input();
  solve();
  return 0;
}