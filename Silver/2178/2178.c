#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE (100)

static int map[MAX_SIZE][MAX_SIZE];
static int ans = MAX_SIZE * MAX_SIZE;
static int height, width;

static void dfs(int x, int y, int depth)
{
    if (x == width - 1 && y == height - 1)
    {
        if (ans > depth)
            ans = depth;
        printf("%d\n", ans);
        exit(0);
    }

    if (!map[y][x])
    {
        return;
    }
    map[y][x] = 0;
    if (x > 0)
    {
        dfs(x - 1, y, depth + 1);
    }
    if (y < height - 1)
    {
        dfs(x, y + 1, depth + 1);
    }
    if (x < width - 1)
    {
        dfs(x + 1, y, depth + 1);
    }
    if (y > 0)
    {
        dfs(x, y - 1, depth + 1);
    }
    map[y][x] = 1;
}

int main(void)
{
    scanf("%d %d", &height, &width);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    dfs(0, 0, 1);
    return (0);
}