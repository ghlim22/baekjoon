#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

struct pos {
  int y;
  int x;
  int k;
};

typedef std::pair<int, int> pii_t;

const int dy[12] = {-2, -2, -1, -1, 1, 1, 2, 2, 0, 0, -1, 1};
const int dx[12] = {-1, 1, -2, 2, -2, 2, -1, 1, -1, 1, 0, 0};

int map[200][200];
int visited[200][200];
int W;
int H;
int K;

void input() {
  fastio;
  std::cin >> K >> W >> H;
  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      std::cin >> map[y][x];
    }
  }
}

int solve() {
  std::memset(visited, -1, sizeof(visited));
  pos init = {.y = 0, .x = 0, .k = K};
  std::queue<pos> q;
  visited[init.y][init.x] = init.k;
  q.push(init);

  for (int cost = 0; !q.empty(); ++cost) {
    int len = q.size();
    while (len--) {
      pos cur = q.front();
      if (cur.y == H - 1 && cur.x == W - 1) {
        return cost;
      }
      for (int i = 0; i < 12; ++i) {
        if (i < 8 && cur.k == 0) {
          continue;
        }
        int ny = cur.y + dy[i];
        int nx = cur.x + dx[i];
        int nc = cur.k - (i < 8);
        if (!(ny >= 0 && ny < H && nx >= 0 && nx < W)) {
          continue;
        }
        if (map[ny][nx] == 1) {
          continue;
        }
        if (visited[ny][nx] != -1 && visited[ny][nx] >= nc) {
          continue;
        }
        visited[ny][nx] = nc;
        pos np = {.y = ny, .x = nx, .k = nc};
        q.push(np);
      }
      q.pop();
    }
  }

  return -1;
}

int main(void) {
  input();
  std::cout << solve() << std::endl;

  return 0;
}