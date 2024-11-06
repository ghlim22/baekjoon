#include <memory.h>
#include <iostream>
#include <queue>
#include <utility>
#define MAX_SIZE (20)
#define INF (100000)

typedef struct s_shark
{
    int x;
    int y;
    int size;
    int fish_cnt;
    int time;
} t_shark;

static const int dx[4] = {0, -1, 1, 0};
static const int dy[4] = {-1, 0, 0, 1};

static t_shark sh;
static int map_size;
static int total_fish;
static int map[MAX_SIZE][MAX_SIZE];
static int cost[MAX_SIZE][MAX_SIZE];

static void init_shark(void);
static void input(void);
static void solve(void);

int main(void)
{
    init_shark();
    input();
    solve();
    return (0);
}

static void init_shark(void)
{
    sh.x = 0;
    sh.y = 0;
    sh.fish_cnt = 0;
    sh.size = 2;
    sh.time = 0;
}

static void input(void)
{
    std::cin >> map_size;
    for (int i = 0; i < map_size; ++i)
    {
        for (int j = 0; j < map_size; ++j)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 9)
            {
                map[i][j] = 0;
                sh.x = j;
                sh.y = i;
            }
            if (map[i][j] != 0 && map[i][j] < sh.size)
                total_fish++;
        }
    }
}

static bool find_fish(void)
{
    int min_cost = INF;
    std::queue<std::pair<int, int> > q;
    memset(cost, -1, sizeof(int) * MAX_SIZE * MAX_SIZE);

    q.push(std::make_pair(sh.x, sh.y));
    cost[sh.y][sh.x] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if ((x != sh.x || y != sh.y) && map[y][x] != 0 && cost[y][x] < min_cost && map[y][x] < sh.size)
        {
            min_cost = cost[y][x];
        }
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < map_size && ny >= 0 && ny < map_size)
            {
                if (cost[ny][nx] == -1 && map[ny][nx] <= sh.size)
                {
                    cost[ny][nx] = cost[y][x] + 1;
                    q.push(std::make_pair(nx, ny));
                }
            }
        }
    }

    if (min_cost == INF)
        return (false);
    for (int i = 0; i < map_size; ++i)
    {
        for (int j = 0; j < map_size; ++j)
        {
            if (map[i][j] != 0 && cost[i][j] == min_cost && map[i][j] < sh.size)
            {
                sh.x = j;
                sh.y = i;
                sh.fish_cnt++;
                sh.time += min_cost;
                map[i][j] = 0;
                if (sh.fish_cnt == sh.size)
                {
                    sh.fish_cnt = 0;
                    sh.size++;
                }
                return (true);
            }
        }
    }
    return (false);
}

static void solve(void)
{
    while (find_fish())
        ;
    std::cout << sh.time;
}
