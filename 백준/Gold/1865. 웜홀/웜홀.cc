#include <cstring>
#include <iostream>
#include <vector>

struct edge
{
	int start;
	int end;
	int time;
};

bool visited[501];
bool connected[501][501];
long long cost[501];
long long inf = 500 * 10000L + 1;

bool dfs(int startingPoint, int point, int N)
{
	visited[point] = true;
	for (int i = 1; i <= N; ++i)
	{
		if (connected[point][i])
		{
			if (i == startingPoint)
			{
				return true;
			}
			if (!visited[i])
			{
				if (dfs(startingPoint, i, N))
				{
					return true;
				}
			}
		}
	}

	return false;
}

std::vector<int> findStartingPoints(int N)
{
	std::vector<int> startingPoints;
	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i] && dfs(i, i, N))
		{
			startingPoints.push_back(i);
		}
	}

	return startingPoints;
}

bool findNegativeCycle(const std::vector<edge> &edges, int N)
{
	auto startingPoints = findStartingPoints(N);
	for (int i = 1; i <= N; ++i)
	{
		cost[i] = inf;
	}
	for (int i : startingPoints)
	{
		cost[i] = 0;
	}

	for (int i = 0; i < N; ++i)
	{
		for (const auto &e : edges)
		{
			if (cost[e.start] == inf)
			{
				continue;
			}
			if (cost[e.end] > cost[e.start] + e.time)
			{
				if (i == N - 1)
				{
					return true;
				}
				cost[e.end] = cost[e.start] + e.time;
			}
		}
	}
	return false;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int TC;
	std::cin >> TC;

	while (TC--)
	{
		int N, M, W;
		std::cin >> N >> M >> W;

		std::memset(connected, 0, sizeof(connected));
		std::memset(visited, 0, sizeof(visited));
		std::memset(cost, 0, sizeof(cost));

		std::vector<edge> edges;
		for (int i = 0; i < M; ++i)
		{
			int S, E, T;
			std::cin >> S >> E >> T;
			edges.push_back({S, E, T});
			edges.push_back({E, S, T});
			connected[S][E] = true;
			connected[E][S] = true;
		}

		for (int i = 0; i < W; ++i)
		{
			int S, E, T;
			std::cin >> S >> E >> T;
			edges.push_back({S, E, -T});
			connected[S][E] = true;
		}

		if (findNegativeCycle(edges, N)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}