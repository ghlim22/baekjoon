#include <memory.h>
#include <iostream>
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

static void calculate_cost(void)
{
    memset(cost, -1, sizeof(int) * MAX_SIZE * MAX_SIZE);
    cost[sh.y][sh.x] = 0;
    int flag = 0;
    do
    {
        flag = 0;
        for (int i = 0; i < map_size; ++i)
        {
            for (int j = 0; j < map_size; ++j)
            {
                if (cost[i][j] != -1)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int cur_x = j + dx[k];
                        int cur_y = i + dy[k];
                        if (cur_x >= 0 && cur_x < map_size && cur_y >= 0 && cur_y < map_size)
                        {
                            if (map[cur_y][cur_x] > sh.size)
                                continue;
                            if (cost[cur_y][cur_x] == -1)
                            {
                                cost[cur_y][cur_x] = cost[i][j] + 1;
                                flag = 1;
                            }
                            else if (cost[cur_y][cur_x] > cost[i][j] + 1)
                            {
                                cost[cur_y][cur_x] = cost[i][j] + 1;
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }
    } while (flag);
}

static void calculate_available_fish(void)
{
    for (int i = 0; i < map_size; ++i)
    {
        for (int j = 0; j < map_size; ++j)
        {
            if (cost[i][j] != -1 && map[i][j] < sh.size)
                total_fish++;
        }
    }
}

static void solve(void)
{
    while (total_fish > 0)
    {
        int min_x = -1;
        int min_y = -1;
        int min_cost = INF;
        int flag = 0;
        total_fish = 0;
        calculate_cost();
        calculate_available_fish();
        if (total_fish == 0)
            break;
        for (int i = 0; i < map_size; ++i)
        {
            for (int j = 0; j < map_size; ++j)
            {
                if (cost[i][j] != -1 && cost[i][j] != 0 && cost[i][j] < min_cost && map[i][j] != 0 && map[i][j] < sh.size)
                {
                    min_x = j;
                    min_y = i;
                    min_cost = cost[i][j];
                }
            }
        }
        if (min_cost == INF)
            break;
        map[min_y][min_x] = 0;
        sh.x = min_x;
        sh.y = min_y;
        sh.time += min_cost;
        sh.fish_cnt++;
        if (sh.fish_cnt == sh.size)
        {
            sh.fish_cnt = 0;
            sh.size++;
        }
    }
    std::cout << sh.time;
}
