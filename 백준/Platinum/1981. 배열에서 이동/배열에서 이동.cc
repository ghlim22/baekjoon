#include <iostream>
#include <cstring>
#include <utility>
#include <tuple>
#include <queue>

#define fastio                            \
	do                                    \
	{                                     \
		std::ios::sync_with_stdio(false); \
		std::cin.tie(0);                  \
		std::cout.tie(0);                 \
	} while (0)

const int d4y[4] = {0, -1, 1, 0};
const int d4x[4] = {-1, 0, 0, 1};

int mat[100][100];
bool visited[100][100];

bool go(int n, int min, int max)
{
	if (mat[0][0] < min || mat[0][0] > max)
		return false;

	if (mat[n - 1][n - 1] < min || mat[n - 1][n - 1] > max)
		return false;

	std::memset(visited, 0, sizeof(visited));

	std::queue<std::pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		if (y == n - 1 && x == n - 1)
			break;

		for (int i = 0; i < 4; ++i)
		{
			int newY = y + d4y[i];
			int newX = x + d4x[i];

			if (!(newY >= 0 && newY < n && newX >= 0 && newX < n))
				continue;

			if (visited[newY][newX])
				continue;

			if (!(mat[newY][newX] >= min && mat[newY][newX] <= max))
				continue;

			visited[newY][newX] = true;
			q.push({newY, newX});
		}
	}

	return visited[n - 1][n - 1];
}

bool check(int n, int diff)
{
	for (int min = 0; min + diff <= 200; ++min)
	{
		int max = min + diff;
		if (go(n, min, max))
		{
			return true;
		}
	}

	return false;
}

int main(void)
{
	fastio;

	int n;

	std::cin >> n;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
			std::cin >> mat[y][x];
	}

	int lo = 0;
	int hi = 200;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (check(n, mid))
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}

	std::cout << hi;

	return 0;
}