#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits.h>

#define MAX_CNT (20)

static int stat[MAX_CNT][MAX_CNT];
static int start[MAX_CNT];
static int n = 0;
static int ans = INT_MAX;

static bool is_start(int num)
{
	for (int i = 0; i < n / 2; ++i)
	{
		if (start[i] == num)
			return true;
	}
	return false;
}

static void	solve(int i, int dep)
{
	if (dep == n / 2)
	{
		int start_stat = 0;
		int link_stat = 0;
		for (int i = 0; i < n; ++i)
		{
			if (is_start(i))
			{
				for (int j = 0; j < n; ++j)
				{
					if (i != j && is_start(j))
						start_stat += stat[i][j];
				}
			}
			else
			{
				for (int j = 0; j < n; ++j)
				{
					if (i != j && !is_start(j))
						link_stat += stat[i][j];
				}
			}
		}
		ans = std::min(ans, std::abs(start_stat - link_stat));	
		return ;
	}
	if (i >= n)
		return ;
	solve(i + 1, dep);
	start[dep] = i;
	solve(i + 1, dep + 1);
}

int main(void)
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			std::cin >> stat[i][j];
	}
	solve(0, 0);
	std::cout << ans << std::endl;
	return 0;
}
