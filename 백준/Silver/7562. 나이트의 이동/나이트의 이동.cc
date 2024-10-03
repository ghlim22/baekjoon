#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

#define MAX (300)
typedef std::pair<int, int> pii_t;

const int DX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int DY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int cache[MAX][MAX];

int main() {
  int t;

  scanf("%d", &t);
  while (t--) {
    int l, sy, sx, gy, gx;
    std::queue<pii_t> q;

    memset(cache, 0, sizeof(cache));

    scanf("%d", &l);
    scanf("%d %d %d %d", &sy, &sx, &gy, &gx);

    q.push(std::make_pair(sy, sx));
    cache[sy][sx] = 1;
    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      int cost = cache[y][x];
      q.pop();

      if (y == gy && x == gx) {
        printf("%d\n", cost - 1);
        break;
      }

      for (int i = 0; i < 8; ++i) {
        int ny = y + DY[i];
        int nx = x + DX[i];
        if (!(ny >= 0 && ny < l))
          continue;
        if (!(nx >= 0 && nx < l))
          continue;
        if (cache[ny][nx] > 0)
          continue;
        cache[ny][nx] = cost + 1;
        q.push(std::make_pair(ny, nx));
      }
    }
  }

  return 0;
}
