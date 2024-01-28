#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>

#define MAX_SIZE (1000)
#define FALSE (0)
#define TRUE (1)

typedef std::pair<int, int> pii_t;
typedef std::pair<pii_t, bool> piib_t;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE][2];
int n;
int m;

static inline bool is_valid_range(int y, int x)
{
    return (y >= 0 && y < n && x >= 0 && x < m);
}

static inline bool more_optizable(int next, int cur)
{
    return (next == 0 || next > cur + 1);
}

static void input()
{
    std::scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::scanf("%1d", &map[i][j]);
        }
    }
}

static void solve()
{
    std::queue<piib_t> q;

    dist[0][0][FALSE] = 1;
    q.push(std::make_pair(std::make_pair(0, 0), false));

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        bool bBrokeWall = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!is_valid_range(ny, nx)) {
                continue;
            }

            if (bBrokeWall) {
                if (map[ny][nx] == 0 &&
                    more_optizable(dist[ny][nx][TRUE], dist[y][x][TRUE])) {
                    dist[ny][nx][TRUE] = dist[y][x][TRUE] + 1;
                    q.push(std::make_pair(std::make_pair(ny, nx), bBrokeWall));
                }
            } else {
                if (map[ny][nx] == 0) {
                    if (more_optizable(dist[ny][nx][FALSE],
                                       dist[y][x][FALSE])) {
                        dist[ny][nx][FALSE] = dist[y][x][FALSE] + 1;
                        q.push(
                            std::make_pair(std::make_pair(ny, nx), bBrokeWall));
                    }
                } else {
                    if (more_optizable(dist[ny][nx][TRUE], dist[y][x][FALSE])) {
                        dist[ny][nx][TRUE] = dist[y][x][FALSE] + 1;
                        q.push(std::make_pair(std::make_pair(ny, nx), true));
                    }
                }
            }
        }
    }
}

void print_result()
{
    if (dist[n - 1][m - 1][FALSE] == 0 && dist[n - 1][m - 1][TRUE] == 0) {
        std::printf("%d\n", -1);
    } else if (dist[n - 1][m - 1][FALSE] == 0) {
        std::printf("%d\n", dist[n - 1][m - 1][TRUE]);
    } else if (dist[n - 1][m - 1][TRUE] == 0) {
        std::printf("%d\n", dist[n - 1][m - 1][FALSE]);
    } else {
        std::printf("%d\n", std::min(dist[n - 1][m - 1][FALSE],
                                     dist[n - 1][m - 1][TRUE]));
    }
}

int main()
{
    input();
    solve();
    print_result();
    return 0;
}
