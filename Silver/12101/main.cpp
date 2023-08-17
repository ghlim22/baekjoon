#include <iostream>

static int	arr[505];
static int	order = 0;

static bool	dfs(int n, int k, int dep);

int main(void)
{
	int	n;
	int	k;

	std::cin >> n >> k;
	if (!dfs(n, k, 0))
		std::cout << -1 << std::endl;
	return (0);
}

static bool	dfs(int n, int k, int dep)
{
	bool flag = false;
	if (n == 0)
	{
		order++;
		if (order == k)
		{
			for (int i = 0; i < dep; ++i)
			{
				std::cout << arr[i];
				if (i != dep - 1)
					std::cout << '+';
				else
					std::cout << std::endl;
			}
			return (true);
		}
	}
	if (n < 0)
		return (false);
	arr[dep] = 1;
	flag |= dfs(n - 1, k, dep + 1);
	arr[dep] = 2;
	flag |= dfs(n - 2, k, dep + 1);
	arr[dep] = 3;
	flag |= dfs(n - 3, k, dep + 1);
	return (flag);
}