#include <iostream>
#include <queue>

const int DY[4] = {-2, 2, -1, 1};
const int DX[4] = {1, 1, 2, 2};

int bfs(int n, int m)
{
	int y = n - 1;
	int x = 0;
	bool go = true;
	int time = 1;
	while (go && time < 4)
	{
		go = false;
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + DY[i];
			int nx = x + DX[i];
			if (!(ny >= 0 && ny < n && nx >= 0 && nx < m))
				continue;
			go = true;
			time++;
			y = ny;
			x = nx;
			break;
		}
	}

	return time;
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
