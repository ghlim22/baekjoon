#include <algorithm>
#include <cstring>
#include <iostream>

int parent[1000001];
int rank[1000001];

int find(int x)
{
	if (parent[x] == -1)
	{
		return x;
	}

	int y = find(parent[x]);
	parent[x] = y;
	return parent[x];
}

void unionXY(int x, int y)
{
	int rootX = find(x);
	int rootY = find(y);

	if (rootX == rootY)
		return;

	if (rank[rootX] < rank[rootY])
		std::swap(rootX, rootY);

	parent[rootY] = rootX;
	if (rank[rootX] == rank[rootY])
	{
		rank[rootX] = rank[rootY] + 1;
	}
}

int main()
{
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, m;

	std::cin >> n >> m;

	std::memset(parent, -1, sizeof(int) * (n + 1));

	while (m--)
	{
		int cmd, a, b;

		std::cin >> cmd >> a >> b;

		if (cmd == 0)
		{
			unionXY(a, b);
		}
		else
		{
			if (find(a) == find(b))
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}
}