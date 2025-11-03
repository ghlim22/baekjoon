#include <algorithm>
#include <iostream>
#include <utility>
#define LMT 100000
#define MAXIMUM 1000000000
#define MINIMUM 1

int elem[LMT + 1];
int mintree[4 * LMT + 1];
int maxtree[4 * LMT + 1];

std::pair<int, int> construct(int node, int node_left, int node_right)
{
	if (node_left == node_right)
	{
		mintree[node] = elem[node_left];
		maxtree[node] = elem[node_left];
	}
	else
	{
		int mid = (node_left + node_right) / 2;
		auto [min_left, max_left] = construct(node * 2, node_left, mid);
		auto [min_right, max_right] = construct(node * 2 + 1, mid + 1, node_right);
		mintree[node] = std::min(min_left, min_right);
		maxtree[node] = std::max(max_left, max_right);
	}
	return {mintree[node], maxtree[node]};
}

std::pair<int, int> find(int node, int node_left, int node_right, int left, int right)
{
	if (node_right < left || node_left > right)
	{
		return {MAXIMUM + 1, MINIMUM - 1};
	}

	if (left <= node_left && node_right <= right)
	{
		return {mintree[node], maxtree[node]};
	}

	int mid = (node_left + node_right) / 2;
	auto [min_left, max_left] = find(node * 2, node_left, mid, left, right);
	auto [min_right, max_right] = find(node * 2 + 1, mid + 1, node_right, left, right);

	int minval = std::min(min_left, min_right);
	int maxval = std::max(max_left, max_right);
	return {minval, maxval};
}

int main(void)
{
	 std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> elem[i];
	}
	construct(1, 1, n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		auto [minval, maxval] = find(1, 1, n, a, b);
		std::cout << minval << ' ' << maxval << '\n';
	}

	return 0;
}