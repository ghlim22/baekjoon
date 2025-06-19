#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		int s, e;
		std::cin >> s >> e;
		v.push_back({s, 1});
		v.push_back({e, -1});
	}

	std::sort(v.begin(), v.end());

	int maxRoom = 0;
	int room = 0;
	for (const auto &p : v) {
		if (p.second == -1) {
			room--;
		} else {
			room++;
		}
		maxRoom = std::max(maxRoom, room);
	}

	std::cout << maxRoom << std::endl;
	
	return 0;
}