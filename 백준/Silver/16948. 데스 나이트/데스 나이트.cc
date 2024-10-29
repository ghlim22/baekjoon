#include <iostream>
#include <queue>
#include <utility>

typedef std::pair<int, int> pii_t;

int g_size;
bool g_visited[200][200];
pii_t start;
pii_t dest;

void input(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> g_size;
  std::cin >> start.first >> start.second >> dest.first >> dest.second;
}

int bfs(void) {
  const int DY[6] = {-2, -2, 0, 0, 2, 2};
  const int DX[6] = {-1, 1, -2, 2, -1, 1};
  std::queue<pii_t> q;
  int cost = 0;

  q.push(start);
  g_visited[start.first][start.second] = true;

  while (q.empty() == false) {
    const int Q_SIZE = q.size();
    for (int i = 0; i < Q_SIZE; i++) {
      pii_t cur = q.front();
      q.pop();

      if (cur.first == dest.first && cur.second == dest.second) {
        return cost;
      }
      for (int j = 0; j < 6; j++) {
        int ny = cur.first + DY[j];
        int nx = cur.second + DX[j];

        if (!(ny >= 0 && ny < g_size && nx >= 0 && nx < g_size)) {
          continue;
        }
        if (g_visited[ny][nx]) {
          continue;
        }

        g_visited[ny][nx] = true;
        q.push(std::make_pair(ny, nx));
      }
    }
    cost++;
  }

  return -1;
}

void solve(void) { std::cout << bfs(); }

int main(void) {
  input();
  solve();
}