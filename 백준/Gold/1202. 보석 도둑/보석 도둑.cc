#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define fastio                            \
	do                                    \
	{                                     \
		std::ios::sync_with_stdio(false); \
		std::cin.tie(0);                  \
		std::cout.tie(0);                 \
	} while (0)

struct jewelry
{
	int m;
	int v;
};

int main()
{
	fastio;

	int n;
	int k;

	std::cin >> n >> k;

	std::vector<jewelry> items(n);
	std::vector<int> bags(k);

	for (int i = 0; i < n; ++i)
		std::cin >> items[i].m >> items[i].v;

	for (int i = 0; i < k; ++i)
		std::cin >> bags[i];

	std::sort(items.begin(), items.end(), [](const auto &a, const auto &b)
			  { return a.m < b.m; });
	std::sort(bags.begin(), bags.end());

	std::priority_queue<int> pq;
	int j = 0;
	long sum = 0;
	for (int i = 0; i < k; ++i)
	{
		while (j < n && items[j].m <= bags[i])
		{
			pq.push(items[j].v);
			j++;
		}

		if (pq.empty())
		{
			if (j == n)
			{
				break;
			}
			continue;
		}

		sum += pq.top();
		pq.pop();
	}

	std::cout << sum;

	return 0;
}