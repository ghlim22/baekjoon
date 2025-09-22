#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
	int C, N;
	std::cin >> C >> N;
	
	std::vector<std::pair<int, int>> ad;
	std::vector<int> cus(C + 1);
	for (int i = 0; i < N; ++i) {
		int cost, customers;
		std::cin >> cost >> customers;
		ad.push_back({cost, customers});
	}

	for (int i = 0; i <= C; ++i) {
		if (i != 0 && cus[i] == 0)
		 	continue;
		for (const auto &p : ad) {
			int cost = p.first;
			int customers = p.second;
			int nextIdx = i + customers;
			if (nextIdx > C)
				nextIdx = C;
			if (cus[nextIdx] == 0)
				cus[nextIdx] = cus[i] + cost;
			else
				cus[nextIdx] = std::min(cus[nextIdx], cus[i] + cost);
		}	
	}
	std::cout << cus[C] << std::endl;

	return 0;
}