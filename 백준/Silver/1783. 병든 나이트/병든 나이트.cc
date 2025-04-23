#include <iostream>
#include <queue>

const int DY[4] = {-2, 2, -1, 1};
const int DX[4] = {1, 1, 2, 2};

int bfs(int n, int m)
{
	int time = 0;
	std::queue<std::pair<int, int>> q;
	q.push({n - 1, 0});
	for (; time < 3 && !q.empty(); ++time)
	{
		int len = q.size();
		while (len--)
		{
			for (int i = 0; i < 4; ++i)
			{
				int ny = q.front().first + DY[i];
				int nx = q.front().second + DX[i];
				if (!(ny >= 0 && ny < n && nx >= 0 && nx < m))
					continue;
				q.push({ny, nx});
			}
			q.pop();
		}
		if (q.empty())
			break;
	}

	return time + 1;
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	int cnt = 0;
	if (n < 3 || m <= 5)
	{
		cnt = bfs(n, m);
	}
	else
	{
		cnt = 3 + m - 5;
	}

	std::cout << cnt;

	return 0;
}
