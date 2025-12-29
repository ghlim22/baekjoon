#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int main() {
	int n;
	while (std::cin >> n && n > 0) {
		int sum = 0;
		std::vector<int> v;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				sum += i;
				sum += n / i;
				v.push_back(i);
				v.push_back(n / i);
			}
		}
		sum += 1;
		v.push_back(1);
		if (sum == n) {
			std::cout << n << " = ";
			std::sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); ++i) {
				std::cout << v[i];
				if (i < v.size() - 1) {
					std::cout << " + ";
				}
			}
			std::cout << '\n';
		} else {
			std::cout << n << " is NOT perfect.\n";
		}
	}
	return 0;
}