#include <stdio.h>
#include <stdlib.h>

static int ans = 0;
static int dx[4] = {-1, 1, 0, 0};
static int dy[4] = {0, 0, -1, 1};
static int height;
static int width;
static char **map;

static void search(int x, int y);
static void destroy_map(char **map);

int main(void)
{
    int init_x;
    int init_y;

    scanf("%d %d", &height, &width);

    map = (char **)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; ++i)
    {
        map[i] = (char *)malloc(sizeof(int) * width);
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'I')
            {
                init_y = i;
                init_x = j;
                map[i][j] = 'X';
            }
        }
    }
    search(init_x, init_y);
    if (ans == 0)
        printf("TT\n");
    else
        printf("%d\n", ans);
    destroy_map(map);
    return (0);
}

static void search(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if (rx >= 0 && rx < width && ry >= 0 && ry < height)
        {
            if (map[ry][rx] != 'X')
            {
                if (map[ry][rx] == 'P')
                    ans++;
                map[ry][rx] = 'X';
                search(rx, ry);
            }
        }
    }
}

static void destroy_map(char **map)
{
    for (int i = 0; i < height; ++i)
        free(map[i]);
    free(map);
}
