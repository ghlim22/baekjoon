#include <iostream>
#include <queue>
#define MAX (1000)

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int arr[MAX][MAX];
bool vis[MAX][MAX];

static void input(int &height, int &width, int &start_x, int &start_y);
static void bfs(const int &height, const int &width, const int &start_x, const int &start_y);
static void print(const int &height, const int &width);

int main(void)
{
	int height, width, start_x, start_y;

	input(height, width, start_x, start_y);
	bfs(height, width, start_x, start_y);
	print(height, width);

	return (0);	
}

static void input(int &height, int &width, int &start_x, int &start_y)
{
	std::cin >> height >> width;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				start_x = j;
				start_y = i;
				arr[i][j] = 0;
			}
		}
	}
}

static void bfs(const int &height, const int &width, const int &start_x, const int &start_y)
{
	std::queue< std::pair<int, int> > q;
	
	q.push(std::make_pair(start_y, start_x));
	vis[start_y][start_x] = true;
	while (!q.empty())
	{
		std::pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int y = cur.first + dy[i];
			int x = cur.second + dx[i];
			if (y < 0 || y > height - 1 || x < 0 || x > width - 1)
				continue;
			if (!vis[y][x] && arr[y][x] != 0)
			{
				arr[y][x] = arr[cur.first][cur.second] + 1;
				q.push(std::make_pair(y, x));
				vis[y][x] = true;
			}
		}
	}
}

static void print(const int &height, const int &width)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (arr[i][j] == 0)
				std::cout << 0;
			else if (!vis[i][j])
				std::cout << -1;
			else
				std::cout << arr[i][j];
			
			if (j < width - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
