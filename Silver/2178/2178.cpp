#include <stdio.h>
#include <queue>
#include <utility>
#define MAX_SIZE (100)

typedef std::pair<int, int> pii;

static int	maize[MAX_SIZE][MAX_SIZE];
static int	cnt[MAX_SIZE][MAX_SIZE];
static bool	visited[MAX_SIZE][MAX_SIZE];

static void	get_input(int *p_height, int *p_width);
static void	solve(int height, int width);

int	main(void)
{
	int height, width;

	get_input(&height, &width);
	solve(height, width);

	return (0);
}

static void	get_input(int *p_height, int *p_width)
{
	scanf("%d %d", p_height, p_width);
	for (int i = 0; i < *p_height; ++i)
	{
		for (int j = 0; j < *p_width; ++j)
		{
			scanf("%1d", &maize[i][j]);
		}
	}
}

static void	solve(int height, int width)
{
	static int dx[4] = {0, 0, -1, 1};
	static int dy[4] = {-1, 1, 0, 0};
	std::queue<pii> bfs_queue;

	visited[0][0] = true;
	cnt[0][0] = 1;
	bfs_queue.push(std::make_pair(0, 0));
	while (!bfs_queue.empty())
	{
		int y = bfs_queue.front().first;
		int x = bfs_queue.front().second;
		bfs_queue.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < height && nx >= 0 && nx < width)
			{
				if (!visited[ny][nx] && maize[ny][nx])
				{
					visited[ny][nx] = true;
					cnt[ny][nx] = cnt[y][x] + 1;
					bfs_queue.push(std::make_pair(ny, nx));
				}
			}
		}
	}
	printf("%d\n", cnt[height - 1][width - 1]);
}