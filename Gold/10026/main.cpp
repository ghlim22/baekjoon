#include <iostream>
#include <memory.h>
#include <string>
#include <queue>
#include <utility>

#define PAINT_SIZE 100

char paint[PAINT_SIZE][PAINT_SIZE];
int visited[PAINT_SIZE][PAINT_SIZE];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int solve_noncb();
int solve_cb();

int main(void)
{
    int x; // count for non-colorblind
    int y; // count for colorblind;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> paint[i][j];
        }
    }

    x = solve_noncb();
    memset(visited, 0, sizeof(visited));
    y = solve_cb();

    std::cout << x << " " << y << "\n";

    return 0;
}

void search_noncb(int r, int c, char color)
{
    int nr;
    int nc;
    std::queue< std::pair<int, int> > q;

    q.push(std::make_pair(r, c));
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            nr = r + dy[i];
            nc = c + dx[i];
            if (!(nr >= 0 && nr < n))
            {
                continue;
            }
            if (!(nc >= 0 && nc < n))
            {
                continue;
            }
            if (paint[nr][nc] == color && !visited[nr][nc])
            {
                visited[nr][nc] = 1;
                q.push(std::make_pair(nr, nc));
            }
        }
    }
}

int solve_noncb()
{
    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                ++cnt;
                search_noncb(i, j, paint[i][j]);
            }
        }
    }

    return cnt;
}

void search_cb(int r, int c, char color)
{
    int nr;
    int nc;
    std::queue< std::pair<int, int> > q;

    q.push(std::make_pair(r, c));
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            nr = r + dy[i];
            nc = c + dx[i];
            if (!(nr >= 0 && nr < n))
            {
                continue;
            }
            if (!(nc >= 0 && nc < n))
            {
                continue;
            }
            if (!visited[nr][nc])
            {
                if (paint[nr][nc] == color || (color == 'R' && paint[nr][nc] == 'G') || (color == 'G' && paint[nr][nc] == 'R'))
                {
                    visited[nr][nc] = 1;
                    q.push(std::make_pair(nr, nc));
                }
            }
        }
    }
}

int solve_cb()
{
    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                ++cnt;
                search_cb(i, j, paint[i][j]);
            }
        }
    }

    return cnt;
}
